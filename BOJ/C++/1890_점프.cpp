/*
����
N��N �����ǿ� ���� ������ �ִ�. �� ������ ��ǥ�� ���� ���� �� ĭ���� ���� ������ �Ʒ� ĭ���� ��Ģ�� �°� ������ �ؼ� ���� ���̴�.

�� ĭ�� �����ִ� ���� ���� ĭ���� �� �� �ִ� �Ÿ��� �ǹ��Ѵ�. �ݵ�� �������̳� �Ʒ������θ� �̵��ؾ� �Ѵ�. 0�� �� �̻� ������ ���� �������̸�, �׻� ���� ĭ�� �����ִ� ����ŭ �������̳� �Ʒ��� ���� �Ѵ�. �� �� ������ �� ��, ������ �ٲٸ� �� �ȴ�. ��, �� ĭ���� ���������� ������ �ϰų�, �Ʒ��� ������ �ϴ� �� ��츸 �����Ѵ�.

���� ���� �� ĭ���� ���� ������ �Ʒ� ĭ���� ��Ģ�� �°� �̵��� �� �ִ� ����� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ���� ���� ũ�� N (4 �� N �� 100)�� �־�����. �� ���� N�� �ٿ��� �� ĭ�� ������ �ִ� ���� N���� �־�����. ĭ�� �����ִ� ���� 0���� ũ�ų� ����, 9���� �۰ų� ���� �����̸�, ���� ������ �Ʒ� ĭ���� �׻� 0�� �־�����.

���
���� ���� �� ĭ���� ���� ������ �Ʒ� ĭ���� ������ ��Ģ�� �°� �� �� �ִ� ����� ������ ����Ѵ�. ����� ������ 263-1���� �۰ų� ����.

Ǯ��:
dp�� ������ dfs �����̴�.
*/
#include<iostream>
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
int mv1[4] = { 0, 1, 0, -1 };
int mv2[4] = { 1, 0, -1, 0 };
int mv_all1[8] = { 0, 1, 0, -1, -1, -1, 1, 1 };
int mv_all2[8] = { 1, 0, -1, 0 , -1, 1, -1, 1 };

int n;
int maps[101][101];
ll dp[101][101];

ll dfs(int x, int y) {

	ll& ret = dp[x][y];

	if (ret != -1)	return ret;

	ret = 0;
	if (x == n - 1 && y == n - 1)	return ret = 1;

	for (int i = 0; i < 2; i++)
	{
		int nx = x + mv1[i] * maps[x][y];
		int ny = y + mv2[i] * maps[x][y];

		if (nx < 0 || ny < 0 || nx >= n || ny >= n)	continue;

		ret += dfs(nx, ny);
	}

	return ret;
}

int main(void) {
	FIO;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> maps[i][j];
			dp[i][j] = -1;
		}
	}

	dfs(0, 0);

	cout << dp[0][0];
}