/*
C. Circular RMQ
time limit per test1.5 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given circular array a 0, a 1, ..., a n - 1. There are two types of operations with it:

inc(lf, rg, v) — this operation increases each element on the segment [lf, rg] (inclusively) by v;
rmq(lf, rg) — this operation returns minimal value on the segment [lf, rg] (inclusively).
Assume segments to be circular, so if n = 5 and lf = 3, rg = 1, it means the index sequence: 3, 4, 0, 1.

Write program to process given sequence of operations.

Input
The first line contains integer n (1 ≤ n ≤ 200000). The next line contains initial state of the array: a 0, a 1, ..., a n - 1 ( - 106 ≤ a i ≤ 106), a i are integer. The third line contains integer m (0 ≤ m ≤ 200000), m — the number of operartons. Next m lines contain one operation each. If line contains two integer lf, rg (0 ≤ lf, rg ≤ n - 1) it means rmq operation, it contains three integers lf, rg, v (0 ≤ lf, rg ≤ n - 1; - 106 ≤ v ≤ 106) — inc operation.

Output
For each rmq operation write result for it. Please, do not use %lld specificator to read or write 64-bit integers in C++. It is preffered to use cout (also you may use %I64d).

풀이:
세그먼트 트리 응용 문제입니다.

최소값 세그먼트 트리를 사용하는데, 구간을 증가시키는 쿼리가 있기 때문에 주의해야 합니다.
모든 노드들은 자신의 구간이 얼마나 증가했는지를 누적해서 가지고 있게 됩니다.
자식 구간들은 어차피 자신의 증가값만큼 증가하기 때문에 업데이트 시 더 내려갈 필요가 없습니다.
(증가값만 갱신해 줍니다.)
노드의 최소값은 현재 최소값 + 증가값 이 됩니다.
lazy propagation과 비슷한 느낌?입니다.
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
#define pic pair<int, char>
#define ll long long
#define vi vector<int>
#define vl vector<long long>
#define vii vector<pii>
#define IMAX 2000000001
#define LMAX 100000000000000
int mv1[4] = { 0, 0, 1, -1 };
int mv2[4] = { 1, -1, 0, 0 };

ll tree[900001];
ll inc[9000001];
int n, m;

void update(int now, int s, int e, int l, int r, ll v) {
	if (r < s || e < l)	return;
	if (l <= s && e <= r) {
		inc[now] += v;
		return;
	}
	if (s == e) {
		tree[now] += v;
		return;
	}

	update(now * 2, s, (s + e) / 2, l, r, v);
	update(now * 2 + 1, (s + e) / 2 + 1, e, l, r, v);
	tree[now] = min(tree[now * 2] + inc[now * 2], tree[now * 2 + 1] + inc[now * 2 + 1]);
}

ll getMin(int now, int s, int e, int l, int r) {
	if (r < s || e < l)	return LMAX;
	if (l <= s && e <= r)	return tree[now] + inc[now];

	return min(getMin(now * 2, s, (s + e) / 2, l, r), getMin(now * 2 + 1, (s + e) / 2 + 1, e, l, r)) + inc[now];
}

int main(void) {
	FIO;
	
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		ll v;
		cin >> v;

		update(1, 0, n - 1, i, i, v);
	}

	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int l, r, c;
		ll v = LMAX;
		cin >> l >> r;

		if (cin.get() != '\n')
			cin >> v;

		if (v == LMAX) {
			if (l > r) {
				cout << min(getMin(1, 0, n - 1, l, n - 1), getMin(1, 0, n - 1, 0, r)) << "\n";
			}
			else {
				cout << getMin(1, 0, n - 1, l, r) << "\n";
			}
		}
		else {
			if (l > r) {
				update(1, 0, n - 1, l, n - 1, v);
				update(1, 0, n - 1, 0, r, v);
			}
			else {
				update(1, 0, n - 1, l, r, v);
			}
		}
	}
}