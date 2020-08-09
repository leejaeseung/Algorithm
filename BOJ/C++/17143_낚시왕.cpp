/*
문제
낚시왕이 상어 낚시를 하는 곳은 크기가 R×C인 격자판으로 나타낼 수 있다. 격자판의 각 칸은 (r, c)로 나타낼 수 있다. r은 행, c는 열이고, (R, C)는 아래 그림에서 가장 오른쪽 아래에 있는 칸이다. 칸에는 상어가 최대 한 마리 들어있을 수 있다. 상어는 크기와 속도를 가지고 있다.



낚시왕은 처음에 1번 열의 한 칸 왼쪽에 있다. 다음은 1초 동안 일어나는 일이며, 아래 적힌 순서대로 일어난다. 낚시왕은 가장 오른쪽 열의 오른쪽 칸에 이동하면 이동을 멈춘다.

낚시왕이 오른쪽으로 한 칸 이동한다.
낚시왕이 있는 열에 있는 상어 중에서 땅과 제일 가까운 상어를 잡는다. 상어를 잡으면 격자판에서 잡은 상어가 사라진다.
상어가 이동한다.
상어는 입력으로 주어진 속도로 이동하고, 속도의 단위는 칸/초이다. 상어가 이동하려고 하는 칸이 격자판의 경계를 넘는 경우에는 방향을 반대로 바꿔서 속력을 유지한채로 이동한다.

왼쪽 그림의 상태에서 1초가 지나면 오른쪽 상태가 된다. 상어가 보고 있는 방향이 속도의 방향, 왼쪽 아래에 적힌 정수는 속력이다. 왼쪽 위에 상어를 구분하기 위해 문자를 적었다.



상어가 이동을 마친 후에 한 칸에 상어가 두 마리 이상 있을 수 있다. 이때는 크기가 가장 큰 상어가 나머지 상어를 모두 잡아먹는다.

낚시왕이 상어 낚시를 하는 격자판의 상태가 주어졌을 때, 낚시왕이 잡은 상어 크기의 합을 구해보자.

입력
첫째 줄에 격자판의 크기 R, C와 상어의 수 M이 주어진다. (2 ≤ R, C ≤ 100, 0 ≤ M ≤ R×C)

둘째 줄부터 M개의 줄에 상어의 정보가 주어진다. 상어의 정보는 다섯 정수 r, c, s, d, z (1 ≤ r ≤ R, 1 ≤ c ≤ C, 0 ≤ s ≤ 1000, 1 ≤ d ≤ 4, 1 ≤ z ≤ 10000) 로 이루어져 있다. (r, c)는 상어의 위치, s는 속력, d는 이동 방향, z는 크기이다. d가 1인 경우는 위, 2인 경우는 아래, 3인 경우는 오른쪽, 4인 경우는 왼쪽을 의미한다.

두 상어가 같은 크기를 갖는 경우는 없고, 하나의 칸에 둘 이상의 상어가 있는 경우는 없다.

출력
낚시왕이 잡은 상어 크기의 합을 출력한다.

풀이:
최대 10000마리의 상어의 움직임을 상수 시간에 계산하기만 하면 간단히 풀린다.

상어의 위치를 매번 맵에 새롭게 찍어주면서 하면 상어가 이동하기 전에 잡아먹히는 걸 방지할 수 있다.
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
int mv1[4] = { -1, 1, 0, 0 };
int mv2[4] = { 0, 0, 1, -1 };
int mv_all1[8] = { 0, 1, 0, -1, -1, -1, 1, 1 };
int mv_all2[8] = { 1, 0, -1, 0 , -1, 1, -1, 1 };

int R, C, M;
int maps[101][101];
bool eated[10001];

class shark {
public: 
	int x, y, speed, dir, size;

	shark(int x, int y, int s, int d, int z) :
		x(x), y(y), speed(s), dir(d), size(z) {};
};

vector<shark> vt;

int turn(int dir) {
	switch (dir) {
	case 1:
		return 2;
	case 2:
		return 1;
	case 3:
		return 4;
	case 4:
		return 3;
	}
}

void move(int idx) {

	int x = vt[idx].x;
	int y = vt[idx].y;
	int speed = vt[idx].speed;
	int dir = vt[idx].dir;
	int size = vt[idx].size;

	int front, back, nx, ny, leng;

	maps[x][y] = 0;
	//이동하기 전 위치를 0으로 초기화

	switch (dir)
	{
	case 1:
		front = x - 1;
		back = R - x;
		leng = R - 1;
		break;
	case 2:
		back = x - 1;
		front = R - x;
		leng = R - 1;
		break;
	case 3:
		front = C - y;
		back = y - 1;
		leng = C - 1;
		break;
	case 4:
		front = y - 1;
		back = C - y;
		leng = C - 1;
		break;
	}

	int move = speed % (front * 2 + back * 2);

	if (front > move) {
		//앞으로 전진하고 끝인 경우
		nx = x + mv1[dir - 1] * move;
		ny = y + mv2[dir - 1] * move;
	}
	else if (move >= front && move < front + leng) {
		//한 번의 방향 전환이 이루어지는 경우

		x = x + mv1[dir - 1] * (front);
		y = y + mv2[dir - 1] * (front);

		move = move - (front);
		
		dir = turn(dir);

		nx = x + mv1[dir - 1] * (move);
		ny = y + mv2[dir - 1] * (move);
	}
	else {
		//두 번의 방향 전환이 이루어지는 경우
		dir = turn(dir);

		move = (front * 2 + back * 2) - move;

		nx = x + mv1[dir - 1] * (move);
		ny = y + mv2[dir - 1] * (move);

		dir = turn(dir);
	}

	vt[idx].x = nx;
	vt[idx].y = ny;
	vt[idx].dir = dir;
	//상어의 새로운 좌표, 방향을 갱신
}

int main(void) {
	FIO;

	cin >> R >> C >> M;

	vt.push_back(shark(-1,-1,-1,-1,-1));

	for (int i = 1; i <= M; i++)
	{
		int r, c, s, d, z;

		cin >> r >> c >> s >> d >> z;

		maps[r][c] = i;
		vt.push_back(shark(r, c, s, d, z));
	}

	int ans = 0;

	for (int col = 1; col <= C; col++)
	{
		for (int row = 1; row <= R; row++)
		{
			if (maps[row][col] != 0) {
				ans += vt[maps[row][col]].size;
				eated[maps[row][col]] = true;
				maps[row][col] = 0;
				break;
			}
		}

		for (int i = 1; i <= M; i++)
		{
			if (eated[i])	continue;
			move(i);
			//상어 이동
		}

		for (int i = 1; i <= M; i++)
		{
			if (eated[i])	continue;

			int x = vt[i].x;
			int y = vt[i].y;

			if (maps[x][y] != 0) {
				//상어가 이미 존재하면 먹음
				int ori_size = vt[maps[x][y]].size;

				if (ori_size < vt[i].size) {
					eated[maps[x][y]] = true;
					maps[x][y] = i;
				}
				else {
					eated[i] = true;
				}
			}
			else {
				//상어 위치 갱신
				maps[x][y] = i;
			}
		}
	}

	cout << ans;
}