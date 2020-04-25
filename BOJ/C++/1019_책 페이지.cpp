/*
����
�����̴� N���� å�� �ѱ� �ִ�. ù �������� 1���̰�, ������ �������� N���̴�. �� ���ڰ� ��� �� ���� �������� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� N�� �־�����. N�� 1,000,000,000���� �۰ų� ���� �ڿ����̴�.

���
ù° �ٿ� 0�� �� �� �� ��������, 1�� �� �� �� ��������, ..., 9�� �� �� �� ���������� ����Ѵ�.

Ǯ��:

*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<string>
#include<vector>
#include<queue>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>
#define ll long long

int N;
ll num[10];

void add(ll n, ll mul) {
	while (n > 0) {
		num[n % 10] += mul;
		n /= 10;
	}
}

void recul(ll A, ll B, ll mul) {
	
	while (A % 10 != 0 && A <= B) {

		add(A, mul);
		A++;
	}

	if (A > B)	return;

	while (B % 10 != 9 && B >= A) {

		add(B, mul);
		B--;
	}

	for (int i = 0; i < 10; i++)
	{
		num[i] += (B / 10 - A / 10 + 1) * mul;
	}

	recul(A / 10, B / 10, mul * 10);
}

int main(void) {
	FIO;

	cin >> N;

	recul(1, N, 1);

	for (int i = 0; i < 10; i++)
	{
		cout << num[i] << " ";
	}
}