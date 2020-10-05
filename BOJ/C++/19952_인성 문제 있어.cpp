/*
����
�μ��̴� �νΰ� �Ǳ� ���ؼ� �ν�Ʈ Ư�������� �����ߴ�. �Ʒ� ù�� �μ��̴� �賭�� �̷ο��� �������� �����ؾ� �ϴ� �Ʒ��� �ް� �ִ�. ���� �ð� �ȿ� �̷θ� ������� ���ϸ� ��� ���� �Կ��� ���� ��⿡ �μ��̴� �ּ��� ���� �̷θ� ����Ϸ��� �Ѵ�.

�̷δ� ���� ���� W, ���� ���� H�� ���� ���¸� ������, �μ��̴� �� ���� ���� ���� ��, ��, ��, ��� ��ĭ �� ������ �� �ִ�.  �� �̵��� �Ϸ�� �ÿ� �μ����� ���� ���� 1�� �����ϰ�, ���� ���� 0������ ��쿡�� �� �̻� �������� ���ϰ� �ȴ�.

�̷��� �� ���ڿ��� ��ֹ��� �ִµ�, ������ ��ֹ��� ���� ������ ������ �ִ�. ��ֹ��� ���� ��ġ�� ���� ���̰� 0 �̴�. �μ��̰� �̵��� ��, ���� ��ġ���� �̵��� ��ġ�� ���̰� �� ������ �ƹ��� ������ ���� �ʰ� �̵��� �� �ִ�. �� ���� ������ �̵��� ���� ������ �� �� �ִµ�, �����ؾ� �ϴ� ���̴� (�̵��� ���� ���� - ���� ��ġ�� ���� ����) �̴�. �̶� �����ִ� ���� �����ؾ� �ϴ� ���̺��� ũ�ų� ������ �̵��� �� �ְ�, �׷��� ������ �̵����� ���Ѵ�.

�μ��̴� ��ü�� �Ѱ踦 �غ��ϰ� ������ �������� �����ؼ� ��� �������� �弳�� ���� ���� �� ������?

�Է�
ù° �ٿ� �׽�Ʈ ���̽� T�� �־�����. �� �׽�Ʈ ���̽��� ������ ���� �־�����.

ù° �ٿ� �̷��� ���α��� H, ���α��� W, ��ֹ��� ���� O, �ʱ� �� F, ������� ��ǥ ���� Xs(��), Ys(��)�������� ��ǥ���� Xe(��), Ye(��) �� �־�����.

��° �ٺ��� O���� �ٿ� ��ֹ��� ��ǥ ���� X(��), Y(��) �� ���� ���� L�� �־�����. ��� ��ֹ��� ���� �ٸ� ��ġ�� �����Ѵ�.

���
T���� �ٿ� �μ��̰� �������� ������ �� ���� �� "���߾�!!", �������� ������ �� ���� �� "�μ� �����־�??" �� ����Ѵ�.

����
1 �� T �� 10
2 �� H, W �� 100
0 �� O �� H x W
0 �� F �� 10,000, F �� �����̴�.
1 �� L �� 50, L�� �����̴�.
1 �� X, Xs, Xe �� H
1 �� Y, Ys, Ye �� W
���� ��ġ�� ���������� ��ֹ��� �������� �ʴ´�.

Ǯ��:
������ ���ǿ� �°� BFS�� �ϰ�,
�湮�� üũ�� �� ���� �� ���� ��� �湮���� �ʰ� ���ָ� �ȴ�.
������ �� ����
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

int T, H, W, O, F;
int sx, sy, ex, ey;
int maps[101][101];
int visit[101][101];

int main(void) {
	FIO;

	cin >> T;

	while (T--) {

		cin >> H >> W >> O >> F >> sx >> sy >> ex >> ey;

		fill(&maps[0][0], &maps[100][101], 0);
		fill(&visit[0][0], &visit[100][101], -1);

		for (int i = 0; i < O; i++)
		{
			int x, y, L;
			cin >> x >> y >> L;

			maps[x][y] = L;
		}

		bool canGo = false;
		queue<pair<pii, int>> q;
		visit[sx][sy] = F;
		q.push({ {sx, sy}, F });

		while (!q.empty()) {
			pii now = q.front().first;
			int nowF = q.front().second;
			q.pop();

			if (nowF <= 0)	continue;

			for (int i = 0; i < 4; i++)
			{
				int nx = now.first + mv1[i];
				int ny = now.second + mv2[i];

				if (nx <= 0 || ny <= 0 || nx > H || ny > W || maps[nx][ny] > maps[now.first][now.second] + nowF)	continue;

				if (visit[nx][ny] < nowF - 1) {
					visit[nx][ny] = nowF - 1;

					if (nx == ex && ny == ey) {
						canGo = true;
						break;
					}

					q.push({ {nx, ny}, nowF - 1 });
				}
			}

			if (canGo)	break;
		}

		if (canGo)
			cout << "���߾�!!\n";
		else
			cout << "�μ� �����־�??\n";
	}
}