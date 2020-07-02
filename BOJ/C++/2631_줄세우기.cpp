/*
����
KOI ��������� N���� ���̵��� �ִ�. ������ ��ǳ�� ���� ���̴�. �������� 1������ N������ ��ȣ�� �����ִ� ��ȣǥ�� ���̵��� ������ �ٿ��־���. �������� ���̵��� ȿ�������� ��ȣ�ϱ� ���� ���������� ��ȣ������� �Ϸķ� ���� �ɾ���� �Ͽ���. �̵� ���߿� ���� ���̵��� ��ȣ������ �ٲ����. �׷��� �������� �ٽ� ��ȣ ������� ���� ����� ���ؼ� ���̵��� ��ġ�� �ű���� �Ѵ�. �׸��� ���̵��� ȥ������������ �ʵ��� �ϱ� ���� ��ġ�� �ű�� ���̵��� ���� �ּҷ� �Ϸ��� �Ѵ�.

���� ���, 7���� ���̵��� ������ ���� ������� ���� �� �ִٰ� ����.

3 7 5 2 6 1 4

���̵��� ������� ���� ����� ����, ���� 4�� ���̸� 7�� ������ �ڷ� �Űܺ���. �׷��� ������ ���� ������ �ȴ�.

3 7 4 5 2 6 1

����, 7�� ���̸� �� �ڷ� �ű��.

3 4 5 2 6 1 7

���� 1�� ���̸� �� ������ �ű��.

1 3 4 5 2 6 7

���������� 2�� ���̸� 1�� ������ �ڷ� �ű�� ��ȣ ������� ��ġ�ȴ�.

1 2 3 4 5 6 7

���� ������� ��� 4���� ���̸� �Ű� ��ȣ ������� ���� �����. ���� ������ 3���� ���̸��� �Űܼ��� ������� ��ġ�� ���� ����. ����, 4���� �ű�� ���� ���� ���� ���� ���̸� �ű�� ���̴�.

N���� ���̵��� ������ ������ ���� �� ���� ��, ��ȣ ������� ��ġ�ϱ� ���� �Ű����� ������ �ּ� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ��� ���̵��� �� N�� �־�����. ��° �ٺ��ʹ� 1���� N������ ���ڰ� �� �ٿ� �ϳ��� �־�����. N�� 2 �̻� 200 ������ �����̴�.

���
ù° �ٿ��� ��ȣ ������� ���� ����µ� �Ű����� ���̵��� �ּ� ���� ����Ѵ�.

Ǯ��:
LIS �����Դϴ�.

���� �� �κ� ���� ����(���ÿ��� 3 5 6) �� ���ϸ�, �ٸ� ���ڵ��� �� �κ� ���� ������ �������ߴ°� �ּ��Դϴ�.
���� (n - �κ� ���� ������ ����) �� ������ �˴ϴ�.
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

int n;
int arr[201];
//int dp[201];
vector<int> dp;

int lower_bound(int s, int e, int v) {
	while (s < e) {
		int mid = (s + e) / 2;

		if (dp[mid] > v) {
			e = mid;
		}
		else {
			s = mid + 1;
		}
	}

	return s;
}

int main(void) {
	FIO;

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	dp.push_back(arr[1]);

	for (int i = 2; i <= n; i++)
	{
		int now = arr[i];

		if (dp[dp.size() - 1] < now) {
			dp.push_back(now);
		}
		else {
			dp[lower_bound(0, dp.size() - 1, now)] = now;
		}
	}

	cout << n - dp.size();
}