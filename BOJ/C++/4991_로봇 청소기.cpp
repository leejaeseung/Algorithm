/*
문제
오늘은 직사각형 모양의 방을 로봇 청소기를 이용해 청소하려고 한다. 이 로봇 청소기는 유저가 직접 경로를 설정할 수 있다.

방은 크기가 1×1인 정사각형 칸으로 나누어져 있으며, 로봇 청소기의 크기도 1×1이다. 칸은 깨끗한 칸과 더러운 칸으로 나누어져 있으며, 로봇 청소기는 더러운 칸을 방문해서 깨끗한 칸으로 바꿀 수 있다.

일부 칸에는 가구가 놓여져 있고, 가구의 크기도 1×1이다. 로봇 청소기는 가구가 놓여진 칸으로 이동할 수 없다.

로봇은 한 번 움직일 때, 인접한 칸으로 이동할 수 있다. 또, 로봇은 같은 칸을 여러 번 방문할 수 있다.

방의 정보가 주어졌을 때, 더러운 칸을 모두 깨끗한 칸으로 만드는데 필요한 이동 횟수의 최솟값을 구하는 프로그램을 작성하시오.

입력
입력은 여러 개의 테스트케이스로 이루어져 있다.

각 테스트 케이스의 첫째 줄에는 방의 가로 크기 w와 세로 크기 h가 주어진다. (1 ≤ w, h ≤ 20) 둘째 줄부터 h개의 줄에는 방의 정보가 주어진다. 방의 정보는 4가지 문자로만 이루어져 있으며, 각 문자의 의미는 다음과 같다.

.: 깨끗한 칸
*: 더러운 칸
x: 가구
o: 로봇 청소기의 시작 위치
더러운 칸의 개수는 10개를 넘지 않으며, 로봇 청소기의 개수는 항상 하나이다.

입력의 마지막 줄에는 0이 두 개 주어진다.

출력
각각의 테스트 케이스마다 더러운 칸을 모두 깨끗한 칸으로 바꾸는 이동 횟수의 최솟값을 한 줄에 하나씩 출력한다. 만약, 방문할 수 없는 더러운 칸이 존재하는 경우에는 -1을 출력한다.

풀이:
더러운 칸의 개수가 10개를 넘지 않기 때문에 BFS 와 브루트 포스로 풀이할 수 있다.
BFS로 모든 점에 대해 한 점에서 한 점까지의 최단 거리를 모두 구한다.
이후, 브루트 포스로 시작점(index : 0) 부터 거리의 합이 최소인 점 배열을 구하면 된다.
최대 11개(시작점 포함)의 점을 나열하는 방법은 11! 로 4천만정도의 연산이므로 충분히 시간 안에 통과된다.
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
int maps[21][21];
int dist[12][12];
vector<pii> points;
int ans;

int BFS(pii start, pii end) {
	queue<pair<pii, int>> q;
	bool visit[21][21];
	fill(&visit[0][0], &visit[20][21], false);

	q.push({ start, 0});

	while (!q.empty()) {
		pii now = q.front().first;
		int now_move = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = now.first + mv1[i];
			int ny = now.second + mv2[i];
			int next_move = now_move + 1;
		
			if (nx < 0 || nx >= h || ny < 0 || ny >= w)	continue;
			if (maps[nx][ny] == -1)	continue;

			if (!visit[nx][ny]) {
				visit[nx][ny] = true;
				if (nx == end.first && ny == end.second) {
					return next_move;
				}
				q.push({ {nx, ny}, next_move });
			}
		}
	}
	return -1;
}

void brute(int check_mask, int now, int sum, int left) {
	if (left == 0) {
		ans = min(ans, sum);
		return;
	}

	for (int i = 0; i < points.size(); i++)
	{
		if (((1 << i) & check_mask) == 0) {
			brute((1 << i) | check_mask, i, sum + dist[now][i], left - 1);
		}
	}
}

int main() {
	FIO;

	while (true) {

		cin >> w >> h;

		if (w == 0 && h == 0)	break;

		fill(&maps[0][0], &maps[20][21], 0);
		fill(&dist[0][0], &dist[11][12], 0);
		points.clear();
		points.push_back({ -1, -1 });
		ans = IMAX;

		for (int i = 0; i < h; i++)
		{
			string str;
			cin >> str;
			for (int j = 0; j < w; j++)
			{
				if (str[j] == 'o') {
					points[0] = { i, j };
				}
				else if (str[j] == '*') {
					points.push_back({ i, j });
				}
				else if (str[j] == 'x') {
					maps[i][j] = -1;
				}
			}
		}

		bool cant = false;

		for (int i = 0; i < points.size() - 1; i++)
		{
			for (int j = i + 1; j < points.size(); j++)
			{
				dist[i][j] = BFS(points[i], points[j]);
				dist[j][i] = dist[i][j];
				if (dist[i][j] == -1) {
					cant = true;
				}
			}
		}

		brute(1, 0, 0,  points.size() - 1);


		if (!cant)
			cout << ans << "\n";
		else
			cout << "-1\n";
	}
}