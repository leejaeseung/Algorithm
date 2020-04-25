/*
문제
지민이는 N쪽인 책이 한권 있다. 첫 페이지는 1쪽이고, 마지막 페이지는 N쪽이다. 각 숫자가 모두 몇 번이 나오는지 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 N이 주어진다. N은 1,000,000,000보다 작거나 같은 자연수이다.

출력
첫째 줄에 0이 총 몇 번 나오는지, 1이 총 몇 번 나오는지, ..., 9가 총 몇 번 나오는지를 출력한다.

풀이:

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