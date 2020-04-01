/*
����
�����̰� ��� �ִ� ���ô� �ű��ϰ� �����. �� ���ô� �������·� �����, ���簢���̴�. ������ ���� ũ��� N�̰�, ���� ũ��� M�̴�. ��, �������� ���� (0, 0)�� �ְ�, �������� �б��� (N, M)�� �ִ�.

����, �Ʒ� �׸��� ���� �����.



�����̴� ������ �б��� ���� ���� ����� ���� �� �� ���� �ִ��� �ñ������� �����ߴ�.

�����̴� �׻� �ִܰŸ��θ� ���� ������, �׻� ���θ� ��Ȯ�ϰ� N + M�� ��ģ��. ������, �ֱ� ��� �� ������ ���ΰ� �νǰ��� ��Ȥ���� �������� ���� �ִ�. ���ΰ� ���� ���� ����, �� ���θ� ���� �� ����.

(0, 0)���� (N, M)���� ���� ���� �ٸ� ����� ����� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ������ ���� ũ�� N�� ���� ũ�� M�� �־�����. N�� M�� 100���� �۰ų� ���� �ڿ����̰�, ��° �ٿ��� �������� ������ ���� K�� �־�����. K�� 0���� ũ�ų� ����, 100���� �۰ų� ���� �ڿ����̴�. ��° �ٺ��� K�� �ٿ��� �������� ������ ������ a b c d�� ���� �־�����. a�� c�� 0���� ũ�ų� ����, N���� �۰ų� ���� �ڿ����̰�, b�� d�� 0���� ũ�ų� ����, M���� �۰ų� ���� �ڿ����̴�. �׸���, (a, b)�� (c, d)�� �Ÿ��� �׻� 1�̴�.

���
ù° �ٿ� (0, 0)���� (N, M)���� ���� ����� ���� ����Ѵ�. �� ���� 0���� ũ�ų� ����, 2^63-1���� �۰ų� ���� �ڿ����̴�.

Ǯ��:
DFS�� �̿��� DP �����Դϴ�.
�׻� �ִܰŸ��θ� �̵��ϱ� ������ �ڷΰ��� ����ó���� �� �� �ʿ䰡 �������ϴ�.
DFS�� �������� Ž���ϸ鼭, �̹� ������ �Ÿ��� ������ �ش� dp ���� �ڽſ��� ���ϴ� ������� �����߽��ϴ�.
*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<vector>
#include<stack>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>

int N, M, K;
long long dp[10210];
bool connect[10210][2];
int mv1[2] = { 0,1 };
int mv2[2] = { 1,0 };

int toNum(int x, int y) {
	return x * (M + 1) + y;
}

pii toXY(int num) {
	return make_pair(num / (M + 1), num % (M + 1));
}

long long DFS(int now) {

	long long& ret = dp[now];
	if (ret != 0)
		return ret;

	pii nowXY = toXY(now);
	if (now == (M + 1) * (N + 1) - 1) {
		return dp[now] = 1;
	}
	for (int i = 0; i < 2; i++)
	{
		int next_x = nowXY.first + mv1[i];
		int next_y = nowXY.second + mv2[i];
		if (next_x > N || next_y > M)	continue;

		int next = toNum(next_x, next_y);
		if (connect[now][i])	continue;

		ret += DFS(next);
	}
	return ret;
}

int main(void) {
	FIO;

	cin >> N >> M >> K;

	for (int i = 0; i < K; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		int x = toNum(a, b);
		int y = toNum(c, d);

		if(abs(x - y) == 1)
			connect[min(x, y)][0] = true;
		else
			connect[min(x, y)][1] = true;
	}

	cout << DFS(0);
}