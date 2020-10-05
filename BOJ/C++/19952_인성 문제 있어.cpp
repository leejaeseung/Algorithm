/*
문제
인성이는 인싸가 되기 위해서 인싸트 특별과정에 참가했다. 훈련 첫날 인성이는 험난한 미로에서 목적지에 도달해야 하는 훈련을 받고 있다. 제한 시간 안에 미로를 통과하지 못하면 명기 교관 님에게 욕을 듣기에 인성이는 최선을 다해 미로를 통과하려고 한다.

미로는 가로 길이 W, 세로 길이 H의 격자 형태를 가지며, 인성이는 한 번에 격자 상의 상, 하, 좌, 우로 한칸 씩 움직일 수 있다.  매 이동이 완료될 시에 인성이의 남은 힘은 1씩 감소하고, 남은 힘이 0이하인 경우에는 더 이상 움직이지 못하게 된다.

미로의 각 격자에는 장애물이 있는데, 각각의 장애물은 높이 정보를 가지고 있다. 장애물이 없는 위치는 전부 높이가 0 이다. 인성이가 이동할 때, 현재 위치보다 이동할 위치의 높이가 더 낮으면 아무런 제약을 갖지 않고 이동할 수 있다. 더 높은 곳으로 이동할 때는 점프를 할 수 있는데, 점프해야 하는 높이는 (이동할 곳의 높이 - 현재 위치한 곳의 높이) 이다. 이때 남아있는 힘이 점프해야 하는 높이보다 크거나 같으면 이동할 수 있고, 그렇지 않으면 이동하지 못한다.

인성이는 신체적 한계를 극복하고 무사히 목적지에 도달해서 명기 교관님의 욕설을 듣지 않을 수 있을까?

입력
첫째 줄에 테스트 케이스 T가 주어진다. 각 테스트 케이스는 다음과 같이 주어진다.

첫째 줄에 미로의 세로길이 H, 가로길이 W, 장애물의 개수 O, 초기 힘 F, 출발지의 좌표 정보 Xs(행), Ys(열)목적지의 좌표정보 Xe(행), Ye(열) 가 주어진다.

둘째 줄부터 O개의 줄에 장애물의 좌표 정보 X(행), Y(열) 와 높이 정보 L이 주어진다. 모든 장애물은 서로 다른 위치에 존재한다.

출력
T개의 줄에 인성이가 목적지에 도착할 수 있을 때 "잘했어!!", 목적지에 도착할 수 없을 때 "인성 문제있어??" 를 출력한다.

제한
1 ≤ T ≤ 10
2 ≤ H, W ≤ 100
0 ≤ O ≤ H x W
0 ≤ F ≤ 10,000, F 는 정수이다.
1 ≤ L ≤ 50, L은 정수이다.
1 ≤ X, Xs, Xe ≤ H
1 ≤ Y, Ys, Ye ≤ W
시작 위치와 목적지에는 장애물이 존재하지 않는다.

풀이:
문제의 조건에 맞게 BFS를 하고,
방문을 체크할 때 힘이 더 적을 경우 방문하지 않게 해주면 된다.
문제를 잘 읽자
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

int T, H, W, O, F;
int sx, sy, ex, ey;
int maps[101][101];
int visit[101][101];

int main(void) {
	FIO;

	cin >> T;

	while (T--) {

		cin >> H >> W >> O >> F >> sx >> sy >> ex >> ey;

		fill(&maps[0][0], &maps[100][101], 0);
		fill(&visit[0][0], &visit[100][101], -1);

		for (int i = 0; i < O; i++)
		{
			int x, y, L;
			cin >> x >> y >> L;

			maps[x][y] = L;
		}

		bool canGo = false;
		queue<pair<pii, int>> q;
		visit[sx][sy] = F;
		q.push({ {sx, sy}, F });

		while (!q.empty()) {
			pii now = q.front().first;
			int nowF = q.front().second;
			q.pop();

			if (nowF <= 0)	continue;

			for (int i = 0; i < 4; i++)
			{
				int nx = now.first + mv1[i];
				int ny = now.second + mv2[i];

				if (nx <= 0 || ny <= 0 || nx > H || ny > W || maps[nx][ny] > maps[now.first][now.second] + nowF)	continue;

				if (visit[nx][ny] < nowF - 1) {
					visit[nx][ny] = nowF - 1;

					if (nx == ex && ny == ey) {
						canGo = true;
						break;
					}

					q.push({ {nx, ny}, nowF - 1 });
				}
			}

			if (canGo)	break;
		}

		if (canGo)
			cout << "잘했어!!\n";
		else
			cout << "인성 문제있어??\n";
	}
}