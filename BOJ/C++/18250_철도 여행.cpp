/*
문제
한국에는 N개의 도시 C1, C2, ..., CN가 있고, 두 개의 도시를 양방향으로 잇는 M개의 철도 노선이 있다.

철도를 좋아하는 가희는 철도 여행을 하려고 한다. 철도 여행이란 시작 도시에서 도착 도시까지 철도 노선만을 이용해 이동하는데, 하나의 철도 노선을 두 번 이상 타지 않는 것을 의미한다. 시작 도시와 도착 도시는 같을 수도 있으며, 하나의 도시를 여러 번 방문할 수도 있다.

가희는 최소 횟수의 철도 여행으로 모든 노선을 정확히 한 번씩 타고자 한다. 가희가 철도 여행을 몇 번 해야 하는지 구해보자.

입력
입력의 첫 줄에 두 정수 N(1 ≤ N ≤ 200,000)과 M(1 ≤ M ≤ 300,000)이 주어진다.

이후 M개의 줄에 걸쳐 서로 다른 두 정수 u, v(1 ≤ u, v ≤ N)가 주어진다. 이는 Cu와 Cv를 양방향으로 잇는 철도 노선이 존재함을 의미한다.

단, 두 개의 도시를 직접 잇는 철도 노선은 많아야 하나이다.

출력
가희가 해야 하는 철도 여행의 최소 횟수를 출력한다.

풀이:
한붓그리기(오일러 경로) 문제였습니다.
단, 그룹이 여러 개가 생길 수 있으므로 유니온-파인드 알고리즘을 적용해주어야 합니다.

각 그룹마다, 홀수 점의 개수를 카운트하고, 홀수 점이 없으면 +1, 홀수 점이 있다면 (홀수 점) / 2 개를 추가해 줍니다.
그룹에 하나의 노드만 있는 경우(경로가 이어지지 않은 노드)는 걸러줍니다.
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
int cnt[200001];
int parent[200001];
bool group[200001];
int g_odd[200001];
int group_cnt[200001];

int find(int now) {
	if (parent[now] == now)
		return now;

	return parent[now] = find(parent[now]);
}

void merge(int x, int y) {

	x = find(x);
	y = find(y);

	if (x != y) {
		parent[x] = y;
	}
}

int main(void) {
	FIO;

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
	}

	for (int i = 0; i < m; i++)
	{
		int s, e;
		cin >> s >> e;
		cnt[s]++;
		cnt[e]++;
		merge(s, e);
	}

	for (int i = 1; i <= n; i++)
	{
		int p = find(i);
		if (!group[p]) {
			group[p] = true;
		}
		if (cnt[i] % 2 != 0)
			g_odd[p]++;
		group_cnt[p]++;
	}

	int ans = 0;

	for (int i = 1; i <= n; i++)
	{
		if (group_cnt[i] == 1)	continue;
		if (group[i]) {
			if (g_odd[i] == 0)
				ans++;
			else
				ans += (g_odd[i] / 2);
		}
	}

	cout << ans;
} 