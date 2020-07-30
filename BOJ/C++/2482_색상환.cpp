/*
문제
색을 표현하는 기본 요소를 이용하여 표시할 수 있는 모든 색 중에서 대표적인 색을 고리 모양으로 연결하여 나타낸 것을 색상환이라고 한다. 미국의 화가 먼셀(Munsell)이 교육용으로 고안한 20색상환이 널리 알려져 있다. 아래 그림은 먼셀의 20색상환을 보여준다.



그림 1. 먼셀의 20색상환

색상환에서 인접한 두 색은 비슷하여 언뜻 보면 구별하기 어렵다. 위 그림의 20색상환에서 다홍은 빨강과 인접하고 또 주황과도 인접하다. 풀색은 연두, 녹색과 인접하다. 시각적 대비 효과를 얻기 위하여 인접한 두 색을 동시에 사용하지 않기로 한다.

주어진 색상환에서 시각적 대비 효과를 얻기 위하여 서로 이웃하지 않은 색들을 선택하는 경우의 수를 생각해 보자.  먼셀의 20색상환에서 시각적 대비 효과를 얻을 수 있게 10개의 색을 선택하는 경우의 수는 2이지만, 시각적 대비 효과를 얻을 수 있게 11개 이상의 색을 선택할 수 없으므로 이 경우의 수는 0이다.

주어진 정수 N과 K에 대하여, N개의 색으로 구성되어 있는 색상환 (N색상환)에서 어떤 인접한 두 색도 동시에 선택하지 않으면서 서로 다른 K개의 색을 선택하는 경우의 수를 구하는 프로그램을 작성하시오.

입력
입력 파일의 첫째 줄에 색상환에 포함된 색의 개수를 나타내는 양의 정수 N(4≤N≤1,000)이 주어지고, 둘째 줄에 N색상환에서 선택할 색의 개수 K(1≤K≤N)가 주어진다.

출력
첫째 줄에 N색상환에서 어떤 인접한 두 색도 동시에 선택하지 않고 K개의 색을 고를 수 있는 경우의 수를 1,000,000,003 (10억 3) 으로 나눈 나머지를 출력한다.

풀이:
N - 1 번 색을 생각하지 않고 0번~ N - 2 번까지 선형으로 칠해본다.

dp[i][j] = dp[i - 2][j - 1] + dp[i - 1][j]

i번째 색을 j번째로 칠하는 경우의 수 = 두 칸 전의 색의 경우의 수 + 전 칸에 칠하는 경우의 수

N - 1 번째 칸을 칠할 경우
- 0번, N - 2 번째 칸을 칠하지 말아야 하므로 1 ~ N - 3번 칸을 칠하는 경우의 수와 같다.

N - 1 번째 칸을 칠하지 않을 경우
- 0 ~ N - 2번 칸을 칠하는 경우의 수와 같다.
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

int n, k;
int dp[1000][1001];
int mod = 1000000003;

int main(void) {
	FIO;

	cin >> n >> k;

	if (n / 2 < k)
		cout << "0";
	else {

		for (int i = 0; i < n; i++)
		{
			dp[i][1] = i + 1;
			dp[i][0] = 1;
		}

		for (int i = 2; i <= n - 1; i++)
		{
			for (int j = 2; j <= k; j++)
			{
				dp[i][j] = ((dp[i - 2][j - 1] % mod) + (dp[i - 1][j] % mod)) % mod;
			}
		}

		dp[n - 1][k] = ((dp[n - 4][k - 1] % mod) + (dp[n - 2][k] % mod)) % mod;
		cout << dp[n - 1][k];
	}
}