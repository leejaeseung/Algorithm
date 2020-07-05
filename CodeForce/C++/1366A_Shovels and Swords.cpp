/*
A. Shovels and Swords
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Polycarp plays a well-known computer game (we won't mention its name). In this game, he can craft tools of two types — shovels and swords. To craft a shovel, Polycarp spends two sticks and one diamond; to craft a sword, Polycarp spends two diamonds and one stick.

Each tool can be sold for exactly one emerald. How many emeralds can Polycarp earn, if he has a sticks and b diamonds?

Input
The first line contains one integer t (1≤t≤1000) — the number of test cases.

The only line of each test case contains two integers a and b (0≤a,b≤109) — the number of sticks and the number of diamonds, respectively.

Output
For each test case print one integer — the maximum number of emeralds Polycarp can earn.

풀이:

maxv = 2개씩 사고 남은 수 (a, b 중 큰 값에 대해)
minv = 1개씩 사고 남은 수 (a, b 중 작은 값에 대해)

minv 가 0보다 작거나 같다면 더 이상 구매할 수 없으므로 결국 a, b 중 더 작은 값에 대해 1개씩만 구매하는게 최선입니다.

minv 가 0보다 크다면 더 구매할 수 있는데, 위에서 maxv와 minv 는 같은 값인 상태입니다.(큰 값에서 2개씩, 작은 값에서 1개씩 뺴서 서로 개수 차이만큼 빼줬기 때문에)
경우는 1 1, 2 2, 3 3, 4 4 등등이 있는데 여기서 3 3 같은 경우 2 1, 1 2로 사는 게 최선입니다. 따라서 3으로 나눈 값에 * 2 를 더해주면 됩니다.
5 5 같은 경우 3으로 나눠주고, 2 2 가 남기 때문에 + 1을 더 해주면 됩니다.
*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>
#define pdd pair<double, double>
#define pil pair<int, long long>
#define pli pair<long long, int>
#define ll long long
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vii vector<pii>
#define IMAX 2000000001
#define LMAX 9000000000000000000
#define DMAX 0xFFFFFFFFFFFFF
int mv1[4] = { 0, 1, 0, -1 };
int mv2[4] = { 1, 0, -1, 0 };

int a, b, q;

int main(void) {
	FIO;

	cin >> q;

	while (q--) {
		cin >> a >> b;

		int ans = abs(a - b);

		int maxv = max(a, b) - ans * 2;
		int minv = min(a, b) - ans;

		if (0 >= minv)
			cout << min(a, b) << "\n";
		else {
			ans += ((maxv / 3) * 2);
			maxv %= 3;
			ans += maxv / 2;
			cout << ans << "\n";
		}
	}
}