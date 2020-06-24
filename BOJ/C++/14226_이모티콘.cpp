/*
문제
영선이는 매우 기쁘기 때문에, 효빈이에게 스마일 이모티콘을 S개 보내려고 한다.

영선이는 이미 화면에 이모티콘 1개를 입력했다. 이제, 다음과 같은 3가지 연산만 사용해서 이모티콘을 S개 만들어 보려고 한다.

화면에 있는 이모티콘을 모두 복사해서 클립보드에 저장한다.
클립보드에 있는 모든 이모티콘을 화면에 붙여넣기 한다.
화면에 있는 이모티콘 중 하나를 삭제한다.
모든 연산은 1초가 걸린다. 또, 클립보드에 이모티콘을 복사하면 이전에 클립보드에 있던 내용은 덮어쓰기가 된다. 클립보드가 비어있는 상태에는 붙여넣기를 할 수 없으며, 일부만 클립보드에 복사할 수는 없다. 또한, 클립보드에 있는 이모티콘 중 일부를 삭제할 수 없다. 화면에 이모티콘을 붙여넣기 하면, 클립보드에 있는 이모티콘의 개수가 화면에 추가된다.

영선이가 S개의 이모티콘을 화면에 만드는데 걸리는 시간의 최솟값을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 S (2 ≤ S ≤ 1000) 가 주어진다.

출력
첫째 줄에 이모티콘을 S개 만들기 위해 필요한 시간의 최솟값을 출력한다.

풀이:
bfs로 풀이했습니다.
(현재 값, 클립보드 복사값) 으로 방문 체크를 해가며 bfs 탐색하면 됩니다.
*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
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

int s;
bool visit[5000][5000];
int cnt[10000];

int main(void) {
	FIO;

	cin >> s;

	queue<pair<pii, int>> q;
	q.push(make_pair(make_pair(1, 0), 0));

	int ans = IMAX;

	while (!q.empty()) {
		int now = q.front().first.first;
		int now_cnt = q.front().first.second;
		int clip = q.front().second;
		q.pop();

		if (ans <= now_cnt)	continue;
		if(now == s)
			ans = min(ans, now_cnt);

		if (now < 1)	continue;
		if (visit[now][clip])	continue;
		visit[now][clip] = true;

		//1번 연산
		q.push(make_pair(make_pair(now + clip, now_cnt + 1), clip));
		//2번 연산
		q.push(make_pair(make_pair(now, now_cnt + 1), now));
		//3번 연산
		q.push(make_pair(make_pair(now - 1, now_cnt + 1), clip));
	}

	cout << ans;
}