/*
문제
세계적인 도둑 상덕이는 보석점을 털기로 결심했다.

상덕이가 털 보석점에는 보석이 총 N개 있다. 각 보석은 무게 Mi와 가격 Vi를 가지고 있다. 상덕이는 가방을 K개 가지고 있고, 각 가방에 담을 수 있는 최대 무게는 Ci이다. 가방에는 최대 한 개의 보석만 넣을 수 있다.

상덕이가 훔칠 수 있는 보석의 최대 가격을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N과 K가 주어진다. (1 ≤ N, K ≤ 300,000)

다음 N개 줄에는 각 보석의 정보 Mi와 Vi가 주어진다. (0 ≤ Mi, Vi ≤ 1,000,000)

다음 K개 줄에는 가방에 담을 수 있는 최대 무게 Ci가 주어진다. (1 ≤ Ci ≤ 100,000,000)

모든 숫자는 양의 정수이다.

출력
첫째 줄에 상덕이가 훔칠 수 있는 보석 가격의 합의 최댓값을 출력한다.

풀이:
무게가 작은 가방부터 보석을 채워나갑니다.

작은 가방부터 해당 가방에 들어갈 수 있는 모든 보석을 우선순위 큐에 넣어가면, 우선순위 큐의 맨 위엔
가장 가격이 높은 보석이 있게 되기 때문에 해당 보석을 pop해 줍니다.
작은 가방부터 봤기 때문에 이전 가방에 들어갈 수 있었다면 이번 가방에도 들어갈 수 있습니다.
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