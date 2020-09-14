/*
문제
N개의 수로 이루어진 1차원 배열이 있다. 이 배열을 M개 이하의 구간으로 나누어서 구간의 점수의 최댓값을 최소로 하려고 한다. 구간은 다음과 같은 조건을 만족해야 한다.

하나의 구간은 하나 이상의 연속된 수들로 이루어져 있다.
배열의 각 수는 모두 하나의 구간에 포함되어 있어야 한다.
구간의 점수란 구간에 속한 수의 최댓값과 최솟값의 차이이다.

예를 들어, 배열이 [1, 5, 4, 6, 2, 1, 3, 7] 이고, M = 3인 경우가 있다.

이때, [1, 5], [4, 6, 2], [1, 3, 7]로 구간을 나누면 각 구간의 점수는 4, 4, 6점이 된다. 이때, 최댓값은 6점이다.

만약, [1, 5, 4], [6, 2, 1], [3, 7]로 구간을 나누었다면, 각 구간의 점수는 4, 5, 4점이 되고, 이때 최댓값은 5점이 된다.

두 경우 중에서 최댓값이 최소인 것은 5점인 것이고, 5점보다 최댓값을 작게 만드는 방법은 없다.

배열과 M이 주어졌을 때, 구간의 점수의 최댓값의 최솟값을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 배열의 크기 N과 M이 주어진다. (1 ≤ N ≤ 5,000, 1 ≤ M ≤ N)

둘째 줄에 배열에 들어있는 수가 순서대로 주어진다. 배열에 들어있는 수는 1보다 크거나 같고, 10,000보다 작거나 같은 자연수이다.

출력
첫째 줄에 구간의 점수의 최댓값의 최솟값을 출력한다.

풀이:
파라매트릭 서치 문제이다.
모든 구간 (s,e) 에 대해 구간 값들을 구해 놓고, 0 ~ 10000 을 이분 탐색으로 최소값을 찾았다.
mid 값보다 구간 값이 작게 구간들을 나눴을 때 구간의 개수가 m 보다 커지면 false를 반환하는 parametric 함수로 풀이했다.
*/
/*#include<iostream>
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

int n, m;
int arr[5001];

bool parametric(int v) {

	int group = 1;
	int mx = 0;
	int mn = IMAX;
	
	for (int i = 1; i <= n; i++)
	{
		mx = max(mx, arr[i]);
		mn = min(mn, arr[i]);

		if (mx - mn > v) {
			group++;
			mx = arr[i];
			mn = arr[i];
		}
	}

	if (group > m)
		return false;
	return true;
}

int main(void) {
	FIO;

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	int s = 0;
	int e = 10000;
	int ans = 0;

	while (s < e) {
		int mid = (s + e) / 2;

		if (parametric(mid)) {
			ans = mid;
			e = mid;
		}
		else {
			s = mid + 1;
		}
	}
	cout << ans;
}*/