/*
B. Jzzhu and Cities
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Jzzhu is the president of country A. There are n cities numbered from 1 to n in his country. City 1 is the capital of A. Also there are m roads connecting the cities. One can go from city ui to vi (and vise versa) using the i-th road, the length of this road is xi. Finally, there are k train routes in the country. One can use the i-th train route to go from capital of the country to city si (and vise versa), the length of this route is yi.

Jzzhu doesn't want to waste the money of the country, so he is going to close some of the train routes. Please tell Jzzhu the maximum number of the train routes which can be closed under the following condition: the length of the shortest path from every city to the capital mustn't change.

Input
The first line contains three integers n, m, k (2 ≤ n ≤ 105; 1 ≤ m ≤ 3·105; 1 ≤ k ≤ 105).

Each of the next m lines contains three integers ui, vi, xi (1 ≤ ui, vi ≤ n; ui ≠ vi; 1 ≤ xi ≤ 109).

Each of the next k lines contains two integers si and yi (2 ≤ si ≤ n; 1 ≤ yi ≤ 109).

It is guaranteed that there is at least one way from every city to the capital. Note, that there can be multiple roads between two cities. Also, there can be multiple routes going to the same city from the capital.

Output
Output a single integer representing the maximum number of the train routes which can be closed.

풀이:
다익스트라 알고리즘입니다.
canGo[i] = train이 없어도 i번째 도시를 갈 수 있는 지
최단 경로를 갱신했는데 사용한 길이 train 이라면 그 train은 꼭 필요하므로 canGo 를 false로 바꿉니다.
만약 최단 경로를 갱신했는데 사용한 길이 train이 아니라면 train없이 갈 수 있으므로 canGo를 true로 바꿉니다.

길이가 같은 경우에도 train을 안쓰고 갈 수 있다면 canGo를 true로 바꿉니다.

visit배열을 사용하지 않았을 때 45번 TC에서 시간 초과가 났습니다.
아마 중복된 길을 가는걸 최소화하는 용도인 듯 한데 더 공부해봐야 할 것 같습니다.
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
#define pil pair<int, long long>
#define pli pair<long long, int>
#define ll long long
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vii vector<pii>
#define IMAX 2000000001
#define LMAX 9000000000000000000
#define DMAX 0xFFFFFFFFFFFFF
int mv1[4] = { 0, 1, 0, -1 };
int mv2[4] = { 1, 0, -1, 0 };

int n, m, k;
vector<pair<pil, bool>> edge[100001];
ll dist[100001];
bool visit[100001];
bool canGo[100001];

void Dijkstra() {
	priority_queue<pli> pq;
	dist[1] = 0;
	visit[1] = true;
	pq.push(make_pair(0, 1));

	while (!pq.empty()) {
		ll nowD = -pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (nowD < dist[now])
			continue;
		visit[now] = false;
		for (int i = 0; i < edge[now].size(); i++)
		{
			int next = edge[now][i].first.first;
			ll dis = edge[now][i].first.second;
			bool isTrain = edge[now][i].second;

			if (dist[next] > dist[now] + dis) {
				if (!isTrain)
					canGo[next] = true;
				else
					canGo[next] = false;
				dist[next] = dist[now] + dis;
				if (!visit[next]) {
					//중복된 경로를 최소화?
					visit[next] = true;
					pq.push(make_pair(-dist[next], next));
				}
			}
			else if (dist[next] == dist[now] + dis) {
				if (!isTrain)
					canGo[next] = true;
			}
		}
	}
}

int main(void) {
	FIO;

	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++)
	{
		dist[i] = LMAX;
	}

	for (int i = 0; i < m; i++)
	{
		int s, e;
		ll v;
		cin >> s >> e >> v;

		edge[s].push_back(make_pair(make_pair(e, v), false));
		edge[e].push_back(make_pair(make_pair(s, v), false));
	}

	for (int i = 0; i < k; i++)
	{
		int s;
		ll v;
		cin >> s >> v;
		edge[1].push_back(make_pair(make_pair(s, v), true));
		edge[s].push_back(make_pair(make_pair(1, v), true));
	}

	Dijkstra();

	for (int i = 2; i <= n; i++)
	{
		if (!canGo[i])
			k--;
	}
	
	cout << k;
}