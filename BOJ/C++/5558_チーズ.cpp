/*
문제
今年も JOI 町のチーズ工場がチーズの生産を始め，ねずみが巣から顔を出した．JOI 町は東西南北に区画整理されていて，各区画は巣，チーズ工場，障害物，空き地のいずれかである．ねずみは巣から出発して全てのチーズ工場を訪れチーズを 1 個ずつ食べる．

この町には，N 個のチーズ工場があり，どの工場も１種類のチーズだけを生産している．チーズの硬さは工場によって異なっており，硬さ 1 から N までのチーズを生産するチーズ工場がちょうど 1 つずつある．

ねずみの最初の体力は 1 であり，チーズを 1 個食べるごとに体力が 1 増える．ただし，ねずみは自分の体力よりも硬いチーズを食べることはできない．

ねずみは，東西南北に隣り合う区画に 1 分で移動することができるが，障害物の区画には入ることができない．チーズ工場をチーズを食べずに通り過ぎることもできる．すべてのチーズを食べ終えるまでにかかる最短時間を求めるプログラムを書け．ただし，ねずみがチーズを食べるのにかかる時間は無視できる．

입력
入力は H+1 行ある．1 行目には 3 つの整数 H，W，N (1 ≦ H ≦ 1000，1 ≦ W ≦ 1000，1 ≦ N ≦ 9) がこの順に空白で区切られて書かれている．2 行目から H+1 行目までの各行には，'S'，'1', '2', ..., '9'，'X'，'.' からなる W 文字の文字列が書かれており，各々が各区画の状態を表している．北から i 番目，西から j 番目の区画を (i,j) と記述することにすると (1 ≦ i ≦ H, 1 ≦ j ≦ W)，第 i+1 行目の j 番目の文字は，区画 (i,j) が巣である場合は 'S' となり，障害物である場合は 'X' となり，空き地である場合は '.' となり，硬さ 1, 2, ..., 9 のチーズを生産する工場である場合はそれぞれ '1', '2', ..., '9' となる．入力には巣と硬さ 1, 2, ..., N のチーズを生産する工場がそれぞれ 1 つずつある．他のマスは障害物または空き地であることが保証されている．ねずみは全てのチーズを食べられることが保証されている．

출력
すべてのチーズを食べ終えるまでにかかる最短時間（分）を表す整数を 1 行で出力せよ．

풀이:
bfs 기본 문제(번역기 빡세게 돌림)

치즈를 먹을 때마다 해당 지점에서 다시 bfs를 시작하면 된다.
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
int mv1[4] = { 0, 1, 0, -1 };
int mv2[4] = { 1, 0, -1, 0 };
int mv_all1[8] = { 0, 1, 0, -1, -1, -1, 1, 1 };
int mv_all2[8] = { 1, 0, -1, 0 , -1, 1, -1, 1 };

int h, w, n;
char maps[1001][1001];
bool visit[1001][1001];

int main(void) {
	FIO;

	cin >> h >> w >> n;

	queue<pair<pii, pii>> q;

	for (int i = 0; i < h; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < w; j++)
		{
			maps[i][j] = str[j];
			if (maps[i][j] == 'S') {
				q.push(make_pair(make_pair(i, j), make_pair(1, 0)));
				maps[i][j] = '.';
				visit[i][j] = true;
			}
		}
	}

	while (!q.empty()) {
		pii now = q.front().first;
		int nowHP = q.front().second.first;
		int nowStep = q.front().second.second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nextx = now.first + mv1[i];
			int nexty = now.second + mv2[i];

			if (nextx < 0 || nexty < 0 || nextx >= h || nexty >= w)	continue;
			if (maps[nextx][nexty] == 'X')	continue;
			if (visit[nextx][nexty])	continue;

			visit[nextx][nexty] = true;

			if (maps[nextx][nexty] == '.' || maps[nextx][nexty] - '0' > nowHP) {
				q.push(make_pair(make_pair(nextx, nexty), make_pair(nowHP, nowStep + 1)));
			}
			else{
				maps[nextx][nexty] = '.';

				for (int i = 0; i < h; i++)
				{
					for (int j = 0; j < w; j++)
					{
						visit[i][j] = false;
					}
				}

				queue<pair<pii, pii>> temp;
				q.swap(temp);

				if (nowHP == n) {
					cout << nowStep + 1;
					exit(0);
				}

				q.push(make_pair(make_pair(nextx, nexty), make_pair(nowHP + 1, nowStep + 1)));
				break;
			}
		}
	}
}