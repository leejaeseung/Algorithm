/*
����
�Ұ� ���� �ǳʰ� ������ �׳� ���� ���Ƽ��̴�. ���� ���忡�� ���� �ʹ� ���Ƽ�, ���� �ǳ��� �ʰ��� ���� ���ƴٴ� ���� ����.

���� ���忡 ������� ������ �־���. ���� ���� ���簢�� �������� N��N (2 �� N �� 100) ���ڷ� �̷���� �ִ�. ������ ������ ���̴� �Ϲ������� �����Ӱ� �ǳʰ� �� ������, �� �� �Ϻδ� ���� �ǳʾ� �Ѵ�. ������ �ٱ����� ���� ��Ÿ���� �־ �Ұ� ���� ������ ���� ���� ����.

K������ (1 �� K �� 100,K �� N2) �Ұ� ���� ���忡 �ְ�, �� �Ҵ� ���� �ٸ� �������� �ִ�. � �� �Ҵ� ���� �ǳ��� ������ ������ �� �� �� �ִ�. �̷� �Ұ� �� ������ �����.

�Է�
ù �ٿ� N, K, R�� �־�����. ���� R�ٿ��� �� �ٿ� �ϳ��� ���� �־�����. ���� �����¿�� ������ �� �������� �հ�, r c r�� c���� ���� (��, ��, ��, ��)�� �־�����. �� ���� 1 �̻� N �����̴�. �� ���� K�ٿ��� �� ���� �ϳ��� ���� ��ġ�� ��� ���� �־�����.

���
���� �ǳ��� ������ ���� �� ���� �Ұ� �� ������ ����Ѵ�.

Ǯ��:
BFS�� DFS�� �� �Ҹ��� Ž���ϴµ�, Ž�� �ø��� map�� ���� ĥ���ݴϴ�.
�̹� ĥ���� ���̸� ���� �� �ִ� �ҵ��Դϴ�.

ĥ���� ������ ������ �ش� ���� ���� ���� ���� ī��Ʈ�Ͽ� ���� ���� ���մϴ�.
*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include<queue>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>

int N, K, R;
int color = 1;
int map[101][101];
int mv1[4] = { 0, 0, 1, -1 };
int mv2[4] = { 1, -1, 0, 0 };
bool edge[10001][10001];
int cow_color[10010];
int color_cnt[10010];


void BFS(int start, int cow_num) {
	queue<int> q;
	q.push(start);
	int start_x = (start - 1) / N + 1;
	int start_y = start - (start_x - 1) * N;
	if (map[start_x][start_y] != 0) {
		cow_color[cow_num] = map[start_x][start_y];
		return;
	}
	map[start_x][start_y] = color;

	while (!q.empty()) {
		int now = q.front();	q.pop();
		int now_x = (now - 1) / N + 1;
		int now_y = now - (now_x - 1) * N;

		for (int i = 0; i < 4; i++)
		{
			int next_x = now_x + mv1[i];
			int next_y = now_y + mv2[i];
			if (next_x <= 0 || next_y <= 0 || next_x > N || next_y > N)	continue;
			int next = (next_x - 1) * N + next_y;
			if (edge[now][next])	continue;

			if (map[next_x][next_y] == 0) {
				map[next_x][next_y] = color;
				q.push(next);
			}
		}
	}
	cow_color[cow_num] = color++;
}

int main(void) {
	FIO;

	cin >> N >> K >> R;

	for (int i = 0; i < R; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		int n1 = (x1 - 1) * N + y1;
		int n2 = (x2 - 1) * N + y2;

		edge[n1][n2] = true;
		edge[n2][n1] = true;
	}

	vector<int> cow;
	for (int i = 0; i < K; i++)
	{
		int x, y;
		cin >> x >> y;

		int n = (x - 1) * N + y;
		cow.push_back(n);
	}

	for (int i = 0; i < cow.size(); i++)
	{
		BFS(cow[i], i);
	}
	for (int i = 0; i < K; i++)
	{
		color_cnt[cow_color[i]]++;
	}
	int sum = 0;
	for (int i = 0; i < 10009; i++)
	{
		if (color_cnt[i] != 0) {
			for (int j = i + 1; j < 10010; j++)
			{
				sum += color_cnt[i] * color_cnt[j];
			}
		}
	}
	cout << sum;
}