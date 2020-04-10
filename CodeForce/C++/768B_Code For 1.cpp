/*
B. Code For 1
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Jon fought bravely to rescue the wildlings who were attacked by the white-walkers at Hardhome. On his arrival, Sam tells him that he wants to go to Oldtown to train at the Citadel to become a maester, so he can return and take the deceased Aemon's place as maester of Castle Black. Jon agrees to Sam's proposal and Sam sets off his journey to the Citadel. However becoming a trainee at the Citadel is not a cakewalk and hence the maesters at the Citadel gave Sam a problem to test his eligibility.

Initially Sam has a list with a single element n. Then he has to perform certain operations on this list. In each operation Sam must remove any element x, such that x > 1, from the list and insert at the same position , ,  sequentially. He must continue with these operations until all the elements in the list are either 0 or 1.

Now the masters want the total number of 1s in the range l to r (1-indexed). Sam wants to become a maester but unfortunately he cannot solve this problem. Can you help Sam to pass the eligibility test?

Input
The first line contains three integers n, l, r (0 ≤ n < 250, 0 ≤ r - l ≤ 105, r ≥ 1, l ≥ 1) – initial element and the range l to r.

It is guaranteed that r is not greater than the length of the final list.

Output
Output the total number of 1s in the range l to r in the final sequence.

풀이:
트리의 전체 길이를 먼저 구합니다. -> 재귀함수
트리를 왼쪽, 오른쪽으로 나눠가며 l, r의 범위에 포함되는지 여부에 따라 더 탐색할지를 결정합니다.

현재 노드의 s 보다 r이 작거나, e 보다 l이 크면 더 깊이 내려갈 필요가 없습니다.
범위에 포함되는 노드들만 1의 개수를 세어 리턴합니다.
*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<string.h>
#include<vector>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>

long long N, l, r;
long res = 0;
long long pos = 0;
long long leng = 0;

long long getLeng(long long now) {

	if (now == 1) {
		return 1;
	}
	if (now == 0) {
		return 1;
	}
	
	long long temp = getLeng(now / 2);
	long long pos = temp;

	if (pos >= l && pos <= r)
		res += now / 2;

	pos++;

	if (pos >= l && pos <= r)
		res += now % 2;

	pos += temp;

	if (pos >= l && pos <= r)
		res += now / 2;

	return pos;
}

long long recul(long long now, long long s, long long e) {
	long long mid = (s + e) / 2;
	if (s > r || e < l)	return 0;

	if (now == 1) {
		return 1;
	}
	if (now == 0) {
		return 0;
	}

	long long ret = 0;
	ret += recul(now / 2, s, mid - 1);
	
	if (l <= mid && r >= mid)
		ret += now % 2;
	ret += recul(now / 2, mid + 1, e);

	return ret;
}

int main(void) {
	FIO;

	cin >> N >> l >> r;

	leng = getLeng(N);

	cout << recul(N, 1, leng);
}