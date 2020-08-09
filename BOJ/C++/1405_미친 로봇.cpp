/*
문제
통제 할 수 없는 미친 로봇이 평면위에 있다. 그리고 이 로봇은 N번의 행동을 취할 것이다.

각 행동에서 로봇은 4개의 방향 중에 하나를 임의로 선택한다. 그리고 그 방향으로 한 칸 이동한다.

로봇이 같은 곳을 한 번보다 많이 이동하지 않을 때, 로봇의 이동 경로가 단순하다고 한다. (로봇이 시작하는 위치가 처음 방문한 곳이다.) 로봇의 이동 경로가 단순할 확률을 구하는 프로그램을 작성하시오. 예를 들어, EENE와 ENW는 단순하지만, ENWS와 WWWWSNE는 단순하지 않다. (E는 동, W는 서, N은 북, S는 남)

입력
첫째 줄에 N, 동쪽으로 이동할 확률, 서쪽으로 이동할 확률, 남쪽으로 이동할 확률, 북쪽으로 이동할 확률이 주어진다. N은 14보다 작거나 같은 자연수이고,  모든 확률은 100보다 작거나 같은 자연수 또는 0이다. 그리고, 동서남북으로 이동할 확률을 모두 더하면 100이다.

출력
첫째 줄에 로봇의 이동 경로가 단순할 확률을 출력한다. 절대/상대 오차는 10-9 까지 허용한다.

풀이:
최대 이동 가능 거리는 14칸이므로 적당한 50 x 50 의 맵을 만들어 방문 체크를 하면서
dfs로 탐색한다.

경로가 단순한 경우만 확률을 구해 최종 확률을 계산해가면 된다.
*/
#include<iostream>
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
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vii vector<pii>
#define IMAX 2000000001
#define LMAX 1000000000000000000
#define DMAX 0xFFFFFFFFFFFFF
int mv1[4] = { 0, 0, 1, -1 };
int mv2[4] = { 1, -1, 0, 0 };
int mv_all1[8] = { 0, 1, 0, -1, -1, -1, 1, 1 };
int mv_all2[8] = { 1, 0, -1, 0 , -1, 1, -1, 1 };

int n;
double perc[4];
bool visit[50][50];

double moves(int x, int y, double nowP, int mv) {

	if (mv >= n)	return nowP;
	visit[x][y] = true;
	double ret = 0;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + mv1[i];
		int ny = y + mv2[i];

		if (visit[nx][ny] || perc[i] == 0)	continue;

		ret += moves(nx, ny, perc[i], mv + 1);
	}
	visit[x][y] = false;

	return ret * nowP;
}

int main(void) {
	FIO;

	cin >> n;

	for (int i = 0; i < 4; i++)
	{
		cin >> perc[i];
		perc[i] /= 100;
	}

	cout.precision(10);
	cout << moves(25, 25, 1, 0);
}