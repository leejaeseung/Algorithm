/*
A. Boredom
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Alex doesn't like boredom. That's why whenever he gets bored, he comes up with games. One long winter evening he came up with a game and decided to play it.

Given a sequence a consisting of n integers. The player can make several steps. In a single step he can choose an element of the sequence (let's denote it ak) and delete it, at that all elements equal to ak + 1 and ak - 1 also must be deleted from the sequence. That step brings ak points to the player.

Alex is a perfectionist, so he decided to get as many points as possible. Help him.

Input
The first line contains integer n (1 ≤ n ≤ 105) that shows how many numbers are in Alex's sequence.

The second line contains n integers a1, a2, ..., an (1 ≤ ai ≤ 105).

Output
Print a single integer — the maximum number of points that Alex can earn.

풀이:
dp[i][0 or 1] -> 0 일 때 = i 를 선택하지 않을 경우의 최댓값, 1 일 때 = i 를 선택할 경우의 최댓값으로 정의합니다.

문제에 사용된 모든 숫자를 저장하고, 정렬합니다. 그리고 각 숫자마다 몇 개인지 카운트를 세줍니다.

1. i번째를 선택하지 않을 때(dp[i][0]) = i - 1 번째를 선택할 때 와 i - 1 번째를 선택하지 않을 때 중 큰 값
2. i번째를 선택할 때(dp[i][1]) = 
2-1. i번째 숫자와 i - 1 번째 숫자의 차이가 1 보다 클 때 = i - 1 번째를 선택하고, i 번째 숫자의 개수만큼 더함.
2-2. i번째 숫자와 i - 1 번째 숫자의 차이가 1 보다 작을 때 = i - 1 번째를 선택하지 않고, i 번째 숫자의 개수만큼 더함.
*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<string.h>
#include<vector>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>

int N;
long long cnt[100002];
long long dp[100002][2];
vector<long long> vt;

int main(void) {
	FIO;

	cin >> N;

	for (int i = 1; i <= N ; i++)
	{
		int v;
		cin >> v;
		if (cnt[v] == 0)
			vt.push_back(v);
		cnt[v]++;
	}

	sort(vt.begin(), vt.end());

	dp[0][1] = vt[0] * cnt[vt[0]];
	for (int i = 1; i < vt.size(); i++)
	{
		long long n = vt[i];
		long long c = cnt[n];

		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
		dp[i][1] = dp[i - 1][0] + n * c;
		long long temp = dp[i - 1][1] + n * c;
		if (abs(n - vt[i - 1]) > 1 && temp > dp[i][1])	dp[i][1] = temp;
	}
	cout << max(dp[vt.size() - 1][0], dp[vt.size() - 1][1]);
}