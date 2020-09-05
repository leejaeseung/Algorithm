/*
����
ù ���� a, ���� r, ���� ���� n�� �������� ���� mod�� ���� �������� ���Ͻÿ�.

�Է�
ù° �ٿ� a, r, n, mod�� �������� ���еǾ� �־�����. a, r, n, mod�� ��� 1���� ũ�ų� ����, 109���� �۰ų� ���� �ڿ����̴�.

���
������ ������ ����϶�.

Ǯ��:
�������� �� ������ �̿��Ϸ� ������ �������� �ְ�, mod ���� �Ҽ��� �ƴϱ� ������ �丣���� �������� ������ �� ������.

https://m.blog.naver.com/PostView.nhn?blogId=rdd573&logNo=221271017363&proxyReferer=https:%2F%2Fwww.google.com%2F
�� Ǯ�̸� �����Ͽ� n�� Ȧ��, ¦���� ���� ���� log �ŵ����� ������� Ǯ���ߴ�.
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