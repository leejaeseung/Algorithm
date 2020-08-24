/*
����
n���� ������ �̷���� ������ ������ �־�����. �츮�� �� �� ���ӵ� �� ���� ���� �����ؼ� ���� �� �ִ� �� �� ���� ū ���� ���Ϸ��� �Ѵ�. ��, ���� �� �� �̻� �����ؾ� �Ѵ�. ��, �������� ���� �ϳ� ������ �� �ִ�. (�������� �ʾƵ� �ȴ�)

���� �� 10, -4, 3, 1, 5, 6, -35, 12, 21, -1 �̶�� ������ �־����ٰ� ����. ���⼭ ���� �������� �ʾ��� ���� ������ 12+21�� 33�� ������ �ȴ�.

����, -35�� �����Ѵٸ�, ������ 10, -4, 3, 1, 5, 6, 12, 21, -1�� �ǰ�, ���⼭ ������ 10-4+3+1+5+6+12+21�� 54�� �ȴ�.

�Է�
ù° �ٿ� ���� n(1 �� n �� 100,000)�� �־����� ��° �ٿ��� n���� ������ �̷���� ������ �־�����. ���� -1,000���� ũ�ų� ����, 1,000���� �۰ų� ���� �����̴�.

���
ù° �ٿ� ���� ����Ѵ�.

Ǯ��:
����, �����ʿ������� �������� ��� ���ϴµ�
i ������ �������� ������ i�� ������ i���� �������� �ٽ� �����ϰԲ� �Ѵ�.

�Ź� �������� ���� ������ ��������� ������ or ���� ���� �ִ��� ��� �����Ѵ�.(�� ���� ���� �ִ�)

�������� ��� ���� �� ���� �� ������ ������, ������ �ش� index�� �������� �� + (�� �� * -2)(�ߺ����� 2�� �������Ƿ�)
�� �ִ��� ���Ѵ�.

��, n == 1 �� �� ��� �ϳ� ���� �ϹǷ� ����ó�� ���ش�.
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
int mv1[4] = { 0, 0, 1, -1 };
int mv2[4] = { 1, -1, 0, 0 };
int mv_all1[8] = { 0, 1, 0, -1, -1, -1, 1, 1 };
int mv_all2[8] = { 1, 0, -1, 0 , -1, 1, -1, 1 };

int n;
vector<int> vt;
int leftMax[100001];
int rightMax[100001];

int main(void) {
	FIO;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int v;
		cin >> v;
		vt.push_back(v);
	}

	int maxV = -IMAX;
	int sum = 0;

	int lm = -IMAX;
	int rm = -IMAX;

	for (int i = 0; i < n; i++)
	{
		int now = vt[i];

		sum += now;
		maxV = sum;

		if (sum - now < 0) {
			if (now >= 0) {
				maxV = now;
				sum = now;
			}
		}

		//���� ������ ����
		leftMax[i] = maxV;
		lm = max(lm, max(maxV, now));
	}
		
	maxV = -IMAX;
	sum = 0;

	for (int i = n - 1; i >= 0; i--)
	{
		int now = vt[i];

		sum += now;
		maxV = sum;

		if (sum - now < 0) {
			if (now >= 0) {
				maxV = now;
				sum = now;
			}
		}

		//������ ������ ����
		rightMax[i] = maxV;
		rm = max(rm, max(maxV, now));
	}

	int ans = -IMAX;

	ans = max(lm, rm);

	if (n > 1) {
		//��� �ϳ� �����Ѵ�.
		for (int i = 0; i < n; i++)
		{
			int now = vt[i];

			if (now < 0)
				ans = max(ans, leftMax[i] + rightMax[i] + abs(now) * 2);
		}
	}

	cout << ans;
}