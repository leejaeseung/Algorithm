/*
E. Lucky Queries
time limit per test3 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Petya loves lucky numbers very much. Everybody knows that lucky numbers are positive integers whose decimal record contains only the lucky digits 4 and 7. For example, numbers 47, 744, 4 are lucky and 5, 17, 467 are not.

Petya brought home string s with the length of n. The string only consists of lucky digits. The digits are numbered from the left to the right starting with 1. Now Petya should execute m queries of the following form:

switch l r — "switch" digits (i.e. replace them with their opposites) at all positions with indexes from l to r, inclusive: each digit 4 is replaced with 7 and each digit 7 is replaced with 4 (1 ≤ l ≤ r ≤ n);
count — find and print on the screen the length of the longest non-decreasing subsequence of string s.
Subsequence of a string s is a string that can be obtained from s by removing zero or more of its elements. A string is called non-decreasing if each successive digit is not less than the previous one.

Help Petya process the requests.

Input
The first line contains two integers n and m (1 ≤ n ≤ 106, 1 ≤ m ≤ 3·105) — the length of the string s and the number of queries correspondingly. The second line contains n lucky digits without spaces — Petya's initial string. Next m lines contain queries in the form described in the statement.

Output
For each query count print an answer on a single line.

풀이:
세그먼트 트리 레이지 프로퍼게이션 문제였습니다.

TF[now] = 현재 구간에서의 왼쪽->오른쪽 방향의 최장 수열 길이
TB[now] = 현재 구간에서의 오른쪽->왼쪽 방향의 최장 수열 길이
c4[now] = 현재 구간의 4의 개수
c7[now] = 현재 구간의 7의 개수

현재 노드의 최장 수열의 길이를 구하려면
max((왼쪽 노드의 최장 수열 길이 + 오른쪽 노드의 7의 개수), (오른쪽 노드의 최장 수열 길이) + (왼쪽 노드의 4의 개수)) 가 됩니다.

왜냐하면
왼쪽에서 최장 수열의 길이를 이미 구했다고 가정하고, 오른쪽에 7의 개수만 세어주면 되는데, 오른쪽에 4가 오는 경우는 두 번째 조건에서 찾게 됩니다.
즉, 오른쪽에 4가 오는 경우는 (오른쪽 노드의 최장 수열 길이)에 포함되어 있습니다.
마찬가지로 오른쪽 최장 수열 길이를 이미 구했다면 왼쪽에 올 수 있는 건 4밖에 없습니다.
위에서 TF를 구했고, TB는 반대로만 해주면 됩니다.

위 방법만을 이용하면 결과는 TF[1](Root) 에 저장되지만, 시간 초과가 나므로 레이지 프로퍼게이션을 적용해야 합니다.

774 777
위 두개를 자식노드로 하고 있다고 가정해 봅시다.
774의 TB는 3입니다. 4->7->7 이므로
774를 뒤집으면, TF는 3이 나옵니다. 4->4->7 이므로
즉, 뒤집은 다음의 TF는 뒤집기 전 TB와 같습니다.

따라서 774777의 TF를 구하려면
(774의 TB + 777의 4의 개수)와 -- 4의 개수? = 4가 뒤집히면 7이 되므로
같은 방식으로
(777의 TB + 774의 7의 개수)
중 큰 값을 구하면 됩니다.

이제 어떤 노드 n 에 대하여 n의 구간을 모두 뒤집을 때 TF의 값을 구할 수 있었습니다.
같은 방식으로 TB도 구할 수 있습니다.
물론 자신의 c4, c7의 개수도 서로 바꿔 줍니다.

지금까지 구한 게 레이지 프로퍼게이션 중 일부인데,
이제 자식 노드들만의 정보만으로 자신의 정보(TF, TB)를 업데이트(뒤집기)할 수 있습니다!
그렇다는건 뒤집어야 하는지 여부만 자식들에게 알려준 뒤, 빠르게 자신의 구간 값을 return할 수 있다는 얘깁니다.

남은건 각 노드를 만날 때마다 뒤집을 지 여부가 true라면 뒤집고, 자식들에게 전파만 하면 됩니다.

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
#define pic pair<int, char>
#define ll long long
#define vi vector<int>
#define vl vector<long long>
#define vii vector<pii>
#define IMAX 2000000001
#define LMAX 100000000000000
int mv1[4] = { 0, 0, 1, -1 };
int mv2[4] = { 1, -1, 0, 0 };

int n, m;
int TN[5000001];
int TF[5000001];
int TB[5000001];
int c4[5000001];
int c7[5000001];
bool rev[5000001];

void propagate(int now, int s, int e) {
	if (rev[now]) {

		if (s != e) {
			rev[now * 2] = !rev[now * 2];
			rev[now * 2 + 1] = !rev[now * 2 + 1];

			if (rev[now * 2]) {
				//자식이 뒤집어져 있었지 않다면
				TF[now] = max(TB[now * 2] + c4[now * 2 + 1], c7[now * 2] + TB[now * 2 + 1]);
				TB[now] = max(TF[now * 2] + c7[now * 2 + 1], c4[now * 2] + TF[now * 2 + 1]);
			}
			else {
				//자식이 뒤집어져 있었다면 -> 다시 뒤집을 필요 없으므로 그대로 사용
				TF[now] = max(TF[now * 2] + c7[now * 2 + 1], c4[now * 2] + TF[now * 2 + 1]);
				TB[now] = max(TB[now * 2 + 1] + c7[now * 2], c4[now * 2 + 1] + TB[now * 2]);
			}
		}

		int temp = c4[now];
		c4[now] = c7[now];
		c7[now] = temp;
		//4,7의 개수 바꿔줌.
		rev[now] = 0;
	}
}

void init(int now, int s, int e, int l, int r, int v) {
	if (l > e || r < s)	return;
	if (s == e) {
		TF[now] = 1;
		TB[now] = 1;
		if (v == 4) {
			c4[now] = 1;
		}
		else if (v == 7) {
			c7[now] = 1;
		}
		return;
	}

	int mid = (s + e) / 2;
	init(now * 2, s, mid, l, r, v);
	init(now * 2 + 1, mid + 1, e, l, r, v);

	c4[now] = c4[now * 2] + c4[now * 2 + 1];
	c7[now] = c7[now * 2] + c7[now * 2 + 1];

	TF[now] = max(TF[now * 2] + c7[now * 2 + 1], c4[now * 2] + TF[now * 2 + 1]);
	TB[now] = max(TB[now * 2 + 1] + c7[now * 2], c4[now * 2 + 1] + TB[now * 2]);
}

void update(int now, int s, int e, int l, int r) {
	propagate(now, s, e);
	//뒤집을 지 확인

	if (l > e || r < s)	return;
	if (l <= s && e <= r) {
		rev[now] = !rev[now];
		propagate(now, s, e);
		//뒤집을 지 확인
		return;
	}
	if (s == e) return;
	

	int mid = (s + e) / 2;
	update(now * 2, s, mid, l, r);
	update(now * 2 + 1, mid + 1, e, l, r);

	c4[now] = c4[now * 2] + c4[now * 2 + 1];
	c7[now] = c7[now * 2] + c7[now * 2 + 1];
	
	TF[now] = max(TF[now * 2] + c7[now * 2 + 1], c4[now * 2] + TF[now * 2 + 1]);
	TB[now] = max(TB[now * 2 + 1] + c7[now * 2], c4[now * 2 + 1] + TB[now * 2]);
}

int main(void) {
	FIO;

	cin >> n >> m;

	string s;
	cin >> s;

	for (int i = 1; i <= n; i++)
	{
		int v = s[i - 1] - '0';
		init(1, 1, n, i, i, v);
	}

	for (int i = 0; i < m; i++)
	{
		string q;
		cin >> q;

		if (q == "switch") {
			int l, r;
			cin >> l >> r;
			update(1, 1, n, l, r);
		}
		else {
			cout << TF[1] << "\n";
		}
	}
}