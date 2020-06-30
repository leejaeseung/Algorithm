/*
문제
히스토그램에 대해서 알고 있는가? 히스토그램은 아래와 같은 막대그래프를 말한다.



각 칸의 간격은 일정하고, 높이는 어떤 정수로 주어진다. 위 그림의 경우 높이가 각각 2 1 4 5 1 3 3이다.

이러한 히스토그램의 내부에 가장 넓이가 큰 직사각형을 그리려고 한다. 아래 그림의 빗금 친 부분이 그 예이다. 이 직사각형의 밑변은 항상 히스토그램의 아랫변에 평행하게 그려져야 한다.



주어진 히스토그램에 대해, 가장 큰 직사각형의 넓이를 구하는 프로그램을 작성하시오.

입력
첫 행에는 N (1 ≤ N ≤ 100,000) 이 주어진다. N은 히스토그램의 가로 칸의 수이다. 다음 N 행에 걸쳐 각 칸의 높이가 왼쪽에서부터 차례대로 주어진다. 각 칸의 높이는 1,000,000,000보다 작거나 같은 자연수 또는 0이다.

출력
첫째 줄에 가장 큰 직사각형의 넓이를 출력한다. 이 값은 20억을 넘지 않는다.

풀이:
분할- 정복으로 풀이했습니다.

왼쪽, 오른쪽 구간으로 나누고, 합쳐가며 최댓값을 갱신하는데, 어떤 구간 s~e 에서 최댓값은 다음을 고려합니다.

1. 왼쪽에서의 최댓값
2. 오른쪽에서의 최댓값
3. 왼쪽, 오른쪽을 합친 현재 구간에서 중간에서부터 시작해서 양 끝까지 가로로 칠해보았을 때의 최댓값

*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
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

ll n;
ll arr[100001];

ll getMax(ll s, ll e) {
	if (s == e) {
		return arr[s];
	}

	ll mid = (s + e) / 2;

	ll ret = max(getMax(s, mid), getMax(mid + 1, e));

	ll l = mid, r = mid + 1;
	ll h = min(arr[l], arr[r]);

	ret = max(ret, h * (r - l + 1));

	while (l > s || r < e) {
		if (r < e && (l == s || arr[r + 1] > arr[l - 1])) {
			h = min(h, arr[++r]);
		}
		else {
			h = min(h, arr[--l]);
		}
		ret = max(ret, h * (r - l + 1));
	}
	return ret;
}

int main(void) {
	FIO;

		cin >> n;

		for (int i = 1; i <= n; i++)
		{
			cin >> arr[i];
		}

		cout << getMax(1, n);
}