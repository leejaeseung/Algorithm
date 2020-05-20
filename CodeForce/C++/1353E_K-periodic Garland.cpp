/*
E. K-periodic Garland
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given a garland consisting of n lamps. States of the lamps are represented by the string s of length n. The i-th character of the string si equals '0' if the i-th lamp is turned off or '1' if the i-th lamp is turned on. You are also given a positive integer k.

In one move, you can choose one lamp and change its state (i.e. turn it on if it is turned off and vice versa).

The garland is called k-periodic if the distance between each pair of adjacent turned on lamps is exactly k. Consider the case k=3. Then garlands "00010010", "1001001", "00010" and "0" are good but garlands "00101001", "1000001" and "01001100" are not. Note that the garland is not cyclic, i.e. the first turned on lamp is not going after the last turned on lamp and vice versa.

Your task is to find the minimum number of moves you need to make to obtain k-periodic garland from the given one.

You have to answer t independent test cases.

Input
The first line of the input contains one integer t (1≤t≤25 000) — the number of test cases. Then t test cases follow.

The first line of the test case contains two integers n and k (1≤n≤106;1≤k≤n) — the length of s and the required period. The second line of the test case contains the string s consisting of n characters '0' and '1'.

It is guaranteed that the sum of n over all test cases does not exceed 106 (∑n≤106).

Output
For each test case, print the answer — the minimum number of moves you need to make to obtain k-periodic garland from the given one.

풀이:
문자열을 k 번씩 건너뛰어가며 자릅니다.
100011010 , k = 3 이라면

1 : 100
2 : 011
3 : 010
과 같이 됩니다. 이제 위 부분 문자열은 모두 0이 되던가, 단 하나의 문자열만 전부 1이 되야 합니다.

최종적으로 구해야 하는 값은 바꿔야하는 0 혹은 1의 개수의 최소값인데,
그 말은 즉 이미 완성되어있는 1은 최대한 살려가며 1을 없애는 게 최적일 것입니다.

위 예에선 2번째 부분 문자열을 살려서 나머지 1두 개를 지우는게 최적입니다.
0에는 -1의 패널티를 주고 1에는 +1의 값을 준 뒤 부분 문자열에 대해 총 합을 구합니다.(단, 총 합이 0보다 작아질 경우 0 그대로입니다.)
구해지는 총 합 중 최대값이 가장 길게 살릴 수 있는 1의 개수가 되므로, 총 1의 개수에서 구한 값을 빼주면 답이 됩니다.
*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>
#define pic pair<int, char>
#define ll long long
#define vi vector<int>
#define vl vector<long long>
#define vii vector<pii>
#define IMAX 2000000001
int mv1[4] = { 0, 0, 1, -1 };
int mv2[4] = { 1, -1, 0, 0 };

int t, n, k;
string str;
int dp[1000001];

int main(void) {
	FIO;

	cin >> t;

	while (t--) {
		cin >> n >> k >> str;

		int all = 0;
		int ans = 0;

		for (int i = 0; i < k; i++)
		{
			if (str[i] == '1')
				all++;

			ans = max(ans, dp[i] = (int)(str[i] - '0'));
			//매번 가장 긴 1의 개수를 비교합니다.
			for (int j = i + k; j < n; j = j + k)
			{
				if (str[j] == '0')
					dp[j] = max(0, dp[j - k] - 1);
				else {
					dp[j] = dp[j - k] + 1;
					all++;
				}
				ans = max(ans, dp[j]);
				//매번 가장 긴 1의 개수를 비교합니다.
			}
		}

		cout << all - ans << "\n";
	}
}