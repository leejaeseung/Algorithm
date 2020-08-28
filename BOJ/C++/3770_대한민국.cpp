/*
����
���ѹα��� ���ƽþƿ� ��ġ�� �ѹݵ��� ��ġ�ϰ� �ִ�. 3���� �ٴ��� �ѱ��� �������� ����, �������� ����, �������� ���ؿ� ���� �ѷ��ο� �ִ�.

���ѹα��� ���ؾȿ��� ���ð� N�� �ְ�, ���ؾȿ��� ���ð� M�� �ִ�. (M �� 1000, N �� 1000) �� ���δ� ���ʺ��� ���ʱ��� ��ȣ�� 1������ �Ű��� �ִ�. ���� ������ ������� ���ؾȰ� ���ؾ��� �����ϴ� K���� ��ӵ��θ� ������� �Ѵ�. �� ��ӵ��δ� ���ؾȿ� �ִ� ���ÿ� ���ؾȿ� �ִ� ���ø� �����ϴ� ������ �����̴�. (���� �������� ���δ� �����縦 �����ϰ� �ϰ� �Ƿΰ��� ������ �Ͽ� ����� ������ �ǹǷ�, �Ϻη� ������ ����ų� Ŀ�긦 ���� �׷��� ���� �Ͼ�� �ʵ��� ����Ǿ� �ִ�)

��ӵ��ΰ� ���� �����ϴ� ������ �ްԼҸ� �������� �Ѵ�. �� ������ �����ϴ� ��ӵ��δ� �ִ� 2���̴�. ��ӵ��ΰ� �־����� ��, ��ӵ��ΰ� �����ϴ� ���� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
�Է��� ù° �ٿ��� �׽�Ʈ ���̽��� ���� T�� �־�����. �� �׽�Ʈ ���̽��� ù° �ٿ��� N, M, K�� �־�����. K�� ��ӵ����� ���̴�. ��° �ٺ��� K���� �ٿ��� ��ӵ����� ������ �־�����. ��ӵ����� ������ ���� 2���� �̷���� �ִ�. ù ��° ���ڴ� ���ؾȿ� �ִ� ������ ��ȣ�̰�, �� ��° ���ڴ� ���ؾȿ� �ִ� ������ ��ȣ�̴�.

��ӵ����� ������ 40�������� �۰ų� ������, ������ ����dl 263-1���� �۰ų� ���� ��츸 �Է����� �־�����.

���
�� �׽�Ʈ ���̽��� ���ؼ�, �������� ���� ���̽� ��ȣ�� �Բ� ����Ѵ�.

Ǯ��:
https://www.acmicpc.net/problem/3653
�� ����� ������� Ǯ���ߴ�.

M ���� �������� �����ϴµ�, �� ó���� 0 ~ M �� ������ ����� ������ ������Ʈ�Ѵ�.
���ؾ��� ������������ ����, ����� ���ؾȵ� ������������ ���鼭,
���ؾ� x ���� �ްԼ� ������ 0 ~ (x - 1) �������� ����̴�.
�ߺ��� ���� ���� �̹� �� ���ؾ��� ���� -1 ���ش�.
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

int t, n, m, k;
ll tree[5001];
vector<int> edge[1001];

void update(int now, int s, int e, int idx, ll v) {
	if (idx > e || s > idx)	return;

	if (s == e) {
		tree[now] += v;
		return;
	}

	update(now * 2, s, (s + e) / 2, idx, v);
	update(now * 2 + 1, (s + e) / 2 + 1, e, idx, v);

	tree[now] = tree[now * 2] + tree[now * 2 + 1];
}

ll get(int now, int s, int e, int l, int r) {
	if (r < s || l > e)	return 0;
	if (l <= s && r >= e)	return tree[now];

	return get(now * 2, s, (s + e) / 2, l, r) + get(now * 2 + 1, (s + e) / 2 + 1, e, l, r);
}

int main(void) {
	FIO;

	cin >> t;

	for (int test = 1; test <= t; test++) {
		cin >> n >> m >> k;

		for (int i = 0; i < 5001; i++)
			tree[i] = 0;

		for (int i = 0; i < 1001; i++)
			edge[i].clear();

		for (int i = 0; i < k; i++)
		{
			int s, e;
			cin >> s >> e;

			edge[s].push_back(e);
			update(1, 0, m - 1, e - 1, 1);
		}

		ll ans = 0;

		for (int i = 1; i <= n; i++)
		{
			sort(edge[i].begin(), edge[i].end());

			for (int j = 0; j < edge[i].size(); j++)
			{
				int tgt = edge[i][j];

				ans += get(1, 0, m - 1, 0, tgt - 2);
				update(1, 0, m - 1, tgt - 1, -1);
			}
		}

		cout << "Test case " << test <<  ": " << ans << "\n";
	}
}