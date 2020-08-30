/*
����
����̴� �޿��� ���̰� L�� ���ڿ��� �ܿ���.

�޿��� �� ����̴� �� ���ڿ��� ���̿� ������. ���̸� ���� �߿� � ���ڿ��� �� �� �̻� �����ϴ� �� ���� ������ �޾Ҵ�.

���ڿ��� �־����� ��, �� �� �̻� ������ �κ� ���ڿ� �� ���� ���̰� �� ���� ã�� ���α׷��� �ۼ��Ͻÿ�. (�κй��ڿ��� ���ļ� ������ ���� �ִ�)

�Է�
ù° �ٿ� L�� �־�����. (1 �� L �� 200,000) ���� �ٿ��� ���̰� L�̸鼭 ���ĺ� �ҹ��ڷ� �̷���� ���ڿ��� �־�����.

���
ù° �ٿ� �� �� �̻� �����ϴ� �κ� ���ڿ� �� ���̰� ���� �� ���� ���̸� ����Ѵ�. ���� �׷��� ���ڿ��� ���� ���� 0�� ����Ѵ�.

Ǯ��:
���-ī���� �̺� Ž���� �̿��� �����̴�.
https://m.blog.naver.com/PostView.nhn?blogId=kks227&logNo=220927272165&proxyReferer=https:%2F%2Fwww.google.com%2F
�� ��α׸� ������ Ǯ����.

K ������ �κ� ���ڿ��� 2�� �̻� �ִٸ� �翬�� K ������ �κ� ���ڿ��� 2�� �̻� �ִ�.
���� �̺� Ž���� ������ �� �ִ�.
(K ������ �κ� ���ڿ��� 2�� �̻� ������ -> K ���� ū �κ� ���ڿ��鿡 ���� ����)

K �� ���̿� ���� �̺� Ž���� �����ϰ�, ���ڿ� S �� ���� ���̰� K �� ��� �κ� ���ڿ��� �ؽð���
���-ī�� �˰����� ����� ���Ѵ�.

��ⷯ ���� �ÿ� ���� ������ ����� ����� �ٲ���� �Ѵ�.
������ ���� ������ �ٸ� ���ڿ��� �� �����Ƿ�(�ؽ� �浹) ��ġ�� ���ڿ��鿡 ����
���� ���� ���ڿ����� ������ Ȯ�����ָ� �ȴ�.
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
int mv1[4] = { 0, 0, 1, -1 };
int mv2[4] = { 1, -1, 0, 0 };
int mv_all1[8] = { 0, 1, 0, -1, -1, -1, 1, 1 };
int mv_all2[8] = { 1, 0, -1, 0 , -1, 1, -1, 1 };

const int MOD = 100003;
vector<int> visit[MOD];

int mod(ll n) {
	if (n >= 0)	return n % MOD;
	else
		return ((-n / MOD + 1) * MOD + n) % MOD;
	//������ ����� ��ⷯ ����
}

int main(void) {
	FIO;

	int leng, ans = 0;
	string str;
	cin >> leng >> str;

	int s = 0;
	int e = leng;

	while (s < e) {

		int m = (s + e) / 2;
		ll H = 0;
		ll mul = 1;
		bool flag = false;
		for (int i = 0; i < MOD; i++)
		{
			visit[i].clear();
		}

		for (int i = 0; i <= leng - m; i++)
		{
			if (i == 0) {

				for (int j = m - 1; j >= 0; j--)
				{
					H = mod(H + (str[j] - 'a') * mul);
					if (j > 0)
						mul = mod(mul * 2);
				}
			}
			else {
				H = mod(2 * (H - (str[i - 1] - 'a') * mul) + (str[i + m - 1] - 'a'));
			}

			if (!visit[H].empty()) {

			for (int start = 0; start < visit[H].size(); start++)
				{
				bool match = true;
					for (int j = 0; j < m; j++)
					{
						if (str[visit[H][start] + j] != str[i + j]) {
							match = false;
							break;
						}
					}
					if (match) {
						flag = true;
						break;
					}
				}
			}
			if (flag)
				break;
			else
				visit[H].push_back(i);
			//�浹 �߻�x , �ؽð��� ���� ��ġ ����
		}

		if (flag) {
			ans = m;
			s = m + 1;
		}
		else {
			e = m;
		}
	}

	cout << ans;
}