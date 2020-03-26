/*
문제
4×4 격자판에 1에서 16까지 정수 번호가 매겨진 16개 타일이 임의로 놓여져 있다. 타일을 움직여 그림 1과 같이 타일을 놓이게 하려고 한다.



그림 1

타일을 움직이는 방법은 하나의 행(가로줄)을 오른쪽으로 원하는 칸 수만큼 순환적으로 움직이거나, 하나의 열(세로줄)을 원하는 칸 수만큼 아래쪽으로 순환적으로 움직이는 것이다. 그림 2는 그림 1의 2번째 행을 오른쪽으로 2칸 움직인 것이다. 그림 1의 2번째 행의 오른쪽 끝에 있는 7번 타일과 8번 타일이 오른쪽 경계를 넘어가서 왼쪽 끝으로 옮겨갔다.



그림 2

그림 3은 그림 2의 3번째 열을 아래쪽으로 1칸 움직인 것이다. 그림 2의 3번째 열의 가장 아래에 있는 15번 타일이 가장 위쪽으로 옮겨갔다.



그림 3

그림 3과 같이 타일이 놓여진 격자판이 주어졌다면 3번째 열을 3칸 움직인 다음, 2번째 행을 2칸 움직이면 그림 1과 같이 타일이 놓이게 된다. 따라서 2번 움직이면 된다.

1에서 16까지 번호가 매겨진 타일이 임의로 놓여져 있을 때 그림 1과 같이 타일이 놓일 수 있도록 타일을 움직이는 순서를 출력하는 프로그램을 작성하시오. 여기서 움직이는 횟수는 최소로 하여야 한다.

입력
4×4 격자판에 놓여진 타일 번호가 행단 위로 4개 줄에 주어진다. 타일 번호는 1부터 16까지의 정수이다.

각 줄에는 해당하는 행에 놓여지는 4개 타일의 번호가 빈칸을 사이에 두고 순서대로 주어진다.

출력
첫 번째 줄에는 움직이는 횟수를, 두 번째 줄부터는 한 줄에 하나씩 타일을 움직이는 방법을 순서대로 출력한다.

이때, 격자판의 i번째 행을 k칸 움직였다면 정수 1과 i와 k를 빈칸을 사이에 두고 한 줄에 출력한다. 그리고 격자판의 i번째 열을 k칸 움직였다면 정수 2와 i와 k를 빈칸을 사이에 두고 한 줄에 출력한다. 여기서 i는 1 이상 4 이하, k는 1 이상 3 이하의 정수이다.

풀이:
행과 열을 이동하는 경우가 8가지이므로 0~7로 번호를 매겨 나타냈습니다.
각 이동에 대해 칸수 1~3 을 가는 모든 경우를 탐색합니다.

이 때, 16개의 칸 중에 맞게 들어간 갯수를 가치지기 조건으로 합니다.
맞은 갯수가 16개이면 해당 경로를 저장합니다.

정답일 때, 즉 16개가 모두 맞게 들어갔을 때 행 혹은 열을 한 번 움직이게 되면 총 4개가 틀리게 됩니다.(12개가 맞게 들어가게 됩니다.)
따라서 정답의 개수가 12개 미만이면 최소 2번은 더 움직여야 정답을 맞출 수 있다는 얘깁니다.
같은 방식으로 정답의 개수가 9개 미만이면 최소 3번, 6개 미만이면 최소 4번을 더 움직여야 하므로 가지치기 조건을 추가해주면 시간을 줄일 수 있습니다.
*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include<stack>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>

int map[5][5];
int ans = 9;
vector<pii> route;

int getcnt() {
	int count = 1;
	int ret = 0;
	for (int i = 1; i < 5; i++)
	{
		for (int j = 1; j < 5; j++)
		{
			if (map[i][j] == count)
				ret++;
			count++;
		}
	}
	return ret;
}

void moveTile(int tile, int move) {
	bool flag = false;
	if (tile > 3)	flag = true;
	tile = tile % 4 + 1;
	
	for (int i = 0; i < move; i++)
	{
		if (flag) {
			int temp = map[1][tile];
			map[1][tile] = map[4][tile];
			map[4][tile] = map[3][tile];
			map[3][tile] = map[2][tile];
			map[2][tile] = temp;
		}
		else {
			int temp = map[tile][1];
			map[tile][1] = map[tile][4];
			map[tile][4] = map[tile][3];
			map[tile][3] = map[tile][2];
			map[tile][2] = temp;
		}
	}
}

void recul(int tile, int move, int cnt, vector<pii> now_route, int diff) {
	
	if (cnt >= ans || cnt == 8)	return;

	if (diff == 16) {
		route.clear();
		ans = min(ans, cnt);

		for (int i = 0; i < now_route.size(); i++)
		{
			route.push_back(now_route[i]);
		}
		return;
	}

	if (diff < 12 && cnt + 2 >= ans)	return;
	if (diff < 9 && cnt + 3 >= ans)	return;
	if (diff < 6 && cnt + 4 >= ans)	return;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			now_route.push_back(make_pair(i, j));
			moveTile(i, j);
			recul(i, j, cnt + 1, now_route, getcnt());
			moveTile(i, 4 - j);
			now_route.pop_back();
		}
	}
}

int main(void) {
	FIO;

	int diff = 0;
	int count = 1;
	for (int i = 1; i < 5; i++)
	{
		for (int j = 1; j < 5; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == count)
				diff++;
			count++;
		}
	}

	vector<pii> vt;
	recul(0, 0, 0, vt, diff);

	cout << ans << "\n";
	for (int i = 0; i < route.size(); i++)
	{
		int r = route[i].first;
		int c = route[i].second;

		if (r > 3) {
			cout << "2 " << r - 3 << " " << c << "\n";
		}
		else {
			cout << "1 " << r + 1 << " " << c << "\n";
		}
	}
}