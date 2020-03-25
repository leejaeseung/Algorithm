/*
문제
집합 Zn을 0부터 n-1까지의 정수 집합이라고 하자. Zn ∋ a, b 일 때, (a+b) mod n = 0이면 b는 a의 덧셈역이라고 하고 (a*c) mod n = 1이면 c는 a의 곱셈역이라고 한다.

정수 N, A가 주어졌을 때 Zn에서의 A의 덧셈역과 곱셈역을 구하시오.

단, 곱셈역을 구할 수 없으면 -1을 출력한다.

입력
첫 번째 줄에 N(2 ≤ N ≤ 1012)과 A(1 ≤ A < N)이 주어진다..

출력
첫 번째 줄에 A의 N에 대한 덧셈역과 곱셈역을 한 줄에 공백으로 구분하여 출력한다.

풀이:
확장 유클리드 호제법을 이용해 풀이했습니다.
덧셈의 역원은 N - A 이고,

N 과 A에 대해 최대 공약수를 구하면서, 확장 유클리드 호제법에 의해 구해진 최종 t 가 답이 됩니다.(t가 음수값이 나오면 N을 더해 양수로 만들어 줍니다.)
최대 공약수가 1이 아닌 경우 N 과 A가 서로소가 아니므로 -1을 출력합니다.
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