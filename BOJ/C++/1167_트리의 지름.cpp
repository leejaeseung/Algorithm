/*
문제
트리의 지름이란, 트리에서 임의의 두 점 사이의 거리 중 가장 긴 것을 말한다. 트리의 지름을 구하는 프로그램을 작성하시오.

입력
트리가 입력으로 주어진다. 먼저 첫 번째 줄에서는 트리의 정점의 개수 V가 주어지고 (2≤V≤100,000)둘째 줄부터 V개의 줄에 걸쳐 간선의 정보가 다음과 같이 주어진다. (정점 번호는 1부터 V까지 매겨져 있다고 생각한다)

먼저 정점 번호가 주어지고, 이어서 연결된 간선의 정보를 의미하는 정수가 두 개씩 주어지는데, 하나는 정점번호, 다른 하나는 그 정점까지의 거리이다. 예를 들어 네 번째 줄의 경우 정점 3은 정점 1과 거리가 2인 간선으로 연결되어 있고, 정점 4와는 거리가 3인 간선으로 연결되어 있는 것을 보여준다. 각 줄의 마지막에는 -1이 입력으로 주어진다. 주어지는 거리는 모두 10,000 이하의 자연수이다.

출력
첫째 줄에 트리의 지름을 출력한다.

풀이:
dfs를 두 번 사용하여 풀이했습니다.
https://www.acmicpc.net/problem/1967 와 같은 문제.
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
vector<pii> edge[100001];
bool visit[100001];
int idx = 1;
int maxDis = 0;

void dfs(int now, int nowDis) {

	if (maxDis < nowDis) {
		maxDis = nowDis;
		idx = now;
	}

	for (int i = 0; i < edge[now].size(); i++)
	{
		int next = edge[now][i].first;
		int nextDis = edge[now][i].second;

		if (!visit[next]) {
			visit[next] = true;
			dfs(next, nowDis + nextDis);
		}
	}
	visit[now] = false;
}

int main(void) {
	FIO;

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		int prev;
		cin >> prev;

		while (true) {
			int next, dis;
			cin >> next;

			if (next == -1)	break;

			cin >> dis;

			edge[prev].push_back(make_pair(next, dis));
		}
	}

	visit[1] = true;
	dfs(1, 0);

	maxDis = 0;
	visit[idx] = true;
	dfs(idx, 0);

	cout << maxDis;
}