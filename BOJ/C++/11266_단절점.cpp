/*
����
�׷����� �־����� ��, �������� ��� ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�������̶� �� ������ �������� ��, �׷����� �� �� �Ǵ� �� �̻����� ���������� ������ ���Ѵ�. ��, �������� �� �׷����� connected component�� ������ �����ϴ� ������ ���Ѵ�.

�Է�
ù° �ٿ� �� ���� V(1��V��10,000), E(1��E��100,000)�� �־�����. �̴� �׷����� V���� ������ E���� �������� �̷���� �ִٴ� �ǹ��̴�. ���� E���� �ٿ��� ������ ���� ������ ��Ÿ���� �� ���� A, B�� �־�����. �̴� A�� ������ B�� ������ ����Ǿ� �ִٴ� �ǹ��̸�, ������ ������̴�.

�Է����� �־����� �׷����� ���� �׷����� �ƴ� ���� �ִ�.

���
ù° �ٿ� �������� ������ ����Ѵ�.

��° �ٿ��� �������� ��ȣ�� �������� ������ ������������ ����Ѵ�.

Ǯ��:
�������� ������ �˰����̴�.
https://jason9319.tistory.com/119
�� ��α׸� ������ Ǯ���ߴ�.

�ϳ��� �׷������� ������ �� ��带 ��Ʈ�� ��� �� ���� dfs�� �ذ��Ѵ�.
dfs�� �ϸ鼭 �湮 ��ȣ�� ��帶�� �ٿ� �ִµ�, dfs���� �ڽ��� �ڽĵ� �߿���(�ڽź��� ���߿� Ž���Ǵ�)
�ڽź��� ���� �湮 ��ȣ�� ���� ���� ����Ǿ� �ִٸ� �ڽ��� �������� �ƴϴ�.

��, ��Ʈ���� ���ܷ� dfs�� ���� �ڽ��� 2�� �̻��̸� ������ �������̴�.
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

int v, e;
bool visit[10001];
int visit_seq[10001];
vector<int> edge[10001];
set<int> ans;

int visit_cnt = 1;

int dfs(int now, bool isRoot) {

	visit_seq[now] = visit_cnt;
	int ret = visit_cnt++;
	int child = 0;

	for (int i = 0; i < edge[now].size(); i++)
	{
		int next = edge[now][i];

		if (!visit[next]) {
			visit[next] = true;
			child++;

			int sons = dfs(next, false);
			//�ڽ��� ���� �� �� ���� ���� ���� ����

			if (!isRoot && sons >= visit_seq[now])
				ans.insert(now);

			ret = min(ret, sons);
		}

		ret = min(ret, visit_seq[next]);
		//�ڽ��� ���� �� �� ���� ���� ���� ���� -> �θ𿡰� �˷��ֱ� ����
	}

	//��Ʈ�� ��
	if (isRoot && child > 1) {
		ans.insert(now);
	}

	return ret;
}

int main(void) {
	FIO;

	cin >> v >> e;

	for (int i = 0; i < e; i++)
	{
		int a, b;
		cin >> a >> b;

		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	for (int i = 1; i <= v; i++)
	{
		if (!visit[i]) {
			visit[i] = true;

			dfs(i, true);
		}
	}

	cout << ans.size() << "\n";
	for (auto iter = ans.begin(); iter != ans.end(); iter++)
		cout << *iter << " ";
}