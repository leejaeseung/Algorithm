/*
����
N���� ���� �̷���� 1���� �迭�� �ִ�. �� �迭�� M�� ������ �������� ����� ������ ������ �ִ��� �ּҷ� �Ϸ��� �Ѵ�. ������ ������ ���� ������ �����ؾ� �Ѵ�.

�ϳ��� ������ �ϳ� �̻��� ���ӵ� ����� �̷���� �ִ�.
�迭�� �� ���� ��� �ϳ��� ������ ���ԵǾ� �־�� �Ѵ�.
������ ������ ������ ���� ���� �ִ񰪰� �ּڰ��� �����̴�.

���� ���, �迭�� [1, 5, 4, 6, 2, 1, 3, 7] �̰�, M = 3�� ��찡 �ִ�.

�̶�, [1, 5], [4, 6, 2], [1, 3, 7]�� ������ ������ �� ������ ������ 4, 4, 6���� �ȴ�. �̶�, �ִ��� 6���̴�.

����, [1, 5, 4], [6, 2, 1], [3, 7]�� ������ �������ٸ�, �� ������ ������ 4, 5, 4���� �ǰ�, �̶� �ִ��� 5���� �ȴ�.

�� ��� �߿��� �ִ��� �ּ��� ���� 5���� ���̰�, 5������ �ִ��� �۰� ����� ����� ����.

�迭�� M�� �־����� ��, ������ ������ �ִ��� �ּڰ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �迭�� ũ�� N�� M�� �־�����. (1 �� N �� 5,000, 1 �� M �� N)

��° �ٿ� �迭�� ����ִ� ���� ������� �־�����. �迭�� ����ִ� ���� 1���� ũ�ų� ����, 10,000���� �۰ų� ���� �ڿ����̴�.

���
ù° �ٿ� ������ ������ �ִ��� �ּڰ��� ����Ѵ�.

Ǯ��:
�Ķ��Ʈ�� ��ġ �����̴�.
��� ���� (s,e) �� ���� ���� ������ ���� ����, 0 ~ 10000 �� �̺� Ž������ �ּҰ��� ã�Ҵ�.
mid ������ ���� ���� �۰� �������� ������ �� ������ ������ m ���� Ŀ���� false�� ��ȯ�ϴ� parametric �Լ��� Ǯ���ߴ�.
*/
/*#include<iostream>
#include<memory.h>
#include<algorithm>
#include<math.h>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>
#define pdd pair<double, double>
#define pic pair<int, char>
#define ll long long
#define pll pair<ll, ll>
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vii vector<pii>
#define IMAX 2000000001
#define LMAX 1000000000000000000
#define DMAX 0xFFFFFFFFFFFFF
#define MOD 100003
int mv1[4] = { 0, 0, 1, -1 };
int mv2[4] = { 1, -1, 0, 0 };
int mv_all1[8] = { 0, 1, 0, -1, -1, -1, 1, 1 };
int mv_all2[8] = { 1, 0, -1, 0 , -1, 1, -1, 1 };

int n, m;
int arr[5001];

bool parametric(int v) {

	int group = 1;
	int mx = 0;
	int mn = IMAX;
	
	for (int i = 1; i <= n; i++)
	{
		mx = max(mx, arr[i]);
		mn = min(mn, arr[i]);

		if (mx - mn > v) {
			group++;
			mx = arr[i];
			mn = arr[i];
		}
	}

	if (group > m)
		return false;
	return true;
}

int main(void) {
	FIO;

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	int s = 0;
	int e = 10000;
	int ans = 0;

	while (s < e) {
		int mid = (s + e) / 2;

		if (parametric(mid)) {
			ans = mid;
			e = mid;
		}
		else {
			s = mid + 1;
		}
	}
	cout << ans;
}*/