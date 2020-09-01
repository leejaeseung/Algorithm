/*
����
N���� ������ �̷���� ������ ���� ��, ũ�Ⱑ ����� �κм��� �߿��� �� ������ ���Ҹ� �� ���� ���� S�� �Ǵ� ����� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ������ ������ ��Ÿ���� N�� ���� S�� �־�����. (1 �� N �� 20, |S| �� 1,000,000) ��° �ٿ� N���� ������ �� ĭ�� ���̿� �ΰ� �־�����. �־����� ������ ������ 100,000�� ���� �ʴ´�.

���
ù° �ٿ� ���� S�� �Ǵ� �κм����� ������ ����Ѵ�.

Ǯ��:
������ ��� �κ� ������ ���ϴ� ������, ��Ʈ����ũ�� �̿��� ���Ʈ ������ Ǯ���ߴ�.

for (int i = all; i > 0; i = ((i - 1) & all))

�� �ݺ������� i�� ��� �κ� ������ ����� �������.(������ ������ 0���� �� ����)
*/
#include<iostream>
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
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vii vector<pii>
#define IMAX 2000000001
#define LMAX 1000000000000000000
#define DMAX 0xFFFFFFFFFFFFF
#define MOD 100007
int mv1[4] = { 0, 0, 1, -1 };
int mv2[4] = { 1, -1, 0, 0 };
int mv_all1[8] = { 0, 1, 0, -1, -1, -1, 1, 1 };
int mv_all2[8] = { 1, 0, -1, 0 , -1, 1, -1, 1 };

int n, s;
int arr[20];

int main(void) {
	FIO;

	cin >> n >> s;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int all = 0;

	for (int i = 0; i < n; i++)
	{
		all = (all << 1) + 1;
	}

	int ans = 0;

	for (int i = all; i > 0; i = ((i - 1) & all))
	{
		int sum = 0;

		for (int j = 0; j < n; j++)
		{
			if ((i & (1 << j)) > 0) {
				sum += arr[j];
			}

		}

		if (sum == s)
			ans++;
	}

	cout << ans;
}