/*
문제
박성원은 이 문제를 풀지 못했다.

서로 다른 정수로 이루어진 집합이 있다. 이 집합의 순열을 합치면 큰 정수 하나를 만들 수 있다. 예를 들어, {5221,40,1,58,9}로 5221401589를 만들 수 있다. 합친수가 정수 K로 나누어 떨어지는 순열을 구하는 프로그램을 작성하시오.

하지만, 박성원은 이 문제를 풀지 못했다.

따라서 박성원은 그냥 랜덤하게 순열 하나를 정답이라고 출력하려고 한다. 이 문제에는 정답이 여러 개 있을 수도 있고, 박성원이 우연히 문제의 정답을 맞출 수도 있다.

박성원이 우연히 정답을 맞출 확률을 분수로 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 집합의 수의 개수 N이 주어진다. N은 15보다 작거나 같은 자연수이다. 둘째 줄부터 N개의 줄에는 집합에 포함된 수가 주어진다. 각 수의 길이는 길어야 50인 자연수이다. 마지막 줄에는 K가 주어진다. K는 100보다 작거나 같은 자연수이다.

출력
첫째 줄에 정답을 기약분수 형태로 출력한다. p/q꼴로 출력하며, p는 분자, q는 분모이다. 정답이 0인 경우는 0/1로, 1인 경우는 1/1로 출력한다.

풀이:
https://suuntree.tistory.com/124
참고했습니다.ㅎㄷㄷ
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
#define pic pair<int, char>
#define ll long long
#define vi vector<int>
#define vl vector<long long>
#define vii vector<pii>
#define IMAX 2000000001
int mv1[4] = { 0, 0, 1, -1 };
int mv2[4] = { 1, -1, 0, 0 };

int n, k;
vector<string> vt;
int remain[16];
int ten[51];
ll dp[1 << 15][101];

ll gcd(ll x, ll y) {
	if (y == 0) return x;
	return gcd(y, x % y);
}

int main(void) {

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		vt.push_back(s);
		
	}

	cin >> k;

	ten[0] = 1;
	for (int i = 1; i <= 50; i++)
	{
		ten[i] = ten[i - 1] * 10;
		ten[i] %= k;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < vt[i].size(); j++)
		{
			remain[i] = (remain[i] * 10 + (int)(vt[i][j] - '0')) % k;
		}
	}

	dp[0][0] = 1;
	for (int i = 0; i < (1 << n); i++)
	{
		for (int j = 0; j < k; j++)
		{
			for (int l = 0; l < n; l++)
			{
				if ((i & (1 << l)) == 0) {
					int next = j * ten[vt[l].size()];
					next %= k;
					next += remain[l];
					next %= k;

					dp[i | (1 << l)][next] += dp[i][j];
				}
			}
			
		}
	}

	ll all = 1;
	for (int i = 1; i <= n; i++)
	{
		all *= i;
	}

	ll ans = dp[(1 << n) - 1][0];
	ll g = gcd(ans, all);

	all /= g;
	ans /= g;

	cout << ans << "/" << all;
}