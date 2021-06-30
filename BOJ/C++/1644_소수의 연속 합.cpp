/*
문제
하나 이상의 연속된 소수의 합으로 나타낼 수 있는 자연수들이 있다. 몇 가지 자연수의 예를 들어 보면 다음과 같다.

3 : 3 (한 가지)
41 : 2+3+5+7+11+13 = 11+13+17 = 41 (세 가지)
53 : 5+7+11+13+17 = 53 (두 가지)
하지만 연속된 소수의 합으로 나타낼 수 없는 자연수들도 있는데, 20이 그 예이다. 7+13을 계산하면 20이 되기는 하나 7과 13이 연속이 아니기에 적합한 표현이 아니다. 또한 한 소수는 반드시 한 번만 덧셈에 사용될 수 있기 때문에, 3+5+5+7과 같은 표현도 적합하지 않다.

자연수가 주어졌을 때, 이 자연수를 연속된 소수의 합으로 나타낼 수 있는 경우의 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 자연수 N이 주어진다. (1 ≤ N ≤ 4,000,000)

출력
첫째 줄에 자연수 N을 연속된 소수의 합으로 나타낼 수 있는 경우의 수를 출력한다.

풀이:
에라토스테네스의 체로 소수를 모두 구해 배열에 넣고, 연속된 소수들의 시작과 끝을 left, right 투 포인터를 이용해 탐색한다.

연속된 소수들의 합이 N 보다 작으면 right++, N보다 크다면 left++ 해가며 탐색하면 된다.
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
#define vc vector<char>
#define vii vector<pii>
#define IMAX 2147483647
#define LMAX 1000000000000500000
#define DMAX 0xFFFFFFFFFFFFF
int mv1[4] = { 0, 1, -1, 0 };
int mv2[4] = { 1, 0, 0, -1 };

int n;
bool prime_check[4000001];
vector<int> prime;

void getPrime() {
	prime_check[1] = true;

	for (int i = 2; i <= sqrt(4000000); i++)
	{
		for (int j = 2; i * j <= 4000000; j++)
		{
			prime_check[i * j] = true;
		}
	}

	for (int i = 2; i <= 4000000; i++)
	{
		if (!prime_check[i]) {
			prime.push_back(i);
		}
	}
}

int main() {
	FIO;

	cin >> n;

	getPrime();

	int left = 0;
	int right = 0;
	int sum = prime[0];

	int count = 0;

	while (right < prime.size() - 1) {

		if (sum == n) {
			count++;
		}
		else if (sum > n) {
			sum -= prime[left];
			left++;
			continue;
		}
		right++;
		sum += prime[right];
	}

	if (sum == n)	count++;

	cout << count;
}