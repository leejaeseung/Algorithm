/*
문제
정수로 이루어진 크기가 같은 배열 A, B, C, D가 있다.

A[a], B[b], C[c], D[d]의 합이 0인 (a, b, c, d) 쌍의 개수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 배열의 크기 n (1 ≤ n ≤ 4000)이 주어진다. 다음 n개 줄에는 A, B, C, D에 포함되는 정수가 공백으로 구분되어져서 주어진다. 배열에 들어있는 정수의 절댓값은 최대 228이다.

출력
합이 0이 되는 쌍의 개수를 출력한다.

풀이:
재귀 호출을 이용한 브루트포스로 해결하려하면 4000 * 4000 * 4000 * 4000 이므로 시간초과가 납니다.
따라서, A와 B를 합쳐 4000 * 4000 배열, C와 D를 합쳐 4000 * 4000 배열 두 개를 가지고 수행해야 합니다.

두 배열 모두 오름차순으로 정렬한 뒤(N logN) 한 배열을 기준으로 잡고 다른 배열 값에 대해 이분 탐색으로 0이 되는 값을 찾으면
아슬아슬하게 시간이 통과됩니다.

즉, -99 를 0으로 만들 수 있는 값은 99인데 이 값을 찾기 위해 -99의 부호를 바꾸고, -1 을 해준 뒤 lower_bound로 98보다 큰 값이 나오기 바로 전
위치를 얻어왔습니다. 그리고 99가 여러 개일 수 있기 때문에 99의 마지막 위치도 lower_bound로 가져온 뒤, 해당 범위만큼을 카운트해주면 됩니다.
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

int n;
int a[4001];
int b[4001];
int c[4001];
int d[4001];
ll arr1[16000002];
ll arr2[16000002];

int lower_bound(int s, int e, ll v) {
	while (s < e) {
		int mid = (s + e) / 2;

		if(arr2[mid] > v){
			e = mid;
		}
		else {
			s = mid + 1;
		}
	}

	return s;
}

int main(void) {
	FIO;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	}

	int idx = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr1[idx] = a[i] + b[j];
			arr2[idx++] = c[i] + d[j];
		}
	}

	sort(arr1, arr1 + n * n);
	sort(arr2, arr2 + n * n);

	ll cnt = 0;

	for (int i = 0; i < n * n; i++)
	{
		int idx_s = lower_bound(0, n * n - 1, -(arr1[i]) - 1);	//찾을 값의 시작 위치
		int idx_e = lower_bound(0, n * n - 1, -(arr1[i]));	//찾을 값의 마지막 위치

		if (arr2[idx_s] == -arr1[i]) {
			if (idx_e == n * n - 1)		
				idx_e++;
			cnt += (idx_e - idx_s);
		}
	}

	cout << cnt;

}