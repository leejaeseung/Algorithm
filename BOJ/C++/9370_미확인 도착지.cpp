/*
문제
(취익)B100 요원, 요란한 옷차림을 한 서커스 예술가 한 쌍이 한 도시의 거리들을 이동하고 있다. 너의 임무는 그들이 어디로 가고 있는지 알아내는 것이다. 우리가 알아낸 것은 그들이 s지점에서 출발했다는 것, 그리고 목적지 후보들 중 하나가 그들의 목적지라는 것이다. 그들이 급한 상황이기 때문에 목적지까지 우회하지 않고 최단거리로 갈 것이라 확신한다. 이상이다. (취익)

어휴! (요란한 옷차림을 했을지도 모를) 듀오가 어디에도 보이지 않는다. 다행히도 당신은 후각이 개만큼 뛰어나다. 이 후각으로 그들이 g와 h 교차로 사이에 있는 도로를 지나갔다는 것을 알아냈다.

이 듀오는 대체 어디로 가고 있는 것일까?



예제 입력의 두 번째 케이스를 시각화한 것이다. 이 듀오는 회색 원에서 두 검은 원 중 하나로 가고 있고 점선으로 표시된 도로에서 냄새를 맡았다. 따라서 그들은 6으로 향하고 있다.

입력
첫 번째 줄에는 테스트 케이스의 T(1 ≤ T ≤ 100)가 주어진다. 각 테스트 케이스마다

첫 번째 줄에 3개의 정수 n, m, t (2 ≤ n ≤ 2 000, 1 ≤ m ≤ 50 000 and 1 ≤ t ≤ 100)가 주어진다. 각각 교차로, 도로, 목적지 후보의 개수이다.
두 번째 줄에 3개의 정수 s, g, h (1 ≤ s, g, h ≤ n)가 주어진다. s는 예술가들의 출발지이고, g, h는 문제 설명에 나와 있다. (g ≠ h)
그 다음 m개의 각 줄마다 3개의 정수 a, b, d (1 ≤ a < b ≤ n and 1 ≤ d ≤ 1 000)가 주어진다. a와 b 사이에 길이 d의 양방향 도로가 있다는 뜻이다.
그 다음 t개의 각 줄마다 정수 x가 주어지는데, t개의 목적지 후보들을 의미한다. 이 t개의 지점들은 서로 다른 위치이며 모두 s와 같지 않다.
교차로 사이에는 도로가 많아봐야 1개이다. m개의 줄 중에서 g와 h 사이의 도로를 나타낸 것이 존재한다. 또한 이 도로는 목적지 후보들 중 적어도 1개로 향하는 최단 경로의 일부이다.

출력
테스트 케이스마다

입력에서 주어진 목적지 후보들 중 불가능한 경우들을 제외한 목적지들을 공백으로 분리시킨 오름차순의 정수들로 출력한다.

풀이:
다익스트라의 최단 경로를 모두 찾는 문제이다.
다익스트라 한 번으로 목적지까지의 모든 최단 경로를 prv 로부터 알 수 있고,
prv를 dfs로 순회하면서 g, h 의 경로가 포함되었는지 체크하면 된다.
*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<regex>
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

int T;
int n, m, t, s, g, h;
vector<pii> vt[2001];
int dist[2001];
vector<int> prv[2001];


void Dijkstra(int start) {
	priority_queue<pii> pq;
	pq.push({ 0, start });
	dist[start] = 0;

	while (!pq.empty()) {
		int nowDis = -pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (nowDis > dist[now])	continue;

		for (int i = 0; i < vt[now].size(); i++)
		{
			int next = vt[now][i].first;
			int nextDis = vt[now][i].second;

			if (dist[next] > dist[now] + nextDis) {
				dist[next] = dist[now] + nextDis;
				prv[next].clear();
				prv[next].push_back(now);

				pq.push({ -dist[next], next });
			}
			else if (dist[next] == dist[now] + nextDis) {
				prv[next].push_back(now);
			}
		}
	}
}

bool dfs(int now) {
	
	bool find = false;

	for (int i = 0; i < prv[now].size(); i++)
	{
		int next = prv[now][i];

		if ((now == g && next == h) || (now == h && next == g)) {
			find = true;
			break;
		}
		else {
			find = dfs(next);
			if (find)
				return true;
		}
	}

	return find;
}

int main(void) {
	FIO;

	cin >> T;

	while (T--) {
		cin >> n >> m >> t >> s >> g >> h;
		
		priority_queue<int> dest;

		for (int i = 0; i < 2001; i++)
		{
			vt[i].clear();
			dist[i] = IMAX;
			prv[i].clear();
		}

		for (int i = 0; i < m; i++)
		{
			int a, b, d;
			cin >> a >> b >> d;

			vt[a].push_back({ b, d });
			vt[b].push_back({ a, d });
		}

		for (int i = 0; i < t; i++)
		{
			int x;
			cin >> x;
			dest.push(-x);
		}

		Dijkstra(s);

		while (!dest.empty()) {
			int now = -dest.top();
			dest.pop();

			if (dfs(now))
				cout << now << " ";
		}

		cout << "\n";
	}
}