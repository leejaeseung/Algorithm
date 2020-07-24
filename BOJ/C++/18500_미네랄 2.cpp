/*
����
â���� ����� �� ������ ���� �������� �����ϰ� �ִ�. �� ����� ����⸦ ���ο��� ������ ����� �̿��� ������ ���������� �����ϱ�� �ߴ�. �ο��� �������� ��������. �������� �̳׶��� ����Ǿ� ������, ���� ����Ⱑ �̳׶��� �ı��� ���� �ִ�.

������ R�� C���� ��Ÿ�� �� ������, R��Cĭ���� �̷���� �ִ�. �� ĭ�� ����ְų� �̳׶��� �����ϰ� ������, �� ���� �� �ϳ��� ������ �̳׶��� ���Ե� �� ĭ�� ���� Ŭ�������̴�.

â���� ������ ���ʿ� ���ְ�, ����� �����ʿ� ���ִ�. �� ����� ���� �����ư��� ����⸦ ������. ���븦 ������ ���� ���� ���̸� ���ؾ� �Ѵ�. ����� ���� ������ �̷�� ���ư���.

���밡 ���ư��ٰ� �̳׶��� ������, �� ĭ�� �ִ� �̳׶��� ��� �ı��ǰ� ����� �� �ڸ����� �̵��� �����.

�̳׶��� �ı��� ���Ŀ� ���� Ŭ�����Ͱ� �и��� ���� �ִ�. ���Ӱ� ������ Ŭ�����Ͱ� �� �ִ� ��쿡�� �߷¿� ���ؼ� �ٴ����� �������� �ȴ�. �������� ���� Ŭ�������� ����� ������ �ʴ´�. Ŭ�����ʹ� �ٸ� Ŭ�����ͳ� ���� ������ ������ �Լ��ؼ� ��������. Ŭ�����ʹ� �ٸ� Ŭ������ ���� ������ �� �ְ�, �� ���Ŀ��� �������� �ȴ�.

������ �ִ� �̳׶��� ���� �� ����� ���� ������ ���̰� �־�����. ��� ���븦 ������ �� ���Ŀ� �̳׶� ����� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ������ ũ�� R�� C�� �־�����. (1 �� R,C �� 100)

���� R�� �ٿ��� C���� ���ڰ� �־�����, '.'�� �� ĭ, 'x'�� �̳׶��� ��Ÿ����.

���� �ٿ��� ���븦 ���� Ƚ�� N�� �־�����. (1 �� N �� 100)

������ �ٿ��� ���븦 ���� ���̰� �־�����, �������� ���еǾ��� �ִ�. ��� ���̴� 1�� R�����̸�, ���� 1�� ����� ���� �ٴ�, R�� ���� ���� �ǹ��Ѵ�. ù ��° ����� ���ʿ��� ���������� ��������, �� ��°�� �����ʿ��� ��������, �̿� ���� ������ �����ư��� ������.

���߿� �� �ִ� �̳׶� Ŭ�����ʹ� ������, �� �� �Ǵ� �� �̻��� Ŭ�����Ͱ� ���ÿ� �������� ��쵵 ����.

���
�Է� ���İ� ���� �������� �̳׶� ����� ����Ѵ�.

Ǯ��:
������ ��ٷο� DFS Ž�� �����Դϴ�.

�Ź� ���밡 �̳׶��� ���� ������ �� ���� Ŭ�����͸� ������ �մϴ�.
�ϳ��� �ٴڿ� �پ��ִ� Ŭ������, �������� �������� Ŭ������.
(ó���� ���밡 ���� �̳׶��� �ֺ� Ŭ�����Ϳ� ���� �����µ�, �̳׶��� ����Ǿ� ���� �ʾƵ� �ٴڿ� �پ��ִ� Ŭ�����Ͱ� ���� �� �ֽ��ϴ�.)

�ݷ�

9 8
........
...xxx..
.xxx....
.x.x.xxx
.x.x...x
.x.xxx.x
.x.....x
.x.....x
.xxx...x
1
7

����

........
........
...xxx..
.xxx.xxx
.x.x...x
.x.x...x
.x.xxx.x
.x.....x
.xxx...x

�� ���� Ŭ�����ͷ� �����ٸ�, �������� Ŭ�����Ϳ� ���� �������� �Ÿ��� �ּҰ��� ���� �� �� �Ʒ��ʺ��� �ش� �Ÿ���ŭ �Ű��ָ� �˴ϴ�.

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
int mv1[4] = { 0, 1, 0, -1 };
int mv2[4] = { 1, 0, -1, 0 };

int R, C;
char maps[101][101];
bool visit[101][101];
bool cluster_check[2];
char cluster[101][101][2];

int main(void) {
	FIO;

	cin >> R >> C;

	for (int i = 0; i < R; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < C; j++)
		{
			maps[i][j] = str[j];
		}
	}

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int h;
		int turn = i % 2;
		cin >> h;
		h = R - h;

		stack<pii> st;

		for (int j = 0; j < 101; j++)
		{
			for (int k = 0; k < 101; k++)
			{
				visit[j][k] = false;
				cluster[j][k][0] = '.';
				cluster[j][k][1] = '.';
			}
		}

		for (int j = 0; j < 2; j++)
		{
			cluster_check[j] = false;
		}

		pii mineral = make_pair(-1, -1);

		//����, ������
		if (turn == 0) {
			for (int j = 0; j < C; j++)
			{
				if (maps[h][j] == 'x') {
					mineral = make_pair(h, j);
					break;
				}
			}
		}
		else {
			for (int j = C - 1; j >= 0; j--)
			{
				if (maps[h][j] == 'x') {
					mineral = make_pair(h, j);
					break;
				}
			}
		}

		//���밡 �ƹ��͵� �μ��� �ʾҴٸ� continue
		if (mineral.first == -1)	continue;

		maps[mineral.first][mineral.second] = '.';

		int c_idx = -1;

		for (int j = 0; j < 4; j++)
			//���� �̳׶� �ֺ��� ���� Ŭ�����͸� ����
		{
			int next_x = mineral.first + mv1[j];
			int next_y = mineral.second + mv2[j];

			if (next_x < 0 || next_y < 0 || next_x >= R || next_y >= C)	continue;
			if (maps[next_x][next_y] == 'x') {
				if (!visit[next_x][next_y]) {
					st.push(make_pair(next_x, next_y));
					c_idx++;
				}

				while (!st.empty()) {
					//Ŭ������ dfs
					int nowx = st.top().first;
					int nowy = st.top().second;
					st.pop();

					visit[nowx][nowy] = true;
					cluster[nowx][nowy][c_idx] = 'x';

					for (int k = 0; k < 4; k++)
					{
						int nextx = nowx + mv1[k];
						int nexty = nowy + mv2[k];

						if (nextx < 0 || nexty < 0 || nexty >= C)	continue;
						if (nextx >= R) {
							//�ٴ��� ����
							cluster_check[c_idx] = true;
						}
						else if (maps[nextx][nexty] == 'x' && !visit[nextx][nexty]) {
							st.push(make_pair(nextx, nexty));
						}
					}
				}
			}
		}

		for (int j = 0; j < 2; j++)
		{
			if (!cluster_check[j]) {
				//�ٴ��� �� ���� Ŭ������(�������� Ŭ������)
				int minLeng = 200;

				//map�� �ִ� �������� Ŭ�����Ͱ� �ƴ� ��� Ŭ�����͸� üũ��
				for (int k = 0; k < R; k++)
				{
					for (int l = 0; l < C; l++)
					{
						if (!visit[k][l] && maps[k][l] == 'x') {
							cluster[k][l][(j + 1) % 2] = 'x';
						}
					}
				}

				for (int k = 0; k < R; k++)
				{
					for (int l = 0; l < C; l++)
					{

						if (cluster[k][l][j] == 'x') {
							int ground = R - 1;

							for (int c = k + 1; c < R; c++)
							{
								if (cluster[c][l][(j + 1) % 2] == 'x') {
									ground = c - 1;
									break;
								}
							}

							minLeng = min(minLeng, ground - k);
							//������ �ּҰ� ����
						}
					}
				}

				//Ŭ�������� �� �Ʒ����� �Ű���
				for (int k = R - 1; k >= 0; k--)
				{
					for (int l = 0; l < C; l++)
					{
						if (cluster[k][l][j] == 'x') {
							maps[k][l] = '.';
							maps[k + minLeng][l] = 'x';
						}
					}
				}
			}
		}
	}

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cout << maps[i][j];
		}
		cout << "\n";
	}
}