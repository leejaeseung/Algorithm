/*
F. Maximum White Subtree
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given a tree consisting of n vertices. A tree is a connected undirected graph with n−1 edges. Each vertex v of this tree has a color assigned to it (av=1 if the vertex v is white and 0 if the vertex v is black).

You have to solve the following problem for each vertex v: what is the maximum difference between the number of white and the number of black vertices you can obtain if you choose some subtree of the given tree that contains the vertex v? The subtree of the tree is the connected subgraph of the given tree. More formally, if you choose the subtree that contains cntw white vertices and cntb black vertices, you have to maximize cntw−cntb.

Input
The first line of the input contains one integer n (2≤n≤2⋅105) — the number of vertices in the tree.

The second line of the input contains n integers a1,a2,…,an (0≤ai≤1), where ai is the color of the i-th vertex.

Each of the next n−1 lines describes an edge of the tree. Edge i is denoted by two integers ui and vi, the labels of vertices it connects (1≤ui,vi≤n,ui≠vi).

It is guaranteed that the given edges form a tree.

Output
Print n integers res1,res2,…,resn, where resi is the maximum possible difference between the number of white and black vertices in some subtree that contains the vertex i.

풀이:
dfs를 두 번하여 해결했습니다.
첫 번째 dfs에선 각 노드마다 그 노드를 root로 했을 때 나올 수 있는 최댓값을 구해 배열에 저장합니다.

두 번째 dfs에선 root노드부터 leaf노드까지 탐색하는데, 부모의 최댓값을 전파하며 내려갑니다.

자식 노드의 최댓값이 0 이상일 경우 -> max(자식 노드의 최댓값, 부모 노드의 최댓값) 을 전파합니다.
자식 노드의 최댓값이 0 보다 작을 경우 -> max(자식 노드의 최댓값 - 1, 부모 노드의 최댓값) 을 전파합니다.
(자식 노드의 최댓값이 0보다 작다는 건 아무리 최대여도 -1을 해줘야 한다는 뜻입니다.)
*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<vector>
#include<queue>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>
#define ll long long

int N;
int color[200001];
vector<int> vt[200001];
bool visit[200001];
int maxV[200001];
int out[200001];

int dfs(int now) {

	int v = color[now];

	for (int i = 0; i < vt[now].size(); i++)
	{
		int next = vt[now][i];
		
		if (!visit[next]) {
			visit[next] = true;
			v = max(v, dfs(next) + v);
		}
	}

	return maxV[now] = v;
	//now 노드가 root일 때 가질 수 있는 최댓값
}

void dfs2(int now, int prevV) {

	out[now] = prevV;
	//최종 결과값을 배열에 저장

	for (int i = 0; i < vt[now].size(); i++)
	{
		int next = vt[now][i];

		if (!visit[next]) {

			visit[next] = true;

			if(maxV[next] >= 0)
				dfs2(next, max(prevV, maxV[next]));
			//자식 vs 부모 중 큰 값을 전파
			else
				dfs2(next, max(prevV - 1, maxV[next]));
		}
	}
}

int main(void) {
	FIO;

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		int v;
		cin >> v;
		if (v == 0)
			color[i] = -1;
		else
			color[i] = 1;
	}

	for (int i = 0; i < N - 1; i++)
	{
		int a, b;
		cin >> a >> b;

		vt[a].push_back(b);
		vt[b].push_back(a);
	}

	visit[1] = true;
	dfs(1);
	for (int i = 0; i < 200001; i++)
	{
		visit[i] = false;
	}
	visit[1] = true;
	dfs2(1, maxV[1]);

	for (int i = 1; i <= N; i++)
	{
		cout << out[i] << " ";
	}
}