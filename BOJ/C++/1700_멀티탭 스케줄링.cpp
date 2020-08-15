/*
����
����翡�� ��� �ִ� �رԴ� �� ���� ��Ƽ���� �̿��ϰ� �ִ�. �رԴ� Ű����, ������̱�, �ڵ��� ������, ������ ī�޶� ������ �� ���� ���� �����ǰ�� ����ϸ鼭 ��¿ �� ���� ���� �����ǰ�� �÷��׸� ���� �ȾҴ� �ϴ� �������� �ް� �ִ�. �׷��� �رԴ� �ڽ��� ��Ȱ ������ �м��Ͽ�, �ڱⰡ ����ϰ� �ִ� �����ǰ�� �������� �˾Ƴ�����, �̸� ������� �÷��׸� ���� Ƚ���� �ּ�ȭ�ϴ� ����� ����Ͽ� ���� ������ ��Ȱȯ���� ������� �Ѵ�.

���� ��� 3 ��(������ �� �� �޸�) ��Ƽ���� �� ��, �����ǰ�� ��� ������ �Ʒ��� ���� �־����ٸ�,

Ű����
������̱�
�ڵ��� ������
������ ī�޶� ������
Ű����
������̱�
Ű����, ������̱�, �ڵ��� �������� �÷��׸� ������� ��Ƽ�ǿ� ���� ���� ������ ī�޶� ������ �÷��׸� �ȱ� ���� �ڵ��������� �÷��׸� ���� ���� ������ ���̹Ƿ� �÷��״� �� ���� ���� �ȴ�.

�Է�
ù �ٿ��� ��Ƽ�� ������ ���� N (1 �� N �� 100)�� ���� ��ǰ�� �� ���Ƚ�� K (1 �� K �� 100)�� ������ �־�����. �� ��° �ٿ��� �����ǰ�� �̸��� K ������ �ڿ����� ��� ������� �־�����. �� ���� ��� ���� ���̴� ���鹮�ڷ� ���еǾ� �ִ�.

���
�ϳ��� �÷��׸� ���� �ּ��� Ƚ���� ����Ͻÿ�.

Ǯ��:
1. �ܼ�Ʈ�� �� �� ������ ��� �ȴ´�.
2. �ܼ�Ʈ�� �� �� ���
2-1. ���Ŀ� ������ �ʴ� �ܼ�Ʈ �� �ƹ��ų� �ϳ� �̴´�.
2-2. ���� �ܼ�Ʈ �� ������ ���� �ʰ� ��Ÿ���� �ܼ�Ʈ�� �̴´�.
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

int n, k;
bool check[101];
int cnts[101];
vector<int> order;

int main(void) {
	FIO;

	cin >> n >> k;

	for (int i = 0; i < k; i++)
	{
		int o;
		cin >> o;

		cnts[o]++;
		order.push_back(o);
	}

	vector<int> use;

	int ans = 0;

	for (int i = 0; i < k; i++)
	{
		int now = order[i];
		cnts[now]--;

		if (!check[now]) {
			check[now] = true;

			if (use.size() == n) {

				int maxCnt = -1;
				int out = 0;

				for (int j = 0; j < n; j++)
				{
					int comp = use[j];

					if (cnts[comp] == 0) {
						//������ ��Ÿ���� ���� ��
						out = j;
						break;
					}

					int cnt = 0;

					for (int l = i + 1; l < k; l++)
					{
						if (comp == order[l]) {
							break;
						}
						cnt++;
					}

					if (maxCnt < cnt) {
						//���� �ʰ�(cnt�� ���� ū) ��Ÿ���� �ܼ�Ʈ�� �̴´�.
						maxCnt = cnt;
						out = j;
					}
				}

				check[use[out]] = false;
				use[out] = now;
				ans++;
			}
			else {
				use.push_back(now);
			}
		}
	}

	cout << ans;
}