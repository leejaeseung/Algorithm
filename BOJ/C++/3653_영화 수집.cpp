/*
����
����̴� ��ȭ DVD �������̴�. ����̴� ���� DVD �ݷ����� �׾� �����Ѵ�.

���� ���� ��ȭ�� ���� ����, DVD�� ��ġ�� ã�� ���� �׾Ƴ��� �ݷ����� �������� �ʰ� ���ɽ����� DVD�� ����. ��ȭ�� �� �� ���Ŀ��� ���� ���� ���´�.

����̴� DVD�� �ſ� ���� ������, ��ȭ�� ��ġ�� ã�µ� �ð��� �ʹ� ���� �ɸ���. �� DVD�� ��ġ��, ã������ DVD�� ���� �ִ� ��ȭ�� ������ �˸� ���� ���� �� �ִ�. �� ��ȭ�� DVD ǥ���� �پ��ִ� ���ڷ� ���� ������ �� �ִ�.

�� ��ȭ�� ��ġ�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�. ����̰� ��ȭ�� �� �� �� ������ �� DVD�� ���� �� ���� DVD�� �־������� ���ؾ� �Ѵ�.

�Է�
ù° �ٿ� �׽�Ʈ ���̽��� ������ �־�����. �׽�Ʈ ���̽��� ������ 100���� ���� �ʴ´�.

�� �׽�Ʈ ���̽��� ù° �ٿ��� ����̰� ������ �ִ� ��ȭ�� �� n�� ������ �ϴ� ��ȭ�� �� m�� �־�����. (1 �� n, m �� 100,000) ��° �ٿ��� ������ �ϴ� ��ȭ�� ��ȣ�� ������� �־�����.

��ȭ�� ��ȣ�� 1���� n���� �̸�, ���� ó���� ��ȭ�� �׿��� ������ 1���� �����ϴ� �����̴�. ���� ���� �ִ� ��ȭ�� ��ȣ�� 1�̴�.

���
�� �׽�Ʈ ���̽��� ���ؼ� �� �ٿ� m���� ������ ����ؾ� �Ѵ�. i��° ����ϴ� ���� i��°�� ��ȭ�� �� �� �� ��ȭ�� ���� �־��� DVD�� �����̴�. ����̴� �Ź� ��ȭ�� �� ������ �� ��ȭ DVD�� ���� ���� ���´�.

Ǯ��:
�� �Ʒ��� �״� �� �ƴ϶� �� ������ ���ĵθ� ���� Ǯ���ϴ�.
n + m ũ���� å���� �ִٰ� �����ϸ�, n = 5, m = 3 �� �� ������ ���� ��Ÿ�� �� �ֽ��ϴ�.(f = �̹��� �ű� ��ġ)

- - - 1 2 3 4 5
    f

m���� dvd�� �ű�Ƿ� �� ĭ�� mĭ�̸� ����մϴ�.
4�� dvd�� �ű� �� �� ó������ 4�� �ٷ� �ձ����� ���� ���� ���ϸ� �˴ϴ�.

- - 4 1 2 3 - 5
  f

���� ���� ���ϰ�, �� dvd ��ȣ�� �Ű��� ��ġ�� ���� idx[] �迭�� �����ϸ� �˴ϴ�.
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

int t, n, m;
int tree[800005];
int idx[100001];

int update(int now, int s, int e, int idx, int v) {
	if (s > idx || e < idx)	return tree[now];
	if (s == e) {
		return tree[now] = v;
	}
	return tree[now] = update(now * 2, s, (s + e) / 2, idx, v) + update(now * 2 + 1, (s + e) / 2 + 1, e, idx, v);
}

int get(int now, int s, int e, int l, int r) {

	if (e < l || s > r)	return 0;
	if (l <= s && r >= e) {
		return tree[now];
	}
	return get(now * 2, s, (s + e) / 2, l, r) + get(now * 2 + 1, (s + e) / 2 + 1, e, l, r);
}

int main(void) {
	FIO;

	cin >> t;

	while (t--) {
		cin >> n >> m;

		for (int i = 0; i < 800005; i++)
		{
			tree[i] = 0;
		}
		for (int i = 0; i < 100001; i++)
		{
			idx[i] = 0;
		}

		for (int i = m + 1; i <= n + m; i++)
		{
			//�����ʿ� dvd�� ���Ƴ���
			update(1, 1, n + m, i, 1);
			idx[i - m] = i;
		}

		int front = m;

		for (int i = 0; i < m; i++)
		{
			int v;
			cin >> v;

			//�ű� dvd�� �ٷ� �ձ��� �������� ����.
			cout << get(1, 1, n + m, 1, idx[v] - 1) << " ";
				
			if (idx[v] != front) {
				//�� �� dvd�� �ƴ� ��� dvd�� �ű�
				update(1, 1, n + m, idx[v], 0);
				idx[v] = --front;
				update(1, 1, n + m, idx[v], 1);

			}
		}
		cout << "\n";
	}
}