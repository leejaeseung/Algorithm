/*
문제
n×m의 0, 1로 된 배열이 있다. 이 배열에서 1로 된 가장 큰 정사각형의 크기를 구하는 프로그램을 작성하시오.

0	1	0	0
0	1	1	1
1	1	1	0
0	0	1	0
위와 같은 예제에서는 가운데의 2×2 배열이 가장 큰 정사각형이다.

입력
첫째 줄에 n, m(1 ≤ n, m ≤ 1,000)이 주어진다. 다음 n개의 줄에는 m개의 숫자로 배열이 주어진다.

출력
첫째 줄에 가장 큰 정사각형의 넓이를 출력한다.

풀이:
dp[i][j]를 (i,j)를 오른쪽 아래 꼭지점으로 하는 정사각형의 한 변의 길이로 정의한다.
점을 순차적으로 탐색해가면서 왼쪽, 왼쪽 위, 위쪽 중 최솟값 + 1 이 dp[i][j] 가 된다.
dp[i][j] 가 0인 경우는 정사각형을 만들 수 없으므로 그대로 0이다.
*/
#include<iostream>
#include<algorithm>
using namespace std;

int N, M;
int dp[1001][1001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	char s[1001];

	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> s;
		for (int j = 0; j < M; j++)
		{
			if (s[j] - '0' == 0)	continue;
			if (i == 0 && j == 0) {
				dp[i][j] = s[j] - '0';
			}
			else if (i == 0) {
				dp[i][j] = 1;
			}
			else if (j == 0) {
				dp[i][j] = 1;
			}
			else {
				dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
			}
			ans = max(ans, dp[i][j]);
		}
		
	}

	cout << ans * ans;
}