/*
����
 'Dummy' ��� ���������� �ִ�. �� ���ӿ��� ���� ���ͼ� ���ٴϴµ�, ����� ������ �� ���̰� �þ��. ���� �̸����� ���ٴϴٰ� �� �Ǵ� �ڱ��ڽ��� ���� �ε����� ������ ������.

������ NxN ���簢 ���������� ����ǰ�, ��� ĭ���� ����� ������ �ִ�. ������ �����¿� ���� ���� �ִ�. ������ �����Ҷ� ���� ���� �������� ��ġ�ϰ� ���� ���̴� 1 �̴�. ���� ó���� �������� ���Ѵ�.

���� �� �ʸ��� �̵��� �ϴµ� ������ ���� ��Ģ�� ������.

���� ���� �����̸� �÷� �Ӹ��� ����ĭ�� ��ġ��Ų��.
���� �̵��� ĭ�� ����� �ִٸ�, �� ĭ�� �ִ� ����� �������� ������ �������� �ʴ´�.
���� �̵��� ĭ�� ����� ���ٸ�, �����̸� �ٿ��� ������ ��ġ�� ĭ�� ����ش�. ��, �����̴� ������ �ʴ´�.
����� ��ġ�� ���� �̵���ΰ� �־��� �� �� ������ �� �ʿ� �������� ����϶�.

�Է�
ù° �ٿ� ������ ũ�� N�� �־�����. (2 �� N �� 100) ���� �ٿ� ����� ���� K�� �־�����. (0 �� K �� 100)

���� K���� �ٿ��� ����� ��ġ�� �־����µ�, ù ��° ������ ��, �� ��° ������ �� ��ġ�� �ǹ��Ѵ�. ����� ��ġ�� ��� �ٸ���, �� �� �� ���� (1�� 1��) ���� ����� ����.

���� �ٿ��� ���� ���� ��ȯ Ƚ�� L �� �־�����. (1 �� L �� 100)

���� L���� �ٿ��� ���� ���� ��ȯ ������ �־����µ�,  ���� X�� ���� C�� �̷���� ������. ���� ���� �ð����κ��� X�ʰ� ���� �ڿ� ����(C�� 'L') �Ǵ� ������(C�� 'D')�� 90�� ������ ȸ����Ų�ٴ� ���̴�. X�� 10,000 ������ ���� �����̸�, ���� ��ȯ ������ X�� �����ϴ� ������ �־�����.

���
ù° �ٿ� ������ �� �ʿ� �������� ����Ѵ�.

Ǯ��:
�� ���� ��ȯ���� ���� �̵���Ű�� �����Ѵ�.
���� ũ�⸦ �ø��� ���̴� �� ���� �̿��� ������ ��ǥ�� map���� ���������� �ȴ�.
���� ��ȯ�� ��� ���� �� �ſ� ū ���� x�� �־� ���� ������ �ڵ��� �����.
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
#define pll pair<ll, ll>
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vii vector<pii>
#define IMAX 2000000001
#define LMAX 1000000000000000000
#define DMAX 0xFFFFFFFFFFFFF
#define MOD 100003
int mv1[4] = { 0, 1, 0, -1 };
int mv2[4] = { 1, 0, -1, 0 };
int mv_all1[8] = { 0, 1, 0, -1, -1, -1, 1, 1 };
int mv_all2[8] = { 1, 0, -1, 0 , -1, 1, -1, 1 };

int n, k, l;
int maps[101][101];
deque<pii> snake;

int main(void) {
	FIO;

	cin >> n >> k;

	for (int i = 0; i < k; i++)
	{
		int x, y;
		cin >> x >> y;
		maps[x][y] = -1;
	}

	pii head = { 1, 1 };
	snake.push_back(head);
	maps[1][1] = 1;
	int dir = 0;

	cin >> l;

	int ans = 0;

	for (int i = 0; i <= l; i++)
	{
		int x;
		char d;
		if(i < l)
			cin >> x >> d;
		else {
			x = 10001;
			d = 'L';
		}

		while(ans < x)
		{
			ans++;
			int nx = head.first + mv1[dir];
			int ny = head.second + mv2[dir];

			if (nx > n || ny > n || nx <= 0 || ny <= 0 || maps[nx][ny] == 1) {
				cout << ans;
				exit(0);
			}

			head = { nx, ny };
			snake.push_back(head);

			if (maps[nx][ny] == 0) {
				pii tail = snake.front();
				snake.pop_front();

				maps[tail.first][tail.second] = 0;
			}

			maps[nx][ny] = 1;
		}

		if (d == 'D') {
			dir = (dir + 1) % 4;
		}
		else {
			dir = (dir + 3) % 4;
		}
	}

}