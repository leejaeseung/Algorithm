/*
C. Similar Pairs
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
We call two numbers x and y similar if they have the same parity (the same remainder when divided by 2), or if |x−y|=1. For example, in each of the pairs (2,6), (4,3), (11,7), the numbers are similar to each other, and in the pairs (1,4), (3,12), they are not.

You are given an array a of n (n is even) positive integers. Check if there is such a partition of the array into pairs that each element of the array belongs to exactly one pair and the numbers in each pair are similar to each other.

For example, for the array a=[11,14,16,12], there is a partition into pairs (11,12) and (14,16). The numbers in the first pair are similar because they differ by one, and in the second pair because they are both even.

Input
The first line contains a single integer t (1≤t≤1000) — the number of test cases. Then t test cases follow.

Each test case consists of two lines.

The first line contains an even positive integer n (2≤n≤50) — length of array a.

The second line contains n positive integers a1,a2,…,an (1≤ai≤100).

Output
For each test case print:

YES if the such a partition exists,
NO otherwise.
The letters in the words YES and NO can be displayed in any case.

풀이:
홀수의 개수가 짝수 개, 짝수의 개수가 짝수 개이면 무조건 YES입니다.
마찬가지로 짝수 개, 홀수 개(홀수 개, 짝수 개)이면 절대 만들 수 없으므로 NO입니다.

홀수 개, 홀수 개일 때 인접한 수의 개수를 고려해야 합니다.
1차이가 나는 수의 개수를 먼저 세줍니다.(sim)

1차이가 나는 수가 하나라도 있으면 홀수, 짝수를 각각 하나씩 줄여줄 수 있으므로 무조건 YES가 됩니다.
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
#define pdd pair<double, double>
#define pic pair<int, char>
#define ll long long
#define vi vector<int>
#define vl vector<long long>
#define vii vector<pii>
#define IMAX 2000000001
#define LMAX 1000000000000000000
#define DMAX 0xFFFFFFFFFFFFF
int mv1[4] = { 0, 1, 0, -1 };
int mv2[4] = { 1, 0, -1, 0 };

int t, n;
int c[101];

int main(void) {
	FIO;

	cin >> t;

	while (t--) {
		cin >> n;
		vi vt;
		for (int i = 0; i < 101; i++)
		{
			c[i] = 0;
		}

		int cntE = 0;
		int cntO = 0;

		for (int i = 0; i < n; i++)
		{
			int v;
			cin >> v;
			vt.push_back(v);
			if (v % 2 == 0)
				cntE++;
			else
				cntO++;
		}

		sort(vt.begin(), vt.end());

		
		int sim = 0;
		for (int i = 0; i < vt.size() - 1; i++)
		{
			if (abs(vt[i] - vt[i + 1]) == 1) {
				sim++;
				i++;
			}
		}

		if (cntE % 2 == 0 && cntO % 2 == 0)
			cout << "YES\n";
		else if(cntE % 2 != 0 && cntO % 2 != 0){
			if (sim > 0) {
				cout << "YES\n";
			}
			else
				cout << "NO\n";
		}
		else {
			cout << "NO\n";
		}

	}
}