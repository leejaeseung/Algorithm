/*
문제
CTP의 대표 상남자 영조는 자유롭게 이동하는 것을 좋아한다. 그렇지만 영조는 상남자이기 때문에 위아래로만 간다. 따라서 위, 아래로는 얼마든지 이동할 수 있지만 왼쪽, 오른쪽으로는 이동하지 않는다. 하지만 영조의 행동이 답답한 영조의 친구 보성이는 영조가 위, 아래로만 가는 걸 막기 위해 영조와 같이 다니며 왼쪽으로 최대 L번 오른쪽으로 최대 R번만큼 이동할 수 있게 영조를 도와준다. 영조와 보성이는 지도 밖으로는 나가지 않는다.

갈수 있는 땅, 벽의 위치, 영조와 보성이의 출발 위치가 지도 정보로 주어졌을 때 영조와 보성이가 출발 위치로부터 이동해서 갈 수 있는 모든 땅의 개수를 구해보자.

다음은 이해를 돕기 위한 예제1 그림이다.



영조와 보성이가 시작 위치에서 갈수 있는 땅은 파란색, 벽이 있어 갈수 없는 땅은 검은색이다.

다음 그림은 영조와 보성이가 시작 위치에서 왼쪽으로 한 칸 이동했을 때이다.



왼쪽으로 한 칸 이동하였으므로 더 이상 왼쪽으로는 갈 수 없고, 현재 상태에서 갈수 있는 길은 파란색으로 나타내었다.

다음 그림은 영조와 보성이가 시작 위치에서 아래로 갔을 때이다.



영조와 보성이가 아래로 한 칸 이동했을 때의 갈 수 있는 땅과 현재 상태이다.

다음 그림은 영조와 보성이가 자유롭게 이동하였을 때 도달 가능한 땅을 나타낸다.



영조와 보성이가 최대 왼쪽으로 L번, 오른쪽으로 R번 만큼 움직여서 자유롭게 이동했을 때 도달 가능한 땅은 13칸이다.

입력
첫 번째 줄에 지도의 행과 열 N, M이 주어진다 (1 ≤ N, M ≤ 1,000)

두 번째 줄에 왼쪽과 오른쪽으로 갈수 있는 최대 횟수 L, R이 주어진다. (0 ≤ L, R ≤ M)

세 번째 줄부터 N+2줄까지 M 의 크기만큼 지도가 주어진다.

0: 갈 수 있는 땅
1: 벽이 있어 갈 수 없는 땅
2: 영조와 보성이가 있는 위치
출력
시작 위치를 포함하여 갈수 있는 땅의 개수를 출력한다.

풀이:
우선순위 큐를 이용한 BFS로 풀이했다.

위 아래로 갈 수 있는 땅을 굳이 왼쪽, 오른쪽을 사용하여 갈 필요가 없다.
따라서 땅을 들를 때마다 그 땅의 위아래를 무조건 먼저 탐색한다.

위,아래 갈 때의 우선 순위를 1로 주고 왼쪽, 오른쪽 갈 때의 우선 순위를 0으로 주면 항상 위아래가 큐에서 먼저 나온다.
단, 큐에 왼쪽, 오른쪽밖에 남지 않았다면 이동 횟수가 적은 쪽에게 우선 순위를 높게 준다.
(이동 횟수 = 왼쪽, 오른쪽으로 간 횟수, 위아래는 이동 횟수에 포함시키지 않는다)
*/
#include<iostream>
#include<memory.h>
#include<algorithm>
#include<math.h>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>
#define pdd pair<double, double>
#define pic pair<int, char>
#define ll long long
#define pll pair<ll, ll>
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vii vector<pii>
#define IMAX 2000000001
#define LMAX 1000000000000000000
#define DMAX 0xFFFFFFFFFFFFF
#define MOD 100003
int mv1[4] = { 0, 0, 1, -1 };
int mv2[4] = { 1, -1, 0, 0 };
int mv_all1[8] = { 0, 1, 0, -1, -1, -1, 1, 1 };
int mv_all2[8] = { 1, 0, -1, 0 , -1, 1, -1, 1 };

int n, m;
int L, R;
int maps[1001][1001];
bool visit[1001][1001];
int prio[4];
priority_queue<pair<pii, pair<pii, pii>>> pq;

int main(void) {
	FIO;

	cin >> n >> m >> L >> R;

	int ans = 0;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < m; j++)
		{
			maps[i][j] = int(str[j] - '0');
			if (maps[i][j] == 2) {
				pq.push({ {-1, 0}, {{i, j}, {0, 0}} });
			}
		}
	}

	prio[2] = 1;
	prio[3] = 1;
	//위아래 이동 시 우선 순위 높게

	while (!pq.empty()) {
		pii now = pq.top().second.first;
		pii LR = pq.top().second.second;
		int nowMove = -pq.top().first.second;
		pq.pop();

		if (LR.first > L || LR.second > R)	continue;
		if (visit[now.first][now.second])	continue;

		visit[now.first][now.second] = true;
		ans++;


		for (int i = 0; i < 4; i++)
		{
			int nx = now.first + mv1[i];
			int ny = now.second + mv2[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m)	continue;
			if (maps[nx][ny] == 1)	continue;

			if (!visit[nx][ny]) {

				pii nextLR = LR;
				int nextMove = nowMove + 1;

				if (i == 0)
					nextLR.second++;
				else if (i == 1)
					nextLR.first++;
				else
					nextMove--;
				//위아래 이동 시 이동 횟수 0


				pq.push({ {prio[i], -nextMove }, {{nx, ny}, nextLR } });
				//이동 횟수가 적은 순으로 우선 순위 부여
			}
		}
	}

	cout << ans;
}