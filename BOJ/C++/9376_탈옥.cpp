/*
문제
상근이는 감옥에서 죄수 두 명을 탈옥시켜야 한다. 이 감옥은 1층짜리 건물이고, 상근이는 방금 평면도를 얻었다.

평면도에는 모든 벽과 문이 나타나있고, 탈옥시켜야 하는 죄수의 위치도 나타나 있다. 감옥은 무인 감옥으로 죄수 두 명이 감옥에 있는 유일한 사람이다.

문은 중앙 제어실에서만 열 수 있다. 상근이는 특별한 기술을 이용해 제어실을 통하지 않고 문을 열려고 한다. 하지만, 문을 열려면 시간이 매우 많이 걸린다. 두 죄수를 탈옥시키기 위해서 열어야 하는 문의 개수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 테스트 케이스의 개수가 주어진다. 테스트 케이스의 수는 100개를 넘지 않는다.

첫째 줄에는 평면도의 높이 h와 너비 w가 주어진다. (2 ≤ h, w ≤ 100) 다음 h개 줄에는 감옥의 평면도 정보가 주어지며, 빈 공간은 '.', 지나갈 수 없는 벽은 '*', 문은 '#', 죄수의 위치는 '$'이다.

상근이는 감옥 밖을 자유롭게 이동할 수 있고, 평면도에 표시된 죄수의 수는 항상 두 명이다. 각 죄수와 감옥의 바깥을 연결하는 경로가 항상 존재하는 경우만 입력으로 주어진다.

출력
각 테스트 케이스마다 두 죄수를 탈옥시키기 위해서 열어야 하는 문의 최솟값을 출력한다.

풀이:
https://jaimemin.tistory.com/1243
위 블로그를 참고하여 풀이함.

상근, 죄수1, 죄수2 총 세명이 어느 지점(i, j) 까지 문을 연 최소 횟수를 미리 구해놓는다.
(다익스트라 이용)

모든 점에 대해 세 명이 연 횟수를 더한 값의 최소값이 정답이 되는데
어떤 점이 '#' 이라면 중복이 세 번 일어났으므로 2를 뺴주고 계산하면 된다.
(죄수가 탈출했다. == 세 명이 한 지점에서 만났다. 이므로)

맵을 '.' 으로 한 번 감싸준 뒤 상근이는 (0, 0) 에서 출발시킨다.
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

int h, w;
char maps[103][103];
int dis[3][103][103];
pii player[3];

int main(void) {
	FIO;

	int t;
	cin >> t;

	while (t--) {
		cin >> h >> w;

		int p = 1;
		player[0] = make_pair(0, 0);

		for (int i = 0; i <= h + 1; i++)
		{
			string str;
			if (i > 0 && i <= h)
			cin >> str;

			for (int j = 0; j <= w + 1; j++)
			{
				dis[0][i][j] = IMAX;
				dis[1][i][j] = IMAX;
				dis[2][i][j] = IMAX;

				if (i == 0 || j == 0 || i == h + 1 || j == w + 1)
					maps[i][j] = '.';
				else {
					maps[i][j] = str[j - 1];

					
					

					if (maps[i][j] == '$') {
						player[p] = make_pair(i, j);
						maps[i][j] = p++;
					}
				}
			}
		}
		
		priority_queue<pair<pii, pii>> pq;

		for (int i = 0; i < 3; i++)
		{
			int x = player[i].first;
			int y = player[i].second;

			dis[i][x][y] = 0;
			pq.push(make_pair(make_pair(0, i), make_pair(x, y)));
		}

		while (!pq.empty()) {
			int nowDis = -pq.top().first.first;
			int nowP = pq.top().first.second;
			int nowx = pq.top().second.first;
			int nowy = pq.top().second.second;
			pq.pop();

			for (int i = 0; i < 4; i++)
			{
				int nx = nowx + mv1[i];
				int ny = nowy + mv2[i];

				if (nx < 0 || ny < 0 || nx > h + 1 || ny > w + 1)	continue;
				if (maps[nx][ny] == '*')	continue;

				if (maps[nx][ny] == '#') {
					if (dis[nowP][nx][ny] > dis[nowP][nowx][nowy] + 1) {
						dis[nowP][nx][ny] = dis[nowP][nowx][nowy] + 1;

						pq.push(make_pair(make_pair(-dis[nowP][nx][ny], nowP), make_pair(nx, ny)));
					}
				}
				else {
					if (dis[nowP][nx][ny] > dis[nowP][nowx][nowy]) {
						dis[nowP][nx][ny] = dis[nowP][nowx][nowy];

						pq.push(make_pair(make_pair(-dis[nowP][nx][ny], nowP), make_pair(nx, ny)));
					}
				}
			}
		}

		int ans = IMAX;

		for (int i = 0; i <= h + 1; i++)
		{
			for (int j = 0; j <= w + 1; j++)
			{
				if (maps[i][j] != '*') {
					int sum = 0;

					for (int k = 0; k < 3; k++)
					{
						sum += dis[k][i][j];
					}

					if (maps[i][j] == '#') {
						sum -= 2;
					}

					ans = min(ans, sum);
				}
			}
		}

		cout << ans << "\n";
	}
}