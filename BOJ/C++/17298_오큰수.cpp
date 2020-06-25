/*
����
ũ�Ⱑ N�� ���� A = A1, A2, ..., AN�� �ִ�. ������ �� ���� Ai�� ���ؼ� ��ū�� NGE(i)�� ���Ϸ��� �Ѵ�. Ai�� ��ū���� �����ʿ� �����鼭 Ai���� ū �� �߿��� ���� ���ʿ� �ִ� ���� �ǹ��Ѵ�. �׷��� ���� ���� ��쿡 ��ū���� -1�̴�.

���� ���, A = [3, 5, 2, 7]�� ��� NGE(1) = 5, NGE(2) = 7, NGE(3) = 7, NGE(4) = -1�̴�. A = [9, 5, 4, 8]�� ��쿡�� NGE(1) = -1, NGE(2) = 8, NGE(3) = 8, NGE(4) = -1�̴�.

�Է�
ù° �ٿ� ���� A�� ũ�� N (1 �� N �� 1,000,000)�� �־�����. ��°�� ���� A�� ���� A1, A2, ..., AN (1 �� Ai �� 1,000,000)�� �־�����.

���
�� N���� �� NGE(1), NGE(2), ..., NGE(N)�� �������� ������ ����Ѵ�.

Ǯ��:
���� �����ε�, �켱���� ť�ε� Ǯ�̰� ������ �����Դϴ�.
1��° ���Һ��� ������ �켱���� ť�� ������ Ǯ���մϴ�.

���� ���� ť�� �ֱ� ��, ť�� top(������������ �����մϴ�.) �� ���� �������� ������ ũ�ٸ�, �� ���� ��ū���̹Ƿ�
���� �� -> ť�� top���� �������ݴϴ�.
���� ������ ť�� top�� �۰ų� ������ ������ �ݺ��մϴ�.
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
int arr[1000001];
int value[1000001];
priority_queue<pii> pq;

int main(void) {
	FIO;

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int v;
		cin >> v;
		arr[i] = v;
		value[i] = -1;
	}

	pq.push(make_pair(-arr[1], 1));

	for (int i = 2; i <= n; i++)
	{
		int now = arr[i];

		while (!pq.empty() && now > -pq.top().first) {
			value[pq.top().second] = now;
			//��ū�� ����
			pq.pop();
		}
		pq.push(make_pair(-now, i));
	}

	for (int i = 1; i <= n; i++)
	{
		cout << value[i] << " ";
	}
}