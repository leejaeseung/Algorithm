/*
F. Binary String Reconstruction
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
For some binary string s (i.e. each character si is either '0' or '1'), all pairs of consecutive (adjacent) characters were written. In other words, all substrings of length 2 were written. For each pair (substring of length 2), the number of '1' (ones) in it was calculated.

You are given three numbers:

n0 — the number of such pairs of consecutive characters (substrings) where the number of ones equals 0;
n1 — the number of such pairs of consecutive characters (substrings) where the number of ones equals 1;
n2 — the number of such pairs of consecutive characters (substrings) where the number of ones equals 2.
For example, for the string s="1110011110", the following substrings would be written: "11", "11", "10", "00", "01", "11", "11", "11", "10". Thus, n0=1, n1=3, n2=5.

Your task is to restore any suitable binary string s from the given values n0,n1,n2. It is guaranteed that at least one of the numbers n0,n1,n2 is greater than 0. Also, it is guaranteed that a solution exists.

Input
The first line contains an integer t (1≤t≤1000) — the number of test cases in the input. Then test cases follow.

Each test case consists of one line which contains three integers n0,n1,n2 (0≤n0,n1,n2≤100; n0+n1+n2>0). It is guaranteed that the answer for given n0,n1,n2 exists.

Output
Print t lines. Each of the lines should contain a binary string corresponding to a test case. If there are several possible solutions, print any of them.

풀이:
처음엔 BruteForce문제인 줄 알았는데 길이가 30정도만 넘어가도 시간초과가 납니다.(2^n)

이 문제에서 키포인트는 n1의 개수입니다.(코드 상에선 n2)
미리 만들어진 문자열이 있다고 하면(예를들어"0010101") n0나 n2 가 늘어나서 '0'이나 '1'을 추가한다고 해도
다른 값들에 영향을 미치지 않습니다.
0010101 에서 n0가 2 늘어나면 -> 000010101 이나 001000101 처럼 0 옆에 다시 0을 붙여주기만 하면 됩니다.
n2도 마찬가지입니다.

따라서, n1을 기준으로 먼저 문자열을 만들어 놓고 나면 그 문자열에 0, 1을 알맞은 위치에 끼워넣어 주기만 하면 됩니다.
n1은 다음과 같은 3가지 경우로 나눌 수 있습니다.
1. n1 == 0  -> 무조건 0000 이나 1111같은 경우입니다.(문자열이 존재한다고 보장되어 있으므로)
2. n1 이 짝수 -> 101 , 010 , 10101 , 01010... = 1로 시작하나 0으로 시작하나 똑같습니다.
3. n1 이 홀수 -> 10 , 01 , 1010 , 0101... = 마찬가지
즉, 양 쪽이 같거나, 다르거나 두 경우밖에 없습니다.

n1에 맞춰서 문자열을 만든 후, n0, n2 에 맞게 0 , 1 을 끼워넣어주면 해결됩니다.
*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>
#define pic pair<int, char>
#define ll long long
#define vi vector<int>
#define vl vector<long long>
#define vii vector<pii>

int t, n1, n2, n3;
int leng = 0;

int main(void) {
	FIO;

	cin >> t;

	while (t--) {
		cin >> n1 >> n2 >> n3;

		string ans = "";

		int s = 1;
		
		if (n2 != 0) {
			for (int i = 0; i < n2 + 1; i++)
			{
				ans += (char)((s++) % 2 + '0');
			}
			if (n2 % 2 == 0) {	//101
				string temp = "";
				for (int i = 0; i < n1; i++)
				{
					temp += "0";
				}
				ans.erase(0, 1);
				//맨 앞의 1뒤에 0을 끼워넣음
				ans= "1" + temp + ans;
				

				for (int i = 0; i < n3; i++)
				{
					ans += "1";
				}
				//맨 뒤에 1끼워넣음
			}
			else {				//1010
				string temp = "";
				for (int i = 0; i < n3; i++)
				{
					temp += "1";
				}
				ans = temp + ans;
				//맨 앞에 1끼워넣음

				for (int i = 0; i < n1; i++)
				{
					ans += "0";
				}
				//맨 뒤에 0끼워넣음
			}
		}
		else {
			if (n1 != 0) {
				for (int i = 0; i < n1 + 1; i++)
				{
					ans += "0";
				}
			}
			if (n3 != 0) {
				for (int i = 0; i < n3 + 1; i++)
				{
					ans += "1";
				}
			}
		}
		cout << ans << "\n";
	}
}