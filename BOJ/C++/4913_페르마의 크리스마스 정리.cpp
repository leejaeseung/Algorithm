/*
문제
1640년 12월 25일, 위대한 수학자 피에르 드 페르마는 마랭 메르센에게 다음과 같은 내용의 편지를 썼다.

I just proved that an odd prime p is expressible as p = a2 + b2 if and only if p is expressible as p = 4c + 1.
편지에는 증명은 포함되어 있지 않았고, 100년후에 오일러가 증명했다. 5, 13, 17, 41은 두 제곱수의 합으로 나타낼 수 있다.

5=22+11 13=32+22 17=42+12 41=52+42

하지만, 11, 19, 23, 31은 제곱수의 합으로 나타낼 수 없다.

어떤 구간이 주어졌을 때, 이 구간에 포함되어 있는 소수를 제곱수의 합으로 나타낼 수 있는 경우의 수를 구하는 프로그램을 작성하시오.

입력
입력은 여러 개의 테스트 케이스로 이루어져 있다. 각 테스트 케이스는 한 줄로 이루어져 있고, L과 U가 공백으로 구분되어 주어진다. (L ≤ U < 1,000,000)

입력의 마지막 줄은 L과 U가 -1이다.

출력
각 테스트 케이스에 대해서, 한 줄에 L U x y를 출력한다. 여기서 L과 U는 입력으로 주어진 값이고, x는 구간 [L,U]에 포함된 소수의 개수, y는 [L,U]에 포함된 소수중 제곱수의 합으로 나타낼 수 있는 것의 개수이다.

풀이:
에라토스테네스의 체로 소수 배열을 만들고, 소수를 제곱수 둘의 합으로 나타낼 수 있는지 여부는
a == 2 || a % 4 == 1 로 찾아날 수 있다.(a 가 소수일 때)

그런데 테스트케이스마다 1초가 아니라 전체 테스트케이스가 1초안에 돌아야 해서
반복문을 이용해 L ~ U 까지 배열로 판단하니 시간 초과가 났고, L과 U가 음수인 경우도 처리해 주어야 했다.
소수, 제곱수의 합으로 된 소수 두 개의 벡터를 만들고, 이분 탐색으로 L, U 사이에 있는 개수를 구해 주었다.
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