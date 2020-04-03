/*
문제
정수 A를 B로 바꾸려고 한다. 가능한 연산은 다음과 같은 두 가지이다.

2를 곱한다.
1을 수의 가장 오른쪽에 추가한다.
A를 B로 바꾸는데 필요한 연산의 최솟값을 구해보자.

입력
첫째 줄에 A, B (1 ≤ A < B ≤ 109)가 주어진다.

출력
A를 B로 바꾸는데 필요한 연산의 최솟값에 1을 더한 값을 출력한다. 만들 수 없는 경우에는 -1을 출력한다.

풀이:
정말 정직하게 완전탐색을 했더니 풀린 문제였습니다.
A부터 *2 혹은 *10 + 1 을 해주면서 B와 같아질 때까지 탐색합니다.

B보다 커지는 경우만 걸러주면 됩니다.
*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<vector>
#include<queue>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>

long long A, B;
int ans = 100000000;

void recul(long long now, int cnt) {
	if (now > B)
		return;
	if (now == B) {
		ans = min(ans, cnt + 1);
	}

	recul(now * 2, cnt + 1);
	recul(now * 10 + 1, cnt + 1);
}

int main(void) {
	FIO;

	cin >> A >> B;

	recul(A, 0);

	if (ans == 100000000)
		cout << "-1";
	else
		cout << ans;
}