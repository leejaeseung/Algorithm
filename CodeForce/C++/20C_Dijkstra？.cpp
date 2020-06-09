/*
C. Dijkstra?
time limit per test1 second
memory limit per test64 megabytes
inputstandard input
outputstandard output
You are given a weighted undirected graph. The vertices are enumerated from 1 to n. Your task is to find the shortest path between the vertex 1 and the vertex n.

Input
The first line contains two integers n and m (2 ≤ n ≤ 105, 0 ≤ m ≤ 105), where n is the number of vertices and m is the number of edges. Following m lines contain one edge each in form ai, bi and wi (1 ≤ ai, bi ≤ n, 1 ≤ wi ≤ 106), where ai, bi are edge endpoints and wi is the length of the edge.

It is possible that the graph has loops and multiple edges between pair of vertices.

Output
Write the only integer -1 in case of no path. Write the shortest path in opposite case. If there are many solutions, print any of them.

풀이:
다익스트라 알고리즘에 back 경로를 추가한 문제였습니다.
다익스트라 알고리즘에서 최단 거리 값을 갱신할 때마다 back link를 이어주고, 
n 에서부터 1 까지 back link를 타고 역으로 출력해주면 됩니다.
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
#define pll pair<long long, long long>
#define pdd pair<double, double>
#define pic pair<int, char>
#define ll long long
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vii vector<pii>
#define vll vector<pll>
#define IMAX 2000000001
#define LMAX 1000000000000000000
#define DMAX 0xFFFFFFFFFFFFF
int mv1[4] = { 0, 1, 0, -1 };
int mv2[4] = { 1, 0, -1, 0 };

int n, m;
ll dist[100001];
vll edge[100001];
int back[100001];

void Dijkstra() {
	priority_queue<pair<ll, int>> pq;
	dist[1] = 0;
	pq.push(make_pair(0, 1));


	while (!pq.empty()) {
		int now = pq.top().second;
		ll d = -pq.top().first;
		pq.pop();

		if (dist[now] > d)	continue;

		for (int i = 0; i < edge[now].size(); i++)
		{
			int next = edge[now][i].first;
			ll dis = edge[now][i].second;

			if (dist[next] > dist[now] + dis) {
				dist[next] = dist[now] + dis;
				back[next] = now;
				pq.push(make_pair(-dist[next], next));
			}
		}

	}
}

int main(void) {
	FIO;

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int from, to;
		ll v;
		cin >> from >> to >> v;

		edge[from].push_back(make_pair(to, v));
		edge[to].push_back(make_pair(from, v));
	}

	for (int i = 0; i <= n; i++)
	{
		dist[i] = LMAX;
		back[i] = -1;
	}

	Dijkstra();

	int now = n;
	stack<int> out;

	if (dist[n] != LMAX) {
		while (n != -1) {
			out.push(n);
			n = back[n];
		}
		while (!out.empty()) {
			cout << out.top() << " ";
			out.pop();
		}
	}
	else {
		cout << "-1";
	}
}