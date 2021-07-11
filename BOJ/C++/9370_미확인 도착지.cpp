/*
����
(����)B100 ���, ����� �������� �� ��Ŀ�� ������ �� ���� �� ������ �Ÿ����� �̵��ϰ� �ִ�. ���� �ӹ��� �׵��� ���� ���� �ִ��� �˾Ƴ��� ���̴�. �츮�� �˾Ƴ� ���� �׵��� s�������� ����ߴٴ� ��, �׸��� ������ �ĺ��� �� �ϳ��� �׵��� ��������� ���̴�. �׵��� ���� ��Ȳ�̱� ������ ���������� ��ȸ���� �ʰ� �ִܰŸ��� �� ���̶� Ȯ���Ѵ�. �̻��̴�. (����)

����! (����� �������� �������� ��) ����� ��𿡵� ������ �ʴ´�. �������� ����� �İ��� ����ŭ �پ��. �� �İ����� �׵��� g�� h ������ ���̿� �ִ� ���θ� �������ٴ� ���� �˾Ƴ´�.

�� ����� ��ü ���� ���� �ִ� ���ϱ�?



���� �Է��� �� ��° ���̽��� �ð�ȭ�� ���̴�. �� ����� ȸ�� ������ �� ���� �� �� �ϳ��� ���� �ְ� �������� ǥ�õ� ���ο��� ������ �þҴ�. ���� �׵��� 6���� ���ϰ� �ִ�.

�Է�
ù ��° �ٿ��� �׽�Ʈ ���̽��� T(1 �� T �� 100)�� �־�����. �� �׽�Ʈ ���̽�����

ù ��° �ٿ� 3���� ���� n, m, t (2 �� n �� 2 000, 1 �� m �� 50 000 and 1 �� t �� 100)�� �־�����. ���� ������, ����, ������ �ĺ��� �����̴�.
�� ��° �ٿ� 3���� ���� s, g, h (1 �� s, g, h �� n)�� �־�����. s�� ���������� ������̰�, g, h�� ���� ���� ���� �ִ�. (g �� h)
�� ���� m���� �� �ٸ��� 3���� ���� a, b, d (1 �� a < b �� n and 1 �� d �� 1 000)�� �־�����. a�� b ���̿� ���� d�� ����� ���ΰ� �ִٴ� ���̴�.
�� ���� t���� �� �ٸ��� ���� x�� �־����µ�, t���� ������ �ĺ����� �ǹ��Ѵ�. �� t���� �������� ���� �ٸ� ��ġ�̸� ��� s�� ���� �ʴ�.
������ ���̿��� ���ΰ� ���ƺ��� 1���̴�. m���� �� �߿��� g�� h ������ ���θ� ��Ÿ�� ���� �����Ѵ�. ���� �� ���δ� ������ �ĺ��� �� ��� 1���� ���ϴ� �ִ� ����� �Ϻ��̴�.

���
�׽�Ʈ ���̽�����

�Է¿��� �־��� ������ �ĺ��� �� �Ұ����� ������ ������ ���������� �������� �и���Ų ���������� ������� ����Ѵ�.

Ǯ��:
���ͽ�Ʈ���� �ִ� ��θ� ��� ã�� �����̴�.
���ͽ�Ʈ�� �� ������ ������������ ��� �ִ� ��θ� prv �κ��� �� �� �ְ�,
prv�� dfs�� ��ȸ�ϸ鼭 g, h �� ��ΰ� ���ԵǾ����� üũ�ϸ� �ȴ�.
*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<regex>
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

int T;
int n, m, t, s, g, h;
vector<pii> vt[2001];
int dist[2001];
vector<int> prv[2001];


void Dijkstra(int start) {
	priority_queue<pii> pq;
	pq.push({ 0, start });
	dist[start] = 0;

	while (!pq.empty()) {
		int nowDis = -pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (nowDis > dist[now])	continue;

		for (int i = 0; i < vt[now].size(); i++)
		{
			int next = vt[now][i].first;
			int nextDis = vt[now][i].second;

			if (dist[next] > dist[now] + nextDis) {
				dist[next] = dist[now] + nextDis;
				prv[next].clear();
				prv[next].push_back(now);

				pq.push({ -dist[next], next });
			}
			else if (dist[next] == dist[now] + nextDis) {
				prv[next].push_back(now);
			}
		}
	}
}

bool dfs(int now) {
	
	bool find = false;

	for (int i = 0; i < prv[now].size(); i++)
	{
		int next = prv[now][i];

		if ((now == g && next == h) || (now == h && next == g)) {
			find = true;
			break;
		}
		else {
			find = dfs(next);
			if (find)
				return true;
		}
	}

	return find;
}

int main(void) {
	FIO;

	cin >> T;

	while (T--) {
		cin >> n >> m >> t >> s >> g >> h;
		
		priority_queue<int> dest;

		for (int i = 0; i < 2001; i++)
		{
			vt[i].clear();
			dist[i] = IMAX;
			prv[i].clear();
		}

		for (int i = 0; i < m; i++)
		{
			int a, b, d;
			cin >> a >> b >> d;

			vt[a].push_back({ b, d });
			vt[b].push_back({ a, d });
		}

		for (int i = 0; i < t; i++)
		{
			int x;
			cin >> x;
			dest.push(-x);
		}

		Dijkstra(s);

		while (!dest.empty()) {
			int now = -dest.top();
			dest.pop();

			if (dfs(now))
				cout << now << " ";
		}

		cout << "\n";
	}
}