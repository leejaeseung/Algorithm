/*
����
�ν��̴� ȸ���� �Ŵ����̴�. �׸���, �ν��̴� ȸ���� �߿��� ������ ��� �������� ������ �����Ϸ��� �Ѵ�. �ν����� ȸ��� Ʈ�� �����̴�. ��� ������ ��Ȯ�ϰ� �� ���� ���� ��簡 �ִ�. �ڱ��ڽ��� �׵� �ڱ� �ڽ��� ���� �Ǵ� ���� ��簡 �ƴϰ�, ��� ������ �ν����� ���� �Ǵ� �������� �����̴�.

�ν��̴� �ϴ� �ڱ� �ڽ��� ���� ���Ͽ��� �� ���� �� ����� ��ȭ�� �Ѵ�. ������ ���� �Ŀ�, �� ���ϴ� ���� ���� ���Ͽ��� �� ���� �� ����� ��ȭ�� �Ѵ�. �� ���� ��� ������ ������ ���� �� ���� ��ӵȴ�. ��� ����� �ڽ��� ���� ���Ͽ��Ը� ��ȭ�� �� �� �ְ�, ��ȭ�� ��Ȯ�ϰ� 1�� �ɸ���. �̶� ��� ������ �ҽ��� ��µ� �ɸ��� �ð��� �ּڰ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

���ν��� ��� ��ȣ�� 0�̰�, �ٸ� ����� ��ȣ�� 1���� �����Ѵ�.

�Է�
ù° �ٿ� ������ �� N�� �־�����. ��° �ٿ��� 0�� �������� �׵��� ����� ��ȣ�� �־�����. �ݵ�� 0�� ���� (���ν�)�� ���� -1�̰�, -1�� ��簡 ���ٴ� ���̴�. N�� 50���� �۰ų� ���� �ڿ����̴�.

���
ù° �ٿ� ��� �ҽ��� ���ϴµ� �ɸ��� �ð��� �ּڰ��� ����Ѵ�.

Ǯ��:
Ʈ���� dfs�� ��ȸ�ϴµ�, �� ���� �ڽ��� �ڽĵ鿡�� ���� ���� �ɸ��� �ð��� ��ȯ�ϰ� �ȴ�.
�׸��� �θ� ���� �ڽ��� �ڽ� ���鿡�� �� ��°�� ��ȭ�� ���� ���ؾ� �Ѵ�.

�ּ� �ð��� ���ؾ� �ϱ� ������ ���� �ɸ��� ��忡�� ���� ���� ��ȭ�� �ذ��� �ȴ�.
(��, �ڽ� ������ ���� �ɸ��� ������ �����ϰ�, �ش� ��� ���� ������� 1, 2, 3 ... �� ���Ѵ�.)

������ ���� ��, �ִ� ���� �ش� �θ� ����� ���� ���� �ɸ��� �ð��� �ǹǷ� ��Ʈ���� �ݺ��ϸ� �ȴ�.
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

int n;
vector<int> child[51];
int ans = 0;

int dfs(int now) {

	int ret = 0;

	if (child[now].size() == 0)
		return ret;

	priority_queue<pii> pq;

	for (int i = 0; i < child[now].size(); i++)
	{
		int next = child[now][i];

		pq.push(make_pair(dfs(next), i));
		//�ڽ� ��带 ���� �ɸ��� ������ ����
	}

	int iter = 0;

	while (!pq.empty())
	{
		int next = pq.top().second;
		int time = pq.top().first + 1 + iter++;
		//���� �ɸ��� ������ 1, 2, 3... �� ���Ѵ�.
		pq.pop();

		ret = max(ret, time);
		//���� ���� �ɸ��� �ð��� ����
	}

	return ret;
}

int main(void) {
	FIO;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int p;
		cin >> p;
		if (p == -1)	continue;

		child[p].push_back(i);
	}

	cout << dfs(0);
}