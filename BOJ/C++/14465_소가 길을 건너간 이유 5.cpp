/*
����
��� ���� ���忡 ���� ���� �ִٰ� ������, ���� �׻Ӹ��� �ƴϴ�. �� ���� ������ ���� �ִµ�, 1������ N�������� ��ȣ�� ���� Ⱦ�ܺ��� N (1 �� N �� 100,000)���� �̷���� �ִ�. ������ �����ϱ� ���� ���� �� Ⱦ�ܺ����� ��ȣ���� ��ġ�� ���Ҵ�. �׷��� ��� ��, ������ ����� ���� ��� ��ȣ���� ��������. ���� ������ K���� ��ȣ���� �����ϵ��� ��ȣ���� �����ϰ� �ʹ�. �̹����� �츮�� ���� ��������.

�Է�
ù �ٿ� N, K, B (1 �� B,K �� N)�� �־�����. �� ���� B�ٿ��� ���峭 ��ȣ���� ��ȣ�� �ϳ��� �־�����.

���
���������� �۵��ϴ� ���� K���� ��ȣ���� �����Ϸ��� �ּ� �� ���� ��ȣ���� �����ؾ� �ϴ��� ����Ѵ�.

Ǯ��:
k �� ���̸� ���� �� �����͸� �� ĭ�� �Űܰ��� �ּ� ���� ������ ã�´�.
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
#define IMAX 2147483647
#define LMAX 1000000000000500000
#define DMAX 0xFFFFFFFFFFFFF
int mv1[4] = { 0, 1, -1, 0 };
int mv2[4] = { 1, 0, 0, -1 };

int n, k, b;
int broke[100001];

int main() {
	FIO;

	cin >> n >> k >> b;

	for (int i = 0; i < b; i++)
	{
		int v;
		cin >> v;
		broke[v] = 1;
	}

	int l = 1;
	int r = k;
	int brokeCnt = 0;
	int minBroke = IMAX;

	for (int i = 1; i <= k; i++)
	{
		if (broke[i]) {
			brokeCnt++;
		}
	}

	while (r <= n) {	
		minBroke = min(minBroke, brokeCnt);

		brokeCnt = brokeCnt + broke[++r] - broke[l++];
	}

	cout << minBroke;
}