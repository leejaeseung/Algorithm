/*
����
�ѱ����� N���� ���� C1, C2, ..., CN�� �ְ�, �� ���� ���ø� ��������� �մ� M���� ö�� �뼱�� �ִ�.

ö���� �����ϴ� ����� ö�� ������ �Ϸ��� �Ѵ�. ö�� �����̶� ���� ���ÿ��� ���� ���ñ��� ö�� �뼱���� �̿��� �̵��ϴµ�, �ϳ��� ö�� �뼱�� �� �� �̻� Ÿ�� �ʴ� ���� �ǹ��Ѵ�. ���� ���ÿ� ���� ���ô� ���� ���� ������, �ϳ��� ���ø� ���� �� �湮�� ���� �ִ�.

����� �ּ� Ƚ���� ö�� �������� ��� �뼱�� ��Ȯ�� �� ���� Ÿ���� �Ѵ�. ���� ö�� ������ �� �� �ؾ� �ϴ��� ���غ���.

�Է�
�Է��� ù �ٿ� �� ���� N(1 �� N �� 200,000)�� M(1 �� M �� 300,000)�� �־�����.

���� M���� �ٿ� ���� ���� �ٸ� �� ���� u, v(1 �� u, v �� N)�� �־�����. �̴� Cu�� Cv�� ��������� �մ� ö�� �뼱�� �������� �ǹ��Ѵ�.

��, �� ���� ���ø� ���� �մ� ö�� �뼱�� ���ƾ� �ϳ��̴�.

���
���� �ؾ� �ϴ� ö�� ������ �ּ� Ƚ���� ����Ѵ�.

Ǯ��:
�Ѻױ׸���(���Ϸ� ���) ���������ϴ�.
��, �׷��� ���� ���� ���� �� �����Ƿ� ���Ͽ�-���ε� �˰����� �������־�� �մϴ�.

�� �׷츶��, Ȧ�� ���� ������ ī��Ʈ�ϰ�, Ȧ�� ���� ������ +1, Ȧ�� ���� �ִٸ� (Ȧ�� ��) / 2 ���� �߰��� �ݴϴ�.
�׷쿡 �ϳ��� ��常 �ִ� ���(��ΰ� �̾����� ���� ���)�� �ɷ��ݴϴ�.
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

int n, m;
int cnt[200001];
int parent[200001];
bool group[200001];
int g_odd[200001];
int group_cnt[200001];

int find(int now) {
	if (parent[now] == now)
		return now;

	return parent[now] = find(parent[now]);
}

void merge(int x, int y) {

	x = find(x);
	y = find(y);

	if (x != y) {
		parent[x] = y;
	}
}

int main(void) {
	FIO;

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
	}

	for (int i = 0; i < m; i++)
	{
		int s, e;
		cin >> s >> e;
		cnt[s]++;
		cnt[e]++;
		merge(s, e);
	}

	for (int i = 1; i <= n; i++)
	{
		int p = find(i);
		if (!group[p]) {
			group[p] = true;
		}
		if (cnt[i] % 2 != 0)
			g_odd[p]++;
		group_cnt[p]++;
	}

	int ans = 0;

	for (int i = 1; i <= n; i++)
	{
		if (group_cnt[i] == 1)	continue;
		if (group[i]) {
			if (g_odd[i] == 0)
				ans++;
			else
				ans += (g_odd[i] / 2);
		}
	}

	cout << ans;
} 