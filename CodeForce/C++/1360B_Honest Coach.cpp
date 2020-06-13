/*
B. Honest Coach
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
There are n athletes in front of you. Athletes are numbered from 1 to n from left to right. You know the strength of each athlete — the athlete number i has the strength si.

You want to split all athletes into two teams. Each team must have at least one athlete, and each athlete must be exactly in one team.

You want the strongest athlete from the first team to differ as little as possible from the weakest athlete from the second team. Formally, you want to split the athletes into two teams A and B so that the value |max(A)−min(B)| is as small as possible, where max(A) is the maximum strength of an athlete from team A, and min(B) is the minimum strength of an athlete from team B.

For example, if n=5 and the strength of the athletes is s=[3,1,2,6,4], then one of the possible split into teams is:

first team: A=[1,2,4],
second team: B=[3,6].
In this case, the value |max(A)−min(B)| will be equal to |4−3|=1. This example illustrates one of the ways of optimal split into two teams.

Print the minimum value |max(A)−min(B)|.

Input
The first line contains an integer t (1≤t≤1000) — the number of test cases in the input. Then t test cases follow.

Each test case consists of two lines.

The first line contains positive integer n (2≤n≤50) — number of athletes.

The second line contains n positive integers s1,s2,…,sn (1≤si≤1000), where si — is the strength of the i-th athlete. Please note that s values may not be distinct.

Output
For each test case print one integer — the minimum value of |max(A)−min(B)| with the optimal split of all athletes into two teams. Each of the athletes must be a member of exactly one of the two teams.

풀이:
배열을 정렬한 뒤 인접한 두 개의 원소의 차이가 최소인 값을 출력하면 됩니다.
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

int main(void) {
	FIO;

	cin >> t;

	while (t--) {
		cin >> n;
		vi vt;
		priority_queue<int> A;
		priority_queue<int> B;

		for (int i = 0; i < n; i++)
		{
			int v;
			cin >> v;
			vt.push_back(v);
		}

		sort(vt.begin(), vt.end());
		int ans = IMAX;

		for (int i = 0; i < vt.size() - 1; i++)
		{
			ans = min(ans, abs(vt[i] - vt[i + 1]));
		}
		cout << ans << "\n";
	}
}