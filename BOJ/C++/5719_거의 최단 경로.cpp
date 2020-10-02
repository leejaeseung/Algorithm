/*
문제
요즘 많은 자동차에서는 GPS 네비게이션 장비가 설치되어 있다. 네비게이션은 사용자가 입력한 출발점과 도착점 사이의 최단 경로를 검색해 준다. 하지만, 교통 상황을 고려하지 않고 최단 경로를 검색하는 경우에는 극심한 교통 정체를 경험할 수 있다.

상근이는 오직 자기 자신만 사용 가능한 네비게이션을 만들고 있다. 이 네비게이션은 절대로 최단 경로를 찾아주지 않는다. 항상 거의 최단 경로를 찾아준다.

거의 최단 경로란 최단 경로에 포함되지 않는 도로로만 이루어진 경로 중 가장 짧은 것을 말한다.

예를 들어, 도로 지도가 아래와 같을 때를 생각해보자. 원은 장소를 의미하고, 선은 단방향 도로를 나타낸다. 시작점은 S, 도착점은 D로 표시되어 있다. 굵은 선은 최단 경로를 나타낸다. (아래 그림에 최단 경로는 두 개가 있다)거의 최단 경로는 점선으로 표시된 경로이다. 이 경로는 최단 경로에 포함되지 않은 도로로 이루어진 경로 중 가장 짧은 경로이다. 거의 최단 경로는 여러 개 존재할 수도 있다. 예를 들어, 아래 그림의 길이가 3인 도로의 길이가 1이라면, 거의 최단 경로는 두 개가 된다. 또, 거의 최단 경로가 없는 경우도 있다.



입력
입력은 여러 개의 테스트 케이스로 이루어져 있다. 각 테스트 케이스의 첫째 줄에는 장소의 수 N (2 ≤ N ≤ 500)과 도로의 수 M (1 ≤ M ≤ 104)가 주어진다. 장소는 0부터 N-1번까지 번호가 매겨져 있다. 둘째 줄에는 시작점 S와 도착점 D가 주어진다. (S ≠ D; 0 ≤ S, D < N) 다음 M개 줄에는 도로의 정보 U, V, P가 주어진다. (U ≠ V ; 0 ≤ U, V < N; 1 ≤ P ≤ 103) 이 뜻은 U에서 V로 가는 도로의 길이가 P라는 뜻이다. U에서 V로 가는 도로는 최대 한 개이다. 또, U에서 V로 가는 도로와 V에서 U로 가는 도로는 다른 도로이다.

입력의 마지막 줄에는 0이 두 개 주어진다.

출력
각 테스트 케이스에 대해서, 거의 최단 경로의 길이를 출력한다. 만약, 거의 최단 경로가 없는 경우에는 -1을 출력한다.

풀이:
다익스트라 + BFS 알고리즘 문제이다.
다익스트라로 최단 경로를 모두 구하고, 도착점에서 시작점까지의 back trace를 저장한다.
그 후 BFS를 도착점부터 돌면서 모든 도착점으로의 경로를 없애준다.
(BFS에서 방문 체크를 해주지 않아 재채점 시 메모리 초과가 났다. 큐에 중복된 값이 많이 들어가서 그런듯 하다)

최단 경로를 없앤 뒤 다시 다익스트라로 답을 구하면 된다.
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
int mv1[4] = { 0, 1, 0, -1 };
int mv2[4] = { 1, 0, -1, 0 };
int mv_all1[8] = { 0, 1, 0, -1, -1, -1, 1, 1 };
int mv_all2[8] = { 1, 0, -1, 0 , -1, 1, -1, 1 };

int n, m;
int s, e;
int dist[501];
vector<pii> edge[501];
vector<int> prv[501];

void Dijkstra() {
	fill(&dist[0], &dist[501], IMAX);
	priority_queue<pii> pq;

	pq.push({ 0, s });
	dist[s] = 0;

	while (!pq.empty()) {
		int now = pq.top().second;
		int nowDis = -pq.top().first;
		pq.pop();

		if (nowDis > dist[now])	continue;

		for (int i = 0; i < edge[now].size(); i++)
		{
			int nx = edge[now][i].first;
			int nxDis = edge[now][i].second;

			if (dist[nx] > dist[now] + nxDis) {
				dist[nx] = dist[now] + nxDis;

				prv[nx].clear();
				prv[nx].push_back(now);

				pq.push({ -dist[nx], nx });
			}
			else if (dist[nx] == dist[now] + nxDis) {
				prv[nx].push_back(now);
			}
		}
	}
}

void BFS() {
	bool visit[501][501];
	fill(&visit[0][0], &visit[500][501], false);

	queue<int> q;
	q.push(e);

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 0; i < prv[now].size(); i++)
		{
			int nx = prv[now][i];

			if (visit[nx][now])	continue;
			visit[nx][now] = true;

			for (int j = 0; j < edge[nx].size(); j++)
			{
				if (edge[nx][j].first == now) {
					edge[nx][j].second = IMAX;
					q.push(nx);
				}
			}
		}
	}
}

int main(void) {
	FIO;

	while (true) {
		cin >> n >> m;

		if (n == 0 && m == 0)	break;

		cin >> s >> e;

		for (int i = 0; i < 501; i++)
		{
			edge[i].clear();
			prv[i].clear();
		}

		for (int i = 0; i < m; i++)
		{
			int a, b, c;
			cin >> a >> b >> c;

			edge[a].push_back({b, c});
		}

		Dijkstra();
		BFS();
		Dijkstra();

		if (dist[e] == IMAX)
			cout << "-1\n";
		else
			cout << dist[e] << "\n";
	}
}