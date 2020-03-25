/*
문제
공교육의 수호자 수찬이는 공교육의 정수라고 할 수 있는 한국정보올림피아드의 문제를 가지고 게임을 하려고 한다. 수찬이는 2010년도 한국정보올림피아드 시·도 지역본선 중등부 1번 문제를 보고 영감을 받아 새로운 게임을 만들었다. 기존 게임은 1에서부터 6까지의 눈을 가진 3개의 주사위를 던져서 다음과 같은 규칙에 따라 상금을 받는 게임이다.

같은 눈이 3개가 나오면 10,000원+(같은 눈)*1,000원의 상금을 받게 된다.
같은 눈이 2개만 나오는 경우에는 1,000원+(같은 눈)*100원의 상금을 받게 된다.
모두 다른 눈이 나오는 경우에는 (그 중 가장 큰 눈)*100원의 상금을 받게 된다.
예를 들어, 3개의 눈 3, 3, 6이 주어지면 상금은 1,000+3*100으로 계산되어 1,300원을 받게 된다. 또 3개의 눈이 2, 2, 2로 주어지면 10,000+2*1,000 으로 계산되어 12,000원을 받게 된다. 3개의 눈이 6, 2, 5로 주어지면 그중 가장 큰 값이 6이므로 6*100으로 계산되어 600원을 상금으로 받게 된다.

수찬이가 만든 새로운 게임의 룰은 다음과 같다.

게임이 시작되면 플레이어는 주사위를 여러 번 던진다.
주사위를 던지다가 던진 눈의 값이 마음에 들면 언제든지 게임을 끝낼 수 있다. 그렇지 않다면 주사위를 한 번 더 던질 수 있다.
주사위는 최소 세 번 던져야 하며 최대 N번까지 던질 수 있다.
게임이 끝날 때 플레이어가 받는 상금은 가장 최근에 던진 주사위 세 번의 값을 가지고 기존 규칙에 따라 계산한다.
만약 수찬이가 주사위를 여섯 번 던져서 6, 6, 6, 5, 1, 5가 나왔다면 상금은 1,000+5*100으로 계산되어 1,500원을 받게 된다.

수찬이는 받을 수 있는 상금의 기댓값이 최대가 되도록 게임을 플레이한다. N이 주어질 때 수찬이가 받는 상금의 기댓값을 구하는 프로그램을 작성하여라.

입력
첫 번째 줄에 주사위를 던질 수 있는 최대 횟수 N (3 ≤ N ≤ 1,000)가 주어진다.

풀이:
기댓값에 대한 이해가 필요한 문제였습니다.

https://sos0911.github.io/ps/alg17367/
를 참고했습니다.
*/
#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<vector>
#include<cstring>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>

int N;
double dp[1001][7][7][7];

double calculate(int a, int b,int c) {
	if (a == b && b == c) 
		return 10000 + (double)a * 1000;
	else if (a == b || b == c) 
		return 1000 + (double)b * 100;
	else if (a == c) 
		return 1000 + (double)a * 100;
	else
		return 100 * (double)max(a, max(b, c));
}

double recul(int i, int j, int k, int left) {
	double now = calculate(i, j, k);

	if (left == 0)
		return now;

	double& ret = dp[left][i][j][k];

	if (ret > 0)
		return ret;

	double sum = 0;
	for (int l = 1; l <= 6; l++)
	{
		sum += recul(j, k, l, left - 1);
	}
	return ret = max(now, sum / 6);
}

int main(void) {
	FIO;

	cin >> N;

	memset(dp, -1, sizeof(dp));
	double ans = 0;

	for (int i = 1; i <= 6; i++)
	{
		for (int j = 1; j <= 6; j++)
		{
			for (int k = 1; k <= 6; k++)
			{
				ans += recul(i, j, k, N - 3);
			}
		}
	}
	cout.precision(12);
	cout << ans / 216 << "\n";
}