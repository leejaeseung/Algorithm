/*
문제
홍준이는 러너이다. 그런데 어쩌다 보니 아무리 뛰어도 뛰어도 속도가 변하지 않는다. 1초에 딱 1칸을 움직인다.

그런데 홍준이가 뛰는 코스는 광고판으로 가득하다. 광고판은 빛의 세기가 다른데, 홍준이는 자신이 볼 수 있는 광고판들 중에서 가장 강렬한 빛의 광고판만이 눈에 들어온다.

홍준이는 눈이 안좋기 때문에 빛의 세기가 강한 지점에서는 안경을 쓰고 뛰려한다. 그래서 알아야 할 것이, 뛰어가면서 보이는 광고판의 빛의 세기를 알고 싶다.

홍준이가 뛰어갈 때, 1초마다 보이는 광고판의 빛의 세기를 출력하여라.

입력
첫째 줄에는 뛰는 코스의 길이, 즉 칸수 N과 홍준이의 시야의 범위 M이 주어진다. 시야가 M이라고 하면 현재 위치에서 앞뒤로 M칸까지 광고판이 보이는 것이다. (1<=M<=N<=1,000,000) 두 번째 줄에는 각각 칸에 있는 광고판들의 빛의 세기가 주어진다. 빛의 세기는 1,000,000을 넘지 않는 자연수이다.
  홍준이는 언제나 광고판을 2M-1개 보면서 뛰고 싶기 때문에(중심으로) M번째 칸에서 뛰기 시작해서 N-M+1번째 칸에서 멈춘다고 가정하자.

출력
뛰면서 보이는 광고판의 세기를 출력한다.

풀이:
최댓값 세그먼트 트리 문제이다.
*/
#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
using namespace std;

int N, M;
int* tree;
int list[1000001];

int init(int now, int l, int r) {
	if (l == r)
		return tree[now] = list[l];

	return tree[now] = max(init(now * 2, l, (l + r) / 2), init(now * 2 + 1, (l + r) / 2 + 1, r));
}

int getMax(int now, int l, int r, int s, int e) {
	if (r < s || l > e)	return 0;
	if (s <= l && e >= r)	return tree[now];

	return max(getMax(now * 2, l, (l + r) / 2, s, e), getMax(now * 2 + 1, (l + r) / 2 + 1, r, s , e));
}


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	double H = ceil(log2(N));
	tree = (int*)malloc(sizeof(int) * (int)(pow(2, H + 1)));

	for (int i = 1; i <= N; i++)
	{
		cin >> list[i];
	}
	init(1, 1, N);

	for (int i = M; i <= N - M + 1; i++)
	{
		cout << getMax(1, 1, N, i - M + 1, i + M - 1) << " ";
	}

}