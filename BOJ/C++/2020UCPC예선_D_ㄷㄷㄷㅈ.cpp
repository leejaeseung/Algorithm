/*
문제
어느 날, 트리를 물끄러미 보고 있던 동현이는 엄청난 사실을 하나 발견했다. 바로 정점이 네 개인 트리는 ‘ㄷ’과 ‘ㅈ’의 두 종류밖에 없다는 사실이다!



정점이 네 개 이상 있는 임의의 트리에 대해, 그 트리에서 정점 네 개로 이루어진 집합을 고르자. 전체 트리의 간선들 중 집합에 속한 두 정점을 잇는 간선만을 남겼을 때, 네 개의 정점이 하나의 트리 형태로 이어지게 된다면 ‘ㄷ’ 모양이거나 ‘ㅈ’ 모양일 것이다. 트리에서 ‘ㄷ’의 개수와 ‘ㅈ’의 개수를 각각 트리에서 ‘ㄷ’ 모양, ‘ㅈ’ 모양을 이루는 정점 네 개짜리 집합의 개수라고 하자.

이제, 동현이는 세상의 모든 트리를 다음과 같은 세 종류로 나누었다.

D-트리 : ‘ㄷ’이 ‘ㅈ’의 배보다 많은 트리
G-트리 : ‘ㄷ’이 ‘ㅈ’의 배보다 적은 트리
DUDUDUNGA-트리 : ‘ㄷ’이 ‘ㅈ’의 정확히 배만큼 있는 트리
신이 난 동현이는 트리만 보이면 그 트리에 있는 ‘ㄷ’과 ‘ㅈ’이 몇 개인지 세고 다니기 시작했다. 하지만 곧 정점이 만 개나 있는 트리가 동현이 앞에 나타났고, 동현이는 그만 정신을 잃고 말았다. 동현이를 대신해 주어진 트리가 D-트리인지 G-트리인지 아니면 DUDUDUNGA-트리인지 알려주자!

입력
첫 번째 줄에 트리의 정점 수 이 주어진다. ()

두 번째 줄부터 개의 줄에 트리의 각 간선이 잇는 두 정점의 번호 , 가 주어진다. ()

출력
첫 번째 줄에 주어진 트리가 D-트리라면 D, G-트리라면 G, DUDUDUNGA-트리라면 DUDUDUNGA를 출력한다.

풀이:
dfs + 조합 문제, G-트리 = 자식 노드가 3개 이상인 애들에 대해 nC3 , D-트리 = 가운데 두 점을 잡고 양 옆 점의 조합 개수
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
#define DMAX 0xfffffffffffff
int mv1[4] = { 0, 1, 0, -1 };
int mv2[4] = { 1, 0, -1, 0 };
int mv_all1[8] = { 0, 1, 0, -1, -1, -1, 1, 1 };
int mv_all2[8] = { 1, 0, -1, 0 , -1, 1, -1, 1 };

int n;
vector<int> edge[300001];
ll g_cnt = 0;
ll d_cnt = 0;

void dfs(int prev, int now) {

	ll prev_cnt = edge[prev].size() - 1;
	ll now_cnt = edge[now].size() - 1;

	d_cnt += (prev_cnt * now_cnt);

	for (int i = 0; i < edge[now].size(); i++)
	{
		if (edge[now][i] == prev)	continue;
		dfs(now, edge[now][i]);
	}
}

ll comb(ll N) {
	return N * (N - 1) * (N - 2) / 6;
}

int main(void) {
	FIO;

	cin >> n;

	for (int i = 0; i < n - 1; i++)
	{
		int s, e;
		cin >> s >> e;

		edge[s].push_back(e);
		edge[e].push_back(s);
	}

	for (int i = 1; i <= n; i++)
	{
		if (edge[i].size() >= 3) {
			g_cnt += comb(edge[i].size());
		}
	}

	for (int i = 0; i < edge[1].size(); i++)
	{
		dfs(1, edge[1][i]);
	}

	g_cnt *= 3;

	if (d_cnt < g_cnt)
		cout << "G";
	else if (d_cnt > g_cnt)
		cout << "D";
	else
		cout << "DUDUDUNGA";
}