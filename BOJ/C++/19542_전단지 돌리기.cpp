/*
����
�����̴� Ʈ�� ����� �� ������ ������̸� Ÿ�� �������� �������� �Ѵ�. �������� ��ǥ�� �ɴϼ���Ʈ���� ����Ͽ� ��� ��忡 �������� ������, �ٽ� �ɴϼ���Ʈ�� ���ƿ��� ���̴�. �����̴� ���� ���� ������ ���� ��忡�� �Ÿ���  ������ ��� ��忡 �������� ���� �� �ִ�.

������ �ſ� ���� ������, �����̴� �ּ��Ѹ� �̵��ؼ� ��ǥ�� �޼��ϰ� �ʹ�! �����̸� ���� �����̰� �̵��ؾ� �ϴ� �� �Ÿ��� ��������.

�Է�
ù��° �ٿ��� ����� ���� ()�� �ɴϼ���Ʈ�� ��ġ (), �� ()�� �־�����.

�� ��° �ٺ��� ��° �ٱ���, Ʈ���� ���� ������ �ǹ��ϴ� �� �ڿ��� , �� �������� ���еǾ� �־�����. �̴� �� ���� �� ��尡 ����Ǿ� ������ �ǹ��Ѵ�. (, )

�־����� �������� Ʈ���� �����ϸ�, ��� ������ ���̴� �̴�.

���
�����̰� ��ǥ�� �ϼ��ϱ� ���� �̵��ؾ� �ϴ� �ּ� �Ÿ��� ����Ͽ���.

Ǯ��:
Ʈ������, �ɴϼ���Ʈ�� root�� �Ͽ� ��� ��忡 ���� ���̸� ���Ѵ�.

�ٽ� root���� Ž���ϸ鼭 �ڽ��� ���̰� ������ �۴ٸ� �� ����� ��� �ڽĳ�忣 �������� ���� �� �����Ƿ�
Ž������ �ʰ�, ũ�ų� ���ٸ� �ش� ���� �����ϰ�, ���ٰ� �;��ϹǷ� 2�� ���Ѵ�.
*/
#include<iostream>
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
int mv1[4] = { 0, 1, 0, -1 };
int mv2[4] = { 1, 0, -1, 0 };
int mv_all1[8] = { 0, 1, 0, -1, -1, -1, 1, 1 };
int mv_all2[8] = { 1, 0, -1, 0 , -1, 1, -1, 1 };

int n, S, D;
bool visit[100001];
int height[100001];
vector<int> edge[100001];
vector<int> child[100001];

int res = 0;

int make_tree(int now) {

	int h = 0;

	if (now != S && edge[now].size() == 1) {
		return height[now] = h;
	}

	for (int i = 0; i < edge[now].size(); i++)
	{
		int next = edge[now][i];

		if (!visit[next]) {
			visit[now] = true;

			child[now].push_back(next);
			h = max(h, make_tree(next));
		}
	}

	return height[now] = h + 1;
}

void dfs(int now) {

	for (int i = 0; i < child[now].size(); i++)
	{
		int next = child[now][i];

		if (height[next] >= D) {
			res += 2;

			dfs(next);
		}
	}
}

int main(void) {
	FIO;

	cin >> n >> S >> D;

	for (int i = 0; i < n - 1; i++)
	{
		int s, e;

		cin >> s >> e;

		edge[s].push_back(e);
		edge[e].push_back(s);
	}

	visit[S] = true;
	make_tree(S);

	dfs(S);

	cout << res;
}