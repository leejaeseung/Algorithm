/*
����
�ø����� ������ ���ǰ� �ֱ⿡ ���������δ� ������ ������ ������ �ʴ´�. �׷���, ���� ������� �ڽ��� ������ �󸶳� �� �ϴ����� ������ ���� ������ ����������δ� ������ ������ ���ϰ� �ִ�. �� ���� ���� ���� ��, ��, ���޴� ���� �־�����, ���� ���� ��Ģ�� ���� ��� ���� �� ���ߴ��� �����Ѵ�.

�ݸ޴� ���� �� ���� ����
�ݸ޴� ���� ������, ���޴� ���� �� ���� ����
��, ���޴� ���� ��� ������, ���޴� ���� �� ���� ����
�� ������ 1���� N ������ ������ ǥ���ȴ�. �� ������ ����� (�ڽź��� �� ���� ���� ��) + 1�� ���ǵȴ�. ���� �� ���� ��, ��, ���޴� ���� ��� ���ٸ� �� ������ ����� ����. ���� ���, 1�� ������ �ݸ޴� 1��, ���޴� 1���� �����, 2�� ������ 3�� ������ ��� ���޴� 1���� �������, 4�� ������ �޴��� ���� ���Ͽ��ٸ�, 1�� ������ 1��, 2�� ������ 3�� ������ ���� 2��, 4�� ������ 4���� �ȴ�. �� ��� 3���� ����.

�� ������ ��, ��, ���޴� ������ �Է¹޾Ƽ�, ��� ������ �� ���� �ߴ��� �˷��ִ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
�Է��� ù ���� ������ �� N(1 �� N �� 1,000)�� ����� �˰� ���� ���� K(1 �� K �� N)�� ��ĭ�� ���̿� �ΰ� �־�����. �� ������ 1���� N ������ ������ ǥ���ȴ�. ���� N���� �� �ٿ��� ���ʴ�� �� ������ ��Ÿ���� ������ �� ������ ���� ��, ��, ���޴��� ���� ��ĭ�� ���̿� �ΰ� �־�����. ��ü �޴� ���� ������ 1,000,000 �����̴�.

���
����� �� �� ���̸�, �Է¹��� ���� K�� ����� �ϳ��� ������ ����Ѵ�. ����� �ݵ�� �������� ���ǵ� ����� ����� �Ѵ�.

Ǯ��:
�ݸ޴�, ���޴�, ���޴� ������ �������� �����ϰ�, 
�޴��� ���� ���� ��� same ī��Ʈ�� �ø���,
�޴��� �ٸ� ��� ���� ����� same + 1 �ذ��� k�� ã�´�.
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

int n, k;
vector<pair<pii, pii>> vt;

int main(void) {
	FIO;

	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		vt.push_back({ {-b, -c}, {-d, a} });
	}

	sort(vt.begin(), vt.end());

	int g = -1, s = -1, b = -1;
	int rank = 0;
	int same = 0;

	for (int i = 0; i < vt.size(); i++)
	{
		int nowG = -vt[i].first.first;
		int nowS = -vt[i].first.second;
		int nowB = -vt[i].second.first;

		if (g != nowG || s != nowS || b != nowB) {
			g = nowG; s = nowS; b = nowB;
			rank += same + 1;
			same = 0;
		}
		else
			same++;

		if (vt[i].second.second == k) {
			cout << rank;
			break;
		}
	}

}