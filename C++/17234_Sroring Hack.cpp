/*
����
0������ ������ �� �� ������ ȹ���� ������ ������ �ִ�. �� �Ͽ��� �÷��̾ ���� ���� �¸��ϸ� a���� ���, ���� b���� ��´�. ������ ������ n�� �̻��̸� ������ ������ �ȴ�.

�������� �� �л��� �� ������ ��ŷ�ϴ� �� �����ߴ�. �׷��� �� �Ͽ��� �¸�����, ���� �����Ӱ� ������ �� �ִ�. ������� ���ϴ� �Ͽ��� ������ a���̳� b�� �ø��� ��� �� ��� �ٲٴ� �͵� �����ϴ�. ���� ��� a�� 3�̰� b�� 2�̸� ���� ������ 10�̶�� �� ��, ���� ���� ������ ������ �Ϳ��� 12, 13, �Ǵ� 20�� �ִ�. ������ ���� �л��� n+a�� �̻��� ������ ������ ������ �ǰų�, �� ���� ������ �� ������ �� ��� �ø� ���� ��ü ���� 10%�� �ʰ��ϸ� �л��� ���� ����� �ǽ��� �ް� �ǰ�, ���ӿ��� ������ϰ� �ȴ�.

�� �л��� ����� �ǽ��� ���� �ʰ� ������ ������ �� �ʿ��� �ּ����� ���� ���϶�.

�Է�
n, a, b �� ���� ������ ���⸦ ���̿� �ΰ� �־�����. (1 �� n �� 500, 1 �� b �� a �� 100)

���
�� �л��� ����� �ǽ��� ���� �ʰ� ������ ������ �� �ʿ��� �ּ����� ���� ����Ѵ�.

Ǯ��:
visit �湮 �迭�� [���� ��][�� ���� Ƚ��][�� ��] �� �����Ѵ�.
�Ź� ���� ������ Ȯ���ϸ� Ž���Ѵ�.
*/
#include<iostream>
#include<queue>
#include<utility>
#include<math.h>
using namespace std;

int n, a, b;
bool visit[2000][10][2000];
int ans = 1000000000;

int BFS() {
	queue<pair<pair<int, int>, int> > q;
	q.push(make_pair(make_pair(0, 0), 0));
	visit[0][0][0] = true;
	visit[0][1][0] = true;

	while (!q.empty()) {
		int now = q.front().first.first;
		int cheat = q.front().first.second;
		int now_cnt = q.front().second;
		q.pop();
		if (cheat * 10 > now_cnt)	continue;
		if (now >= n + a)	continue;

		if (now >= n) {
			ans = min(ans, now_cnt);
		}

		if (!visit[now + a][cheat][now_cnt + 1]) {
			visit[now + a][cheat][now_cnt + 1] = true;
			q.push(make_pair(make_pair(now + a, cheat), now_cnt + 1));
		}
		if (!visit[now + b][cheat][now_cnt + 1]) {
			visit[now + b][cheat][now_cnt + 1] = true;
			q.push(make_pair(make_pair(now + b, cheat), now_cnt + 1));
		}
		if (!visit[now * 2][cheat + 1][now_cnt + 1]) {
			visit[now * 2][cheat + 1][now_cnt + 1] = true;
			q.push(make_pair(make_pair(now * 2, cheat + 1), now_cnt + 1));
		}
	}
	return ans;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> a >> b;

	cout << BFS();
}