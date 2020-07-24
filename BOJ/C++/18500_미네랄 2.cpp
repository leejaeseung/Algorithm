/*
문제
창영과 상근은 한 동굴을 놓고 소유권을 주장하고 있다. 두 사람은 막대기를 서로에게 던지는 방법을 이용해 누구의 소유인지를 결정하기로 했다. 싸움은 동굴에서 벌어진다. 동굴에는 미네랄이 저장되어 있으며, 던진 막대기가 미네랄을 파괴할 수도 있다.

동굴은 R행 C열로 나타낼 수 있으며, R×C칸으로 이루어져 있다. 각 칸은 비어있거나 미네랄을 포함하고 있으며, 네 방향 중 하나로 인접한 미네랄이 포함된 두 칸은 같은 클러스터이다.

창영은 동굴의 왼쪽에 서있고, 상근은 오른쪽에 서있다. 두 사람은 턴을 번갈아가며 막대기를 던진다. 막대를 던지기 전에 던질 높이를 정해야 한다. 막대는 땅과 수평을 이루며 날아간다.

막대가 날아가다가 미네랄을 만나면, 그 칸에 있는 미네랄은 모두 파괴되고 막대는 그 자리에서 이동을 멈춘다.

미네랄이 파괴된 이후에 남은 클러스터가 분리될 수도 있다. 새롭게 생성된 클러스터가 떠 있는 경우에는 중력에 의해서 바닥으로 떨어지게 된다. 떨어지는 동안 클러스터의 모양은 변하지 않는다. 클러스터는 다른 클러스터나 땅을 만나기 전까지 게속해서 떨어진다. 클러스터는 다른 클러스터 위에 떨어질 수 있고, 그 이후에는 합쳐지게 된다.

동굴에 있는 미네랄의 모양과 두 사람이 던진 막대의 높이가 주어진다. 모든 막대를 던지고 난 이후에 미네랄 모양을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 동굴의 크기 R과 C가 주어진다. (1 ≤ R,C ≤ 100)

다음 R개 줄에는 C개의 문자가 주어지며, '.'는 빈 칸, 'x'는 미네랄을 나타낸다.

다음 줄에는 막대를 던진 횟수 N이 주어진다. (1 ≤ N ≤ 100)

마지막 줄에는 막대를 던진 높이가 주어지며, 공백으로 구분되어져 있다. 모든 높이는 1과 R사이이며, 높이 1은 행렬의 가장 바닥, R은 가장 위를 의미한다. 첫 번째 막대는 왼쪽에서 오른쪽으로 던졌으며, 두 번째는 오른쪽에서 왼쪽으로, 이와 같은 식으로 번갈아가며 던진다.

공중에 떠 있는 미네랄 클러스터는 없으며, 두 개 또는 그 이상의 클러스터가 동시에 떨어지는 경우도 없다.

출력
입력 형식과 같은 형식으로 미네랄 모양을 출력한다.

풀이:
구현이 까다로운 DFS 탐색 문제입니다.

매번 막대가 미네랄을 없앨 때마다 두 개의 클러스터를 만들어야 합니다.
하나는 바닥에 붙어있는 클러스터, 나머지는 떨어지는 클러스터.
(처음엔 막대가 없앤 미네랄의 주변 클러스터에 대해 나눴는데, 미네랄이 연결되어 있지 않아도 바닥에 붙어있는 클러스터가 있을 수 있습니다.)

반례

9 8
........
...xxx..
.xxx....
.x.x.xxx
.x.x...x
.x.xxx.x
.x.....x
.x.....x
.xxx...x
1
7

정답

........
........
...xxx..
.xxx.xxx
.x.x...x
.x.x...x
.x.xxx.x
.x.....x
.xxx...x

두 개의 클러스터로 나눴다면, 떨어지는 클러스터에 대해 떨어지는 거리의 최소값을 구한 뒤 맨 아래쪽부터 해당 거리만큼 옮겨주면 됩니다.

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

int R, C;
char maps[101][101];
bool visit[101][101];
bool cluster_check[2];
char cluster[101][101][2];

int main(void) {
	FIO;

	cin >> R >> C;

	for (int i = 0; i < R; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < C; j++)
		{
			maps[i][j] = str[j];
		}
	}

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int h;
		int turn = i % 2;
		cin >> h;
		h = R - h;

		stack<pii> st;

		for (int j = 0; j < 101; j++)
		{
			for (int k = 0; k < 101; k++)
			{
				visit[j][k] = false;
				cluster[j][k][0] = '.';
				cluster[j][k][1] = '.';
			}
		}

		for (int j = 0; j < 2; j++)
		{
			cluster_check[j] = false;
		}

		pii mineral = make_pair(-1, -1);

		//왼쪽, 오른쪽
		if (turn == 0) {
			for (int j = 0; j < C; j++)
			{
				if (maps[h][j] == 'x') {
					mineral = make_pair(h, j);
					break;
				}
			}
		}
		else {
			for (int j = C - 1; j >= 0; j--)
			{
				if (maps[h][j] == 'x') {
					mineral = make_pair(h, j);
					break;
				}
			}
		}

		//막대가 아무것도 부수지 않았다면 continue
		if (mineral.first == -1)	continue;

		maps[mineral.first][mineral.second] = '.';

		int c_idx = -1;

		for (int j = 0; j < 4; j++)
			//먼저 미네랄 주변에 대해 클러스터를 나눔
		{
			int next_x = mineral.first + mv1[j];
			int next_y = mineral.second + mv2[j];

			if (next_x < 0 || next_y < 0 || next_x >= R || next_y >= C)	continue;
			if (maps[next_x][next_y] == 'x') {
				if (!visit[next_x][next_y]) {
					st.push(make_pair(next_x, next_y));
					c_idx++;
				}

				while (!st.empty()) {
					//클러스터 dfs
					int nowx = st.top().first;
					int nowy = st.top().second;
					st.pop();

					visit[nowx][nowy] = true;
					cluster[nowx][nowy][c_idx] = 'x';

					for (int k = 0; k < 4; k++)
					{
						int nextx = nowx + mv1[k];
						int nexty = nowy + mv2[k];

						if (nextx < 0 || nexty < 0 || nexty >= C)	continue;
						if (nextx >= R) {
							//바닥을 만남
							cluster_check[c_idx] = true;
						}
						else if (maps[nextx][nexty] == 'x' && !visit[nextx][nexty]) {
							st.push(make_pair(nextx, nexty));
						}
					}
				}
			}
		}

		for (int j = 0; j < 2; j++)
		{
			if (!cluster_check[j]) {
				//바닥을 안 만난 클러스터(떨어지는 클러스터)
				int minLeng = 200;

				//map에 있는 떨어지는 클러스터가 아닌 모든 클러스터를 체크함
				for (int k = 0; k < R; k++)
				{
					for (int l = 0; l < C; l++)
					{
						if (!visit[k][l] && maps[k][l] == 'x') {
							cluster[k][l][(j + 1) % 2] = 'x';
						}
					}
				}

				for (int k = 0; k < R; k++)
				{
					for (int l = 0; l < C; l++)
					{

						if (cluster[k][l][j] == 'x') {
							int ground = R - 1;

							for (int c = k + 1; c < R; c++)
							{
								if (cluster[c][l][(j + 1) % 2] == 'x') {
									ground = c - 1;
									break;
								}
							}

							minLeng = min(minLeng, ground - k);
							//떨어질 최소값 갱신
						}
					}
				}

				//클러스터의 맨 아래부터 옮겨줌
				for (int k = R - 1; k >= 0; k--)
				{
					for (int l = 0; l < C; l++)
					{
						if (cluster[k][l][j] == 'x') {
							maps[k][l] = '.';
							maps[k + minLeng][l] = 'x';
						}
					}
				}
			}
		}
	}

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cout << maps[i][j];
		}
		cout << "\n";
	}
}