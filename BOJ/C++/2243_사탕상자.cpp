/*
����
�����̴� � ������ �޷��� ���ؼ� ������ ����Ѵ�. �����̴� ��ҿ� ���� ���� ������ �缭 �������ڿ� �־�ΰ�, ������ ���� �� ���� ���� �� �ȿ��� ������ ������ �ְ� �Ѵ�.

������ ������ �� ���� ���� ������ 1���� 1,000,000������ ������ ���еȴ�. 1�� ���� ���ִ� ������ �ǹ��ϸ�, 1,000,000�� ���� ������ ������ �ǹ��Ѵ�. �����̴� ������ ���� �� ���� ������ ����, �������� �ȿ� �ִ� ������ �� �� ��°�� ���ִ� ������ �����ְ� �Ѵ�. ���� ��� ���� �ſ� �� ����� ������ �������ڿ��� ���� ���ִ� ������ �����ְ�, ���� ���� �� ����� ������ �������ڿ��� ���� ��°�� ���ִ� ������ �����ִ� ���̴�.

�����̰� �����ϰ� �ִ� ������ �ſ� ���� ������ �Ź� �������ڸ� ������ ���� ������ ��󳻴� ���� �ſ� ��ƴ�. �����̸� �����ִ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �����̰� �������ڿ� ���� �� Ƚ�� n(1��n��100,000)�� �־�����. ���� n���� �ٿ��� �� ���� A, B, Ȥ�� �� ���� A, B, C�� �־�����. A�� 1�� ���� �������ڿ��� ������ ������ ����̴�. �̶����� �� ������ �־�����, B�� ���� ������ ������ �ǹ��Ѵ�. �� ��� �������ڿ��� �� ���� ������ �������� �ȴ�. ��, A�� 2�� ���� ������ �ִ� ����̴�. �̶����� �� ������ �־����µ�, B�� ���� ������ ���� ��Ÿ���� �����̰� C�� �׷��� ������ �����̴�. C�� ����� ��쿡�� ������ �ִ� ����̰�, ������ ��쿡�� ���� ����̴�. �� ó������ �� �������ڿ��� �����Ѵٰ� �����ϸ�, ������ �� ������ 2,000,000,000�� ���� �ʴ´�. ���� ���� ������ ������ ���� ���� �߸��� �Է��� �־����� �ʴ´�.

���
A�� 1�� ��� �Է¿� ���ؼ�, ���� ������ ���� ��ȣ�� ����Ѵ�. ����, A=2 �̸鼭 C<0 �� ���� ������� �ʴ´�.

Ǯ��:
1 ~ 1000000 �� ������ ���� ���׸�Ʈ Ʈ���� ����� ������ ���� Ʈ���� �̺� Ž���ϸ� ã���� �ȴ�.
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
#define IMAX 2147483647
#define LMAX 1000000000000500000
#define DMAX 0xFFFFFFFFFFFFF
int mv1[4] = { 0, 1, -1, 0 };
int mv2[4] = { 1, 0, 0, -1 };

int n;
int tree[4005001];
int ans;

int update(int now, int s, int e,int idx, int v) {
	if (s > idx || e < idx)	return tree[now];

	if (s == e) {
		return tree[now] += v;
	}

	return tree[now] = update(now * 2, s, (s + e) / 2, idx, v) + update(now * 2 + 1, (s + e) / 2 + 1, e, idx, v);
}

int get(int now, int s, int e, int rank) {
	if (s == e) {
		tree[now]--;
		ans = s;
		return tree[now];
	}


	int left = tree[now * 2];
	int right = tree[now * 2 + 1];

	if (left < rank) {
		return tree[now] = tree[now * 2] + get(now * 2 + 1, (s + e) / 2 + 1, e, rank - left);
	}
	else {
		return tree[now] = get(now * 2, s, (s + e) / 2, rank) + tree[now * 2 + 1];
	}
}

int main(void) {
	FIO;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int a, b, c;
		cin >> a >> b;

		if (a == 1) {
			get(1, 1, 1000000, b);
			cout << ans << "\n";
		}
		else {
			cin >> c;

			update(1, 1, 1000000, b, c);
		}
	}
}