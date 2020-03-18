/*
문제
0점에서 시작해 매 턴 점수를 획득해 나가는 게임이 있다. 각 턴에서 플레이어가 게임 에서 승리하면 a점을 얻고, 지면 b점을 얻는다. 점수의 총합이 n점 이상이면 게임이 끝나게 된다.

포스텍의 한 학생이 이 게임을 해킹하는 데 성공했다. 그래서 각 턴에서 승리할지, 질지 자유롭게 결정할 수 있다. 심지어는 원하는 턴에서 점수를 a점이나 b점 올리는 대신 두 배로 바꾸는 것도 가능하다. 예를 들면 a가 3이고 b가 2이며 현재 점수가 10이라고 할 때, 다음 턴의 점수로 가능한 것에는 12, 13, 또는 20이 있다. 하지만 만약 학생이 n+a점 이상의 점수로 게임을 끝내게 되거나, 각 턴이 끝났을 때 점수를 두 배로 올린 턴이 전체 턴의 10%를 초과하면 학생은 게임 운영진의 의심을 받게 되고, 게임에서 퇴출당하게 된다.

이 학생이 운영진의 의심을 받지 않고 게임을 끝내는 데 필요한 최소한의 턴을 구하라.

입력
n, a, b 세 개의 정수가 띄어쓰기를 사이에 두고 주어진다. (1 ≤ n ≤ 500, 1 ≤ b ≤ a ≤ 100)

출력
이 학생이 운영진의 의심을 받지 않고 게임을 끝내는 데 필요한 최소한의 턴을 출력한다.

풀이:
visit 방문 배열을 [현재 수][두 배한 횟수][턴 수] 로 정의한다.
매번 제약 조건을 확인하며 탐색한다.
*/
#include<iostream>
#include<queue>
#include<utility>
#include<math.h>
using namespace std;

int n, a, b;
bool visit[2000][10][2000];
int ans = 1000000000;

int BFS() {
	queue<pair<pair<int, int>, int> > q;
	q.push(make_pair(make_pair(0, 0), 0));
	visit[0][0][0] = true;
	visit[0][1][0] = true;

	while (!q.empty()) {
		int now = q.front().first.first;
		int cheat = q.front().first.second;
		int now_cnt = q.front().second;
		q.pop();
		if (cheat * 10 > now_cnt)	continue;
		if (now >= n + a)	continue;

		if (now >= n) {
			ans = min(ans, now_cnt);
		}

		if (!visit[now + a][cheat][now_cnt + 1]) {
			visit[now + a][cheat][now_cnt + 1] = true;
			q.push(make_pair(make_pair(now + a, cheat), now_cnt + 1));
		}
		if (!visit[now + b][cheat][now_cnt + 1]) {
			visit[now + b][cheat][now_cnt + 1] = true;
			q.push(make_pair(make_pair(now + b, cheat), now_cnt + 1));
		}
		if (!visit[now * 2][cheat + 1][now_cnt + 1]) {
			visit[now * 2][cheat + 1][now_cnt + 1] = true;
			q.push(make_pair(make_pair(now * 2, cheat + 1), now_cnt + 1));
		}
	}
	return ans;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> a >> b;

	cout << BFS();
}