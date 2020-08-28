/*
문제
대한민국은 동아시아에 위치한 한반도에 위치하고 있다. 3면이 바다인 한국의 서쪽으로 서해, 동쪽으로 동해, 남쪽으로 남해에 의해 둘러싸여 있다.

대한민국의 동해안에는 도시가 N개 있고, 서해안에는 도시가 M개 있다. (M ≤ 1000, N ≤ 1000) 각 도로는 북쪽부터 남쪽까지 번호가 1번부터 매겨져 있다. 새로 취임한 대통령은 서해안과 동해안을 연결하는 K개의 고속도로를 만들려고 한다. 각 고속도로는 동해안에 있는 도시와 서해안에 있는 도시를 연결하는 일직선 도로이다. (원래 일직선인 도로는 운전사를 지루하게 하고 피로감을 느끼게 하여 사고의 원인이 되므로, 일부러 고저를 만들거나 커브를 만들어서 그러한 일이 일어나지 않도록 설계되어 있다)

고속도로가 서로 교차하는 곳에는 휴게소를 지으려고 한다. 한 점에서 교차하는 고속도로는 최대 2개이다. 고속도로가 주어졌을 때, 고속도로가 교차하는 곳의 개수를 구하는 프로그램을 작성하시오.

입력
입력의 첫째 줄에는 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스의 첫째 줄에는 N, M, K가 주어진다. K는 고속도로의 수이다. 둘째 줄부터 K개의 줄에는 고속도로의 정보가 주어진다. 고속도로의 정보는 숫자 2개로 이루어져 있다. 첫 번째 숫자는 동해안에 있는 도시의 번호이고, 두 번째 숫자는 서해안에 있는 도시의 번호이다.

고속도로의 개수는 40만개보다 작거나 같으며, 문제의 정답dl 263-1보다 작거나 같은 경우만 입력으로 주어진다.

출력
각 테스트 케이스에 대해서, 교차점의 수를 케이스 번호와 함께 출력한다.

풀이:
https://www.acmicpc.net/problem/3653
와 비슷한 방식으로 풀이했다.

M 개의 구간합을 관리하는데, 맨 처음엔 0 ~ M 에 도착지 노드의 개수를 업데이트한다.
동해안을 오름차순으로 보고, 연결된 서해안도 오름차순으로 보면서,
서해안 x 번의 휴게소 개수는 0 ~ (x - 1) 구간합의 결과이다.
중복을 막기 위해 이미 본 서해안의 수는 -1 해준다.
*/
#include<iostream>
#include<memory.h>
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
int mv1[4] = { 0, 0, 1, -1 };
int mv2[4] = { 1, -1, 0, 0 };
int mv_all1[8] = { 0, 1, 0, -1, -1, -1, 1, 1 };
int mv_all2[8] = { 1, 0, -1, 0 , -1, 1, -1, 1 };

int t, n, m, k;
ll tree[5001];
vector<int> edge[1001];

void update(int now, int s, int e, int idx, ll v) {
	if (idx > e || s > idx)	return;

	if (s == e) {
		tree[now] += v;
		return;
	}

	update(now * 2, s, (s + e) / 2, idx, v);
	update(now * 2 + 1, (s + e) / 2 + 1, e, idx, v);

	tree[now] = tree[now * 2] + tree[now * 2 + 1];
}

ll get(int now, int s, int e, int l, int r) {
	if (r < s || l > e)	return 0;
	if (l <= s && r >= e)	return tree[now];

	return get(now * 2, s, (s + e) / 2, l, r) + get(now * 2 + 1, (s + e) / 2 + 1, e, l, r);
}

int main(void) {
	FIO;

	cin >> t;

	for (int test = 1; test <= t; test++) {
		cin >> n >> m >> k;

		for (int i = 0; i < 5001; i++)
			tree[i] = 0;

		for (int i = 0; i < 1001; i++)
			edge[i].clear();

		for (int i = 0; i < k; i++)
		{
			int s, e;
			cin >> s >> e;

			edge[s].push_back(e);
			update(1, 0, m - 1, e - 1, 1);
		}

		ll ans = 0;

		for (int i = 1; i <= n; i++)
		{
			sort(edge[i].begin(), edge[i].end());

			for (int j = 0; j < edge[i].size(); j++)
			{
				int tgt = edge[i][j];

				ans += get(1, 0, m - 1, 0, tgt - 2);
				update(1, 0, m - 1, tgt - 1, -1);
			}
		}

		cout << "Test case " << test <<  ": " << ans << "\n";
	}
}