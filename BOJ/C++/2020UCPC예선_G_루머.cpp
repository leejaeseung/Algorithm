/*
����
����� ��Ӹ� �ϴ°�?

�� ���� �ɸ��� ���迡���� ����鿡�� �� ���� ���� �����ְ�, � ���� �� ���� ���϶� �ߴ�. ��� �� ����� �����ϰ� �������� �����ڿ� ���� ������ ���۵� ������̾���. ���۵� ������� ��ǻ� �� ª�� ���� �� ��ٰ� ���ߴ�. �ֺ� ��ΰ� ���� �亯�� ����, ��¥ �ǽ����� ���� ª�� ���� �� ��ٰ� ���ߴ�. �� ������ ������� �ֺ����� ������ ���ϰ� �޴´ٴ� ���� �����־��µ�, ��ӵ� �̿� ����.

��Ӵ� ���� �����ڷκ��� �����Ѵ�. ���� �����ڴ� ���� ���� �� �ְ�, ���� �����ڸ� �����ϰ� ������ ��Ӹ� ����� �ϴ� ����� ����.

�ź� ��Ӹ� �ϴ� ����� ��� �ֺ��ο��� ��Ӹ� ���ÿ� ��Ʈ����, ���� �� ����� �ֺ����� ���� �̻��� ��Ӹ� ���� �� ���ε� ��Ӹ� �ϴ´�.

��Ӹ� �ϴ� �������� �ٸ� ���� ���� �ʱ� ������, �ѹ� ���� ��Ӵ� ��� �ϴ´�.

�̶�, ������� ��Ӹ� ó�� �ϱ� �����ϴ� �ð��� �˾Ƴ� ����.

�Է�
ù° �ٿ� ����� �� �� �־�����. () �̴� �� ������� �� ������� ������ �ǹ��Ѵ�.

��° �ٺ��� ���� ���� �־�����. �� �� ��° �ٿ��� �� ����� �ֺ��ε��� ��ȣ�� �Է��� �������� ��Ÿ���� 0�� �������� ���еǾ� �־�����. ��ȣ��  �̻�  ������ �ڿ����̰�, ���� �ٿ� �ߺ��� ��ȣ�� ����. �ڱ� �ڽ��� �ֺ����̰ų� �Ϲ������� �ֺ����� ���� ������, ��ü ����� �ֺ��� ����� ���� ���� �ʴ´�.

���� �ٿ��� ��Ӹ� �۶߸��� ���� �������� �� �� �־�����.
������ �ٿ��� ���� �������� ��ȣ�� �������� ���еǾ� �־�����. ���� �������� ��ȣ�� �ߺ����� �ʴ´�.

���
���� ���� �� ���� ������ ����Ѵ�. �� �� ����� ��Ӹ� ó�� �ϱ� ������ �ð�(��)�̸�, ����� ���� �ð��� ������ ��Ӹ� ���� ���� ��� �̴�. ���� �����ڴ� ��Ӹ� �к��� �ϱ� �����ߴٰ� �����Ѵ�.

Ǯ��:
bfs ���� ����

���� ��尡 ��Ӹ� ���� �� -> �ֺ� ���鿡�� �ŷڵ��� 1 ������Ű��, Ž��
�� ��, ���� ��尡 ��Ӹ� ���� �� �Ѵٸ�, Ž������ ����.

���� ��尡 ��Ӹ� ���� ���� �� -> ���� ��带 �ð��� �������� ť�� �߰�

��ΰ� ��Ӹ� ���� �� �־��� ��� �ִ� n - 1 �ð����� �ɸ��Ƿ� �ش� �ð��� �ʰ��ϸ� Ž���� �ߴ�.
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
int mv_all1[8] = { 0, 1, 0, -1, -1, -1, 1, 1 };
int mv_all2[8] = { 1, 0, -1, 0 , -1, 1, -1, 1 };

int n, m;
vector<int> edge[200001];
queue<pii> q;
int ans[200001];
int trust_cnt[200001];

int main(void) {
	FIO;

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		while (true) {
			int near;
			cin >> near;
			if (near == 0)	break;

			edge[i].push_back(near);
		}
		ans[i] = -1;
	}

	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int p;
		cin >> p;
		q.push(make_pair(p, 0));
		ans[p] = 0;
	}

	while (!q.empty()) {
			int nowP = q.front().first;
			int nowTime = q.front().second;
			q.pop();

			if (nowTime > n)	break;
			if (ans[nowP] > nowTime)	continue;

			if (ans[nowP] != -1) {
				for (int i = 0; i < edge[nowP].size(); i++)
				{
					int nextP = edge[nowP][i];

					if (ans[nextP] == -1) {
						trust_cnt[nextP]++;

						int mid = edge[nextP].size() / 2;
						if (edge[nextP].size() % 2 != 0)
							mid++;

						if (trust_cnt[nextP] >= mid)
							ans[nextP] = nowTime + 1;

						if(ans[nextP] != -1)
							q.push(make_pair(nextP, nowTime + 1));
					}
					
				}
			}
			else {
				q.push(make_pair(nowP, nowTime + 1));
			}
	}

	for (int i = 1; i <= n; i++)
	{
		cout << ans[i] << " ";
	}
}