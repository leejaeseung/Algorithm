/*
����
70�� ������ �Ҿƹ����� ���� ���� �� �ݾ��� �Դ´�. �ճ� �����̴� ���� �Ҿƹ������� ���� N�� ��� ���� ������ �־���.

ù° ���� ������ ������ �� �ϳ��� ������. �� ����, �� ���� ������ �ɰ��� �� ������ �԰�, �ٸ� ������ �ٽ� ���� �ִ´�.

���� ������ ������ ������ ���� �ϳ� ������. (���� �� ���� ��ü �� ���� �ְ�, �ɰ� �� ���� �� ���� �ִ�) �� �����̶�� �� ���� �԰�, �ƴ϶�� ���� �ɰ��� �� ������ �԰�, �ٸ� ������ �ٽ� ���� �ִ´�.

������ �ճ࿡�� �� ������ ���� ������ W��, �� ������ ���� ������ H ������. �ճ�� �Ҿƹ������� ���� ���ڸ� ���̿� ����� ���´�. �� 2N���� ������ ���̰� 2N�� ���ڿ��� ��������� �ȴ�. �̶�, ������ ���� �ٸ� ���ڿ��� ������ �� �� ���ϱ�?

�Է�
�Է��� �ִ� 1000���� �׽�Ʈ ���̽��� �̷���� �ִ�. �� �׽�Ʈ ���̽��� �� ���̸�, ���� ����ִ� ���� ���� N �� 30 �� �־�����.

�Է��� ������ �ٿ��� 0�� �ϳ� �־�����.

���
�� �׽�Ʈ ���̽��� ���ؼ� ������ ���ڿ��� ������ ����Ѵ�.

Ǯ��:
dfs + �޸������̼� ��������.
�˾��� ��� �ݰ��� ���� ���(one�� 0���� ��) ������ ����� ���� ��� S�� ���� ������ �Ѱ��� ������ �ٿ������� �Ѵ�.
�Ѱ�¥�� ����, �ݰ��� �־�� dfs�� �����ϴµ�, �ݰ�¥���� ���� ��쵵 �߰��Ѵ�.

�Ѱ�¥���� �ݰ�¥���� ������ ���� ��Ȳ�̸� �޸������̼��� �̿��� �ɷ��� �� �ִ�.
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

ll dp[31][31];

ll dfs(int one, int half) {

	if (one == 0)	return 1;

	ll &ret = dp[one][half];
	if (ret > -1)	return ret;
	//�Ѱ� ¥���� �ݰ� ¥���� ������ ���� ��

	ret = dfs(one - 1, half + 1);
	//�Ѱ��� ����, �ݰ��� ����

	if (half > 0)
		ret += dfs(one, half - 1);
		//�ݰ��� ��

	return ret;
}

int main(void) {
	FIO;

	while (true) {
		int n;
		cin >> n;

		if (n == 0)	break;

		fill(&dp[0][0], &dp[30][31], -1);

		cout << dfs(n, 0) << "\n";
	}
}