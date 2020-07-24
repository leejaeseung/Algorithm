/*
����
�����̴� ������ ã�� ������ ���� ���� �ٴٰ� �׷��� �ִ� ������ ���.

������ N*M ũ���� ���簢�� ����̰�, ������ 1*1ũ���� ĭ���� ��x�� �Ǵ� ��.������ �ϳ��� ���� �ִ�.

�ٴٴ� ��.���� ���η� �Ǵ� ���η� �ִ�� ����Ǿ� �ִ� �׷��̴�.

���� ��x���� ����, ����, �Ǵ� �밢������ �ִ�� ����Ǿ� �ִ� �׷��̴�.

���� � ���� �ٸ� ���� �����ϰ� ���� �ʴ´ٸ�, �� ���� ���̰� 0�̴�. ���� � ��A�� �����ϰ� �ִ� ���߿� ���� ���̰� ���� ���� ���̰� K���, �� �� A�� ���̴� K+1�̴�.

�� A�� �� B�� �����Ѵٴ� ����, �ϴ� A�� B�� �ٸ���, �� B�� ��� ������ ����ص� A�� ������ ���� �� ���� ���̴�. �̶� �밢������ �̵��� �Ұ����ϴ�.

������ ���� ������ ����.

xxx.x...xxxxx        000.0...11111
xxxx....x...x        0000....1...1
........x.x.x        ........1.4.1
..xxxxx.x...x        ..55555.1...1
..x...x.xxx.x        ..5...5.111.1
..x.x.x...x..        ..5.3.5...1..
..x...x...xxx        ..5...5...111
...xxxxxx....        ...555555....
x............        2............
���� �� 6���� �ִ�. ���̰� 0�� ���� 5���̴�. (0~4) �׸���, ���̰� 1�� ���� 1�� �ִ�. (5) 3�� ������ ����ؼ� 5�� ���� ������ ���� �� ���� ������ ��5�� ��3�� �����ϰ� �ִ� ���̴�. ������, ��4���� ����ؼ� ��1�� ���� �� �����Ƿ� ,��1�� ��4�� �����ϰ� �ִ� ���� �ƴϴ�.

������ �־����� ��, ���̰� 0�� ���� �������� ���̰� M�� ���� ���������� ���ʴ�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�. M�� ������ �ִ� �� �߿��� ���� ���� �����̴�.

�Է�
ù° �ٿ� N�� M�� �־�����. N�� M�� 50���� �۰ų� ���� �ڿ����̴�. ��° �ٺ��� N���� �ٿ� ���� ������ �־�����.

���
ù° �ٿ� ���̰� 0�� ���� ����, ���̰� 1�� ���� ����, ��, ���̰� M�� ���� ���� ���� �������� �����ؼ� ����Ѵ�. ���� ���� �ϳ��� ���� ���� -1�� ����Ѵ�.

Ǯ��:
���� ���ǿ� ���� ��� ���� ��ȣ�� �ű�ϴ�.(dfs�� �ش� ���� ����� ��� x�� ��ȣ�� �ű�ϴ�.)
�� �� �翬�ϰԵ� � �� A�� �� B�� ���Եȴٸ�, (A�� ��ȣ) > (B�� ��ȣ) �� �ǰ� �˴ϴ�.
(�� �κ��� ���� dfs�� ���� �̹� ��ȣ�� �Ű��� �ֱ� ����)

���� � ���� ���� ������ �����ϰ� �ִ� ��(parent) = ������ �� �ִ� ���� ��ȣ �� �ּ� ��
�� �˴ϴ�.
(Ž�� �� ���� ��� ���� -1�� �� �־����ϴ�.)

��� ���� ���� parent�� �������� ������ child�� ��� �޾��ְ�, child �� ���� ���� child�� ���̰� �ش� ����
���̰� �˴ϴ�.
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
int mv_all1[8] = { 0, 1, 0, -1, -1, -1, 1, 1 };
int mv_all2[8] = { 1, 0, -1, 0 , -1, 1, -1, 1};

int r, c;
char maps[51][51];
int color[51][51];
int height[3000];
bool check[3000];
bool visit[51][51];
int parent[3000];
vector<int> child[3000];

int dfs(int now) {

	int ret = -1;

	for (int i = 0; i < child[now].size(); i++)
	{
		ret = max(ret, dfs(child[now][i]));
	}

	return ret + 1;
}

int main(void) {
	FIO;

	cin >> r >> c;

	stack<pii> st;

	for (int i = 0; i < r; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < c; j++)
		{
			maps[i][j] = str[j];
			
			color[i][j] = -1;
		}
	}

	for (int i = 0; i < 3000; i++)
	{
		parent[i] = IMAX;
	}

	int clr = 0;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (maps[i][j] == 'x' && color[i][j] == -1) {
				st.push(make_pair(i, j));

				while (!st.empty()) {
					int nowx = st.top().first;
					int nowy = st.top().second;
					st.pop();

					color[nowx][nowy] = clr;
					//���� ��ȣ�� �ο�

					for (int k = 0; k < 8; k++)
					{
						int nextx = nowx + mv_all1[k];
						int nexty = nowy + mv_all2[k];

						if (nextx < 0 || nexty < 0 || nextx >= r || nexty >= c)	continue;
						if (maps[nextx][nexty] == 'x' && color[nextx][nexty] == -1) {
							st.push(make_pair(nextx, nexty));
						}
					}
				}
				clr++;
			}
		}
	}

	stack<pair<pii, int>> escape_st;
	vector<pii> start;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (maps[i][j] == 'x' && !check[color[i][j]]) {
				//���� ���� Ž���� ������ ���� �� �ϳ��� ���ÿ� ����
				check[color[i][j]] = true;
				start.push_back(make_pair(i, j));
			}
		}
	}

	for (int i = 0; i < start.size(); i++)
	{
		for (int j = 0; j < 51; j++)
		{
			for (int k = 0; k < 51; k++)
			{
				visit[j][k] = false;
			}
		}

		escape_st.push(make_pair(make_pair(start[i].first, start[i].second), color[start[i].first][start[i].second]));

		while (!escape_st.empty()) {
			int nowx = escape_st.top().first.first;
			int nowy = escape_st.top().first.second;
			int nowcolor = escape_st.top().second;
			escape_st.pop();

			visit[nowx][nowy] = true;

			for (int j = 0; j < 4; j++)
			{
				int nextx = nowx + mv1[j];
				int nexty = nowy + mv2[j];

				if (nextx < 0 || nexty < 0 || nextx >= r || nexty >= c) {
					//���� ��� �� parent�� -1
					parent[nowcolor] = -1;
					continue;
				}
				if (visit[nextx][nexty])	continue;
				
				if (maps[nextx][nexty] == 'x' && color[nextx][nexty] != nowcolor) {
					//parent ����
					parent[nowcolor] = min(parent[nowcolor], color[nextx][nexty]);
				}
				else {
					escape_st.push(make_pair(make_pair(nextx, nexty), nowcolor));
				}


			}
		}
	}

	for (int i = 0; i < clr; i++)
	{
		if (parent[i] != -1) {
			child[parent[i]].push_back(i);
		}
	}

	int maxH = -1;

	for (int i = 0; i < clr; i++)
	{
		int h = dfs(i);
		maxH = max(maxH, h);
		height[h]++;
	}

	if (maxH > -1) {
		for (int i = 0; i <= maxH; i++)
		{
			cout << height[i] << " ";
		}
	}
	else {
		cout << "-1";
	}
}