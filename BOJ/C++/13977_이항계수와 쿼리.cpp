/*
����
���� �ڿ��� �� ���� �� �־����� �� ���� ��� �� 1,000,000,007�� ���� �������� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �� �־�����. (1 ��  �� 100,000)

��° �ٺ��� ���� �ٿ� �� �� �־�����. (1 ��  �� 4,000,000, 0 ��  �� )

���
�� ���� �ٿ� �� 1,000,000,007�� ���� �������� ����Ѵ�.

Ǯ��:
1 ���� 4000000 ������ ���丮���� ��� �����ְ�, 
�丣���� �������� �̿��� nCr ���� ���Ǵ� �������� �������� �ٲپ� �־�� �Ѵ�.

A / B (mod M) == A / B^(M - 2)

�� ������ �̿�.
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