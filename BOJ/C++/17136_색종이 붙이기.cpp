/*
문제
<그림 1>과 같이 정사각형 모양을 한 다섯 종류의 색종이가 있다. 색종이의 크기는 1×1, 2×2, 3×3, 4×4, 5×5로 총 다섯 종류가 있으며, 각 종류의 색종이는 5개씩 가지고 있다.



<그림 1>

색종이를 크기가 10×10인 종이 위에 붙이려고 한다. 종이는 1×1 크기의 칸으로 나누어져 있으며, 각각의 칸에는 0 또는 1이 적혀 있다. 1이 적힌 칸은 모두 색종이로 덮여져야 한다. 색종이를 붙일 때는 종이의 경계 밖으로 나가서는 안되고, 겹쳐도 안 된다. 또, 칸의 경계와 일치하게 붙여야 한다. 0이 적힌 칸에는 색종이가 있으면 안 된다.

종이가 주어졌을 때, 1이 적힌 모든 칸을 붙이는데 필요한 색종이의 최소 개수를 구해보자.

입력
총 10개의 줄에 종이의 각 칸에 적힌 수가 주어진다.

출력
모든 1을 덮는데 필요한 색종이의 최소 개수를 출력한다. 1을 모두 덮는 것이 불가능한 경우에는 -1을 출력한다.

풀이:
처음에는 오른쪽 아래부터 가장 큰 색종이를 채워가는 그리디한 풀이를 사용했는데, 작은 색종이를 먼저 썼을 때
더 효율적인 경우가 있어 백트래킹으로 풀이해야 했습니다.
각 점에서 다음 1인 점을 찾아 색종이를 모두 붙여보며 재귀호출을 반복합니다.
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