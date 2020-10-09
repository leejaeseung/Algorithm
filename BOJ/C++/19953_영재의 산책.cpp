/*
����
����� �˰��� ������ Ǫ�� ���� �����Ѵ�. ������ �� Ǯ���� ���ϴ� ����� ������ ���� ���� �� ��å�� �Ѵ�. ���õ� ������ ���� �ʾ� ����� ���׸� ��å�Ѵ�. ������ ���״� 2���� ��ǥ�� �̷���� �ִ�.

�ƹ� ��Ģ ���� �ȴ� ���� ��̷��� �ʴٰ� ���� ����� ������ ��Ģ�� ���� �ȱ�� �Ͽ���.

���� t�ʿ� v�� �ӷ����� �ȴ´ٸ� 1�� ���� v�� �ӷ����� �ȴ´�. �׸��� t+1�ʰ� �� ���� ���������� 90�� ȸ���� �� (v��m)%10�� �ӷ����� �ȴ´�. �ʱ� �ӷ� v0, m, �� ��å �ð� t�� �־����� ��, ������ ���� ��ġ�� ����Ͽ���. ������ ó�� ��ġ�� (0, 0)�̰�, ó�� ������ �����̴�.

������ y��ǥ�� Ŀ���� �����̰�, ������ x��ǥ�� Ŀ���� �����̴�.

�Է�
�ʱ� �ӷ� v0, m, �� ��å �ð� t�� �־�����.

���
��å�� ���� �� ������ ��ġ�� ����Ͽ���.

����
1 �� v0 �� 1,000
1 �� m �� 1,000
1 �� t �� 1,000,000,000

Ǯ��:
t �� 10���̹Ƿ� �� �ʸ��� �̵����ָ� �ð� �ʰ��� �� �� �ۿ� ����.
(v * m) % 10 �� ��Ģ�� Ȱ���ؾ� �Ѵ�.

���� ���� ������ �� ��� v, m �� � �����̴� ���� ��� ���� 4���� ���ϸ��� ������.
v = 1, m = 2 �� �� -> 2, 4, 8, 6
v = 123, m = 127 �� �� -> 1, 7, 9, 3

��, �� ó�� ���������� �̵��� �����ϸ� ���� �̵����ʹ� ��, ��, ��, �� �� ���������� �̵� �Ÿ��� �����ϴٴ� ���̴�.
ó�� �������� �̵��� �� �� ������ ���������� ���, ��, ��, ��, ������ ���� �� �� �� �� �ִ��� ���� ��
�̵� �Ÿ���ŭ ������ָ� �ȴ�.
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
int mv1[4] = { 0, 1, 0, -1 };
int mv2[4] = { 1, 0, -1, 0 };
int mv_all1[8] = { 0, 1, 0, -1, -1, -1, 1, 1 };
int mv_all2[8] = { 1, 0, -1, 0 , -1, 1, -1, 1 };

int v, m, t;
int dv[4];
int cnt[4];

int main(void) {
	FIO;

	cin >> v >> m >> t;

	int num = (v * m) % 10;

	for (int i = 0; i < 4; i++)
	{
		dv[i] = num;
		num = (num * m) % 10;
	}

	int x = 0, y = v;
	t--;

	for (int i = 0; i < 4; i++)
	{
		cnt[i] = (t - 1) / 4;
	}

	for (int i = 0; i <= (t - 1) % 4; i++)
	{
		cnt[i]++;
	}

	x += dv[0] * cnt[0] - dv[2] * cnt[2];
	y += dv[3] * cnt[3] - dv[1] * cnt[1];
	
	cout << x << " " << y;
}