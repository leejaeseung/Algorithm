/*
A. Chain Reaction
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
There are n beacons located at distinct positions on a number line. The i-th beacon has position a i and power level b i. When the i-th beacon is activated, it destroys all beacons to its left (direction of decreasing coordinates) within distance b i inclusive. The beacon itself is not destroyed however. Saitama will activate the beacons one at a time from right to left. If a beacon is destroyed, it cannot be activated.

Saitama wants Genos to add a beacon strictly to the right of all the existing beacons, with any position and any power level, such that the least possible number of beacons are destroyed. Note that Genos's placement of the beacon means it will be the first beacon activated. Help Genos by finding the minimum number of beacons that could be destroyed.

Input
The first line of input contains a single integer n (1 ≤ n ≤ 100 000) — the initial number of beacons.

The i-th of next n lines contains two integers a i and b i (0 ≤ a i ≤ 1 000 000, 1 ≤ b i ≤ 1 000 000) — the position and power level of the i-th beacon respectively. No two beacons will have the same position, so a i ≠ a j if i ≠ j.

Output
Print a single integer — the minimum number of beacons that could be destroyed if exactly one beacon is added.

문제 설명:
부수는 비콘을 최소로 하는 문제입니다.
처음엔 한번만 오른쪽부터 연속된 비콘을 부술 수 있습니다.

a 포지션의 비콘을 작동시키면 왼쪽으로 b만큼의 비콘이 부숴집니다.
비콘은 오른쪽에서 왼쪽으로 작동시킵니다.

풀이:
1부터 N까지 i번째 비콘을 부수면 몇 개의 비콘이 부숴지는지 계산해 놓습니다. -> 이분 탐색, dp 이용
destroy[i] = i번째 비콘을 부술 때 부숴지는 왼쪽의 전체 비콘 수

이분 탐색으로 다음 범위에서 가장 가까운 position - 1 이 i 번째 비콘을 부쉈을 때 부숴지지 않는 마지막 비콘입니다.
destroy[현재] = 범위 내의 비콘 개수 + destroy[부숴지지 않은 마지막 비콘]

다시 1부터 N까지 탐색하면서 (처음엔 부순 비콘 개수) + destroy[now] 의 최솟값을 구합니다.

*/

#include<iostream>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<string>
#include<vector>
#include<queue>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
#define pii pair<int, int>

int N;
int destroy[1000001];	//destroy[i] = i position의 비콘이 파괴하는 비콘 수?
vector<pii> PL;

int lowerBound(int s, int e, ll v) {
	while (s < e) {
		int mid = (s + e) / 2;
		if (PL[mid].first >= v)
			e = mid;
		else
			s = mid + 1;
	}
	return s;
}



int main(void) {
	FIO;

	cin >> N;

	PL.push_back(make_pair(0, 0));
	for (int i = 1; i <= N; i++)
	{
		int a, b;
		cin >> a >> b;
		PL.push_back(make_pair(a, b));
	}

	sort(PL.begin(), PL.end());

	for (size_t i = 1; i <= N; i++)
	{
		int nextPos = lowerBound(1, N, PL[i].first - PL[i].second) - 1;

		destroy[i] = i - nextPos - 1 + destroy[nextPos];
		//i번째를 activate하면 몇 개가 부숴지는지
	}

	int ans = 10000000;
	
	for (int i = 1; i <= N; i++)
	{
		ans = min(ans, destroy[i] + N - i);
		
	}

	cout << ans;
}