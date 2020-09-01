/*
문제
1학년은 노는 게 남는 거란 선배의 말을 철석같이 믿고, 전공 과목은 다 수강철회하고 교양 과목은 다 F 받는 방탕한 1학년을 보냈던 태우는 이제 와서 자신의 행동을 후회하고 있습니다. 졸업 전에 채워야 할 학점이 너무 많기 때문입니다. 졸업 필수 학점을 채우려면 전공 과목 N 개 중 K 개 이상을 수강해야 합니다. 그런데 각 과목은 해당 과목의 선수과목을 미리 수강했어야만 수강할 수 있으며, 각 학기마다 모든 과목이 개설되는 것이 아니기 때문에 문제가 복잡해졌습니다. 어떻게 해야 최소 학기에 졸업을 할 수 있을까요?

각 과목의 정보와 앞으로 M 학기 동안 개설될 과목의 목록이 주어질 때, 태우가 최소 몇 학기를 다녀야 졸업할 수 있는지 계산하는 프로그램을 작성하세요. 한 과목도 수강하지 않는 학기는 휴학한 것으로 하며, 다닌 학기 수에 포함되지 않습니다.

입력
입력의 첫 줄에는 테스트 케이스의 수 C (C <= 50) 가 주어집니다. 각 테스트 케이스의 첫 줄에는 전공 과목의 수 N (1 <= N <= 12), 들어야 할 과목의 수 K (0 <= K <= N), 학기의 수 M (1 <= M <= 10) 과 태우가 한 학기에 최대로 들을 수 있는 과목의 수 L (1 <= L <= 10)이 주어집니다. 각 과목에는 0부터 N-1 까지의 번호가 매겨져 있습니다.

그 후 N 줄에 0번 과목부터 순서대로 각 과목의 정보가 주어집니다. 이 줄에는 해당 과목의 선수 과목의 수 Ri (0 <= Ri <= N-1) 가 처음 주어지고, 그 후 Ri 개의 정수로 선수 과목의 번호가 주어집니다.

그 후 M 줄에는 이번 학기부터 순서대로 각 학기의 정보가 주어집니다. 각 줄에는 해당 학기에 개설되는 과목의 숫자 Ci (1 <= Ci <= 10) 가 주어지고, 그 후 Ci 개의 정수로 개설되는 과목의 번호들이 주어집니다.

출력
각 테스트 케이스마다 한 줄에 태우가 다녀야 할 최소 학기 수를 출력합니다. M 학기 내에 졸업할 수 없는 경우 IMPOSSIBLE을 출력합니다.

풀이:
비트마스크를 이용한 브루트 포스 + 메모이제이션 문제이다.

각 학기마다 모든 가능한 조합에 대해 수강을 해본다.
memo[학기][수강한 bitmask] 로 메모이제이션을 수행한다.

수강했을 때와, 아무것도 수강하지 않았을 때를 나눠 생각한다.
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
#define MOD 100007
int mv1[4] = { 0, 0, 1, -1 };
int mv2[4] = { 1, -1, 0, 0 };
int mv_all1[8] = { 0, 1, 0, -1, -1, -1, 1, 1 };
int mv_all2[8] = { 1, 0, -1, 0 , -1, 1, -1, 1 };

int cs[12];
int semester[10];
int memo[10][1 << 12];
int t, n, k, m, l;

int brute(int nowSem, int nowBit, int nowCnt) {

	if (nowCnt >= k)	return 0;

	if (nowSem >= m)	return IMAX;

	int& ret = memo[nowSem][nowBit];

	if (ret != -1)	return ret;

	ret = IMAX;

	for (int i = semester[nowSem]; i > 0; i = ((i - 1) & semester[nowSem]))
	{
		int cnt = 0;
		int cls_cnt = 0;
		int bit = 0;

		for (int j = 1; j <= i; j = (j << 1))
		{	
			if ((j & i) != 0 && (j & nowBit) == 0 && (cs[cls_cnt] & nowBit) == cs[cls_cnt]) {
				cnt++;
				bit |= j;
			}

			cls_cnt++;
		}

		if (cnt > l || cnt == 0)	continue;

		ret = min(ret, brute(nowSem + 1, nowBit | bit, nowCnt + cnt) + 1);
	}

	ret = min(ret, brute(nowSem + 1, nowBit, nowCnt));

	return ret;
}

int main(void) {
	FIO;

	cin >> t;

	while (t--) {
		cin >> n >> k >> m >> l;

		memset(cs, 0, sizeof(cs));
		memset(semester, 0, sizeof(semester));
		fill(&memo[0][0], &memo[9][1 << 12], -1);

		for (int i = 0; i < n; i++)
		{
			int r;
			cin >> r;

			for (int j = 0; j < r; j++)
			{
				int prev;
				cin >> prev;

				cs[i] = cs[i] | (1 << prev);
			}
		}

		for (int i = 0; i < m; i++)
		{
			int c;
			cin >> c;

			for (int j = 0; j < c; j++)
			{
				int open;
				cin >> open;

				semester[i] = semester[i] | (1 << open);
			}
		}

		int ans = brute(0, 0, 0);

		if (ans == IMAX)
			cout << "IMPOSSIBLE\n";
		else
			cout << ans << "\n";
	}
}