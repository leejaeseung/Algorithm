/*
C. Little Girl and Maximum Sum
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
The little girl loves the problems on array queries very much.

One day she came across a rather well-known problem: you've got an array of n elements (the elements of the array are indexed starting from 1); also, there are q queries, each one is defined by a pair of integers li, ri (1 ≤ li ≤ ri ≤ n). You need to find for each query the sum of elements of the array with indexes from li to ri, inclusive.

The little girl found the problem rather boring. She decided to reorder the array elements before replying to the queries in a way that makes the sum of query replies maximum possible. Your task is to find the value of this maximum sum.

Input
The first line contains two space-separated integers n (1 ≤ n ≤ 2·105) and q (1 ≤ q ≤ 2·105) — the number of elements in the array and the number of queries, correspondingly.

The next line contains n space-separated integers ai (1 ≤ ai ≤ 2·105) — the array elements.

Each of the following q lines contains two space-separated integers li and ri (1 ≤ li ≤ ri ≤ n) — the i-th query.

Output
In a single line print a single integer — the maximum sum of query replies after the array elements are reordered.

Please, do not use the %lld specifier to read or write 64-bit integers in С++. It is preferred to use the cin, cout streams or the %I64d specifier.

풀이:
그리디 + 세그먼트 트리 + 레이지 프로퍼게이션으로 풀이했습니다.

최적의 해를 구하는 법은 간단합니다.
모든 쿼리를 받아본 다음, 겹치는 부분을 세고,
겹친 수가 가장 많은 곳에 제일 큰 숫자를 놓으면 됩니다.
두 번째로 많은 곳에 두 번째로 큰 숫자...n개의 수에 대해 계산하면 됩니다.

쿼리를 하나씩 볼 때마다 그 구간의 카운트를 세게 되면 200000 * 200000 번이므로 시간 초과가 나게 됩니다.
따라서 세그먼트 트리 + 레이지 프로퍼게이션을 이용해 각 구간의 합을 저장합니다.

쿼리를 받을 때마다 해당 구간을 +1 업데이트 해주면 됩니다.
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
#define IMAX 2000000001
#define LMAX 1000000000000000000
#define DMAX 0xFFFFFFFFFFFFF
int mv1[4] = { 0, 1, 0, -1 };
int mv2[4] = { 1, 0, -1, 0 };

int n, q;
int tree[8000005];
int lazy[8000005];
priority_queue<ll> pq;
priority_queue<ll> cnt;

void propagate(int now, int s, int e) {
	if (lazy[now] != 0) {

		if (s != e) {
			lazy[now * 2] += lazy[now];
			lazy[now * 2 + 1] += lazy[now];
		}

		tree[now] += (e - s + 1) * lazy[now];
		lazy[now] = 0;
	}
}

void update(int now, int s, int e, int l, int r, int v) {
	propagate(now, s, e);

	if (s > r || e < l)	return;
	if (l <= s && r >= e) {
		lazy[now] += v;

		propagate(now, s, e);
		return;
	}

	update(now * 2, s, (s + e) / 2, l, r, v);
	update(now * 2 + 1, (s + e) / 2 + 1, e, l, r, v);

	tree[now] = tree[now * 2] + tree[now * 2 + 1];
}

void get(int now, int s, int e, int idx) {
	propagate(now, s, e);

	if (idx > e || idx < s)	return;
	if (s == e) {
		cnt.push(tree[now]);
		return;
	}

	get(now * 2, s, (s + e) / 2, idx);
	get(now * 2 + 1, (s + e) / 2 + 1, e, idx);
}

int main(void) {
	FIO;

	cin >> n >> q;

	for (int i = 0; i < n; i++)
	{
		ll v;
		cin >> v;
		pq.push(v);
	}

	for (int i = 0; i < q; i++)
	{
		int l, r;
		cin >> l >> r;

		update(1, 1, n, l, r, 1);
	}

	for (int i = 1; i <= n; i++)
	{
		get(1, 1, n, i);
	}

	ll sum = 0;

	for (int i = 0; i < n; i++)
	{
		sum += pq.top() * cnt.top();
		pq.pop();	cnt.pop();
	}

	cout << sum;
}