/*
����
2���� ���� n���� ���� �־����� ��, �� ���� �� ���� ����� �� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �ڿ��� n(2 �� n �� 100,000)�� �־�����. ���� n���� �ٿ��� ���ʷ� �� ���� x, y��ǥ�� �־�����. ������ ��ǥ�� ������ 10,000�� ���� �ʴ� �����̴�. ���� ���� ���� �� �־��� ���� �ִ�.

���
ù° �ٿ� ���� ����� �� ���� �Ÿ��� ������ ����Ѵ�.
Ǯ��:
���� �� ���..�� �����ؾߴ�
https://www.crocus.co.kr/807
�����߽��ϴ�.
*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<vector>
#include<set>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>
#define ll long long

int N;
vector<pii> vt;
set<pii> s;
double ans;

double getD(pii p1, pii p2) {
	return pow((double)(p1.first - p2.first), 2) + pow((double)(p1.second - p2.second), 2);
}

int main(void) {
	FIO;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int x, y;
		cin >> x >> y;

		vt.push_back(make_pair(x, y));
	}

	sort(vt.begin(), vt.end());

	s.insert({ vt[0].second, vt[0].first});
	s.insert({ vt[1].second, vt[1].first});

	ans = getD(vt[0], vt[1]);

	int l = 0;

	for (int i = 2; i < N; i++)
	{
		while (i > l) {
			double dx = vt[i].first - vt[l].first;

			if (pow(dx, 2) <= ans)	break;

			s.erase({vt[l].second, vt[l].first});
			l++;
		}

		double limit = sqrt(ans);

		auto lo = s.lower_bound({ vt[i].second - limit, -10000000 });
		auto up = s.upper_bound({ vt[i].second + limit, 10000000 });

		for (auto it = lo; it != up; it++)
		{
			ans = min(ans, getD({it->second, it->first}, vt[i]));
		}

		s.insert({ vt[i].second, vt[i].first });
	}
	cout << (int)ans;
}