/*
����
���� �� �� ���� ��ģ �κ��� ������� �ִ�. �׸��� �� �κ��� N���� �ൿ�� ���� ���̴�.

�� �ൿ���� �κ��� 4���� ���� �߿� �ϳ��� ���Ƿ� �����Ѵ�. �׸��� �� �������� �� ĭ �̵��Ѵ�.

�κ��� ���� ���� �� ������ ���� �̵����� ���� ��, �κ��� �̵� ��ΰ� �ܼ��ϴٰ� �Ѵ�. (�κ��� �����ϴ� ��ġ�� ó�� �湮�� ���̴�.) �κ��� �̵� ��ΰ� �ܼ��� Ȯ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�. ���� ���, EENE�� ENW�� �ܼ�������, ENWS�� WWWWSNE�� �ܼ����� �ʴ�. (E�� ��, W�� ��, N�� ��, S�� ��)

�Է�
ù° �ٿ� N, �������� �̵��� Ȯ��, �������� �̵��� Ȯ��, �������� �̵��� Ȯ��, �������� �̵��� Ȯ���� �־�����. N�� 14���� �۰ų� ���� �ڿ����̰�,  ��� Ȯ���� 100���� �۰ų� ���� �ڿ��� �Ǵ� 0�̴�. �׸���, ������������ �̵��� Ȯ���� ��� ���ϸ� 100�̴�.

���
ù° �ٿ� �κ��� �̵� ��ΰ� �ܼ��� Ȯ���� ����Ѵ�. ����/��� ������ 10-9 ���� ����Ѵ�.

Ǯ��:
�ִ� �̵� ���� �Ÿ��� 14ĭ�̹Ƿ� ������ 50 x 50 �� ���� ����� �湮 üũ�� �ϸ鼭
dfs�� Ž���Ѵ�.

��ΰ� �ܼ��� ��츸 Ȯ���� ���� ���� Ȯ���� ����ذ��� �ȴ�.
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
int mv1[4] = { 0, 0, 1, -1 };
int mv2[4] = { 1, -1, 0, 0 };
int mv_all1[8] = { 0, 1, 0, -1, -1, -1, 1, 1 };
int mv_all2[8] = { 1, 0, -1, 0 , -1, 1, -1, 1 };

int n;
double perc[4];
bool visit[50][50];

double moves(int x, int y, double nowP, int mv) {

	if (mv >= n)	return nowP;
	visit[x][y] = true;
	double ret = 0;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + mv1[i];
		int ny = y + mv2[i];

		if (visit[nx][ny] || perc[i] == 0)	continue;

		ret += moves(nx, ny, perc[i], mv + 1);
	}
	visit[x][y] = false;

	return ret * nowP;
}

int main(void) {
	FIO;

	cin >> n;

	for (int i = 0; i < 4; i++)
	{
		cin >> perc[i];
		perc[i] /= 100;
	}

	cout.precision(10);
	cout << moves(25, 25, 1, 0);
}