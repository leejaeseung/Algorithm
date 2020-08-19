/*
����
�������м�������(ICPC: International Collegiate Parcel Center)�� ������ ���л����� ������� ���� ���� ��� �̺�Ʈ�� �����ϰ� �ִ�. ���� ��� ������ ���� ������ ��ǰ 4���� �����Ǿ�� �ϸ� �̵� ��ǰ�� ���� ���� ��Ȯ�� ������ ���� ���� w �׷��̾�� �Ѵٴ� ���̴�.

�λ���б��� �ִ� ������ ���� �ո����п� �ִ� ��ȯ���� ���� ��ǰ�� �ſ� ���� �ִµ�, �� ��ǰ�� ����(��� ���� �׷�)�� ��� �ٸ���. �� �̺�Ʈ�� �ѽ������� ����Ǵ� �̺�Ʈ�̱� ������ ������ �ڽ��� ���� ��ǰ �߿��� �� ������ �����ϴ� ��ǰ 4���� �ִ��� �����ϸ� ���� �˾Ƴ��� �ʹ�. �ٽ� ���ؼ� ���� �ٸ� n(n �� 4)���� ������ �̷���� ���� A���� 4���� ���Ҹ� ������ ���� �κ����� B(|B| = 4)�� ��b��B b = w ������ �����ϴ��� �Ǵ��Ϸ��� �Ѵ�.

�־��� w�� A�� ���ؼ�, �� ������ �����ϴ� �κ����� B�� �����ϸ� YES��, �ƴϸ� NO�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
�Է��� ǥ���Է��� ����Ѵ�. �Է��� ù �ٿ��� ���� w(10 �� w �� 799,994)�� A�� ���� ���� n(4 �� n �� 5,000)�� �������� �и��Ǿ� �־�����. ���� �ٿ��� A�� ������ n���� ���� ai �� A(1 �� i �� n)�� �������� �и��Ǿ� �־�����. �� ���� ai�� 1�̻� 200,000�����̴�(1 �� ai �� 200,000).

���
����� ǥ������� ����Ѵ�. ������ ���ǿ� ���� YES�� NO�� �� �ٿ� ����Ѵ�.

Ǯ��:
5000������ 4���� ������ ����� ���� �ʹ� �����Ƿ� �ΰ� �� ���� �������ƾ� �Ѵ�.
�׷��� 5000 * 5000 = 25000000 ���� ������ �����µ�, ��� ���տ� ���� w���� �� �� ��,
���� ���� ���� 25000000 ���� ���� �ȿ� �ִ��� üũ�ϸ� �ȴ�.
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

int w, n;
vector<int> vt;
vector<pair<int, pii>> sum;
pii check[800500];

int main(void) {
	FIO;

	cin >> w >> n;

	for (int i = 0; i < n; i++)
	{
		int v;
		cin >> v;

		vt.push_back(v);
	}

	for (int i = 0; i < 800500; i++)
	{
		check[i] = make_pair(-1, -1);
	}

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			int s = vt[i] + vt[j];

			sum.push_back(make_pair(s, make_pair(i, j)));
			check[s] = make_pair(i, j);
		}
	}

	for (int i = 0; i < sum.size(); i++)
	{
		int diff = w - sum[i].first;
		int ori_f = sum[i].second.first;
		int ori_s = sum[i].second.second;
		if (diff < 0)	continue;

		int f = check[diff].first;
		int s = check[diff].second;

		if (f != -1) {
			if (ori_f != f && ori_f != s && ori_s != f && ori_s != s) {
				cout << "YES";
				exit(0);
			}
		}
	}
	cout << "NO";
}