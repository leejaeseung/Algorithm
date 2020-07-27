/*
����
��� ��, Ʈ���� �������� ���� �ִ� �����̴� ��û�� ����� �ϳ� �߰��ߴ�. �ٷ� ������ �� ���� Ʈ���� �������� �������� �� �����ۿ� ���ٴ� ����̴�!



������ �� �� �̻� �ִ� ������ Ʈ���� ����, �� Ʈ������ ���� �� ���� �̷���� ������ ����. ��ü Ʈ���� ������ �� ���տ� ���� �� ������ �մ� �������� ������ ��, �� ���� ������ �ϳ��� Ʈ�� ���·� �̾����� �ȴٸ� ������ ����̰ų� ������ ����� ���̴�. Ʈ������ �������� ������ �������� ������ ���� Ʈ������ ������ ���, ������ ����� �̷�� ���� �� ��¥�� ������ ������� ����.

����, �����̴� ������ ��� Ʈ���� ������ ���� �� ������ ��������.

D-Ʈ�� : �������� �������� �躸�� ���� Ʈ��
G-Ʈ�� : �������� �������� �躸�� ���� Ʈ��
DUDUDUNGA-Ʈ�� : �������� �������� ��Ȯ�� �踸ŭ �ִ� Ʈ��
���� �� �����̴� Ʈ���� ���̸� �� Ʈ���� �ִ� �������� �������� �� ������ ���� �ٴϱ� �����ߴ�. ������ �� ������ �� ���� �ִ� Ʈ���� ������ �տ� ��Ÿ����, �����̴� �׸� ������ �Ұ� ���Ҵ�. �����̸� ����� �־��� Ʈ���� D-Ʈ������ G-Ʈ������ �ƴϸ� DUDUDUNGA-Ʈ������ �˷�����!

�Է�
ù ��° �ٿ� Ʈ���� ���� �� �� �־�����. ()

�� ��° �ٺ��� ���� �ٿ� Ʈ���� �� ������ �մ� �� ������ ��ȣ , �� �־�����. ()

���
ù ��° �ٿ� �־��� Ʈ���� D-Ʈ����� D, G-Ʈ����� G, DUDUDUNGA-Ʈ����� DUDUDUNGA�� ����Ѵ�.

Ǯ��:
dfs + ���� ����, G-Ʈ�� = �ڽ� ��尡 3�� �̻��� �ֵ鿡 ���� nC3 , D-Ʈ�� = ��� �� ���� ��� �� �� ���� ���� ����
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
#define DMAX 0xfffffffffffff
int mv1[4] = { 0, 1, 0, -1 };
int mv2[4] = { 1, 0, -1, 0 };
int mv_all1[8] = { 0, 1, 0, -1, -1, -1, 1, 1 };
int mv_all2[8] = { 1, 0, -1, 0 , -1, 1, -1, 1 };

int n;
vector<int> edge[300001];
ll g_cnt = 0;
ll d_cnt = 0;

void dfs(int prev, int now) {

	ll prev_cnt = edge[prev].size() - 1;
	ll now_cnt = edge[now].size() - 1;

	d_cnt += (prev_cnt * now_cnt);

	for (int i = 0; i < edge[now].size(); i++)
	{
		if (edge[now][i] == prev)	continue;
		dfs(now, edge[now][i]);
	}
}

ll comb(ll N) {
	return N * (N - 1) * (N - 2) / 6;
}

int main(void) {
	FIO;

	cin >> n;

	for (int i = 0; i < n - 1; i++)
	{
		int s, e;
		cin >> s >> e;

		edge[s].push_back(e);
		edge[e].push_back(s);
	}

	for (int i = 1; i <= n; i++)
	{
		if (edge[i].size() >= 3) {
			g_cnt += comb(edge[i].size());
		}
	}

	for (int i = 0; i < edge[1].size(); i++)
	{
		dfs(1, edge[1][i]);
	}

	g_cnt *= 3;

	if (d_cnt < g_cnt)
		cout << "G";
	else if (d_cnt > g_cnt)
		cout << "D";
	else
		cout << "DUDUDUNGA";
}