/*
B. Shuffle
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given an array consisting of n integers a1, a2, ..., an. Initially ax=1, all other elements are equal to 0.

You have to perform m operations. During the i-th operation, you choose two indices c and d such that li≤c,d≤ri, and swap ac and ad.

Calculate the number of indices k such that it is possible to choose the operations so that ak=1 in the end.

Input
The first line contains a single integer t (1≤t≤100) — the number of test cases. Then the description of t testcases follow.

The first line of each test case contains three integers n, x and m (1≤n≤109; 1≤m≤100; 1≤x≤n).

Each of next m lines contains the descriptions of the operations; the i-th line contains two integers li and ri (1≤li≤ri≤n).

Output
For each test case print one integer — the number of indices k such that it is possible to choose the operations so that ak=1 in the end.

문제 설명:
처음엔 x 에만 1이 놓여져 있고, m 개의 구간이 주어지는데, 순서대로 주어지는 구간에 대해
해당 구간 안에 1이 있으면 그 구간을 모두 1로 칠해가는 문제입니다.

풀이:
시작과 끝 구간을 처음엔 x로 놓고, 각 operation 마다 현재 구간이 해당 구간에 포함되는 지 판단해주고, 
포함된다면 시작, 끝 구간을 넓혀가면 됩니다.
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
#define pil pair<int, long long>
#define pli pair<long long, int>
#define ll long long
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vii vector<pii>
#define IMAX 2000000001
#define LMAX 9000000000000000000
#define DMAX 0xFFFFFFFFFFFFF
int mv1[4] = { 0, 1, 0, -1 };
int mv2[4] = { 1, 0, -1, 0 };

int t, n, m, x;

int main(void) {
	FIO;

	cin >> t;

	while (t--) {
		cin >> n >> x >> m;

		int s = x;
		int e = x;

		for (int i = 0; i < m; i++)
		{
			int l, r;
			cin >> l >> r;

			if ((r >= s && l < s) || (e >= l && r > e) || (l < s && r > e)) {
				s = min(s, l);
				e = max(r, e);
			}
		}
		cout << e - s + 1 << "\n";

	}
}