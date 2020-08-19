/*
����
����̴� �������� �˼� �� ���� Ż�����Ѿ� �Ѵ�. �� ������ 1��¥�� �ǹ��̰�, ����̴� ��� ��鵵�� �����.

��鵵���� ��� ���� ���� ��Ÿ���ְ�, Ż�����Ѿ� �ϴ� �˼��� ��ġ�� ��Ÿ�� �ִ�. ������ ���� �������� �˼� �� ���� ������ �ִ� ������ ����̴�.

���� �߾� ����ǿ����� �� �� �ִ�. ����̴� Ư���� ����� �̿��� ������� ������ �ʰ� ���� ������ �Ѵ�. ������, ���� ������ �ð��� �ſ� ���� �ɸ���. �� �˼��� Ż����Ű�� ���ؼ� ����� �ϴ� ���� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �׽�Ʈ ���̽��� ������ �־�����. �׽�Ʈ ���̽��� ���� 100���� ���� �ʴ´�.

ù° �ٿ��� ��鵵�� ���� h�� �ʺ� w�� �־�����. (2 �� h, w �� 100) ���� h�� �ٿ��� ������ ��鵵 ������ �־�����, �� ������ '.', ������ �� ���� ���� '*', ���� '#', �˼��� ��ġ�� '$'�̴�.

����̴� ���� ���� �����Ӱ� �̵��� �� �ְ�, ��鵵�� ǥ�õ� �˼��� ���� �׻� �� ���̴�. �� �˼��� ������ �ٱ��� �����ϴ� ��ΰ� �׻� �����ϴ� ��츸 �Է����� �־�����.

���
�� �׽�Ʈ ���̽����� �� �˼��� Ż����Ű�� ���ؼ� ����� �ϴ� ���� �ּڰ��� ����Ѵ�.

Ǯ��:
https://jaimemin.tistory.com/1243
�� ��α׸� �����Ͽ� Ǯ����.

���, �˼�1, �˼�2 �� ������ ��� ����(i, j) ���� ���� �� �ּ� Ƚ���� �̸� ���س��´�.
(���ͽ�Ʈ�� �̿�)

��� ���� ���� �� ���� �� Ƚ���� ���� ���� �ּҰ��� ������ �Ǵµ�
� ���� '#' �̶�� �ߺ��� �� �� �Ͼ���Ƿ� 2�� ���ְ� ����ϸ� �ȴ�.
(�˼��� Ż���ߴ�. == �� ���� �� �������� ������. �̹Ƿ�)

���� '.' ���� �� �� ������ �� ����̴� (0, 0) ���� ��߽�Ų��.
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
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vii vector<pii>
#define IMAX 2000000001
#define LMAX 1000000000000000000
#define DMAX 0xFFFFFFFFFFFFF
int mv1[4] = { 0, 0, 1, -1 };
int mv2[4] = { 1, -1, 0, 0 };
int mv_all1[8] = { 0, 1, 0, -1, -1, -1, 1, 1 };
int mv_all2[8] = { 1, 0, -1, 0 , -1, 1, -1, 1 };

int h, w;
char maps[103][103];
int dis[3][103][103];
pii player[3];

int main(void) {
	FIO;

	int t;
	cin >> t;

	while (t--) {
		cin >> h >> w;

		int p = 1;
		player[0] = make_pair(0, 0);

		for (int i = 0; i <= h + 1; i++)
		{
			string str;
			if (i > 0 && i <= h)
			cin >> str;

			for (int j = 0; j <= w + 1; j++)
			{
				dis[0][i][j] = IMAX;
				dis[1][i][j] = IMAX;
				dis[2][i][j] = IMAX;

				if (i == 0 || j == 0 || i == h + 1 || j == w + 1)
					maps[i][j] = '.';
				else {
					maps[i][j] = str[j - 1];

					
					

					if (maps[i][j] == '$') {
						player[p] = make_pair(i, j);
						maps[i][j] = p++;
					}
				}
			}
		}
		
		priority_queue<pair<pii, pii>> pq;

		for (int i = 0; i < 3; i++)
		{
			int x = player[i].first;
			int y = player[i].second;

			dis[i][x][y] = 0;
			pq.push(make_pair(make_pair(0, i), make_pair(x, y)));
		}

		while (!pq.empty()) {
			int nowDis = -pq.top().first.first;
			int nowP = pq.top().first.second;
			int nowx = pq.top().second.first;
			int nowy = pq.top().second.second;
			pq.pop();

			for (int i = 0; i < 4; i++)
			{
				int nx = nowx + mv1[i];
				int ny = nowy + mv2[i];

				if (nx < 0 || ny < 0 || nx > h + 1 || ny > w + 1)	continue;
				if (maps[nx][ny] == '*')	continue;

				if (maps[nx][ny] == '#') {
					if (dis[nowP][nx][ny] > dis[nowP][nowx][nowy] + 1) {
						dis[nowP][nx][ny] = dis[nowP][nowx][nowy] + 1;

						pq.push(make_pair(make_pair(-dis[nowP][nx][ny], nowP), make_pair(nx, ny)));
					}
				}
				else {
					if (dis[nowP][nx][ny] > dis[nowP][nowx][nowy]) {
						dis[nowP][nx][ny] = dis[nowP][nowx][nowy];

						pq.push(make_pair(make_pair(-dis[nowP][nx][ny], nowP), make_pair(nx, ny)));
					}
				}
			}
		}

		int ans = IMAX;

		for (int i = 0; i <= h + 1; i++)
		{
			for (int j = 0; j <= w + 1; j++)
			{
				if (maps[i][j] != '*') {
					int sum = 0;

					for (int k = 0; k < 3; k++)
					{
						sum += dis[k][i][j];
					}

					if (maps[i][j] == '#') {
						sum -= 2;
					}

					ans = min(ans, sum);
				}
			}
		}

		cout << ans << "\n";
	}
}