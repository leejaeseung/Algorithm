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
int dis[40001];
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
			dis[next] = dis[now] + next_dis;
			dfs(next, d + 1);
		}
	}
}

int getParent(int n1, int n2) {

	int n1_dist = dis[n1];
	int n2_dist = dis[n2];
	
	int final_node = 0;

	while (true) {
		int pn1 = parent[n1];
		int pn2 = parent[n2];

		if (depth[n1] > depth[n2]) {
				n1 = pn1;
		}
		else if (depth[n1] < depth[n2]) {
				n2 = pn2;
		}
		else {
			if (n1 == n2) {
				final_node = n1;
				//���� ����
				break;
			}
			else {
				n1 = pn1;
				n2 = pn2;
			}
		}
	}

	return n1_dist + n2_dist - dis[final_node] * 2;
	//root���� �� �������� �Ÿ� - root���� ���� ��������� �Ÿ�
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

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int s, e;
		cin >> s >> e;

		cout << getParent(s, e) << "\n";
	}
}