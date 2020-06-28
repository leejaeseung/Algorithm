/*
����
���� ó���ϴ� ���� ����п��� ����� �߿��� ���̴�. ����п��� N���� ���� ��ǥ�ϴ� �⺻ ��谪���� ������ ���� �͵��� �ִ�. ��, N�� Ȧ����� ��������.

������ : N���� ������ ���� N���� ���� ��
�߾Ӱ� : N���� ������ �����ϴ� ������ �������� ��� �� �߾ӿ� ��ġ�ϴ� ��
�ֺ� : N���� ���� �� ���� ���� ��Ÿ���� ��
���� : N���� ���� �� �ִ񰪰� �ּڰ��� ����
N���� ���� �־����� ��, �� ���� �⺻ ��谪�� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ���� ���� N(1 �� N �� 500,000)�� �־�����. �� ���� N���� �ٿ��� �������� �־�����. �ԷµǴ� ������ ������ 4,000�� ���� �ʴ´�.

���
ù° �ٿ��� �������� ����Ѵ�. �Ҽ��� ���� ù° �ڸ����� �ݿø��� ���� ����Ѵ�.

��° �ٿ��� �߾Ӱ��� ����Ѵ�.

��° �ٿ��� �ֺ��� ����Ѵ�. ���� �� ���� ������ �ֺ� �� �� ��°�� ���� ���� ����Ѵ�.

��° �ٿ��� ������ ����Ѵ�.

Ǯ��:
�϶�°� ���� ����..
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
priority_queue<int> pq;
int cnt[8003];

int main(void) {
	FIO;

	cin >> n;

	int sum = 0;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		sum += num;
		cnt[num + 4000]++;

		pq.push(num);
	}

	int maxV = pq.top();

	for (int i = 0; i < n / 2; i++)
	{
		pq.pop();
	}

	int mid = pq.top();

	while (pq.size() > 1) {
		pq.pop();
	}

	int minV = pq.top();	pq.pop();
	int maxCnt = 0;
	for (int i = 0; i < 8003; i++)
	{
		maxCnt = max(maxCnt, cnt[i]);
	}

	for (int i = 0; i < 8003; i++)
	{
		if (maxCnt == cnt[i]) {
			pq.push(-(i - 4000));
		}
	}

	int maxE = -pq.top();

	if (pq.size() > 1) {
		pq.pop();
		maxE = -pq.top();
	}

	int range = maxV - minV;
	double everage = (double)sum / (double)n;
	
	cout << round(everage) << "\n";
	cout << mid << "\n";
	cout << maxE << "\n";
	cout << range << "\n";
}