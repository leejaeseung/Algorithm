/*
����
ȿ���̴� ģ����� ī���뿡 �湮�ߴ�. ȿ���̿� �Բ��� �׷��� �� N������ �̷���� �ִ�.

ī���뿡�� �� ������ M���� �������� ���������ִ� �������� ����ȴ�. ������ ���۵� ��, �� ������Դ� Ĩ�� 1���� �־�����.

������ �� K���� ����� �̷���� �ְ�, �Ʒ��� ���� ����ȴ�.

�� �÷��̾�� M���� ���� �� �ϳ��� Ĩ�� ���´�.
������ M���� ���� �߿� �ϳ��� �������� ����.
������ �� ������ Ĩ�� ���� ����� ���ӿ��� ���ܵȴ�.
K���� ���忡�� ���ӿ��� ���ܵ��� ������ ������ �¸��� ���̴�.

ȿ���̿� ģ������ ��� �� ����� ������ �¸��� Ȯ���� �ִ�� �Ϸ��� �Ѵ�.

N, M, K�� �־����� ��, ȿ���̿� ģ������ ������ ������ ������� �������� ��, ��� �� ����� ������ �¸��� Ȯ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� N, M, K�� �־�����. (1 �� N �� 1012, 1 �� M, K �� 50)

���
ù° �ٿ� ��� �� ����� ������ �¸��� Ȯ���� ����Ѵ�. ������� ����/��� ������ 10-3���� ����Ѵ�.

Ǯ��:
�׸��� + dp �޸������̼� �����̴�.
�������� ������ ����̶� �� ���帶�� ���� ����� �ִ����� Ĩ�� ������ ���̴�.
���� ���� ���� Ĩ��, M �� ���� Ĩ�� ��ġ�� �����ȴ�.

1. Ĩ < M  --> Ĩ�� �� ������ ���� �� �ּ��̴�.
2. Ĩ % M == 0  --> Ĩ�� (Ĩ / M) ���� ��� M �ڸ��� ���� �� �ּ��̴�.
3. Ĩ % M != 0  --> Ĩ�� (Ĩ / M) ���� ��� M �ڸ��� ���Ƶ� ��������ŭ�� Ĩ�� ���´�. ���� Ĩ���� �ϳ��� ���� �ٸ� �ڸ��� ���´�.

1 ���� Ȯ���� ������ Ĩ�� ���� Ȯ�� = Ĩ�� ���� / M + Ĩ�� ���� ���� Ȯ�� = (M - Ĩ�� ����) / M
2 ���� Ȯ���� ��� �ڸ��� Ĩ�� ������ �����Ƿ� 1�̴�.
3 ���� Ȯ���� ������ (Ĩ / M) ���� Ĩ�� ���� ��� = (M - ������) / M + (Ĩ / M + 1) ���� Ĩ�� ���� ��� = ������ / M

���� ���� ���� ������ Ĩ�� ������ ���� ��� �Լ��� �����ϸ� �ȴ�.
������ �� ���帶�� �ִ� 2���� �бⰡ �Ͼ�Ƿ� 2^50 �� �ð� �ʰ��� ����.

1, 2, 3 ���� ������ ������ (Ĩ % M) ���� �� �� �ִ�.
���� �� ���帶�� (Ĩ % M) �� ���¸� �޸������̼� �� �־� �ð��� ���� �� �־���.
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
#define MOD 100003
int mv1[4] = { 0, 0, 1, -1 };
int mv2[4] = { 1, -1, 0, 0 };
int mv_all1[8] = { 0, 1, 0, -1, -1, -1, 1, 1 };
int mv_all2[8] = { 1, 0, -1, 0 , -1, 1, -1, 1 };

ll n, m, k;
double dm;
double dp[51][51];

double recul(ll chip, ll round) {

	if (round >= k) {
		if (chip > 0)	return 1;
		else return 0;
	}

	if (chip == 0)	return 0;

	ll remain = chip % m;

	double& ret = dp[remain][round];
	if (ret != -1)	return ret;
	ret = 0;

	if (m > chip) {
		ret += (recul(chip - 1, round + 1) * ((double)chip / dm));
		ret += (recul(chip, round + 1) * (dm - (double)chip) / dm);
	}
	else {
		if (chip % m == 0) {
			ret += recul(chip - (chip / m), round + 1);
		}
		else {
			ret += (recul(chip - (chip / m) , round + 1) * ((dm - (double)remain) / dm));
			ret += (recul(chip - (chip / m) - 1, round + 1) * ((double)remain / dm));
		}
	}

	return ret;
}

int main(void) {
	FIO;

	cin >> n >> m >> k;
	dm = (double)m;

	fill(&dp[0][0], &dp[50][51], -1);

	cout.precision(10);
	cout << recul(n, 0);
}