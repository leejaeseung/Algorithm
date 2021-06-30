/*
����
�ϳ� �̻��� ���ӵ� �Ҽ��� ������ ��Ÿ�� �� �ִ� �ڿ������� �ִ�. �� ���� �ڿ����� ���� ��� ���� ������ ����.

3 : 3 (�� ����)
41 : 2+3+5+7+11+13 = 11+13+17 = 41 (�� ����)
53 : 5+7+11+13+17 = 53 (�� ����)
������ ���ӵ� �Ҽ��� ������ ��Ÿ�� �� ���� �ڿ����鵵 �ִµ�, 20�� �� ���̴�. 7+13�� ����ϸ� 20�� �Ǳ�� �ϳ� 7�� 13�� ������ �ƴϱ⿡ ������ ǥ���� �ƴϴ�. ���� �� �Ҽ��� �ݵ�� �� ���� ������ ���� �� �ֱ� ������, 3+5+5+7�� ���� ǥ���� �������� �ʴ�.

�ڿ����� �־����� ��, �� �ڿ����� ���ӵ� �Ҽ��� ������ ��Ÿ�� �� �ִ� ����� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �ڿ��� N�� �־�����. (1 �� N �� 4,000,000)

���
ù° �ٿ� �ڿ��� N�� ���ӵ� �Ҽ��� ������ ��Ÿ�� �� �ִ� ����� ���� ����Ѵ�.

Ǯ��:
�����佺�׳׽��� ü�� �Ҽ��� ��� ���� �迭�� �ְ�, ���ӵ� �Ҽ����� ���۰� ���� left, right �� �����͸� �̿��� Ž���Ѵ�.

���ӵ� �Ҽ����� ���� N ���� ������ right++, N���� ũ�ٸ� left++ �ذ��� Ž���ϸ� �ȴ�.
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
#define IMAX 2147483647
#define LMAX 1000000000000500000
#define DMAX 0xFFFFFFFFFFFFF
int mv1[4] = { 0, 1, -1, 0 };
int mv2[4] = { 1, 0, 0, -1 };

int n;
bool prime_check[4000001];
vector<int> prime;

void getPrime() {
	prime_check[1] = true;

	for (int i = 2; i <= sqrt(4000000); i++)
	{
		for (int j = 2; i * j <= 4000000; j++)
		{
			prime_check[i * j] = true;
		}
	}

	for (int i = 2; i <= 4000000; i++)
	{
		if (!prime_check[i]) {
			prime.push_back(i);
		}
	}
}

int main() {
	FIO;

	cin >> n;

	getPrime();

	int left = 0;
	int right = 0;
	int sum = prime[0];

	int count = 0;

	while (right < prime.size() - 1) {

		if (sum == n) {
			count++;
		}
		else if (sum > n) {
			sum -= prime[left];
			left++;
			continue;
		}
		right++;
		sum += prime[right];
	}

	if (sum == n)	count++;

	cout << count;
}