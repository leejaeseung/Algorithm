/*
문제
SSR(A, B) = (sqrt(A) + sqrt(B))^2 이다.

두 정수 N, M이 주어졌을 때, 1 ≤ A ≤ N, 1 ≤ B ≤ M 이면서 SSR(A, B)가 정수인 (A, B) 쌍의 개수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N, M이 주어진다. (1 ≤ N, M ≤ 77,777)

출력
첫째 줄에 문제의 정답을 출력한다.

풀이:
루트를 벗기지 못하는 정수 x 에 대해, x와 짝을 이룰 수 있는 y 의 값들은
x * 1, x * 4, x * 9 ... 처럼 x에 제곱수를 곱한 값이다.

따라서 1 ~ 77777까지 모든 제곱수가 아닌 정수 a 에 대해 
a = b * root(c) 에서 최소의 c 값을 구한다.(나눌 수 있는 제곱수 중 가장 큰 값으로 나누면 된다.)

n 과 m 중 큰 값, 작은 값으로 나눠놓고 c * 제곱수 가 최소 값을 넘지 않을 때까지 카운트 해주면 된다.
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
#define MOD 100003
int mv1[4] = { 0, 0, 1, -1 };
int mv2[4] = { 1, -1, 0, 0 };
int mv_all1[8] = { 0, 1, 0, -1, -1, -1, 1, 1 };
int mv_all2[8] = { 1, 0, -1, 0 , -1, 1, -1, 1 };

int main(void) {
	FIO;

	int n, m;
	cin >> n >> m;

	int mx = max(n, m);
	int mn = min(n, m);

	int ans = 0;

	for (int i = 1; i <= mx; i++)
	{
		int maxSq = 1;
		for (int j = 1; j * j <= i; j++)
		{
			if(i % (j * j) == 0)
				maxSq = max(maxSq, j * j);
		}

		for (int j = 1; j * j <= 77777; j++)
		{
			if (mn >= (i / maxSq) * (j * j))
				ans++;
			else
				break;
		}
	}

	cout << ans;
}