/*
문제
민식이는 회사의 매니저이다. 그리고, 민식이는 회사의 중요한 뉴스를 모든 직원에게 빠르게 전달하려고 한다. 민식이의 회사는 트리 구조이다. 모든 직원은 정확하게 한 명의 직속 상사가 있다. 자기자신은 그들 자기 자신의 직접 또는 간접 상사가 아니고, 모든 직원은 민식이의 직접 또는 간접적인 부하이다.

민식이는 일단 자기 자신의 직속 부하에게 한 번에 한 사람씩 전화를 한다. 뉴스를 들은 후에, 각 부하는 그의 직속 부하에게 한 번에 한 사람씩 전화를 한다. 이 것은 모든 직원이 뉴스를 들을 때 까지 계속된다. 모든 사람은 자신의 직속 부하에게만 전화를 걸 수 있고, 전화는 정확하게 1분 걸린다. 이때 모든 직원이 소식을 듣는데 걸리는 시간의 최솟값을 구하는 프로그램을 작성하시오.

오민식의 사원 번호는 0이고, 다른 사원의 번호는 1부터 시작한다.

입력
첫째 줄에 직원의 수 N이 주어진다. 둘째 줄에는 0번 직원부터 그들의 상사의 번호가 주어진다. 반드시 0번 직원 (오민식)의 상사는 -1이고, -1은 상사가 없다는 뜻이다. N은 50보다 작거나 같은 자연수이다.

출력
첫째 줄에 모든 소식을 전하는데 걸리는 시간의 최솟값을 출력한다.

풀이:
트리를 dfs로 순회하는데, 각 노드는 자신의 자식들에서 가장 오래 걸리는 시간을 반환하게 된다.
그리고 부모 노드는 자신의 자식 노드들에게 몇 번째로 전화를 걸지 정해야 한다.

최소 시간을 구해야 하기 때문에 오래 걸리는 노드에게 가장 먼저 전화를 해가면 된다.
(즉, 자식 노드들을 오래 걸리는 순으로 정렬하고, 해당 노드 값에 순서대로 1, 2, 3 ... 을 더한다.)

더해진 값들 중, 최대 값이 해당 부모 노드의 가장 오래 걸리는 시간이 되므로 루트까지 반복하면 된다.
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
int mv_all1[8] = { 0, 1, 0, -1, -1, -1, 1, 1 };
int mv_all2[8] = { 1, 0, -1, 0 , -1, 1, -1, 1 };

int n;
vector<int> child[51];
int ans = 0;

int dfs(int now) {

	int ret = 0;

	if (child[now].size() == 0)
		return ret;

	priority_queue<pii> pq;

	for (int i = 0; i < child[now].size(); i++)
	{
		int next = child[now][i];

		pq.push(make_pair(dfs(next), i));
		//자식 노드를 오래 걸리는 순으로 정렬
	}

	int iter = 0;

	while (!pq.empty())
	{
		int next = pq.top().second;
		int time = pq.top().first + 1 + iter++;
		//오래 걸리는 노드부터 1, 2, 3... 을 더한다.
		pq.pop();

		ret = max(ret, time);
		//가장 오래 걸리는 시간을 갱신
	}

	return ret;
}

int main(void) {
	FIO;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int p;
		cin >> p;
		if (p == -1)	continue;

		child[p].push_back(i);
	}

	cout << dfs(0);
}