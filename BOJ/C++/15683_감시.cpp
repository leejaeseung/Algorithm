/*
문제
스타트링크의 사무실은 1×1크기의 정사각형으로 나누어져 있는 N×M 크기의 직사각형으로 나타낼 수 있다. 사무실에는 총 K개의 CCTV가 설치되어져 있는데, CCTV는 5가지 종류가 있다. 각 CCTV가 감시할 수 있는 방법은 다음과 같다.


1번	2번	3번	4번	5번
1번 CCTV는 한 쪽 방향만 감시할 수 있다. 2번과 3번은 두 방향을 감시할 수 있는데, 2번은 감시하는 방향이 서로 반대방향이어야 하고, 3번은 직각 방향이어야 한다. 4번은 세 방향, 5번은 네 방향을 감시할 수 있다.

CCTV는 감시할 수 있는 방향에 있는 칸 전체를 감시할 수 있다. 사무실에는 벽이 있는데, CCTV는 벽을 통과할 수 없다. CCTV가 감시할 수 없는 영역은 사각지대라고 한다.

CCTV는 회전시킬 수 있는데, 회전은 항상 90도 방향으로 해야 하며, 감시하려고 하는 방향이 가로 또는 세로 방향이어야 한다.

0 0 0 0 0 0
0 0 0 0 0 0
0 0 1 0 6 0
0 0 0 0 0 0
지도에서 0은 빈 칸, 6은 벽, 1~5는 CCTV의 번호이다. 위의 예시에서 1번의 방향에 따라 감시할 수 있는 영역을 '#'로 나타내면 아래와 같다.

0 0 0 0 0 0
0 0 0 0 0 0
0 0 1 # 6 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
# # 1 0 6 0
0 0 0 0 0 0
0 0 # 0 0 0
0 0 # 0 0 0
0 0 1 0 6 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 1 0 6 0
0 0 # 0 0 0
→	←	↑	↓
CCTV는 벽을 통과할 수 없기 때문에, 1번이 → 방향을 감시하고 있을 때는 6의 오른쪽에 있는 벽을 감시할 수 없다.

0 0 0 0 0 0
0 2 0 0 0 0
0 0 0 0 6 0
0 6 0 0 2 0
0 0 0 0 0 0
0 0 0 0 0 5
위의 예시에서 감시할 수 있는 방향을 알아보면 아래와 같다.

0 0 0 0 0 #
# 2 # # # #
0 0 0 0 6 #
0 6 # # 2 #
0 0 0 0 0 #
# # # # # 5
0 0 0 0 0 #
# 2 # # # #
0 0 0 0 6 #
0 6 0 0 2 #
0 0 0 0 # #
# # # # # 5
0 # 0 0 0 #
0 2 0 0 0 #
0 # 0 0 6 #
0 6 # # 2 #
0 0 0 0 0 #
# # # # # 5
0 # 0 0 0 #
0 2 0 0 0 #
0 # 0 0 6 #
0 6 0 0 2 #
0 0 0 0 # #
# # # # # 5
왼쪽 상단 2: ↔, 오른쪽 하단 2: ↔	왼쪽 상단 2: ↔, 오른쪽 하단 2: ↕	왼쪽 상단 2: ↕, 오른쪽 하단 2: ↔	왼쪽 상단 2: ↕, 오른쪽 하단 2: ↕
CCTV는 CCTV를 통과할 수 있다. 아래 예시를 보자.

0 0 2 0 3
0 6 0 0 0
0 0 6 6 0
0 0 0 0 0
위와 같은 경우에 2의 방향이 ↕ 3의 방향이 ←와 ↓인 경우 감시받는 영역은 다음과 같다.

# # 2 # 3
0 6 # 0 #
0 0 6 6 #
0 0 0 0 #
사무실의 크기와 상태, 그리고 CCTV의 정보가 주어졌을 때, CCTV의 방향을 적절히 정해서, 사각 지대의 최소 크기를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 사무실의 세로 크기 N과 가로 크기 M이 주어진다. (1 ≤ N, M ≤ 8)

둘째 줄부터 N개의 줄에는 사무실 각 칸의 정보가 주어진다. 0은 빈 칸, 6은 벽, 1~5는 CCTV를 나타내고, 문제에서 설명한 CCTV의 종류이다.

CCTV의 최대 개수는 8개를 넘지 않는다.

출력
첫째 줄에 사각 지대의 최소 크기를 출력한다.

풀이:
완전 탐색 문제입니다.
각 CCTV의 방향의 모든 경우의 수를 생각하여 맵을 칠한 뒤,
맵의 마지막에 도달하면 칠하지 않은 맵의 수를 세어주면 됩니다.
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
#define vii vector<pii>
#define IMAX 2000000001
#define LMAX 1000000000000000000
#define DMAX 0xFFFFFFFFFFFFF
int mv1[4] = { 0, 1, 0, -1 };
int mv2[4] = { 1, 0, -1, 0 };

int n, m;
int ans = 500;

void BF(int x, int y, vector<vector<int>> now) {
	vector<vector<int>> next = now;

	if (x == n && y == 0) {
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (next[i][j] == 0)
					cnt++;
			}
		}
		ans = min(ans, cnt);
		return;
	}

	int nx, ny;
	if (y + 1 >= m) {
		nx = x + 1;
		ny = 0;
	}
	else {
		nx = x;
		ny = y + 1;
	}

	if (now[x][y] == 1) {

		for (int i = 0; i < 4; i++)
		{
			vector<vector<int>> next = now;

			int ntx = x + mv1[i];
			int nty = y + mv2[i];

			while (ntx >= 0 && nty >= 0 && ntx < n && nty < m) {
				if (next[ntx][nty] == 0)
					next[ntx][nty] = -1;
				else if (next[ntx][nty] == 6)
					break;
				else {
					ntx += mv1[i];
					nty += mv2[i];
				}
			}
			BF(nx, ny, next);
		}
	}
	else if (now[x][y] == 2) {

		for (int j = 0; j < 2; j++)
		{
			vector<vector<int>> next = now;
			for (int i = 0; i < 4; i++)
			{
				if ((j + i) % 2 == 0)	continue;

				int ntx = x + mv1[i];
				int nty = y + mv2[i];

				while (ntx >= 0 && nty >= 0 && ntx < n && nty < m) {
					if (next[ntx][nty] == 0)
						next[ntx][nty] = -1;
					else if (next[ntx][nty] == 6)
						break;
					else {
						ntx += mv1[i];
						nty += mv2[i];
					}
				}
			}

			BF(nx, ny, next);
			
		}
	}

	else if (now[x][y] == 3) {

		for (int j = 0; j < 4; j++)
		{
			vector<vector<int>> next = now;
			for (int i = j; i < j + 2; i++)
			{

				int ntx = x + mv1[i % 4];
				int nty = y + mv2[i % 4];

				while (ntx >= 0 && nty >= 0 && ntx < n && nty < m) {
					if (next[ntx][nty] == 0)
						next[ntx][nty] = -1;
					else if (next[ntx][nty] == 6)
						break;
					else {
						ntx += mv1[i % 4];
						nty += mv2[i % 4];
					}
				}
			}
			BF(nx, ny, next);
			
		}
	}
	else if (now[x][y] == 4) {

		for (int j = 0; j < 4; j++)
		{
			vector<vector<int>> next = now;
			for (int i = j; i < j + 3; i++)
			{

				int ntx = x + mv1[i % 4];
				int nty = y + mv2[i % 4];

				while (ntx >= 0 && nty >= 0 && ntx < n && nty < m) {
					if (next[ntx][nty] == 0)
						next[ntx][nty] = -1;
					else if (next[ntx][nty] == 6)
						break;
					else {
						ntx += mv1[i % 4];
						nty += mv2[i % 4];
					}
				}
			}
			BF(nx, ny, next);
			
		}
	}
	else if (now[x][y] == 5) {

	vector<vector<int>> next = now;
		for (int i = 0; i < 4; i++)
		{
			int ntx = x + mv1[i];
			int nty = y + mv2[i];

			while (ntx >= 0 && nty >= 0 && ntx < n && nty < m) {
				if (next[ntx][nty] == 0)
					next[ntx][nty] = -1;
				else if (next[ntx][nty] == 6)
					break;
				else {
					ntx += mv1[i];
					nty += mv2[i];
				}
			}
		}
		BF(nx, ny, next);
		
	}
	else {
		BF(nx, ny, next);
		
	}
}

int main(void) {
	FIO;

	cin >> n >> m;
	vector<vector<int>> maps(n, vector<int>(m));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> maps[i][j];
		}
	}

	BF(0, 0, maps);

	cout << ans;
}