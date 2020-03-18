/*

문제
영선이는 요즘 여행에 빠져있다. 그래서 짧게나마 여행을 다녀오고 싶었던 영선이는 주말을 활용해 여행 갈 계획을 세우고 있다. 하지만 영선이는 가고 싶은 여행지가 너무 많아 고민 중이며, 숙소 또한 좋은 곳으로 가고 싶기에 여행지와 숙소를 기반으로 계획을 작성하려 한다.

영선이는 가고 싶은 여행지 리스트와 숙소 리스트를 미리 조사하여 작성했다. 그리고 각 여행지와 숙소에 조사한 자료를 통해 기대치를 매겼다. 시간이 없기에 영선이는 여행지 한 곳, 숙소 한 곳을 방문할 것이며, 이때 선택된 장소들의 기대치 합이 최대가 되는 여행 계획을 작성할 것이다.



또한, 여행지와 숙소 사이의 거리가 멀다면 여행지에서 관광을 하는 시간이 줄어들기 때문에, 여행 자체의 재미가 줄어든다고 생각했다. 결국 영선이는 기대치 합에서 둘 사이 거리를 빼기로 하였다.

즉, 여행 계획은 여행지, 숙소 각각의 기대치의 합에서 둘 사이의 거리를 뺀 값을 최대로 하는 계획을 작성하려고 한다. 하지만 어떤 문제나 그렇듯 영선이는 매우 바쁜 관계로 계획을 세울 시간이 없다. 그렇기 때문에 계획을 세우는 것을 당신에게 부탁했다. 영선이가 작성한 여행지와 숙소 리스트 및 인근 지역의 지도를 토대로 영선이의 주말 여행 계획을 세워주자.

입력
프로그램의 입력은 표준 입력으로 받는다. 여행을 하고자 하는 지역의 지도는 다음과 같은 정보가 주어진다. 주요 지점들 n개와 그 사이를 연결하는 도로가 주어지고, 도로에는 거리가 표기되어 있다. 여행지와 숙소들은 각각 한 지점에 표기되어 있으며, 여행지와 숙소는 같은 지점에 위치해 있지 않는다. 그리고 모든 지점들은 다른 지점으로 도로를 통하여 이동할 수 있는 경로가 존재한다.

입력의 첫 줄에는 지점의 개수 n이 주어진다. (2 ≤ n ≤ 1000)

다음 n줄에는 각 줄마다 n개의 정수가 주어지며, i번째 줄의 j번째 수 dij 는 i번째 지점에서 j번째 지점까지의 거리이다. 만약 거리가 0이라면 둘 사이의 도로는 존재하지 않는다(0 ≤ dij ≤ 5000, dij = dji , dii = 0)

다음 줄에는 리스트에 작성된 여행지의 개수 p, 숙소의 개수 q가 주어진다. (1 ≤ p,q ≤ n, 2 ≤ p+q ≤ n)

다음 p줄에는 여행지가 위치한 지점번호 lj 과 기대치 wj 가 주어진다.(1 ≤ lj ≤ n, 1 ≤ wj ≤ 5000)

다음 q줄에는 숙소가 위치한 지점번호 li 과 기대치 wi 가 주어진다.(1 ≤ li ≤ n, 1 ≤ wi ≤ 5000)

출력
프로그램의 출력은 표준 출력으로 한다. 여행지와 숙소의 쌍 중 각각의 기대치의 합에서 둘 사이의 거리를 뺀 값이 최대가 되는 값을 출력하시오. 이때, 여행지와 숙소 사이의 경로에 다른 여행지나 숙소가 존재해도 무방하다.

풀이:
기존 다익스트라 알고리즘은 시작점을 0으로 두고 하지만, 이 문제에선 (여행지들의 기대치 * -1) 로 주고 모든 여행지를 시작 큐에 넣고
다익스트라 알고리즘을 수행한다.
그 뒤, 숙소 기대치 - dist 를 해주게 되면 거리값은 숙소 기대치에서 뺴지고, 여행지의 기대치는 처음에 빼주었지 때문에 다시 더해지게 된다.
*/
#include<iostream>
#include<algorithm>
#include<queue>
#include<utility>
#include<vector>
#include<math.h>
using namespace std;

int N, p, q;
long long map[1001][1001];
long long dist[1001];
vector<pair<int, long long> > s;
vector<pair<int, long long > > e;

void Dijkstra() {
	priority_queue<pair<long long, int> > pq;

	int start;
	for (int i = 0; i < s.size(); i++)
	{
		int start = s.at(i).first;
		dist[start] = s.at(i).second * -1;
		pq.push(make_pair(0, start));
		
	}

	while (!pq.empty()) {
		int now = pq.top().second;
		pq.pop();

		for (int i = 1; i <= N ; i++)
		{
			if (map[now][i] == 0)	continue;

			if (dist[i] > dist[now] + map[now][i]) {
				dist[i] = dist[now] + map[now][i];
				pq.push(make_pair(dist[i], i));
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		dist[i] = 1000000000000000000;
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}
	cin >> p >> q;

	for (int i = 0; i < p; i++)
	{
		int n, v;
		cin >> n >> v;
		s.push_back(make_pair(n, v));
	}
	
	for (int i = 0; i < q; i++)
	{
		int n, v;
		cin >> n >> v;
		e.push_back(make_pair(n, v));
	}
	Dijkstra();
	long long ans = -100000000000000;

	for (int i = 0; i < e.size(); i++)
	{
			int q = e.at(i).first;
			long long q_v = e.at(i).second;

			ans = max(ans, q_v - dist[q]);
	}
	cout << ans;
}