/*
����
�������� ���� ����̴� �������� �б�� ����ߴ�.

����̰� �� ���������� ������ �� N�� �ִ�. �� ������ ���� Mi�� ���� Vi�� ������ �ִ�. ����̴� ������ K�� ������ �ְ�, �� ���濡 ���� �� �ִ� �ִ� ���Դ� Ci�̴�. ���濡�� �ִ� �� ���� ������ ���� �� �ִ�.

����̰� ��ĥ �� �ִ� ������ �ִ� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� N�� K�� �־�����. (1 �� N, K �� 300,000)

���� N�� �ٿ��� �� ������ ���� Mi�� Vi�� �־�����. (0 �� Mi, Vi �� 1,000,000)

���� K�� �ٿ��� ���濡 ���� �� �ִ� �ִ� ���� Ci�� �־�����. (1 �� Ci �� 100,000,000)

��� ���ڴ� ���� �����̴�.

���
ù° �ٿ� ����̰� ��ĥ �� �ִ� ���� ������ ���� �ִ��� ����Ѵ�.

Ǯ��:
���԰� ���� ������� ������ ä�������ϴ�.

���� ������� �ش� ���濡 �� �� �ִ� ��� ������ �켱���� ť�� �־��, �켱���� ť�� �� ����
���� ������ ���� ������ �ְ� �Ǳ� ������ �ش� ������ pop�� �ݴϴ�.
���� ������� �ñ� ������ ���� ���濡 �� �� �־��ٸ� �̹� ���濡�� �� �� �ֽ��ϴ�.
*/
#include<iostream>
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
int mv1[4] = { 0, 1, 0, -1 };
int mv2[4] = { 1, 0, -1, 0 };

int n, k;
priority_queue<ll> pq;
vector<pair<ll, ll>> jew;
vector<ll> backpack;

int main(void) {
	FIO;

	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		ll m, v;
		cin >> m >> v;

		jew.push_back(make_pair(m, v));
	}

	for (int i = 0; i < k; i++)
	{
		int c;
		cin >> c;

		backpack.push_back(c);
	}

	sort(jew.begin(), jew.end());
	sort(backpack.begin(), backpack.end());

	ll sum = 0;
	int j = 0;

	for (int i = 0; i < backpack.size(); i++)
	{
		ll weight = backpack[i];

		for (; j < n; j++)
		{
			if (weight < jew[j].first)
				break;
			
			pq.push(jew[j].second);
		}

		if (!pq.empty()) {
			sum += pq.top();
			pq.pop();
		}
	}

	cout << sum;
}