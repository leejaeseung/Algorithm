/*
문제
1부터 N까지의 번호가 부여된 N개의 정점과 N-1개의 간선으로 구성된 트리가 있다. 이 트리의 루트는 1번 정점이며, 임의의 한 정점과 다른 정점 사이의 경로가 반드시 한 개 존재한다.

트리의 각 정점은 특정 색깔을 가지고 있다. 편의상 색깔은 1 이상 C 이하의 자연수로 표현된다. 이때, 질의 f(v,c)를 다음과 같이 정의하자.

f(v, c) : 정점 v가 루트인 부트리(sub-tree)에서 색깔이 c 이하인 정점의 개수

M개의 질의 f(vi, ci)가 주어질 때, 각 질의에 대한 답을 계산하는 프로그램을 작성하시오.

입력
첫 번째 줄에 정점의 수를 나타내는 N(1 ≤ N ≤ 2×105), 질의의 개수를 나타내는 M(1 ≤ M ≤ 2×105), 정점의 색깔 종류를 나타내는 C(1 ≤ C ≤ N)가 공백 하나를 사이에 두고 차례로 주어진다.

두 번째 줄에는 각 정점의 색깔을 나타내는 N개의 정수가 공백으로 구분되어 순서대로 주어진다. 첫 번째 수는 1번 정점의 색깔이며, ..., N 번째 수는 N번 정점의 색깔이다.

세 번째 줄부터 N-1개의 줄에 걸쳐서 트리를 이루는 각 간선의 정보가 주어진다. 각 간선의 정보는 해당 간선을 이루는 서로 다른 두 정점의 번호로 구성된다. 각 정점의 번호는 1 이상 N 이하의 자연수이다.

이후, 이어서 M개의 줄에 걸쳐서 i번째 줄에 i번째 질의의 정보 vi, ci가 공백으로 구분되어 주어진다. vi는 1 이상 N 이하의 정점 번호를 나타낸다. ci는 1 이상 C 이하의 색깔 정보를 나타낸다.

출력
M개의 질의에 대한 정답을 모두 더한 뒤, 1,000,000,007로 나눈 나머지를 출력한다.

풀이:
머지 소트 트리로 풀이했습니다.
먼저, 주어진 트리를 구간 트리로 나타내기 위해 dfs로 탐색하며 인덱스를 새로 부여해 줍니다.

새롭게 만들어진 구간 트리를 머지 소트 방식으로 모든 노드에 각 구간의 color값들을 정렬되게 저장합니다.
만들어진 머지 소트 트리를 탐색하면서 upper_bound로 색C 이하의 개수를 구합니다.
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
#define pic pair<int, char>
#define ll long long
#define vi vector<int>
#define vl vector<long long>
#define vii vector<pii>
#define IMAX 2000000001
#define LMAX 100000000000000
int mv1[4] = { 0, 0, 1, -1 };
int mv2[4] = { 1, -1, 0, 0 };

int n, m, c;
int color[200001];
vi edge[200001];
int arr[200001];
vi tree[800010];
int s[200001];
int e[200001];
int d = 1000000007;
int num = 1;

 void dfs(int now) {

	 s[now] = num;
	 //새로운 구간 트리의 시작구간 저장
	 arr[num++] = color[now];
	//새로운 인덱스에 대한 색깔 값 저장

	for (int i = 0; i < edge[now].size(); i++)
	{
		int next = edge[now][i];
		if (!s[next]) {
			dfs(next);
		}
	}
	e[now] = num - 1;
	//새로운 구간 트리의 끝구간 저장
}

 void init(int now, int s, int e, int idx) {
	 if (idx < s || idx > e)	return;
	 
	 if (s == e) {
		 tree[now].push_back(arr[idx]);
		 return;
	 }
	 init(now * 2, s, (s + e) / 2, idx);
	 init(now * 2 + 1, (s + e) / 2 + 1, e, idx);
 }

 void update(int now, int s, int e) {
	 //머지-소트 과정 -> 그냥 모든 tree[i] 에 대해 sort함수를 써도 된다.
	 if (s == e) {
		 return;
	 }

	 update(now * 2, s, (s + e) / 2);
	 update(now * 2 + 1, (s + e) / 2 + 1, e);

	 vi left = tree[now * 2];
	 vi right = tree[now * 2 + 1];
	 int lidx = 0, ridx = 0;

	 while (left.size() > lidx&& right.size() > ridx) {
		 if (left[lidx] <= right[ridx]) {
			 tree[now].push_back(left[lidx++]);
		 }
		 else {
			 tree[now].push_back(right[ridx++]);
		 }
	 }
	 while (left.size() > lidx) {
		 tree[now].push_back(left[lidx++]);
	 }
	 while (right.size() > ridx) {
		 tree[now].push_back(right[ridx++]);
	 }
 }

 int get(int now, int s, int e, int l, int r, int c) {
	 if (r < s || l > e)	return 0;
	 if (l <= s && e <= r) {
		 return tree[now].size() - (tree[now].end() - upper_bound(tree[now].begin(), tree[now].end(), c));
		 //구간에 포함될 때 카운트 값을 upper_bound로 세어줌
	 }

	 return (get(now * 2, s, (s + e) / 2, l, r, c) + get(now * 2 + 1, (s + e) / 2 + 1, e, l, r, c)) % d;
}

int main(void) {
	FIO;
	cin >> n >> m >> c;

	for (int i = 1; i <= n; i++)
	{
		cin >> color[i];
	}

	for (int i = 0; i < n - 1; i++)
	{
		int s, e;
		cin >> s >> e;
		edge[s].push_back(e);
		edge[e].push_back(s);
	}
	
	dfs(1);

	for (int i = 1; i <= n; i++)
	{
		init(1, 1, n, i);
	}

	update(1, 1, n);

	int ans = 0;

	for (int i = 0; i < m; i++)
	{
		int v, c;
		cin >> v >> c;

		ans = ((ans % d) + (get(1, 1, n, s[v], e[v], c) % d)) % d;
	}

	cout << ans % d;
}