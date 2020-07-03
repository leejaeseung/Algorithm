/*
����
Ʈ���� �����̶�, Ʈ������ ������ �� �� ������ �Ÿ� �� ���� �� ���� ���Ѵ�. Ʈ���� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
Ʈ���� �Է����� �־�����. ���� ù ��° �ٿ����� Ʈ���� ������ ���� V�� �־����� (2��V��100,000)��° �ٺ��� V���� �ٿ� ���� ������ ������ ������ ���� �־�����. (���� ��ȣ�� 1���� V���� �Ű��� �ִٰ� �����Ѵ�)

���� ���� ��ȣ�� �־�����, �̾ ����� ������ ������ �ǹ��ϴ� ������ �� ���� �־����µ�, �ϳ��� ������ȣ, �ٸ� �ϳ��� �� ���������� �Ÿ��̴�. ���� ��� �� ��° ���� ��� ���� 3�� ���� 1�� �Ÿ��� 2�� �������� ����Ǿ� �ְ�, ���� 4�ʹ� �Ÿ��� 3�� �������� ����Ǿ� �ִ� ���� �����ش�. �� ���� ���������� -1�� �Է����� �־�����. �־����� �Ÿ��� ��� 10,000 ������ �ڿ����̴�.

���
ù° �ٿ� Ʈ���� ������ ����Ѵ�.

Ǯ��:
dfs�� �� �� ����Ͽ� Ǯ���߽��ϴ�.
https://www.acmicpc.net/problem/1967 �� ���� ����.
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

int n;
vector<pii> edge[100001];
bool visit[100001];
int idx = 1;
int maxDis = 0;

void dfs(int now, int nowDis) {

	if (maxDis < nowDis) {
		maxDis = nowDis;
		idx = now;
	}

	for (int i = 0; i < edge[now].size(); i++)
	{
		int next = edge[now][i].first;
		int nextDis = edge[now][i].second;

		if (!visit[next]) {
			visit[next] = true;
			dfs(next, nowDis + nextDis);
		}
	}
	visit[now] = false;
}

int main(void) {
	FIO;

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		int prev;
		cin >> prev;

		while (true) {
			int next, dis;
			cin >> next;

			if (next == -1)	break;

			cin >> dis;

			edge[prev].push_back(make_pair(next, dis));
		}
	}

	visit[1] = true;
	dfs(1, 0);

	maxDis = 0;
	visit[idx] = true;
	dfs(idx, 0);

	cout << maxDis;
}