/*
문제
현민이는 트리 모양의 길 위에서 오토바이를 타고 전단지를 돌리려고 한다. 현민이의 목표는 케니소프트에서 출발하여 모든 노드에 전단지를 돌리고, 다시 케니소프트로 돌아오는 것이다. 현민이는 힘이 좋기 때문에 현재 노드에서 거리가  이하인 모든 노드에 전단지를 돌릴 수 있다.

날씨가 매우 덥기 때문에, 현민이는 최소한만 이동해서 목표를 달성하고 싶다! 현민이를 위해 현민이가 이동해야 하는 총 거리를 구해주자.

입력
첫번째 줄에는 노드의 개수 ()과 케니소프트의 위치 (), 힘 ()이 주어진다.

두 번째 줄부터 번째 줄까지, 트리의 간선 정보를 의미하는 두 자연수 , 가 공백으로 구분되어 주어진다. 이는 번 노드와 번 노드가 연결되어 있음을 의미한다. (, )

주어지는 연결관계는 트리를 구성하며, 모든 간선의 길이는 이다.

출력
현민이가 목표를 완수하기 위해 이동해야 하는 최소 거리를 출력하여라.

풀이:
트리에서, 케니소프트를 root로 하여 모든 노드에 대해 높이를 구한다.

다시 root부터 탐색하면서 자식의 높이가 힘보다 작다면 그 노드의 모든 자식노드엔 전단지를 돌릴 수 있으므로
탐색하지 않고, 크거나 같다면 해당 노드로 진행하고, 갔다가 와야하므로 2를 더한다.
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