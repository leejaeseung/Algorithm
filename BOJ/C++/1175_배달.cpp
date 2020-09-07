/*
문제
어제 선물을 모두 포장한 민식이는 이제 선물을 배달하려고 한다. 민식이가 선물을 배달할 곳은 이 문제를 읽는 사람들이 앉아 있는 교실이다. 교실은 직사각형모양이고, 모두 같은 크기의 정사각형 블록으로 나누어져 있다.

입력으로 교실의 지도가 주어진다. 각각의 정사각형 블록은 다음과 같이 4가지 종류가 있다.

S : 지금 민식이가 있는 곳이다. 이곳이 민식이가 배달을 시작하는 곳이다.
C : 민식이가 반드시 선물을 배달해야 하는 곳이다. 이러한 블록은 정확하게 2개 있다.
# : 민식이가 갈 수 없는 곳이다.
. : 민식이가 자유롭게 지나갈 수 있는 곳이다.
민식이가 한 블록 동서남북으로 이동하는데는 1분이 걸린다. 민식이는 네가지 방향 중 하나로 이동할 수 있으며, 교실을 벗어날 수 없다. 민식이가 선물을 배달해야 하는 곳에 들어갈 때, 민식이는 그 곳에 있는 사람 모두에게 선물을 전달해야 한다. 이 상황은 동시에 일어나며, 추가적인 시간이 소요되지 않는다.

민식이는 어느 누구도 자신을 보지 않았으면 하기 때문에, 멈추지 않고 매 시간마다 방향을 바꿔야 한다. 이 말은 같은 방향으로 두 번 연속으로 이동할 수 없다는 말이다. 민식이가 선물을 모두 배달하는데 걸리는 시간의 최솟값을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 교실의 세로 크기 N과 가로 크기 M이 주어진다. N과 M은 50보다 작거나 같은 자연수이다. 둘째 줄부터 N개의 줄에 교실의 지도가 주어진다.

출력
첫째 줄에 민식이가 선물을 모두 배달하는데 걸리는 시간의 최솟값을 출력한다. 만약 불가능 할 때는 -1을 출력한다.

풀이:
시작점 = s, 선물1 = d1, 선물2 = d2 으로 놨을 때,
구해야 하는 최소 경로는 min(s -> d1 -> d2 , s -> d2 -> d1) 이다.

문제의 조건에서 같은 방향으로 두번 갈 수 없으므로 a -> b 로 갈 때 도착 지점에서의 이전 방향에 대해
4개의 거리 값을 구해야 한다.
방문 배열에 이전 방향 값을 추가해 bfs 하면 구할 수 있다.
그러면 s -> d1 으로 갈 때 4가지 * d1 -> d2 갈 때 4 가지 --> 16가지의 경우 중 최소 경로를 구하면 된다.
s -> d2 -> d1 에 대해서도 똑같이 수행한다.
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
int mv1[4] = { 0, 0, 1, -1 };
int mv2[4] = { 1, -1, 0, 0 };
int mv_all1[8] = { 0, 1, 0, -1, -1, -1, 1, 1 };
int mv_all2[8] = { 1, 0, -1, 0 , -1, 1, -1, 1 };

int n, m;
char maps[51][51];

vector<int> BFS(pii src, pii dst, int dir) {
	queue< pair < pii, pii >> q;

	bool visit[51][51][4];
	fill(&visit[0][0][0], &visit[50][50][4], false);

	visit[src.first][src.second][dir] = true;
	q.push({ {src.first, src.second}, {dir, 0} });

	vector<int> ret(4, IMAX);

	while (!q.empty()) {
		pii now = q.front().first;
		int prevDir = q.front().second.first;
		int nowMove = q.front().second.second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = now.first + mv1[i];
			int ny = now.second + mv2[i];

			if (i == prevDir)	continue;
			if (nx < 0 || ny < 0 || nx >= n || ny >= m)	continue;
			if (maps[nx][ny] == '#')	continue;

			if (!visit[nx][ny][i]) {
				visit[nx][ny][i] = true;
				if (nx == dst.first && ny == dst.second)
					ret[i] = nowMove + 1;

				q.push({ {nx, ny}, {i, nowMove + 1 } });
			}
		}
	}

	return ret;
}

int search(pii src, pii dst1, pii dst2) {
	int ret = IMAX;

	for (int i = 0; i < 4; i++)
	{
		vector<int> path1 = BFS(src, dst1, i);

		for (int j = 0; j < 4; j++)
		{
			int path1_leng = path1[j];
			if (path1_leng == IMAX)	continue;

			vector<int> path2 = BFS(dst1, dst2, j);

			for (int k = 0; k < 4; k++)
			{
				int path2_leng = path2[k];
				if (path2_leng == IMAX)	continue;

				ret = min(ret, path1_leng + path2_leng);
			}
		}
	}

	return ret;
}

int main(void) {
	FIO;

	cin >> n >> m;

	int idx = 1;
	vector<pii> vt(3);

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < m; j++)
		{
			maps[i][j] = str[j];
			if (maps[i][j] == 'S') {
				vt[0] = {i, j};
			}
			else if (maps[i][j] == 'C') {
				vt[idx++] = { i, j };
			}
		}
	}

	int ans = min(search(vt[0], vt[1], vt[2]), search(vt[0], vt[2], vt[1]));

	if (ans == IMAX)
		cout << "-1";
	else
		cout << ans;
}