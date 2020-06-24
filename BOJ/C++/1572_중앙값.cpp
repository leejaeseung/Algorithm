/*
����
�߾Ӱ��̶�, ������ �����߰�, �� ũ�Ⱑ N�� ��, 1���� �����ؼ� (N+1)/2��° �ִ� ���Ұ� �� ������ �߾Ӱ��̴�. ���� ���, {1, 2, 6, 5, 4, 3}������ 3�̰�, {11, 13, 12, 15, 14}������ 13�̴�.

�������� 1�ʿ� �µ��� �ϳ��� ��� �µ��踦 �������. �� �µ��迡�� ���� ���÷��� â�� �ϳ� �ִµ�, �� â���� ���ݺ��� �ֱ� K�� ���� �µ��� �߾Ӱ��� ǥ���� �ش�. (�µ��� ���������� K�ʺ��� ǥ���Ѵ�. �� ������ �ƹ��͵� ��µ��� �ʴ´�.)

�������� �µ��� N�ʵ��� ���. �� �ð� ���� �µ����� ���÷��� â�� �ߴ� ������ ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�ٸ� ���� �ϸ�, ���̰� N�� ������ �־�����. �� ������ N-K+1 ���� ���̰� K�� ���ӵ� �κ� ������ �����Ѵ�. �� �κ� ������ �߾Ӱ��� ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� N�� K�� �־�����. N�� 250,000���� �۰ų� ���� �ڿ����̰�, K�� 5,000���� �۰ų� ���� �ڿ����̴�. N�� �׻� K���� ũ�ų� ����. ��° �ٺ��� N���� ���� �� �ٿ� �ϳ��� �־�����. �Է����� �־����� ���� 65536���� �۰ų� ���� �ڿ��� �Ǵ� 0�̴�.

���
��° �ٿ� ������ ����Ѵ�. ������ int64������.

Ǯ��:
���׸�Ʈ Ʈ�� ���� �����Դϴ�.
�迭�� ���� �� �ִ� ���� ������ 0 ~ 65536���� ����� �����ϴ�.
�� ������ ���׸�Ʈ Ʈ���� ����µ�, �ʰ� ���� ������ �ش� �µ��� �ش��ϴ� tree�� ���� �� ���� 1�������� �ݴϴ�.

�׷� ���׸�Ʈ Ʈ���� ���� ������ �� �µ����� �� �� �����ϴ��� ���� ������ ��Ÿ���� ���ϴ�.
�߾Ӱ��� ���Ϸ���, ��Ʈ���� ���� �������� ���鼭 
mid��((k + 1) / 2) ���� �������� ũ�ų� ���ٸ� -> ����
�۴ٸ� -> ������(�� ��, mid���� ���� �����ո�ŭ ���־�� �մϴ�.)

leaf ��尡 �ش� ������ �߾Ӱ��� �˴ϴ�.
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
int mv1[4] = { 0, 1, 0, -1 };
int mv2[4] = { 1, 0, -1, 0 };

int n, k;
int tree[300000];
int arr[250001];
ll sum = 0;

int update(int now, int s, int e, int v, int idx) {
	if (idx < s || idx > e)	return tree[now];
	if (s == e) {
		return tree[now] += v;
	}
	
	return tree[now] = update(now * 2, s, (s + e) / 2, v, idx) + update(now * 2 + 1, (s + e) / 2 + 1, e, v, idx);
}

void get(int now, int s, int e, int mid) {
	
	if (s == e) {
		sum += s;
		return;
	}
	int left = tree[now * 2];
	int right = tree[now * 2 + 1];

	if (left >= mid) {
		get(now * 2, s, (s + e) / 2, mid);
	}
	else {
		get(now * 2 + 1, (s + e) / 2 + 1, e, mid - left);
	}
}

int main(void) {
	FIO;

	cin >> n >> k;

	for (int i = 1; i <= n; i++)
	{
		int v;
		cin >> v;
		arr[i] = v;
	}

	for (int i = 1; i <= n; i++)
	{
		update(1, 0, 65536, 1, arr[i]);
		if (i > k) 
			update(1, 0, 65536, -1, arr[i - k]);
		
		if(i >= k)
			get(1, 0, 65536, (k + 1) / 2);
	}

	cout << sum;
}