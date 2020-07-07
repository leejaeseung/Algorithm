/*
문제
45656이란 수를 보자.

이 수는 인접한 모든 자리수의 차이가 1이 난다. 이런 수를 계단 수라고 한다.

그럼, 오늘도 역시 세준이는 0부터 9까지 모든 한 자리수가 자리수로 등장하면서, 수의 길이가 N인 계단 수가 몇 개 있는지 궁금해졌다.

N이 주어질 때, 길이가 N이면서 0에서 9가 모두 등장하는 계단 수가 총 몇 개 있는 지 구하는 프로그램을 작성하시오. (0으로 시작하는 수는 없다.)

입력
첫째 줄에 N이 주어진다. N은 1보다 크거나 같고, 100보다 작거나 같은 자연수이다.

출력
첫째 줄에 정답을 1,000,000,000으로 나눈 나머지를 출력한다.

풀이:
숫자를 하나하나 추가하며 이전 숫자의 값에 따라 넣어줄 숫자가 바뀌게 됩니다.
만약 이전 마지막 숫자가 0 이라면 1 만, 9 라면 8 만, 1 ~ 8 이라면 +1 or -1 의 숫자만이 다음에 올 수 있습니다.

문제에서 0 ~9 까지의 숫자가 모두 들어가야 한다고 했으므로 10 개의 숫자에 대해 비트마스크로 체크를 해줘야 합니다.
따라서 dp[마지막 숫자][길이][지금까지 사용된 숫자들 비트마스크] 로 만들어 숫자를 하나 넣어줄 때마다 이전 비트마스크들의 값을 모두 더해주어야 합니다.
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

int n;
ll divide = 1000000000;
ll dp[10][101][1024];

int main(void) {
	FIO;

	cin >> n;

	ll sum = 0;

	for (int i = 1; i < 10; i++)
	{
		//시작 값이 0을 제외하고 모두 1로 초기화
		dp[i][1][1 << i] = 1;
	}

		for (int i = 2; i <= n; i++)
		{

			for (int j = 0; j < 10; j++)
			{

				if (j == 0) {

					for (int k = 0; k < 1024; k++)
						//이전의 모든 비트마스크들의 값들을 더해줌
					{
						dp[j][i][k | (1 << 0)] = dp[j][i][k | (1 << 0)] % divide + dp[1][i - 1][k] % divide;
					}
				}
				else if (j == 9) {
					for (int k = 0; k < 1024; k++)
					{
						dp[j][i][k | (1 << 9)] = dp[j][i][k | (1 << 9)] % divide + dp[8][i - 1][k] % divide;
					}
				}
				else {
					for (int k = 0; k < 1024; k++)
					{
						dp[j][i][k | (1 << j)] = dp[j][i][k | (1 << j)] % divide + dp[j - 1][i - 1][k] % divide + dp[j + 1][i - 1][k] % divide;
					}
				}
			}
		}

		for (int i = 0; i < 10; i++)
		{
			//비트마스크가 1023인 경우에만 전부 사용된 것이므로 1023인 dp만 합함.
			sum = ((sum % divide) + (dp[i][n][1023]) % divide) % divide;
		}

	cout << sum;
}