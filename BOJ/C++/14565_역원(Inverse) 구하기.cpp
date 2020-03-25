/*
����
���� Zn�� 0���� n-1������ ���� �����̶�� ����. Zn �� a, b �� ��, (a+b) mod n = 0�̸� b�� a�� �������̶�� �ϰ� (a*c) mod n = 1�̸� c�� a�� �������̶�� �Ѵ�.

���� N, A�� �־����� �� Zn������ A�� �������� �������� ���Ͻÿ�.

��, �������� ���� �� ������ -1�� ����Ѵ�.

�Է�
ù ��° �ٿ� N(2 �� N �� 1012)�� A(1 �� A < N)�� �־�����..

���
ù ��° �ٿ� A�� N�� ���� �������� �������� �� �ٿ� �������� �����Ͽ� ����Ѵ�.

Ǯ��:
Ȯ�� ��Ŭ���� ȣ������ �̿��� Ǯ���߽��ϴ�.
������ ������ N - A �̰�,

N �� A�� ���� �ִ� ������� ���ϸ鼭, Ȯ�� ��Ŭ���� ȣ������ ���� ������ ���� t �� ���� �˴ϴ�.(t�� �������� ������ N�� ���� ����� ����� �ݴϴ�.)
�ִ� ������� 1�� �ƴ� ��� N �� A�� ���μҰ� �ƴϹǷ� -1�� ����մϴ�.
*/
#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<vector>
#include<queue>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>

long long N, A;
vector<long long> s, t;

long long gcd(long long x, long long y) {
	s = { 1, 0 };
	t = { 0, 1 };
	long long q = 1;

	for (int i = 2; ; i++) {
		long long temp = x % y;
		q = x / y;
		x = y;
		y = temp;

		if (y == 0)	break;

		s.push_back(s[i - 2] - s[i - 1] * q);
		t.push_back(t[i - 2] - t[i - 1] * q);
	}
	return x;
}

int main(void) {
	FIO;

	cin >> N >> A;
	cout << N - A << " ";

	if (gcd(N, A) == 1) {
		long long m = t.back();
		if (m < 0)
			m += N;
		cout << m;
	}
	else
		cout << -1;
}