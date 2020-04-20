/*
����
10,000 ������ �ڿ����� �̷���� ���� N¥�� ������ �־�����. �� �������� ���ӵ� ������ �κ��� �߿� �� ���� S �̻��� �Ǵ� �� ��, ���� ª�� ���� ���̸� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� N (10 �� N < 100,000)�� S (0 < S �� 100,000,000)�� �־�����. ��° �ٿ��� ������ �־�����. ������ �� ���Ҵ� �������� ���еǾ��� ������, 10,000������ �ڿ����̴�.

���
ù° �ٿ� ���ϰ��� �ϴ� �ּ��� ���̸� ����Ѵ�. ���� �׷��� ���� ����� ���� �Ұ����ϴٸ� 0�� ����ϸ� �ȴ�.

Ǯ��:
�� ������ prefix Sum�� ���س���, ����, �� �����͸� ��ĭ�� �Űܰ��� �ش� ������ �κ� ���� S ���� Ŭ ������ ���� �����մϴ�.
���� �����Ͱ� �� �����ͺ��� Ŀ���� �ʰ� �����մϴ�.
*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<string>
#include<vector>
#include<queue>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>

int N, S;
int arr[100001];
long long sum[100001];
int ans = 100001;

int main(void) {
	FIO;

	cin >> N >> S;

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
		sum[i] = sum[i - 1] + arr[i];
	}
	int s = 1;
	int e = 1;

	while (s <= N) {
		long long nowSum = sum[e] - sum[s - 1];
		if (nowSum >= S) {
			ans = min(ans, e - s + 1);
		}
		if (e != N) {
			if (s == e) {
				e++;
				continue;
			}
			if (nowSum >= S) {
				s++;
			}
			else {
				e++;
			}
		}
		else {
			s++;
		}
	}
	if (ans == 100001)
		cout << "0";
	else
		cout << ans;
}