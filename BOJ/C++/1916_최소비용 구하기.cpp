/*
문제
N개의 도시가 있다. 그리고 한 도시에서 출발하여 다른 도시에 도착하는 M개의 버스가 있다. 우리는 A번째 도시에서 B번째 도시까지 가는데 드는 버스 비용을 최소화 시키려고 한다. A번째 도시에서 B번째 도시까지 가는데 드는 최소비용을 출력하여라. 도시의 번호는 1부터 N까지이다.

입력
첫째 줄에 도시의 개수 N(1 ≤ N ≤ 1,000)이 주어지고 둘째 줄에는 버스의 개수 M(1 ≤ M ≤ 100,000)이 주어진다. 그리고 셋째 줄부터 M+2줄까지 다음과 같은 버스의 정보가 주어진다. 먼저 처음에는 그 버스의 출발 도시의 번호가 주어진다. 그리고 그 다음에는 도착지의 도시 번호가 주어지고 또 그 버스 비용이 주어진다. 버스 비용은 0보다 크거나 같고, 100,000보다 작은 정수이다.

그리고 M+3째 줄에는 우리가 구하고자 하는 구간 출발점의 도시번호와 도착점의 도시번호가 주어진다. 출발점에서 도착점을 갈 수 있는 경우만 입력으로 주어진다.

출력
첫째 줄에 출발 도시에서 도착 도시까지 가는데 드는 최소 비용을 출력한다.

풀이:
다익스트라 연습문제
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
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define pic pair<int, char>
#define ll long long
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vii vector<pii>
#define IMAX 2147483647
#define LMAX 1000000000000500000
#define DMAX 0xFFFFFFFFFFFFF
int mv1[4] = { 0, 1, -1, 0 };
int mv2[4] = { 1, 0, 0, -1 };

int n, m;
vector<pll> vt[1001];
ll dist[1001];
int s, e;

void Dijkstra() {
	dist[s] = 0;

	priority_queue<pll> pq;
	pq.push({ 0, s });

	while (!pq.empty()) {
		ll nowDis = -pq.top().first;
		ll now = pq.top().second;
		pq.pop();

		if (nowDis > dist[now])	continue;

		for (int i = 0; i < vt[now].size(); i++)
		{
			ll next = vt[now][i].first;
			ll nextDis = vt[now][i].second;

			if (dist[next] > dist[now] + nextDis) {
				dist[next] = dist[now] + nextDis;
				pq.push({ -dist[next], next });
			}
		}
	}
	
}

int main(void) {
	FIO;

	cin >> n >> m;
	fill(&dist[0], &dist[1001], LMAX);

	for (int i = 0; i < m; i++)
	{
		ll from, to, v;
		cin >> from >> to >> v;

		vt[from].push_back({ to, v });
	}
	
	cin >> s >> e;

	Dijkstra();

	cout << dist[e];
}