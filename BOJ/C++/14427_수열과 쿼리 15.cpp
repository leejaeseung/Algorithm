/*
����
���̰� N�� ���� A1, A2, ..., AN�� �־�����. �̶�, ���� ������ �����ϴ� ���α׷��� �ۼ��Ͻÿ�.

1 i v : Ai�� v�� �ٲ۴�. (1 �� i �� N, 1 �� v �� 109)
2 : �������� ũ�Ⱑ ���� ���� ���� �ε����� ����Ѵ�. �׷��� ���� �������� ��쿡�� �ε����� ���� ���� ����Ѵ�.
������ �ε����� 1���� �����Ѵ�.

�Է�
ù° �ٿ� ������ ũ�� N�� �־�����. (1 �� N �� 100,000)

��° �ٿ��� A1, A2, ..., AN�� �־�����. (1 �� Ai �� 109)

��° �ٿ��� ������ ���� M�� �־�����. (1 �� M �� 100,000)

��° �ٺ��� M���� �ٿ��� ������ �־�����.

���
2�� ������ ���ؼ� ������ �� �ٿ� �ϳ��� ������� ����Ѵ�.

Ǯ��:
�ּҰ� ���׸�Ʈ Ʈ���� �ۼ��մϴ�.
�ε����� ����ؾ� �ϹǷ�, ���׸�Ʈ Ʈ���� �ε����� �����մϴ�.
*/

#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pii pair<int, int>

int N, Q;
int tree[500010];
int list[100001];

int update(int now, int l, int r, int idx) {
	if (l > idx || r < idx)	return tree[now];
	if (l == r) {
		return tree[now] = idx;
	}
	int left = update(now * 2, l, (l + r) / 2, idx);
	int right = update(now * 2 + 1, (l + r) / 2 + 1, r, idx);

	if (list[left] < list[right])
		tree[now] = left;
	else if (list[left] == list[right]) {
		if (left < right)
			tree[now] = left;
		else
			tree[now] = right;
	}
	else
		tree[now] = right;
	return tree[now];
}

int main(void) {
	FIO;

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		int v;
		cin >> v;

		list[i] = v;
	}
	for (int i = 1; i <= N ; i++)
	{
		update(1, 1, N, i);
	}
	cin >> Q;

	for (int i = 0; i < Q; i++)
	{
		int q, a, b;
		cin >> q;

		if (q == 1) {
			cin >> a >> b;

			list[a] = b;
			update(1, 1, N, a);
		}
		else {
			cout << tree[1] << "\n";
		}
	}
	
}