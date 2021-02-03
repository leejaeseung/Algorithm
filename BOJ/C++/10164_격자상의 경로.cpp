/*
����
���� ���� N�̰� ���� ���� M�� ������ �� ĭ�� 1���� N��M������ ��ȣ�� ù ����� �����Ͽ� ���ʷ� �ο��Ǿ� �ִ�. ������ � ĭ�� �� ǥ�ð� �Ǿ� �ִ�. (��, 1�� ĭ�� N �� M�� ĭ�� �� ǥ�ð� �Ǿ� ���� �ʴ�. ����, �� ǥ�ð� �Ǿ� �ִ� ĭ�� �ִ� �� ���̴�. ��, �� ǥ�ð� �� ĭ�� ���� ���� �ִ�.)

���� ���� 3�̰� ���� ���� 5�� ���ڿ��� �� ĭ�� ��ȣ�� 1���� ���ʴ�� �ο��� ���� �Ʒ��� �ִ�. �� ���ڿ����� 8�� ĭ�� �� ǥ�ð� �Ǿ� �ִ�.



������ 1�� ĭ���� ����� � �κ��� �Ʒ��� �� ������ �����ϸ鼭 N��M�� ĭ���� ������ �Ѵ�.

���� 1: �κ��� �� ���� �����ʿ� ������ ĭ �Ǵ� �Ʒ��� ������ ĭ���θ� �̵��� �� �ִ�. (��, �밢�� �������δ� �̵��� �� ����.)
���� 2: ���ڿ� �۷� ǥ�õ� ĭ�� �ִ� ��쿣 �κ��� �� ĭ�� �ݵ�� �������� �Ѵ�.
������ ���� �Ͱ� ���� ���ڰ� �־��� ��, �κ��� �̵��� �� �ִ� ���� �ٸ� ����� �� ���� ���� �Ʒ��� �ִ�.

1 �� 2 �� 3 �� 8 �� 9 �� 10 �� 15
1 �� 2 �� 3 �� 8 �� 13 �� 14 �� 15
���ڿ� ���� ������ �־��� �� �κ��� �տ��� ������ �� ������ �����ϸ鼭 �̵��� �� �ִ� ���� �ٸ� ��ΰ� �� �� ���� �Ǵ��� ã�� ���α׷��� �ۼ��϶�.

�Է�
�Է��� ù° �ٿ��� ������ ���� ���� ���� ���� ��Ÿ���� �� ���� N�� M(1 �� N, M �� 15), �׸��� �۷� ǥ�õ� ĭ�� ��ȣ�� ��Ÿ���� ���� K(K=0 �Ǵ� 1 < K < N��M)�� ���ʷ� �־�����, �� ���� �������� ���еȴ�. K�� ���� 0�� ��쵵 �ִµ�, �̴� �۷� ǥ�õ� ĭ�� ������ �ǹ��Ѵ�. N�� M�� ���ÿ� 1�� ���� ����.

���
�־��� ������ ������ �̿��Ͽ� ������ ������ �����ϴ� ���� �ٸ� ����� ���� ����Ͽ� ����ؾ� �Ѵ�.

Ǯ��:
�޸������̼��� ����� dfs�� Ǯ��, O ���� ������ ���� �ϹǷ� �� ���� ���� dfs�Ѵ�.
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
int mv1[4] = { 0, 1, -1, 0 };
int mv2[4] = { 1, 0, 0, -1 };

int n, m, k;
int dp[16][16];

int dfs(int x, int y, int ex, int ey) {

	int& ret = dp[x][y];

	if (x == ex && y == ey)	return 1;
	if (ret != -1)	return ret;
	ret = 0;

	for (int i = 0; i < 2; i++)
	{
		int nx = x + mv1[i];
		int ny = y + mv2[i];

		if (nx > ex || ny > ey)	continue;

		ret += dfs(nx, ny, ex, ey);
	}

	return ret;
}

int main() {

	cin >> n >> m >> k;

	fill(&dp[0][0], &dp[15][16], -1);

	if (k == 0) {
		cout << dfs(1, 1, n, m);
	}
	else {
		int tx = (k - 1) / m + 1;
		int ty = (k - 1) % m + 1;

		cout << dfs(1, 1, tx, ty) * dfs(tx, ty, n, m);
	}
}