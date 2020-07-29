/*
문제
당신은  크기의 차원 격자 맵에서 두 세력이 전투를 벌이는 시뮬레이션 게임을 개발하고 있다.

격자의 각 칸은 좌표와 좌표의 쌍 로 표현할 수 있다. 첫 번째 줄에 있는 칸들은 왼쪽부터 순서대로 로 표현하며, 두 번째 줄의 칸들은 로 표현한다. 같은 방법으로 번째 줄까지의 모든 칸들을 좌표로 표현한다. 어떤 칸의 위, 아래, 왼쪽, 오른쪽 칸들은 그 칸에 ‘인접한’ 칸이라고 한다.

맵은 다양한 지형으로 이루어져 있고 각 지형은 정해진 ‘험준도’ 수치를 가진다. 또, 맵에는 여러 유닛이 서로 겹치지 않게 배치되어 있으며, 각 유닛은 전투 중인 두 세력 중 한 세력에 속한다. 각 유닛은 맵 밖으로 벗어나지 않는 한 위치한 곳으로부터 상하좌우로 인접한 칸으로 이동할 수 있다. 이동 시에는 해당 칸의 지형이 가진 험준도만큼의 스태미나를 소모하게 된다. 일부 지형은 너무 험준하여 이동이 불가능할 수도 있다. 세력이 다른 두 유닛이 인접해 있다면 그 둘은 교전 상태이다.

모든 유닛은 전투식량을 든든하게 챙겨 먹고 나왔기 때문에 무한한 스태미나를 가지고 있다. 다만 각 유닛은 한 번의 약진에 최대로 소모할 수 있는 스태미나 총량이 제한되어 있으며, 이를 유닛의 ‘이동력’이라고 한다. 약진이란 전투 중인 유닛이 비교적 가까운 목표지점까지 빠르게 달려 단숨에 이동하는 전술 행동으로서 하나 이상의 칸을 거쳐 이동하는 것이다. 약진은 목표지점에 다른 유닛이 없어야만 가능하다. 약진 중에 같은 세력의 유닛을 만났다면 통과하여 지나갈 수 있으나, 다른 세력의 유닛을 만났다면 그 유닛과 상하좌우로 인접하게 되는 순간 교전이 벌어지기 때문에 그 자리에 멈춰야만 한다. 하지만, 선택된 유닛이 이미 교전 상태였다면 약진하여 교전에서 벗어날 수 있다.

당신은 게임에 버그가 있는지 테스트하기 위해서 자동으로 임의의 유닛을 선택하여 약진 명령을 내리는 봇을 만들었다. 이 봇은 수행이 불가능한 약진 명령을 내리기도 한다. 목표 지점에 다른 유닛이 있거나, 목표 지점이 이동 불가 지형이거나, 이동력의 한계로 인해 목표 지점에 도달하는 경로가 존재하지 않는 경우, 그 명령은 수행 불가능하다. 게임에 버그가 없다면 이러한 명령은 무시되어야 한다.

이제 버그가 있는지 없는지 확인할 시간이다. 봇이 내린 명령들이 시간 순으로 주어졌을 때, 모든 명령이 순차적으로 처리된 후 각 유닛이 위치한 좌표를 출력하는 프로그램을 작성하시오.

입력
첫 번째 줄에 지형의 종류 수 , 맵의 세로 길이 , 맵의 가로 길이 가 공백으로 구분되어 주어진다. (, )

이어서 개의 줄에 걸쳐 왼쪽부터 차례대로 각 칸의 지형 번호를 의미하는 개의 정수가 공백으로 구분되어 주어지며, 각 수는  이상  이하이다.

다음 줄에 개의 정수  (, )이 공백으로 구분되어 주어진다. 가 이라면 번째 지형이 너무 험준하여 진입할 수 없음을 의미하며, 이외의 경우에는 는 번째 지형의 험준도를 의미한다.

다음 줄에 유닛의 수 이 주어진다. ()

이어서 개의 줄에 걸쳐 번 유닛부터 차례로 각 유닛의 이동력, 세력, 유닛이 있는 칸의 좌표, 유닛이 있는 칸의 좌표 정보를 의미하는 네 개의 정수 , , , 가 공백으로 구분되어 주어진다. (, , , )

각 칸에는 최대 하나의 유닛이 배치되며, 진입 불가능한 지형의 칸에는 유닛이 배치되지 않는다.

다음 줄에 약진 명령의 개수  ()가 주어진다.

이어서 개의 줄에 걸쳐 약진 명령을 의미하는 세 정수 , , 가 공백으로 구분되어 주어진다. (, , ) 이는 번 유닛을 로 약진시키는 명령이다.

출력
개의 줄에 걸쳐 모든 약진 명령이 처리된 후의 유닛의 위치를 출력한다. 번 유닛이 에 위치할 경우 번째 줄에 두 정수 , 를 공백으로 구분하여 출력한다.

풀이:
방문 배열을 매번 초기화하지 않고 쿼리의 인덱스로 처리해야 한다.
다익스트라 알고리즘을 변형해 가장 cost가 적은 곳부터 bfs 하는 방식으로 풀이한다.

최대 스테미나가 20이기 때문에 택시거리로 20까지만 이동할 수 있다.
따라서 거리를 넘어갈 시 예외처리를 해주어 시간을 단축할 수 있다.

매 이동마다 주변에 상대 세력이 있는 지 체크해준다.
(단, 이동하기 전에 이미 붙어있었던 경우엔 지나갈 수 있다. - 통과도 가능)
*/
#include<iostream>
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
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vii vector<pii>
#define IMAX 2000000001
#define LMAX 1000000000000000000
#define DMAX 0xFFFFFFFFFFFFF
int mv1[4] = { 0, 1, 0, -1 };
int mv2[4] = { 1, 0, -1, 0 };
int mv_all1[8] = { 0, 1, 0, -1, -1, -1, 1, 1 };
int mv_all2[8] = { 1, 0, -1, 0 , -1, 1, -1, 1 };

