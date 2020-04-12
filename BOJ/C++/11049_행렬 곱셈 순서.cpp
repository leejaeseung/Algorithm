/*
문제
크기가 N×M인 행렬 A와 M×K인 B를 곱할 때 필요한 곱셈 연산의 수는 총 N×M×K번이다. 행렬 N개를 곱하는데 필요한 곱셈 연산의 수는 행렬을 곱하는 순서에 따라 달라지게 된다.

예를 들어, A의 크기가 5×3이고, B의 크기가 3×2, C의 크기가 2×6인 경우에 행렬의 곱 ABC를 구하는 경우를 생각해보자.

AB를 먼저 곱하고 C를 곱하는 경우 (AB)C에 필요한 곱셈 연산의 수는 5×3×2 + 5×2×6 = 30 + 60 = 90번이다.
BC를 먼저 곱하고 A를 곱하는 경우 A(BC)에 필요한 곱셈 연산의 수는 3×2×6 + 5×3×6 = 36 + 90 = 126번이다.
같은 곱셈이지만, 곱셈을 하는 순서에 따라서 곱셈 연산의 수가 달라진다.

행렬 N개의 크기가 주어졌을 때, 모든 행렬을 곱하는데 필요한 곱셈 연산 횟수의 최솟값을 구하는 프로그램을 작성하시오. 입력으로 주어진 행렬의 순서를 바꾸면 안 된다.

입력
첫째 줄에 행렬의 개수 N(1 ≤ N ≤ 500)이 주어진다.

둘째 줄부터 N개 줄에는 행렬의 크기 r과 c가 주어진다. (1 ≤ r, c ≤ 500)

항상 순서대로 곱셈을 할 수 있는 크기만 입력으로 주어진다.

출력
첫째 줄에 입력으로 주어진 행렬을 곱하는데 필요한 곱셈 연산의 최솟값을 출력한다. 정답은 231-1 보다 작거나 같은 자연수이다. 또한, 최악의 순서로 연산해도 연산 횟수가 231-1보다 작거나 같다.

풀이:
11066번 파일 합치기와 같은 방식으로 풀이하는 문제였습니다.
단, 행렬의 곱이므로 다음과 같은 세 가지 경우를 생각합니다.

1. A * (B * C * D) -> 왼쪽은 하나의 행렬, 오른쪽은 여러 개의 행렬
2. (A * B) * (C * D) -> 왼쪽, 오른쪽 모두 여러 개의 행렬
3. (A * B * C) * D -> 왼쪽은 여러 개의 행렬, 오른쪽은 하나의 행렬

파일 합치기 문제와 마찬가지로 여러 개의 행렬은 이미 최소값이 계산되었다고 생각할 수 있습니다.
계산된 dp 값 두 개 + 두 행렬 뭉치의 곱 의 최소값을 갱신해주면 됩니다.
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
vector<pii> vt;
pair<long long, pii> dp[501][501];

int main(void) {
	FIO;

	cin >> N;

	for (int i = 0; i < 501; i++)
	{
		for (int j = 0; j < 501; j++)
		{
			dp[i][j].first = 10000000000;
		}
	}

	for (int i = 1; i <= N; i++)
	{
		int a, b;
		cin >> a >> b;

		dp[i][i].second = make_pair(a, b);
		dp[i][i].first = 0;
	}

	for (int itv = 1; itv < N; itv++)
	{
		for (int start = 1; start + itv <= N; start++)
		{
			for (int mid = start; mid <= start + itv; mid++)
			{
				if (dp[start][start + itv].first > dp[start][mid].first + dp[mid + 1][start + itv].first + dp[start][start].second.first * dp[mid][mid].second.second * dp[start + itv][start + itv].second.second) {
					dp[start][start + itv].first = dp[start][mid].first + dp[mid + 1][start + itv].first + dp[start][start].second.first * dp[mid][mid].second.second * dp[start + itv][start + itv].second.second;
				}
			}
		}
	}
	cout << dp[1][N].first;
}