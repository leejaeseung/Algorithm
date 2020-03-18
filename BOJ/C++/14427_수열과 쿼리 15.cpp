/*
문제
길이가 N인 수열 A1, A2, ..., AN이 주어진다. 이때, 다음 쿼리를 수행하는 프로그램을 작성하시오.

1 i v : Ai를 v로 바꾼다. (1 ≤ i ≤ N, 1 ≤ v ≤ 109)
2 : 수열에서 크기가 가장 작은 값의 인덱스를 출력한다. 그러한 값이 여러개인 경우에는 인덱스가 작은 것을 출력한다.
수열의 인덱스는 1부터 시작한다.

입력
첫째 줄에 수열의 크기 N이 주어진다. (1 ≤ N ≤ 100,000)

둘째 줄에는 A1, A2, ..., AN이 주어진다. (1 ≤ Ai ≤ 109)

셋째 줄에는 쿼리의 개수 M이 주어진다. (1 ≤ M ≤ 100,000)

넷째 줄부터 M개의 줄에는 쿼리가 주어진다.

출력
2번 쿼리에 대해서 정답을 한 줄에 하나씩 순서대로 출력한다.

풀이:
최소값 세그먼트 트리를 작성합니다.
인덱스를 출력해야 하므로, 세그먼트 트리에 인덱스를 저장합니다.
*/

#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pii pair<int, int>

int N, Q;
int tree[500010];
int list[100001];

int update(int now, int l, int r, int idx) {
	if (l > idx || r < idx)	return tree[now];
	if (l == r) {
		return tree[now] = idx;
	}
	int left = update(now * 2, l, (l + r) / 2, idx);
	int right = update(now * 2 + 1, (l + r) / 2 + 1, r, idx);

	if (list[left] < list[right])
		tree[now] = left;
	else if (list[left] == list[right]) {
		if (left < right)
			tree[now] = left;
		else
			tree[now] = right;
	}
	else
		tree[now] = right;
	return tree[now];
}

int main(void) {
	FIO;

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		int v;
		cin >> v;

		list[i] = v;
	}
	for (int i = 1; i <= N ; i++)
	{
		update(1, 1, N, i);
	}
	cin >> Q;

	for (int i = 0; i < Q; i++)
	{
		int q, a, b;
		cin >> q;

		if (q == 1) {
			cin >> a >> b;

			list[a] = b;
			update(1, 1, N, a);
		}
		else {
			cout << tree[1] << "\n";
		}
	}
	
}