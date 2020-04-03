/*
����
���� A�� B�� �ٲٷ��� �Ѵ�. ������ ������ ������ ���� �� �����̴�.

2�� ���Ѵ�.
1�� ���� ���� �����ʿ� �߰��Ѵ�.
A�� B�� �ٲٴµ� �ʿ��� ������ �ּڰ��� ���غ���.

�Է�
ù° �ٿ� A, B (1 �� A < B �� 109)�� �־�����.

���
A�� B�� �ٲٴµ� �ʿ��� ������ �ּڰ��� 1�� ���� ���� ����Ѵ�. ���� �� ���� ��쿡�� -1�� ����Ѵ�.

Ǯ��:
���� �����ϰ� ����Ž���� �ߴ��� Ǯ�� ���������ϴ�.
A���� *2 Ȥ�� *10 + 1 �� ���ָ鼭 B�� ������ ������ Ž���մϴ�.

B���� Ŀ���� ��츸 �ɷ��ָ� �˴ϴ�.
*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<vector>
#include<queue>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>

long long A, B;
int ans = 100000000;

void recul(long long now, int cnt) {
	if (now > B)
		return;
	if (now == B) {
		ans = min(ans, cnt + 1);
	}

	recul(now * 2, cnt + 1);
	recul(now * 10 + 1, cnt + 1);
}

int main(void) {
	FIO;

	cin >> A >> B;

	recul(A, 0);

	if (ans == 100000000)
		cout << "-1";
	else
		cout << ans;
}