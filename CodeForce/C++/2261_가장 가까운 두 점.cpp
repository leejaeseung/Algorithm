/*
문제
2차원 평면상에 n개의 점이 주어졌을 때, 이 점들 중 가장 가까운 두 점을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 자연수 n(2 ≤ n ≤ 100,000)이 주어진다. 다음 n개의 줄에는 차례로 각 점의 x, y좌표가 주어진다. 각각의 좌표는 절댓값이 10,000을 넘지 않는 정수이다. 같은 점이 여러 번 주어질 수도 있다.

출력
첫째 줄에 가장 가까운 두 점의 거리의 제곱을 출력한다.
풀이:
ㄹㅇ 넘 어렵..더 공부해야댐
https://www.crocus.co.kr/807
참고했습니다.
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