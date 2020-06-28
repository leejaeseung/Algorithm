/*
����
�������� ����: 2���� ū ¦���� �� �Ҽ��� ������ ��Ÿ�� �� �ִ�.
¦�� N�� �� �Ҽ��� ������ ��Ÿ���� ǥ���� ������ ��Ƽ���̶�� �Ѵ�. ¦�� N�� �־����� ��, ������ ��Ƽ���� ������ ���غ���. �� �Ҽ��� ������ �ٸ� ���� ���� ��Ƽ���̴�.

�Է�
ù° �ٿ� �׽�Ʈ ���̽��� ���� T (1 �� T �� 100)�� �־�����. �� �׽�Ʈ ���̽��� �� �ٷ� �̷���� �ְ�, ���� N�� ¦���̰�, 2 < N �� 1,000,000�� �����Ѵ�.

���
������ �׽�Ʈ ���̽����� ������ ��Ƽ���� ���� ����Ѵ�.

Ǯ��:
�����佺�׳׽��� ü ����~
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

int t, n;
bool prime[1000001];

int main(void) {
	FIO;

	cin >> t;

	prime[1] = true;

	for (int i = 2; i <= sqrt(1000000); i++)
	{
		for (int j = 2; i * j <= 1000000; j++)
		{
			prime[i * j] = true;
		}
	}

	while (t--) {
		cin >> n;

		int cnt = 0;

		for (int i = 2; i <= n / 2; i++)
		{
			if (!prime[i] && !prime[n - i])
				cnt++;
		}
		cout << cnt << "\n";
	}
}