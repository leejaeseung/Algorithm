/*
E. Paths and Trees
time limit per test3 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Little girl Susie accidentally found her elder brother's notebook. She has many things to do, more important than solving problems, but she found this problem too interesting, so she wanted to know its solution and decided to ask you about it. So, the problem statement is as follows.

Let's assume that we are given a connected weighted undirected graph G = (V, E) (here V is the set of vertices, E is the set of edges). The shortest-path tree from vertex u is such graph G1 = (V, E1) that is a tree with the set of edges E1 that is the subset of the set of edges of the initial graph E, and the lengths of the shortest paths from u to any vertex to G and to G1 are the same.

You are given a connected weighted undirected graph G and vertex u. Your task is to find the shortest-path tree of the given graph from vertex u, the total weight of whose edges is minimum possible.

Input
The first line contains two numbers, n and m (1 ≤ n ≤ 3·105, 0 ≤ m ≤ 3·105) — the number of vertices and edges of the graph, respectively.

Next m lines contain three integers each, representing an edge — ui, vi, wi — the numbers of vertices connected by an edge and the weight of the edge (ui ≠ vi, 1 ≤ wi ≤ 109). It is guaranteed that graph is connected and that there is no more than one edge between any pair of vertices.

The last line of the input contains integer u (1 ≤ u ≤ n) — the number of the start vertex.

Output
In the first line print the minimum total weight of the edges of the tree.

In the next line print the indices of the edges that are included in the tree, separated by spaces. The edges are numbered starting from 1 in the order they follow in the input. You may print the numbers of the edges in any order.

If there are multiple answers, print any of them.

풀이:
구하고자 하는 값은 기존의 최단 경로를 유지하면서, 모든 노드를 거치는 최소 경로 값입니다.

먼저 다익스트라 알고리즘을 한 번 사용해 기존의 최단경로를 모두 구합니다.

다익스트라를 한 번 더 사용하는데, 이 때 다음 탐색할 노드까지의 거리가 기존 최단 경로 값과 같은 지 비교해줍니다.
같지 않다면 그 엣지는 사용할 필요가 없습니다.
같다면, 새로운 최단 경로를 갱신해가는데, 이 때 이전 노드의 번호를 back-link 해갑니다.(노드의 번호와 해당 엣지의 index 둘 다)
최단 경로라면 해당 엣지의 가중치만큼을 ans에 더해줍니다.

만약 중복 경로라면(dist[next] == dist[now] + dis) 현재 엣지와 next의 기존에 연결된 엣지 중 하나만을 사용해야 합니다.
(ans 값이 최소가 되게 하기 위해 중복되는 경로를 제거해야 합니다.)
기존 연결된 엣지의 길이를 ans에서 빼주고, 현재 엣지를 다시 더해줍니다.
현재 엣지를 연결했으므로 back-link도 현재 엣지로 걸어줍니다.
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

int n, m, u;
vector<pair<pil, int>> edge[300001];
ll ori_dist[300001];
ll dist[300001];
bool edges[300001];
ll edge_leng[300001];
pii route[300001];
ll ans = 0;

void Dijkstra() {
	priority_queue<pli> pq;
	ori_dist[u] = 0;
	pq.push(make_pair(0, u));

	while (!pq.empty()) {
		int now = pq.top().second;
		ll nowD = -pq.top().first;
		pq.pop();

		if (nowD < ori_dist[now])	continue;

		for (int i = 0; i < edge[now].size(); i++)
		{
			int next = edge[now][i].first.first;
			ll dis = edge[now][i].first.second;

			if (ori_dist[next] > ori_dist[now] + dis) {
				ori_dist[next] = ori_dist[now] + dis;

				pq.push(make_pair(-ori_dist[next], next));
			}
		}
	}
}

void Dijkstra2() {
	priority_queue<pli> pq;
	dist[u] = 0;
	pq.push(make_pair(0, u));

	while (!pq.empty()) {
		int now = pq.top().second;
		ll nowD = -pq.top().first;
		pq.pop();

		if (nowD < dist[now])	continue;

		for (int i = 0; i < edge[now].size(); i++)
		{
			int next = edge[now][i].first.first;
			ll dis = edge[now][i].first.second;
			int idx = edge[now][i].second;

			if (dist[next] > dist[now] + dis && ori_dist[next] == dist[now] + dis) {
				dist[next] = dist[now] + dis;
				route[next] = make_pair(now, idx);
				ans += dis;

				pq.push(make_pair(-dist[next], next));
			}
			else if (dist[next] == dist[now] + dis && ori_dist[next] == dist[now] + dis) {
				ans -= edge_leng[route[next].second];
				ans += dis;
				route[next] = make_pair(now, idx);
			}
		}
	}
}

void DFS(int now) {

	for (int i = 0; i < edge[now].size(); i++)
	{
		int next = edge[now][i].first.first;
		if (route[next].first != now)	continue;

		cout << route[next].second << " ";
		DFS(next);
	}
}

int main(void) {
	FIO;

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		ori_dist[i] = LMAX;
		dist[i] = LMAX;
		route[i] = make_pair(-1, -1);
	}

	for (int i = 1; i <= m; i++)
	{
		int s, e;
		ll v;
		cin >> s >> e >> v;

		edge[s].push_back(make_pair(make_pair(e, v), i));
		edge[e].push_back(make_pair(make_pair(s, v), i));
		edge_leng[i] = v;
	}
	cin >> u;

	Dijkstra();
	Dijkstra2();

	cout << ans << "\n";
	DFS(u);
}