/*
문제
2차원 평면상에 m개의 수직선과 n개의 수평선으로 이루어진 격자 형태의 도로망이 있다. 아래 그림은 7개의 수직선과 6개의 수평선으로 이루어진 도로망의 예이다.



수직선과 수평선이 만나는 교차점들 중 가장 왼쪽 아래 점의 위치는 (1,1)이고, 가장 오른쪽 위 점의 좌표는 (m,n)이다. 이 도로망을 운행하는 버스들이 k개 있고, 각  버스는 하나의 수평선 상의 두 교차점 사이 선분이나 하나의 수직선 상의 두 교차점 사이 선분을 왕복 운행한다. 각 버스는 운행하는 선분 사이의 모든 교차점(선분의 양 끝 교차점 포함)에서 정차한다.

출발지 교차점과 목적지 교차점 (출발지와 목적지는 다름)이 주어질 때, 출발지에서 목적지로 버스만을 이용하여 가려고 한다. 이용하는 버스의 최소 수를 구하는 프로그램을 작성하시오.

예를 들어,  8대의 버스가 다음과 같이 운행한다고 하자.

1번 버스: (2, 1) - (2, 2)

2번 버스: (1, 1) - (5, 1)

3번 버스: (3, 2) - (6, 2)

4번 버스: (5, 6) - (5, 1)

5번 버스: (1, 5) - (7, 5)

6번 버스: (7, 3) - (7, 6)

7번 버스: (2, 1) - (2, 6)

8번 버스: (3, 5) - (6, 5)

출발지가 (2, 1)이고 목적지가 (7, 4)라 하자. 한 가지 방법으로, 처음에 2번 버스를 타고 교차점 (5, 1)에서 내려, 4번 버스를 타고 (5, 5)에서 내리고, 5번 버스를 탄 후 (7, 5)에서 내려, 마지막으로 6번 버스를 타서 목적지 (7, 4)에서 내린다. 그러면 이용하는 버스 수는 4이다. 다른 방법으로, 7번 버스를 타고 (2, 5)에서 내려, 5번 버스를 타고 (7, 5)에서 내린 후, 마지막으로 6번 버스를 타서 목적지 (7, 4)에서 내린다. 그러면 이용하는 버스 수는 3이고 이것이 최소이다.

입력
첫 번째 줄에 수직선의 수 m과 수평선의 수 n이 빈칸을 사이에 두고 주어진다 (1 ≤ m,n ≤ 100,000). 두 번째 줄에 버스의 수 k (1 ≤ k ≤ 5,000)가 주어진다. 세 번째 줄부터 k 줄에 걸쳐 각 줄에 버스의 운행구간을 나타내는 5개의 수 b, x1, y1, x2, y2가 빈칸을 사이에 두고 주어진다. 여기서 b (1 ≤ b ≤ k) 는 버스의 번호, (x1,y1) 과 (x2, y2)는 이 버스가 운행하는 양쪽 끝 교차점의 좌표를 나타낸다. 마지막 줄에 출발지와 목적지 좌표를 나타내는 네 개의 수 sx, sy, dx, dy가 빈칸을 사이에 두고 주어진다. 여기서 (sx, sy)는 출발지 좌표이고 (dx, dy)는 목적지 좌표이다.  1 ≤ x1, x2, sx, dx ≤ m이고, 1 ≤ y1, y2, sy, dy ≤ n이다.

모든 입력에 대하여, 출발지와 목적지는 다르게 주어지며 출발지에서 목적지로 가는 방법은 한 가지 이상 존재한다.

출력
첫째 줄에 이용하는 최소 버스 수를 출력한다.

풀이:
버스의 경로를 정점, 버스가 겹치면 두 정점을 간선으로 이어준다.
(ccw 를 이용해 두 선분의 교차 여부를 확인 = N^2)
시작점을 포함하는 정점을 모두 우선순위 큐에 넣고 다익스트라 알고리즘을 사용해 풀이했다.
도착점을 포함하는 정점들 중 거리가 최소인 점이 답이 된다.

좌표의 크기가 최대 100000 이므로 ccw를 구할 때 오버플로우가 발생할 수 있다.
*/
/*#include<iostream>
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

int m, n, k, sx, sy, dx, dy;
pair<pll, pll> bus[5001];
pll start;
pll dest;
vector<int> edge[5001];
bool isEnd[5001];
int dist[5001];
priority_queue<pii> pq;

int ccw(pll p1, pll p2, pll p3) {
	ll S = (p1.first * p2.second + p2.first * p3.second + p3.first * p1.second) 
		- (p1.second * p2.first + p2.second * p3.first + p3.second * p1.first);

	if (S > 0)
		//반시계
		return -1;
	else if (S < 0)
		//시계
		return 1;
	else
		//일직선
		return 0;
}

bool cross(pair<pll, pll> L1, pair<pll, pll> L2) {
	pll a = L1.first;
	pll b = L1.second;
	pll c = L2.first;
	pll d = L2.second;

	int abL2 = ccw(a, b, c) * ccw(a, b, d);
	int cdL1 = ccw(c, d, a) * ccw(c, d, b);

	if (abL2 == 0 && cdL1 == 0) {
		if (a > b)	swap(a, b);
		if (c > d)	swap(c, d);
		return c <= b && a <= d;
	}
	return abL2 <= 0 && cdL1 <= 0;
}

int main(void) {
	FIO;

	cin >> m >> n >> k;

	for (int i = 0; i < k; i++)
	{
		int b, x1, y1, x2, y2;
		cin >> b >> x1 >> y1 >> x2 >> y2;

		bus[b] = { {x1, y1}, {x2, y2} };
	}

	cin >> sx >> sy >> dx >> dy;

	fill(&dist[0], &dist[5001], IMAX);

	start = { sx, sy };
	dest = { dx, dy };

	for (int i = 1; i <= k; i++)
	{
		if (cross(bus[i], { dest, dest }))
			isEnd[i] = true;
		if (cross(bus[i], { start, start })) {
			dist[i] = 1;
			pq.push({ 1, i });
		}
		if (i <= k - 1) {
			for (int j = i + 1; j <= k; j++)
			{
				if (cross(bus[i], bus[j])) {
					edge[i].push_back(j);
					edge[j].push_back(i);
				}
			}
		}
	}

	while (!pq.empty()) {
		int nowDist = -pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (dist[now] < nowDist)	continue;

		for (int i = 0; i < edge[now].size(); i++)
		{
			int next = edge[now][i];

			if (dist[next] > dist[now] + 1) {
				dist[next] = dist[now] + 1;

				pq.push({ -dist[next], next });
			}
		}
	}

	int ans = IMAX;

	for (int i = 1; i <= k; i++)
	{
		if(isEnd[i])
			ans = min(ans, dist[i]);
	}

	cout << ans;
}*/