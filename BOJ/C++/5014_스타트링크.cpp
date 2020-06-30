/*
����
��ȣ�� �ڵ� ������ �ϴ� ��ŸƮ�� ��ŸƮ��ũ�� �����ߴ�. ������ ��ȣ�� �������̴�. ������, ������ �� ��ȣ�� ��ŸƮ��ũ�� �ִ� �ǹ��� �ʰ� �����ϰ� ���Ҵ�.

��ŸƮ��ũ�� �� F������ �̷���� ���� �ǹ��� �繫���� �ְ�, ��ŸƮ��ũ�� �ִ� ���� ��ġ�� G���̴�. ��ȣ�� ���� �ִ� ���� S���̰�, ���� ���������͸� Ÿ�� G������ �̵��Ϸ��� �Ѵ�.

���� ���������Ϳ��� � ������ �̵��� �� �ִ� ��ư�� ������, ��ȣ�� ź ���������ʹ� ��ư�� 2���ۿ� ����. U��ư�� ���� U���� ���� ��ư, D��ư�� �Ʒ��� D���� ���� ��ư�̴�. (����, U�� ��, �Ǵ� D�� �Ʒ��� �ش��ϴ� ���� ���� ����, ���������ʹ� �������� �ʴ´�)

��ȣ�� G���� �����Ϸ���, ��ư�� ��� �� �� ������ �ϴ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�. ����, ���������͸� �̿��ؼ� G���� �� �� ���ٸ�, "use the stairs"�� ����Ѵ�.

�Է�
ù° �ٿ� F, S, G, U, D�� �־�����. (1 �� S, G �� F �� 1000000, 0 �� U, D �� 1000000) �ǹ��� 1������ �����ϰ�, ���� ���� ���� F���̴�.

���
ù° �ٿ� ��ȣ�� S������ G������ ���� ���� ������ �ϴ� ��ư�� ���� �ּڰ��� ����Ѵ�. ����, ���������ͷ� �̵��� �� ���� ���� "use the stairs"�� ����Ѵ�.

Ǯ��:
bfs �⺻ �����Դϴ�.
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

int f, s, g, u, d;
bool visit[1000001];

int bfs() {
	queue<pii> q;
	q.push(make_pair(s, 0));
	visit[s] = true;

	while (!q.empty()) {
		int now = q.front().first;
		int now_cnt = q.front().second;
		q.pop();

		if (now == g)
			return now_cnt;

		if (now + u <= f && !visit[now + u]) {
			visit[now + u] = true;
			q.push(make_pair(now + u, now_cnt + 1));
		}
		if (now - d >= 1 && !visit[now - d]) {
			visit[now - d] = true;
			q.push(make_pair(now - d, now_cnt + 1));
		}
	}
	return -1;
}

int main(void) {
	FIO;

	cin >> f >> s >> g >> u >> d;

	int ans = bfs();

	if (ans == -1)
		cout << "use the stairs";
	else
		cout << ans;
}