/*
����
���� S�� � �� Sk�� �������� S1 < S2 < ... Sk-1 < Sk > Sk+1 > ... SN-1 > SN�� �����Ѵٸ�, �� ������ ������� �����̶�� �Ѵ�.

���� ���, {10, 20, 30, 25, 20}�� {10, 20, 30, 40}, {50, 40, 25, 10} �� ������� ����������,  {1, 2, 3, 2, 1, 2, 3, 2, 1}�� {10, 20, 30, 40, 20, 30} �� ������� ������ �ƴϴ�.

���� A�� �־����� ��, �� ������ �κ� ���� �� ������� �����̸鼭 ���� �� ������ ���̸� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ���� A�� ũ�� N�� �־�����, ��° �ٿ��� ���� A�� �̷�� �ִ� Ai�� �־�����. (1 �� N �� 1,000, 1 �� Ai �� 1,000)

���
ù° �ٿ� ���� A�� �κ� ���� �߿��� ���� �� ������� ������ ���̸� ����Ѵ�.

Ǯ��:
���� �� �κ� ���� ������ ��¦ �����ϸ� �Ǵ� ���������ϴ�.
������ �Ǵ� ���� 0~N ��°���� �ٲ㰡�� ������ ���� ���� �� �κ� ���� ����, �������� ���� ���� �� �κ� ���� ������ ���մϴ�.

�� ������ �� - 1(���� ���� �ߺ��ǹǷ�) �� �ִ밡 �Ǵ� ��찡 �����Դϴ�.
*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<vector>
#include<queue>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>

int N;
int arr[1001];
vector<int> left_dp;
vector<int> right_dp;

void BS(vector<int> &dp, int s, int e, int v) {
	while (s < e) {
		int mid = (s + e) / 2;

		if (dp[mid] <= v)
			e = mid;
		else
			s = mid + 1;
	}
	dp[s] = v;
}

int main(void) {
	FIO;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	int ans = 0;

	for (int center = 0; center < N; center++)
	{
		left_dp.push_back(arr[center]);
		right_dp.push_back(arr[center]);
		
		for (int i = center - 1; i >= 0 ; i--)
		{
			int now = arr[i];
			
			if (now >= left_dp.back()) {
				BS(left_dp, 0, left_dp.size() - 1, now);
			}
			else {
				left_dp.push_back(now);
			}
		}
		for (int i = center + 1; i < N; i++)
		{
			int now = arr[i];

			if (now >= right_dp.back()) {
				BS(right_dp, 0, right_dp.size() - 1, now);
			}
			else {
				right_dp.push_back(now);
			}
		}
		ans = max(ans, (int)(left_dp.size() + right_dp.size() - 1));

		left_dp.clear();
		right_dp.clear();
	}
	cout << ans;
}