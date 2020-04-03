/*
문제
근우와 명우는 재미있는 카드 게임을 하고 있다. N개의 카드가 일렬로 놓여 있다. 각 카드에는 점수가 적혀있다. 근우부터 시작하여 번갈아가면서 턴이 진행되는데 한 턴에는 가장 왼쪽에 있는 카드나 가장 오른쪽에 있는 카드를 가져갈 수 있다. 카드가 더 이상 남아있지 않을 때까지 턴은 반복된다. 게임의 점수는 자신이 가져간 카드에 적힌 수의 합이다.

근우와 명우는 서로 자신의 점수를 가장 높이기 위해 최선의 전략으로 게임에 임한다. 놓여있는 카드의 개수 N과 카드가 놓여있는 상태가 주어졌을 때 근우가 얻는 점수를 구하는 프로그램을 작성하시오.

예를 들어 카드가 [4, 3, 1, 2]로 놓여있다고 하자. 근우는 처음에 4가 적힌 카드를 가져가고, 명우는 3이 적힌 카드를 가져간다. 그리고 근우는 2가 적힌 카드를 가져가고, 명우는 마지막으로 1이 적힌 카드를 가져간다. 이때 근우와 명우는 최선의 전략으로 임했으며, 근우가 얻는 점수는 6이다.

입력
입력의 첫 줄에는 테스트케이스의 수 T가 주어진다.

각 테스트케이스 마다 첫 줄에는 카드의 개수 N(1 ≤ N ≤ 1,000)이 주어진다. 두 번째 줄에는 N개의 자연수가 공백으로 구분되어 주어지는데, i번째로 주어지는 수는 왼쪽에서 i번째에 놓인 카드에 적힌 수를 의미한다. 카드에 적혀있는 수는 1이상 10,000이하다.

출력
각 테스트케이스마다 근우와 명우가 최선의 전략으로 임할 때 근우가 얻게되는 점수를 줄로 구분하여 출력한다.

풀이:
근우의 턴엔 근우가 최대가 되게, 명우의 턴엔 근우가 최소가 되게 완전탐색합니다.
왼쪽에서 뽑는 인덱스, 오른쪽에서 뽑는 인덱스, 턴이 동일하다면 항상 같은 값을 가지기 때문에 
3차원 배열을 이용해 메모이제이션을 사용할 수 있습니다.
*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<vector>
#include<string.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>

int T, N;
int arr[1001];
int dp[1001][1001][2];

int recul(int l, int r, int turn) {
	int& ret = dp[l][r][turn];
	if (ret != -1)	return ret;
	if (l >= r) {
		if (turn)	return ret = arr[l];
		return ret = 0;
	}
	if (turn) {
		return ret = max(recul(l + 1, r, !turn) + arr[l], recul(l, r - 1, !turn) + arr[r]);
	}
	else {
		return ret = min(recul(l + 1, r, !turn), recul(l, r - 1, !turn));
	}
}

int main(void) {
	FIO;

	cin >> T;
	while (T--) {
		cin >> N;

		for (int i = 0; i < N; i++)
		{
			cin >> arr[i];
		}

		memset(dp, -1, sizeof(dp));

		cout << recul(0, N - 1, 1) << "\n";
	}
}