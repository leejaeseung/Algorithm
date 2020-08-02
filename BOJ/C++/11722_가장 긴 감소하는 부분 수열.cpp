/*
����
���� A�� �־����� ��, ���� �� �����ϴ� �κ� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

���� ���, ���� A = {10, 30, 10, 20, 20, 10} �� ��쿡 ���� �� �����ϴ� �κ� ������ A = {10, 30, 10, 20, 20, 10}  �̰�, ���̴� 3�̴�.

�Է�
ù° �ٿ� ���� A�� ũ�� N (1 �� N �� 1,000)�� �־�����.

��° �ٿ��� ���� A�� �̷�� �ִ� Ai�� �־�����. (1 �� Ai �� 1,000)

���
ù° �ٿ� ���� A�� ���� �� �����ϴ� �κ� ������ ���̸� ����Ѵ�.

Ǯ��:
LIS �⺻ �����̴�.
*/
#include<iostream>
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
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vii vector<pii>
#define IMAX 2000000001
#define LMAX 1000000000000000000
#define DMAX 0xFFFFFFFFFFFFF
int mv1[4] = { 0, 1, 0, -1 };
int mv2[4] = { 1, 0, -1, 0 };
int mv_all1[8] = { 0, 1, 0, -1, -1, -1, 1, 1 };
int mv_all2[8] = { 1, 0, -1, 0 , -1, 1, -1, 1 };

int n;
int arr[1001];
vector<int> dp;

int lo_bound(int s, int e, int v) {
	while (s < e) {
		int mid = (s + e) / 2;

		if (dp[mid] > v) {
			s = mid + 1;
		}
		else {
			e = mid;
		}
	}

	return s;
}

int main(void) {
	FIO;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	dp.push_back(arr[0]);

	for (int i = 1; i < n; i++)
	{
		if (dp[dp.size() - 1] <= arr[i]) {
			dp[lo_bound(0, dp.size() - 1, arr[i])] = arr[i];
		}
		else {
			dp.push_back(arr[i]);
		}
	}

	cout << dp.size();
}