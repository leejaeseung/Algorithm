/*
����
ũ���������� �����Ͽ� ��Ÿ �Ҿƹ����� �������� ���� ��� K���� ������ ���ַ��� �Ѵ�. ��Ÿ �Ҿƹ����� ������ �����ϱ� ���ؼ� ������ ���������� "������"�� ã�ư���. �����Ϳ��� N���� ���� ���ڰ� �� �ٷ� �����Ǿ� �ְ�, �� ���� ���ڿ��� �� �� �̻��� ������ ��� �ִ�. �׸��� �����Ϳ����� �ֹ��� ���Ǽ��� ���� �� ���ڿ� ��ȣ�� �ٿ� ���Ұ�, �ֹ��� "H�� ���ں��� T�� ���ڱ��� �� �ּ���."��� �� �� �ִ�. (H �� T)

��Ÿ �Ҿƹ����� �� �� �ֹ��� ������, �ֹ��� ���ڿ� �ִ� �������� ��� ������ ������ K���� ��Ȯ�� ���� ����ŭ ������ �ְ�, ���� ������ ������ �Ѵ�.

�� �� �ֹ��� �� �ִٸ�, ������ �ֹ� ����� �� �����ΰ�?
���� �� �ֹ��� �� �ִٸ�, �ֹ��� ��ġ�� �ʰ� �ִ� �� �� �ֹ��� �� �ִ°�? (�ֹ��� ��ģ�ٴ� ���� � �� �ֹ��� ���� ��ȣ�� ���� ���ڰ� ���ԵǴ� ���� ���Ѵ�.)
�Է�
ù ��° �ٿ��� �׽�Ʈ ���̽��� ���� T�� �־�����. ( T �� 60 )

�� �׽�Ʈ ���̽��� ù ��° �ٿ��� ���� ������ ���� N�� ����� �� K�� �־�����.(1 �� N, K �� 100000)

�� ��° �ٿ��� 1�� ���� ���ں��� N�� ���� ���ڱ��� �� ���� ���ڿ� ��� �ִ� ������ ���� Di�� �־�����. ( 1 �� i �� N, 1 �� Di �� 100000 )

���
1���� ���� ��� 2���� ���� ���� �� �ٿ� �ϳ��� ��ĭ���� ������ ����Ѵ�. 1�� ���� �ſ� Ŭ �� �����Ƿ� 20091101�� ���� �������� ����Ѵ�.

Ǯ��:
� ���� i ~ j �� ���Ͽ� i ~ j �� k �� ������ ���������� ���θ� ���ϱ� ����
sum[j] MOD k == sum[i - 1] MOD k �� �̿��Ѵ�.
��, sum �迭�� ��� mod k ���� ��, ���� ���� 2�� �̻� �ִٸ�, �� ������ 
�ߺ��� ������� �ʰ� 2���� �̴� ����� ���� ���ϰ�, ��� ���ϸ� �ȴ�.(1��)

2���� dp�� �ذ� �����ϴ�.
� ���� x ������ sum ����(mod k ��) �ֱٿ� ���Ҵٸ�(�ش� ���� = i - 1)
sum[j] MOD k == sum[i - 1] MOD k �� ���� i - 1 ���� ���� ��, i ~ x ���� �ٽ� ��ĥ �� �ִ�.
���� dp[x - 1] �� dp[���� ����] + 1 �� �ִ� ���� dp[x] �� �����Ѵ�.

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
#define MOD 20091101
int mv1[4] = { 0, 0, 1, -1 };
int mv2[4] = { 1, -1, 0, 0 };
int mv_all1[8] = { 0, 1, 0, -1, -1, -1, 1, 1 };
int mv_all2[8] = { 1, 0, -1, 0 , -1, 1, -1, 1 };

int t, n, k;
int sum[100001];
ll counts[100001];
int dp[100001];
int prv[100001];

int main(void) {
	FIO;

	cin >> t;

	while (t--) {
		cin >> n >> k;

		ll ans = 0;

		for (int i = 0; i < 100001; i++)
		{
			prv[i] = -1;
			counts[i] = 0;
			dp[i] = 0;
			sum[i] = 0;
		}

		for (int i = 1; i <= n; i++)
		{
			int v;
			cin >> v;
			sum[i] = (sum[i - 1] +  v) % k;
			counts[sum[i]]++;
		}

		counts[0]++;

		for (int i = 0; i < k; i++)
		{
			if (counts[i] >= 2)
				ans = ((ans % MOD) + (counts[i] * (counts[i] - 1) / 2) % MOD) % MOD;
		}

		for (int i = 0; i <= n; i++)
		{
			//i �� 0���� �����ϴ� ���� = �� ó������ �ڸ��� ��츦 �����ϱ� ����
			if (i == 0)
				dp[i] = 0;
			else
				dp[i] = dp[i - 1];

			if (prv[sum[i]] != -1)
				dp[i] = max(dp[i], dp[prv[sum[i]]] + 1);

			prv[sum[i]] = i;
		}

		cout << ans << " " << dp[n] << "\n";
	}
}