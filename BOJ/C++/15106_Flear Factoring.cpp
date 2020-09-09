/*
문제
The Slivians are afraid of factoring; it’s just, well, difficult.

Really, they don’t even care about the factors themselves, just how much they sum to.

We can define F(n) as the sum of all of the factors of n; so F(6) = 12 and F(12) = 28. Your task is, given two integers a and b with a ≤ b, to calculate

입력
The input consists of a single line containing space-separated integers a and b (1 ≤ a ≤ b ≤ 1012; b − a ≤ 106).

출력
Print S on a single line.

풀이:
답지 참고
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

unsigned ll a, b;

unsigned ll getSum(unsigned ll s, unsigned ll e) {
	return (e + s + 1) * (e - s) / 2;
}

int main(void) {
	FIO;

	cin >> a >> b;

	unsigned ll sum = 0;

	unsigned ll sq = sqrt(b);

	for (ll i = 1; i <= sq; i++)
	{
		sum += i * (b / i - (a - 1) / i) + getSum(max(sq, (a - 1) / i), max(sq, b / i));
	}

	cout << sum;
}