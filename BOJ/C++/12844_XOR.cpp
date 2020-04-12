/*
����
������ ��� �����ڵ� �����ڵ� �����. ���� �� ������ �ʹ� ģ���ϰԵ� ª��.

������ �־����� �� �� ������ ������ �����ؾ� �Ѵ�.

a�� b ���� (a, b�� ����) ������ �ִ� ��� ���ҿ� c�� xor �Ѵ�.
a�� b ���� (a, b�� ����) ������ �ִ� ��� ���Ҹ� xor �� ���� ����Ѵ�.
�ʱ� ������ ������ ������ �־����� ��, �׿� �°� ����Ѵ�.

�Է�
ù ��° �ٿ� ������ ũ�� n(0 < n �� 500,000)�� �־�����.

������ ���Ұ� 0������ n - 1 ������ ���ʴ�� �־�����. ������ ���Ҵ� 100,000���� �۰ų� ���� �ڿ��� �Ǵ� 0�̴�.

�� ��° �ٿ� �������� ������ ������ ���� m(0 < m �� 500,000)�� �־�����.

�� ���� m ���� �ٿ��� t, a, b, c�� �־�����. t�� 1�̸� ù ��° ������ ������ �����ؾ� �ϰ�, t�� 2�̸� �� ��° ������ ������ �����ؾ� �Ѵ�. (0 �� a, b < n, 0 �� c �� 100,000)

���
�� ��° ������ ������ �����Ѵ�.

Ǯ��:
���� �� ������ �����۰��̼ǰ� ���� ���� �����Դϴ�.

lazy ���� ������ �� ^ ������ ¦�� �� ���� �� ���� ��ȭ�� �����Ƿ� 
�ش� ����� ������ Ȧ�� ���� ������ ^ ������ ���ݴϴ�.

���� a, b ���� b > a �� �Է��� �ֽ��ϴ�.
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

int tree[2000000];
int lazy[2000000];
int N;

void propagate(int now, int l, int r) {
	if (lazy[now] != 0) {
		
		if (l != r) {
			lazy[now * 2] ^= lazy[now];
			lazy[now * 2 + 1] ^= lazy[now];
		}
		
		if((r - l + 1) % 2 == 1)
			tree[now] ^= lazy[now];
		
		lazy[now] = 0;
	}
}

void update(int now, int l, int r, int s, int e, int XOR) {
	propagate(now, l, r);

	if (e < l || s > r)	return;
	if (l >= s && e >= r) {
		lazy[now] ^= XOR;
		propagate(now, l, r);
		return;
	}
	update(now * 2, l, (l + r) / 2, s, e, XOR);
	update(now * 2 + 1, (l + r) / 2 + 1, r, s, e, XOR);

	tree[now] = tree[now * 2] ^ tree[now * 2 + 1];
}

int getXOR(int now, int l, int r, int s, int e) {
	propagate(now, l, r);

	if (e < l || s > r)		return 0;
	if (l >= s && e >= r)	return tree[now];

	return getXOR(now * 2, l, (l + r) / 2, s, e) ^ getXOR(now * 2 + 1, (l + r) / 2 + 1, r, s, e);
}


int main(void) {
	FIO;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int v;
		cin >> v;
		update(1, 0, N - 1, i, i, v);
	}

	int Q;
	cin >> Q;
	while (Q--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (b > c)
			swap(b, c);

		if (a == 1) {
			int d;
			cin >> d;
			update(1, 0, N - 1, b ,c , d);
		}
		else {
			cout << getXOR(1, 0, N - 1, b, c) << "\n";
		}
	}
}