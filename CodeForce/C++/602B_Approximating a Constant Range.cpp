/*
B. Approximating a Constant Range
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
When Xellos was doing a practice course in university, he once had to measure the intensity of an effect that slowly approached equilibrium. A good way to determine the equilibrium intensity would be choosing a sufficiently large number of consecutive data points that seems as constant as possible and taking their average. Of course, with the usual sizes of data, it's nothing challenging — but why not make a similar programming contest problem while we're at it?

You're given a sequence of n data points a 1, ..., a n. There aren't any big jumps between consecutive data points — for each 1 ≤ i < n, it's guaranteed that |a i + 1 - a i| ≤ 1.

A range [l, r] of data points is said to be almost constant if the difference between the largest and the smallest value in that range is at most 1. Formally, let M be the maximum and m the minimum value of a i for l ≤ i ≤ r; the range [l, r] is almost constant if M - m ≤ 1.

Find the length of the longest almost constant range.

Input
The first line of the input contains a single integer n (2 ≤ n ≤ 100 000) — the number of data points.

The second line contains n integers a 1, a 2, ..., a n (1 ≤ a i ≤ 100 000).

Output
Print a single number — the maximum length of an almost constant range of the given sequence.
문제 설명:
N 개의 연속된 숫자가 주어집니다.
여러 개의 부분 구간 중 구간 내의 최소 값과 최대 값의 차이가 1이하인 구간의 최대 길이를 구하는 문제입니다.

풀이:
N 개의 수를 차례대로 보면서 각 수의 인덱스를 저장합니다. 단, 같은 수가 연속으로 나올 경우 가장 앞의 인덱스를 저장합니다.
나온 수가 다시 나온다면 새로 업데이트합니다.

1 2 3 4 5
6 7 6 6 7
위 예시에서 6의 인덱스는 3, 7의 인덱스는 5가 됩니다.

매번마다 부분 구간의 시작 점을 업데이트하는데, 업데이트할 경우는 두 가지밖에 없습니다.
7 8 9
처럼 최소값(7)과 현재 숫자의 차가 2이상일 때, -- (1)
9 8 7
처럼 최대값(9)와 현재 숫자의 차가 2이상일 때 -- (2)

1번 경우는 현재 최대값인 9의 -1인 8의 최근 인덱스가 부분 구간의 시작 점이 됩니다.
2번 경우는 현재 최소값인 7의 +1인 8의 최근 인덱스가 부분 구간의 시작 점이 됩니다.

매번 부분 구간의 최댓값을 업데이트해주면 됩니다.
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
int arr[100001];
int idx[100002];

int main(void) {
	FIO;

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < 100002; i++)
	{
		idx[i] = 100001;
	}

	int ans = 0;
	int Min = 100001;
	int Max = 0;
	int s = 1;

	for (int i = 1; i <= N; i++)
	{
		int n = arr[i];
		Min = min(Min, n);
		Max = max(Max, n);

		if(arr[i - 1] != arr[i])
			idx[n] = i;

		if (abs(Min - arr[i]) >= 2) {
			s = idx[n - 1];
			Min = arr[s];
		}
		if (abs(Max - arr[i]) >= 2) {
			s = idx[n + 1];
			Max = arr[s];
		}

		ans = max(ans, i - s + 1);
	}
	cout << ans;
}