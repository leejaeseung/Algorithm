/*
문제
n부터 m까지 숫자를 하나씩 종이에 작성할 때, 숫자 0을 몇 번 쓰는지 구하는 프로그램을 작성하시오.

입력
입력은 여러개의 테스트 케이스로 이루어져 있다. 각 테스트 케이스는 두 정수 n과 m이 공백으로 되어있으며, 한 줄로 이루어져 있다. 입력의 마지막 줄은 n값이 음수이고, 이 경우는 계산할 필요 없이 프로그램을 종료하면 된다.

출력
각 테스트 케이스에 대해서, 0을 몇 번 쓰는지 출력한다.

풀이:
1019_책 페이지 문제에서 0의 개수만 출력하는 문제였습니다.
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