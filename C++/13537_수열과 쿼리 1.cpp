/*
����
���̰� N�� ���� A1, A2, ..., AN�� �־�����. �̶�, ���� ������ �����ϴ� ���α׷��� �ۼ��Ͻÿ�.

i j k: Ai, Ai+1, ..., Aj�� �̷���� �κ� ���� �߿��� k���� ū ������ ������ ����Ѵ�.
�Է�
ù° �ٿ� ������ ũ�� N (1 �� N �� 100,000)�� �־�����.

��° �ٿ��� A1, A2, ..., AN�� �־�����. (1 �� Ai �� 109)

��° �ٿ��� ������ ���� M (1 �� M �� 100,000)�� �־�����.

��° �ٺ��� M���� �ٿ��� ���� i, j, k�� �� �ٿ� �ϳ��� �־�����. (1 �� i �� j �� N, 1 �� k �� 109)

���
������ �������� ������ �� �ٿ� �ϳ��� ����Ѵ�.

Ǯ��:
Merge Sort Tree �����Դϴ�. = ���׸�Ʈ Ʈ���� Merge Sort�� ��ģ ��.
https://justicehui.github.io/ps/2018/11/26/BOJ13537/
�� ��α׸� ������ Ǯ�����ϴ�.

��, ���׸�Ʈ Ʈ���� ��� ������ �ش��ϴ� ������ ������ ���ĵ� ���·� ���� �ְ� ����� �˴ϴ�.
*/

#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int N, Q;
vector<int> tree[500010];

void update(int now, int l, int r, int idx, int v) {
	if (l > idx || r < idx)	return;
	if (l == r) {
		tree[now].push_back(v);
		return;
	}
	tree[now].push_back(v);
	update(now * 2, l, (l + r) / 2, idx, v);
	update(now * 2 + 1, (l + r) / 2 + 1, r, idx, v);
}

int getMax(int now, int l, int r, int s, int e, int v) {
	if (r < s || l > e)	return 0;
	if (s <= l && r <= e) {
		return tree[now].end() - upper_bound(tree[now].begin(), tree[now].end(), v);
	}
	return getMax(now * 2, l, (l + r) / 2, s, e, v) + getMax(now * 2 + 1, (l + r) / 2 + 1, r, s, e, v);
}

int main(void) {
	FIO;

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		int v;
		cin >> v;

		update(1, 1, N, i, v);
	}
	for (int i = 0; i < 500010; i++)
	{
		sort(tree[i].begin(), tree[i].end());
	}
	cin >> Q;

	for (int i = 0; i < Q; i++)
	{
		int a, b, k;
		cin >> a >> b >> k;

		cout << getMax(1, 1, N, a, b, k) << "\n";
	}
}