/*
����
LCS(Longest Common Subsequence, ���� ���� �κ� ����)������ �� ������ �־����� ��, ����� �κ� ������ �Ǵ� ���� �� ���� �� ���� ã�� �����̴�.

���� ���, ACAYKP�� CAPCAK�� LCS�� ACAK�� �ȴ�.

�Է�
ù° �ٰ� ��° �ٿ� �� ���ڿ��� �־�����. ���ڿ��� ���ĺ� �빮�ڷθ� �̷���� ������, �ִ� 1000���ڷ� �̷���� �ִ�.

���
ù° �ٿ� �Է����� �־��� �� ���ڿ��� LCS�� ���̸�, ��° �ٿ� LCS�� ����Ѵ�.

LCS�� ���� ������ ��쿡�� �ƹ��ų� ����ϰ�, LCS�� ���̰� 0�� ��쿡�� ��° ���� ������� �ʴ´�.

Ǯ��:
LCS ������ ��� ã�⸦ �߰��� ���������ϴ�.
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
int mv1[3] = { 0, 1, 1 };
int mv2[3] = { 1, 0, 1 };

string s1, s2;
int dp[1001][1001];

pii getidx(int x, int y) {
	int now = dp[x][y];

	if (dp[x - 1][y] == now) {
		while (dp[x - 1][y] == now) {
			x--;
		}
	}
	else if (dp[x][y - 1] == now) {
		while (dp[x][y - 1] == now) {
			y--;
		}
	}
	return make_pair(x, y);
}

int main(void) {
	FIO;

	cin >> s1 >> s2;
	int n = s1.size(), m = s2.size();

	for (int i = 1; i <= n; i++)
	{
		char now = s1[i - 1];

		for (int j = 1; j <= m; j++)
		{
			char comp = s2[j - 1];

			if (now == comp) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	int leng = dp[n][m];
	int x = n, y = m;

	stack<char> stack;

	while (dp[x][y] != 0) {
		if (dp[x - 1][y] == dp[x][y]) {
				x--;
		}
		else if (dp[x][y - 1] == dp[x][y]) {
				y--;
		}
		else if(dp[x][y] - 1 == dp[x - 1][y - 1]){
			stack.push(s1[x - 1]);
			x--;
			y--;
		}
	}

	cout << leng << "\n";

	while (!stack.empty()) {
		cout << stack.top();
		stack.pop();
	}
}