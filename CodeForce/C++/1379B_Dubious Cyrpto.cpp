/*
B. Dubious Cyrpto
time limit per test1 second
memory limit per test512 megabytes
inputstandard input
outputstandard output
Pasha loves to send strictly positive integers to his friends. Pasha cares about security, therefore when he wants to send an integer n, he encrypts it in the following way: he picks three integers a, b and c such that l≤a,b,c≤r, and then he computes the encrypted value m=n⋅a+b−c.

Unfortunately, an adversary intercepted the values l, r and m. Is it possible to recover the original values of a, b and c from this information? More formally, you are asked to find any values of a, b and c such that

a, b and c are integers,
l≤a,b,c≤r,
there exists a strictly positive integer n, such that n⋅a+b−c=m.
Input
The first line contains the only integer t (1≤t≤20) — the number of test cases. The following t lines describe one test case each.

Each test case consists of three integers l, r and m (1≤l≤r≤500000, 1≤m≤1010). The numbers are such that the answer to the problem exists.

Output
For each test case output three integers a, b and c such that, l≤a,b,c≤r and there exists a strictly positive integer n such that n⋅a+b−c=m. It is guaranteed that there is at least one possible solution, and you can output any possible combination if there are multiple solutions.

풀이:
a, b, c 의 범위 l, r 이 주어지고, m 이 주어질 때, m = n * a + b - c 를 만족하는 a, b, c를 찾는 문제입니다.
(n은 어떤 양수 값이나 될 수 있습니다. 0 제외)

n이 어떤 값이든 될 수 있으므로, 결국 m을 a로 나눴을 때 나머지를 b - c로 채워줘야 하는 문제입니다.
a를 l ~ r 중 한 값으로 두고, m을 나눠보면서, 해당 나머지를 b - c 로 만들 수 있는지 확인하면 됩니다.

10 12 9 와 같은 경우, 위 식을 만족시키려면 n이 0이 될 수 없으므로, a = 10, n = 1 , 따라서 b - c 가 -1 이 되야 합니다.
10 12 19 도 비슷하게, a = 10, n = 2, b - c = -1 입니다.

b와 c 도 10 ~ 12 사이의 값이므로 b - c 만으로 나머지인 9를 만들 수 없기 때문에 n을 증가시키고, 뺴주어 9를 만든 것을 볼 수 있습니다.

m 값이 int 범위를 초과하는 것에 주의합니다. ㅡㅡ
*/
#include<iostream>
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
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vii vector<pii>
#define IMAX 2000000001
#define LMAX 1000000000000000000
#define DMAX 0xFFFFFFFFFFFFF
int mv1[4] = { 0, 1, 0, -1 };
int mv2[4] = { 1, 0, -1, 0 };

int t;

int main(void) {
	FIO;

	cin >> t;

	while (t--) {
		ll l, r, m;

		cin >> l >> r >> m;

		ll a, b, c;
		ll range = r - l;
		
		for (int i = l; i <= r; i++)
		{
			a = i;

			ll remain = m % a;
			remain = min(remain, a - remain);

			if (remain != m % a || a > m) {
				//나머지를 b - c 로 만들 수 없을 때
				remain = m % a;
				remain = a - remain;

				b = l;
				c = l + remain;

				if (c >= l && c <= r) {
					cout << a << " " << b << " " << c << "\n";
					break;
				}
			}
			else {
				b = l + remain;
				c = l;
				if (b >= l && b <= r) {
					cout << a << " " << b << " " << c << "\n";
					break;
				}
			}
		}
	}
}