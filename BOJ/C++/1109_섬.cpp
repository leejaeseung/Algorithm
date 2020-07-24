/*
문제
지민이는 보물을 찾아 떠나기 위해 섬과 바다가 그려져 있는 지도를 샀다.

지도는 N*M 크기의 직사각형 모양이고, 각각의 1*1크기의 칸에는 ‘x’ 또는 ‘.’중의 하나가 쓰여 있다.

바다는 ‘.’이 가로로 또는 세로로 최대로 연결되어 있는 그룹이다.

섬은 ‘x’가 가로, 세로, 또는 대각선으로 최대로 연결되어 있는 그룹이다.

만약 어떤 섬이 다른 섬을 포함하고 있지 않는다면, 그 섬은 높이가 0이다. 만약 어떤 섬A가 포함하고 있는 섬중에 가장 높이가 높은 섬의 높이가 K라면, 그 섬 A의 높이는 K+1이다.

섬 A가 섬 B를 포함한다는 말은, 일단 A와 B가 다르고, 섬 B의 어느 곳에서 출발해도 A의 밖으로 나갈 수 없을 때이다. 이때 대각선으로 이동은 불가능하다.

다음과 같은 지도를 보자.

xxx.x...xxxxx        000.0...11111
xxxx....x...x        0000....1...1
........x.x.x        ........1.4.1
..xxxxx.x...x        ..55555.1...1
..x...x.xxx.x        ..5...5.111.1
..x.x.x...x..        ..5.3.5...1..
..x...x...xxx        ..5...5...111
...xxxxxx....        ...555555....
x............        2............
섬은 총 6개가 있다. 높이가 0인 섬은 5개이다. (0~4) 그리고, 높이가 1인 섬은 1개 있다. (5) 3번 섬에서 출발해서 5번 섬의 밖으로 나갈 수 없기 때문에 섬5는 섬3을 포함하고 있는 것이다. 하지만, 섬4에서 출발해서 섬1을 나갈 수 있으므로 ,섬1은 섬4를 포함하고 있는 것이 아니다.

지도가 주어졌을 때, 높이가 0인 섬의 개수부터 높이가 M인 섬의 개수까지를 차례대로 출력하는 프로그램을 작성하시오. M은 지도에 있는 섬 중에서 가장 높은 높이이다.

입력
첫째 줄에 N과 M이 주어진다. N과 M은 50보다 작거나 같은 자연수이다. 둘째 줄부터 N개의 줄에 섬의 지도가 주어진다.

출력
첫째 줄에 높이가 0인 섬의 개수, 높이가 1인 섬의 개수, …, 높이가 M인 섬의 개수 까지 공백으로 구분해서 출력한다. 만약 섬이 하나도 없을 때는 -1을 출력한다.

풀이:
먼저 조건에 따라 모든 섬에 번호를 매깁니다.(dfs로 해당 섬과 연결된 모든 x에 번호를 매깁니다.)
이 때 당연하게도 어떤 섬 A가 섬 B에 포함된다면, (A의 번호) > (B의 번호) 가 되게 됩니다.
(겉 부분인 섬은 dfs를 통해 이미 번호가 매겨져 있기 때문)

따라서 어떤 섬의 가장 가깝게 포함하고 있는 섬(parent) = 도달할 수 있는 섬의 번호 중 최소 값
이 됩니다.
(탐색 중 맵을 벗어날 경우는 -1로 해 주었습니다.)

모든 섬에 대해 parent를 구했으면 역으로 child를 모두 달아주고, child 중 가장 깊은 child의 깊이가 해당 섬의
높이가 됩니다.
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
int mv_all2[8] = { 1, 0, -1, 0 , -1, 1, -1, 1};

int r, c;
char maps[51][51];
int color[51][51];
int height[3000];
bool check[3000];
bool visit[51][51];
int parent[3000];
vector<int> child[3000];

int dfs(int now) {

	int ret = -1;

	for (int i = 0; i < child[now].size(); i++)
	{
		ret = max(ret, dfs(child[now][i]));
	}

	return ret + 1;
}

int main(void) {
	FIO;

	cin >> r >> c;

	stack<pii> st;

	for (int i = 0; i < r; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < c; j++)
		{
			maps[i][j] = str[j];
			
			color[i][j] = -1;
		}
	}

	for (int i = 0; i < 3000; i++)
	{
		parent[i] = IMAX;
	}

	int clr = 0;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (maps[i][j] == 'x' && color[i][j] == -1) {
				st.push(make_pair(i, j));

				while (!st.empty()) {
					int nowx = st.top().first;
					int nowy = st.top().second;
					st.pop();

					color[nowx][nowy] = clr;
					//섬에 번호를 부여

					for (int k = 0; k < 8; k++)
					{
						int nextx = nowx + mv_all1[k];
						int nexty = nowy + mv_all2[k];

						if (nextx < 0 || nexty < 0 || nextx >= r || nexty >= c)	continue;
						if (maps[nextx][nexty] == 'x' && color[nextx][nexty] == -1) {
							st.push(make_pair(nextx, nexty));
						}
					}
				}
				clr++;
			}
		}
	}

	stack<pair<pii, int>> escape_st;
	vector<pii> start;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (maps[i][j] == 'x' && !check[color[i][j]]) {
				//섬에 대해 탐색을 시작할 점을 단 하나만 스택에 넣음
				check[color[i][j]] = true;
				start.push_back(make_pair(i, j));
			}
		}
	}

	for (int i = 0; i < start.size(); i++)
	{
		for (int j = 0; j < 51; j++)
		{
			for (int k = 0; k < 51; k++)
			{
				visit[j][k] = false;
			}
		}

		escape_st.push(make_pair(make_pair(start[i].first, start[i].second), color[start[i].first][start[i].second]));

		while (!escape_st.empty()) {
			int nowx = escape_st.top().first.first;
			int nowy = escape_st.top().first.second;
			int nowcolor = escape_st.top().second;
			escape_st.pop();

			visit[nowx][nowy] = true;

			for (int j = 0; j < 4; j++)
			{
				int nextx = nowx + mv1[j];
				int nexty = nowy + mv2[j];

				if (nextx < 0 || nexty < 0 || nextx >= r || nexty >= c) {
					//맵을 벗어날 시 parent는 -1
					parent[nowcolor] = -1;
					continue;
				}
				if (visit[nextx][nexty])	continue;
				
				if (maps[nextx][nexty] == 'x' && color[nextx][nexty] != nowcolor) {
					//parent 갱신
					parent[nowcolor] = min(parent[nowcolor], color[nextx][nexty]);
				}
				else {
					escape_st.push(make_pair(make_pair(nextx, nexty), nowcolor));
				}


			}
		}
	}

	for (int i = 0; i < clr; i++)
	{
		if (parent[i] != -1) {
			child[parent[i]].push_back(i);
		}
	}

	int maxH = -1;

	for (int i = 0; i < clr; i++)
	{
		int h = dfs(i);
		maxH = max(maxH, h);
		height[h]++;
	}

	if (maxH > -1) {
		for (int i = 0; i <= maxH; i++)
		{
			cout << height[i] << " ";
		}
	}
	else {
		cout << "-1";
	}
}