/*
문제
개의 자연수 과 정수 가 주어졌을 때 이항 계수 를 1,000,000,007로 나눈 나머지를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 이 주어진다. (1 ≤  ≤ 100,000)

둘째 줄부터 개의 줄에 과 가 주어진다. (1 ≤  ≤ 4,000,000, 0 ≤  ≤ )

출력
총 개의 줄에 를 1,000,000,007로 나눈 나머지를 출력한다.

풀이:
1 부터 4000000 까지의 팩토리얼을 모두 구해주고, 
페르마의 소정리를 이용해 nCr 에서 사용되는 나눗셈을 곱셈으로 바꾸어 주어야 한다.

A / B (mod M) == A / B^(M - 2)

위 공식을 이용.
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
int mv1[4] = { 0, 0, 1, -1 };
int mv2[4] = { 1, -1, 0, 0 };
int mv_all1[8] = { 0, 1, 0, -1, -1, -1, 1, 1 };
int mv_all2[8] = { 1, 0, -1, 0 , -1, 1, -1, 1 };

int m;
ll fact[4000001];
ll inv[4000001];
ll mod = 1000000007;

ll mypow(ll A, ll n) {
	if (n == 1)	return A;

	ll ret = mypow(A, n / 2) % mod;

	if (n % 2 == 0) {
		return ((ret % mod) * (ret % mod)) % mod;
	}
	else {
		return ((((ret % mod) * (ret % mod)) % mod) * (A % mod)) % mod;
	}
}

int main(void) {
	FIO;

	cin >> m;
	fact[0] = 1;

	for (int i = 1; i < 4000001; i++)
	{
		fact[i] = ((fact[i - 1] % mod) * (i % mod)) % mod;
 	}

	for (int i = 0; i < m; i++)
	{
		int n, k;

		cin >> n >> k;


		cout << ((fact[n] % mod) * (mypow((((fact[k] % mod) * (fact[n - k] % mod)) % mod), mod - 2) % mod)) % mod << "\n";
	}
}