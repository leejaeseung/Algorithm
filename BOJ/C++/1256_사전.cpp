/*
����
��ȣ�� �Կ��̴� 212ȣ���� ���ڿ��� ���� �����ϰ� �ִ�. ������ ������ ��ȣ�� �Կ��̿��� Ư�� ������ �־���. Ư�� ������ Ư���� ���ڿ��� �̷�� �� ������ ����� ���̴�. ������ ���ϵǾ� �ִ� ��� ���ڿ��� N���� "a"�� M���� "z"�� �̷���� �ִ�. �׸��� �ٸ� ���ڴ� ����. �������� ���ĺ� ������� ���ϵǾ� �ִ�.

�Կ��̴� ������ �ϼ�������, ��ȣ�� ������ �ϼ����� ���ߴ�. ��ȣ�� �ڽ��� ������ ������ ���ؼ� �Կ����� ������ ���� �����ϱ�� �ߴ�. ��ȣ�� �Կ��̰� �ڸ��� ��� ���̿� ���� ������ ������ �ϱ� ������, ���ڿ� �ϳ��� ã�� �����ۿ� ����.

N�� M�� �־����� ��, �Կ����� �������� K��° ���ڿ��� �������� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� N, M, K�� ������� �־�����. N�� M�� 100���� �۰ų� ���� �ڿ����̰�, K�� 1,000,000,000���� �۰ų� ���� �ڿ����̴�.

���
ù° �ٿ� �Կ����� �������� K��° ���ڿ��� ����Ѵ�. ���� �Կ����� ������ ���ϵǾ� �ִ� ���ڿ��� ������ K���� ������ -1�� ����Ѵ�.

Ǯ��:
���װ���� �̿��Ͽ� n���� a, m���� z �� ���� �� �ִ� ��� ������ ���� dp[n][m] �� ���س��� �����մϴ�.
(��, long long ������ �ʰ��� �� �ֽ��ϴ�. ������ k ������ �˸� �ǹǷ� 1000000000�� �ʰ��� ������ 1000000001�� �ٲ��ݴϴ�.)

n = 2 , m = 2, k = 2 �� �� ������ �����ϴ�.

1 aazz
2 azaz  <- k
3 azza
4 zaaz
5 zaza
6 zzaa

���������� �տ������� ���ؾ� �ϹǷ�, �� �տ� a�� �̹� ���Ҵٰ� �����ϰ�, a�� 1��, z�� 2���� ���� ����� ���� ���մϴ�
dp[1][2] = 3
k�� �ش� ������ ���ԵǹǷ�(k <= 3) �� �տ� a�� �ٿ��ݴϴ�.
���� �������� ũ�ٸ�, k = k - 3 ���� k ���� �����ݴϴ�.(z�� �� �տ� �ٿ��ݴϴ�.)

a�� z�� ���� ������ ���� �����ִ� a�� ����, z�� ������ ���� �ٿ����� �˴ϴ�.
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
int mv1[4] = { 0, 1, 0, -1 };
int mv2[4] = { 1, 0, -1, 0 };

int n, m, k;
ll dp[101][101];		//dp[a�� ����][z�� ����] = �� ����� ��

int main(void) {
	FIO;

	cin >> n >> m >> k;
	
	dp[0][0] = 1;
	dp[0][1] = 1;
	dp[1][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		dp[i][0] = 1;
	}
	for (int i = 1; i <= m; i++)
	{
		dp[0][i] = 1;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			if (dp[i][j] >= 1000000001)
				dp[i][j] = 1000000001;
		}
	}

	if (k <= dp[n][m]) {
		ll nowN = n, nowM = m;

		string ans = "";

		while (nowN > 0 || nowM > 0) {
			//a�� z�� ����������
			ll now;
			if (nowN <= 0)
				now = 1;
			else
				now = dp[nowN - 1][nowM];

			if (nowN > 0 && now >= k) {
				ans += "a";
				nowN--;
				//a�� �ٿ����Ƿ� a�� ���� ����
			}
			else{
				ans += "z";
				k -= now;
				nowM--;
				//z�� �ٿ����Ƿ� z�� ���� ����
			}
		}

		cout << ans;
	}
	else
		cout << "-1";
}