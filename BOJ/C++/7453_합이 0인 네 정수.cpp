/*
����
������ �̷���� ũ�Ⱑ ���� �迭 A, B, C, D�� �ִ�.

A[a], B[b], C[c], D[d]�� ���� 0�� (a, b, c, d) ���� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �迭�� ũ�� n (1 �� n �� 4000)�� �־�����. ���� n�� �ٿ��� A, B, C, D�� ���ԵǴ� ������ �������� ���еǾ����� �־�����. �迭�� ����ִ� ������ ������ �ִ� 228�̴�.

���
���� 0�� �Ǵ� ���� ������ ����Ѵ�.

Ǯ��:
��� ȣ���� �̿��� ���Ʈ������ �ذ��Ϸ��ϸ� 4000 * 4000 * 4000 * 4000 �̹Ƿ� �ð��ʰ��� ���ϴ�.
����, A�� B�� ���� 4000 * 4000 �迭, C�� D�� ���� 4000 * 4000 �迭 �� ���� ������ �����ؾ� �մϴ�.

�� �迭 ��� ������������ ������ ��(N logN) �� �迭�� �������� ��� �ٸ� �迭 ���� ���� �̺� Ž������ 0�� �Ǵ� ���� ã����
�ƽ��ƽ��ϰ� �ð��� ����˴ϴ�.

��, -99 �� 0���� ���� �� �ִ� ���� 99�ε� �� ���� ã�� ���� -99�� ��ȣ�� �ٲٰ�, -1 �� ���� �� lower_bound�� 98���� ū ���� ������ �ٷ� ��
��ġ�� ���Խ��ϴ�. �׸��� 99�� ���� ���� �� �ֱ� ������ 99�� ������ ��ġ�� lower_bound�� ������ ��, �ش� ������ŭ�� ī��Ʈ���ָ� �˴ϴ�.
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
int a[4001];
int b[4001];
int c[4001];
int d[4001];
ll arr1[16000002];
ll arr2[16000002];

int lower_bound(int s, int e, ll v) {
	while (s < e) {
		int mid = (s + e) / 2;

		if(arr2[mid] > v){
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

	for (int i = 0; i < n; i++)
	{
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	}

	int idx = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr1[idx] = a[i] + b[j];
			arr2[idx++] = c[i] + d[j];
		}
	}

	sort(arr1, arr1 + n * n);
	sort(arr2, arr2 + n * n);

	ll cnt = 0;

	for (int i = 0; i < n * n; i++)
	{
		int idx_s = lower_bound(0, n * n - 1, -(arr1[i]) - 1);	//ã�� ���� ���� ��ġ
		int idx_e = lower_bound(0, n * n - 1, -(arr1[i]));	//ã�� ���� ������ ��ġ

		if (arr2[idx_s] == -arr1[i]) {
			if (idx_e == n * n - 1)		
				idx_e++;
			cnt += (idx_e - idx_s);
		}
	}

	cout << cnt;

}