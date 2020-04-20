/*
C. Hard problem
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Vasiliy is fond of solving different tasks. Today he found one he wasn't able to solve himself, so he asks you to help.

Vasiliy is given n strings consisting of lowercase English letters. He wants them to be sorted in lexicographical order (as in the dictionary), but he is not allowed to swap any of them. The only operation he is allowed to do is to reverse any of them (first character becomes last, second becomes one before last and so on).

To reverse the i-th string Vasiliy has to spent c i units of energy. He is interested in the minimum amount of energy he has to spent in order to have strings sorted in lexicographical order.

String A is lexicographically smaller than string B if it is shorter than B (|A| < |B|) and is its prefix, or if none of them is a prefix of the other and at the first position where they differ character in A is smaller than the character in B.

For the purpose of this problem, two equal strings nearby do not break the condition of sequence being sorted lexicographically.

Input
The first line of the input contains a single integer n (2 ≤ n ≤ 100 000) — the number of strings.

The second line contains n integers c i (0 ≤ c i ≤ 109), the i-th of them is equal to the amount of energy Vasiliy has to spent in order to reverse the i-th string.

Then follow n lines, each containing a string consisting of lowercase English letters. The total length of these strings doesn't exceed 100 000.

Output
If it is impossible to reverse some of the strings such that they will be located in lexicographical order, print  - 1. Otherwise, print the minimum total amount of energy Vasiliy has to spent.
문제 설명:
N개의 문자열이 주어지고, 각 문자열마다 문자열을 반전시키는 비용도 주어집니다.

문자열을 반전시키거나 반전시키지 않고, 문자열을 사전식으로 정렬해야 할 때, 반전 비용의 최소값을 구하는 문제입니다.
중간에 prefix 관련 설명은 
aa
aab 
위 순서대로 정렬해야 한다는 뜻입니다. 만약
z
aa
위 예제는 -1을 출력해야 합니다. --> compare 함수에서 자동으로 판단해 줍니다.
풀이:
원본 문자열과 반전 문자열 두 개를 준비합니다.(문자열 길이의 총 합이 100000이하이므로 가능합니다.)

dp[x][0 or 1] = x번째 문자열에서 이전 문자열을 0 = 반전x , 1 = 반전o

이전 문자열과, 현재 문자열을 반전시키거나 그대로 두면서 재귀 호출합니다.
반전시킬 경우에만 energy값을 더해줍니다.
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
#define MAX 1000000000000000000LL

int N;
ll energy[100001];
string str[100001][2];
ll dp[100002][2];

ll recul(int now,int order) {

	if (now == N + 1) {
		return 0;
	}

	ll& ret = dp[now][order];
	//dp 메모이제이션
	if (ret != -1)	return ret;
	ret = 0;
	ll o = MAX;
	ll r = MAX;
	
	if (str[now][0].compare(str[now - 1][order]) >= 0) {
		//원본 문자열과 비교
		o = recul(now + 1, 0);
	}
			
	if (str[now][1].compare(str[now - 1][order]) >= 0) {
		//반전해서 비교 - energy값이 필요
		r = recul(now + 1, 1) + energy[now];
	}

	return ret = min(o, r);
	//둘 중 작은 값을 return
}

int main(void) {
	FIO;

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> energy[i];
	}
	for (int i = 1; i <= N; i++)
	{
		cin >> str[i][0];
		str[i][1] = str[i][0];
		reverse(str[i][1].begin(), str[i][1].end());
	}
	memset(dp, -1, sizeof(dp));

	ll ans = recul(1, 0);
	
	if (ans == MAX)
		cout << "-1";
	else
		cout << ans;
}