/*
����
� N���� ���� �־��� �ִ�. �׷��� �߰��� ���� ������ ����� �Ͼ�� �� �߰��� � �κ��� ���� ���Ϸ� �Ѵ�. ���࿡ 1,2,3,4,5 ��� ���� �ְ�, 3��°���� 4��° ���� 6�� ���ϸ� 1, 2, 9, 10, 5�� �ǰ�, ���⼭ 2��°���� 5��°���� ���� ���϶�� �Ѵٸ� 26�� ����ϸ� �Ǵ� ���̴�. �׸��� �� ���¿��� 1��°���� 3��° ���� 2�� ���� 2��°���� 5��°���� ���� ���϶�� �Ѵٸ� 22�� �� ���̴�.

�Է�
ù° �ٿ� ���� ���� N(1 �� N �� 1,000,000)�� M(1 �� M �� 10,000), K(1 �� K �� 10,000) �� �־�����. M�� ���� ������ �Ͼ�� Ƚ���̰�, K�� ������ ���� ���ϴ� Ƚ���̴�. �׸��� ��° �ٺ��� N+1��° �ٱ��� N���� ���� �־�����. �׸��� N+2��° �ٺ��� N+M+K+1��° �ٱ��� �� ���� ���� a, b, c �Ǵ� a, b, c, d�� �־����µ�, a�� 1�� ��� b��° ������ c��° ���� d�� ���ϰ�, a�� 2�� ��쿡�� b���� c������ ���� ���Ͽ� ����ϸ� �ȴ�.

�Է����� �־����� ��� ���� -263���� ũ�ų� ����, 263-1���� �۰ų� ���� �����̴�.

���
ù° �ٺ��� K�ٿ� ���� ���� ������ ���� ����Ѵ�. ��, ������ -263���� ũ�ų� ����, 263-1���� �۰ų� ���� �����̴�.

Ǯ��:
������ ���׸�Ʈ Ʈ���� �������ϰ� �����ϴ� �����Դϴ�.
http://blog.naver.com/PostView.nhn?blogId=kks227&logNo=220824350353&parentCategoryNo=168&categoryNo=&viewDate=&isShowPopularPosts=true&from=search
Ǯ�̴� �� ��α׸� �����߽��ϴ�.
���� update ��, ���� ���� ���� �� �ڽ� ���鿡�� ���ݱ��� ���� �ڽ��� lazy���� �����ϴ� propagate() �� ����մϴ�.
*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include<stack>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pii pair<int, int>;

int N, M, K;
long long tree[5000001];
long long lazy[5000001];

long long init(int now, int l, int r, int idx, long long v) {
	if (idx > r || idx < l)	return tree[now];
	if (l == r) 
		return tree[now] = v;
	
	return tree[now] = init(now * 2, l, (l + r) / 2, idx, v) + init(now * 2 + 1, (l + r) / 2 + 1, r, idx, v);
}

void propagate(int now, int l, int r) {
	if (lazy[now] != 0) {
		if (l != r) {
			lazy[now * 2] += lazy[now];
			lazy[now * 2 + 1] += lazy[now];
		}
		tree[now] += lazy[now] * (r - l + 1);
		lazy[now] = 0;
	}
}

void update(int now, int l, int r, int s, int e, long long add) {
	propagate(now, l, r);

	if (r < s || l > e)	return;
	if (s <= l && e >= r) {
		lazy[now] += add;
		propagate(now, l, r);
	}
	else {
		update(now * 2, l, (l + r) / 2, s, e, add);
		update(now * 2 + 1, (l + r) / 2 + 1, r, s, e, add);

		tree[now] = tree[now * 2] + tree[now * 2 + 1];
	}
}



long long getSum(int now, int l, int r, int s, int e) {
	propagate(now, l, r);

	if (r < s || l > e)	return 0;
	if (s <= l && e >= r) return tree[now];

		return getSum(now * 2, l, (l + r) / 2, s, e) + getSum(now * 2 + 1, (l + r) / 2 + 1, r, s, e);
}

int main(void) {
	FIO;

	cin >> N >> M >> K;
	
	for (int i = 1; i <= N; i++)
	{
		int n;
		cin >> n;
		init(1, 1, N, i, n);
	}

	for (int i = 0; i < M + K; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c;

		if (a == 1) {
			cin >> d;

			update(1, 1, N, b, c, d);
		}
		else {
			cout << getSum(1, 1, N, b, c) << "\n";
		}
	}
}