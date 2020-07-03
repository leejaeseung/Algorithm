/*
. A Simple Task
time limit per test5 seconds
memory limit per test512 megabytes
inputstandard input
outputstandard output
This task is very simple. Given a string S of length n and q queries each query is on the format i j k which means sort the substring consisting of the characters from i to j in non-decreasing order if k = 1 or in non-increasing order if k = 0.

Output the final string after applying the queries.

Input
The first line will contain two integers n, q (1 ≤ n ≤ 105, 0 ≤ q ≤ 50 000), the length of the string and the number of queries respectively.

Next line contains a string S itself. It contains only lowercase English letters.

Next q lines will contain three integers each i, j, k (1 ≤ i ≤ j ≤ n, ).

Output
Output one line, the string S after applying the queries.

풀이:
레이지 프로퍼게이션 문제입니다.

각 알파벳마다 자신이 어느 구간에 있는 지 1로 체크를 해줍니다.
(정렬한다는 의미는 a부터 시작하여 해당 구간의 맨 앞부터 1을 채운다는 의미입니다. - 해당 구간의 알파벳 개수만큼)
그리고 기존 알파벳의 1로 체크되어 있던 건 0으로 바꿔줍니다.(뒤로 밀렸기 때문에)

마지막 출력 시에는 leaf 노드들을 모두 보면서 1인 경우 해당 알파벳을 출력하면 됩니다.
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
string str;
int tree[26][400005];
int lazy[26][400005];
int out[100005];
int cnt[26];

void init(int alpha, int now, int s, int e) {
	lazy[alpha][now] = -1;
	if (s == e) {
		if (str[s - 1] - 'a' == alpha) {
			tree[alpha][now] = 1;
		}
		return;
	}

	init(alpha, now * 2, s, (s + e) / 2);
	init(alpha, now * 2 + 1, (s + e) / 2 + 1, e);
	
	tree[alpha][now] = tree[alpha][now * 2] + tree[alpha][now * 2 + 1];
}

void propagate(int alpha, int now, int s, int e) {
	if (lazy[alpha][now] != -1) {

		if (s != e) {
			lazy[alpha][now * 2] = lazy[alpha][now];
			lazy[alpha][now * 2 + 1] = lazy[alpha][now];
		}

		tree[alpha][now] = lazy[alpha][now] * (e - s + 1);
		lazy[alpha][now] = -1;
	}
}

int get(int alpha, int now, int s, int e, int l, int r) {
	propagate(alpha, now, s, e);

	if (r < s || l > e)	return 0;
	if (l <= s && r >= e)
		return tree[alpha][now];

	return get(alpha, now * 2, s, (s + e) / 2, l, r) + get(alpha, now * 2 + 1, (s + e) / 2 + 1, e, l, r);
}

void update(int alpha, int now, int s, int e, int l, int r, int v) {
	propagate(alpha, now, s, e);

	if (r < s || l > e)	return;
	if (l <= s && r >= e) {

		lazy[alpha][now] = v;
		propagate(alpha, now, s, e);
		return;
	}

	update(alpha, now * 2, s, (s + e) / 2, l, r, v);
	update(alpha, now * 2 + 1, (s + e) / 2 + 1, e, l, r, v);

	tree[alpha][now] = tree[alpha][now * 2] + tree[alpha][now * 2 + 1];
}

int main(void) {
	FIO;

	cin >> n >> q >> str;

	for (int i = 0; i < 26; i++)
	{
		init(i, 1, 1, n);
	}
	
	for (int j = 0; j < q; j++)
	{
		int l, r, k;
		cin >> l >> r >> k;

		if (k == 1) {
			for (int i = 0; i < 26; i++)
			{
				cnt[i] = get(i, 1, 1, n, l, r);
				update(i, 1, 1, n, l, r, 0);
			}
			for (int i = 0; i < 26; i++)
			{
				if (cnt[i] != 0) {
					update(i, 1, 1, n, l, l + cnt[i] - 1, 1);
					l = l + cnt[i];
					cnt[i] = 0;
				}
			}
		}
		else {
			for (int i = 0; i < 26; i++)
			{
				cnt[i] = get(i, 1, 1, n, l, r);
				update(i, 1, 1, n, l, r, 0);
			}
			for (int i = 25; i >= 0; i--)
			{
				if (cnt[i] != 0) {
					update(i, 1, 1, n, l, l + cnt[i] - 1, 1);
					l = l + cnt[i];
					cnt[i] = 0;
				}
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			if (get(j, 1, 1, n, i, i) > 0)	cout << (char)(j + 'a');
		}
	}
}