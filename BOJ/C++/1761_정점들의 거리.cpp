/*
문제
N(2 ≤ N ≤ 40,000)개의 정점으로 이루어진 트리가 주어지고 M(1 ≤ M ≤ 10,000)개의 두 노드 쌍을 입력받을 때 두 노드 사이의 거리를 출력하라.

입력
첫째 줄에 노드의 개수 N이 입력되고 다음 N-1개의 줄에 트리 상에 연결된 두 점과 거리를 입력받는다. 그 다음 줄에 M이 주어지고, 다음 M개의 줄에 거리를 알고 싶은 노드 쌍이 한 줄에 한 쌍씩 입력된다. 두 점 사이의 거리는 10,000보다 작거나 같은 자연수이다.

정점은 1번부터 N번까지 번호가 매겨져 있다.

출력
M개의 줄에 차례대로 입력받은 두 노드 사이의 거리를 출력한다.

풀이:
트리에서 공통 조상을 찾는 문제입니다.
한 점을 root로 삼고, 모든 노드에 대해 dfs로 탐색하며 부모 노드를 정해줍니다.
그리고 각 노드들의 depth를 기록해 주고, 루트에서부터 각 노드까지의 거리를 구해줍니다.

이제, 쿼리를 처리할 때, 두 노드를 받으면 depth를 비교하고, depth가 같지 않다면 depth가
큰 노드가 depth가 같아질 때까지 부모를 타고 올라옵니다.
depth가 같아졌다면, 다음 두 가지 경우 중 하나입니다.
1. 두 노드가 같음 -> 해당 노드가 공통 조상입니다.
2. 두 노드가 다름 -> 두 노드가 같아질 때까지 부모 노드를 타고 올라갑니다.

공통 조상을 찾았다면, 두 노드간의 거리는 root부터 두 노드까지 거리 - root부터 공통조상 까지의 거리 입니다.
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
				//공통 조상
				break;
			}
			else {
				n1 = pn1;
				n2 = pn2;
			}
		}
	}

	return n1_dist + n2_dist - dis[final_node] * 2;
	//root부터 두 노드까지의 거리 - root부터 공통 조상까지의 거리
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