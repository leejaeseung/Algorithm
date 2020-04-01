/*
B. Anton and Digits
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Recently Anton found a box with digits in his room. There are k2 digits 2, k3 digits 3, k5 digits 5 and k6 digits 6.

Anton's favorite integers are 32 and 256. He decided to compose this integers from digits he has. He wants to make the sum of these integers as large as possible. Help him solve this task!

Each digit can be used no more than once, i.e. the composed integers should contain no more than k2 digits 2, k3 digits 3 and so on. Of course, unused digits are not counted in the sum.

Input
The only line of the input contains four integers k2, k3, k5 and k6 — the number of digits 2, 3, 5 and 6 respectively (0 ≤ k2, k3, k5, k6 ≤ 5·106).

Output
Print one integer — maximum possible sum of Anton's favorite integers that can be composed using digits from the box.

문제 설명:
순서대로 안톤이 가지고 있는 2, 3, 5, 6 의 개수가 주어집니다.
위 숫자를 조합해서 256, 32 만 만들 수 있습니다.
조합한 숫자들의 합의 최대값을 구합니다.

풀이:
그리디하게 256을 먼저 만들고, 남은 수들로 32를 만들면 쉽게 풀이할 수 있습니다.

*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<vector>
#include<stack>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>

int cnt[7];

int main(void) {
	FIO;

	cin >> cnt[2];
	cin >> cnt[3];
	cin >> cnt[5];
	cin >> cnt[6];

	int cnt256 = min(cnt[2], min(cnt[5], cnt[6]));
	cnt[2] -= cnt256;
	cnt[5] -= cnt256;
	cnt[6] -= cnt256;
	int cnt32 = min(cnt[3], cnt[2]);

	cout << cnt256 * 256 + cnt32 * 32;
}