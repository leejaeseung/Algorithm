/*
문제
3×N 크기의 벽을 2×1, 1×2 크기의 타일로 채우는 경우의 수를 구해보자.

입력
첫째 줄에 N(1 ≤ N ≤ 30)이 주어진다.

출력
첫째 줄에 경우의 수를 출력한다.

풀이:
오른쪽에 타일을 붙여가며 풀이하는데, 4, 6, 8 ... 마다 해당 크기의 고유한 타일이 2개 만들어지는 걸
고려해서 계산한다.
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

int dp[31];

int main(void) {
	FIO;

	int n;
	cin >> n;

	dp[2] = 3;
	dp[0] = 1;

	if (n % 2 != 0) {
		cout << "0";
	}
	else {

		for (int i = 4; i <= n; i += 2)
		{
			dp[i] = dp[i - 2] * 3;

			for (int j = 4; j <= i; j += 2)
			{
				dp[i] += dp[i - j] * 2;
			}
		}

		cout << dp[n];
	}
}