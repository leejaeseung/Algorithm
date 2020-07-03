/*
문제
동호와 규완이는 212호에서 문자열에 대해 공부하고 있다. 김진영 조교는 동호와 규완이에게 특별 과제를 주었다. 특별 과제는 특별한 문자열로 이루어 진 사전을 만드는 것이다. 사전에 수록되어 있는 모든 문자열은 N개의 "a"와 M개의 "z"로 이루어져 있다. 그리고 다른 문자는 없다. 사전에는 알파벳 순서대로 수록되어 있다.

규완이는 사전을 완성했지만, 동호는 사전을 완성하지 못했다. 동호는 자신의 과제를 끝내기 위해서 규완이의 사전을 몰래 참조하기로 했다. 동호는 규완이가 자리를 비운 사이에 몰래 사전을 보려고 하기 때문에, 문자열 하나만 찾을 여유밖에 없다.

N과 M이 주어졌을 때, 규완이의 사전에서 K번째 문자열이 무엇인지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N, M, K가 순서대로 주어진다. N과 M은 100보다 작거나 같은 자연수이고, K는 1,000,000,000보다 작거나 같은 자연수이다.

출력
첫째 줄에 규완이의 사전에서 K번째 문자열을 출력한다. 만약 규완이의 사전에 수록되어 있는 문자열의 개수가 K보다 작으면 -1을 출력한다.

풀이:
이항계수를 이용하여 n개의 a, m개의 z 가 가질 수 있는 모든 조합의 수를 dp[n][m] 에 구해놓고 시작합니다.
(단, long long 범위를 초과할 수 있습니다. 어차피 k 까지만 알면 되므로 1000000000을 초과한 값들은 1000000001로 바꿔줍니다.)

n = 2 , m = 2, k = 2 일 때 다음과 같습니다.

1 aazz
2 azaz  <- k
3 azza
4 zaaz
5 zaza
6 zzaa

사전식으로 앞에서부터 구해야 하므로, 맨 앞에 a를 이미 놓았다고 가정하고, a가 1개, z가 2개일 때의 경우의 수를 구합니다
dp[1][2] = 3
k가 해당 구간에 포함되므로(k <= 3) 맨 앞에 a를 붙여줍니다.
만약 구간보다 크다면, k = k - 3 으로 k 값을 내려줍니다.(z를 맨 앞에 붙여줍니다.)

a나 z를 붙일 때마다 현재 보고있는 a의 개수, z의 개수를 각각 줄여가면 됩니다.
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

int n, m, k;
ll dp[101][101];		//dp[a의 개수][z의 개수] = 총 경우의 수

int main(void) {
	FIO;

	cin >> n >> m >> k;
	
	dp[0][0] = 1;
	dp[0][1] = 1;
	dp[1][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		dp[i][0] = 1;
	}
	for (int i = 1; i <= m; i++)
	{
		dp[0][i] = 1;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			if (dp[i][j] >= 1000000001)
				dp[i][j] = 1000000001;
		}
	}

	if (k <= dp[n][m]) {
		ll nowN = n, nowM = m;

		string ans = "";

		while (nowN > 0 || nowM > 0) {
			//a나 z가 남아있으면
			ll now;
			if (nowN <= 0)
				now = 1;
			else
				now = dp[nowN - 1][nowM];

			if (nowN > 0 && now >= k) {
				ans += "a";
				nowN--;
				//a를 붙였으므로 a의 개수 감소
			}
			else{
				ans += "z";
				k -= now;
				nowM--;
				//z를 붙였으므로 z의 개수 감소
			}
		}

		cout << ans;
	}
	else
		cout << "-1";
}