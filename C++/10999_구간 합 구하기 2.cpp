/*
문제
어떤 N개의 수가 주어져 있다. 그런데 중간에 수의 변경이 빈번히 일어나고 그 중간에 어떤 부분의 합을 구하려 한다. 만약에 1,2,3,4,5 라는 수가 있고, 3번째부터 4번째 수에 6을 더하면 1, 2, 9, 10, 5가 되고, 여기서 2번째부터 5번째까지 합을 구하라고 한다면 26을 출력하면 되는 것이다. 그리고 그 상태에서 1번째부터 3번째 수에 2를 빼고 2번째부터 5번째까지 합을 구하라고 한다면 22가 될 것이다.

입력
첫째 줄에 수의 개수 N(1 ≤ N ≤ 1,000,000)과 M(1 ≤ M ≤ 10,000), K(1 ≤ K ≤ 10,000) 가 주어진다. M은 수의 변경이 일어나는 횟수이고, K는 구간의 합을 구하는 횟수이다. 그리고 둘째 줄부터 N+1번째 줄까지 N개의 수가 주어진다. 그리고 N+2번째 줄부터 N+M+K+1번째 줄까지 세 개의 정수 a, b, c 또는 a, b, c, d가 주어지는데, a가 1인 경우 b번째 수부터 c번째 수에 d를 더하고, a가 2인 경우에는 b부터 c까지의 합을 구하여 출력하면 된다.

입력으로 주어지는 모든 수는 -263보다 크거나 같고, 263-1보다 작거나 같은 정수이다.

출력
첫째 줄부터 K줄에 걸쳐 구한 구간의 합을 출력한다. 단, 정답은 -263보다 크거나 같고, 263-1보다 작거나 같은 정수이다.

풀이:
구간합 세그먼트 트리를 레이지하게 구현하는 문제입니다.
http://blog.naver.com/PostView.nhn?blogId=kks227&logNo=220824350353&parentCategoryNo=168&categoryNo=&viewDate=&isShowPopularPosts=true&from=search
풀이는 위 블로그를 참고했습니다.
값을 update 및, 구간 합을 구할 때 자식 노드들에게 지금까지 쌓인 자신의 lazy값을 전파하는 propagate() 를 사용합니다.
*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include<stack>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pii pair<int, int>;

int N, M, K;
long long tree[5000001];
long long lazy[5000001];

long long init(int now, int l, int r, int idx, long long v) {
	if (idx > r || idx < l)	return tree[now];
	if (l == r) 
		return tree[now] = v;
	
	return tree[now] = init(now * 2, l, (l + r) / 2, idx, v) + init(now * 2 + 1, (l + r) / 2 + 1, r, idx, v);
}

void propagate(int now, int l, int r) {
	if (lazy[now] != 0) {
		if (l != r) {
			lazy[now * 2] += lazy[now];
			lazy[now * 2 + 1] += lazy[now];
		}
		tree[now] += lazy[now] * (r - l + 1);
		lazy[now] = 0;
	}
}

void update(int now, int l, int r, int s, int e, long long add) {
	propagate(now, l, r);

	if (r < s || l > e)	return;
	if (s <= l && e >= r) {
		lazy[now] += add;
		propagate(now, l, r);
	}
	else {
		update(now * 2, l, (l + r) / 2, s, e, add);
		update(now * 2 + 1, (l + r) / 2 + 1, r, s, e, add);

		tree[now] = tree[now * 2] + tree[now * 2 + 1];
	}
}



long long getSum(int now, int l, int r, int s, int e) {
	propagate(now, l, r);

	if (r < s || l > e)	return 0;
	if (s <= l && e >= r) return tree[now];

		return getSum(now * 2, l, (l + r) / 2, s, e) + getSum(now * 2 + 1, (l + r) / 2 + 1, r, s, e);
}

int main(void) {
	FIO;

	cin >> N >> M >> K;
	
	for (int i = 1; i <= N; i++)
	{
		int n;
		cin >> n;
		init(1, 1, N, i, n);
	}

	for (int i = 0; i < M + K; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c;

		if (a == 1) {
			cin >> d;

			update(1, 1, N, b, c, d);
		}
		else {
			cout << getSum(1, 1, N, b, c) << "\n";
		}
	}
}