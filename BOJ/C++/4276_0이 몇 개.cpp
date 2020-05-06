/*
����
n���� m���� ���ڸ� �ϳ��� ���̿� �ۼ��� ��, ���� 0�� �� �� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
�Է��� �������� �׽�Ʈ ���̽��� �̷���� �ִ�. �� �׽�Ʈ ���̽��� �� ���� n�� m�� �������� �Ǿ�������, �� �ٷ� �̷���� �ִ�. �Է��� ������ ���� n���� �����̰�, �� ���� ����� �ʿ� ���� ���α׷��� �����ϸ� �ȴ�.

���
�� �׽�Ʈ ���̽��� ���ؼ�, 0�� �� �� ������ ����Ѵ�.

Ǯ��:
1019_å ������ �������� 0�� ������ ����ϴ� ���������ϴ�.
*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<vector>
#include<set>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>
#define ll long long

ll N, M;
ll ans = 0;

void add(ll n, ll mul) {
	while (n > 0) {
		if(n % 10 == 0)
			ans += mul;
		n /= 10;
	}
}

void cnt(ll A, ll B, ll mul) {
	

	while (A <= B && A % 10 != 0) {
		add(A, mul);
		A++;
	}
	
	if (A > B)	return;

	while (A <= B && B % 10 != 9) {
		add(B, mul);
		B--;
	}
	

	ans += (B / 10 - A / 10 + 1) * mul;

	cnt(A / 10, B / 10, mul * 10);
}

int main(void) {
	FIO;

	while (true) {
		cin >> N;

		ans = 0;

		if (N == -1)	break;

		cin >> M;

		if (N == 0) {
			ans++;
			N = 1;
		}
		cnt(N, M, 1);

		cout << ans << "\n";
	}
}