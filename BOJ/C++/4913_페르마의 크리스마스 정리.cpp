/*
����
1640�� 12�� 25��, ������ ������ �ǿ��� �� �丣���� ���� �޸������� ������ ���� ������ ������ ���.

I just proved that an odd prime p is expressible as p = a2 + b2 if and only if p is expressible as p = 4c + 1.
�������� ������ ���ԵǾ� ���� �ʾҰ�, 100���Ŀ� ���Ϸ��� �����ߴ�. 5, 13, 17, 41�� �� �������� ������ ��Ÿ�� �� �ִ�.

5=22+11 13=32+22 17=42+12 41=52+42

������, 11, 19, 23, 31�� �������� ������ ��Ÿ�� �� ����.

� ������ �־����� ��, �� ������ ���ԵǾ� �ִ� �Ҽ��� �������� ������ ��Ÿ�� �� �ִ� ����� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
�Է��� ���� ���� �׽�Ʈ ���̽��� �̷���� �ִ�. �� �׽�Ʈ ���̽��� �� �ٷ� �̷���� �ְ�, L�� U�� �������� ���еǾ� �־�����. (L �� U < 1,000,000)

�Է��� ������ ���� L�� U�� -1�̴�.

���
�� �׽�Ʈ ���̽��� ���ؼ�, �� �ٿ� L U x y�� ����Ѵ�. ���⼭ L�� U�� �Է����� �־��� ���̰�, x�� ���� [L,U]�� ���Ե� �Ҽ��� ����, y�� [L,U]�� ���Ե� �Ҽ��� �������� ������ ��Ÿ�� �� �ִ� ���� �����̴�.

Ǯ��:
�����佺�׳׽��� ü�� �Ҽ� �迭�� �����, �Ҽ��� ������ ���� ������ ��Ÿ�� �� �ִ��� ���δ�
a == 2 || a % 4 == 1 �� ã�Ƴ� �� �ִ�.(a �� �Ҽ��� ��)

�׷��� �׽�Ʈ���̽����� 1�ʰ� �ƴ϶� ��ü �׽�Ʈ���̽��� 1�ʾȿ� ���ƾ� �ؼ�
�ݺ����� �̿��� L ~ U ���� �迭�� �Ǵ��ϴ� �ð� �ʰ��� ����, L�� U�� ������ ��쵵 ó���� �־�� �ߴ�.
�Ҽ�, �������� ������ �� �Ҽ� �� ���� ���͸� �����, �̺� Ž������ L, U ���̿� �ִ� ������ ���� �־���.
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

bool isPrime[1000001];
vector<int> sq;
vector<int> prime;

int main(void) {
	FIO;

	for (int i = 2; i <= 1000; i++)
	{
		for (int j = 2; i * j < 1000000; j++)
		{
			isPrime[i * j] = true;
		}
	}

	for (int i = 2; i < 1000000; i++)
	{
		if (!isPrime[i]) {
			prime.push_back(i);

			if (i == 2 || i % 4 == 1)
				sq.push_back(i);
		}
	}

	while (true) {
		int L, U;
		cin >> L >> U;

		if (L == -1 && U == -1)	break;

		int n = max(0, L);
		int m = max(0, U);

		int ans1 = (lower_bound(prime.begin(), prime.end(), m + 1) - prime.begin()) - (lower_bound(prime.begin(), prime.end(), n) - prime.begin());
		int ans2 = (lower_bound(sq.begin(), sq.end(), m + 1) - sq.begin()) - (lower_bound(sq.begin(), sq.end(), n) - sq.begin());

		cout << L << " " << U << " " << ans1 << " " << ans2 << "\n";
	}
}