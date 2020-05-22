/*
����
�������̳�� ũ�Ⱑ 1��1�� ���簢���� ���� �� �̾ ���� �����̸�, ������ ���� ������ �����ؾ� �Ѵ�.

���簢���� ���� ��ġ�� �� �ȴ�.
������ ��� ����Ǿ� �־�� �Ѵ�.
���簢���� ������ ����Ǿ� �־�� �Ѵ�. ��, �������� �������� �´�� ������ �� �ȴ�.
���簢�� 4���� �̾� ���� �������̳�� ��Ʈ�ι̳��� �ϸ�, ������ ���� 5������ �ִ�.



�Ƹ��̴� ũ�Ⱑ N��M�� ���� ���� ��Ʈ�ι̳� �ϳ��� �������� �Ѵ�. ���̴� 1��1 ũ���� ĭ���� �������� ������, ������ ĭ���� ������ �ϳ� ���� �ִ�.

��Ʈ�ι̳� �ϳ��� ������ ���Ƽ� ��Ʈ�ι̳밡 ���� ĭ�� ���� �ִ� ������ ���� �ִ�� �ϴ� ���α׷��� �ۼ��Ͻÿ�.

��Ʈ�ι̳�� �ݵ�� �� ���簢���� ��Ȯ�� �ϳ��� ĭ�� �����ϵ��� ���ƾ� �ϸ�, ȸ���̳� ��Ī�� ���ѵ� �ȴ�.

�Է�
ù° �ٿ� ������ ���� ũ�� N�� ���� ũ�� M�� �־�����. (4 �� N, M �� 500)

��° �ٺ��� N���� �ٿ� ���̿� ���� �ִ� ���� �־�����. i��° ���� j��° ���� ���������� i��° ĭ, ���ʿ������� j��° ĭ�� ���� �ִ� ���̴�. �Է����� �־����� ���� 1,000�� ���� �ʴ� �ڿ����̴�.

���
ù° �ٿ� ��Ʈ�ι̳밡 ���� ĭ�� ���� ������ ���� �ִ��� ����Ѵ�.

Ǯ��:
DFS�� Ȱ���� ���Ʈ ���� ���������ϴ�.

�� �� x,y���� 4ĭ���� dfs�� ��� ��θ� Ž���մϴ�.
�׷��� ��,��,��,�� ����� ������ ��� ��θ� �� �� �����Ƿ� �ִ밪�� �ϴ� �����ϰ�,
dfs�� ���� �� ���� ��,��,��,�� ����� ������ Ȯ���� �ָ� �˴ϴ�.
(��,��,��,�� ����� ���� �ʰ� ���δ� ���� �׵θ��� �� ĭ�� �÷��־� ������ �ذ� �����մϴ�.����)
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
#define pic pair<int, char>
#define ll long long
#define vi vector<int>
#define vl vector<long long>
#define vii vector<pii>
#define IMAX 2000000001
#define LMAX 100000000000000
int mv1[4] = { 0, 0, 1, -1 };
int mv2[4] = { 1, -1, 0, 0 };

int n, m;
int maps[503][503];
bool visit[503][503];
int maxV = 0;

void dfs(int x, int y, int cnt, int sum) {
	visit[x][y] = true;
	if (cnt == 4) {
		maxV = max(maxV, sum);
	}
	else {
		for (int i = 0; i < 4; i++)
		{
			int nx = x + mv1[i];
			int ny = y + mv2[i];

			if (nx <= 0 || ny <= 0 || nx > n || ny > m)	continue;
			if (!visit[nx][ny]) {
				dfs(nx, ny, cnt + 1, sum + maps[nx][ny]);
			}
		}
	}
	visit[x][y] = false;
}

int getMax(int x, int y) {
	//��,��,��,�� ��� Ȯ��
	int sum1 = maps[x][y] + maps[x + 1][y] + maps[x - 1][y] + maps[x][y + 1];
	int sum2 = maps[x][y] + maps[x + 1][y] + maps[x - 1][y] + maps[x][y - 1];
	int sum3 = maps[x][y] + maps[x + 1][y] + maps[x][y - 1] + maps[x][y + 1];
	int sum4 = maps[x][y] + maps[x - 1][y] + maps[x][y - 1] + maps[x][y + 1];

	return max(max(max(sum1, sum2), sum3), sum4);
}

int main(void) {
	FIO;

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> maps[i][j];
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			dfs(i, j, 1, maps[i][j]);
			maxV = max(maxV, getMax(i, j));
		}
	}
	cout << maxV;
}