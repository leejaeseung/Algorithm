/*
����
�ڿ��� �� ���� �� �־����� �� ���� ��� �� 10,007�� ���� �������� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �� �� �־�����. (1 ��  �� 1,000, 0 ��  �� )

���
 �� 10,007�� ���� �������� ����Ѵ�.

Ǯ��:
���շ�, �丣���� �������� �̿��� Ǯ��
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

int n, k;
int mod = 10007;

int factorial(int a) {
	int ret = 1;

	for (int i = 1; i <= a; i++)
	{
		ret = ((ret % mod) * (i % mod)) % mod;
	}

	return ret;
}

int mypow(int a, int b) {

	if (b == 1)	return a;

	int ret = mypow(a, b / 2) % mod;
	ret = ((ret % mod) * (ret % mod)) % mod;

	if (b % 2 == 0)
		return ret;
	else
		return ((ret % mod) * (a % mod)) % mod;
}

int main(void) {
	FIO;

	cin >> n >> k;

	cout << ((factorial(n) % mod) * (mypow(((factorial(k) % mod) * (factorial(n - k) % mod)) % mod, mod - 2) % mod)) % mod;
}