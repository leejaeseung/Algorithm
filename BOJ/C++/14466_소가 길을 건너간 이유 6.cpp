/*
문제
소가 길을 건너간 이유는 그냥 길이 많아서이다. 존의 농장에는 길이 너무 많아서, 길을 건너지 않고서는 별로 돌아다닐 수가 없다.

존의 농장에 대대적인 개편이 있었다. 이제 작은 정사각형 목초지가 N×N (2 ≤ N ≤ 100) 격자로 이루어져 있다. 인접한 목초지 사이는 일반적으로 자유롭게 건너갈 수 있지만, 그 중 일부는 길을 건너야 한다. 농장의 바깥에는 높은 울타리가 있어서 소가 농장 밖으로 나갈 일은 없다.

K마리의 (1 ≤ K ≤ 100,K ≤ N2) 소가 존의 농장에 있고, 각 소는 서로 다른 목초지에 있다. 어떤 두 소는 길을 건너지 않으면 만나지 못 할 수 있다. 이런 소가 몇 쌍인지 세어보자.

입력
첫 줄에 N, K, R이 주어진다. 다음 R줄에는 한 줄에 하나씩 길이 주어진다. 길은 상하좌우로 인접한 두 목초지를 잇고, r c r′ c′의 형태 (행, 열, 행, 열)로 주어진다. 각 수는 1 이상 N 이하이다. 그 다음 K줄에는 한 줄의 하나씩 소의 위치가 행과 열로 주어진다.

출력
길을 건너지 않으면 만날 수 없는 소가 몇 쌍인지 출력한다.

풀이:
BFS나 DFS로 각 소마다 탐색하는데, 탐색 시마다 map에 색을 칠해줍니다.
이미 칠해진 곳이면 만날 수 있는 소들입니다.

칠해진 색들의 종류와 해당 색을 가진 소의 수를 카운트하여 소의 쌍을 구합니다.
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