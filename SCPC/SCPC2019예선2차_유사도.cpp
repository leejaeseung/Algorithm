/*
n 개의 숫자들로 이루어진 두 개의 수열 a=a1 a2⋯an와 b=b1 b2⋯bn가 있다.
두 수열 a와 b의 유사도란 두 수열에서 같은 위치의 숫자가 일치하는 개수이다.
예를 들어, a=5 2 3 7 6 1와 b=5 7 1 2 6 3가 주어지면, 제일 첫 번째 숫자 5와 뒤에서 두 번째 숫자 6이 일치하므로 a와 b의 유사도는 2이다.

우리는 두 번째 수열 b에 대해서만 임의의 구간 [i,j]를 선택해서 이 구간에 속한 수들을 회전시킨다.
여기서, 회전이라는 것은 이 구간에 속한 수 bi bi+1⋯bj−1 bj를 bj bj−1⋯bi+1 bi와 같이 앞쪽과 뒤쪽의 수들을 서로 맞 바꾸는 것이다.
특별한 경우로 구간 [i,i]을 회전하면 수열엔 변화가 없다.

위 예의 b=5 7 1 2 6 3에서 구간 [3,6]을 회전하면, b는 수열 5 7 3 6 2 1이 되고 두 수열의 유사도는 3이 된다.
그러나 b 에서 구간 [2,4]를 회전하면, b는 수열 5 2 1 7 6 3 이 되고 두 수열의 유사도는 4 가 된다.

두 수열 a와 b가 주어질 때, 수열 b의 구간을 선택해서 단 한번 회전한 후 두 수열의 유사도가 최대가 되도록 하고 그 때의 유사도를 출력하는 프로그램을 작성하시오.

- 제한시간: 전체 테스트 케이스는 40개 이하이며, 전체 수행 시간은 2초 이내. (Java 4초 이내)
	제한 시간을 초과하면 제출한 소스코드의 프로그램이 즉시 종료되며,
	그때까지 수행한 결과에서 테스트 케이스를 1개 그룹 이상 통과하였더라도 점수는 0점이 됩니다.
	그러나, 제한 시간을 초과하더라도 테스트 케이스를 1개 그룹 이상 통과하였다면 '부분 점수(0< 점수< 만점)'를 받을 수 있으며,
	이를 위해서는, C / C++ 에서 "printf 함수" 사용할 경우, 프로그램 시작부분에서 "setbuf(stdout, NULL);"를 한번만 사용하십시오.
	C++에서는 "setbuf(stdout, NULL);"와 "printf 함수" 대신 "cout"를 사용하고, Java에서는 "System.out.printIn"을 사용하시면,
	제한 시간을 초과하더라도 '부분 점수'를 받을 수 있습니다.
	※ 언어별 기본 제공 소스코드 내용 참고
	만약, 제한 시간을 초과하지 않았는데도 '부분 점수'를 받았다면, 일부 테스트 케이스를 통과하지 못한 경우 입니다.

- 메모리 사용 제한 : heap, global, static 총계 256MB, stack 100MB
- 제출 제한 : 최대 10회 (제출 횟수를 반영하여 순위 결정 → 동점자의 경우 제출 횟수가 적은 사람에게 높은 순위 부여)

풀이:
어떤 구간 a, b 를 뒤집었을 때의 유사도는 다음과 같이 구할 수 있다.
(a - 1 까지의 유사도) + (a ~ b 의 거꾸로 유사도) + (b + 1 ~ n 까지의 유사도)

왼쪽과 오른쪽 값은 유사도의 prefix sum을 이용해 간단히 구할 수 있다.
dp[i] => i 까지의 유사도 누적 합

어떤 구간 a, b 에 대해 a, b 를 뒤집었을 때의 유사도를 미리 구해놔야 하는데,(N^2)
팰린드롬 dp 와 유사하게 만들면 된다.

수열의 길이를 1부터 시작해 늘려가면서 이전 길이의 dp값을 사용한다.
즉, x a b c d y 란 수열이 있을 때, x ~ y의 dp 값은 a ~ b 의 dp 값에 x,y 가 같은지 여부에 따라 0, 1, 2를 추가한 값이다.
*/
#include<iostream>
#include<memory.h>
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
#define pll pair<ll, ll>
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vii vector<pii>
#define IMAX 2000000001
#define LMAX 1000000000000000000
#define DMAX 0xFFFFFFFFFFFFF
#define MOD 0x0100000000
int mv1[4] = { 0, 0, 1, -1 };
int mv2[4] = { 1, -1, 0, 0 };
int mv_all1[8] = { 0, 1, 0, -1, -1, -1, 1, 1 };
int mv_all2[8] = { 1, 0, -1, 0 , -1, 1, -1, 1 };

int t, n;
int dp[5001];
int rdp[5001][5001];

int main(void) {
	FIO;

	cin >> t;

	for (int k = 1; k <= t; k++) {
		cin >> n;

		vector<int> A;
		vector<int> B;
		fill(&dp[0], &dp[5001], 0);
		fill(&rdp[0][0], &rdp[5000][5001], 0);

		A.push_back(-1);
		B.push_back(-1);

		for (int i = 0; i < n; i++)
		{
			int v;
			cin >> v;
			A.push_back(v);
		}

		for (int i = 0; i < n; i++)
		{
			int v;
			cin >> v;
			B.push_back(v);
		}

		for (int i = 1; i <= n; i++)
		{
			dp[i] = dp[i - 1];

			if (A[i] == B[i])
				dp[i]++;
		}

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n - i + 1; j++)
			{
				if (i == 1) {
					if(A[j] == B[j])
						rdp[j][j] = 1;
				}
				else if (i == 2) {
					if (A[j] == B[j + 1])
						rdp[j][j + 1]++;
					if(B[j] == A[j + 1])
						rdp[j][j + 1]++;
				}
				else {
					rdp[j][j + i - 1] = rdp[j + 1][j + i - 2];

					if (A[j] == B[j + i - 1])
						rdp[j][j + i - 1]++;
					if (B[j] == A[j + i - 1])
						rdp[j][j + i - 1]++;
				}
			}
		}

		int ans = 0;

		for (int i = 1; i <= n; i++)
		{
			for (int j = i; j <= n; j++)
			{
				ans = max(ans, dp[i - 1] + rdp[i][j] + (dp[n] - dp[j]));
			}
		}

		cout << "Case #" << k << "\n";
		cout << ans << "\n";
	}
}