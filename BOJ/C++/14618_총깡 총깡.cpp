/*
문제
동물 애호가 진서는 총깡총깡 뛰는 동물과 짝폴짝폴 뛰는 동물들을 K마리씩 키운다. 타지로 취업하게 된 진서는 내일 이사를 한다.

이사하게 될 집에서 같이 살게 될 룸메이트 일호는 동물을 싫어하기 때문에 진서는 근처의 집에 동물들을 한마리씩 맡길 예정이다.

진서가 동물들을 맡길 수 있는 집의 종류는 A형 집과 B형 집 2종류 이다.

우연하게도 짝폴짝폴 뛰는 동물과 총깡총깡 뛰는 동물, A형 집, B형 집의 수는 모두 같다.



진서는 총깡총깡 뛰는 동물들과 짝폴짝폴 뛰는 동물들을 같은 종류의 집에 통일 시켜 맡기고 싶다.

하지만 진서는 총깡총깡 뛰는 동물들을 약간 더 좋아하므로 각 집에서 동시에 출발하여 진서네 집으로 가장 빨리 도착하는 동물이 총깡총깡 뛰는 동물이길 원한다.

진서가 살게 될 집, A형 집, B형 집, A형 집도 B형 집도 아닌 집이 있는 지도가 주어질 때 총깡총깡 뛰는 동물이 A형 집에 살아야 할 지 B형집에 살아야 할지 출력하고 가장 빨리 도착하는 총깡총깡 뛰는 동물이 진서네 집으로 부터 얼마만큼 떨어져 있는지 출력하라.

(만약 총깡총깡 뛰는 동물들이 A형집에 살던 B형집에 살던 상관이 없는 경우는 A형집에 살기로 한다.)

입력
입력의 첫 번째 줄에 전체 집의 수 N과 집과 집사이를 연결하는 도로 M이 공백으로 주어진다. (3 ≤ N ≤ 5,000, 3 ≤ M ≤ 20,000)

입력의 둘째 줄에 진서의 집 J가 주어진다 (1 ≤ J ≤ N)

입력의 셋째 줄에 종류별 동물의 수 K가 주어진다. (2*K ≤ N)

입력의 넷째 줄에 K개의 A형 집이 공백으로 구분되어 주어진다.

입력의 다섯 번째 줄에 K개의 B형 집이 공백으로 구분되어 주어진다.

이후 M개의 줄에 X Y Z(1 ≤ X, Y ≤ N, 1 ≤ Z ≤ 100)가 주어진다. 이는 X번 집과 Y번 집 사이에 Z의 길이를 가지는 도로가 존재한다는 것이다.

출력
총깡총깡 뛰는 동물이 살게 될 집의 종류를 말한 뒤 다음줄에 거리를 출력한다.

A형 집에서만 진서의 집에 갈 수 있는 경우 A를 출력한 뒤 다음 줄에 거리를 출력, B형 집에서만 진서의 집에 갈 수 있는 경우 B를 출력한 뒤 다음 줄에 거리를 출력, A형 집, B형 집 둘다 진서의 집에 갈 수 없는 경우에는 –1을 출력한다.

풀이:
문제를 잘 읽자.(아무것도 아닌 집도 있다)
진서의 집에서 모든 집까지의 거리를 구한 뒤 가장 짧은 집이 A인지, B인지 판별하면 된다.
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
int mv1[4] = { 0, 0, 1, 1 };
int mv2[4] = { 0, 1, 0, 1 };

int home[5001];	// 3 = 진수, 1 = A, 2 = B, 0 = 암것도 아닌 집
vii vt[5001];
priority_queue<pii> pq;
int dist[5001];
int j;

void Dijkstra() {

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
				pq.push({ -dist[next], next });
			}
		}
	}
}

int main() {
	FIO;

	int n, m, k;
	cin >> n >> m >> j >> k;

	home[j] = 3;
	fill(&dist[0], &dist[5001], IMAX);
	dist[j] = 0;
	pq.push({ 0, j });

	for (int i = 0; i < k; i++)
	{
		int tmp;
		cin >> tmp;
		
		home[tmp] = 1;
	}

	for (int i = 0; i < k; i++)
	{
		int tmp;
		cin >> tmp;
		
		home[tmp] = 2;
	}

	for (int i = 0; i < m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;

		vt[x].push_back({ y, z });
		vt[y].push_back({ x, z });
	}

	Dijkstra();

	int minDis = IMAX;
	int minHome = 1;

	for (int i = 1; i <= n; i++)
	{
		if (home[i] == 1 || home[i] == 2) {
			if (minDis > dist[i]) {
				minDis = dist[i];
				minHome = home[i];
			}
			else if (minDis == dist[i]) {
				minHome = 1;
			}
		}
	}

	if (minDis == IMAX) {
		cout << "-1";
	}
	else {
		cout << (minHome == 1 ? "A" : "B") << "\n" << minDis;
	}
}