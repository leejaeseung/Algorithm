/*
문제
문자열과 놀기를 세상에서 제일 좋아하는 영식이는 오늘도 문자열 2개의 LCS(Longest Common Subsequence)를 구하고 있었다. 어느 날 영식이는 조교들이 문자열 3개의 LCS를 구하는 것을 보았다. 영식이도 도전해 보았지만 실패하고 말았다.

이제 우리가 할 일은 다음과 같다. 영식이를 도와서 문자열 3개의 LCS를 구하는 프로그램을 작성하라.

입력
첫 줄에는 첫 번째 문자열이, 둘째 줄에는 두 번째 문자열이, 셋째 줄에는 세 번째 문자열이 주어진다. (각 문자열의 길이는 100보다 작거나 같다)

출력
첫 줄에 첫 번째 문자열과 두 번째 문자열과 세 번째 문자열의 LCS의 길이를 출력한다.

풀이:
LCS 문제를 3차원으로 확장한 문제입니다.

같은 알고리즘을 3차원으로 적용해주면 쉽게 풀립니다.
*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
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

string s1, s2, s3;
int dp[101][101][101];

int main(void) {
	FIO;

	cin >> s1 >> s2 >> s3;

	int n = s1.size(), m = s2.size(), k = s3.size();

	for (int i = 1; i <= n; i++)
	{
		char c1 = s1[i - 1];
		for (int j = 1; j <= m; j++)
		{
			char c2 = s2[j - 1];

			for (int l = 1; l <= k; l++)
			{
				char c3 = s3[l - 1];

				if (c1 == c2 && c2 == c3) {
					dp[i][j][l] = dp[i - 1][j - 1][l - 1] + 1;
				}
				else {
					dp[i][j][l] = max(max(dp[i][j][l - 1], dp[i][j - 1][l]), dp[i - 1][j][l]);
				}
			}
		}
	}

	cout << dp[n][m][k];
}