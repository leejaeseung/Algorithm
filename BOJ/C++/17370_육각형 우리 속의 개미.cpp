/*
문제
무한히 많은 정육각형이 서로 맞닿아 놓인 형태의 개미 우리가 있다. 다음 그림과 같은 형태이고, 하얀색 변으로만 개미가 다닐 수 있다.

img1

개미 우리의 모습

곤충 관찰이 취미인 유이는 세 정육각형이 서로 맞닿아 있는 어떤 점 위에 개미를 하나 올렸다. 이렇게 우리에 올라온 개미는 그 자신에게 미지의 영역인 우리를 페로몬을 뿌리며 탐색하기 시작했다. 처음 개미는 점과 연결된 세 변 중 하나를 향해 이동을 시작하는데, 편의를 위해 이 첫 번째 이동이 북쪽을 향하도록 돌려서 보자.

만약 개미가 변이 세 갈래로 갈라지는 점에 도착하면, 자신이 이동해온 변을 제외한 나머지 두 변 중 하나를 골라 그 방향으로 회전하여 탐색을 계속한다.

img2

연두색은 시작 지점, 초록색은 개미가 탐색하며 페로몬을 뿌린 경로. 검은색은 개미, 주황색은 다음 이동을 위해 선택 가능한 두 변을 나타낸다.

개미가 이전에 방문했던, 즉, 페로몬이 뿌려진 지점에 도착하면 이곳이 이미 익숙한 영역이라는 착각에 빠지고 더 이상의 탐색을 멈춘다. 이렇게 탐색을 멈췄을 때, 방향을 회전한 횟수가 정확히 N번이 되는 경우의 수를 구해보자.

img3

방향을 7번 회전하는 두 경로. 페로몬의 궤적은 동일해도 개미의 이동 방향에 따라 경로를 구별하도록 한다.

입력
첫 번째 줄에 하나의 정수 N(1 ≤ N ≤ 22)이 주어진다.

출력
첫 번째 줄에 개미가 방향 회전을 N번 하고 멈추는 경우의 수를 출력한다.

풀이:
방향을 꺾는 것을 상,하,좌,우로 생각했습니다.
이동 횟수가 홀수 번이면, 좌,우,하 로만 갈 수 있고, 짝수 번이면 좌,우,상 으로만 갈 수 있습니다.
visit[][] 배열로 좌우 몇칸, 상하 몇칸을 방문했는지 나타내어 재방문시 이동 횟수가 N + 1 번이라면 카운트해줍니다.
단, 방문한 곳을 찾기 때문에 이전 경로를 다시 방문할 수 있습니다.
4차원 배열 : a지점 -> b지점 에 대한 방문을 체크하여 걸러줍니다.
*/

#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include<stack>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pii pair<int, int>;

int N;
bool visit[100][100][100][100];
bool visit2[100][100];

int BT(int cnt, int r, int u, int f_r, int f_u) {
	if (cnt > N + 1)	return 0;
	if (visit2[r][u]) {
		if (visit[r][u][f_r][f_u])	return 0;
		if (cnt == N + 1) {
			return 1;
		}
		return 0;
	}
	visit2[r][u] = true;
	
	int ret = 0;

	if (cnt % 2 == 0) {
		visit[r][u][r + 1][u] = true;
		ret += BT(cnt + 1, r + 1, u, r, u);
		visit[r][u][r + 1][u] = false;
		visit[r][u][r][u + 1] = true;
		ret += BT(cnt + 1, r, u + 1, r, u);
		visit[r][u][r][u + 1] = false;
		visit[r][u][r - 1][u] = true;
		ret += BT(cnt + 1, r - 1, u, r, u);
		visit[r][u][r - 1][u] = false;
	}
	else {
		visit[r][u][r + 1][u] = true;
		ret += BT(cnt + 1, r + 1, u, r, u);
		visit[r][u][r + 1][u] = false;
		visit[r][u][r][u - 1] = true;
		ret += BT(cnt + 1, r, u - 1, r, u);
		visit[r][u][r][u - 1] = false;
		visit[r][u][r - 1][u] = true;
		ret += BT(cnt + 1, r - 1, u, r, u);
		visit[r][u][r - 1][u] = false;
	}

	visit2[r][u] = false;
	return ret;
}

int main(void) {
	FIO;

	cin >> N;

	visit2[50][50] = true;
	visit[50][50][50][51] = true;
	cout << BT(1, 50, 51, 50, 50);
}