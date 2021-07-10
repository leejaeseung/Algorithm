/*
����
������ ���簢�� ����� ���� �κ� û�ұ⸦ �̿��� û���Ϸ��� �Ѵ�. �� �κ� û�ұ�� ������ ���� ��θ� ������ �� �ִ�.

���� ũ�Ⱑ 1��1�� ���簢�� ĭ���� �������� ������, �κ� û�ұ��� ũ�⵵ 1��1�̴�. ĭ�� ������ ĭ�� ������ ĭ���� �������� ������, �κ� û�ұ�� ������ ĭ�� �湮�ؼ� ������ ĭ���� �ٲ� �� �ִ�.

�Ϻ� ĭ���� ������ ������ �ְ�, ������ ũ�⵵ 1��1�̴�. �κ� û�ұ�� ������ ������ ĭ���� �̵��� �� ����.

�κ��� �� �� ������ ��, ������ ĭ���� �̵��� �� �ִ�. ��, �κ��� ���� ĭ�� ���� �� �湮�� �� �ִ�.

���� ������ �־����� ��, ������ ĭ�� ��� ������ ĭ���� ����µ� �ʿ��� �̵� Ƚ���� �ּڰ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
�Է��� ���� ���� �׽�Ʈ���̽��� �̷���� �ִ�.

�� �׽�Ʈ ���̽��� ù° �ٿ��� ���� ���� ũ�� w�� ���� ũ�� h�� �־�����. (1 �� w, h �� 20) ��° �ٺ��� h���� �ٿ��� ���� ������ �־�����. ���� ������ 4���� ���ڷθ� �̷���� ������, �� ������ �ǹ̴� ������ ����.

.: ������ ĭ
*: ������ ĭ
x: ����
o: �κ� û�ұ��� ���� ��ġ
������ ĭ�� ������ 10���� ���� ������, �κ� û�ұ��� ������ �׻� �ϳ��̴�.

�Է��� ������ �ٿ��� 0�� �� �� �־�����.

���
������ �׽�Ʈ ���̽����� ������ ĭ�� ��� ������ ĭ���� �ٲٴ� �̵� Ƚ���� �ּڰ��� �� �ٿ� �ϳ��� ����Ѵ�. ����, �湮�� �� ���� ������ ĭ�� �����ϴ� ��쿡�� -1�� ����Ѵ�.

Ǯ��:
������ ĭ�� ������ 10���� ���� �ʱ� ������ BFS �� ���Ʈ ������ Ǯ���� �� �ִ�.
BFS�� ��� ���� ���� �� ������ �� �������� �ִ� �Ÿ��� ��� ���Ѵ�.
����, ���Ʈ ������ ������(index : 0) ���� �Ÿ��� ���� �ּ��� �� �迭�� ���ϸ� �ȴ�.
�ִ� 11��(������ ����)�� ���� �����ϴ� ����� 11! �� 4õ�������� �����̹Ƿ� ����� �ð� �ȿ� ����ȴ�.
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