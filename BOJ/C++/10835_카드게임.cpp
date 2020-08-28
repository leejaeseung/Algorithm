/*
문제
지훈이는 최근에 혼자 하는 카드게임을 즐겨하고 있다. 게임에 사용하는 각 카드에는 양의 정수 하나가 적혀있고 같은 숫자가 적힌 카드는 여러 장 있을 수 있다. 게임방법은 우선 짝수개의 카드를 무작위로 섞은 뒤 같은 개수의 두 더미로 나누어 하나는 왼쪽에 다른 하나는 오른쪽에 둔다. 그리고 빈 통을 하나 준비한다.

이제 각 더미의 제일 위에 있는 카드끼리 서로 비교하며 게임을 한다. 게임 규칙은 다음과 같다. 지금부터 왼쪽 더미의 제일 위 카드를 왼쪽 카드로, 오른쪽 더미의 제일 위 카드를 오른쪽 카드로 부르겠다.

언제든지 왼쪽 카드만 통에 버릴 수도 있고 왼쪽 카드와 오른쪽 카드를 둘 다 통에 버릴 수도 있다. 이때 얻는 점수는 없다.
오른쪽 카드에 적힌 수가 왼쪽 카드에 적힌 수보다 작은 경우에는 오른쪽 카드만 통에 버릴 수도 있다. 오른쪽 카드만 버리는 경우에는 오른쪽 카드에 적힌 수만큼 점수를 얻는다.
(1)과 (2)의 규칙에 따라 게임을 진행하다가 어느 쪽 더미든 남은 카드가 없다면 게임이 끝나며 그때까지 얻은 점수의 합이 최종 점수가 된다.
다음 예는 세 장 씩 두 더미의 카드를 가지고 게임을 시작하는 경우이다

카드 순서	왼쪽 더미	오른쪽 더미
1	3	2
2	2	4
3	5	1
이 경우, 우선 오른쪽 카드 2가 왼쪽 카드 3보다 작으므로 규칙 (1)에 따라 왼쪽 카드만 버리거나 왼쪽 카드와 오른쪽 카드를 모두 버리거나, 규칙 (2)에 따라 오른쪽 카드만 버릴 수 있다. 만약 오른쪽 카드만 버리는 것으로 선택하면, 2만큼 점수를 얻고 오른쪽 카드 2는 버린다. 이제 오른쪽 더미의 제일 위 카드는 4이고 이는 왼쪽 카드 3보다 크므로 규칙 (1)에 따라 왼쪽 카드만 버리거나 왼쪽 카드와 오른쪽 카드를 둘 다 버릴 수 있다. 만약 둘 다 버리는 것으로 선택하면, 이제 왼쪽 카드는 2가 되고 오른쪽 카드는 1이 된다. 이 경우 다시 규칙 (1)과 (2)에 따라 세 가지 중 한가지를 선택할 수 있고, 그 중 왼쪽 카드만 버리는 것으로 선택하면 이제 왼쪽 카드는 5가 되고 오른쪽 카드는 1이 된다. 이 경우에도 역시 규칙 (1)과 (2)에 따라 세 가지 중 한가지를 선택할 수 있고, 그 중 오른쪽 카드만 버리는 것으로 선택하면 1만큼 점수를 얻고 오른쪽 카드 1은 버린다. 이제 오른쪽 더미에는 남은 카드가 없으므로 규칙 (3)에 따라 게임이 끝나며 최종 점수는 2+1=3이 된다.

두 더미의 카드가 주어졌을 때, 게임을 통해 얻을 수 있는 최종 점수의 최댓값을 출력하는 프로그램을 작성하시오. 위 예에서 최종 점수의 최댓값은 7이다.

입력
첫 줄에는 한 더미의 카드의 개수를 나타내는 자연수 N(1 ≤ N ≤ 2,000)이 주어진다. 다음 줄에는 왼쪽 더미의 카드에 적힌 정수 A(1 ≤ A ≤ 2,000)가 카드 순서대로 N개 주어진다. 그 다음 줄에는 오른쪽 더미의 카드에 적힌 정수 B(1 ≤ B ≤ 2,000)가 카드 순서대로 N개 주어진다. 각 더미에는 같은 숫자를 가진 카드가 두 개 이상 있을 수 있다.

출력
얻을 수 있는 최종 점수의 최댓값을 출력한다.

풀이:
재귀함수를 이용한 DP 문제이다.
각 상황마다 가능한 경우를 모두 재귀 호출하고, 메모이제이션을 이용해 풀이한다.
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

int n;
int dp[2001][2001];
vector<int> lc;
vector<int> rc;

int recul(int lp, int rp) {

	if (lp >= lc.size() || rp >= rc.size())	return 0;

	int& ret = dp[lp][rp];
	if (ret != -1)	return ret;

	ret = 0;

	if (lc[lp] > rc[rp]) {
		ret = max(ret, max(recul(lp, rp + 1) + rc[rp], max(recul(lp + 1, rp + 1), recul(lp + 1, rp))));
	}
	else {
		ret = max(ret, max(recul(lp + 1, rp + 1), recul(lp + 1, rp)));
	}

	return ret;
}

int main(void) {
	FIO;

	cin >> n;

	fill(&dp[0][0], &dp[2000][2001], -1);

	for (int i = 0; i < n; i++)
	{
		int v;
		cin >> v;
		lc.push_back(v);
	}

	for (int i = 0; i < n; i++)
	{
		int v;
		cin >> v;
		rc.push_back(v);
	}

	cout << recul(0, 0);
}