﻿/*
A. Sum of Round Numbers
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
A positive (strictly greater than zero) integer is called round if it is of the form d00...0. In other words, a positive integer is round if all its digits except the leftmost (most significant) are equal to zero. In particular, all numbers from 1 to 9 (inclusive) are round.

For example, the following numbers are round: 4000, 1, 9, 800, 90. The following numbers are not round: 110, 707, 222, 1001.

You are given a positive integer n (1≤n≤104). Represent the number n as a sum of round numbers using the minimum number of summands (addends). In other words, you need to represent the given number n as a sum of the least number of terms, each of which is a round number.

Input
The first line contains an integer t (1≤t≤104) — the number of test cases in the input. Then t test cases follow.

Each test case is a line containing an integer n (1≤n≤104).

Output
Print t answers to the test cases. Each answer must begin with an integer k — the minimum number of summands. Next, k terms must follow, each of which is a round number, and their sum is n. The terms can be printed in any order. If there are several answers, print any of them.

풀이:
일의 자리, 십의 자리, 백의 자리.... 순으로 10, 100, 1000 의 나머지를 출력해가면 됩니다.
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

int t, n;

int main(void) {
	FIO;

	cin >> t;

	while (t--) {
		cin >> n;

		vector<int> vt;

		int d = 10;

		while (d <= n * 10) {
			if (n % d != 0) {
				vt.push_back(n % d);
				n -= n % d;
			}

			d *= 10;
		}

		cout << vt.size() << "\n";
		for (int i = 0; i < vt.size(); i++)
		{
			cout << vt[i] << " ";
		}
		cout << "\n";
	}
}