int n, h, w, M, k;
int maps[501][501];
int unit_map[501][501];
int visit[501][501];
int cell[10];

class unit {
public:
	int move;
	int team;
	int x, y;
	unit(int m, int t, int x, int y) :
		move(m), team(t), x(x), y(y){}
};

vector<unit> u;

int main(void) {
	FIO;

	cin >> n >> h >> w;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> maps[i][j];
		}
	}
	for (int i = 1; i <= n; i++)
		cin >> cell[i];
	
	cin >> M;

	u.push_back(unit(-1, -1, -1, -1));

	for (int i = 1; i <= M; i++)
	{
		int m, t, a, b;
		cin >> m >> t >> a >> b;

		u.push_back(unit(m, t, a, b));
		unit_map[a][b] = i;
	}

	cin >> k;

	for (int j = 1; j <= k; j++)
	{
		int c, a, b;
		cin >> c >> a >> b;

		if (cell[maps[a][b]] == -1 || unit_map[a][b] != 0)	continue;
		if (u[c].x == a && u[c].y == b)	continue;

		priority_queue<pair<int, pii>> q;

		int ori_x = u[c].x;
		int ori_y = u[c].y;

		q.push(make_pair(0, make_pair(ori_x, ori_y)));
		visit[ori_x][ori_y] = j;

		while (!q.empty()) {
			int nowx = q.top().second.first;
			int nowy = q.top().second.second;
			int nowSt = -q.top().first;
			q.pop();

			if (abs(ori_x - nowx) > 20 || abs(ori_y - nowy) > 20)	continue;
			if (nowSt > u[c].move) break;
			if (unit_map[nowx][nowy] != 0 && u[unit_map[nowx][nowy]].team != u[c].team)	continue;

			if (nowx == a && nowy == b) {
				unit_map[nowx][nowy] = c;
				u[c].x = nowx;
				u[c].y = nowy;

				unit_map[ori_x][ori_y] = 0;
				break;
			}

			bool check = false;

			for (int i = 0; i < 4; i++)
			{
				int nextx = nowx + mv1[i];
				int nexty = nowy + mv2[i];

				if (nextx < 0 || nexty < 0 || nextx >= h || nexty >= w)	continue;
				if (unit_map[nextx][nexty] != 0 && u[unit_map[nextx][nexty]].team != u[c].team) {
					check = true;
					break;
				}
			}

			if (nowSt != 0 && check)	continue;

			for (int i = 0; i < 4; i++)
			{
				int nextx = nowx + mv1[i];
				int nexty = nowy + mv2[i];
				
				if (nextx < 0 || nexty < 0 || nextx >= h || nexty >= w)	continue;
				if (cell[maps[nextx][nexty]] == -1)	continue;

				int nextSt = cell[maps[nextx][nexty]] + nowSt;
				if (nextSt > u[c].move)	continue;
				//스테미나가 오버되면 pass

				//쿼리 인덱스로 j번째 쿼리의 방문 처리
				if (visit[nextx][nexty] == j)	continue;
				visit[nextx][nexty] = j;
				
				q.push(make_pair(-nextSt, make_pair(nextx, nexty)));
			}
		}
	}

	for (int i = 1; i <= M; i++)
	{
		cout << u[i].x << " " << u[i].y << "\n";
	}
}