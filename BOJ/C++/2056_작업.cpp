/*
문제
수행해야 할 작업 N개 (3 ≤ N ≤ 10000)가 있다. 각각의 작업마다 걸리는 시간(1 ≤ 시간 ≤ 100)이 정수로 주어진다.

몇몇 작업들 사이에는 선행 관계라는 게 있어서, 어떤 작업을 수행하기 위해 반드시 먼저 완료되어야 할 작업들이 있다. 이 작업들은 번호가 아주 예쁘게 매겨져 있어서, K번 작업에 대해 선행 관계에 있는(즉, K번 작업을 시작하기 전에 반드시 먼저 완료되어야 하는) 작업들의 번호는 모두 1 이상 (K-1) 이하이다. 작업들 중에는, 그것에 대해 선행 관계에 있는 작업이 하나도 없는 작업이 반드시 하나 이상 존재한다. (1번 작업이 항상 그러하다)

모든 작업을 완료하기 위해 필요한 최소 시간을 구하여라. 물론, 서로 선행 관계가 없는 작업들은 동시에 수행 가능하다.

입력
첫째 줄에 N이 주어진다.

두 번째 줄부터 N+1번째 줄까지 N개의 줄이 주어진다. 2번째 줄은 1번 작업, 3번째 줄은 2번 작업, ..., N+1번째 줄은 N번 작업을 각각 나타낸다. 각 줄의 처음에는, 해당 작업에 걸리는 시간이 먼저 주어지고, 그 다음에 그 작업에 대해 선행 관계에 있는 작업들의 개수(0 ≤ 개수 ≤ 100)가 주어진다. 그리고 선행 관계에 있는 작업들의 번호가 주어진다.

출력
첫째 줄에 모든 작업을 완료하기 위한 최소 시간을 출력한다.

풀이:
위상 정렬에 우선순위 큐를 적용한 문제입니다.

위상 정렬을 할 때 해당 노드까지 소모된 시간을 오름차순으로 정렬하게 되면, 더 오래걸리는 작업들은
뒤로 밀리게 되므로 자연스럽게 작업이 빨리 끝나도 다음 노드는 더 긴 시간의 노드를 기다리기 때문에(degree로 인해)
간선이 없는 노드에 다다르면 해당 작업들의 최소 시간이 남게 되고, 모든 작업 set 중 가장 오래 걸린 시간이 정답이 됩니다.
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
#define DMAX 0xFFFFFFFFFFFFF
int mv1[4] = { 0, 1, 0, -1 };
int mv2[4] = { 1, 0, -1, 0 };

int n;
int degree[10001];
int minTime[10001];
int time[10001];
vector<int> edge[10001];

int main(void) {
	FIO;

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		int c;

		cin >> time[i] >> c;

		for (int j = 0; j < c; j++)
		{
			int prev;
			cin >> prev;

			edge[prev].push_back(i);
			degree[i]++;
		}
	}

	priority_queue<pii> q;

	for (int i = 1; i <= n; i++)
	{
		if (degree[i] == 0)
			q.push(make_pair(-time[i], i));
	}

	int ans = 0;

	while (!q.empty()) {
		int nowTime = -q.top().first;
		int now = q.top().second;
		q.pop();

		if (edge[now].size() == 0) {
			ans = max(ans, nowTime);
		}

		for (int i = 0; i < edge[now].size(); i++)
		{
			int next = edge[now][i];

			degree[next]--;
			if (degree[next] == 0) {

				q.push(make_pair(-(nowTime + time[next]), next));
			}
		}
	}

	cout << ans;
}