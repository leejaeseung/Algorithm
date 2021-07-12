/*
문제
러시아 가스를 크로아티아로 운반하기 위해 자그레브와 모스코바는 파이프라인을 디자인하고 있다. 두 사람은 실제 디자인을 하기 전에 파이프 매니아 게임을 이용해서 설계를 해보려고 한다.

이 게임에서 유럽은 R행 C열로 나누어져 있다. 각 칸은 비어있거나, 아래 그림과 같은 일곱가지 기본 블록으로 이루어져 있다.


블록 '|'	블록 '-'	블록 '+'	블록 '1'	블록 '2'	블록 '3'	블록 '4'
가스는 모스크바에서 자그레브로 흐른다. 가스는 블록을 통해 양방향으로 흐를 수 있다. '+'는 특별한 블록으로, 아래 예시처럼 두 방향 (수직, 수평)으로 흘러야 한다.



파이프 라인의 설계를 마친 후 두 사람은 잠시 저녁을 먹으러 갔다. 그 사이 해커가 침임해 블록 하나를 지웠다. 지운 블록은 빈 칸이 되어있다.

해커가 어떤 칸을 지웠고, 그 칸에는 원래 어떤 블록이 있었는지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 유럽의 크기 R과 C가 주어진다. (1 ≤ R, C ≤ 25)

다음 R개 줄에는 C개 글자가 주어지며, 다음과 같은 글자로 이루어져 있다.

빈칸을 나타내는 '.'
블록을 나타내는 '|'(아스키 124), '-','+','1','2','3','4'
모스크바의 위치를 나타내는 'M'과 자그레브를 나타내는 'Z'. 두 글자는 한 번만 주어진다.
항상 답이 존재하고, 가스의 흐름이 유일한 경우만 입력으로 주어진다, 또, 모스크바와 자그레브가 하나의 블록과 인접해 있는 입력만 주어진다. 또, 불필요한 블록이 존재하지 않는다. 즉, 없어진 블록을 추가하면, 모든 블록에 가스가 흐르게 된다.

출력
지워진 블록의 행과 열 위치를 출력하고, 어떤 블록이었는지를 출력한다.

풀이:
빡구현으로 풀이했다.
맵을  | , - 파이프로 감싸주면 예외처리하기 편하다.
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