/*
C. Number of Ways
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You've got array a[1], a[2], ..., a[n], consisting of n integers. Count the number of ways to split all the elements of the array into three contiguous parts so that the sum of elements in each part is the same.

More formally, you need to find the number of such pairs of indices i, j (2 ≤ i ≤ j ≤ n - 1), that .

Input
The first line contains integer n (1 ≤ n ≤ 5·105), showing how many numbers are in the array. The second line contains n integers a[1], a[2], ..., a[n] (|a[i]| ≤  109) — the elements of array a.

Output
Print a single integer — the number of ways to split the array into three parts with the same sum.

문제 설명:
N개의 숫자를 세 부분으로 나눴을 때 나눈 3개의 부분의 합이 모두 같을 경우의 수를 구하는 문제입니다.

풀이:
만약 세 구간이 위 조건을 만족한다면 다음과 같이 나타낼 수 있습니다.

1. 첫 번째 구간의 합 = A 라고 하면,
2. 처음부터 두 번째 구간의 끝까지의 합 = 2A
3. 처음부터 세 번째 구간의 끝까지의 합 = 3A

위에서 3번의 경우는 N개의 수에 대해 prefix sum을 구했을 때 sum[N] 으로 나타내어 집니다.
즉, sum[N]이 3의 배수일 경우에만 조건을 만족할 수 있습니다.

sum[N]이 3의 배수일 경우부턴 이제 패턴을 찾기만 하면 됩니다. (A = sum[N] / 3 으로 구할 수 있습니다.)
맨 왼쪽부터 prefix sum을 탐색하면서 A , 2A , 3A 의 순서인 경우의 수를 세어주면 됩니다.

*/
#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<vector>
#include<queue>
#include<stdio.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define pii pair<int, int>

int N;
long long sum[500001];

int main(void) {
	FIO;

	cin >> N;	

	for (int i = 1; i <= N; i++)
	{
		long long v;
		cin >> v;
		sum[i] = sum[i - 1] + v;
	}

	if (sum[N] % 3 == 0) {
		long long A = sum[N] / 3;
		long long A_cnt = 0;
		long long cnt = 0;

		for (int i = 1; i < N; i++)
		{
			if (sum[i] == A * 2)
				cnt += A_cnt;
			if (sum[i] == A)
				A_cnt++;
		}
		cout << cnt;
	}
	else
		cout << 0;
}