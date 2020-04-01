/*
B. Taxi
time limit per test3 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
After the lessons n groups of schoolchildren went outside and decided to visit Polycarpus to celebrate his birthday. We know that the i-th group consists of si friends (1 ≤ si ≤ 4), and they want to go to Polycarpus together. They decided to get there by taxi. Each car can carry at most four passengers. What minimum number of cars will the children need if all members of each group should ride in the same taxi (but one taxi can take more than one group)?

Input
The first line contains integer n (1 ≤ n ≤ 105) — the number of groups of schoolchildren. The second line contains a sequence of integers s1, s2, ..., sn (1 ≤ si ≤ 4). The integers are separated by a space, si is the number of children in the i-th group.

Output
Print the single number — the minimum number of taxis necessary to drive all children to Polycarpus.

문제 설명:
n 개의 그룹의 사람 수가 주어집니다.
한 택시엔 최대 4명이 탈 수 있고, 여러 그룹이 타도 됩니다.
단, 그룹은 쪼개지지 않게 타야 됩니다.

풀이:
처음엔 사람의 총 합을 4로 나누는 식으로 했는데 다음과 같은 반례가 있었습니다.
8
2 3 2 3 2 3 2 3

답은 6대입니다. 
3명인 그룹은 쪼개질 수 없기 때문에 3명의 그룹에만 4대의 택시가 필요하게 됩니다.
따라서 그리디하게 4명인 그룹부터 1명인 그룹까지 택시 수를 세어주며 풀이합니다.
3명인 그룹은 1명은 무조건 태우고, 2명인 그룹은 2명 + 2명 합치거나, 2명 + 1명 + 1명으로 합치는 경우가 있습니다.
*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<vector>
#include<stack>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>

int N;
int groupCnt[5];

int main(void) {
	FIO;

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		int n;
		cin >> n;

		groupCnt[n]++;
	}

	int ans = groupCnt[4];
	
	ans += groupCnt[3];
	groupCnt[1] -= groupCnt[3];
	if (groupCnt[1] < 0)	groupCnt[1] = 0;
	
	ans += groupCnt[2] / 2;
	groupCnt[2] %= 2;

	ans += groupCnt[2];
	groupCnt[1] -= groupCnt[2] * 2;
	if (groupCnt[1] < 0)	groupCnt[1] = 0;
	
	if (groupCnt[1] % 4 == 0)
		ans += groupCnt[1] / 4;
	else
		ans += groupCnt[1] / 4 + 1;

	cout << ans;
}