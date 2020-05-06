/*
����
<�׸� 1>�� ���� ���簢�� ����� �� �ټ� ������ �����̰� �ִ�. �������� ũ��� 1��1, 2��2, 3��3, 4��4, 5��5�� �� �ټ� ������ ������, �� ������ �����̴� 5���� ������ �ִ�.



<�׸� 1>

�����̸� ũ�Ⱑ 10��10�� ���� ���� ���̷��� �Ѵ�. ���̴� 1��1 ũ���� ĭ���� �������� ������, ������ ĭ���� 0 �Ǵ� 1�� ���� �ִ�. 1�� ���� ĭ�� ��� �����̷� �������� �Ѵ�. �����̸� ���� ���� ������ ��� ������ �������� �ȵǰ�, ���ĵ� �� �ȴ�. ��, ĭ�� ���� ��ġ�ϰ� �ٿ��� �Ѵ�. 0�� ���� ĭ���� �����̰� ������ �� �ȴ�.

���̰� �־����� ��, 1�� ���� ��� ĭ�� ���̴µ� �ʿ��� �������� �ּ� ������ ���غ���.

�Է�
�� 10���� �ٿ� ������ �� ĭ�� ���� ���� �־�����.

���
��� 1�� ���µ� �ʿ��� �������� �ּ� ������ ����Ѵ�. 1�� ��� ���� ���� �Ұ����� ��쿡�� -1�� ����Ѵ�.

Ǯ��:
ó������ ������ �Ʒ����� ���� ū �����̸� ä������ �׸����� Ǯ�̸� ����ߴµ�, ���� �����̸� ���� ���� ��
�� ȿ������ ��찡 �־� ��Ʈ��ŷ���� Ǯ���ؾ� �߽��ϴ�.
�� ������ ���� 1�� ���� ã�� �����̸� ��� �ٿ����� ���ȣ���� �ݺ��մϴ�.
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
#define ll long long

int map[10][10];
int paper[6];
int ans = 51;

void update(int i, int j, int v, int flag) {

	for (int a = 0; a < v; a++)
	{
		for (int b = 0; b < v; b++)
		{
			map[i + a][j + b] = flag;
		}
	}
}

bool check(int i, int j, int v) {

	for (int a = 0; a < v; a++)
	{
		for (int b = 0; b < v; b++)
		{
			if (map[i + a][j + b] == 0)	return false;
		}
	}
	return true;
}

void recul(int a, int b, int cnt) {

	while (map[a][b] == 0) {
		if (++b >= 10) {
			if (++a >= 10) {
				ans = min(ans, cnt);
				return;
			}
			b = 0;
		}
	}

	if (ans <= cnt)	return;

	for (int k = 5; k >= 1; k--)
	{
			if (paper[k] == 0 || a + k > 10 || b + k > 10)	continue;

			if (check(a, b, k)) {
					update(a, b, k, 0);
					paper[k]--;

					recul(a, b, cnt + 1);

					paper[k]++;
					update(a, b, k, 1);
			}
	}
}

int main(void) {
	FIO;

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 1; i <= 5; i++)
	{
		paper[i] = 5;
	}

	recul(0, 0, 0);

	if (ans == 51)
		cout << -1;
	else
		cout << ans;

}