/*
����
N��N ũ���� ������ ����� M������ �Ʊ� ��� 1������ �ִ�. ������ 1��1 ũ���� ���簢�� ĭ���� �������� �ִ�. �� ĭ���� ����Ⱑ �ִ� 1���� �����Ѵ�.

�Ʊ� ���� ������ ��� ũ�⸦ ������ �ְ�, �� ũ��� �ڿ����̴�. ���� ó���� �Ʊ� ����� ũ��� 2�̰�, �Ʊ� ���� 1�ʿ� �����¿�� ������ �� ĭ�� �̵��Ѵ�.

�Ʊ� ���� �ڽ��� ũ�⺸�� ū ����Ⱑ �ִ� ĭ�� ������ �� ����, ������ ĭ�� ��� ������ �� �ִ�. �Ʊ� ���� �ڽ��� ũ�⺸�� ���� ����⸸ ���� �� �ִ�. ����, ũ�Ⱑ ���� ������ ���� �� ������, �� ����Ⱑ �ִ� ĭ�� ������ �� �ִ�.

�Ʊ� �� ���� �̵����� �����ϴ� ����� �Ʒ��� ����.

�� �̻� ���� �� �ִ� ����Ⱑ ������ ���ٸ� �Ʊ� ���� ���� ���� ������ ��û�Ѵ�.
���� �� �ִ� ����Ⱑ 1�������, �� ����⸦ ������ ����.
���� �� �ִ� ����Ⱑ 1�������� ���ٸ�, �Ÿ��� ���� ����� ����⸦ ������ ����.
�Ÿ��� �Ʊ� �� �ִ� ĭ���� ����Ⱑ �ִ� ĭ���� �̵��� ��, �������ϴ� ĭ�� ������ �ּڰ��̴�.
�Ÿ��� ����� ����Ⱑ ���ٸ�, ���� ���� �ִ� �����, �׷��� ����Ⱑ �����������, ���� ���ʿ� �ִ� ����⸦ �Դ´�.
�Ʊ� ����� �̵��� 1�� �ɸ���, ����⸦ �Դµ� �ɸ��� �ð��� ���ٰ� �����Ѵ�. ��, �Ʊ� �� ���� �� �ִ� ����Ⱑ �ִ� ĭ���� �̵��ߴٸ�, �̵��� ���ÿ� ����⸦ �Դ´�. ����⸦ ������, �� ĭ�� �� ĭ�� �ȴ�.

�Ʊ� ���� �ڽ��� ũ��� ���� ���� ����⸦ ���� �� ���� ũ�Ⱑ 1 �����Ѵ�. ���� ���, ũ�Ⱑ 2�� �Ʊ� ���� ����⸦ 2���� ������ ũ�Ⱑ 3�� �ȴ�.

������ ���°� �־����� ��, �Ʊ� �� �� �� ���� ���� ���� ������ ��û���� �ʰ� ����⸦ ��Ƹ��� �� �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ������ ũ�� N(2 �� N �� 20)�� �־�����.

��° �ٺ��� N���� �ٿ� ������ ���°� �־�����. ������ ���´� 0, 1, 2, 3, 4, 5, 6, 9�� �̷���� �ְ�, �Ʒ��� ���� �ǹ̸� ������.

0: �� ĭ
1, 2, 3, 4, 5, 6: ĭ�� �ִ� ������� ũ��
9: �Ʊ� ����� ��ġ
�Ʊ� ���� ������ �� ���� �ִ�.

���
ù° �ٿ� �Ʊ� �� ���� ���� ������ ��û���� �ʰ� ����⸦ ��Ƹ��� �� �ִ� �ð��� ����Ѵ�.

Ǯ��:
������ ���ǿ� �°� �� �Ʊ� �� ��ġ�� ���� bfs�� ���� �� ���Ѵ�.
�Ʊ� �� ���� ����� ��ġ�� �ű��, �̵��� ����ŭ �ʸ� ī��Ʈ�Ѵ�.
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
int mv1[4] = { 0, 1, 0, -1 };
int mv2[4] = { 1, 0, -1, 0 };
int mv_all1[8] = { 0, 1, 0, -1, -1, -1, 1, 1 };
int mv_all2[8] = { 1, 0, -1, 0 , -1, 1, -1, 1 };

int n;
int maps[21][21];

pair<pii, int> bfs(pii now, int sz) {
	bool visit[21][21];
	fill(&visit[0][0], &visit[20][21], false);

	int minDis = IMAX;
	queue<pair<pii, int>> q;
	q.push({ { now.first, now.second }, 0 });
	visit[now.first][now.second] = true;

	priority_queue<pair<pii, int>> eat;

	while (!q.empty()) {
		pii now = q.front().first;
		int nowCnt = q.front().second;
		q.pop();

		if (maps[now.first][now.second] < sz && maps[now.first][now.second] != 0) {
			if (minDis > nowCnt) {
				minDis = nowCnt;
				priority_queue<pair<pii, int>> temp;
				eat.swap(temp);

				eat.push({ { -now.first, -now.second }, nowCnt});
			}
			else if (minDis == nowCnt) {
				eat.push({ { -now.first, -now.second }, nowCnt });
			}
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = now.first + mv1[i];
			int ny = now.second + mv2[i];

			if (nx >= n || ny >= n || nx < 0 || ny < 0 || maps[nx][ny] > sz)	continue;

			if (!visit[nx][ny]) {
				visit[nx][ny] = true;

				q.push({ {nx, ny}, nowCnt + 1 });
			}
		}
	}
	
	if (eat.empty())
		return { { -1, -1 }, -1};
	else
		return eat.top();
}

int main(void) {
	FIO;

	cin >> n;

	pii baby;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> maps[i][j];
			if (maps[i][j] == 9)
				baby = { i, j };
		}
	}

	int ans = 0;
	int nowSize = 2;
	int eatCnt = 0;

	while (true) {
		pair<pii, int> next = bfs(baby, nowSize);

		if (next.second == -1)
			break;
		
		ans += next.second;
		maps[baby.first][baby.second] = 0;
		baby = { -next.first.first, -next.first.second };
		maps[baby.first][baby.second] = 0;

		eatCnt++;
		if (eatCnt == nowSize) {
			eatCnt = 0;
			nowSize++;
		}
	}

	cout << ans;
}