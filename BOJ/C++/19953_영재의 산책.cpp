/*
문제
영재는 알고리즘 문제를 푸는 것을 좋아한다. 하지만 잘 풀지는 못하는 영재는 집중이 되지 않을 때 산책을 한다. 오늘도 집중이 되지 않아 영재는 동네를 산책한다. 영재의 동네는 2차원 좌표로 이루어져 있다.

아무 규칙 없이 걷는 것은 흥미롭지 않다고 느낀 영재는 일정한 규칙을 갖고 걷기로 하였다.

만약 t초에 v의 속력으로 걷는다면 1초 동안 v의 속력으로 걷는다. 그리고 t+1초가 된 순간 오른쪽으로 90도 회전한 후 (v×m)%10의 속력으로 걷는다. 초기 속력 v0, m, 총 산책 시간 t가 주어졌을 때, 영제의 최종 위치를 출력하여라. 영재의 처음 위치는 (0, 0)이고, 처음 방향은 북쪽이다.

북쪽은 y좌표가 커지는 방향이고, 동쪽은 x좌표가 커지는 방향이다.

입력
초기 속력 v0, m, 총 산책 시간 t가 주어진다.

출력
산책이 끝난 후 영재의 위치를 출력하여라.

제한
1 ≤ v0 ≤ 1,000
1 ≤ m ≤ 1,000
1 ≤ t ≤ 1,000,000,000

풀이:
t 가 10억이므로 매 초마다 이동해주면 시간 초과가 날 수 밖에 없다.
(v * m) % 10 의 규칙을 활용해야 한다.

여러 수를 대입해 본 결과 v, m 이 어떤 조합이던 간에 결과 값은 4개의 패턴만을 가진다.
v = 1, m = 2 일 때 -> 2, 4, 8, 6
v = 123, m = 127 일 때 -> 1, 7, 9, 3

즉, 맨 처음 북쪽으로의 이동을 제외하면 다음 이동부터는 동, 서, 남, 북 네 방향으로의 이동 거리가 일정하다는 뜻이다.
처음 북쪽으로 이동한 뒤 그 지점을 시작점으로 잡고, 동, 서, 남, 북으로 각각 몇 번 갈 수 있는지 구한 뒤
이동 거리만큼 계산해주면 된다.
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
int mv1[4] = { 0, 1, 0, -1 };
int mv2[4] = { 1, 0, -1, 0 };
int mv_all1[8] = { 0, 1, 0, -1, -1, -1, 1, 1 };
int mv_all2[8] = { 1, 0, -1, 0 , -1, 1, -1, 1 };

int v, m, t;
int dv[4];
int cnt[4];

int main(void) {
	FIO;

	cin >> v >> m >> t;

	int num = (v * m) % 10;

	for (int i = 0; i < 4; i++)
	{
		dv[i] = num;
		num = (num * m) % 10;
	}

	int x = 0, y = v;
	t--;

	for (int i = 0; i < 4; i++)
	{
		cnt[i] = (t - 1) / 4;
	}

	for (int i = 0; i <= (t - 1) % 4; i++)
	{
		cnt[i]++;
	}

	x += dv[0] * cnt[0] - dv[2] * cnt[2];
	y += dv[3] * cnt[3] - dv[1] * cnt[1];
	
	cout << x << " " << y;
}