/*
����
N��N���� ���� N��N ũ���� ǥ�� ä���� �ִ�. (x1, y1)���� (x2, y2)���� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�. (x, y)�� x�� y���� �ǹ��Ѵ�.

���� ���, N = 4�̰�, ǥ�� �Ʒ��� ���� ä���� �ִ� ��츦 ���캸��.

1	2	3	4
2	3	4	5
3	4	5	6
4	5	6	7
���⼭ (2, 2)���� (3, 4)���� ���� ���ϸ� 3+4+5+4+5+6 = 27�̰�, (4, 4)���� (4, 4)���� ���� ���ϸ� 7�̴�.

ǥ�� ä���� �ִ� ���� ���� ���ϴ� ������ �־����� ��, �̸� ó���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ǥ�� ũ�� N�� ���� ���ؾ� �ϴ� Ƚ�� M�� �־�����. (1 �� N �� 1024, 1 �� M �� 100,000) ��° �ٺ��� N���� �ٿ��� ǥ�� ä���� �ִ� ���� 1����� ���ʴ�� �־�����. ���� M���� �ٿ��� �� ���� ���� x1, y1, x2, y2 �� �־�����, (x1, y1)���� (x2, y2)�� ���� ���� ����ؾ� �Ѵ�. ǥ�� ä���� �ִ� ���� 1,000���� �۰ų� ���� �ڿ����̴�. (x1 �� x2, y1 �� y2)

���
�� M�ٿ� ���� (x1, y1)���� (x2, y2)���� ���� ���� ����Ѵ�.
Ǯ��:
2���� prefix sum ����
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

int n, m;
int sum[1025][1025];

int main(void) {
	FIO;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			cin >> sum[i][j];
			sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
		}

	while (m--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		cout << sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1] << "\n";
	}
}