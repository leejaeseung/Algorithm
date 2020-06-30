/*
����
N��Nũ���� ��ķ� ǥ���Ǵ� ���̰� �ִ�. ������ �� ĭ���� -1, 0, 1�� �� �� �� �ϳ��� ����Ǿ� �ִ�. �츮�� �� ����� ������ ũ��� �ڸ����� �ϴµ�, �̶� ������ ��Ģ�� ���� �ڸ����� �Ѵ�.

���� ���̰� ��� ���� ���� �Ǿ� �ִٸ� �� ���̸� �״�� ����Ѵ�.
(1)�� �ƴ� ��쿡�� ���̸� ���� ũ���� 9���� ���̷� �ڸ���, ������ �߸� ���̿� ���ؼ� (1)�� ������ �ݺ��Ѵ�.
�̿� ���� ���̸� �߶��� ��, -1�θ� ä���� ������ ����, 0���θ� ä���� ������ ����, 1�θ� ä���� ������ ������ ���س��� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� N(1��N��3^7, N�� 3^k ��)�� �־�����. ���� N���� �ٿ��� N���� ������ ����� �־�����.

���
ù° �ٿ� -1�θ� ä���� ������ ������, ��° �ٿ� 0���θ� ä���� ������ ������, ��° �ٿ� 1�θ� ä���� ������ ������ ����Ѵ�.

Ǯ��:
https://www.acmicpc.net/problem/1992 ������ ����ϰ� Ǯ���Ͽ����ϴ�.
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
int square[2188][2188];
int ans1 = 0, ans2 = 0, ans3 = 0;		//-1, 0, 1

void divide(int x, int y, int size) {
	int cnt1 = 0, cnt2 = 0, cnt3 = 0;		//-1, 0, 1

	for (int i = x; i < x + size; i++)
	{
		for (int j = y; j < y + size; j++)
		{
			if (square[i][j] == -1) {
				cnt1++;
			}
			else if (square[i][j] == 0) {
				cnt2++;
			}
			else {
				cnt3++;
			}
		}
	}

	if (cnt1 == size * size) {
		ans1++;
	}
	else if (cnt2 == size * size) {
		ans2++;
	}
	else if (cnt3 == size * size) {
		ans3++;
	}
	else {
		int newSize = size / 3;

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				divide(x + i * newSize, y + j * newSize, newSize);
			}
		}
	}
}

int main(void) {
	FIO;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> square[i][j];
		}
	}

	divide(0, 0, n);

	cout << ans1 << "\n";
	cout << ans2 << "\n";
	cout << ans3 << "\n";
}