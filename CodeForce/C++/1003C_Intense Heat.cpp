/*
C. Intense Heat
time limit per test4 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
The heat during the last few days has been really intense. Scientists from all over the Berland study how the temperatures and weather change, and they claim that this summer is abnormally hot. But any scientific claim sounds a lot more reasonable if there are some numbers involved, so they have decided to actually calculate some value which would represent how high the temperatures are.

Mathematicians of Berland State University came up with a special heat intensity value. This value is calculated as follows:

Suppose we want to analyze the segment of n consecutive days. We have measured the temperatures during these n days; the temperature during i-th day equals ai.

We denote the average temperature of a segment of some consecutive days as the arithmetic mean of the temperature measures during this segment of days. So, if we want to analyze the average temperature from day x to day y, we calculate it as ∑i=xyaiy−x+1 (note that division is performed without any rounding). The heat intensity value is the maximum of average temperatures over all segments of not less than k consecutive days. For example, if analyzing the measures [3,4,1,2] and k=3, we are interested in segments [3,4,1], [4,1,2] and [3,4,1,2] (we want to find the maximum value of average temperature over these segments).

You have been hired by Berland State University to write a program that would compute the heat intensity value of a given period of days. Are you up to this task?

Input
The first line contains two integers n and k (1≤k≤n≤5000) — the number of days in the given period, and the minimum number of days in a segment we consider when calculating heat intensity value, respectively.

The second line contains n integers a1, a2, ..., an (1≤ai≤5000) — the temperature measures during given n days.

Output
Print one real number — the heat intensity value, i. e., the maximum of average temperatures over all segments of not less than k consecutive days.

Your answer will be considered correct if the following condition holds: |res−res0|<10−6, where res is your answer, and res0 is the answer given by the jury's solution.

문제 설명:
주어진 배열에서 최소 길이가 K인 연속된 부분 배열 중 average temperature의 최대값을 구하는 문제입니다.

풀이:
정직하게 2중 반복문으로 구간을 늘려가며 비교해줍니다.
*/

#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include<stack>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>

int N, K;
int sum[5001];

double measure(int x, int y) {
	return (double)((double)(sum[y] - sum[x - 1]) / (double)(y - x + 1));
}

int main(void) {
	FIO;

	cin >> N >> K;

	for (int i = 1; i <= N; i++)
	{
		int v;
		cin >> v;

		sum[i] = sum[i - 1] + v;
	}
	double ans = 0;

	for (int i = K; i <= N; i++)
	{
		for (int j = 1; j + i - 1 <= N; j++)
		{
			ans = max(measure(j, j + i - 1), ans);
		}
	}
	cout.precision(15);
	cout << ans;
}