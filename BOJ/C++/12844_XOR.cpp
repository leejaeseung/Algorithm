/*
문제
문제가 길면 출제자도 참가자도 힘들다. 따라서 이 문제는 너무 친절하게도 짧다.

수열이 주어졌을 때 두 종류의 쿼리를 수행해야 한다.

a와 b 사이 (a, b도 포함) 구간에 있는 모든 원소에 c를 xor 한다.
a와 b 사이 (a, b도 포함) 구간에 있는 모든 원소를 xor 한 값을 출력한다.
초기 수열과 연산의 정보가 주어졌을 때, 그에 맞게 출력한다.

입력
첫 번째 줄에 수열의 크기 n(0 < n ≤ 500,000)이 주어진다.

수열의 원소가 0번부터 n - 1 번까지 차례대로 주어진다. 수열의 원소는 100,000보다 작거나 같은 자연수 또는 0이다.

세 번째 줄에 여러분이 수행할 쿼리의 개수 m(0 < m ≤ 500,000)이 주어진다.

그 다음 m 개의 줄에는 t, a, b, c가 주어진다. t가 1이면 첫 번째 종류의 쿼리를 수행해야 하고, t가 2이면 두 번째 종류의 쿼리를 수행해야 한다. (0 ≤ a, b < n, 0 ≤ c ≤ 100,000)

출력
두 번째 종류의 쿼리를 수행한다.

풀이:
구간 합 레이지 프로퍼게이션과 거의 같은 문제입니다.

lazy 값을 전파할 때 ^ 연산은 짝수 번 연산 시 값의 변화가 없으므로 
해당 노드의 범위가 홀수 개일 때에만 ^ 연산을 해줍니다.

구간 a, b 에서 b > a 인 입력이 있습니다.
*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<string.h>
#include<vector>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>

int tree[2000000];
int lazy[2000000];
int N;

void propagate(int now, int l, int r) {
	if (lazy[now] != 0) {
		
		if (l != r) {
			lazy[now * 2] ^= lazy[now];
			lazy[now * 2 + 1] ^= lazy[now];
		}
		
		if((r - l + 1) % 2 == 1)
			tree[now] ^= lazy[now];
		
		lazy[now] = 0;
	}
}

void update(int now, int l, int r, int s, int e, int XOR) {
	propagate(now, l, r);

	if (e < l || s > r)	return;
	if (l >= s && e >= r) {
		lazy[now] ^= XOR;
		propagate(now, l, r);
		return;
	}
	update(now * 2, l, (l + r) / 2, s, e, XOR);
	update(now * 2 + 1, (l + r) / 2 + 1, r, s, e, XOR);

	tree[now] = tree[now * 2] ^ tree[now * 2 + 1];
}

int getXOR(int now, int l, int r, int s, int e) {
	propagate(now, l, r);

	if (e < l || s > r)		return 0;
	if (l >= s && e >= r)	return tree[now];

	return getXOR(now * 2, l, (l + r) / 2, s, e) ^ getXOR(now * 2 + 1, (l + r) / 2 + 1, r, s, e);
}


int main(void) {
	FIO;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int v;
		cin >> v;
		update(1, 0, N - 1, i, i, v);
	}

	int Q;
	cin >> Q;
	while (Q--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (b > c)
			swap(b, c);

		if (a == 1) {
			int d;
			cin >> d;
			update(1, 0, N - 1, b ,c , d);
		}
		else {
			cout << getXOR(1, 0, N - 1, b, c) << "\n";
		}
	}
}