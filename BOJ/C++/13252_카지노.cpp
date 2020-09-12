/*
문제
효빈이는 친구들과 카지노에 방문했다. 효빈이와 함께한 그룹은 총 N명으로 이루어져 있다.

카지노에서 할 게임은 M개의 영역으로 나누어져있는 지도에서 진행된다. 게임이 시작될 때, 각 사람에게는 칩이 1개씩 주어진다.

게임은 총 K개의 라운드로 이루어져 있고, 아래와 같이 진행된다.

각 플레이어는 M개의 영역 중 하나에 칩을 놓는다.
딜러가 M개의 영역 중에 하나를 랜덤으로 고른다.
딜러가 고른 영역에 칩을 놓은 사람은 게임에서 제외된다.
K개의 라운드에서 게임에서 제외되지 않으면 게임을 승리한 것이다.

효빈이와 친구들은 적어도 한 사람이 게임을 승리할 확률을 최대로 하려고 한다.

N, M, K가 주어졌을 때, 효빈이와 친구들이 게임을 최적의 방법으로 진행했을 때, 적어도 한 사람이 게임을 승리할 확률을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N, M, K가 주어진다. (1 ≤ N ≤ 1012, 1 ≤ M, K ≤ 50)

출력
첫째 줄에 적어도 한 사람이 게임을 승리할 확률을 출력한다. 정답과의 절대/상대 오차는 10-3까지 허용한다.

풀이:
그리디 + dp 메모이제이션 문제이다.
문제에서 최적의 방법이란 매 라운드마다 다음 라운드로 최대한의 칩을 보내는 것이다.
따라서 현재 남은 칩과, M 에 의해 칩의 배치가 결정된다.

1. 칩 < M  --> 칩을 한 개씩만 놓는 게 최선이다.
2. 칩 % M == 0  --> 칩을 (칩 / M) 개씩 모든 M 자리에 놓는 게 최선이다.
3. 칩 % M != 0  --> 칩을 (칩 / M) 개씩 모든 M 자리에 놓아도 나머지만큼의 칩이 남는다. 남는 칩들은 하나씩 각기 다른 자리에 놓는다.

1 번의 확률은 딜러가 칩을 집을 확률 = 칩의 개수 / M + 칩을 집지 않을 확률 = (M - 칩의 개수) / M
2 번의 확률은 모든 자리의 칩의 개수가 같으므로 1이다.
3 번의 확률은 딜러가 (칩 / M) 개의 칩을 집을 경우 = (M - 나머지) / M + (칩 / M + 1) 개의 칩을 집을 경우 = 나머지 / M

위와 같이 현재 라운드의 칩의 개수에 따라 재귀 함수를 진행하면 된다.
하지만 매 라운드마다 최대 2개의 분기가 일어나므로 2^50 의 시간 초과가 난다.

1, 2, 3 번을 나누는 기준은 (칩 % M) 임을 알 수 있다.
따라서 각 라운드마다 (칩 % M) 인 상태를 메모이제이션 해 주어 시간을 줄일 수 있었다.
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
int mv1[4] = { 0, 0, 1, -1 };
int mv2[4] = { 1, -1, 0, 0 };
int mv_all1[8] = { 0, 1, 0, -1, -1, -1, 1, 1 };
int mv_all2[8] = { 1, 0, -1, 0 , -1, 1, -1, 1 };

ll n, m, k;
double dm;
double dp[51][51];

double recul(ll chip, ll round) {

	if (round >= k) {
		if (chip > 0)	return 1;
		else return 0;
	}

	if (chip == 0)	return 0;

	ll remain = chip % m;

	double& ret = dp[remain][round];
	if (ret != -1)	return ret;
	ret = 0;

	if (m > chip) {
		ret += (recul(chip - 1, round + 1) * ((double)chip / dm));
		ret += (recul(chip, round + 1) * (dm - (double)chip) / dm);
	}
	else {
		if (chip % m == 0) {
			ret += recul(chip - (chip / m), round + 1);
		}
		else {
			ret += (recul(chip - (chip / m) , round + 1) * ((dm - (double)remain) / dm));
			ret += (recul(chip - (chip / m) - 1, round + 1) * ((double)remain / dm));
		}
	}

	return ret;
}

int main(void) {
	FIO;

	cin >> n >> m >> k;
	dm = (double)m;

	fill(&dp[0][0], &dp[50][51], -1);

	cout.precision(10);
	cout << recul(n, 0);
}