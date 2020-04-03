/*
문제
수열 S가 어떤 수 Sk를 기준으로 S1 < S2 < ... Sk-1 < Sk > Sk+1 > ... SN-1 > SN을 만족한다면, 그 수열을 바이토닉 수열이라고 한다.

예를 들어, {10, 20, 30, 25, 20}과 {10, 20, 30, 40}, {50, 40, 25, 10} 은 바이토닉 수열이지만,  {1, 2, 3, 2, 1, 2, 3, 2, 1}과 {10, 20, 30, 40, 20, 30} 은 바이토닉 수열이 아니다.

수열 A가 주어졌을 때, 그 수열의 부분 수열 중 바이토닉 수열이면서 가장 긴 수열의 길이를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 수열 A의 크기 N이 주어지고, 둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ N ≤ 1,000, 1 ≤ Ai ≤ 1,000)

출력
첫째 줄에 수열 A의 부분 수열 중에서 가장 긴 바이토닉 수열의 길이를 출력한다.

풀이:
가장 긴 부분 감소 수열을 살짝 응용하면 되는 문제였습니다.
기준이 되는 수를 0~N 번째까지 바꿔가며 왼쪽을 보고 가장 긴 부분 감소 수열, 오른쪽을 보고 가장 긴 부분 감소 수열을 구합니다.

두 수열의 합 - 1(기준 수가 중복되므로) 이 최대가 되는 경우가 정답입니다.
*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<vector>
#include<queue>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>

int N;
int arr[1001];
vector<int> left_dp;
vector<int> right_dp;

void BS(vector<int> &dp, int s, int e, int v) {
	while (s < e) {
		int mid = (s + e) / 2;

		if (dp[mid] <= v)
			e = mid;
		else
			s = mid + 1;
	}
	dp[s] = v;
}

int main(void) {
	FIO;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	int ans = 0;

	for (int center = 0; center < N; center++)
	{
		left_dp.push_back(arr[center]);
		right_dp.push_back(arr[center]);
		
		for (int i = center - 1; i >= 0 ; i--)
		{
			int now = arr[i];
			
			if (now >= left_dp.back()) {
				BS(left_dp, 0, left_dp.size() - 1, now);
			}
			else {
				left_dp.push_back(now);
			}
		}
		for (int i = center + 1; i < N; i++)
		{
			int now = arr[i];

			if (now >= right_dp.back()) {
				BS(right_dp, 0, right_dp.size() - 1, now);
			}
			else {
				right_dp.push_back(now);
			}
		}
		ans = max(ans, (int)(left_dp.size() + right_dp.size() - 1));

		left_dp.clear();
		right_dp.clear();
	}
	cout << ans;
}