/*
B. Same Parity Summands
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given two positive integers n (1≤n≤109) and k (1≤k≤100). Represent the number n as the sum of k positive integers of the same parity (have the same remainder when divided by 2).

In other words, find a1,a2,…,ak such that all ai>0, n=a1+a2+…+ak and either all ai are even or all ai are odd at the same time.

If such a representation does not exist, then report it.

Input
The first line contains an integer t (1≤t≤1000) — the number of test cases in the input. Next, t test cases are given, one per line.

Each test case is two positive integers n (1≤n≤109) and k (1≤k≤100).

Output
For each test case print:

YES and the required values ai, if the answer exists (if there are several answers, print any of them);
NO if the answer does not exist.
The letters in the words YES and NO can be printed in any case.

풀이:
예제 출력을 보고 헷갈릴 수 있는 문제였습니다.
짝수의 가장 작은 수는 2이고, 홀수의 가장 작은 수는 1입니다.
따라서 2를 k - 1 번만큼 n에서 빼주고, 남은 수가 짝수라면 n은 k개의 짝수로 만들 수 있습니다.
마찬가지로 1을 k - 1번만큼 n에서 빼주고, 남은 수가 홀수라면 n은 k개의 홀수로 만들 수 있습니다.
위 두 가지 경우가 아니라면 "NO"를 출력하면 됩니다.
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

int t, n, k;

int main(void) {
	FIO;

	cin >> t;

	while (t--) {
		cin >> n >> k;

		int tempEven = n - (k - 1) * 2;
		int tempOdd = n - (k - 1);
		int tempN = n;
		if (tempEven > 0 && tempEven % 2 == 0) {
			cout << "YES" << "\n";
			for (int i = 0; i < k - 1; i++)
			{
				cout << "2 ";
				tempN -= 2;
			}
			cout << tempN << "\n";
		}
		else if(tempOdd > 0 && tempOdd % 2 == 1){
			cout << "YES" << "\n";
			for (int i = 0; i < k - 1; i++)
			{
				cout << "1 ";
				tempN -= 1;
			}
			cout << tempN << "\n";

		}
		else {
			cout << "NO" << "\n";
		}
	}
}