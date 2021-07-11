/*
����
��� �˴ٽ��� ��ȣ�� Ŀ�Ǽ��� �����̴�. (������ ���������� ���ο��� ������� ����.)

��� �� Ŀ�Ǽ��� �մ� A���� ��ȣ���� ������ ���ڰ� �ߴ�.

�� ������ ������ ���� ��Ģ�� ���´�.

N���� ������ ������, ��ȣ�� ������ ���� ���Ѵ�. ��3~7��° ���� ���� ��������?�� �׷��� ������ ���� ���� 000�Դϴ�. �׸��� 8��° ���� 2�� ��ġ���� ���ҡ� �׷��� ��ȣ�� ���� �˰ڽ��ϴ�.����� �� �ڿ� �ٽ� ������ ��ȣ�� �ߴ� ��ó�� ��8~9��° ���� ���� ��������?����� ���Եȴ�. �� ���� ������ ���鼭 �ݺ��ϴ� �����̴�.

����� �� ������ ���� ���� �þҴ�. ������, ������ ���� ����� �̸� �˾ƾ� �Ѵٴ� ���̴�.

����� �Ӹ��� �����ϴٸ� 10���� ���� �Ǵ� ������ 10���� ���� �Ǵ� ������ ����� �� ���� ���̴�. ���� �� ������ ���� ��ȣ�� ���� ������� �� ������ �ϱ⸦ �ٶ�� �Ǿ���, ��ſ��� ���� ���α׷��� �����ش޶�� ��û�ߴ�.

�Է�
ù° �ٿ� ���� ���� N�� ���� ���� Q�� �־�����.(1 �� N, Q �� 100,000) ��° �ٿ��� ó�� �迭�� �� �ִ� ���� N���� �־�����. �� ��° �ٿ��� Q+2��° �ٱ����� x y a b�� �������� x~y������ ���� ���Ͽ���, a��° ���� b�� �ٲپ�� ��� ���� �����Ͱ� �־�����.

�ԷµǴ� ��� ���� -231���� ũ�ų� ����, 231-1���� �۰ų� ���� �����̴�.

���
�� �ϸ��� ���� ���� �� �ٸ��� �� ���� ����Ѵ�.

Ǯ��:
���׸�Ʈ Ʈ�� �⺻ �����̴�.
x > y �� ��츦 ��������.
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
#define IMAX 2147483647
#define LMAX 1000000000000500000
#define DMAX 0xFFFFFFFFFFFFF
int mv1[4] = { 0, 1, -1, 0 };
int mv2[4] = { 1, 0, 0, -1 };

int n, q;
ll tree[450001];

ll update(int now, int s, int e,int idx, int v) {
	if (s > idx || e < idx)	return tree[now];

	if (s == e) {
		tree[now] = v;
		return tree[now];
	}

	return tree[now] = update(now * 2, s, (s + e) / 2, idx, v) + update(now * 2 + 1, (s + e) / 2 + 1, e, idx, v);
}

ll get(int now, int s, int e, int l, int r) {
	if (r < s || l > e)	return 0;

	if (l <= s && e <= r) {
		return tree[now];
	}

	return get(now * 2, s, (s + e) / 2, l, r) + get(now * 2 + 1, (s + e) / 2 + 1, e, l, r);
}

int main(void) {
	FIO;

	cin >> n >> q;

	for (int i = 1; i <= n; i++)
	{
		int v;
		cin >> v;
		update(1, 1, n, i, v);
	}

	for (int i = 0; i < q; i++)
	{
		int x, y, a, b;
		cin >> x >> y >> a >> b;

		cout << get(1, 1, n, min(x, y), max(x, y)) << "\n";
		update(1, 1, n, a, b);
	}
}