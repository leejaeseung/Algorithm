/*
문제
2차원 배열이 주어졌을 때 (i, j) 위치부터 (x, y) 위치까지에 저장되어 있는 수들의 합을 구하는 프로그램을 작성하시오. 배열의 (i, j) 위치는 i행 j열을 나타낸다.

입력
첫째 줄에 배열의 크기 N, M(1 ≤ N, M ≤ 300)이 주어진다. 다음 N개의 줄에는 M개의 정수로 배열이 주어진다. 배열에 포함되어 있는 수는 절댓값이 10,000보다 작거나 같은 정수이다. 그 다음 줄에는 합을 구할 부분의 개수 K(1 ≤ K ≤ 10,000)가 주어진다. 다음 K개의 줄에는 네 개의 정수로 i, j, x, y가 주어진다(i ≤ x, j ≤ y).

출력
K개의 줄에 순서대로 배열의 합을 출력한다. 배열의 합은 231-1보다 작거나 같다.

풀이:
심심풀이 dp - 2차원 prefix Sum을 사용한다.
*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>
#define pdd pair<double, double>
#define pic pair<int, char>
#define ll long long
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vii vector<pii>
#define IMAX 2000000001
#define LMAX 1000000000000000000
#define DMAX 0xFFFFFFFFFFFFF
int mv1[4] = { 0, 1, 0, -1 };
int mv2[4] = { 1, 0, -1, 0 };
int mv_all1[8] = { 0, 1, 0, -1, -1, -1, 1, 1 };
int mv_all2[8] = { 1, 0, -1, 0 , -1, 1, -1, 1 };

int n, m, k;
int dp[301][301];

int main(void) {
	FIO;

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			int v;
			cin >> v;

			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + v;
		}
	}

	cin >> k;

	for (int i = 0; i < k; i++)
	{
		int a, b, c, d;

		cin >> a >> b >> c >> d;

		cout << dp[c][d] - dp[a - 1][d] - dp[c][b - 1] + dp[a - 1][b - 1] << "\n";
	}
}