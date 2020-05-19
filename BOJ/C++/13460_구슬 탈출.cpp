/*
문제
스타트링크에서 판매하는 어린이용 장난감 중에서 가장 인기가 많은 제품은 구슬 탈출이다. 구슬 탈출은 직사각형 보드에 빨간 구슬과 파란 구슬을 하나씩 넣은 다음, 빨간 구슬을 구멍을 통해 빼내는 게임이다.

보드의 세로 크기는 N, 가로 크기는 M이고, 편의상 1×1크기의 칸으로 나누어져 있다. 가장 바깥 행과 열은 모두 막혀져 있고, 보드에는 구멍이 하나 있다. 빨간 구슬과 파란 구슬의 크기는 보드에서 1×1크기의 칸을 가득 채우는 사이즈이고, 각각 하나씩 들어가 있다. 게임의 목표는 빨간 구슬을 구멍을 통해서 빼내는 것이다. 이때, 파란 구슬이 구멍에 들어가면 안 된다.

이때, 구슬을 손으로 건드릴 수는 없고, 중력을 이용해서 이리 저리 굴려야 한다. 왼쪽으로 기울이기, 오른쪽으로 기울이기, 위쪽으로 기울이기, 아래쪽으로 기울이기와 같은 네 가지 동작이 가능하다.

각각의 동작에서 공은 동시에 움직인다. 빨간 구슬이 구멍에 빠지면 성공이지만, 파란 구슬이 구멍에 빠지면 실패이다. 빨간 구슬과 파란 구슬이 동시에 구멍에 빠져도 실패이다. 빨간 구슬과 파란 구슬은 동시에 같은 칸에 있을 수 없다. 또, 빨간 구슬과 파란 구슬의 크기는 한 칸을 모두 차지한다. 기울이는 동작을 그만하는 것은 더 이상 구슬이 움직이지 않을 때 까지이다.

보드의 상태가 주어졌을 때, 최소 몇 번 만에 빨간 구슬을 구멍을 통해 빼낼 수 있는지 구하는 프로그램을 작성하시오.

입력
첫 번째 줄에는 보드의 세로, 가로 크기를 의미하는 두 정수 N, M (3 ≤ N, M ≤ 10)이 주어진다. 다음 N개의 줄에 보드의 모양을 나타내는 길이 M의 문자열이 주어진다. 이 문자열은 '.', '#', 'O', 'R', 'B' 로 이루어져 있다. '.'은 빈 칸을 의미하고, '#'은 공이 이동할 수 없는 장애물 또는 벽을 의미하며, 'O'는 구멍의 위치를 의미한다. 'R'은 빨간 구슬의 위치, 'B'는 파란 구슬의 위치이다.

입력되는 모든 보드의 가장자리에는 모두 '#'이 있다. 구멍의 개수는 한 개 이며, 빨간 구슬과 파란 구슬은 항상 1개가 주어진다.

출력
최소 몇 번 만에 빨간 구슬을 구멍을 통해 빼낼 수 있는지 출력한다. 만약, 10번 이하로 움직여서 빨간 구슬을 구멍을 통해 빼낼 수 없으면 -1을 출력한다.

풀이:
DFS로 풀이하였습니다.
10x10 지도를 10번 이하로 탐색하므로 모든 경로를 탐색해주면 됩니다.
R과 B가 겹칠 수 없으므로 만약 겹치는 경우에 R과 B중 더 많이 이동한 구슬의 좌표를 한번 빼줍니다.

그리고 시간 절약을 위해 구슬 R,B 의 좌표와 그 때의 횟수를 방문체크해 주었습니다.(5차원 배열)
*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>
#define pic pair<int, char>
#define ll long long
#define vi vector<int>
#define vl vector<long long>
#define vii vector<pii>
#define IMAX 2000000001
int mv1[4] = { 0, 0, 1, -1 };
int mv2[4] = { 1, -1, 0, 0 };

int n, m;
char maps[11][11];
bool visit[11][11][11][11][11];
int ans = IMAX;

void recul(pii pos_R, pii pos_B, int cnt) {

	if (cnt > 9)	return;

	for (int i = 0; i < 4; i++)
	{
		int nxR = pos_R.first;
		int nyR = pos_R.second;
		int nxB = pos_B.first;
		int nyB = pos_B.second;
		int f1 = 0;
		int f2 = 0;
		bool out1 = false;
		bool out2 = false;
		bool imp = false;
		bool succ = false;

		while (true) {
			if (maps[nxB][nyB] == 'O') {
				imp = true;
				break;
			}
			if (maps[nxR][nyR] == 'O') {
				succ = true;
			}

			if (out1 && out2)	break;

			if (nxR + mv1[i] >= 0 && nyR + mv2[i] >= 0 && nxR + mv1[i] < n && nyR + mv2[i] < m && maps[nxR + mv1[i]][nyR + mv2[i]] != '#') {
				f1++;
				nxR += mv1[i];
				nyR += mv2[i];
			}
			else
				out1 = true;

			if (nxB + mv1[i] >= 0 && nyB + mv2[i] >= 0 && nxB + mv1[i] < n && nyB + mv2[i] < m && maps[nxB + mv1[i]][nyB + mv2[i]] != '#') {
				f2++;
				nxB += mv1[i];
				nyB += mv2[i];
			}
			else
				out2 = true;

			
		}
		if (!imp) {
			if (succ) {
				ans = min(ans, cnt + 1);
				return;
			}
			if (nxR == nxB && nyR == nyB) {
				if (f1 > f2) {
					nxR -= mv1[i];
					nyR -= mv2[i];
				}
				else {
					nxB -= mv1[i];
					nyB -= mv2[i];
				}
			}

			if (!visit[nxR][nyR][nxB][nyB][cnt] && cnt < 9) {
				visit[nxR][nyR][nxB][nyB][cnt] = true;
				recul(make_pair(nxR, nyR), make_pair(nxB, nyB), cnt + 1);
			}
		}
	}
}

int main(void) {
	FIO;

	cin >> n >> m;

	pii pr, pb;

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			maps[i][j] = s[j];
			if (s[j] == 'R')
				pr = make_pair(i, j);
			if (s[j] == 'B')
				pb = make_pair(i, j);
		}
	}

	visit[pr.first][pr.second][pb.first][pb.second][0] = true;
	recul(pr, pb, 0);

	if (ans == IMAX)
		cout << "-1";
	else
		cout << ans;
}