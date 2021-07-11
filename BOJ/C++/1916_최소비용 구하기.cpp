/*
����
N���� ���ð� �ִ�. �׸��� �� ���ÿ��� ����Ͽ� �ٸ� ���ÿ� �����ϴ� M���� ������ �ִ�. �츮�� A��° ���ÿ��� B��° ���ñ��� ���µ� ��� ���� ����� �ּ�ȭ ��Ű���� �Ѵ�. A��° ���ÿ��� B��° ���ñ��� ���µ� ��� �ּҺ���� ����Ͽ���. ������ ��ȣ�� 1���� N�����̴�.

�Է�
ù° �ٿ� ������ ���� N(1 �� N �� 1,000)�� �־����� ��° �ٿ��� ������ ���� M(1 �� M �� 100,000)�� �־�����. �׸��� ��° �ٺ��� M+2�ٱ��� ������ ���� ������ ������ �־�����. ���� ó������ �� ������ ��� ������ ��ȣ�� �־�����. �׸��� �� �������� �������� ���� ��ȣ�� �־����� �� �� ���� ����� �־�����. ���� ����� 0���� ũ�ų� ����, 100,000���� ���� �����̴�.

�׸��� M+3° �ٿ��� �츮�� ���ϰ��� �ϴ� ���� ������� ���ù�ȣ�� �������� ���ù�ȣ�� �־�����. ��������� �������� �� �� �ִ� ��츸 �Է����� �־�����.

���
ù° �ٿ� ��� ���ÿ��� ���� ���ñ��� ���µ� ��� �ּ� ����� ����Ѵ�.

Ǯ��:
���ͽ�Ʈ�� ��������
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
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define pic pair<int, char>
#define ll long long
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vii vector<pii>
#define IMAX 2147483647
#define LMAX 1000000000000500000
#define DMAX 0xFFFFFFFFFFFFF
int mv1[4] = { 0, 1, -1, 0 };
int mv2[4] = { 1, 0, 0, -1 };

int n, m;
vector<pll> vt[1001];
ll dist[1001];
int s, e;

void Dijkstra() {
	dist[s] = 0;

	priority_queue<pll> pq;
	pq.push({ 0, s });

	while (!pq.empty()) {
		ll nowDis = -pq.top().first;
		ll now = pq.top().second;
		pq.pop();

		if (nowDis > dist[now])	continue;

		for (int i = 0; i < vt[now].size(); i++)
		{
			ll next = vt[now][i].first;
			ll nextDis = vt[now][i].second;

			if (dist[next] > dist[now] + nextDis) {
				dist[next] = dist[now] + nextDis;
				pq.push({ -dist[next], next });
			}
		}
	}
	
}

int main(void) {
	FIO;

	cin >> n >> m;
	fill(&dist[0], &dist[1001], LMAX);

	for (int i = 0; i < m; i++)
	{
		ll from, to, v;
		cin >> from >> to >> v;

		vt[from].push_back({ to, v });
	}
	
	cin >> s >> e;

	Dijkstra();

	cout << dist[e];
}