/*
A. Cut Ribbon
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Polycarpus has a ribbon, its length is n. He wants to cut the ribbon in a way that fulfils the following two conditions:

After the cutting each ribbon piece should have length a, b or c.
After the cutting the number of ribbon pieces should be maximum.
Help Polycarpus and find the number of ribbon pieces after the required cutting.

Input
The first line contains four space-separated integers n, a, b and c (1 ≤ n, a, b, c ≤ 4000) — the length of the original ribbon and the acceptable lengths of the ribbon pieces after the cutting, correspondingly. The numbers a, b and c can coincide.

Output
Print a single number — the maximum possible number of ribbon pieces. It is guaranteed that at least one correct ribbon cutting exists.

문제 설명:
N의 길이 리본이 주어지고, A, B, C의 필요한 리본 길이가 주어집니다.
N을 A, B, C 외의 다른 길이가 남지 않게 하면서 가장 많은 리본 조각의 개수를 구해야 합니다.
ex) 7 5 5 2 에서 2만큼 3 번 자르면 2,2,2,1 4개의 조각이 남지만, 1의 길이는 필요없는 조각이므로
2,5 만 남게 자르는게 최대값입니다.

풀이:
재귀 호출을 이용하여 풀이했습니다.
N부터 주어진 길이만큼 잘라보면서 카운트를 늘려갑니다.
now 가 0보다 작아지면 안되므로 걸러줍니다.

dp[now]에 now 길이일 때 카운트 값을 넣어주는데, 이미 값이 들어가 있고
그 값이 현재 카운트보다 높거나 같다면, 더 탐색할 필요가 없습니다.(걸러줍니다.)

위 작업을 하지 않으면 중복으로 탐색하게 되어 시간이 매우 오래 걸립니다.

*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<string.h>
#include<queue>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>

int N;
int P[3];
int dp[4001];

void recul(int now, int cnt) {
	
	if (now < 0)	return;

	if (dp[now] >= cnt)	return;
	dp[now] = cnt;

	if (now == 0)	return;

	for (int i = 0; i < 3; i++)
	{
		recul(now - P[i], cnt + 1);
	}
}

int main(void) {
	FIO;

	cin >> N;
	
	memset(dp, -1, sizeof(dp));
	
	for (int i = 0; i < 3; i++)
	{
		cin >> P[i];
	}
	recul(N, 0);

	cout << dp[0];
}