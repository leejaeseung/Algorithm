/*
����
���ÿ��� ��� ���ø� �ϴ� ���� ũ�Ⱑ R��C�� ���������� ��Ÿ�� �� �ִ�. �������� �� ĭ�� (r, c)�� ��Ÿ�� �� �ִ�. r�� ��, c�� ���̰�, (R, C)�� �Ʒ� �׸����� ���� ������ �Ʒ��� �ִ� ĭ�̴�. ĭ���� �� �ִ� �� ���� ������� �� �ִ�. ���� ũ��� �ӵ��� ������ �ִ�.



���ÿ��� ó���� 1�� ���� �� ĭ ���ʿ� �ִ�. ������ 1�� ���� �Ͼ�� ���̸�, �Ʒ� ���� ������� �Ͼ��. ���ÿ��� ���� ������ ���� ������ ĭ�� �̵��ϸ� �̵��� �����.

���ÿ��� ���������� �� ĭ �̵��Ѵ�.
���ÿ��� �ִ� ���� �ִ� ��� �߿��� ���� ���� ����� �� ��´�. �� ������ �����ǿ��� ���� �� �������.
�� �̵��Ѵ�.
���� �Է����� �־��� �ӵ��� �̵��ϰ�, �ӵ��� ������ ĭ/���̴�. �� �̵��Ϸ��� �ϴ� ĭ�� �������� ��踦 �Ѵ� ��쿡�� ������ �ݴ�� �ٲ㼭 �ӷ��� ������ä�� �̵��Ѵ�.

���� �׸��� ���¿��� 1�ʰ� ������ ������ ���°� �ȴ�. �� ���� �ִ� ������ �ӵ��� ����, ���� �Ʒ��� ���� ������ �ӷ��̴�. ���� ���� �� �����ϱ� ���� ���ڸ� ������.



�� �̵��� ��ģ �Ŀ� �� ĭ�� �� �� ���� �̻� ���� �� �ִ�. �̶��� ũ�Ⱑ ���� ū �� ������ �� ��� ��ƸԴ´�.

���ÿ��� ��� ���ø� �ϴ� �������� ���°� �־����� ��, ���ÿ��� ���� ��� ũ���� ���� ���غ���.

�Է�
ù° �ٿ� �������� ũ�� R, C�� ����� �� M�� �־�����. (2 �� R, C �� 100, 0 �� M �� R��C)

��° �ٺ��� M���� �ٿ� ����� ������ �־�����. ����� ������ �ټ� ���� r, c, s, d, z (1 �� r �� R, 1 �� c �� C, 0 �� s �� 1000, 1 �� d �� 4, 1 �� z �� 10000) �� �̷���� �ִ�. (r, c)�� ����� ��ġ, s�� �ӷ�, d�� �̵� ����, z�� ũ���̴�. d�� 1�� ���� ��, 2�� ���� �Ʒ�, 3�� ���� ������, 4�� ���� ������ �ǹ��Ѵ�.

�� �� ���� ũ�⸦ ���� ���� ����, �ϳ��� ĭ�� �� �̻��� �� �ִ� ���� ����.

���
���ÿ��� ���� ��� ũ���� ���� ����Ѵ�.

Ǯ��:
�ִ� 10000������ ����� �������� ��� �ð��� ����ϱ⸸ �ϸ� ������ Ǯ����.

����� ��ġ�� �Ź� �ʿ� ���Ӱ� ����ָ鼭 �ϸ� �� �̵��ϱ� ���� ��Ƹ����� �� ������ �� �ִ�.
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
	//�̵��ϱ� �� ��ġ�� 0���� �ʱ�ȭ

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
		//������ �����ϰ� ���� ���
		nx = x + mv1[dir - 1] * move;
		ny = y + mv2[dir - 1] * move;
	}
	else if (move >= front && move < front + leng) {
		//�� ���� ���� ��ȯ�� �̷������ ���

		x = x + mv1[dir - 1] * (front);
		y = y + mv2[dir - 1] * (front);

		move = move - (front);
		
		dir = turn(dir);

		nx = x + mv1[dir - 1] * (move);
		ny = y + mv2[dir - 1] * (move);
	}
	else {
		//�� ���� ���� ��ȯ�� �̷������ ���
		dir = turn(dir);

		move = (front * 2 + back * 2) - move;

		nx = x + mv1[dir - 1] * (move);
		ny = y + mv2[dir - 1] * (move);

		dir = turn(dir);
	}

	vt[idx].x = nx;
	vt[idx].y = ny;
	vt[idx].dir = dir;
	//����� ���ο� ��ǥ, ������ ����
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
			//��� �̵�
		}

		for (int i = 1; i <= M; i++)
		{
			if (eated[i])	continue;

			int x = vt[i].x;
			int y = vt[i].y;

			if (maps[x][y] != 0) {
				//�� �̹� �����ϸ� ����
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
				//��� ��ġ ����
				maps[x][y] = i;
			}
		}
	}

	cout << ans;
}