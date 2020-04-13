/*
����
������� �������� ���� ��� ����. N�� 3�� �ŵ�����(3, 9, 27, ...)�̶�� �� ��, ũ�� N�� ������ N��N ���簢�� ����̴�.

ũ�� 3�� ������ ����� ������ �ְ�, ����� ������ ��� ĭ�� ���� �ϳ��� �ִ� �����̴�.

***
* *
***
N�� 3���� Ŭ ���, ũ�� N�� ������ �������� ä���� ����� (N/3)��(N/3) ���簢���� ũ�� N/3�� �������� �ѷ��� �����̴�. ���� ��� ũ�� 27�� ������ ���� ��� 1�� ����.

�Է�
ù° �ٿ� N�� �־�����. N�� 3�� �ŵ������̴�. �� � ���� k�� ���� N=3k�̸�, �̶� 1 �� k < 8�̴�.

���
ù° �ٺ��� N��° �ٱ��� ���� ����Ѵ�.
*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<string.h>
#include<vector>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>

int N;
char map[3000][3000];

void recul(int now, int x, int y) {
	if (now == 1) {
		map[x][y] = '*';
		return;
	}
	
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i == 1 && j == 1)	continue;
			recul(now / 3, x + (now / 3) * i, y + (now / 3) * j);
		}
	}
}

int main(void) {
	FIO;

	cin >> N;

	for (int i = 0; i < 3000; i++)
	{
		for (int j = 0; j < 3000; j++)
		{
			map[i][j] = ' ';
		}
	}
	recul(N, 0, 0);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << map[i][j];
		}
		cout << "\n";
	}
}