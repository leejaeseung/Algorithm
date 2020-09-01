/*
����
1�г��� ��� �� ���� �Ŷ� ������ ���� ö������ �ϰ�, ���� ������ �� ����öȸ�ϰ� ���� ������ �� F �޴� ������ 1�г��� ���´� �¿�� ���� �ͼ� �ڽ��� �ൿ�� ��ȸ�ϰ� �ֽ��ϴ�. ���� ���� ä���� �� ������ �ʹ� ���� �����Դϴ�. ���� �ʼ� ������ ä����� ���� ���� N �� �� K �� �̻��� �����ؾ� �մϴ�. �׷��� �� ������ �ش� ������ ���������� �̸� �����߾�߸� ������ �� ������, �� �б⸶�� ��� ������ �����Ǵ� ���� �ƴϱ� ������ ������ �����������ϴ�. ��� �ؾ� �ּ� �б⿡ ������ �� �� �������?

�� ������ ������ ������ M �б� ���� ������ ������ ����� �־��� ��, �¿찡 �ּ� �� �б⸦ �ٳ�� ������ �� �ִ��� ����ϴ� ���α׷��� �ۼ��ϼ���. �� ���� �������� �ʴ� �б�� ������ ������ �ϸ�, �ٴ� �б� ���� ���Ե��� �ʽ��ϴ�.

�Է�
�Է��� ù �ٿ��� �׽�Ʈ ���̽��� �� C (C <= 50) �� �־����ϴ�. �� �׽�Ʈ ���̽��� ù �ٿ��� ���� ������ �� N (1 <= N <= 12), ���� �� ������ �� K (0 <= K <= N), �б��� �� M (1 <= M <= 10) �� �¿찡 �� �б⿡ �ִ�� ���� �� �ִ� ������ �� L (1 <= L <= 10)�� �־����ϴ�. �� ���񿡴� 0���� N-1 ������ ��ȣ�� �Ű��� �ֽ��ϴ�.

�� �� N �ٿ� 0�� ������� ������� �� ������ ������ �־����ϴ�. �� �ٿ��� �ش� ������ ���� ������ �� Ri (0 <= Ri <= N-1) �� ó�� �־�����, �� �� Ri ���� ������ ���� ������ ��ȣ�� �־����ϴ�.

�� �� M �ٿ��� �̹� �б���� ������� �� �б��� ������ �־����ϴ�. �� �ٿ��� �ش� �б⿡ �����Ǵ� ������ ���� Ci (1 <= Ci <= 10) �� �־�����, �� �� Ci ���� ������ �����Ǵ� ������ ��ȣ���� �־����ϴ�.

���
�� �׽�Ʈ ���̽����� �� �ٿ� �¿찡 �ٳ�� �� �ּ� �б� ���� ����մϴ�. M �б� ���� ������ �� ���� ��� IMPOSSIBLE�� ����մϴ�.

Ǯ��:
��Ʈ����ũ�� �̿��� ���Ʈ ���� + �޸������̼� �����̴�.

�� �б⸶�� ��� ������ ���տ� ���� ������ �غ���.
memo[�б�][������ bitmask] �� �޸������̼��� �����Ѵ�.

�������� ����, �ƹ��͵� �������� �ʾ��� ���� ���� �����Ѵ�.
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
#define MOD 100007
int mv1[4] = { 0, 0, 1, -1 };
int mv2[4] = { 1, -1, 0, 0 };
int mv_all1[8] = { 0, 1, 0, -1, -1, -1, 1, 1 };
int mv_all2[8] = { 1, 0, -1, 0 , -1, 1, -1, 1 };

int cs[12];
int semester[10];
int memo[10][1 << 12];
int t, n, k, m, l;

int brute(int nowSem, int nowBit, int nowCnt) {

	if (nowCnt >= k)	return 0;

	if (nowSem >= m)	return IMAX;

	int& ret = memo[nowSem][nowBit];

	if (ret != -1)	return ret;

	ret = IMAX;

	for (int i = semester[nowSem]; i > 0; i = ((i - 1) & semester[nowSem]))
	{
		int cnt = 0;
		int cls_cnt = 0;
		int bit = 0;

		for (int j = 1; j <= i; j = (j << 1))
		{	
			if ((j & i) != 0 && (j & nowBit) == 0 && (cs[cls_cnt] & nowBit) == cs[cls_cnt]) {
				cnt++;
				bit |= j;
			}

			cls_cnt++;
		}

		if (cnt > l || cnt == 0)	continue;

		ret = min(ret, brute(nowSem + 1, nowBit | bit, nowCnt + cnt) + 1);
	}

	ret = min(ret, brute(nowSem + 1, nowBit, nowCnt));

	return ret;
}

int main(void) {
	FIO;

	cin >> t;

	while (t--) {
		cin >> n >> k >> m >> l;

		memset(cs, 0, sizeof(cs));
		memset(semester, 0, sizeof(semester));
		fill(&memo[0][0], &memo[9][1 << 12], -1);

		for (int i = 0; i < n; i++)
		{
			int r;
			cin >> r;

			for (int j = 0; j < r; j++)
			{
				int prev;
				cin >> prev;

				cs[i] = cs[i] | (1 << prev);
			}
		}

		for (int i = 0; i < m; i++)
		{
			int c;
			cin >> c;

			for (int j = 0; j < c; j++)
			{
				int open;
				cin >> open;

				semester[i] = semester[i] | (1 << open);
			}
		}

		int ans = brute(0, 0, 0);

		if (ans == IMAX)
			cout << "IMPOSSIBLE\n";
		else
			cout << ans << "\n";
	}
}