/*
����
SSR(A, B) = (sqrt(A) + sqrt(B))^2 �̴�.

�� ���� N, M�� �־����� ��, 1 �� A �� N, 1 �� B �� M �̸鼭 SSR(A, B)�� ������ (A, B) ���� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� N, M�� �־�����. (1 �� N, M �� 77,777)

���
ù° �ٿ� ������ ������ ����Ѵ�.

Ǯ��:
��Ʈ�� ������ ���ϴ� ���� x �� ����, x�� ¦�� �̷� �� �ִ� y �� ������
x * 1, x * 4, x * 9 ... ó�� x�� �������� ���� ���̴�.

���� 1 ~ 77777���� ��� �������� �ƴ� ���� a �� ���� 
a = b * root(c) ���� �ּ��� c ���� ���Ѵ�.(���� �� �ִ� ������ �� ���� ū ������ ������ �ȴ�.)

n �� m �� ū ��, ���� ������ �������� c * ������ �� �ּ� ���� ���� ���� ������ ī��Ʈ ���ָ� �ȴ�.
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

int main(void) {
	FIO;

	int n, m;
	cin >> n >> m;

	int mx = max(n, m);
	int mn = min(n, m);

	int ans = 0;

	for (int i = 1; i <= mx; i++)
	{
		int maxSq = 1;
		for (int j = 1; j * j <= i; j++)
		{
			if(i % (j * j) == 0)
				maxSq = max(maxSq, j * j);
		}

		for (int j = 1; j * j <= 77777; j++)
		{
			if (mn >= (i / maxSq) * (j * j))
				ans++;
			else
				break;
		}
	}

	cout << ans;
}