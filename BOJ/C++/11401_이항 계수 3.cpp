/*
문제
자연수 과 정수 가 주어졌을 때 이항 계수 를 1,000,000,007로 나눈 나머지를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 과 가 주어진다. (1 ≤  ≤ 4,000,000, 0 ≤  ≤ )

출력
 를 1,000,000,007로 나눈 나머지를 출력한다.

 입력이 4000000 이므로 Nlog(N) 의 풀이로 풀어야 하는 문제입니다.
 페르마의 소정리를 참고하여 풀이했습니다.

 https://kyunstudio.tistory.com/60
*/
#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<vector>
#include<bitset>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pii pair<int, int>;

int N, K;
long long divide = 1000000007;

long long myPow(long long x, int n) {
	if (n == 1)
		return x % divide;

	long long temp = myPow(x, n / 2);
	if (n % 2 == 0) {
		return ((temp % divide) * (temp % divide)) % divide;
	}
	else {
		return ((((temp % divide) * (temp % divide)) % divide) * (x % divide)) % divide;
	}
}

long long factorial(long long x) {
	long long ret = 1;
	for (int i = 1; i <= x; i++)
	{
		ret = ((ret % divide) * (i % divide)) % divide;
	}
	return ret % divide;
}

int main(void) {
	FIO;

	cin >> N >> K;
	
	cout << ((factorial(N) % divide) * (myPow(((factorial(K) % divide) * (factorial(N - K) % divide)) % divide, divide - 2) % divide)) % divide;
}