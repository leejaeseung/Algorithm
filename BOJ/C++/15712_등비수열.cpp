/*
문제
첫 항이 a, 공비가 r, 항의 수가 n인 등비수열의 합을 mod로 나눈 나머지를 구하시오.

입력
첫째 줄에 a, r, n, mod가 공백으로 구분되어 주어진다. a, r, n, mod는 모두 1보다 크거나 같고, 109보다 작거나 같은 자연수이다.

출력
문제의 정답을 출력하라.

풀이:
등비수열의 합 공식을 이용하려 했으나 나눗셈이 있고, mod 값이 소수가 아니기 때문에 페르마의 소정리를 적용할 수 없었다.

https://m.blog.naver.com/PostView.nhn?blogId=rdd573&logNo=221271017363&proxyReferer=https:%2F%2Fwww.google.com%2F
위 풀이를 참고하여 n이 홀수, 짝수일 때를 나눠 log 거듭제곱 방식으로 풀이했다.
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

int a, r, n, mod;

ll md(ll num) {
	return num % mod;
}

ll mypow(ll num, ll cnt) {
	if (cnt == 1)
		return num;

	ll ret = md(mypow(num, cnt / 2));

	if (cnt % 2 == 0)
		return md(ret * ret);
	else
		return md(md(num) * md(ret * ret));
}

ll func(ll x) {
	if (x == 1) {
		return md(a);
	}

	ll ret = md(func(x / 2));

	if (x % 2 == 0)
		return md(ret * md(1 + mypow(r, x / 2)));
	else
		return md(md(ret * md(1 + mypow(r, x / 2))) + md(md(a) * md(mypow(r, x - 1))));

}

int main(void) {
	FIO;

	cin >> a >> r >> n >> mod;

	cout << func(n);
}