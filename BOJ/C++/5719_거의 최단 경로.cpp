/*
����
���� ���� �ڵ��������� GPS �׺���̼� ��� ��ġ�Ǿ� �ִ�. �׺���̼��� ����ڰ� �Է��� ������� ������ ������ �ִ� ��θ� �˻��� �ش�. ������, ���� ��Ȳ�� ������� �ʰ� �ִ� ��θ� �˻��ϴ� ��쿡�� �ؽ��� ���� ��ü�� ������ �� �ִ�.

����̴� ���� �ڱ� �ڽŸ� ��� ������ �׺���̼��� ����� �ִ�. �� �׺���̼��� ����� �ִ� ��θ� ã������ �ʴ´�. �׻� ���� �ִ� ��θ� ã���ش�.

���� �ִ� ��ζ� �ִ� ��ο� ���Ե��� �ʴ� ���ηθ� �̷���� ��� �� ���� ª�� ���� ���Ѵ�.

���� ���, ���� ������ �Ʒ��� ���� ���� �����غ���. ���� ��Ҹ� �ǹ��ϰ�, ���� �ܹ��� ���θ� ��Ÿ����. �������� S, �������� D�� ǥ�õǾ� �ִ�. ���� ���� �ִ� ��θ� ��Ÿ����. (�Ʒ� �׸��� �ִ� ��δ� �� ���� �ִ�)���� �ִ� ��δ� �������� ǥ�õ� ����̴�. �� ��δ� �ִ� ��ο� ���Ե��� ���� ���η� �̷���� ��� �� ���� ª�� ����̴�. ���� �ִ� ��δ� ���� �� ������ ���� �ִ�. ���� ���, �Ʒ� �׸��� ���̰� 3�� ������ ���̰� 1�̶��, ���� �ִ� ��δ� �� ���� �ȴ�. ��, ���� �ִ� ��ΰ� ���� ��쵵 �ִ�.



�Է�
�Է��� ���� ���� �׽�Ʈ ���̽��� �̷���� �ִ�. �� �׽�Ʈ ���̽��� ù° �ٿ��� ����� �� N (2 �� N �� 500)�� ������ �� M (1 �� M �� 104)�� �־�����. ��Ҵ� 0���� N-1������ ��ȣ�� �Ű��� �ִ�. ��° �ٿ��� ������ S�� ������ D�� �־�����. (S �� D; 0 �� S, D < N) ���� M�� �ٿ��� ������ ���� U, V, P�� �־�����. (U �� V ; 0 �� U, V < N; 1 �� P �� 103) �� ���� U���� V�� ���� ������ ���̰� P��� ���̴�. U���� V�� ���� ���δ� �ִ� �� ���̴�. ��, U���� V�� ���� ���ο� V���� U�� ���� ���δ� �ٸ� �����̴�.

�Է��� ������ �ٿ��� 0�� �� �� �־�����.

���
�� �׽�Ʈ ���̽��� ���ؼ�, ���� �ִ� ����� ���̸� ����Ѵ�. ����, ���� �ִ� ��ΰ� ���� ��쿡�� -1�� ����Ѵ�.

Ǯ��:
���ͽ�Ʈ�� + BFS �˰��� �����̴�.
���ͽ�Ʈ��� �ִ� ��θ� ��� ���ϰ�, ���������� ������������ back trace�� �����Ѵ�.
�� �� BFS�� ���������� ���鼭 ��� ������������ ��θ� �����ش�.
(BFS���� �湮 üũ�� ������ �ʾ� ��ä�� �� �޸� �ʰ��� ����. ť�� �ߺ��� ���� ���� ���� �׷��� �ϴ�)

�ִ� ��θ� ���� �� �ٽ� ���ͽ�Ʈ��� ���� ���ϸ� �ȴ�.
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
#define pll pair<ll, ll>
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vii vector<pii>
#define IMAX 2000000001
#define LMAX 1000000000000000000
#define DMAX 0xFFFFFFFFFFFFF
#define MOD 100003
int mv1[4] = { 0, 1, 0, -1 };
int mv2[4] = { 1, 0, -1, 0 };
int mv_all1[8] = { 0, 1, 0, -1, -1, -1, 1, 1 };
int mv_all2[8] = { 1, 0, -1, 0 , -1, 1, -1, 1 };

int n, m;
int s, e;
int dist[501];
vector<pii> edge[501];
vector<int> prv[501];

void Dijkstra() {
	fill(&dist[0], &dist[501], IMAX);
	priority_queue<pii> pq;

	pq.push({ 0, s });
	dist[s] = 0;

	while (!pq.empty()) {
		int now = pq.top().second;
		int nowDis = -pq.top().first;
		pq.pop();

		if (nowDis > dist[now])	continue;

		for (int i = 0; i < edge[now].size(); i++)
		{
			int nx = edge[now][i].first;
			int nxDis = edge[now][i].second;

			if (dist[nx] > dist[now] + nxDis) {
				dist[nx] = dist[now] + nxDis;

				prv[nx].clear();
				prv[nx].push_back(now);

				pq.push({ -dist[nx], nx });
			}
			else if (dist[nx] == dist[now] + nxDis) {
				prv[nx].push_back(now);
			}
		}
	}
}

void BFS() {
	bool visit[501][501];
	fill(&visit[0][0], &visit[500][501], false);

	queue<int> q;
	q.push(e);

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 0; i < prv[now].size(); i++)
		{
			int nx = prv[now][i];

			if (visit[nx][now])	continue;
			visit[nx][now] = true;

			for (int j = 0; j < edge[nx].size(); j++)
			{
				if (edge[nx][j].first == now) {
					edge[nx][j].second = IMAX;
					q.push(nx);
				}
			}
		}
	}
}

int main(void) {
	FIO;

	while (true) {
		cin >> n >> m;

		if (n == 0 && m == 0)	break;

		cin >> s >> e;

		for (int i = 0; i < 501; i++)
		{
			edge[i].clear();
			prv[i].clear();
		}

		for (int i = 0; i < m; i++)
		{
			int a, b, c;
			cin >> a >> b >> c;

			edge[a].push_back({b, c});
		}

		Dijkstra();
		BFS();
		Dijkstra();

		if (dist[e] == IMAX)
			cout << "-1\n";
		else
			cout << dist[e] << "\n";
	}
}