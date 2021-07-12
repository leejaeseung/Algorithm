/*
문제
n×n짜리의 배열이 하나 있다. 이 배열의 (1, 1)에서 (n, n)까지 이동하려고 한다. 이동할 때는 상, 하, 좌, 우의 네 인접한 칸으로만 이동할 수 있다.

이와 같이 이동하다 보면, 배열에서 몇 개의 수를 거쳐서 이동하게 된다. 이동하기 위해 거쳐 간 수들 중 최댓값과 최솟값의 차이가 가장 작아지는 경우를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 n(2≤n≤100)이 주어진다. 다음 n개의 줄에는 배열이 주어진다. 배열의 각 수는 0보다 크거나 같고, 200보다 작거나 같은 정수이다.

출력
첫째 줄에 (최대 - 최소)가 가장 작아질 때의 그 값을 출력한다.

풀이:
이분탐색 풀이 :
파라매트릭 서치와 비슷하다.
diff 값은 최대 200 이므로 0 ~ 200 을 이분탐색 해주면 해당 diff로 bfs를 돌려 경로가 생성되는지 판단한다.

bfs 풀이 : 
한 점에서 diff 는 해당 점까지의 경로의 최솟값(혹은 최댓값) 과 짝지을 수 있다.
따라서 visit[x][y][min or max] 로 방문 배열을 설정하고, 방문한 곳의 diff 값보다 작은 곳만 탐색하도록 한다.
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

int n;
int maps[101][101];
int visit[101][101][201];
int ans = IMAX;

void BFS() {
	queue<pair<pii, pii>> q;

	visit[0][0][0] = true;
	q.push({ {0, 0}, {maps[0][0], maps[0][0]} });

	while (!q.empty()) {
		pii now = q.front().first;
		int nowMin = q.front().second.first;
		int nowMax = q.front().second.second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = now.first + mv1[i];
			int ny = now.second + mv2[i];
			int nextV = maps[nx][ny];
			int nextMin = min(nowMin, nextV);
			int nextMax = max(nowMax, nextV);
			int nextDif = nextMax - nextMin;

			if (nx < 0 || nx >= n || ny < 0 || ny >= n)	continue;

			if (visit[nx][ny][nextMin] > nextDif) {
				visit[nx][ny][nextMin] = nextDif;

				if (nx == n - 1 && ny == n - 1) {
					ans = min(ans, nextDif);
					continue;
				}

				q.push({ {nx, ny}, {nextMin, nextMax} });
			}
		}
	}
}

int main(void) {
	FIO;

	cin >> n;

	fill(&visit[0][0][0], &visit[100][101][201], IMAX);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> maps[i][j];
		}
	}

	BFS();

	cout << ans;
}