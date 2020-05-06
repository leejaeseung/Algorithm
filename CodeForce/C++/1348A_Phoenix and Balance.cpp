/*
A. Phoenix and Balance
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Phoenix has n coins with weights 21,22,…,2n. He knows that n is even.

He wants to split the coins into two piles such that each pile has exactly n2 coins and the difference of weights between the two piles is minimized. Formally, let a denote the sum of weights in the first pile, and b denote the sum of weights in the second pile. Help Phoenix minimize |a−b|, the absolute value of a−b.

Input
The input consists of multiple test cases. The first line contains an integer t (1≤t≤100) — the number of test cases.

The first line of each test case contains an integer n (2≤n≤30; n is even) — the number of coins that Phoenix has.

Output
For each test case, output one integer — the minimum possible difference of weights between the two piles.

풀이:
그리디 알고리즘이었습니다.
수열을 쭉 늘어놨을 때, 
맨 오른쪽 수 + 왼쪽부터 N / 2 개가 될 때까지 더한 수에서
나머지 수를 빼주면 정답이 됩니다.
*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<vector>
#include<set>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>
#define ll long long

int T, N;

int main(void) {
	FIO;

	cin >> T;

	while (T--) {
		cin >> N;

		vector<ll> vt;
		ll A = 0;
		ll B = 0;

		for (int i = 1; i <= N; i++)
		{
			vt.push_back(pow(2, i));
			B += vt[i - 1];
		}

		A = vt[N - 1];
		B -= vt[N - 1];
		
		for (int i = 0; i < N / 2 - 1; i++)
		{
			A += vt[i];
			B -= vt[i];
		}

		cout << A - B << "\n";
	}
}