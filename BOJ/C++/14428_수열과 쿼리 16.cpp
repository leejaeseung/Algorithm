/*
����
���̰� N�� ���� A1, A2, ..., AN�� �־�����. �̶�, ���� ������ �����ϴ� ���α׷��� �ۼ��Ͻÿ�.

1 i v : Ai�� v�� �ٲ۴�.
2 i j : Ai, Ai+1, ..., Aj���� ũ�Ⱑ ���� ���� ���� �ε����� ����Ѵ�. �׷��� ���� �������� ��쿡�� �ε����� ���� ���� ����Ѵ�.
������ �ε����� 1���� �����Ѵ�.

�Է�
ù° �ٿ� ������ ũ�� N�� �־�����. (1 �� N �� 100,000)

��° �ٿ��� A1, A2, ..., AN�� �־�����. (1 �� Ai �� 109)

��° �ٿ��� ������ ���� M�� �־�����. (1 �� M �� 100,000)

��° �ٺ��� M���� �ٿ��� ������ �־�����.

���
2�� ������ ���ؼ� ������ �� �ٿ� �ϳ��� ������� ����Ѵ�.

Ǯ��:
������ �ּڰ� ���׸�Ʈ Ʈ�� ����. 
*/
#include<iostream>
#include<memory.h>
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
int mv1[4] = { 0, 0, 1, -1 };
int mv2[4] = { 1, -1, 0, 0 };
int mv_all1[8] = { 0, 1, 0, -1, -1, -1, 1, 1 };
int mv_all2[8] = { 1, 0, -1, 0 , -1, 1, -1, 1 };

int n, m;
pii tree[500001];

pii update(int now, int s, int e, int idx, int v) {
	if (idx < s || idx > e)	return tree[now];
	if (s == e) {
		return tree[now] = make_pair(v, idx);
	}

	pii left = update(now * 2, s, (s + e) / 2, idx, v);
	pii right = update(now * 2 + 1, (s + e) / 2 + 1, e, idx, v);

	if (left.first <= right.first)
		return tree[now] = left;
	else
		return tree[now] = right;
}

pii get(int now, int s, int e, int l, int r) {
	if (l > e || r < s)	return make_pair(IMAX, -1);
	if (l <= s && r >= e)	return tree[now];
	if (s == e) {
		return tree[now];
	}

	pii left = get(now * 2, s, (s + e) / 2, l, r);
	pii right = get(now * 2 + 1, (s + e) / 2 + 1, e, l, r);

	if (left.first <= right.first)
		return left;
	else
		return right;
}

int main(void) {
	FIO;

	cin >> n;

	for (int i = 0; i < 500000; i++)
	{
		tree[i] = make_pair(IMAX, -1);
	}

	for (int i = 1; i <= n; i++)
	{
		int v;
		cin >> v;
		update(1, 1, n, i, v);
	}

	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int q, a, b;
		cin >> q >> a >> b;

		if (q == 1) {
			update(1, 1, n, a, b);
		}
		else {
			cout << get(1, 1, n, a, b).second << "\n";
		}
	}
}