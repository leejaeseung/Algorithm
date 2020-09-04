/*
문제
nCm의 끝자리 0의 개수를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 정수 n, m(0≤m≤n≤2,000,000,000, n!=0)이 들어온다.

출력
첫째 줄에 0의 개수를 출력한다.

풀이:
끝자리 0의 개수 = 소인수 분해 했을 때 10의 개수 = min(5의 개수, 2의 개수)

A! 에서 5의 개수 = A를 5의 제곱수들로 나눴을 때의 몫들의 합
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

ll n, m;

int cnt(ll num, ll mul) {
	ll ret = 0;

	for (ll i = mul; i <= num; i *= mul)
	{
		ret += num / i;
	}

	return ret;
}

int main(void) {
	FIO;

	cin >> n >> m;

	cout << min(cnt(n, 5) - cnt(n - m, 5) - cnt(m, 5), cnt(n, 2) - cnt(n - m, 2) - cnt(m, 2));
}