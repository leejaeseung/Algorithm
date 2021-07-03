/*
문제
크기가 1×1인 정사각형으로 나누어진 W×H 크기의 지도가 있다. 지도의 각 칸은 빈 칸이거나 벽이며, 두 칸은 'C'로 표시되어 있는 칸이다.

'C'로 표시되어 있는 두 칸을 레이저로 통신하기 위해서 설치해야 하는 거울 개수의 최솟값을 구하는 프로그램을 작성하시오. 레이저로 통신한다는 것은 두 칸을 레이저로 연결할 수 있음을 의미한다.

레이저는 C에서만 발사할 수 있고, 빈 칸에 거울('/', '\')을 설치해서 방향을 90도 회전시킬 수 있다.

아래 그림은 H = 8, W = 7인 경우이고, 빈 칸은 '.', 벽은 '*'로 나타냈다. 왼쪽은 초기 상태, 오른쪽은 최소 개수의 거울을 사용해서 두 'C'를 연결한 것이다.

7 . . . . . . .         7 . . . . . . .
6 . . . . . . C         6 . . . . . /-C
5 . . . . . . *         5 . . . . . | *
4 * * * * * . *         4 * * * * * | *
3 . . . . * . .         3 . . . . * | .
2 . . . . * . .         2 . . . . * | .
1 . C . . * . .         1 . C . . * | .
0 . . . . . . .         0 . \-------/ .
  0 1 2 3 4 5 6           0 1 2 3 4 5 6
입력
첫째 줄에 W와 H가 주어진다. (1 ≤ W, H ≤ 100)

둘째 줄부터 H개의 줄에 지도가 주어진다. 지도의 각 문자가 의미하는 것은 다음과 같다.

.: 빈 칸
*: 벽
C: 레이저로 연결해야 하는 칸
'C'는 항상 두 개이고, 레이저로 연결할 수 있는 입력만 주어진다.

출력
첫째 줄에 C를 연결하기 위해 설치해야 하는 거울 개수의 최솟값을 출력한다.

풀이:
맵을 BFS로 탐색하는데, 방향이 꺾일 때마다 Mir 카운트를 늘려준다.
이미 방문한 곳의 Mir 카운트가 최소인 경우에만 다시 탐색하면 된다.

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
#define IMAX 2147483647
#define LMAX 1000000000000500000
#define DMAX 0xFFFFFFFFFFFFF
int mv1[4] = { 0, 1, -1, 0 };
int mv2[4] = { 1, 0, 0, -1 };

int w, h;
int maps[101][101];
int visit[101][101];
queue<pair<pii, pii>> q;
int ans = IMAX;

void BFS() {
	
	while (!q.empty()) {
		pii now = q.front().first;
		int nowMir = q.front().second.first;
		int nowDir = q.front().second.second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = now.first + mv1[i];
			int ny = now.second + mv2[i];
			int nextMir = nowMir;
			
			if (nowDir != i) {
				nextMir++;
			}

			if (nx < 0 || nx >= h || ny < 0 || ny >= w)	continue;
			if (maps[nx][ny] == -1)	continue;

			if (maps[nx][ny] == 1) {
				visit[nx][ny] = min(visit[nx][ny], nextMir);
				ans = visit[nx][ny];
				continue;
			}

			if (visit[nx][ny] >= nextMir) {
				visit[nx][ny] = nextMir;
				q.push({ {nx, ny}, {nextMir, i} });
			}
		}
	}

}

int main() {
	FIO;

	cin >> w >> h;

	fill(&visit[0][0], &visit[100][101], IMAX);

	for (int i = 0; i < h; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < w; j++)
		{
			if (str[j] == 'C') {
				if (q.empty()) {
					for (int k = 0; k < 4; k++)
					{
						q.push({ { i, j }, {0, k} });
					}
				}
				else {
					maps[i][j] = 1;
				}
			}
			else if (str[j] == '*') {
				maps[i][j] = -1;
			}
		}
	}

	BFS();

	cout << ans;
}