/*
����
�Ѽ��� 2���� �迭 (�׻� 2^N * 2^N ũ���̴�)�� Z������� Ž���Ϸ��� �Ѵ�. ���� ���, 2*2�迭�� ���� ��ĭ, ������ ��ĭ, ���� �Ʒ�ĭ, ������ �Ʒ�ĭ ������� �湮�ϸ� Z����̴�.



����, 2���� �迭�� ũ�Ⱑ 2^N * 2^N�� ���� ���� �ִ� ĭ�� �ϳ��� �ƴ϶��, �迭�� 4��� �� �Ŀ� (ũ�Ⱑ ���� 2^(N-1)��) ��������� ������� �湮�Ѵ�.

���� ���� 2^2 * 2^2 ũ���� �迭�� �湮�� �����̴�.



N�� �־����� ��, (r, c)�� �� ��°�� �湮�ϴ��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

���� �׸��� N=3�� ���� ���̴�.



�Է�
ù° �ٿ� N r c�� �־�����. N�� 15���� �۰ų� ���� �ڿ����̰�, r�� c�� 0���� ũ�ų� ����, 2^N-1���� �۰ų� ���� �����̴�

���
ù° �ٿ� ������ ������ ����Ѵ�.

Ǯ��:
ó���� �� ������ ���� size�� 2�� ��쿡 Z �ڷ� Ž���� �Ź� ���־��µ�, ����� ������ �ð��� �ſ� ���� �ɷȽ��ϴ�.

������ Ž���ϱ� ����, �ش� ������ r,c �� �������� �ʴ´ٸ�(������ üũ) �ش� ���� ũ�⸸ŭ ī��Ʈ���� �÷��ֱ⸸ �ϸ� �˴ϴ�.
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
int mv1[4] = { 0, 0, 1, 1 };
int mv2[4] = { 0, 1, 0, 1 };

int n, r, c, N;
int cnt = 0;

void traverse(int x, int y, int size) {

	if (!(x <= r && r < x + size && y <= c && c < y + size)) {
		cnt += size * size;
		return;
	}

	if (size == 2) {
		for (int i = 0; i < 4; i++)
		{
			int now_x = x + mv1[i];
			int now_y = y + mv2[i];

			if (now_x == r && now_y == c) {
				cout << cnt;
				exit(0);
			}
			cnt++;
		}
	}
	else{
		int mid = size / 2;

		traverse(x, y, size / 2);
		traverse(x, y + mid, size / 2);
		traverse(x + mid, y, size / 2);
		traverse(x + mid, y + mid, size / 2);
	}
}

int main(void) {
	FIO;

	cin >> n >> r >> c;

	N = pow(2, n);

	traverse(0, 0, N);
}