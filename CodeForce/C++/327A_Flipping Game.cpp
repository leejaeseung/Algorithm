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
int arr[101];
int dp[101][101][2];

int main(void) {
	FIO;

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = i; j <= N; j++)
		{
			for (int k = i; k <= j; k++)
			{
					dp[i][j][arr[k]]++;
			}
		}
	}

	int s = 0 , e = 0;
	int max = 0;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (max < dp[i][j][0] - dp[i][j][1]) {
				max = dp[i][j][0] - dp[i][j][1];
				s = i;
				e = j;
			}
		}
	}
	
	if (dp[1][N][1] != N)
		cout << dp[1][s - 1][1] + dp[s][e][0] + dp[e + 1][N][1];
	else
		cout << N - 1;
}