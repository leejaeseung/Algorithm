/*
문제
어느 날, 네오는 길을 걷다가 격자판 하나를 주웠다. 그 격자판은 N 행 M 열로, 각 격자는 흰색 또는 검은색으로 칠해져 있다.

네오는 이 격자판에는 분명 엄청난 비밀이 숨겨져 있을 것이라고 생각해 나중에 해독을 시도해 보기로 하였다. 아래 그림은 격자판 상태의 예시이다.


네오가 잠시 외출한 사이, 프로도는 네오의 격자판을 이리저리 살펴보았다. 얼마 뒤, 하나의 격자를 누르게 되면 자신을 포함해 그 격자와 연결된 모든 칸들의 색이 반전된다는 사실을 관찰할 수 있었다. 여기서, 두 격자가 연결되었다는 것은 두 격자 사이를 서로 같은 색이면서 변을 공유하는 격자들로만 이동하여 오갈 수 있다는 것을 뜻한다. 집으로 돌아온 네오는 프로도가 격자판의 상태를 바꿔버렸다는 것을 알고 좌절했다. 하지만 최종 상태를 알고 있기 때문에, 초기 상태를 추측할 수 있을 것이라는 희망을 가지기로 했다.

프로도는 격자판을 0번 이상 눌렀다(아직 한 번도 누르지 않은 상태일 수도 있다). 현재 각 격자의 색깔이 주어졌을 때, 격자판의 초기 상태로 가능한 경우의 수를 1,000,000,007(109 + 7)로 나눈 나머지를 구하여라. 두 격자판의 상태가 다르다는 것은, 같은 위치의 격자의 색이 다른 경우가 존재할 때로 정의한다.

입력
첫 줄에 격자판의 행의 수 N 과 열의 수 M 이 주어진다. (1 ≤ N, M ≤ 2,000)

둘째 줄부터 N 개의 줄에 걸쳐 현재 각 격자의 색을 나타내는 문자열이 주어진다.

N 개의 줄 중에서 i 번째 줄의 j 번째 문자는 i 행 j 열 격자의 색을 나타내며, 'B'인 경우 검은색, 'W'인 경우 흰색임을 나타낸다.

출력
첫 줄에 격자의 초기 상태로 가능한 경우의 수를 1,000,000,007(109 + 7)로 나눈 나머지를 출력한다.

풀이:
규칙을 찾는 게 까다로웠던 문제.

어떤 위치에서 인접한 블록이 다른 색이라면 해당 위치는 초기 상태이므로 바꿀 수 없다.
결국 인접한 모든 칸이 같은 색인 블록의 수만큼 2의 거듭 제곱을 한 게 답이다.
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

int n, m;
int cnt = 0;
int maps[2002][2002];
ll mod = 1000000007;

int main(void) {
	FIO;

	cin >> n >> m;

	for (int i = 0; i <= n + 1; i++)
	{
		for (int j = 0; j <= m + 1; j++)
		{
			maps[i][j] = -1;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		string str;
		cin >> str;
		for (int j = 1; j <= m; j++)
		{
			if (str[j - 1] == 'W')
				maps[i][j] = 0;
			else
				maps[i][j] = 1;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			int nowColor = maps[i][j];

			for (int k = 0; k < 4; k++)
			{
				int nx = i + mv1[k];
				int ny = j + mv2[k];

				if (maps[nx][ny] == (nowColor + 1) % 2) {
					cnt++;
					break;
				}
			}
		}
	}

	ll iter = n * m - cnt;
	ll ans = 1;
	
	for (int i = 0; i < iter; i++)
	{
		ans = ((ans % mod) * 2) % mod;
	}

	cout << ans;
}