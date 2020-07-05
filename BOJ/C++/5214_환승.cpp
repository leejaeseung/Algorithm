/*
문제
아주 먼 미래에 사람들이 가장 많이 사용하는 대중교통은 하이퍼튜브이다. 하이퍼튜브 하나는 역 K개를 서로 연결한다. 1번역에서 N번역으로 가는데 방문하는 최소 역의 수는 몇 개일까?

입력
첫째 줄에 역의 수 N과 한 하이퍼튜브가 서로 연결하는 역의 개수 K, 하이퍼튜브의 개수 M이 주어진다. (1 ≤ N ≤ 100,000, 1 ≤ K, M ≤ 1000)

다음 M개 줄에는 하이퍼튜브의 정보가 한 줄에 하나씩 주어진다. 총 K개 숫자가 주어지며, 이 숫자는 그 하이퍼튜브가 서로 연결하는 역의 번호이다.

출력
첫째 줄에 1번역에서 N번역으로 가는데 방문하는 역의 개수의 최솟값을 출력한다. 만약, 갈 수 없다면 -1을 출력한다.

풀이:
bfs문제인데, 간선을 연결하는 부분이 생각해내기 어려운 문제였습니다.
모든 간선을 연결하게 되면 1000 * 1000 * 1000 이 되기 때문에 메모리가 초과됩니다.

각 하이퍼 링크를 그룹으로 묶어 총 m 개의 그룹을 만들고, 각 그룹엔 해당 그룹에 속하는 노드들의 번호를 저장합니다.
또, 노드 번호를 통해 그룹을 찾을 수 있게 각 노드가 속한 그룹들을 저장해 줍니다.

1번 노드부터 bfs를 수행하는데, 각 노드가 속한 그룹들을 찾고, 그 그룹들의 노드들을 큐에 넣어가며 bfs를 진행합니다.
그룹, 노드에 대해 모두 방문 체크를 해줘야 합니다.
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

int n, k, m;
vector<int> member[1001];
vector<int> group[100001];
bool visit[100001];
bool visitG[1001];
int ans = IMAX;

void bfs() {
	queue<pii> q;
	visit[1] = true;
	q.push(make_pair(1, 1));

	while (!q.empty()) {
		int now = q.front().first;
		int nowCnt = q.front().second;
		q.pop();

		if (now == n) {
			ans = min(ans, nowCnt);
		}
		
		for (int i = 0; i < group[now].size(); i++)
		{
			int nowGroup = group[now][i];

			if (!visitG[nowGroup]) {
				visitG[nowGroup] = true;

				for (int j = 0; j < member[nowGroup].size(); j++)
				{
					int next = member[nowGroup][j];

					if (!visit[next]) {
						visit[next] = true;
						q.push(make_pair(next, nowCnt + 1));
					}
				}
			}
		}
	}
}

int main(void) {
	FIO;

	cin >> n >> k >> m;

	for (int i = 1; i <= m; i++)
	{
		for (int j = 0; j < k; j++)
		{
			int v;
			cin >> v;
			member[i].push_back(v);
			group[v].push_back(i);
		}
	}


	bfs();

	if (ans == IMAX)
		cout << "-1";
	else
		cout << ans;
}