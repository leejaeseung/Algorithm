/*
A. Ice Skating
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Bajtek is learning to skate on ice. He's a beginner, so his only mode of transportation is pushing off from a snow drift to the north, east, south or west and sliding until he lands in another snow drift. He has noticed that in this way it's impossible to get from some snow drifts to some other by any sequence of moves. He now wants to heap up some additional snow drifts, so that he can get from any snow drift to any other one. He asked you to find the minimal number of snow drifts that need to be created.

We assume that Bajtek can only heap up snow drifts at integer coordinates.

Input
The first line of input contains a single integer n (1 ≤ n ≤ 100) — the number of snow drifts. Each of the following n lines contains two integers xi and yi (1 ≤ xi, yi ≤ 1000) — the coordinates of the i-th snow drift.

Note that the north direction coinсides with the direction of Oy axis, so the east direction coinсides with the direction of the Ox axis. All snow drift's locations are distinct.

Output
Output the minimal number of snow drifts that need to be created in order for Bajtek to be able to reach any snow drift from any other one.

풀이:
유니온-파인드 문제였습니다.

찍힌 점들 중 서로 이동할 수 있는 점들을 하나의 그룹으로 생각하면, 
여러 개의 그룹이 생기는데 n개의 그룹을 서로 이동 가능하게 하려면 최소 n - 1개의 점을 찍어야 함을 알 수 있습니다.
-> 두 개의 그룹은 하나의 점을 찍으면 이동 가능하고, 
만약 세 그룹이 하나의 점을 찍어서 모두 이동 가능하다면, 세 그룹 중 이미 두 그룹은 점을 찍기 전부터 이동 가능했던 것입니다.

유니온-파인드 알고리즘을 통해 그룹의 수를 세어주면 됩니다.
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
#define vc vector<char>
#define vii vector<pii>
#define IMAX 2000000001
#define LMAX 1000000000000000000
#define DMAX 0xFFFFFFFFFFFFF
int mv1[4] = { 0, 1, 0, -1 };
int mv2[4] = { 1, 0, -1, 0 };

int n;
vii vt;
int parent[101];
bool check[101];

int find(int x) {
	if (x == parent[x]) {
		return x;
	}
	return parent[x] = find(parent[x]);
}

void merge(int x, int y) {

	x = find(x);
	y = find(y);

	if (x != y) {
		parent[x] = y;
	}
}

int main(void) {
	FIO;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		vt.push_back(make_pair(x, y));
		parent[i] = i;
	}

	for (int i = 0; i < vt.size() - 1; i++)
	{
		pii now = vt[i];

		for (int j = i + 1; j < vt.size(); j++)
		{
			pii comp = vt[j];

			if (now.first == comp.first || now.second == comp.second) {
				merge(i, j);
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		check[find(i)] = true;
	}
	int cnt = 0;

	for (int i = 0; i < n; i++)
	{
		if (check[i])
			cnt++;
	}

	cout << cnt - 1;
}