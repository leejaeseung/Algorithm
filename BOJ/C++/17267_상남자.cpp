/*
����
CTP�� ��ǥ ���� ������ �����Ӱ� �̵��ϴ� ���� �����Ѵ�. �׷����� ������ �����̱� ������ ���Ʒ��θ� ����. ���� ��, �Ʒ��δ� �󸶵��� �̵��� �� ������ ����, ���������δ� �̵����� �ʴ´�. ������ ������ �ൿ�� ����� ������ ģ�� �����̴� ������ ��, �Ʒ��θ� ���� �� ���� ���� ������ ���� �ٴϸ� �������� �ִ� L�� ���������� �ִ� R����ŭ �̵��� �� �ְ� ������ �����ش�. ������ �����̴� ���� �����δ� ������ �ʴ´�.

���� �ִ� ��, ���� ��ġ, ������ �������� ��� ��ġ�� ���� ������ �־����� �� ������ �����̰� ��� ��ġ�κ��� �̵��ؼ� �� �� �ִ� ��� ���� ������ ���غ���.

������ ���ظ� ���� ���� ����1 �׸��̴�.



������ �����̰� ���� ��ġ���� ���� �ִ� ���� �Ķ���, ���� �־� ���� ���� ���� �������̴�.

���� �׸��� ������ �����̰� ���� ��ġ���� �������� �� ĭ �̵����� ���̴�.



�������� �� ĭ �̵��Ͽ����Ƿ� �� �̻� �������δ� �� �� ����, ���� ���¿��� ���� �ִ� ���� �Ķ������� ��Ÿ������.

���� �׸��� ������ �����̰� ���� ��ġ���� �Ʒ��� ���� ���̴�.



������ �����̰� �Ʒ��� �� ĭ �̵����� ���� �� �� �ִ� ���� ���� �����̴�.

���� �׸��� ������ �����̰� �����Ӱ� �̵��Ͽ��� �� ���� ������ ���� ��Ÿ����.



������ �����̰� �ִ� �������� L��, ���������� R�� ��ŭ �������� �����Ӱ� �̵����� �� ���� ������ ���� 13ĭ�̴�.

�Է�
ù ��° �ٿ� ������ ��� �� N, M�� �־����� (1 �� N, M �� 1,000)

�� ��° �ٿ� ���ʰ� ���������� ���� �ִ� �ִ� Ƚ�� L, R�� �־�����. (0 �� L, R �� M)

�� ��° �ٺ��� N+2�ٱ��� M �� ũ�⸸ŭ ������ �־�����.

0: �� �� �ִ� ��
1: ���� �־� �� �� ���� ��
2: ������ �����̰� �ִ� ��ġ
���
���� ��ġ�� �����Ͽ� ���� �ִ� ���� ������ ����Ѵ�.

Ǯ��:
�켱���� ť�� �̿��� BFS�� Ǯ���ߴ�.

�� �Ʒ��� �� �� �ִ� ���� ���� ����, �������� ����Ͽ� �� �ʿ䰡 ����.
���� ���� �鸦 ������ �� ���� ���Ʒ��� ������ ���� Ž���Ѵ�.

��,�Ʒ� �� ���� �켱 ������ 1�� �ְ� ����, ������ �� ���� �켱 ������ 0���� �ָ� �׻� ���Ʒ��� ť���� ���� ���´�.
��, ť�� ����, �����ʹۿ� ���� �ʾҴٸ� �̵� Ƚ���� ���� �ʿ��� �켱 ������ ���� �ش�.
(�̵� Ƚ�� = ����, ���������� �� Ƚ��, ���Ʒ��� �̵� Ƚ���� ���Խ�Ű�� �ʴ´�)
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
int L, R;
int maps[1001][1001];
bool visit[1001][1001];
int prio[4];
priority_queue<pair<pii, pair<pii, pii>>> pq;

int main(void) {
	FIO;

	cin >> n >> m >> L >> R;

	int ans = 0;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < m; j++)
		{
			maps[i][j] = int(str[j] - '0');
			if (maps[i][j] == 2) {
				pq.push({ {-1, 0}, {{i, j}, {0, 0}} });
			}
		}
	}

	prio[2] = 1;
	prio[3] = 1;
	//���Ʒ� �̵� �� �켱 ���� ����

	while (!pq.empty()) {
		pii now = pq.top().second.first;
		pii LR = pq.top().second.second;
		int nowMove = -pq.top().first.second;
		pq.pop();

		if (LR.first > L || LR.second > R)	continue;
		if (visit[now.first][now.second])	continue;

		visit[now.first][now.second] = true;
		ans++;


		for (int i = 0; i < 4; i++)
		{
			int nx = now.first + mv1[i];
			int ny = now.second + mv2[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m)	continue;
			if (maps[nx][ny] == 1)	continue;

			if (!visit[nx][ny]) {

				pii nextLR = LR;
				int nextMove = nowMove + 1;

				if (i == 0)
					nextLR.second++;
				else if (i == 1)
					nextLR.first++;
				else
					nextMove--;
				//���Ʒ� �̵� �� �̵� Ƚ�� 0


				pq.push({ {prio[i], -nextMove }, {{nx, ny}, nextLR } });
				//�̵� Ƚ���� ���� ������ �켱 ���� �ο�
			}
		}
	}

	cout << ans;
}