/*
문제
크기가 M×M인 격자 형태의 벌집이 있다. 이 벌집의 각 칸에는 여왕벌이 될 애벌레들이 한 마리씩 자라고 있다.

격자칸의 좌표계를 다음과 같이 설정한다. 제일 왼쪽 위 칸의 좌표는 (0,0)이다. 그 아래쪽 칸들의 좌표는 순서대로 (1,0), (2,0), ...등이다. 좌표가 (i,0)인 칸의 오른쪽 칸들의 좌표는 순서대로 (i, 1), (i,2), ... 등이다.

애벌레들은 매일 에너지를 모아서 정오(낮 12시) 에 한번 자라는데, 여기에 걸리는 시간은 매우 짧아서 무시할 수 있다. 첫날 아침 모든 애벌레들의 크기는 1이고, 이러한 과정을 N일 동안 반복한다.

각 애벌레가 자라서 크기가 커지는 정도는 하루에 +0, +1, +2의 세 가지 중 하나이다. 더하기(+) 기호는 앞으로 생략한다. 구체적으로 각 애벌레가 자라는 정도를 결정하는 규칙은 다음과 같다.

제일 왼쪽 열과, 제일 위쪽 행의 애벌레들은 자신이 자라는 정도를 스스로 결정한다. 이들은 입력으로 주어질 것이다. 애벌레들이 자라는 정도를 왼쪽 제일 아래 칸에서 시작하여 위쪽으로 가면서 읽고, 제일 위쪽 칸에 도착하면 오른쪽으로 가면서 행의 끝까지 읽었다고 하자. 모든 입력에서 이렇게 읽은 값들은 감소하지 않는 형태이다.
나머지 애벌레들은 자신의 왼쪽(L), 왼쪽 위(D), 위쪽(U)의 애벌레들이 다 자란 다음, 그 날 가장 많이 자란 애벌레가 자란 만큼 자신도 자란다.
M = 4, N = 2인 예를 하나 들어보자. 다음은 각 격자에 있는 애벌레의 첫날 아침의 크기이다.

1	1	1	1
1	1	1	1
1	1	1	1
1	1	1	1
2일 동안 제일 왼쪽 열과 제일 위쪽 행에 있는 7마리의 애벌레들이 자라는 정도를 왼쪽 제일 아래칸에서 시작하여 위쪽으로 가면서 읽고, 제일 위쪽 칸에 도착하면 오른쪽으로 가면서 행의 끝까지 읽었을 때, 다음과 같다고 하자.

1일: 0, 0, 1, 1, 1, 2, 2
2일: 1, 1, 1, 1, 1, 1, 2
첫날 저녁에 애벌레들은 아래와 같은 크기를 가진다. 예를 들어, 좌표 (1,1)의 애벌레는 왼쪽 애벌레의 크기가 1만큼 자랐고, 왼쪽 위의 애벌레가 1만큼 자랐고, 위쪽 애벌레도 1만큼 자랐으므로, 자신도 1만큼을 자란다. 또, 좌표 (3,3)의 애벌레는 규칙을 따르면 2만큼 자람을 알 수 있다.

2	2	3	3
2	2	3	3
1	2	3	3
1	2	3	3
둘째 날이 지났을 때는 동일한 과정에 따라 다음과 같이 됨을 확인할 수 있다.

3	3	4	5
3	3	4	5
2	3	4	5
2	3	4	5
격자칸의 크기, 날자 수, 날자별 제일 왼쪽 열과 제일 위쪽 행의 애벌레들이 자라는 정도를 입력으로 받아 마지막 날 저녁의 애벌레들의 크기를 출력하는 프로그램을 작성하라

입력
입력의 첫 줄에는 격자칸의 가로와 세로 크기 M(2 ≤ M ≤ 700)과 날짜 수 N(1 ≤ N ≤ 1,000,000)이 자연수로 주어진다. 첫날 아침의 애벌레 크기는 모두 1이므로 입력에 주어지지 않는다. 다음 N개의 줄에는 첫날부터 순서대로 제일 왼쪽 열과 제일 위쪽 행의 애벌레들이 자라는 정도가 다음의 형식으로 주어진다. 본문에서 보인 것과 같이, 자라는 크기를 제일 왼쪽 아래 칸에서 시작해서 위쪽으로 올라가서 제일 위쪽에 도착하면 오른쪽으로 이동하며 읽었다고 하자. 이 값들은 감소하지 않는다. 따라서, 이 수열을 처음부터 읽었을 때 0의 개수, 1의 개수, 2의 개수를 순서대로 입력에 준다. 하루에 대해서 이 세 개수들의 합은 2M-1임이 자명하다. 세 값들 중에 0이 있을 수 있다

출력
M개의 줄에 각각 M개의 자연수를 출력한다. 이는 각 애벌레의 마지막 날 저녁의 크기를 첫 행부터, 각 행에서는 왼쪽부터 제시한 것이다. (본문의 예와 동일한 형태이다.)

풀이:
문제를 꼼꼼히 읽어봐야 하는 문제이다.
주어지는 왼쪽, 위 배열은 항상 증가하므로 나머지 애벌레들의 크기는 맨 위 애벌레의 크기와 항상 같다는 걸 알 수 있다.
(위 애벌레의 증가율은 항상 왼쪽, 왼쪽 위 애벌레 이상이므로)

문제는 왼쪽, 위쪽 애벌레의 최종 크기를 구하는 거였는데
최대가 1400 * 100만이라 각 쿼리마다 0, 1, 2 를 카운트해주면 시간초과가 날 것 같아
lazy propagate 구간합 업데이트를 이용했다.
0, 1, 2의 개수에 대해 각각 세그먼트 트리를 만들어 해당 구간의 개수를 카운트해주고
왼쪽, 위쪽 애벌레에 더해주었다.
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

int n, m;
int dp[701][701];
int lazy[10000][3];
int tree[10000][3];

void propagate(int now, int s, int e, int num) {
	//자식 노드들에 lazy값을 전파
	if (lazy[now] != 0) {
		
		if (s != e) {
			lazy[now * 2][num] += lazy[now][num];
			lazy[now * 2 + 1][num] += lazy[now][num];
		}

		tree[now][num] += (e - s + 1) * lazy[now][num];
		lazy[now][num] = 0;
	}
}

void update(int now, int s, int e, int l, int r, int num) {
	//구간 업데이트
	propagate(now, s, e, num);

	if (r < s || l > e)	return;

	if (l <= s && r >= e) {
		lazy[now][num]++;
		propagate(now, s, e, num);
		return;
	}

	update(now * 2, s, (s + e) / 2, l, r, num);
	update(now * 2 + 1, (s + e) / 2 + 1, e, l, r, num);

	tree[now][num] = tree[now * 2][num] + tree[now * 2 + 1][num];
}

int get(int now, int s, int e, int l, int r, int num) {
	propagate(now, s, e, num);

	if (r < s || l > e)	return 0;

	if (l <= s && r >= e) {
		propagate(now, s, e, num);
		return tree[now][num];
	}

	return get(now * 2, s, (s + e) / 2, l, r, num) + get(now * 2 + 1, (s + e) / 2 + 1, e, l, r, num);
}

int main(void) {
	FIO;

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int p = 0;

		for (int j = 0; j < 3; j++)
		{
			int c;
			cin >> c;

			if (c == 0)	continue;
			//개수가 0이면 업데이트할 게 없으므로 continue

			update(1, 1, 2 * n - 1, p + 1, p + c, j);
			//개수만큼 구간 업데이트

			p += c;
		}
	}

	int ptr = 1;

	for (int i = n - 1; i >= 0; i--)
	{
		dp[i][0] = 1;

		for (int j = 0; j < 3; j++)
		{
			dp[i][0] += get(1, 1, 2 * n - 1, ptr, ptr, j) * j;
			//왼쪽 애벌레 최종 크기
		}
		ptr++;
	}

	for (int i = 1; i < n; i++)
	{
		dp[0][i] = 1;

		for (int j = 0; j < 3; j++)
		{
			dp[0][i] += get(1, 1, 2 * n - 1, ptr, ptr, j) * j;
			//위쪽 애벌레 최종 크기
			
		}
		ptr++;
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			dp[i][j] = dp[i - 1][j];
			//나머지 애벌레의 크기 == 위 애벌레의 크기
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}
}