/*
문제
여자친구와 함께 보드게임카페에 간 주언이는, 여러 보드게임을 하며 데이트를 즐겼다. 3시간 커플세트로 결제를 하려던 순간, 주언이는 가격표 옆에 쓰여 있는 새로운 이벤트를 보았다.

바로 “사장님과의 게임에서 이기면 무료, 지거나 비기면 5000원 추가 지불” 이벤트였다. 보드게임에 자신이 있는 주언이는 사장님에게 게임 룰을 물어보았고, 그 룰은 다음과 같았다.

각자 N장의 카드를 받는다. (N은 홀수다)
각자 카드를 1장씩 골라서 카드에 적힌 수의 크기를 비교한다. (각 카드에 적힌 수는 0이상, 100,000이하의 정수다)
더 작은 수가 적힌 카드를 낸 사람이 1점을 얻고, 승부에 사용된 카드는 버린다. (무승부의 경우, 둘 다 점수를 획득하지 못한다)
총 N번의 승부 후, (N+1)/2점 이상의 점수를 획득한 사람이 승리한다.
(N+1)/2점 이상의 점수를 획득한 사람이 없을 경우, 승자가 없는 것으로 게임이 끝난다.
주언이는 자신이 이길 확률이 조금이라도 있을 경우 게임을 하고자 한다.

사장님이 받은 카드에 적힌 수들과, 주언이가 받은 카드에 적힌 수들이 주어질 때, 주언이가 게임을 해도 되는지 확인하자.

입력
N값이 첫 번째 줄에 입력된다. (1 ≤ N < 100,000, N은 홀수)

주언이가 받은 카드 N장에 적힌 수들이 두 번째 줄에 입력된다.

사장님이 받은 카드 N장에 적힌 수들이 세 번째 줄에 입력된다.

출력
주언이가 이길 확률이 조금이라도 있을 경우 “YES” 라고 출력하고,주언이가 이길 확률이 존재하지 않을 경우 “NO”라고 출력한다.

풀이:
사장님이 가장 큰 수를 계속 내고, 주언이는 그 큰 수에 맞춰 가장 최적의 수를 내는 게 최선의 경우입니다.
두 카드들을 모두 우선순위 큐에 내림차순으로 정렬하여 뽑으며 점수를 카운트합니다.
*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include<queue>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>

int N;
priority_queue<int> ju;
priority_queue<int> sa;

int main(void) {
	FIO;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int n;
		cin >> n;
		ju.push(n);
	}
	for (int i = 0; i < N; i++)
	{
		int n;
		cin >> n;
		sa.push(n);
	}
	int score = 0;
	while(!sa.empty()) {
		int now_sa = sa.top();
		sa.pop();

		while (!ju.empty()&& ju.top() >= now_sa) {
			ju.pop();
		}
		if (!ju.empty()) {
			score++;
			ju.pop();
		}
	}
	

	if (score >= (N + 1) / 2)
		cout << "YES";
	else
		cout << "NO";
}