/*
����
ȫ���̴� �����̴�. �׷��� ��¼�� ���� �ƹ��� �پ �پ �ӵ��� ������ �ʴ´�. 1�ʿ� �� 1ĭ�� �����δ�.

�׷��� ȫ���̰� �ٴ� �ڽ��� ���������� �����ϴ�. �������� ���� ���Ⱑ �ٸ���, ȫ���̴� �ڽ��� �� �� �ִ� �����ǵ� �߿��� ���� ������ ���� �����Ǹ��� ���� ���´�.

ȫ���̴� ���� ������ ������ ���� ���Ⱑ ���� ���������� �Ȱ��� ���� �ٷ��Ѵ�. �׷��� �˾ƾ� �� ����, �پ�鼭 ���̴� �������� ���� ���⸦ �˰� �ʹ�.

ȫ���̰� �پ ��, 1�ʸ��� ���̴� �������� ���� ���⸦ ����Ͽ���.

�Է�
ù° �ٿ��� �ٴ� �ڽ��� ����, �� ĭ�� N�� ȫ������ �þ��� ���� M�� �־�����. �þ߰� M�̶�� �ϸ� ���� ��ġ���� �յڷ� Mĭ���� �������� ���̴� ���̴�. (1<=M<=N<=1,000,000) �� ��° �ٿ��� ���� ĭ�� �ִ� �����ǵ��� ���� ���Ⱑ �־�����. ���� ����� 1,000,000�� ���� �ʴ� �ڿ����̴�.
  ȫ���̴� ������ �������� 2M-1�� ���鼭 �ٰ� �ͱ� ������(�߽�����) M��° ĭ���� �ٱ� �����ؼ� N-M+1��° ĭ���� ����ٰ� ��������.

���
�ٸ鼭 ���̴� �������� ���⸦ ����Ѵ�.

Ǯ��:
�ִ� ���׸�Ʈ Ʈ�� �����̴�.
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