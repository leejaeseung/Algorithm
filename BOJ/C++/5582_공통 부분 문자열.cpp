/*
문제
두 문자열이 주어졌을 때, 두 문자열에 모두 포함된 가장 긴 공통 부분 문자열을 찾는 프로그램을 작성하시오.

어떤 문자열 s의 부분 문자열 t란, s에 t가 연속으로 나타나는 것을 말한다. 예를 들어, 문자열 ABRACADABRA의 부분 문자열은 ABRA, RAC, D, ACADABRA, ABRACADABRA, 빈 문자열 등이다. 하지만, ABRC, RAA, BA, K는 부분 문자열이 아니다.

두 문자열 ABRACADABRA와 ECADADABRBCRDARA의 공통 부분 문자열은 CA, CADA, ADABR, 빈 문자열 등이 있다. 이 중에서 가장 긴 공통 부분 문자열은 ADABR이며, 길이는 5이다. 또, 두 문자열이 UPWJCIRUCAXIIRGL와 SBQNYBSBZDFNEV인 경우에는 가장 긴 공통 부분 문자열은 빈 문자열이다.

입력
첫째 줄과 둘째 줄에 문자열이 주어진다. 문자열은 대문자로 구성되어 있으며, 길이는 1 이상 4000 이하이다.

출력
첫째 줄에 두 문자열에 모두 포함 된 부분 문자열 중 가장 긴 것의 길이를 출력한다.

풀이:
LCS의 다른 유형 문제입니다.

가장 긴 연속된 공통 문자열을 구해야 하므로 기존 LCS에서 왼쪽, 위 값의 max를 취하는 방식으로 하면 안됩니다.
(띄엄띄엄 읽게 되기 때문에)

대신, 왼쪽, 왼쪽 위, 위 세 곳의 값의 min을 취하고, 모든 dp 값 중 최댓 값을 구하면 됩니다.
dp 모양이 연속된 문자열에서 대각선 아래로 연속적으로 증가하게 됩니다.
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

string s1, s2;
int dp[4001][4001];

int main(void) {
	FIO;

	cin >> s1 >> s2;

	int maxLeng = 0;

	for (int i = 1; i <= s1.size(); i++)
	{
		char now = s1[i - 1];
		for (int j = 1; j <= s2.size(); j++)
		{
			char comp = s2[j - 1];

			if (now == comp) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
			}
			
		maxLeng = max(maxLeng, dp[i][j]);
		}
	}

	cout << maxLeng;
}