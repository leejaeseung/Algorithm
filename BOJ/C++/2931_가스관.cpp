/*
����
���þ� ������ ũ�ξ�Ƽ�Ʒ� ����ϱ� ���� �ڱ׷���� ���ڹٴ� ������������ �������ϰ� �ִ�. �� ����� ���� �������� �ϱ� ���� ������ �ŴϾ� ������ �̿��ؼ� ���踦 �غ����� �Ѵ�.

�� ���ӿ��� ������ R�� C���� �������� �ִ�. �� ĭ�� ����ְų�, �Ʒ� �׸��� ���� �ϰ����� �⺻ ������� �̷���� �ִ�.


��� '|'	��� '-'	��� '+'	��� '1'	��� '2'	��� '3'	��� '4'
������ ��ũ�ٿ��� �ڱ׷���� �帥��. ������ ����� ���� ��������� �带 �� �ִ�. '+'�� Ư���� �������, �Ʒ� ����ó�� �� ���� (����, ����)���� �귯�� �Ѵ�.



������ ������ ���踦 ��ģ �� �� ����� ��� ������ ������ ����. �� ���� ��Ŀ�� ħ���� ��� �ϳ��� ������. ���� ����� �� ĭ�� �Ǿ��ִ�.

��Ŀ�� � ĭ�� ������, �� ĭ���� ���� � ����� �־����� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ������ ũ�� R�� C�� �־�����. (1 �� R, C �� 25)

���� R�� �ٿ��� C�� ���ڰ� �־�����, ������ ���� ���ڷ� �̷���� �ִ�.

��ĭ�� ��Ÿ���� '.'
����� ��Ÿ���� '|'(�ƽ�Ű 124), '-','+','1','2','3','4'
��ũ���� ��ġ�� ��Ÿ���� 'M'�� �ڱ׷��긦 ��Ÿ���� 'Z'. �� ���ڴ� �� ���� �־�����.
�׻� ���� �����ϰ�, ������ �帧�� ������ ��츸 �Է����� �־�����, ��, ��ũ�ٿ� �ڱ׷��갡 �ϳ��� ��ϰ� ������ �ִ� �Է¸� �־�����. ��, ���ʿ��� ����� �������� �ʴ´�. ��, ������ ����� �߰��ϸ�, ��� ��Ͽ� ������ �帣�� �ȴ�.

���
������ ����� ��� �� ��ġ�� ����ϰ�, � ����̾������� ����Ѵ�.

Ǯ��:
���������� Ǯ���ߴ�.
����  | , - �������� �����ָ� ����ó���ϱ� ���ϴ�.
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
#include<set>
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

int r, c;
int sx, sy, dx, dy;
int maps[28][28];
bool visit[28][28];

bool pipe2(int idx) {
	if (idx == 0 || idx == 3)	return false;
	return true;
}

bool pipe3(int idx) {
	if (idx == 1 || idx == 2)	return false;
	return true;
}

bool pipe5(int idx) {
	if (idx == 2 || idx == 3)	return false;
	return true;
}

bool pipe6(int idx) {
	if (idx == 1 || idx == 3)	return false;
	return true;
}

bool pipe7(int idx) {
	if (idx == 0 || idx == 1)	return false;
	return true;
}

bool pipe8(int idx) {
	if (idx == 0 || idx == 2)	return false;
	return true;
}

bool bfs() {
	queue<pii> q;
	q.push({ sx, sy });

	fill(&visit[0][0], &visit[27][28], false);
	visit[sx][sy] = true;

	bool can = false;

	while (!q.empty()) {
		pii now = q.front();
		q.pop();

		if (now.first == dx && now.second == dy) {
			can = true;
			continue;
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = now.first + mv1[i];
			int ny = now.second + mv2[i];

			if (maps[now.first][now.second] == 1) {
				if (nx <= 0 || nx >= r + 1 || ny <= 0 || ny >= c + 1) continue;
				if (maps[nx][ny] != 0 && !visit[nx][ny]) {
					visit[nx][ny] = true;
					q.push({ nx, ny });
				}
				continue;
			}
			else if (maps[now.first][now.second] == 2) {
				if (!pipe2(i))
					continue;
				if (i == 2) {
					if (maps[nx][ny] == 3 || maps[nx][ny] == 6 || maps[nx][ny] == 7)
						return false;
				}
				if (i == 1) {
					if (maps[nx][ny] == 3 || maps[nx][ny] == 5 || maps[nx][ny] == 8)
						return false;
				}
			}
			else if (maps[now.first][now.second] == 3) {
				if (!pipe3(i))
					continue;
				if (i == 0) {
					if (maps[nx][ny] == 2 || maps[nx][ny] == 5 || maps[nx][ny] == 6)
						return false;
				}
				if (i == 3) {
					if (maps[nx][ny] == 2 || maps[nx][ny] == 7 || maps[nx][ny] == 8)
						return false;
				}
			}
			else if (maps[now.first][now.second] == 4) {
				if (i == 0) {
					if (maps[nx][ny] == 2 || maps[nx][ny] == 5 || maps[nx][ny] == 6)
						return false;
				}
				if (i == 1) {
					if (maps[nx][ny] == 3 || maps[nx][ny] == 5 || maps[nx][ny] == 8)
						return false;
				}
				if (i == 2) {
					if (maps[nx][ny] == 3 || maps[nx][ny] == 6 || maps[nx][ny] == 7)
						return false;
				}
				if (i == 3) {
					if (maps[nx][ny] == 2 || maps[nx][ny] == 7 || maps[nx][ny] == 8)
						return false;
				}
			}
			else if (maps[now.first][now.second] == 5) {
				if (!pipe5(i))
					continue;
				if (i == 0) {
					if (maps[nx][ny] == 2 || maps[nx][ny] == 5 || maps[nx][ny] == 6)
						return false;
				}
				if (i == 1) {
					if (maps[nx][ny] == 3 || maps[nx][ny] == 5 || maps[nx][ny] == 8)
						return false;
				}
			}
			else if (maps[now.first][now.second] == 6) {
				if (!pipe6(i))
					continue;
				if (i == 0) {
					if (maps[nx][ny] == 2 || maps[nx][ny] == 5 || maps[nx][ny] == 6)
						return false;
				}
				if (i == 2) {
					if (maps[nx][ny] == 3 || maps[nx][ny] == 6 || maps[nx][ny] == 7)
						return false;
				}
			}
			else if (maps[now.first][now.second] == 7) {
				if (!pipe7(i))
					continue;
				if (i == 3) {
					if (maps[nx][ny] == 2 || maps[nx][ny] == 7 || maps[nx][ny] == 8)
						return false;
				}
				if (i == 2) {
					if (maps[nx][ny] == 3 || maps[nx][ny] == 6 || maps[nx][ny] == 7)
						return false;
				}
			}
			else if (maps[now.first][now.second] == 8) {
				if (!pipe8(i))
					continue;
				if (i == 3) {
					if (maps[nx][ny] == 2 || maps[nx][ny] == 7 || maps[nx][ny] == 8)
						return false;
				}
				if (i == 1) {
					if (maps[nx][ny] == 3 || maps[nx][ny] == 5 || maps[nx][ny] == 8)
						return false;
				}
			}

			if (maps[nx][ny] == 0)	return false;

			if (!visit[nx][ny]) {
				visit[nx][ny] = true;

				q.push({ nx, ny });
			}
		}
	}

	return can;
}

int main(void) {
	FIO;

	cin >> r >> c;

	for (int i = 1; i <= r; i++)
	{
		string str;
		cin >> str;

		for (int j = 1; j <= c; j++)
		{
			if (str[j - 1] == 'M') {
				sx = i;
				sy = j;
				maps[i][j] = 1;
			}
			else if (str[j - 1] == 'Z') {
				dx = i;
				dy = j;
				maps[i][j] = -1;
			}
			else if (str[j - 1] == '|') {
				maps[i][j] = 2;
			}
			else if (str[j - 1] == '-') {
				maps[i][j] = 3;
			}
			else if (str[j - 1] == '+') {
				maps[i][j] = 4;
			}
			else if (str[j - 1] == '1') {
				maps[i][j] = 5;
			}
			else if (str[j - 1] == '2') {
				maps[i][j] = 6;
			}
			else if (str[j - 1] == '3') {
				maps[i][j] = 7;
			}
			else if (str[j - 1] == '4') {
				maps[i][j] = 8;
			}
		}
	}

	for (int i = 0; i <= r + 1; i++)
	{
		for (int j = 0; j <= c + 1; j++)
		{
			if (i == 0 || i == r + 1) {
				maps[i][j] = 3;
			}
			if (j == 0 || j == c + 1) {
				maps[i][j] = 2;
			}
		}
	}

	int pipes[7] = { 2, 3, 4, 5, 6, 7, 8 };
	char pipes_str[7] = { '|', '-', '+', '1', '2', '3', '4' };

	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			for (int k = 0; k < 7; k++)
			{
				if (maps[i][j] == 0) {
					maps[i][j] = pipes[k];

					if (bfs()) {
						cout << i << " " << j << " " << pipes_str[k];
						exit(0);
					}
					
					maps[i][j] = 0;
				}
			}
		}
	}

}