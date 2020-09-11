/*
����
��� �� ��� �л����� �� ���� �Ѱ��� ��Ʈ���� ������ �����ϴ� ����, �ڸ��� �ٲٴٰ� �׸� ��Ʈ���� �ڼ��̰� ���Ҵ�. ��ټ��� �л����� �ڽ��� ��Ʈ���� �� �˰� �־ �ڽ��� ��Ʈ���� ���� �� �־�����, �ּ��ϰԵ� N���� �л����� ��Ȯ�� �ڽ��� ��Ʈ���� ������� ���� ���ߴ�. �ֳ��ϸ� �׵��� ��Ʈ���� �����Ѱ� �ٷ� �������� �����̴�.

������ ������ ��Ʈ��, �ٲ�� ��Ϸ�.

�׵鿡�� �ڽ��� ��Ʈ���̶�� �����Ǵ� ��Ʈ�ϵ��� ����� ����� �ߴ�.

�̹����� ���� �ű��ϰԵ� �׵� ������ ��Ʈ���� ������ ������ ���̾���! ���̰� �ƴϸ� �̰� �ƴϸ� �̰� �ƴϸ� �̰� �ϰ� ���ƿ䡱��ī����.

�츮�� ������ �̵��� �䱸�� ���� ���� ������Ű�� ���̴�.

������, �ڽ��� �ڽ��� �� ���ٶ�� ����� ��Ʈ���� ���� ����� �ִ�ȭ �϶�� �Ҹ���.

�Է�
ù° �ٿ��� ��Ʈ���� ���� �� ���� ��Ʈ���� ������ ����� �� N(1 �� N �� 100)�� ��Ʈ�� ������ ���� M(0 �� M �� 5,000) �־�����.

��¶�ٿ��� M+1��° �� ������ ���� �� �ٸ��� a b�� �־����µ�, �̴� a�� ����� b�� ��Ʈ���� �ڽ��� ���̶�� �����Ѵٴ� �ǹ̸� ���´�.

��Ʈ�ϰ� ����� ��ȣ�� 1���� ũ�ų� ����, N���� �۰ų� ����. �� ��� �Ǵ� �� ��Ʈ���� ���� ��ȣ�� ���� ���� ����.

���
�ִ�� ������ �� �ִ� ��� ���� ����Ѵ�.

Ǯ��:
�̺� ��Ī �����̴�.

dfs�� � �� x�� ������ �� ������ true�� ����ϰԲ� �����Ѵ�.
�������� �ߺ� �湮�� ���� �����Ƿ� visit �迭�� �湮 üũ�� ����� �Ѵ�.
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
vector<int> edge[101];
bool visit[5001];
int match[5001];

bool dfs(int now) {
	if (match[now] == 0)	return true;
	visit[now] = true;
	int ori = match[now];

	for (int i = 0; i < edge[ori].size(); i++)
	{
		int tg = edge[ori][i];

		if (match[tg] == 0 || !visit[tg] && dfs(tg)) {
			match[tg] = ori;

			return true;
		}
	}

	return false;
}

int main(void) {
	FIO;

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;

		edge[a].push_back(b);
	}

	int ans = 0;

	for (int i = 1; i <= n; i++)
	{
		fill(&visit[0], &visit[5001], false);
		for (int j = 0; j < edge[i].size(); j++)
		{
			int tg = edge[i][j];

			if (dfs(tg)) {
				
				match[tg] = i;

				ans++;
				break;
			}
		}
	}

	cout << ans;
}