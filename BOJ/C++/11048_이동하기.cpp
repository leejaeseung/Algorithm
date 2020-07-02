/*
����
�رԴ� N��M ũ���� �̷ο� �����ִ�. �̷δ� 1��1ũ���� ������ �������� �ְ�, �� �濡�� ������ ������ �ִ�. �̷��� ���� ���� �� ���� (1, 1)�̰�, ���� ������ �Ʒ� ���� (N, M)�̴�.

�رԴ� ���� (1, 1)�� �ְ�, (N, M)���� �̵��Ϸ��� �Ѵ�. �ر԰� (r, c)�� ������, (r+1, c), (r, c+1), (r+1, c+1)�� �̵��� �� �ְ�, �� ���� �湮�� ������ �濡 �������ִ� ������ ��� ������ �� �ִ�. ��, �̷� ������ ���� ���� ����.

�ر԰� (N, M)���� �̵��� ��, ������ �� �ִ� ���� ������ �ִ��� ���Ͻÿ�.

�Է�
ù° �ٿ� �̷��� ũ�� N, M�� �־�����. (1 �� N, M �� 1,000)

��° �ٺ��� N�� �ٿ��� �� M���� ���ڰ� �־�����, r��° ���� c��° ���� (r, c)�� ������ �ִ� ������ �����̴�. ������ ������ 0���� ũ�ų� ����, 100���� �۰ų� ����.

���
ù° �ٿ� �ر԰� (N, M)���� �̵��� ��, ������ �� �ִ� ���� ������ ����Ѵ�.

Ǯ��:
dp �޸������̼� �⺻ �����Դϴ�.
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
#define IMAX 2000000001
#define LMAX 1000000000000000000
#define DMAX 0xFFFFFFFFFFFFF
int mv1[3] = { 0, 1, 1 };
int mv2[3] = { 1, 0, 1 };

int n, m;
int maps[1001][1001];
int dp[1001][1001];

int dfs(int x, int y) {

	int& ret = dp[x][y];
	if (ret != -1)	return ret;
	ret = 0;

	for (int i = 0; i < 3; i++)
	{
		int next_x = x + mv1[i];
		int next_y = y + mv2[i];

		if (next_x > n || next_y > m)	continue;

		ret = max(ret, dfs(next_x, next_y));
	}

	return dp[x][y] = ret + maps[x][y];
}

int main(void) {
	FIO;

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> maps[i][j];
			dp[i][j] = -1;
		}
	}

	dfs(1, 1);

	cout << dp[1][1];
}