/*
����
N(2 �� N �� 40,000)���� �������� �̷���� Ʈ���� �־����� M(1 �� M �� 10,000)���� �� ��� ���� �Է¹��� �� �� ��� ������ �Ÿ��� ����϶�.

�Է�
ù° �ٿ� ����� ���� N�� �Էµǰ� ���� N-1���� �ٿ� Ʈ�� �� ����� �� ���� �Ÿ��� �Է¹޴´�. �� ���� �ٿ� M�� �־�����, ���� M���� �ٿ� �Ÿ��� �˰� ���� ��� ���� �� �ٿ� �� �־� �Էµȴ�. �� �� ������ �Ÿ��� 10,000���� �۰ų� ���� �ڿ����̴�.

������ 1������ N������ ��ȣ�� �Ű��� �ִ�.

���
M���� �ٿ� ���ʴ�� �Է¹��� �� ��� ������ �Ÿ��� ����Ѵ�.

Ǯ��:
Ʈ������ ���� ������ ã�� �����Դϴ�.
�� ���� root�� ���, ��� ��忡 ���� dfs�� Ž���ϸ� �θ� ��带 �����ݴϴ�.
�׸��� �� ������ depth�� ����� �ְ�, ��Ʈ�������� �� �������� �Ÿ��� �����ݴϴ�.

����, ������ ó���� ��, �� ��带 ������ depth�� ���ϰ�, depth�� ���� �ʴٸ� depth��
ū ��尡 depth�� ������ ������ �θ� Ÿ�� �ö�ɴϴ�.
depth�� �������ٸ�, ���� �� ���� ��� �� �ϳ��Դϴ�.
1. �� ��尡 ���� -> �ش� ��尡 ���� �����Դϴ�.
2. �� ��尡 �ٸ� -> �� ��尡 ������ ������ �θ� ��带 Ÿ�� �ö󰩴ϴ�.

���� ������ ã�Ҵٸ�, �� ��尣�� �Ÿ��� root���� �� ������ �Ÿ� - root���� �������� ������ �Ÿ� �Դϴ�.
(�θ� 2�� n �� �� �ö󰡴� ���? ���� ����)

2�� n�¾� �ö󰡴� ��
https://www.crocus.co.kr/660 �� �����߽��ϴ�.
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

int n, m;
vector<pii> edge[40001];
pii dis[40001][17];
int dist[40001];
int parent[40001];
bool visit[40001];
int depth[40001];

void dfs(int now, int d) {

	depth[now] = d;

	for (int i = 0; i < edge[now].size(); i++)
	{
		int next = edge[now][i].first;
		int next_dis = edge[now][i].second;
		if (!visit[next]) {
			visit[next] = true;
			parent[next] = now;
			dis[next][0].first = next_dis;
			dis[next][0].second = now;
			dist[next] = dist[now] + next_dis;
;			dfs(next, d + 1);
		}
	}
}

int getParent(int up, int down) {

	for (int i = 16; i >= 0; i--)
	{
		if (depth[dis[down][i].second] >= depth[up]) {
			down = dis[down][i].second;
			if (depth[down] == depth[up])	break;
		}
	}

	int lca = up;

	if (up != down) {
		for (int i = 16; i >= 0; i--) {
			if (dis[down][i].second != dis[up][i].second) {
				down = dis[down][i].second;
				up = dis[up][i].second;
			}
			lca = dis[up][i].second;
		}
	}
	return lca;

}

int main(void) {
	FIO;
	cin >> n;

	for (int i = 0; i < n - 1; i++)
	{
		int s, e, v;
		cin >> s >> e >> v;
		edge[s].push_back(make_pair(e, v));
		edge[e].push_back(make_pair(s, v));
	}

	visit[1] = true;
	dfs(1, 1);

	for (int j = 1; j < 17; j++)
	{
		for (int i = 1; i <= n; i++)
		{
			dis[i][j].first = dis[dis[i][j - 1].second][j - 1].first + dis[i][j - 1].first;
			dis[i][j].second = dis[dis[i][j - 1].second][j - 1].second;
		}
	}

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int s, e, fnd;
		cin >> s >> e;

		if (depth[s] >= depth[e]) {
			fnd = getParent(e, s);
		}
		else {
			fnd = getParent(s, e);
		}

		cout << dist[s] + dist[e] - 2 * dist[fnd] << "\n";
	}
}