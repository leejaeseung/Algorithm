/*
����
N(1 �� N �� 50,000)���� ������ ���� ��, �ִ� L1-metric �Ÿ��� ã���ÿ�.

�� ���� ��ǥ�� (a, b), (c, d)�� ��, �� ���� L1-metric �Ÿ��� |a-c|+|b-d|�̴�.

�Է�
ù° �ٿ� N�� �־�����. ���� N���� �ٿ��� �� ���� x, y��ǥ�� �־�����. �� ��ǥ�� ������ -1,000,000�̻� 1,000,000�����̴�.

���
ù° �ٿ� �ִ� �Ÿ��� ����Ѵ�.

Ǯ��:
��� ���� �����ϴ� ���簢���� �ϳ� �׸��ϴ�.
�� ���簢���� �� �밢�� �� �ִ밪(L1-metric����)�� ���ϰ��� �ϴ� ���Դϴ�.

�� �������� ������ ���̹Ƿ� �� ���������� L1-metric�� ���� ����� ���� ã�� ���ο� ���������� �����Ͽ� Ǯ���մϴ�.
*/
#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<vector>
#include<queue>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>

int N;
vector<pii> point;

int L1met(int x1, int y1, int x2, int y2) {
	return abs(x1 - x2) + abs(y1 - y2);
}

int main(void) {
	FIO;

	cin >> N;
	int left = 1000001;
	int up = -1000001;
	int right = -1000001;
	int down = 1000001;

	for (int i = 0; i < N; i++)
	{
		int x, y;
		cin >> x >> y;
		point.push_back(make_pair(x, y));
		
		//���簢���� 4���� ���� ���մϴ�.
		left = min(left, x);
		up = max(up, y);
		right = max(right, x);
		down = min(down, y);
	}
	
	int leftup_dist = 3000000;
	int rightdown_dist = 3000000;
	int rightup_dist = 3000000;
	int leftdown_dist = 3000000;
	for (int i = 0; i < N; i++)
	{
		int x = point[i].first;
		int y = point[i].second;

		//�� ���������κ��� ���� ����� �������� �Ÿ��� ���մϴ�.
		leftup_dist = min(leftup_dist, L1met(left, up, x, y));
		rightdown_dist = min(rightdown_dist, L1met(right, down, x, y));
		rightup_dist = min(rightup_dist, L1met(right, up, x, y));
		leftdown_dist = min(leftdown_dist, L1met(left, down, x, y));
	}
	int res = 3000000;
	int half = abs(right - left) + abs(up - down);
	res = max(half - leftup_dist - rightdown_dist, half - rightup_dist - leftdown_dist);

	cout << res;
}