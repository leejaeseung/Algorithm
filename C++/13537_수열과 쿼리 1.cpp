/*
문제
길이가 N인 수열 A1, A2, ..., AN이 주어진다. 이때, 다음 쿼리를 수행하는 프로그램을 작성하시오.

i j k: Ai, Ai+1, ..., Aj로 이루어진 부분 수열 중에서 k보다 큰 원소의 개수를 출력한다.
입력
첫째 줄에 수열의 크기 N (1 ≤ N ≤ 100,000)이 주어진다.

둘째 줄에는 A1, A2, ..., AN이 주어진다. (1 ≤ Ai ≤ 109)

셋째 줄에는 쿼리의 개수 M (1 ≤ M ≤ 100,000)이 주어진다.

넷째 줄부터 M개의 줄에는 쿼리 i, j, k가 한 줄에 하나씩 주어진다. (1 ≤ i ≤ j ≤ N, 1 ≤ k ≤ 109)

출력
각각의 쿼리마다 정답을 한 줄에 하나씩 출력한다.

풀이:
Merge Sort Tree 문제입니다. = 세그먼트 트리와 Merge Sort를 합친 것.
https://justicehui.github.io/ps/2018/11/26/BOJ13537/
위 블로그를 참고해 풀었습니다.

즉, 세그먼트 트리의 모든 노드들이 해당하는 구간의 값들을 정렬된 상태로 갖고 있게 만들면 됩니다.
*/

#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int N, Q;
vector<int> tree[500010];

void update(int now, int l, int r, int idx, int v) {
	if (l > idx || r < idx)	return;
	if (l == r) {
		tree[now].push_back(v);
		return;
	}
	tree[now].push_back(v);
	update(now * 2, l, (l + r) / 2, idx, v);
	update(now * 2 + 1, (l + r) / 2 + 1, r, idx, v);
}

int getMax(int now, int l, int r, int s, int e, int v) {
	if (r < s || l > e)	return 0;
	if (s <= l && r <= e) {
		return tree[now].end() - upper_bound(tree[now].begin(), tree[now].end(), v);
	}
	return getMax(now * 2, l, (l + r) / 2, s, e, v) + getMax(now * 2 + 1, (l + r) / 2 + 1, r, s, e, v);
}

int main(void) {
	FIO;

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		int v;
		cin >> v;

		update(1, 1, N, i, v);
	}
	for (int i = 0; i < 500010; i++)
	{
		sort(tree[i].begin(), tree[i].end());
	}
	cin >> Q;

	for (int i = 0; i < Q; i++)
	{
		int a, b, k;
		cin >> a >> b >> k;

		cout << getMax(1, 1, N, a, b, k) << "\n";
	}
}