/*
����
n��n¥���� �迭�� �ϳ� �ִ�. �� �迭�� (1, 1)���� (n, n)���� �̵��Ϸ��� �Ѵ�. �̵��� ���� ��, ��, ��, ���� �� ������ ĭ���θ� �̵��� �� �ִ�.

�̿� ���� �̵��ϴ� ����, �迭���� �� ���� ���� ���ļ� �̵��ϰ� �ȴ�. �̵��ϱ� ���� ���� �� ���� �� �ִ񰪰� �ּڰ��� ���̰� ���� �۾����� ��츦 ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� n(2��n��100)�� �־�����. ���� n���� �ٿ��� �迭�� �־�����. �迭�� �� ���� 0���� ũ�ų� ����, 200���� �۰ų� ���� �����̴�.

���
ù° �ٿ� (�ִ� - �ּ�)�� ���� �۾��� ���� �� ���� ����Ѵ�.

Ǯ��:
�̺�Ž�� Ǯ�� :
�Ķ��Ʈ�� ��ġ�� ����ϴ�.
diff ���� �ִ� 200 �̹Ƿ� 0 ~ 200 �� �̺�Ž�� ���ָ� �ش� diff�� bfs�� ���� ��ΰ� �����Ǵ��� �Ǵ��Ѵ�.

bfs Ǯ�� : 
�� ������ diff �� �ش� �������� ����� �ּڰ�(Ȥ�� �ִ�) �� ¦���� �� �ִ�.
���� visit[x][y][min or max] �� �湮 �迭�� �����ϰ�, �湮�� ���� diff ������ ���� ���� Ž���ϵ��� �Ѵ�.
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

int n;
int maps[101][101];
int visit[101][101][201];
int ans = IMAX;

void BFS() {
	queue<pair<pii, pii>> q;

	visit[0][0][0] = true;
	q.push({ {0, 0}, {maps[0][0], maps[0][0]} });

	while (!q.empty()) {
		pii now = q.front().first;
		int nowMin = q.front().second.first;
		int nowMax = q.front().second.second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = now.first + mv1[i];
			int ny = now.second + mv2[i];
			int nextV = maps[nx][ny];
			int nextMin = min(nowMin, nextV);
			int nextMax = max(nowMax, nextV);
			int nextDif = nextMax - nextMin;

			if (nx < 0 || nx >= n || ny < 0 || ny >= n)	continue;

			if (visit[nx][ny][nextMin] > nextDif) {
				visit[nx][ny][nextMin] = nextDif;

				if (nx == n - 1 && ny == n - 1) {
					ans = min(ans, nextDif);
					continue;
				}

				q.push({ {nx, ny}, {nextMin, nextMax} });
			}
		}
	}
}

int main(void) {
	FIO;

	cin >> n;

	fill(&visit[0][0][0], &visit[100][101][201], IMAX);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> maps[i][j];
		}
	}

	BFS();

	cout << ans;
}