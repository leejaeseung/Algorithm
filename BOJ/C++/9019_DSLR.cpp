/*
����
�� ���� ��ɾ� D, S, L, R �� �̿��ϴ� ������ ���Ⱑ �ִ�. �� ���⿡�� �������Ͱ� �ϳ� �ִµ�, �� �������Ϳ��� 0 �̻� 10,000 �̸��� �������� ������ �� �ִ�. �� ��ɾ�� �� �������Ϳ� ����� n�� ������ ���� ��ȯ�Ѵ�. n�� �� �ڸ����� d1, d2, d3, d4��� ����(�� n = ((d1 �� 10 + d2) �� 10 + d3) �� 10 + d4��� ����)

D: D �� n�� �� ��� �ٲ۴�. ��� ���� 9999 ���� ū ��쿡�� 10000 ���� ���� �������� ���Ѵ�. �� ��� ��(2n mod 10000)�� �������Ϳ� �����Ѵ�.
S: S �� n���� 1 �� �� ��� n-1�� �������Ϳ� �����Ѵ�. n�� 0 �̶�� 9999 �� ��� �������Ϳ� ����ȴ�.
L: L �� n�� �� �ڸ����� �������� ȸ������ �� ����� �������Ϳ� �����Ѵ�. �� ������ ������ �������Ϳ� ����� �� �ڸ����� ������� d2, d3, d4, d1�� �ȴ�.
R: R �� n�� �� �ڸ����� ���������� ȸ������ �� ����� �������Ϳ� �����Ѵ�. �� ������ ������ �������Ϳ� ����� �� �ڸ����� ������� d4, d1, d2, d3�� �ȴ�.
������ ����� ��ó��, L �� R ��ɾ�� ���� �ڸ����� �����ϰ� ������ �����Ѵ�. ���� �� n = 1234 ��� ���⿡ L �� �����ϸ� 2341 �� �ǰ� R �� �����ϸ� 4123 �� �ȴ�.

�������� �ۼ��� ���α׷��� �־��� ���� �ٸ� �� ���� A�� B(A �� B)�� ���Ͽ� A�� B�� �ٲٴ� �ּ����� ��ɾ �����ϴ� ���α׷��̴�. ���� �� A = 1234, B = 3412 ��� ������ ���� �� ���� ��ɾ �����ϸ� A�� B�� ��ȯ�� �� �ִ�.

1234 ��L 2341 ��L 3412
1234 ��R 4123 ��R 3412

���� �������� ���α׷��� �� ��쿡 LL �̳� RR �� ����ؾ� �Ѵ�.

n�� �ڸ����� 0 �� ���Ե� ��쿡 �����ؾ� �Ѵ�. ���� �� 1000 �� L �� �����ϸ� 0001 �� �ǹǷ� ����� 1 �� �ȴ�. �׷��� R �� �����ϸ� 0100 �� �ǹǷ� ����� 100 �� �ȴ�.

�Է�
���α׷� �Է��� T ���� �׽�Ʈ ���̽��� �����ȴ�. �׽�Ʈ ���̽� ���� T �� �Է��� ù �ٿ� �־�����. �� �׽�Ʈ ���̽��δ� �� ���� ���� A�� B(A �� B)�� �������� �и��Ǿ� ���ʷ� �־����µ� A�� ���������� �ʱ� ���� ��Ÿ���� B�� ���� ���� ��Ÿ����. A �� B�� ��� 0 �̻� 10,000 �̸��̴�.

���
A���� B�� ��ȯ�ϱ� ���� �ʿ��� �ּ����� ��ɾ� ������ ����Ѵ�.

Ǯ��:
�� DSLR�� ���Ͽ� BFS�� ��ǥ ���ڱ��� Ž���ϸ� �˴ϴ�.

������ ���� BFS�� ���鼭 ��θ� �߰��ذ��� string ������ ť�� ��� ���� ������ �ȵǰ�(�ð� or �޸� �ʰ�),
char������ �������ϸ� �˴ϴ�.

�򰥸� �� �ִ� �κ� : 0���� S -> 9999, 1���� S -> 0
*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<string.h>
#include<queue>
#include<stack>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>

int s, e;
bool visit[10000];
pair<int, char> route[10000];

int oper(int o, int x) {
	switch (o) {
	case 0:
		return (x * 2) % 10000;
	case 1:
		if (x == 0)	return 9999;
		return x - 1;
	case 2:
		return (x * 10 + (x * 10) / 10000) % 10000;
	case 3:
		return ((x % 10) * 1000) + x / 10;
	}
}

char operTochar(int o) {
	switch (o)
	{
	case 0:
		return 'D';
	case 1:
		return 'S';
	case 2:
		return 'L';
	case 3:
		return 'R';
	}
}

void BFS(int start) {
	queue<int> q;

	q.push(start);

	while (!q.empty()) {
		int now = q.front();	q.pop();

		for (int i = 0; i < 4; i++)
		{
			int next = oper(i, now);

			if (visit[next])	continue;
			visit[next] = true;
			route[next] = make_pair(now, operTochar(i));

			if (next == e) {
				return;
			}
			
			q.push(next);
		}
	}
}

int main(void) {
	FIO;

	int T;
	cin >> T;

	while (T--) {
		cin >> s >> e;

		memset(visit, false, sizeof(visit));

		BFS(s);

		int now = e;
		string ans = "";
		while (now != s) {
			ans += route[now].second;
			now = route[now].first;
		}
		reverse(ans.begin(), ans.end());
		cout << ans << "\n";
	}
}