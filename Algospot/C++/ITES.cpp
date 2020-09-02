/*
����
��ȯ�̴� �ܰ迡�� ���ƿ��� ���ĸ� �����ϴ� ������ ��Ը� ������Ʈ, ITES@home�� �����ϰ� �ֽ��ϴ�. �ܰ迡�� ���ƿ��� ���Ĵ� ��ó���� ���� �� ���ڰ� [1,10000] ���� �ȿ� ���� �ڿ��� ������ �־����µ�, �� ���İ� ���� �ܼ��� ���������� �ƴϸ� �ǹ� �ִ� ������ ������ �ִ� �������� �ľ��ϰ� �ͽ��ϴ�. ��ȯ�̴� ������ �κ� ���� �߿� ���� K�� ���� ���� ���ٴ� ���� ��ġë���ϴ�. �κ� �����̶� ���ӵ� ������ �Ϻθ� ���մϴ�. ���� ��� ���� {1,4,2,1,4,3,1,6} ���� ���� 7 �� �κ� ������ ��� 5�� �ֽ��ϴ�. {1,4,2} , {4,2,1} , {2,1,4}, {4,3}, {1,6} �� �κ� �������� ���� ���ĵ� �ȴٴ� �� �����սô�.

K�� �ܰ��ο��� �ǹ� �ִ� �����ϱ��? ��ȯ���� ������ Ȯ���ϱ� ����, ���� N�� ��ȣ ����� �־��� �� ���� K�� �κ� ������ �� ���� �ִ��� ����ϴ� ���α׷��� �ۼ��ϼ���.

�Է� ����
�Է��� ũ�Ⱑ ū �����, �� ���������� ��ȣ ����� �Է¹޴� ��� ������ ���� ���� ���� ���α׷� ������ ���� �����մϴ�.

A[0] = 1983
A[i] = (A[i-1] * 214013 + 2531011) % 232
�� �� i(1 <= i <= N)��° �Է� ��ȣ�� A[i-1] % 10000 + 1�Դϴ�. ������ �ع��� �Է��� �����ϴ� ��İ��� �ƹ� ����� �����ϴ�. �� ��Ģ�� ������ ù 5���� ��ȣ�� ���� 1984, 8791, 4770, 7665, 3188�Դϴ�.

�Է�
�Է� ������ ù �ٿ��� �׽�Ʈ ���̽��� �� C (1 <= C <= 20)�� �־�����, �� �� C �ٿ� �� 2���� ������ K(1 <= K <= 5,000,000) �� N(1 <= N <= 50,000,000) �� �־����ϴ�.

���
�� �׽�Ʈ ���̽����� �� �ٿ� ù N ���� ��ȣ �� ���� K �� ������ ���� ����մϴ�.

Ǯ��:
ó���� A�� �� 5õ������ ��� ���س��� �����̵� ������� Ǫ�� �޸𸮰� ������.
�̸� ���س��� �ʰ�, ������ ���� �ϳ��� �Ź� �����ϰ�, ���� ����(�����̵� �������� ���� ����)
�� ť�� ������ �������� �ȴ�.
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
#define MOD 0x0100000000
int mv1[4] = { 0, 0, 1, -1 };
int mv2[4] = { 1, -1, 0, 0 };
int mv_all1[8] = { 0, 1, 0, -1, -1, -1, 1, 1 };
int mv_all2[8] = { 1, 0, -1, 0 , -1, 1, -1, 1 };

int t;

int main(void) {
	FIO;

	cin >> t;

	while (t--) {
		int k, n;
		cin >> k >> n;

		int s = 0, e = 0;
		ll sum = 0;
		int ans = 0;

		ll num = 1983;

		deque<int> dq;
		dq.push_back(num);

		for (int i = 0; i < n - 1; i++)
		{
			if (i == 0)
				sum = 1983;
			else
				sum += (num % 10000 + 1);

			while (!dq.empty() && sum > k) {
				sum -= dq.front();
				dq.pop_front();
			}

			if (sum == k)
				ans++;

			num = (num * 214013 + 2531011) % MOD;
			dq.push_back(num % 10000 + 1);
		}

		cout << ans << "\n";
	}
}