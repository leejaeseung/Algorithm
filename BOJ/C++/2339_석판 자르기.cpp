/*
����
�ϳ� �̻��� �Ҽ����� ���� ����ü�� �̷���� ������ ���� �������� ������ �����ؼ�, ���� ���� ��ġ�� ���� �� �ֵ��� ������� �Ѵ�. �̶�, ���� ��ġ�� ������ ����� ���ؼ��� ������ ���� �������� ������, �� �������� �Ҽ����� ������ �ؾ��ϸ�, ���� ����ü�� �� �ϳ����� �����ϰ� �־�� �Ѵ�.

����, ���ǿ��� �Ҽ����� ������ ���ؼ��� �Ҽ����� �����ϰ� �ִ� ������ �߽����� �߶�� �Ǵµ�, ������ �� ������ ���� �Ǵ� ���� �������θ� ������ �ڸ� �� �ִ�. ������ �ڸ� ������ ������ �ڸ� ����� ���� �������δ� �ڸ� �� ����. (��, ó���� �ڸ� ���� ���ι����̳�, ���ι��� ��� �����ϴ�.)

���ǿ� �ִ� �Ҽ����� ���� ����ü�� ������ �־��� ��, �� ���ǿ��� �Ҽ������� ���ָ鼭 ������ ������, �� ������ �ݵ�� �ϳ��� ���� ����ü���� ��� �ֵ��� ������ ������ ����� ��� �� ���� �����ϴ��� ����Ͻÿ�.



���� �׸��� �ʱ� ������ ���¿��� �Ҽ����� �����ϸ鼭 ������ �߶��� ��, ���������� �������� ������ ����̴�. ȸ�� ���� �Ҽ����� �߽����� ���� �Ǵ� ���� �������� �ڸ� ��輱�̰�, ��� ���� ������ �ϳ����� �����ϰ� �ִ� �����̴�. ������ �ڸ� �� ����̳� ����� ������ �߷��� ����, �� ����� ����� ���� �������� �ڸ� �� ������, �� ���� ���������� ������� ���� �������� �ڸ� �� ����. �ܼ��ϰ� �ڸ��� ������ �ǹ��ϴ� ���� �ƴϹǷ�, ��� ������ ��� ����� ���� ���� �ִ�.

�߶��� ������ �ݵ�� �� ���� ������ �������� ���̾�� �Ѵ�. ���� ����ü�� �ִ� ���� �ڸ� �� ������, ���������� �������� ���ǿ� �� �� �̻��� ����ü�� ���� �� �ȴ�.

�Է�
ù ��° �ٿ��� ������ ũ�� N(1��N��20)�� ���´�. ���� �ٺ��� N�ٿ� ���ļ� ������ ���°� �Է����� ���´�. ���⼭ 1�� �Ҽ����� �ǹ��ϸ�, 2�� ���� ����ü, 0�� �Ҽ����� ��������ü�� �������� �ʴ� ���� �ǹ��Ѵ�. �̶�, ���� ����ü�� ���� 15���� ���� ������, �� �ٿ� �־����� ������ ������ ���� �ϳ��� �����Ѵ�.

���
������ ���� �ȿ� �Ҽ����� �����鼭 �� �ϳ��� ���� ����ü���� �ֵ��� �־��� ������ ���� ��, ��� �� ������ ��찡 �����ϴ����� ����Ͻÿ�. �̶� ������ ��찡 �������� ������ -1�� ����Ѵ�.

Ǯ��:
divide �Լ��� �簢���� ������ �ް�, �ش� ������ ���� ������ ����, �Ҽ����� ������ ���� 
������ ���� = 1, �Ҽ����� ���� = 0 �� ��쿡 1�� ��ȯ�մϴ�.(�ϼ��� ����)

���� �ƴ϶��, �ش� ������ �����ϴ� �Ҽ������� ��� ����, ���� dir ���� ���� �Ҽ����� �������� �ɰ��� 
���ο� ������ divide�� ȣ���մϴ�.

����� ���� ���� ���� �ڽ��� ȣ���� divide �� ���� ��ȯ���� ������ ��Ÿ�� �� �ֽ��ϴ�.
(���� ���·� ���� �� ���ٸ� 0�� ��ȯ, ���� ���� �� ���ٸ� 0 * x �� �˴ϴ�.)
��� �Ҽ����� ���� �� �ִ� divide�� ���� ��ȯ������ ��� ���� ��, ��ȯ�ϸ� �˴ϴ�.
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
int m[21][21];
vector<pii> bul_vt;

int divide(int x, int y, int size_x, int size_y, int dir) {

	if (x >= n || y >= n || size_x == 0 || size_y == 0)	return 1;
	//������ ��� ��� ������ �׵���� 1 ��ȯ.

	int bul_cnt = 0;
	int bo_cnt = 0;

	for (int i = x; i < x + size_x; i++)
	{
		for (int j = y; j < y + size_y; j++)
		{
			if (m[i][j] == 1) {
				bul_cnt++;
			}
			else if (m[i][j] == 2)
				bo_cnt++;
		}
	}

	if (bul_cnt == 0 && bo_cnt == 1) {
		//������ �� �ɰ� ���
		return 1;
	}
	else {
		int ret = 0;

		for (int i = 0; i < bul_vt.size(); i++)
		{
			int bul_x = bul_vt[i].first;
			int bul_y = bul_vt[i].second;
			bool flag = true;
			if (bul_x < x || bul_y < y || bul_x >= x + size_x || bul_y >= y + size_y)	continue;
			//�Ҽ����� ���� ������ �ִ��� �Ǵ�

			if (dir == 1) {
				//����
				for (int j = x; j < x + size_x; j++)
				{
					if (m[j][bul_y] == 2) {
						//������ �����Ѵٸ� ���� �� ����
						flag = false;
						break;
					}
				}
				if (flag)
					ret += (divide(x, y, size_x, bul_y - y, 2) * divide(x, bul_y + 1, size_x, y + size_y - bul_y - 1, 2));
					//�� ���� ��Ȳ�� ��� ���� ����
			}
			else if (dir == 2) {
				//����
				for (int j = y; j < y + size_y; j++)
				{
					if (m[bul_x][j] == 2) {
						//������ �����Ѵٸ� ���� �� ����
						flag = false;
						break;
					}
				}
				if (flag)
					ret += (divide(x, y, bul_x - x, size_y, 1) * divide(bul_x + 1, y, x + size_x - bul_x - 1, size_y, 1));
				//�� ���� ��Ȳ�� ��� ���� ����
			}
			else {
				//����, ����
				for (int j = x; j < x + size_x; j++)
				{
					if (m[j][bul_y] == 2) {
						//������ �����Ѵٸ� ���� �� ����
						flag = false;
						break;
					}
				}
				if (flag)
					ret += (divide(x, y, size_x, bul_y - y, 2) * divide(x, bul_y + 1, size_x, y + size_y - bul_y - 1, 2));
				//�� ���� ��Ȳ�� ��� ���� ����

				flag = true;
				for (int j = y; j < y + size_y; j++)
				{
					if (m[bul_x][j] == 2) {
						//������ �����Ѵٸ� ���� �� ����
						flag = false;
						break;
					}
				}
				if (flag)
					ret += (divide(x, y, bul_x - x, size_y, 1) * divide(bul_x + 1, y, x + size_x - bul_x - 1, size_y, 1));
				//�� ���� ��Ȳ�� ��� ���� ����
			}
		}

		return ret;
	}
}

int main(void) {
	FIO;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> m[i][j];
			if (m[i][j] == 1)
				bul_vt.push_back(make_pair(i, j));
		}
	}
	int ans = divide(0, 0, n, n, 0);
	if (ans == 0)
		cout << "-1";
	else
		cout << ans;
}