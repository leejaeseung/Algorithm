/*
����
5��5 ũ���� �������� �ִ�. ������ ĭ���� ����(digit, 0���� 9����)�� ���� �ִ�. �� �������� ������ ��ġ���� �����ؼ�, ������ �ִ� �� �������� �ټ� �� �̵��ϸ鼭, �� ĭ�� �����ִ� ���ڸ� ���ʷ� ���̸� 6�ڸ��� ���� �ȴ�. �̵��� �� ������ �� �� ���ƴ� ĭ�� �ٽ� ���ĵ� �Ǹ�, 0���� �����ϴ� 000123�� ���� ���� ���� �� �ִ�.

�������� �־����� ��, ���� �� �ִ� ���� �ٸ� ���� �ڸ��� ������ ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
�ټ� ���� �ٿ� �ټ� ���� ������ �������� �־�����.

���
ù° �ٿ� ���� �� �ִ� ������ ������ ����Ѵ�.

Ǯ��:
���� Ž�� ���������ϴ�.
dfs�� Ȱ���ϸ� ������ Ǯ �� �ֽ��ϴ�.
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
#define vii vector<pii>
#define IMAX 2000000001
#define LMAX 100000000000000
#define DMAX 0xFFFFFFFFFFFFF
int mv1[4] = { 0, 0, 1, -1 };
int mv2[4] = { 1, -1, 0, 0 };

int maps[5][5];
map<string, bool> m;
int ans = 0;

void dfs(string now, int x, int y, int cnt) {

	if (cnt == 6) {
		if (!m[now]) {
			m[now] = true;
			ans++;
		}
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int nx = x + mv1[i];
		int ny = y + mv2[i];

		if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5)	continue;
		dfs(now + to_string(maps[nx][ny]), nx, ny, cnt + 1);
	}
}

int main(void) {
	FIO;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> maps[i][j];
		}
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			dfs(to_string(maps[i][j]), i, j, 1);
		}
	}
	cout << ans;
}