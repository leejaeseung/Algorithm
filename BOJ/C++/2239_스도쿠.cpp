/*
����
������� �ſ� ������ ���� �����̴�. 9��9 ũ���� ���尡 ���� ��, �� ��� �� ��, �׸��� 9���� 3��3 ũ���� ���忡 1���� 9������ ���ڰ� �ߺ� ���� ��Ÿ������ ���带 ä��� �ȴ�. ���� ��� ������ ����.



�� �׸��� �� �ߵ� ������ ������ Ǭ ����̴�. �� �࿡ 1���� 9������ ���ڰ� �ߺ� ���� ������, �� ���� 1���� 9������ ���ڰ� �ߺ� ���� ������, �� 3��3¥�� �簢��(9���̸�, ������ ����� ǥ�õǾ���)�� 1���� 9������ ���ڰ� �ߺ� ���� ������ �����̴�.

�ϴ� �� ������ ������ �־����� ��, ���� ������ ���α׷��� �ۼ��Ͻÿ�.

�Է�
9���� �ٿ� 9���� ���ڷ� ���尡 �Էµȴ�. ���� ���ڰ� ä������ ���� ĭ���� 0�� �־�����.

���
9���� �ٿ� 9���� ���ڷ� ���� ����Ѵ�. ���� ���� �� �ִٸ� �� �� ���������� �ռ��� ���� ����Ѵ�. ��, 81�ڸ��� ���� ���� ���� ��츦 ����Ѵ�.

Ǯ��:
��ǥ i,y�� �� v �� ���Ͽ� 
�ش� �࿡ v�� �����ϴ��� ���� = row[i][v]
�ش� ���� v�� �����ϴ��� ���� = col[j][v]
�ش� �簢���� v�� �����ϴ��� ���� = box[(i / 3) * 3 + j / 3][v]
�� üũ�ؾ� �մϴ�.

map �� 0��(���� ���� ���� ����) �ε����� ã�� 1~9 ���� �־��, ���� ��ǥ�� �Ѱ��ָ� �����մϴ�.
*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<string>
#include<vector>
#include<queue>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>

bool row[9][10];
bool col[9][10];
bool box[9][10];
int map[9][9];
int cnt = 0;

void recul(int x, int y, int c) {

	int next_x = x;
	int next_y = y + 1;
	if (next_y == 9) {
		next_x++;
		next_y = 0;
	}

	while (map[next_x][next_y] != 0) {
		next_y++;
		if (next_y == 9) {
			next_x++;
			next_y = 0;
		}
	}

	if (c == cnt) {
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				cout << map[i][j];
			}
			cout << '\n';
		}
		exit(0);
	}

	for (int k = 1; k < 10; k++)
	{
		if (!row[next_x][k] && !col[next_y][k] && !box[(next_x / 3) * 3 + next_y / 3][k]) {
			map[next_x][next_y] = k;
			row[next_x][k] = true;
			col[next_y][k] = true;
			box[(next_x / 3) * 3 + next_y / 3][k] = true;
			recul(next_x, next_y, c + 1);
			map[next_x][next_y] = 0;
			row[next_x][k] = false;
			col[next_y][k] = false;
			box[(next_x / 3) * 3 + next_y / 3][k] = false;
		}
	}
}

int main(void) {
	FIO;

	for (int i = 0; i < 9; i++)
	{
		string str;
		cin >> str;

		for (int j = 0; j < 9; j++)
		{
			int v = str[j] - '0';

			map[i][j] = v;
			row[i][v] = true;
			col[j][v] = true;
			box[(i / 3) * 3 + j / 3][v] = true;
			if (v == 0)
				cnt++;
		}
	}

	recul(0, -1, 0);
}