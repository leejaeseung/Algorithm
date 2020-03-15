/*
문제
영선회사에는 치명적인 악습이 있는데, 바로 상사가 직속 부하를 갈구면 그 부하가 부하의 직속 부하를 연쇄적으로 갈구는 내리 갈굼이 있다. 즉, 상사가 한 직속 부하를 갈구면 그 부하의 모든 부하들이 갈굼을 당한다.

갈굼에 대해 정도에 대한 수치가 주어지는데, 이 수치 또한 부하들에게 똑같이 갈궈진다.

직속 상사와 직속 부하관계에 대해 주어지고, 갈굼에 대한 정보가 주어질 때, 각자 얼마의 갈굼을 당했는지 출력하시오,

입력
첫째 줄에는 회사의 직원 수 n명, 최초의 갈굼 횟수 m이 주어진다. 직원은 1번부터 n번까지 번호가 매겨져 있다. (2 ≤ n, m ≤ 100,000)

둘째 줄에는 직원 n명의 직속 상사의 번호가 주어진다. 직속 상사의 번호는 자신의 번호보다 작으며, 최종적으로 1번이 사장이다. 1번의 경우, 상사가 없으므로 -1이 입력된다.

다음 m줄에는 직속 상사로부터 갈굼을 당한 직원 번호 i,갈굼의 수치 w가 주어진다.(2 ≤ i ≤ n, 1 ≤ w ≤ 1,000) 사장은 상사가 없으므로 갈굼을 당하지 않는다.

출력
1번부터 n번의 직원까지 갈굼을 당한 정도를 출력하시오.

풀이:
각 노드들에 갈굼 정도를 저장해놓고, 루트부터 leaf 노드까지 dsf로 갈굼을 전달해준다.
*/

#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

int N, M;
int cost[100001];
vector< int > man[100001];

void search() {
	queue<int> q;
	q.push(1);

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 0; i < man[now].size(); i++)
		{
			int next = man[now].at(i);
			cost[next] += cost[now];
			q.push(next);
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		int n;
		cin >> n;
		if (n == -1) continue;
		man[n].push_back(i);
	}

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;

		cost[a] += b;

	}
	search();
	for (int i = 1; i <= N; i++)
	{
		cout << cost[i] << " ";
	}
}