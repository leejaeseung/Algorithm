/*
문제
KOI 부설 과학연구소에서는 많은 종류의 산성 용액과 알칼리성 용액을 보유하고 있다. 각 용액에는 그 용액의 특성을 나타내는 하나의 정수가 주어져있다.  산성 용액의 특성값은 1부터 1,000,000,000까지의 양의 정수로 나타내고, 알칼리성 용액의 특성값은 -1부터 -1,000,000,000까지의 음의 정수로 나타낸다.

같은 양의 세 가지 용액을 혼합한 용액의 특성값은 혼합에 사용된 각 용액의 특성값의 합으로 정의한다. 이 연구소에서는 같은 양의 세 가지 용액을 혼합하여 특성값이 0에 가장 가까운 용액을 만들려고 한다.

예를 들어, 주어진 용액들의 특성값이 [-2, 6, -97, -6, 98]인 경우에는 특성값이 -97와 -2인 용액과 특성값이 98인 용액을 혼합하면 특성값이 -1인 용액을 만들 수 있고, 이 용액이 특성값이 0에 가장 가까운 용액이다. 참고로, 세 종류의 알칼리성 용액만으로나 혹은 세 종류의 산성 용액만으로 특성값이 0에 가장 가까운 혼합 용액을 만드는 경우도 존재할 수 있다.

산성 용액과 알칼리성 용액이 주어졌을 때, 이 중 같은 양의 세 개의 서로 다른 용액을 혼합하여 특성값이 0에 가장 가까운 용액을 만들어내는 세 용액을 찾는 프로그램을 작성하시오.

입력
첫째 줄에는 전체 용액의 수 N이 입력된다. N은 3 이상 5,000 이하의 정수이다. 둘째 줄에는 용액의 특성값을 나타내는 N개의 정수가 빈칸을 사이에 두고 주어진다. 이 수들은 모두 -1,000,000,000 이상 1,000,000,000 이하이다. N개의 용액들의 특성값은 모두 다르고, 산성 용액만으로나 알칼리성 용액만으로 입력이 주어지는 경우도 있을 수 있다.

출력
첫째 줄에 특성값이 0에 가장 가까운 용액을 만들어내는 세 용액의 특성값을 출력한다. 출력해야하는 세 용액은 특성값의 오름차순으로 출력한다. 특성값이 0에 가장 가까운 용액을 만들어내는 경우가 두 개 이상일 경우에는 그 중 아무것이나 하나를 출력한다.

풀이:
기본적인 아이디어는 (두 개 용액의 합 * -1) 을 정렬된 배열에서 이분 탐색을 통해 찾아
총 합의 절댓값이 0에 가까워지게 하면 됩니다.(시간복잡도 : n * n * logn)

단, 이분 탐색으로 나온 인덱스가 i라고 할 때 i - 2 ~ i + 2 중에서 먼저 사용되지 않은 용액을 걸러주고,
(두 개 용액의 합 * -1) 과 가장 가까운 값을 골라줘야 합니다.
*/
#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<vector>
#include<queue>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

int N;
vector<ll> vt;
vector<ll> ans;
bool used[5001];

int upperBound(int s, int e, ll v) {
	while (s < e) {
		int mid = (s + e) / 2;

		if (vt[mid] >= v)
			e = mid;
		else
			s = mid + 1;
	}
	return s;
}

int main(void) {
	FIO;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		ll v;
		cin >> v;
		vt.push_back(v);
	}
	ans.resize(3);

	sort(vt.begin(), vt.end());
	ll sum = 3000000000;

	for (int i = 0; i < vt.size() - 1; i++)
	{
		used[i] = true;
		for (int j = i + 1; j < vt.size(); j++)
		{
			used[j] = true;
			ll temp = vt[i] + vt[j];
			int idx = upperBound(0, vt.size() - 1, -temp);

			ll t = 3000000000;
			for (int k = 0; k < 3; k++)
			{
				int n_m = idx - k;
				int n_p = idx + k;

				if (n_m >= 0) {
					if (used[n_m])	continue;
					if (t > abs(vt[n_m] - temp * -1)) {
						t = abs(vt[n_m] - temp * -1);
						idx = n_m;
					}
				}
				if (n_p < N) {
					if (used[n_p])	continue;
					if (t > abs(vt[n_p] - temp * -1)) {
						t = abs(vt[n_p] - temp * -1);
						idx = n_p;
					}
				}
			}

			if (sum > abs(temp + vt[idx])) {
				sum = abs(temp + vt[idx]);
				ans[0] = vt[i];	ans[1] = vt[j];	ans[2] = vt[idx];
			}

			used[j] = false;
		}
		used[i] = false;
	}

	sort(ans.begin(), ans.end());
	
	for (int i = 0; i < 3; i++)
	{
		cout << ans[i] << " ";
	}
}