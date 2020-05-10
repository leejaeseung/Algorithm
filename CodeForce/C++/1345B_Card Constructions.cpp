/*
B. Card Constructions
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
A card pyramid of height 1 is constructed by resting two cards against each other. For h>1, a card pyramid of height h is constructed by placing a card pyramid of height h−1 onto a base. A base consists of h pyramids of height 1, and h−1 cards on top. For example, card pyramids of heights 1, 2, and 3 look as follows:


You start with n cards and build the tallest pyramid that you can. If there are some cards remaining, you build the tallest pyramid possible with the remaining cards. You repeat this process until it is impossible to build another pyramid. In the end, how many pyramids will you have constructed?

Input
Each test consists of multiple test cases. The first line contains a single integer t (1≤t≤1000) — the number of test cases. Next t lines contain descriptions of test cases.

Each test case contains a single integer n (1≤n≤109) — the number of cards.

It is guaranteed that the sum of n over all test cases does not exceed 109.

Output
For each test case output a single integer — the number of pyramids you will have constructed in the end.

풀이:
dp[x] = dp[x - 1] + (x - 1) * 2 + 2 + x - 1

위 식으로 대략 100000번 까지의 필요한 카드 수를 구해놓고,
현재 N보다 작거나 같은 수 중 가장 가까운 수를 계속해서 빼주면 됩니다.(이진 탐색을 이용)
*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<vector>
#include<queue>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>
#define ll long long

int T, N;
vector<ll> vt;

int main(void) {
	FIO;
	
	cin >> T;

	vt.push_back(2);
	vt.push_back(2);

	for (int i = 2; i < 100000; i++)
	{
		vt.push_back(vt[i - 1] + (i - 1) * 2 + 2 + i - 1);
	}

	while (T--) {
		cin >> N;

		int cnt = 0;

		while (N >= 2) {
			int idx = lower_bound(vt.begin(), vt.end(), N) - vt.begin();
			ll v = vt[idx];

			if (v > N)
				v = vt[idx - 1];
			
			N -= v;
			cnt++;
		}
		cout << cnt << "\n";
	}
}