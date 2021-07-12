/*
문제
상덕이는 언덕 위에 있는 마을의 우체국에 직업을 얻었다. 마을은 N×N 행렬로 나타낼 수 있다. 행렬로 나뉘어진 각 지역은 우체국은 'P', 집은 'K', 목초지는 '.' 중 하나로 나타낼 수 있다. 또, 각 지역의 고도도 알고 있다.

매일 아침 상덕이는 마을의 모든 집에 우편을 배달해야 한다. 배달은 마을에 하나밖에 없는 우체국 'P'가 있는 곳에서 시작한다. 상덕이는 현재 있는 칸과 수평, 수직, 대각선으로 인접한 칸으로 이동할 수 있다. 마지막 편지를 배달하고 난 이후에는 다시 우체국으로 돌아와야 한다.

상덕이는 이렇게 매일 아침 배달을 하는 것이 얼마나 힘든지 궁금해졌다. 상덕이가 배달하면서 방문한 칸 중 가장 높은 곳과 낮은 곳의 고도 차이를 피로도라고 하자. 이때, 가장 작은 피로도로 모든 집에 배달을 하려면 어떻게 해야 하는지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N이 주어진다. (2 ≤ N ≤ 50)

다음 N개 줄에는 마을을 나타내는 행렬이 주어진다. 'P'는 한 번만 주어지며, 'K'는 적어도 한 번 주어진다.

다음 N개 줄에는 행렬로 나뉘어진 지역의 고도가 행렬 형태로 주어진다. 고도는 1,000,000보다 작거나 같은 자연수이다.

출력
첫째 줄에 가장 작은 피로도를 출력한다.

풀이:
투 포인터와 BFS 사용해 풀이했다.
모든 고도를 중복을 제거해 set으로 정렬하고, 상덕이가 갈 수 있는 고도를 left ~ right 투 포인터로 둔다.
포인터를 옮겨가며 BFS로 모든 집을 갈 수 있는지 조하사고, 갈 수 있다면 최소 고도 차이를 갱신하면 된다.
*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<regex>
#include<set>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define pic pair<int, char>
#define ll long long
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vii vector<pii>
#define IMAX 2147483647
#define LMAX 1000000000000500000
#define DMAX 0xFFFFFFFFFFFFF
int mv1[8] = { 0, 1, -1, 0, -1, -1, 1, 1 };
int mv2[8] = { 1, 0, 0, -1, -1, 1, -1, 1 };

int n;
int sx, sy;
bool town[51][51];
int height[51][51];
bool visit[51][51];
int homeCnt = 0;

bool bfs(int s, int e) {
	if (height[sx][sy] < s || height[sx][sy] > e)	return false;

	queue<pii> q;
	fill(&visit[0][0], &visit[50][50], false);

	visit[sx][sy] = true;
	q.push({sx, sy});

	int cnt = 0;

	while (!q.empty()) {
		pii now = q.front();
		q.pop();

		for (int i = 0; i < 8; i++)
		{
			int nx = now.first + mv1[i];
			int ny = now.second + mv2[i];
			
			if (nx < 0 || nx >= n || ny < 0 || ny >= n)	continue;

			if (height[nx][ny] >= s && height[nx][ny] <= e && !visit[nx][ny]) {
				visit[nx][ny] = true;

				if (town[nx][ny]) {

					cnt++;

					if (cnt == homeCnt)	return true;
				}

				q.push( {nx, ny} );
			}
		}
	}

	return false;
}

int main(void) {
	FIO;

	cin >> n;

	set<int> hset;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < n; j++)
		{
			if (str[j] == 'P') {
				sx = i;
				sy = j;
				town[i][j] = true;
			}
			else if (str[j] == 'K') {
				town[i][j] = true;
				homeCnt++;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> height[i][j];
			hset.insert(height[i][j]);
		}
	}

	auto l = hset.begin();
	auto r = hset.begin();

	int ans = IMAX;

	while (r != hset.end()) {
		
		while (*l <= *r) {
			
			if (bfs(*l, *r)) {
				ans = min(ans, *r - *l);

				if (l == r)	break;
				l++;
			}
			else {
				break;
			}
		}
		r++;
	}

	cout << ans;
}