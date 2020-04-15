/*
문제
명우는 홍준이와 함께 팰린드롬 놀이를 해보려고 한다.

먼저, 홍준이는 자연수 N개를 칠판에 적는다. 그 다음, 명우에게 질문을 총 M번 한다.

각 질문은 두 정수 S와 E(1 ≤ S ≤ E ≤ N)로 나타낼 수 있으며, S번째 수부터 E번째 까지 수가 팰린드롬을 이루는지를 물어보며, 명우는 각 질문에 대해 팰린드롬이다 또는 아니다를 말해야 한다.

예를 들어, 홍준이가 칠판에 적은 수가 1, 2, 1, 3, 1, 2, 1라고 하자.

S = 1, E = 3인 경우 1, 2, 1은 팰린드롬이다.
S = 2, E = 5인 경우 2, 1, 3, 1은 팰린드롬이 아니다.
S = 3, E = 3인 경우 1은 팰린드롬이다.
S = 5, E = 7인 경우 1, 2, 1은 팰린드롬이다.
자연수 N개와 질문 M개가 모두 주어졌을 때, 명우의 대답을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 수열의 크기 N (1 ≤ N ≤ 2,000)이 주어진다.

둘째 줄에는 홍준이가 칠판에 적은 수 N개가 순서대로 주어진다. 칠판에 적은 수는 100,000보다 작거나 같은 자연수이다.

셋째 줄에는 홍준이가 한 질문의 개수 M (1 ≤ M ≤ 1,000,000)이 주어진다.

넷째 줄부터 M개의 줄에는 홍준이가 명우에게 한 질문 S와 E가 한 줄에 하나씩 주어진다.

출력
총 M개의 줄에 걸쳐 홍준이의 질문에 대한 명우의 답을 입력으로 주어진 순서에 따라서 출력한다. 팰린드롬인 경우에는 1, 아닌 경우에는 0을 출력한다.

풀이:
dp[i][j] 를 bool형 배열로 선언하고, i~j 까지 팰린드롬인지? 로 정의합니다.

s~e 구간이 팰린드롬인지 판별하는 법은 

s + 1 ~ e - 1 구간이 팰린드롬일 때 arr[s] == arr[e] 이면 s ~ e 구간도 팰린드롬입니다.
s 와 e 의 구간의 간격을 1부터 시작해 늘려가며 위 방법을 적용하면 됩니다.

간격이 1일 땐 arr[s] 와 arr[e] 의 값만 비교하여 판단합니다.
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

int N, M;
bool dp[2001][2001];
int arr[2001];

int main(void) {
	FIO;

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
		dp[i][i] = true;
	}

	for (int itv= 1; itv < N; itv++)
	{
		for (int j = 1; j + itv <= N; j++)
		{
			int s = j;
			int e = j + itv;

			if (itv > 1) {
				if (dp[s + 1][e - 1]) {
					if (arr[s] == arr[e])
						dp[s][e] = true;
				}
			}
			else {
				if (arr[s] == arr[e])
					dp[s][e] = true;
			}
		}
	}

	cin >> M;

	while (M--) {
		int s, e;

		cin >> s >> e;

		cout << (int)dp[min(s, e)][max(s, e)] << "\n";
	}
}