/*
����
2���� ���� N(3 �� N �� 10,000)���� ������ �̷���� �ٰ����� �ִ�. �� �ٰ����� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� N�� �־�����. ���� N���� �ٿ��� �ٰ����� �̷�� ������� N���� ���� x, y��ǥ�� �־�����. ��ǥ���� ������ 100,000�� ���� �ʴ� �����̴�.

���
ù° �ٿ� ������ ����Ѵ�. ������ ����� ������ �Ҽ��� �Ʒ� ��° �ڸ����� �ݿø��Ͽ� ù° �ڸ����� ����Ѵ�.

Ǯ��:
CCW�� �̿��� ������, �� ���� ��� �ٰ����� �̷�� ������� �� ���� ���� �ٲ㰡�� 
�ﰢ���� ���̸� ���� �����ݴϴ�.
�̶�, CCW�� �̿��� ���̴� ����纯���� �����̹Ƿ� / 2 �� ���ִµ� ���� �� Ȧ���� ��
0.5 �� �����־�� �մϴ�.
*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<string.h>
#include<vector>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>

double getS(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
	ll S = ((x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1));
	if (S % 2 == 0)	return (double)(S / 2);
	return (double)(S / 2) + 0.5;
}

int main(void) {
	FIO;

	int N;
	cin >> N;

	vector < pll> vt;

	for (int i = 0; i < N; i++)
	{
		ll x, y;
		cin >> x >> y;
		vt.push_back(make_pair(x, y));
	}
	
	pll s = vt[0];

	double ans = 0;

	for (int i = 1; i < N - 1; i++)
	{
			pll m = vt[i];
			pll e = vt[i + 1];
			ans += getS(s.first, s.second, m.first, m.second, e.first, e.second);
	}

	printf("%.1lf", abs(ans));
}