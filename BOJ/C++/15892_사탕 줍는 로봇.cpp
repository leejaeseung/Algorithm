/*
����
�Ʊ� ��ȯ�� �Ʊ��. �Ʊ� ��ȯ�̴� ������ ���ƴٴϸ� ������ �ѷ� ���� ���� ����. �����̴� �Ʊ� ��ȯ�̶����� ���� ���������� ��ġ�� ������. �̸� �ذ��ϱ� ���� �����̴� ���� û�ҷκ��� �������.

�����̳� ���� n���� ��� m���� ������ �̷���� �ְ�, �ϳ��� ������ ���� �ٸ� �� ���� ���� �����Ͽ� �� �� ���̸� �����Ӱ� ���� �� �ֵ��� �Ѵ�. �� �濡�� 1������ n������ ��ȣ�� �پ��ִ�. �Ʊ� ��ȯ�̴� �������� ������ �ѷ� �ξ���. ���� ���� �� �������� �������� ������ �����ϰ�, �� �ȿ��� ������ ����.

�����̰� ���� �κ��� ������ ���� �����Ѵ�.

�����̰� �κ��� ���۹� ��ȣ�� ������ ��ȣ, �κ��� �̵���θ� �Է��ϰ� �� �κ��� ���۹濡 ���Ƶθ�, �κ��� �˾Ƽ� �Է��� ��θ� ���� ��������� �����δ�.
�κ��� ������ �����ϴ� ������ ������ �� �ִ�. �׸��� ���� �ϳ��� ������ �� �� ������ �ִ� ���� �� �� 1���� �ֿ� ��������. �����̴� �� ������ �����ϴ� ��θ� �Է��� �� �ִ�.
�����̴� �� �κ��� �̿��� �Ʊ� ��ȯ�̰� �������� ���� ���� û���ϸ鼭�� ������ ��̸� �߱��� ����� �����ߴ�. ��� �κ��� 1�� �濡�� ����� n�� ������ �����ϰ� �ϸ鼭�� ��θ� ���� �� �����ϸ�, �κ����� ������ �����ϰ� ���ƴٴϸ� ������ �ֿ� ���̴�. �̶�, �����̴� �κ��� �ִ� �� ���� ������ �� �������� �˰� �ʹ�. �������� �������� �ñ����� �ذ�������.

�Է�
ù ��° �ٿ� �����̳� ���ȿ� �ִ� ���� ������ ��Ÿ���� �ڿ��� n(2 �� n �� 300)�� ������ ������ ��Ÿ���� �ڿ��� m(1 �� m �� 5,000)�� �������� ���еǾ� �־�����.

�� ��° �ٺ��� m���� �ٿ� ���� ������ ������ �� �ٿ� �ϳ��� �־�����. �� �ٿ��� �� ���� �ڿ��� a, b, c�� �־����µ�, �̴� a�� ��� b�� �� ���̿� ������ �ְ� �� �������� c���� ������ �����ִٴ� ���� �ǹ��Ѵ�. (a �� b,  1 �� a, b �� n,  1 �� c �� 100)

���
ù ��° �ٿ� �����̰� ������ �� �ִ� �κ��� �ִ��� ����Ѵ�.

Ǯ��:
�ִ� ���� �⺻ ����.
*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>
#define pic pair<int, char>
#define ll long long
#define vi vector<int>
#define vl vector<long long>
#define vii vector<pii>

int n, m;
int c[301][301];
int f[301][301];
vector<int> edge[301];
int pre[301];

void bfs() {

	queue<int> q;
	q.push(1);

	while (!q.empty()) {
		int now = q.front();	q.pop();

		for (size_t i = 0; i < edge[now].size(); i++)
		{
			int next = edge[now][i];

			if (pre[next] != -1)	continue;
			if (next == 1)	continue;

			if (c[now][next] - f[now][next] > 0) {
				
				pre[next] = now;
				q.push(next);
				

				if (next == n)	break;
			}
		}
	}
}

int main(void) {
	FIO;

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b, v;
		cin >> a >> b >> v;

		edge[a].push_back(b);
		edge[b].push_back(a);
		c[a][b] += v;
		c[b][a] += v;
	}

	int ans = 0;

	while (1) {

		for (int i = 0; i <= n; i++)
		{
			pre[i] = -1;
		}

		bfs();

		if (pre[n] == -1)	break;

		int now = n;
		int maxC = 1000000000;

		while (pre[now] != -1) {
			maxC = min(maxC, c[pre[now]][now] - f[pre[now]][now]);

			now = pre[now];
		}

		now = n;

		while (pre[now] != -1) {
			f[now][pre[now]] -= maxC;
			f[pre[now]][now] += maxC;

			now = pre[now];
		}

		ans += maxC;
	}

	cout << ans;
}