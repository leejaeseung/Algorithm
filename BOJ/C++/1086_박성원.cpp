/*
����
�ڼ����� �� ������ Ǯ�� ���ߴ�.

���� �ٸ� ������ �̷���� ������ �ִ�. �� ������ ������ ��ġ�� ū ���� �ϳ��� ���� �� �ִ�. ���� ���, {5221,40,1,58,9}�� 5221401589�� ���� �� �ִ�. ��ģ���� ���� K�� ������ �������� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

������, �ڼ����� �� ������ Ǯ�� ���ߴ�.

���� �ڼ����� �׳� �����ϰ� ���� �ϳ��� �����̶�� ����Ϸ��� �Ѵ�. �� �������� ������ ���� �� ���� ���� �ְ�, �ڼ����� �쿬�� ������ ������ ���� ���� �ִ�.

�ڼ����� �쿬�� ������ ���� Ȯ���� �м��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ������ ���� ���� N�� �־�����. N�� 15���� �۰ų� ���� �ڿ����̴�. ��° �ٺ��� N���� �ٿ��� ���տ� ���Ե� ���� �־�����. �� ���� ���̴� ���� 50�� �ڿ����̴�. ������ �ٿ��� K�� �־�����. K�� 100���� �۰ų� ���� �ڿ����̴�.

���
ù° �ٿ� ������ ���м� ���·� ����Ѵ�. p/q�÷� ����ϸ�, p�� ����, q�� �и��̴�. ������ 0�� ���� 0/1��, 1�� ���� 1/1�� ����Ѵ�.

Ǯ��:
https://suuntree.tistory.com/124
�����߽��ϴ�.������
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
int mv1[4] = { 0, 0, 1, -1 };
int mv2[4] = { 1, -1, 0, 0 };

int n, k;
vector<string> vt;
int remain[16];
int ten[51];
ll dp[1 << 15][101];

ll gcd(ll x, ll y) {
	if (y == 0) return x;
	return gcd(y, x % y);
}

int main(void) {

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		vt.push_back(s);
		
	}

	cin >> k;

	ten[0] = 1;
	for (int i = 1; i <= 50; i++)
	{
		ten[i] = ten[i - 1] * 10;
		ten[i] %= k;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < vt[i].size(); j++)
		{
			remain[i] = (remain[i] * 10 + (int)(vt[i][j] - '0')) % k;
		}
	}

	dp[0][0] = 1;
	for (int i = 0; i < (1 << n); i++)
	{
		for (int j = 0; j < k; j++)
		{
			for (int l = 0; l < n; l++)
			{
				if ((i & (1 << l)) == 0) {
					int next = j * ten[vt[l].size()];
					next %= k;
					next += remain[l];
					next %= k;

					dp[i | (1 << l)][next] += dp[i][j];
				}
			}
			
		}
	}

	ll all = 1;
	for (int i = 1; i <= n; i++)
	{
		all *= i;
	}

	ll ans = dp[(1 << n) - 1][0];
	ll g = gcd(ans, all);

	all /= g;
	ans /= g;

	cout << ans << "/" << all;
}