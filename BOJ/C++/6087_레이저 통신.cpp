/*
����
ũ�Ⱑ 1��1�� ���簢������ �������� W��H ũ���� ������ �ִ�. ������ �� ĭ�� �� ĭ�̰ų� ���̸�, �� ĭ�� 'C'�� ǥ�õǾ� �ִ� ĭ�̴�.

'C'�� ǥ�õǾ� �ִ� �� ĭ�� �������� ����ϱ� ���ؼ� ��ġ�ؾ� �ϴ� �ſ� ������ �ּڰ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�. �������� ����Ѵٴ� ���� �� ĭ�� �������� ������ �� ������ �ǹ��Ѵ�.

�������� C������ �߻��� �� �ְ�, �� ĭ�� �ſ�('/', '\')�� ��ġ�ؼ� ������ 90�� ȸ����ų �� �ִ�.

�Ʒ� �׸��� H = 8, W = 7�� ����̰�, �� ĭ�� '.', ���� '*'�� ��Ÿ�´�. ������ �ʱ� ����, �������� �ּ� ������ �ſ��� ����ؼ� �� 'C'�� ������ ���̴�.

7 . . . . . . .         7 . . . . . . .
6 . . . . . . C         6 . . . . . /-C
5 . . . . . . *         5 . . . . . | *
4 * * * * * . *         4 * * * * * | *
3 . . . . * . .         3 . . . . * | .
2 . . . . * . .         2 . . . . * | .
1 . C . . * . .         1 . C . . * | .
0 . . . . . . .         0 . \-------/ .
  0 1 2 3 4 5 6           0 1 2 3 4 5 6
�Է�
ù° �ٿ� W�� H�� �־�����. (1 �� W, H �� 100)

��° �ٺ��� H���� �ٿ� ������ �־�����. ������ �� ���ڰ� �ǹ��ϴ� ���� ������ ����.

.: �� ĭ
*: ��
C: �������� �����ؾ� �ϴ� ĭ
'C'�� �׻� �� ���̰�, �������� ������ �� �ִ� �Է¸� �־�����.

���
ù° �ٿ� C�� �����ϱ� ���� ��ġ�ؾ� �ϴ� �ſ� ������ �ּڰ��� ����Ѵ�.

Ǯ��:
���� BFS�� Ž���ϴµ�, ������ ���� ������ Mir ī��Ʈ�� �÷��ش�.
�̹� �湮�� ���� Mir ī��Ʈ�� �ּ��� ��쿡�� �ٽ� Ž���ϸ� �ȴ�.

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
int maps[101][101];
int visit[101][101];
queue<pair<pii, pii>> q;
int ans = IMAX;

void BFS() {
	
	while (!q.empty()) {
		pii now = q.front().first;
		int nowMir = q.front().second.first;
		int nowDir = q.front().second.second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = now.first + mv1[i];
			int ny = now.second + mv2[i];
			int nextMir = nowMir;
			
			if (nowDir != i) {
				nextMir++;
			}

			if (nx < 0 || nx >= h || ny < 0 || ny >= w)	continue;
			if (maps[nx][ny] == -1)	continue;

			if (maps[nx][ny] == 1) {
				visit[nx][ny] = min(visit[nx][ny], nextMir);
				ans = visit[nx][ny];
				continue;
			}

			if (visit[nx][ny] >= nextMir) {
				visit[nx][ny] = nextMir;
				q.push({ {nx, ny}, {nextMir, i} });
			}
		}
	}

}

int main() {
	FIO;

	cin >> w >> h;

	fill(&visit[0][0], &visit[100][101], IMAX);

	for (int i = 0; i < h; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < w; j++)
		{
			if (str[j] == 'C') {
				if (q.empty()) {
					for (int k = 0; k < 4; k++)
					{
						q.push({ { i, j }, {0, k} });
					}
				}
				else {
					maps[i][j] = 1;
				}
			}
			else if (str[j] == '*') {
				maps[i][j] = -1;
			}
		}
	}

	BFS();

	cout << ans;
}