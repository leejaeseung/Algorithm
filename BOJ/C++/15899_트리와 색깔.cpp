/*
����
1���� N������ ��ȣ�� �ο��� N���� ������ N-1���� �������� ������ Ʈ���� �ִ�. �� Ʈ���� ��Ʈ�� 1�� �����̸�, ������ �� ������ �ٸ� ���� ������ ��ΰ� �ݵ�� �� �� �����Ѵ�.

Ʈ���� �� ������ Ư�� ������ ������ �ִ�. ���ǻ� ������ 1 �̻� C ������ �ڿ����� ǥ���ȴ�. �̶�, ���� f(v,c)�� ������ ���� ��������.

f(v, c) : ���� v�� ��Ʈ�� ��Ʈ��(sub-tree)���� ������ c ������ ������ ����

M���� ���� f(vi, ci)�� �־��� ��, �� ���ǿ� ���� ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù ��° �ٿ� ������ ���� ��Ÿ���� N(1 �� N �� 2��105), ������ ������ ��Ÿ���� M(1 �� M �� 2��105), ������ ���� ������ ��Ÿ���� C(1 �� C �� N)�� ���� �ϳ��� ���̿� �ΰ� ���ʷ� �־�����.

�� ��° �ٿ��� �� ������ ������ ��Ÿ���� N���� ������ �������� ���еǾ� ������� �־�����. ù ��° ���� 1�� ������ �����̸�, ..., N ��° ���� N�� ������ �����̴�.

�� ��° �ٺ��� N-1���� �ٿ� ���ļ� Ʈ���� �̷�� �� ������ ������ �־�����. �� ������ ������ �ش� ������ �̷�� ���� �ٸ� �� ������ ��ȣ�� �����ȴ�. �� ������ ��ȣ�� 1 �̻� N ������ �ڿ����̴�.

����, �̾ M���� �ٿ� ���ļ� i��° �ٿ� i��° ������ ���� vi, ci�� �������� ���еǾ� �־�����. vi�� 1 �̻� N ������ ���� ��ȣ�� ��Ÿ����. ci�� 1 �̻� C ������ ���� ������ ��Ÿ����.

���
M���� ���ǿ� ���� ������ ��� ���� ��, 1,000,000,007�� ���� �������� ����Ѵ�.

Ǯ��:
���� ��Ʈ Ʈ���� Ǯ���߽��ϴ�.
����, �־��� Ʈ���� ���� Ʈ���� ��Ÿ���� ���� dfs�� Ž���ϸ� �ε����� ���� �ο��� �ݴϴ�.

���Ӱ� ������� ���� Ʈ���� ���� ��Ʈ ������� ��� ��忡 �� ������ color������ ���ĵǰ� �����մϴ�.
������� ���� ��Ʈ Ʈ���� Ž���ϸ鼭 upper_bound�� ��C ������ ������ ���մϴ�.
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
#define pic pair<int, char>
#define ll long long
#define vi vector<int>
#define vl vector<long long>
#define vii vector<pii>
#define IMAX 2000000001
#define LMAX 100000000000000
int mv1[4] = { 0, 0, 1, -1 };
int mv2[4] = { 1, -1, 0, 0 };

int n, m, c;
int color[200001];
vi edge[200001];
int arr[200001];
vi tree[800010];
int s[200001];
int e[200001];
int d = 1000000007;
int num = 1;

 void dfs(int now) {

	 s[now] = num;
	 //���ο� ���� Ʈ���� ���۱��� ����
	 arr[num++] = color[now];
	//���ο� �ε����� ���� ���� �� ����

	for (int i = 0; i < edge[now].size(); i++)
	{
		int next = edge[now][i];
		if (!s[next]) {
			dfs(next);
		}
	}
	e[now] = num - 1;
	//���ο� ���� Ʈ���� ������ ����
}

 void init(int now, int s, int e, int idx) {
	 if (idx < s || idx > e)	return;
	 
	 if (s == e) {
		 tree[now].push_back(arr[idx]);
		 return;
	 }
	 init(now * 2, s, (s + e) / 2, idx);
	 init(now * 2 + 1, (s + e) / 2 + 1, e, idx);
 }

 void update(int now, int s, int e) {
	 //����-��Ʈ ���� -> �׳� ��� tree[i] �� ���� sort�Լ��� �ᵵ �ȴ�.
	 if (s == e) {
		 return;
	 }

	 update(now * 2, s, (s + e) / 2);
	 update(now * 2 + 1, (s + e) / 2 + 1, e);

	 vi left = tree[now * 2];
	 vi right = tree[now * 2 + 1];
	 int lidx = 0, ridx = 0;

	 while (left.size() > lidx&& right.size() > ridx) {
		 if (left[lidx] <= right[ridx]) {
			 tree[now].push_back(left[lidx++]);
		 }
		 else {
			 tree[now].push_back(right[ridx++]);
		 }
	 }
	 while (left.size() > lidx) {
		 tree[now].push_back(left[lidx++]);
	 }
	 while (right.size() > ridx) {
		 tree[now].push_back(right[ridx++]);
	 }
 }

 int get(int now, int s, int e, int l, int r, int c) {
	 if (r < s || l > e)	return 0;
	 if (l <= s && e <= r) {
		 return tree[now].size() - (tree[now].end() - upper_bound(tree[now].begin(), tree[now].end(), c));
		 //������ ���Ե� �� ī��Ʈ ���� upper_bound�� ������
	 }

	 return (get(now * 2, s, (s + e) / 2, l, r, c) + get(now * 2 + 1, (s + e) / 2 + 1, e, l, r, c)) % d;
}

int main(void) {
	FIO;
	cin >> n >> m >> c;

	for (int i = 1; i <= n; i++)
	{
		cin >> color[i];
	}

	for (int i = 0; i < n - 1; i++)
	{
		int s, e;
		cin >> s >> e;
		edge[s].push_back(e);
		edge[e].push_back(s);
	}
	
	dfs(1);

	for (int i = 1; i <= n; i++)
	{
		init(1, 1, n, i);
	}

	update(1, 1, n);

	int ans = 0;

	for (int i = 0; i < m; i++)
	{
		int v, c;
		cin >> v >> c;

		ans = ((ans % d) + (get(1, 1, n, s[v], e[v], c) % d)) % d;
	}

	cout << ans % d;
}