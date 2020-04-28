/*
A. Linova and Kingdom
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Writing light novels is the most important thing in Linova's life. Last night, Linova dreamed about a fantastic kingdom. She began to write a light novel for the kingdom as soon as she woke up, and of course, she is the queen of it.



There are n cities and n−1 two-way roads connecting pairs of cities in the kingdom. From any city, you can reach any other city by walking through some roads. The cities are numbered from 1 to n, and the city 1 is the capital of the kingdom. So, the kingdom has a tree structure.

As the queen, Linova plans to choose exactly k cities developing industry, while the other cities will develop tourism. The capital also can be either industrial or tourism city.

A meeting is held in the capital once a year. To attend the meeting, each industry city sends an envoy. All envoys will follow the shortest path from the departure city to the capital (which is unique).

Traveling in tourism cities is pleasant. For each envoy, his happiness is equal to the number of tourism cities on his path.

In order to be a queen loved by people, Linova wants to choose k cities which can maximize the sum of happinesses of all envoys. Can you calculate the maximum sum for her?

Input
The first line contains two integers n and k (2≤n≤2⋅105, 1≤k<n)  — the number of cities and industry cities respectively.

Each of the next n−1 lines contains two integers u and v (1≤u,v≤n), denoting there is a road connecting city u and city v.

It is guaranteed that from any city, you can reach any other city by the roads.

Output
Print the only line containing a single integer  — the maximum possible sum of happinesses of all envoys.

문제 설명:
루트가 1인 트리가 하나 주어지고, K개의 industry 도시를 정해야 합니다.(루트도 가능)
각 industry 노드에서 루트까지 최소 경로로 갈 때, 거쳐가는 industry가 아닌 노드(tourism 노드)의 개수가 최대가 되도록
해야 합니다.
풀이:
가장 간단하게 생각하면, 모든 리프 노드가 industry 도시라면 최대가 될 것입니다.
하지만 리프 노드의 개수보다 K 가 크면, 리프가 아닌 노드도 industry 도시가 되야 하므로
그 노드의 자식 노드는 happiness가 1만큼 줄어들게 됩니다.

따라서 리프 노드부터 채워가면서, 자식이 있는 노드를 industry 노드로 추가할 때 자식의 총 개수만큼을 정답에서 빼주어야 합니다.
각 노드들을 다음과 같은 순으로 정렬해 주고, 그리디하게 정답을 구합니다.

노드의 깊이 - 자식의 총 개수 -> 큰 순서로 정렬(각 노드를 추가했을 때 얻을 수 있는 최대 값)

정답이 int 범위를 넘어갈 수 있으므로 주의합니다.
*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>
#define ll long long

int N, K;
vector<int> vt[200001];
vector<int> node;
bool visit[200001];
int child[200001];
int depth[200001];

int myCom(int p1, int p2) {
	if (depth[p1] - child[p1] > depth[p2] - child[p2]) {
		//각 노드를 추가했을 때 얻을 수 있는 최댓값
		return 1;
	}
	else
		return 0;
}

int DFS(int now, int d) {
	
	int ch = 0;
	depth[now] = d;
	//각 노드의 깊이를 구합니다.

	for (int i = 0; i < vt[now].size(); i++)
	{
		int next = vt[now][i];
		if (!visit[next]) {
			visit[next] = true;
			ch += DFS(next, d + 1) + 1;
		}
	}
	return child[now] = ch;
	//각 노드의 자식의 총 개수를 구합니다.
}

int main(void) {
	FIO;

	cin >> N >> K;

	for (int i = 0; i < N - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		vt[a].push_back(b);
		vt[b].push_back(a);

		node.push_back(i + 2);
	}
	
	visit[1] = true;
	DFS(1, 0);
	
	sort(node.begin(), node.end(), myCom);

	ll ans = 0;

	for (int i = 0; i < K; i++)
	{
		int now = node[i];
		ans += depth[now] - child[now];
	}

	cout << ans;
}