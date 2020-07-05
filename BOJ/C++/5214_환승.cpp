/*
����
���� �� �̷��� ������� ���� ���� ����ϴ� ���߱����� ������Ʃ���̴�. ������Ʃ�� �ϳ��� �� K���� ���� �����Ѵ�. 1�������� N�������� ���µ� �湮�ϴ� �ּ� ���� ���� �� ���ϱ�?

�Է�
ù° �ٿ� ���� �� N�� �� ������Ʃ�갡 ���� �����ϴ� ���� ���� K, ������Ʃ���� ���� M�� �־�����. (1 �� N �� 100,000, 1 �� K, M �� 1000)

���� M�� �ٿ��� ������Ʃ���� ������ �� �ٿ� �ϳ��� �־�����. �� K�� ���ڰ� �־�����, �� ���ڴ� �� ������Ʃ�갡 ���� �����ϴ� ���� ��ȣ�̴�.

���
ù° �ٿ� 1�������� N�������� ���µ� �湮�ϴ� ���� ������ �ּڰ��� ����Ѵ�. ����, �� �� ���ٸ� -1�� ����Ѵ�.

Ǯ��:
bfs�����ε�, ������ �����ϴ� �κ��� �����س��� ����� ���������ϴ�.
��� ������ �����ϰ� �Ǹ� 1000 * 1000 * 1000 �� �Ǳ� ������ �޸𸮰� �ʰ��˴ϴ�.

�� ������ ��ũ�� �׷����� ���� �� m ���� �׷��� �����, �� �׷쿣 �ش� �׷쿡 ���ϴ� ������ ��ȣ�� �����մϴ�.
��, ��� ��ȣ�� ���� �׷��� ã�� �� �ְ� �� ��尡 ���� �׷���� ������ �ݴϴ�.

1�� ������ bfs�� �����ϴµ�, �� ��尡 ���� �׷���� ã��, �� �׷���� ������ ť�� �־�� bfs�� �����մϴ�.
�׷�, ��忡 ���� ��� �湮 üũ�� ����� �մϴ�.
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

int n, k, m;
vector<int> member[1001];
vector<int> group[100001];
bool visit[100001];
bool visitG[1001];
int ans = IMAX;

void bfs() {
	queue<pii> q;
	visit[1] = true;
	q.push(make_pair(1, 1));

	while (!q.empty()) {
		int now = q.front().first;
		int nowCnt = q.front().second;
		q.pop();

		if (now == n) {
			ans = min(ans, nowCnt);
		}
		
		for (int i = 0; i < group[now].size(); i++)
		{
			int nowGroup = group[now][i];

			if (!visitG[nowGroup]) {
				visitG[nowGroup] = true;

				for (int j = 0; j < member[nowGroup].size(); j++)
				{
					int next = member[nowGroup][j];

					if (!visit[next]) {
						visit[next] = true;
						q.push(make_pair(next, nowCnt + 1));
					}
				}
			}
		}
	}
}

int main(void) {
	FIO;

	cin >> n >> k >> m;

	for (int i = 1; i <= m; i++)
	{
		for (int j = 0; j < k; j++)
		{
			int v;
			cin >> v;
			member[i].push_back(v);
			group[v].push_back(i);
		}
	}


	bfs();

	if (ans == IMAX)
		cout << "-1";
	else
		cout << ans;
}