/*
문제
그래프가 주어졌을 때, 단절점을 모두 구해 출력하는 프로그램을 작성하시오.

단절점이란 그 정점을 제거했을 때, 그래프가 두 개 또는 그 이상으로 나누어지는 정점을 말한다. 즉, 제거했을 때 그래프의 connected component의 개수가 증가하는 정점을 말한다.

입력
첫째 줄에 두 정수 V(1≤V≤10,000), E(1≤E≤100,000)가 주어진다. 이는 그래프가 V개의 정점과 E개의 간선으로 이루어져 있다는 의미이다. 다음 E개의 줄에는 간선에 대한 정보를 나타내는 두 정수 A, B가 주어진다. 이는 A번 정점과 B번 정점이 연결되어 있다는 의미이며, 방향은 양방향이다.

입력으로 주어지는 그래프는 연결 그래프가 아닐 수도 있다.

출력
첫째 줄에 단절점의 개수를 출력한다.

둘째 줄에는 단절점의 번호를 공백으로 구분해 오름차순으로 출력한다.

풀이:
단절점과 단절선 알고리즘이다.
https://jason9319.tistory.com/119
위 블로그를 참고해 풀이했다.

하나의 그래프에서 임의의 한 노드를 루트로 삼고 한 번의 dfs로 해결한다.
dfs를 하면서 방문 번호를 노드마다 붙여 주는데, dfs중의 자신의 자식들 중에서(자신보다 나중에 탐색되는)
자신보다 낮은 방문 번호를 가진 노드와 연결되어 있다면 자신은 단절점이 아니다.

단, 루트노드는 예외로 dfs로 생긴 자식이 2개 이상이면 무조건 단절점이다.
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
#define pll pair<ll, ll>
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vii vector<pii>
#define IMAX 2000000001
#define LMAX 1000000000000000000
#define DMAX 0xFFFFFFFFFFFFF
#define MOD 100003
int mv1[4] = { 0, 0, 1, -1 };
int mv2[4] = { 1, -1, 0, 0 };
int mv_all1[8] = { 0, 1, 0, -1, -1, -1, 1, 1 };
int mv_all2[8] = { 1, 0, -1, 0 , -1, 1, -1, 1 };

int v, e;
bool visit[10001];
int visit_seq[10001];
vector<int> edge[10001];
set<int> ans;

int visit_cnt = 1;

int dfs(int now, bool isRoot) {

	visit_seq[now] = visit_cnt;
	int ret = visit_cnt++;
	int child = 0;

	for (int i = 0; i < edge[now].size(); i++)
	{
		int next = edge[now][i];

		if (!visit[next]) {
			visit[next] = true;
			child++;

			int sons = dfs(next, false);
			//자식의 연결 점 중 가장 작은 점을 구함

			if (!isRoot && sons >= visit_seq[now])
				ans.insert(now);

			ret = min(ret, sons);
		}

		ret = min(ret, visit_seq[next]);
		//자신의 연결 점 중 가장 작은 점을 저장 -> 부모에게 알려주기 위해
	}

	//루트일 때
	if (isRoot && child > 1) {
		ans.insert(now);
	}

	return ret;
}

int main(void) {
	FIO;

	cin >> v >> e;

	for (int i = 0; i < e; i++)
	{
		int a, b;
		cin >> a >> b;

		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	for (int i = 1; i <= v; i++)
	{
		if (!visit[i]) {
			visit[i] = true;

			dfs(i, true);
		}
	}

	cout << ans.size() << "\n";
	for (auto iter = ans.begin(); iter != ans.end(); iter++)
		cout << *iter << " ";
}