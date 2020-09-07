/*
����
���� ������ ��� ������ �ν��̴� ���� ������ ����Ϸ��� �Ѵ�. �ν��̰� ������ ����� ���� �� ������ �д� ������� �ɾ� �ִ� �����̴�. ������ ���簢������̰�, ��� ���� ũ���� ���簢�� ������� �������� �ִ�.

�Է����� ������ ������ �־�����. ������ ���簢�� ����� ������ ���� 4���� ������ �ִ�.

S : ���� �ν��̰� �ִ� ���̴�. �̰��� �ν��̰� ����� �����ϴ� ���̴�.
C : �ν��̰� �ݵ�� ������ ����ؾ� �ϴ� ���̴�. �̷��� ����� ��Ȯ�ϰ� 2�� �ִ�.
# : �ν��̰� �� �� ���� ���̴�.
. : �ν��̰� �����Ӱ� ������ �� �ִ� ���̴�.
�ν��̰� �� ��� ������������ �̵��ϴµ��� 1���� �ɸ���. �ν��̴� �װ��� ���� �� �ϳ��� �̵��� �� ������, ������ ��� �� ����. �ν��̰� ������ ����ؾ� �ϴ� ���� �� ��, �ν��̴� �� ���� �ִ� ��� ��ο��� ������ �����ؾ� �Ѵ�. �� ��Ȳ�� ���ÿ� �Ͼ��, �߰����� �ð��� �ҿ���� �ʴ´�.

�ν��̴� ��� ������ �ڽ��� ���� �ʾ����� �ϱ� ������, ������ �ʰ� �� �ð����� ������ �ٲ�� �Ѵ�. �� ���� ���� �������� �� �� �������� �̵��� �� ���ٴ� ���̴�. �ν��̰� ������ ��� ����ϴµ� �ɸ��� �ð��� �ּڰ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ������ ���� ũ�� N�� ���� ũ�� M�� �־�����. N�� M�� 50���� �۰ų� ���� �ڿ����̴�. ��° �ٺ��� N���� �ٿ� ������ ������ �־�����.

���
ù° �ٿ� �ν��̰� ������ ��� ����ϴµ� �ɸ��� �ð��� �ּڰ��� ����Ѵ�. ���� �Ұ��� �� ���� -1�� ����Ѵ�.

Ǯ��:
������ = s, ����1 = d1, ����2 = d2 ���� ���� ��,
���ؾ� �ϴ� �ּ� ��δ� min(s -> d1 -> d2 , s -> d2 -> d1) �̴�.

������ ���ǿ��� ���� �������� �ι� �� �� �����Ƿ� a -> b �� �� �� ���� ���������� ���� ���⿡ ����
4���� �Ÿ� ���� ���ؾ� �Ѵ�.
�湮 �迭�� ���� ���� ���� �߰��� bfs �ϸ� ���� �� �ִ�.
�׷��� s -> d1 ���� �� �� 4���� * d1 -> d2 �� �� 4 ���� --> 16������ ��� �� �ּ� ��θ� ���ϸ� �ȴ�.
s -> d2 -> d1 �� ���ؼ��� �Ȱ��� �����Ѵ�.
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