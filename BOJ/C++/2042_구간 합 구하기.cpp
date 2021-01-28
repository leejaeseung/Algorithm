/*
구간 합 구하기 성공분류 Gold Isolved.ac 표준
자료 구조세그먼트 트리
난이도 제공: solved.ac — 난이도 투표하러 가기
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
2 초	256 MB	42922	7908	4107	24.206%
문제
어떤 N개의 수가 주어져 있다. 그런데 중간에 수의 변경이 빈번히 일어나고 그 중간에 어떤 부분의 합을 구하려 한다. 만약에 1,2,3,4,5 라는 수가 있고, 3번째 수를 6으로 바꾸고 2번째부터 5번째까지 합을 구하라고 한다면 17을 출력하면 되는 것이다. 그리고 그 상태에서 다섯 번째 수를 2로 바꾸고 3번째부터 5번째까지 합을 구하라고 한다면 12가 될 것이다.

입력
첫째 줄에 수의 개수 N(1 ≤ N ≤ 1,000,000)과 M(1 ≤ M ≤ 10,000), K(1 ≤ K ≤ 10,000) 가 주어진다. M은 수의 변경이 일어나는 횟수이고, K는 구간의 합을 구하는 횟수이다. 그리고 둘째 줄부터 N+1번째 줄까지 N개의 수가 주어진다. 그리고 N+2번째 줄부터 N+M+K+1번째 줄까지 세 개의 정수 a, b, c가 주어지는데, a가 1인 경우 b(1 ≤ b ≤ N)번째 수를 c로 바꾸고 a가 2인 경우에는 b(1 ≤ b ≤ N)번째 수부터 c(b ≤ c ≤ N)번째 수까지의 합을 구하여 출력하면 된다.

입력으로 주어지는 모든 수는 -263보다 크거나 같고, 263-1보다 작거나 같은 정수이다.

출력
첫째 줄부터 K줄에 걸쳐 구한 구간의 합을 출력한다. 단, 정답은 -263보다 크거나 같고, 263-1보다 작거나 같은 정수이다.

풀이:
세그먼트 트리 기본 문제, 입력의 크기만 잘 생각하자
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
int mv1[4] = { 0, 0, 1, 1 };
int mv2[4] = { 0, 1, 0, 1 };

ll tree[5000000];

void update(int now, int l, int r, int idx, ll v) {
	if (l > idx || r < idx)	return;

	if (l == r) {
		tree[now] = v;
		return;
	}

	update(now * 2, l, (l + r) / 2, idx, v);
	update(now * 2 + 1, (l + r) / 2 + 1, r, idx, v);

	tree[now] = tree[now * 2] + tree[now * 2 + 1];
}

ll getSum(int now, int l, int r, int s, int e) {
	if (r < s || e < l)	return 0;
	if (l >= s && r <= e) return tree[now];
	
	return getSum(now * 2, l, (l + r) / 2, s, e) + getSum(now * 2 + 1, (l + r) / 2 + 1, r, s, e);
}

int main() {
	FIO;

	int n, m, k;

	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++)
	{
		ll num;
		cin >> num;
		
		update(1, 1, n, i, num);
	}

	for (int i = 0; i < m + k; i++)
	{
		ll a, b, c;

		cin >> a >> b >> c;

		if (a == 1) {
			update(1, 1, n, b, c);
		}
		else {
			cout << getSum(1, 1, n, b, c) << "\n";
		}
	}
}