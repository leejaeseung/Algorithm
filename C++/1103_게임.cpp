/*
문제
형택이는 1부터 9까지의 숫자와, 구멍이 있는 직사각형 보드에서 재밌는 게임을 한다.

일단 보드의 가장 왼쪽 위에 동전을 하나 올려놓는다. 그다음에 다음과 같이 동전을 움직인다.

동전이 있는 곳에 쓰여 있는 숫자 X를 본다.
위, 아래, 왼쪽, 오른쪽 방향 중에 한가지를 고른다.
동전을 위에서 고른 방향으로 X만큼 움직인다. 이때, 중간에 있는 구멍은 무시한다.
만약 동전이 구멍에 빠지거나, 보드의 바깥으로 나간다면 게임은 종료된다. 형택이는 이 재밌는 게임을 되도록이면 오래 하고 싶다.

보드의 상태가 주어졌을 때, 형택이가 최대 몇 번 동전을 움직일 수 있는지 구하는 프로그램을 작성하시오.

입력
줄에 보드의 세로 크기 N과 가로 크기 M이 주어진다. 이 값은 모두 50보다 작거나 같은 자연수이다. 둘째 줄부터 N개의 줄에 보드의 상태가 주어진다. 쓰여 있는 숫자는 1부터 9까지의 자연수 또는 H이다. 가장 왼쪽 위칸은 H가 아니다. H는 구멍이다.

출력
첫째 줄에 문제의 정답을 출력한다. 만약 형택이가 동전을 무한번 움직일 수 있다면 -1을 출력한다.

풀이:

dp[][] 배열에 해당 좌표까지의 최대 카운트 수를 저장합니다.
이미 방문한(dp 배열에 카운트가 올라간) 곳이라면 현재 카운트 + 1 과 해당 좌표의 dp 값을 비교합니다.
해당 좌표가 더 크다면 굳이 다시 들리지 않아도 됩니다.
*/

#include<iostream>
#include<queue>
#include<math.h>
#include<utility>
using namespace std;

int N, M;
int dp[50][50];
char map[50][50];
char s[51];
int mv1[4] = { 0,0,1,-1 };
int mv2[4] = { 1,-1,0,0 };

int BFS() {
	queue<pair<int, pair<int, int> > > q;

	q.push(pair<int, pair<int, int> >(0, pair<int, int>(0, 0)));

	int max_v = 0;

	while (!q.empty()) {
		int cnt = q.front().first;
		int x = q.front().second.first;
		int y = q.front().second.second;
		q.pop();

		max_v = max(max_v, dp[x][y]);
		if (max_v > 2500)
			return -1;

		for (int i = 0; i < 4; i++)
		{
			int next_x = x + mv1[i] * (int)(map[x][y] - '0');
			int next_y = y + mv2[i] * (int)(map[x][y] - '0');

			if (next_x < 0 || next_y < 0 || next_x >= N || next_y >= M)	continue;

			if(cnt + 1 > dp[next_x][next_y]){
				dp[next_x][next_y] = cnt + 1;

				if (map[next_x][next_y] == 'H')
					continue;
				
				q.push(pair<int, pair<int, int> >(cnt + 1, pair<int, int>(next_x, next_y)));
			}
		}
	}
	return max_v + 1;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> s;
		for (int j = 0; j < M; j++)
		{
			map[i][j] = s[j];
		}
	}
	cout << BFS();

}