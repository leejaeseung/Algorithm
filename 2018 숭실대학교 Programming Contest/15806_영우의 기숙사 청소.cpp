/*
문제
통학이 너무나도 하기 싫었던 영우는 결국 학교의 기숙사에 들어갔다. 통학의 고통에서 해방된 기쁨도 잠시, 학교 기숙사에서는 일정 기간마다 청소 검사를 한다는 사실을 알게 되었다. 청소 검사에서 나쁜 점수를 받으면 벌점을 받게 되고, 벌점이 많이 쌓이면 기숙사에서 퇴사 해야 한다. 영우는 어떤 경우에 벌점을 받는지 궁금하여 기숙사에서 진행하는 청소 검사 시스템에 대해 자세히 조사해 보았다. 기숙사 청소 검사 시스템은 오늘로부터 정확히 t 일이 지나고 검사를 하며, 검사 시간 단축을 위해 방의 특정 부분만 검사한다. 하지만 검사하는 특정 부분 중 한 곳이라도 더럽다면 영우는 벌점을 받게 된다. 영우가 사는 방은 N * N 정사각형 방이며, 기숙사 방바닥에는 곰팡이가 서식하고 있다. 곰팡이는 1 일이 지날 때마다 특이한 방식으로 증식하는데, 그림 1(a)의 곰팡이는 1 일이 지나면 그림 1(b)와 같이 8 군데로 증식되고, 원래의 곰팡이는 사라진다. 만약 곰팡이가 증식해야 하는 부분이 벽으로 막혀 있다면, 그곳으로는 증식하지 못한다. 그림 2 는 두 군데의 곰팡이가 1 일이 지난 후 모습이다.



그림 1(a)                                                                     그림 1(b)



그림 2(a)                                                                   그림 2(b)

대학원을 준비하느라 바쁜 영우는 청소 검사에서 벌점을 받지 않는다면, 굳이 청소하지 않으려고 한다. 바쁜 영우를 위해 여러분이 영우가 청소를 해야 하는지 아닌지를 알려주자.

입력
프로그램의 입력은 표준 입력으로 받는다. 첫 줄에 영우의 방의 크기, 방에 있는 곰팡이의 개수, 청소 검사 시스템이 검사하는 방바닥 좌표의 개수, 청소 검사가 실시 되기까지 남은 일수인 N M K t 가 주어진다. (1 ≤ N ≤ 300, 0 ≤ M ≤ N2, 0 ≤ K ≤ N2, 1 ≤ t ≤ 10000)

둘째 줄부터 M 개의 줄에 걸쳐 영우의 방에 있는 곰팡이의 위치인 Mx My가 주어진다.(1 ≤ Mx, My ≤ N)

다음 줄부터 K 개의 줄에 걸쳐 검사관이 검사하는 방바닥의 위치인 Kx Ky가 주어진다.(1 ≤ Kx, Ky ≤ N)

풀이:
짝수 번째날엔 제자리로 돌아오는 것을 이용해 방문을 체크해준다.
*/
/*#include<iostream>
#include<algorithm>
#include<queue>
#include<utility>
#include<vector>
using namespace std;

int N, M, K, T;
bool room[301][301][2];
vector<pair<int, int >> check;
int mv1[8] = { -2,-2,2,2,-1,-1,1,1 };
int mv2[8] = { 1,-1,1,-1,2,-2,2,-2 };
queue<pair<int, int>> q;

void BFS() {

	int cnt = 0;
	while (!q.empty()) {
		int size = q.size();
		cnt++;
		if (cnt > T)
			return;

		for (int i = 0; i < size; i++)
		{
			int nowx = q.front().first;
			int nowy = q.front().second;
			q.pop();

			for (int j = 0; j < 8; j++)
			{
				int nextx = nowx + mv1[j];
				int nexty = nowy + mv2[j];

				if (nextx <= 0 || nexty <= 0 || nextx > N || nexty > N)	continue;
				if (!room[nextx][nexty][cnt % 2]) {
					room[nextx][nexty][cnt % 2] = true;
					q.push(make_pair(nextx, nexty));
				}
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> K >> T;
	bool clean = true;

	for (int i = 0; i < M; i++)
	{
		int x, y;
		cin >> x >> y;
		q.push(make_pair(N - y + 1, x));
		room[N - y + 1][x][0] = true;
	}
	for (int i = 0; i < K; i++)
	{
		int x, y;
		cin >> x >> y;
		check.push_back(make_pair(N - y + 1, x));
	}
	BFS();
	for (int i = 0; i < check.size(); i++)
	{
		if (room[check[i].first][check[i].second][T % 2]) {
			clean = false;
		}
	}

	if (clean)
		cout << "NO";
	else
		cout << "YES";

}*/