/*
D. Buying Shovels
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Polycarp wants to buy exactly n shovels. The shop sells packages with shovels. The store has k types of packages: the package of the i-th type consists of exactly i shovels (1≤i≤k). The store has an infinite number of packages of each type.

Polycarp wants to choose one type of packages and then buy several (one or more) packages of this type. What is the smallest number of packages Polycarp will have to buy to get exactly n shovels?

For example, if n=8 and k=7, then Polycarp will buy 2 packages of 4 shovels.

Help Polycarp find the minimum number of packages that he needs to buy, given that he:

will buy exactly n shovels in total;
the sizes of all packages he will buy are all the same and the number of shovels in each package is an integer from 1 to k, inclusive.
Input
The first line contains an integer t (1≤t≤100) — the number of test cases in the input. Then, t test cases follow, one per line.

Each test case consists of two positive integers n (1≤n≤109) and k (1≤k≤109) — the number of shovels and the number of types of packages.

Output
Print t answers to the test cases. Each answer is a positive integer — the minimum number of packages.

풀이:
1. k가 n보다 크거나 같다면 1을 출력합니다.
2. n이 소수인지 판별합니다.(n의 제곱근보다 작거나 같은 수들로 나누어 보면 됩니다.)
소수라면 n을 그대로 출력합니다.(나눌 수 있는 k가 1밖에 없음)

소수가 아니라면, n의 제곱근보다 작거나 같은 수들 중 n을 나눌 수 있는 수를 찾습니다.
이 때, n을 나눌 수 있다면 두 가지 경우가 있습니다.(나누는 수를 i라 하면 - i는 2부터 시작)

n / i 가 k 이하일 때 -> i가 정답이 되므로 바로 출력합니다.(k개를 i 번 사면 되므로, i는 작은 수부터 시작하므로 가장 최선)

n / i 가 k보다 클 때 -> k개를 살 수 없지만 가능성이 있습니다. i 가 k이하라면 (n / i)개를 살 수 있으므로 (n / i)가 
정답 후보가 될 수 있습니다.
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
#define pic pair<int, char>
#define ll long long
#define vi vector<int>
#define vl vector<long long>
#define vii vector<pii>
#define IMAX 2000000001
#define LMAX 1000000000000000000
#define DMAX 0xFFFFFFFFFFFFF
int mv1[4] = { 0, 1, 0, -1 };
int mv2[4] = { 1, 0, -1, 0 };

int t, n, k;

int main(void) {
	FIO;

	cin >> t;

	while (t--) {
		cin >> n >> k;

		int ans = n;
		bool isPrime = true;

		if (n <= k) {
			cout << "1\n";
			continue;
		}

		for (int i = sqrt(n); i > 1 ; i--)
		{
			if (n % i == 0)
				isPrime = false;
		}
		
		if (isPrime) {
			cout << n << "\n";
		}
		else {
			for (int i = 2; i <= sqrt(n); i++)
			{
				if (n % i == 0) {
					if (n / i > k) {
						if (i <= k) {
							ans = min(ans, n / i);
						}
						continue;
					}
					ans = i;
					break;
				}
			}
			cout << ans << "\n";
		}
	}
}