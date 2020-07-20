/*
����
�����ؾ� �� �۾� N�� (3 �� N �� 10000)�� �ִ�. ������ �۾����� �ɸ��� �ð�(1 �� �ð� �� 100)�� ������ �־�����.

��� �۾��� ���̿��� ���� ������ �� �־, � �۾��� �����ϱ� ���� �ݵ�� ���� �Ϸ�Ǿ�� �� �۾����� �ִ�. �� �۾����� ��ȣ�� ���� ���ڰ� �Ű��� �־, K�� �۾��� ���� ���� ���迡 �ִ�(��, K�� �۾��� �����ϱ� ���� �ݵ�� ���� �Ϸ�Ǿ�� �ϴ�) �۾����� ��ȣ�� ��� 1 �̻� (K-1) �����̴�. �۾��� �߿���, �װͿ� ���� ���� ���迡 �ִ� �۾��� �ϳ��� ���� �۾��� �ݵ�� �ϳ� �̻� �����Ѵ�. (1�� �۾��� �׻� �׷��ϴ�)

��� �۾��� �Ϸ��ϱ� ���� �ʿ��� �ּ� �ð��� ���Ͽ���. ����, ���� ���� ���谡 ���� �۾����� ���ÿ� ���� �����ϴ�.

�Է�
ù° �ٿ� N�� �־�����.

�� ��° �ٺ��� N+1��° �ٱ��� N���� ���� �־�����. 2��° ���� 1�� �۾�, 3��° ���� 2�� �۾�, ..., N+1��° ���� N�� �۾��� ���� ��Ÿ����. �� ���� ó������, �ش� �۾��� �ɸ��� �ð��� ���� �־�����, �� ������ �� �۾��� ���� ���� ���迡 �ִ� �۾����� ����(0 �� ���� �� 100)�� �־�����. �׸��� ���� ���迡 �ִ� �۾����� ��ȣ�� �־�����.

���
ù° �ٿ� ��� �۾��� �Ϸ��ϱ� ���� �ּ� �ð��� ����Ѵ�.

Ǯ��:
���� ���Ŀ� �켱���� ť�� ������ �����Դϴ�.

���� ������ �� �� �ش� ������ �Ҹ�� �ð��� ������������ �����ϰ� �Ǹ�, �� �����ɸ��� �۾�����
�ڷ� �и��� �ǹǷ� �ڿ������� �۾��� ���� ������ ���� ���� �� �� �ð��� ��带 ��ٸ��� ������(degree�� ����)
������ ���� ��忡 �ٴٸ��� �ش� �۾����� �ּ� �ð��� ���� �ǰ�, ��� �۾� set �� ���� ���� �ɸ� �ð��� ������ �˴ϴ�.
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

int n;
int degree[10001];
int minTime[10001];
int time[10001];
vector<int> edge[10001];

int main(void) {
	FIO;

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		int c;

		cin >> time[i] >> c;

		for (int j = 0; j < c; j++)
		{
			int prev;
			cin >> prev;

			edge[prev].push_back(i);
			degree[i]++;
		}
	}

	priority_queue<pii> q;

	for (int i = 1; i <= n; i++)
	{
		if (degree[i] == 0)
			q.push(make_pair(-time[i], i));
	}

	int ans = 0;

	while (!q.empty()) {
		int nowTime = -q.top().first;
		int now = q.top().second;
		q.pop();

		if (edge[now].size() == 0) {
			ans = max(ans, nowTime);
		}

		for (int i = 0; i < edge[now].size(); i++)
		{
			int next = edge[now][i];

			degree[next]--;
			if (degree[next] == 0) {

				q.push(make_pair(-(nowTime + time[next]), next));
			}
		}
	}

	cout << ans;
}