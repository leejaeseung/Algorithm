/*
문제
70세 박종수 할아버지는 매일 매일 약 반알을 먹는다. 손녀 선영이는 종수 할아버지에게 약이 N개 담긴 병을 선물로 주었다.

첫째 날에 종수는 병에서 약 하나를 꺼낸다. 그 다음, 그 약을 반으로 쪼개서 한 조각은 먹고, 다른 조각은 다시 병에 넣는다.

다음 날부터 종수는 병에서 약을 하나 꺼낸다. (약은 한 조각 전체 일 수도 있고, 쪼갠 반 조각 일 수도 있다) 반 조각이라면 그 약을 먹고, 아니라면 반을 쪼개서 한 조각을 먹고, 다른 조각은 다시 병에 넣는다.

종수는 손녀에게 한 조각을 꺼낸 날에는 W를, 반 조각을 꺼낸 날에는 H 보낸다. 손녀는 할아버지에게 받은 문자를 종이에 기록해 놓는다. 총 2N일이 지나면 길이가 2N인 문자열이 만들어지게 된다. 이때, 가능한 서로 다른 문자열의 개수는 총 몇 개일까?

입력
입력은 최대 1000개의 테스트 케이스로 이루어져 있다. 각 테스트 케이스는 한 줄이며, 병에 들어있는 약의 개수 N ≤ 30 가 주어진다.

입력의 마지막 줄에는 0이 하나 주어진다.

출력
각 테스트 케이스에 대해서 가능한 문자열의 개수를 출력한다.

풀이:
dfs + 메모이제이션 문제였다.
알약이 모두 반개만 남는 경우(one이 0개일 때) 이후의 경우의 수는 모두 S로 같기 때문에 한개의 개수를 줄여나가야 한다.
한개짜릴 빼고, 반개를 넣어가며 dfs를 진행하는데, 반개짜리만 빼는 경우도 추가한다.

한개짜리와 반개짜리의 개수가 같은 상황이면 메모이제이션을 이용해 걸러줄 수 있다.
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

ll dp[31][31];

ll dfs(int one, int half) {

	if (one == 0)	return 1;

	ll &ret = dp[one][half];
	if (ret > -1)	return ret;
	//한개 짜리와 반개 짜리의 개수가 같을 때

	ret = dfs(one - 1, half + 1);
	//한개를 빼고, 반개를 넣음

	if (half > 0)
		ret += dfs(one, half - 1);
		//반개만 뺌

	return ret;
}

int main(void) {
	FIO;

	while (true) {
		int n;
		cin >> n;

		if (n == 0)	break;

		fill(&dp[0][0], &dp[30][31], -1);

		cout << dfs(n, 0) << "\n";
	}
}