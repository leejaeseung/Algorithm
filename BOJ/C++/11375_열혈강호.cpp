/*
문제
강호네 회사에는 직원이 N명이 있고, 해야할 일이 M개가 있다. 직원은 1번부터 N번까지 번호가 매겨져 있고, 일은 1번부터 M번까지 번호가 매겨져 있다.

각 직원은 한 개의 일만 할 수 있고, 각각의 일을 담당하는 사람은 1명이어야 한다.

각각의 직원이 할 수 있는 일의 목록이 주어졌을 때, M개의 일 중에서 최대 몇 개를 할 수 있는지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 직원의 수 N과 일의 개수 M이 주어진다. (1 ≤ N, M ≤ 1,000)

둘째 줄부터 N개의 줄의 i번째 줄에는 i번 직원이 할 수 있는 일의 개수와 할 수 있는 일의 번호가 주어진다.

출력
첫째 줄에 강호네 회사에서 할 수 있는 일의 개수를 출력한다.

풀이:
모든 간선의 유량을 1로 생각하고 에드몬드-카프 알고리즘으로 풀이했다.
매번 경로를 찾을 때마다 BFS 하느라 시간이 빠듯한 것 같다.

이분 매칭의 특성을 고려하면 매 경로의 최소 유량은 항상 1이다.
*/
#include<iostream>
#include<memory.h>
#include<algorithm>
#include<math.h>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>
#define pdd pair<double, double>
#define pic pair<int, char>
#define ll long long
#define pll pair<ll, ll>
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vii vector<pii>
#define IMAX 2000000001
#define LMAX 1000000000000000000
#define DMAX 0xFFFFFFFFFFFFF
#define MOD 100003
int mv1[4] = { 0, 0, 1, -1 };
int mv2[4] = { 1, -1, 0, 0 };
int mv_all1[8] = { 0, 1, 0, -1, -1, -1, 1, 1 };
int mv_all2[8] = { 1, 0, -1, 0 , -1, 1, -1, 1 };

int n, m;
vector<int> edge[2004];
int f[2004][2004];
int c[2004][2004];
int s, e;

int main(void) {
	FIO;

	cin >> n >> m;

	s = 0;
	e = 2003;

	for (int i = 1; i <= n; i++)
	{
		int cnt;
		cin >> cnt;

		edge[0].push_back(i);
		edge[i].push_back(0);
		c[i][0] = 1;
		c[0][i] = 1;

		for (int j = 0; j < cnt; j++)
		{
			int job;
			cin >> job;

			job += 1000;

			edge[i].push_back(job);
			edge[job].push_back(i);
			c[job][i] = 1;
			c[i][job] = 1;
		}
	}

	for (int i = 1001; i <= m + 1000; i++)
	{
		edge[i].push_back(e);
		edge[e].push_back(i);
		c[e][i] = 1;
		c[i][e] = 1;
	}

	int ans = 0;
	
	while (true) {
		int prev[2004];
		fill(&prev[0], &prev[2004], -1);

		queue<int> q;
		q.push(s);

		while (!q.empty() && prev[e] == -1) {
			int now = q.front();
			q.pop();

			for (int i = 0; i < edge[now].size(); i++)
			{
				int next = edge[now][i];

				if (prev[next] == -1 && c[now][next] > f[now][next]) {
					prev[next] = now;

					q.push(next);

					if (next == e)	break;
				}
			}
		}

		if (prev[e] == -1)	break;

		int cur = e;

		while (cur != s) {
			f[prev[cur]][cur] += 1;
			f[cur][prev[cur]] -= 1;

			cur = prev[cur];
		}

		ans++;
	}

	cout << ans;
}