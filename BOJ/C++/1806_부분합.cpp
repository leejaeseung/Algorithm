/*
문제
10,000 이하의 자연수로 이루어진 길이 N짜리 수열이 주어진다. 이 수열에서 연속된 수들의 부분합 중에 그 합이 S 이상이 되는 것 중, 가장 짧은 것의 길이를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N (10 ≤ N < 100,000)과 S (0 < S ≤ 100,000,000)가 주어진다. 둘째 줄에는 수열이 주어진다. 수열의 각 원소는 공백으로 구분되어져 있으며, 10,000이하의 자연수이다.

출력
첫째 줄에 구하고자 하는 최소의 길이를 출력한다. 만일 그러한 합을 만드는 것이 불가능하다면 0을 출력하면 된다.

풀이:
각 원소의 prefix Sum을 구해놓고, 시작, 끝 포인터를 한칸씩 옮겨가며 해당 구간의 부분 합이 S 보다 클 때마다 값을 갱신합니다.
시작 포인터가 끝 포인터보다 커지지 않게 주의합니다.
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
#define pii pair<int, int>

int N, S;
int arr[100001];
long long sum[100001];
int ans = 100001;

int main(void) {
	FIO;

	cin >> N >> S;

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
		sum[i] = sum[i - 1] + arr[i];
	}
	int s = 1;
	int e = 1;

	while (s <= N) {
		long long nowSum = sum[e] - sum[s - 1];
		if (nowSum >= S) {
			ans = min(ans, e - s + 1);
		}
		if (e != N) {
			if (s == e) {
				e++;
				continue;
			}
			if (nowSum >= S) {
				s++;
			}
			else {
				e++;
			}
		}
		else {
			s++;
		}
	}
	if (ans == 100001)
		cout << "0";
	else
		cout << ans;
}