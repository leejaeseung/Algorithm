/*
����
�ϳ��� ���� ������ �̿��Ͽ� ������ ���Ը� �����Ϸ��� �Ѵ�. �� ������ �� ���� ������ �����̳� �߸� �÷����� ���ð� �޷� �ְ�, ������ ���̴� ����. ����, ������ ���ʿ��� �����ߵ鸸 ���� �� �ְ�, �ٸ� �ʿ��� ���Ը� �����Ϸ��� ���Ǹ� �÷����� �� �ִ�.



���԰� ���� ������ N���� �����߰� �־��� ��, �� �ߵ��� ����Ͽ� ������ �� ���� ���� ���� ���� �� �ּڰ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

���� ���, ���԰� ���� 3, 1, 6, 2, 7, 30, 1�� 7���� �����߰� �־����� ��, �� �ߵ�� ������ �� ���� ���� ���� ���� �� �ּڰ��� 21�̴�.

�Է�
ù ° �ٿ��� �������� ������ ��Ÿ���� ���� ���� N�� �־�����. N�� 1 �̻� 1,000 �����̴�. ��° �ٿ��� �������� ���Ը� ��Ÿ���� N���� ���� ������ ��ĭ�� ���̿� �ΰ� �־�����. �� ���� ���Դ� 1�̻� 1,000,000 �����̴�.

���
ù° �ٿ� �־��� �ߵ�� ������ �� ���� ���� ���� ���� �� �ּڰ��� ����Ѵ�.

Ǯ��:
���԰� ���� ���� �ߺ��� �ϳ��� ���� �߸� ���� �׸����ϰ� Ǯ���մϴ�.

minWeight = ������� ���� �� �ִ� �ִ� ���� ���� �� �����ϰ�,
���� ���� ���԰� minWeight + 1 ���� ũ�� �ʴٸ�, minWeight�� ���� ���� ���Ը� �����ݴϴ�.

�ֳ��ϸ�, minWeight + 1 ���� ũ�� �ʴٴ� �ǹ̴� ���� minWeight���� ��� ���Ը� ���� �� �ִ� �����ε�,
���� ���� ���Կ� minWeight ������ ��� ������ ����ϸ� minWeight + (���� �� ����) ���� ��� Ŀ���� �����ϱ� �����Դϴ�.
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

int n;
priority_queue<int> pq;

int main(void) {
	FIO;

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		int v;
		cin >> v;

		pq.push(-v);
	}
	
	int minWeight = 0;

	while (!pq.empty()) {
		int nowWeight = -pq.top();	pq.pop();

		if (nowWeight <= minWeight + 1) {
			minWeight += nowWeight;
		}
		else {
			break;
		}
	}

	cout << minWeight + 1;
}