/*
����
���ڿ��� ��⸦ ���󿡼� ���� �����ϴ� �����̴� ���õ� ���ڿ� 2���� LCS(Longest Common Subsequence)�� ���ϰ� �־���. ��� �� �����̴� �������� ���ڿ� 3���� LCS�� ���ϴ� ���� ���Ҵ�. �����̵� ������ �������� �����ϰ� ���Ҵ�.

���� �츮�� �� ���� ������ ����. �����̸� ���ͼ� ���ڿ� 3���� LCS�� ���ϴ� ���α׷��� �ۼ��϶�.

�Է�
ù �ٿ��� ù ��° ���ڿ���, ��° �ٿ��� �� ��° ���ڿ���, ��° �ٿ��� �� ��° ���ڿ��� �־�����. (�� ���ڿ��� ���̴� 100���� �۰ų� ����)

���
ù �ٿ� ù ��° ���ڿ��� �� ��° ���ڿ��� �� ��° ���ڿ��� LCS�� ���̸� ����Ѵ�.

Ǯ��:
LCS ������ 3�������� Ȯ���� �����Դϴ�.

���� �˰����� 3�������� �������ָ� ���� Ǯ���ϴ�.
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