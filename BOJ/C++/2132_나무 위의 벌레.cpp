/*
문제
전산학(Computer science)에서 트리란 사이클이 없는 그래프를 말한다. 트리(Tree)라는 이름이 의미하듯, 이러한 구조는 나무의 모습에서 유래한다. 즉, 트리의 각 간선(edge)들이 나무의 가지를 나타내고, 각 정점(node)들은 가지가 갈라지는 지점을 의미한다. 또한 트리의 루트는 나무의 뿌리를 의미한다. 이러한 구조는 일반적인 나무의 구조에 해당하지만, 트리 자체의 성질에 주목하면 실제 나무와는 다소 다른 구조가 되기도 한다.

우리가 생각하려는 나무는 루트가 없는 트리이다. 이때 트리의 각각의 간선은 나무의 가지에 해당하고, 트리의 각 정점은 나무 위에서 열매가 매달려있는 지점을 의미한다. 각각의 정점에는 몇 개의 열매가 매달려 있다. 물론 열매 없이 가지가 갈라지는 경우도 있으므로, 이러한 경우는 그 노드에 0개의 열매가 매달려 있다고 생각하기로 하자.

이러한 나무 위에 한 마리의 벌레가 있다. 이 벌레는 임의의 정점에서 이동하기 시작한다. 벌레가 한 정점에 있을 때에는, 그 정점에 있는 열매들을 먹을 수 있다. 열매들을 다 먹은 후에는 가지를 따라서 다른 정점으로 이동한다. 만약 이동할 수 있는 가지가 여러 개 있다면 그 중 하나를 임의로 선택하지만, 한 번 지났던 가지는 다시 지날 수 없다. 벌레의 이동은 더 이상 이동할 수 있는 정점이 없을 때에 끝난다.

나무의 모양이 주어졌을 때, 벌레가 최대로 먹을 수 있는 열매의 수와 이때 어느 정점에서 이동을 시작해야 하는지를 알아내는 프로그램을 작성하시오.

입력
첫째 줄에는 트리의 정점의 개수를 나타내는 정수 n(1≤n≤10,000)이 주어진다. 다음 줄에는 차례로 1번, 2번, …, n번 정점에 매달려 있는 열매의 개수가 주어진다. 다음 n-1개의 줄에는 트리의 각 간선을 나타내는 서로 다른 두 자연수 A, B(1≤A, B≤n)가 주어진다. 이는 트리의 A번 정점과 B번 정점이 연결되어 있음을 의미한다. 나무에 매달려 있는 열매의 총 개수는 2^31-1 (2,147,483,647)개를 넘지 않는다. 즉, 32-bit int를 사용하면 된다.

출력
첫째 줄에 벌레가 먹을 수 있는 열매의 최대 개수와, 이때 이동을 시작할 정점의 번호를 출력한다. 답이 여러 개 있을 경우에는 정점의 번호가 가장 작은 경우를 출력한다.

풀이:
https://www.acmicpc.net/problem/1967 - 트리의 지름 문제와 유사하지만, 열매의 개수가 0인 조건이 까다로운 문제입니다.

기본 아이디어는 임의의 한 점에서, 가장 열매를 많이 먹을 수 있는 정점을 dfs로 하나 찾습니다.(새로운 시작점)
단, 해당 정점의 번호는 최소값이어야 합니다.(열매가 0인 경우 정점을 거쳐도 열매의 최대값은 변하지 않기 때문에)

찾은 정점에서부터 다시 dfs를 이용하여 가장 먼 거리(maxV = 가장 많이 먹을 수 있는 열매 수)를 구해줍니다.
답은 (가장 먼 점들) or (시작 점) 인데, 이 중 번호가 최소인 걸 구해야 하므로
시작 점으로부터 모든 점들까지의 거리를 저장하고, 번호가 작은 점부터 시작해서, 점까지의 거리가 최대값과 일치한다면 
해당 점이 정답입니다.(시작 점과도 min 연산)
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

int n;
int v[10001];
int maxV = 0;
int dist[10001];
bool visit[10001];
vector<int> vt[10001];
int idx = 20000;

void  dfs(int now, int now_cnt) {

	if (maxV < now_cnt) {
		maxV = now_cnt;
		idx = now;
	}
	else if (maxV == now_cnt)
		idx = min(idx, now);
	//최소 번호 갱신

	for (int i = 0; i < vt[now].size(); i++)
	{
		int next = vt[now][i];

		if (!visit[next]) {
			visit[next] = true;
			dfs(next, now_cnt + v[next]);
		}
	}
	visit[now] = false;
}

void  dfs2(int now, int now_cnt) {

	dist[now] = now_cnt;		//모든 점까지의 거리를 구함
	maxV = max(maxV, now_cnt);	//최대 값을 구함

	for (int i = 0; i < vt[now].size(); i++)
	{
		int next = vt[now][i];

		if (!visit[next]) {
			visit[next] = true;
			dfs2(next, now_cnt + v[next]);
		}
	}
	visit[now] = false;
}

int main(void) {
	FIO;

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
	}

	for (int i = 0; i < n - 1; i++)
	{
		int s, e;
		cin >> s >> e;

		vt[s].push_back(e);
		vt[e].push_back(s);
	}
	
	visit[1] = true;
	dfs(1, v[1]);
	//임의의 점 1부터 가장 먼 점을 구함 = idx

	maxV = 0;
	visit[idx] = true;
	dfs2(idx, v[idx]);
	//idx부터 다시 가장 먼 점을 구함.

	for (int i = 1; i <= n; i++)
		//작은 번호부터 시작
	{
		if (dist[i] == maxV) {
			cout << maxV << " " << min(i, idx);
			break;
		}
	}
}