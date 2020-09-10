/*
����
��ȣ�� ȸ�翡�� ������ N���� �ְ�, �ؾ��� ���� M���� �ִ�. ������ 1������ N������ ��ȣ�� �Ű��� �ְ�, ���� 1������ M������ ��ȣ�� �Ű��� �ִ�.

�� ������ �� ���� �ϸ� �� �� �ְ�, ������ ���� ����ϴ� ����� 1���̾�� �Ѵ�.

������ ������ �� �� �ִ� ���� ����� �־����� ��, M���� �� �߿��� �ִ� �� ���� �� �� �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ������ �� N�� ���� ���� M�� �־�����. (1 �� N, M �� 1,000)

��° �ٺ��� N���� ���� i��° �ٿ��� i�� ������ �� �� �ִ� ���� ������ �� �� �ִ� ���� ��ȣ�� �־�����.

���
ù° �ٿ� ��ȣ�� ȸ�翡�� �� �� �ִ� ���� ������ ����Ѵ�.

Ǯ��:
��� ������ ������ 1�� �����ϰ� ������-ī�� �˰������� Ǯ���ߴ�.
�Ź� ��θ� ã�� ������ BFS �ϴ��� �ð��� ������ �� ����.

�̺� ��Ī�� Ư���� ����ϸ� �� ����� �ּ� ������ �׻� 1�̴�.
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
int mv1[4] = { 0, 0, 1, -1 };
int mv2[4] = { 1, -1, 0, 0 };
int mv_all1[8] = { 0, 1, 0, -1, -1, -1, 1, 1 };
int mv_all2[8] = { 1, 0, -1, 0 , -1, 1, -1, 1 };

int n, m;
vector<int> edge[2004];
int f[2004][2004];
int c[2004][2004];
int s, e;

int main(void) {
	FIO;

	cin >> n >> m;

	s = 0;
	e = 2003;

	for (int i = 1; i <= n; i++)
	{
		int cnt;
		cin >> cnt;

		edge[0].push_back(i);
		edge[i].push_back(0);
		c[i][0] = 1;
		c[0][i] = 1;

		for (int j = 0; j < cnt; j++)
		{
			int job;
			cin >> job;

			job += 1000;

			edge[i].push_back(job);
			edge[job].push_back(i);
			c[job][i] = 1;
			c[i][job] = 1;
		}
	}

	for (int i = 1001; i <= m + 1000; i++)
	{
		edge[i].push_back(e);
		edge[e].push_back(i);
		c[e][i] = 1;
		c[i][e] = 1;
	}

	int ans = 0;
	
	while (true) {
		int prev[2004];
		fill(&prev[0], &prev[2004], -1);

		queue<int> q;
		q.push(s);

		while (!q.empty() && prev[e] == -1) {
			int now = q.front();
			q.pop();

			for (int i = 0; i < edge[now].size(); i++)
			{
				int next = edge[now][i];

				if (prev[next] == -1 && c[now][next] > f[now][next]) {
					prev[next] = now;

					q.push(next);

					if (next == e)	break;
				}
			}
		}

		if (prev[e] == -1)	break;

		int cur = e;

		while (cur != s) {
			f[prev[cur]][cur] += 1;
			f[cur][prev[cur]] -= 1;

			cur = prev[cur];
		}

		ans++;
	}

	cout << ans;
}