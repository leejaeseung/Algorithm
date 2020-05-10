/*
����
"�Ǿ��� ��Ʋ���� ~�ź��� ��ȸ�� ���ݼ���~"�� ������ ���ݼ��� �Ǿ��� ���彺�丮�� ���� �����̴�. �� ������ ���� �߿��� �κ��� "��ȸ"�ε�, ���ݼ��� ���� ǰ���� ������ ����� ����� Ÿ�߸� �Ǿư� �԰� �� �� �ֱ� �����̴�. ���丮�� �ſ� ������ ������ ���� �����ϱ�� �ϰ�, �������� �� ������ ��ȸ ����� Ȯ���ش޶�� ��û�� �޾Ҵ�. �������� Ȯ���ؾ� �ϴ� ��ȸ�� ������ ����.

�������� 5��5 ���� ��� ������ ���� �ٸ� ��� 3���� ������� �־� �ְ� ǰ���� ��ź�� ������ �Ѵ�. ���� ��ȸ���� �غ����ָ�, ���� �� �ִ� ����� �ĺ��� 10�� �����̴�. �־��� ��� �� 3���� �� ��, ������ ���� ������ �� �־�� �Ѵ�.

������ �� ĭ���� ǰ���� ��Ÿ���� ���ڿ� ���Ҹ� ��Ÿ���� ���� ĥ���� �ִ�. �ʱ⿡�� ��� ĭ�� ǰ���� 0, ���Ҵ� ����̴�. ���� 4��4 ������� ��������, ����� i�� j������ 2���� ������ �ִ�.

ȿ��: ���� �� ĭ�� ǰ���� �ٲٴ� -9 �̻� 9 ������ ���� xi,j
����: ���� �� ĭ�� ���Ҹ� �ٲ� �� �ִ� �� ci,j (���� 'R', �Ķ� 'B', �ʷ� 'G', ��� 'Y', ��� 'W' �� �ϳ��̴�)
��Ḧ ������ ���� ���� 5��5 ���ڸ� ��� �� ����. ȸ���� �����ϳ�, ���ڿ� ���� �ʰ� ��￩ ���� ���� ����. ��Ḧ ������ ���� ��, ������ ���´� ������ ���� �ٲ��.

��ᰡ ��ġ���� �ʴ� ������ ����ĭ�� �ƹ��� ��ȭ�� ������ �ʴ´�.
��ᰡ ��ġ�� ������ ����ĭ�� �ִ� ǰ���� ���Ұ��� �ٲ� �� �ִ�.
������ ǰ���� ����� ȿ���� ��������. ���� ���� ���� ������ ��� 0����, 9 �ʰ��� ��� 9�� �ٲ��.
������ ���� ����� ���Ұ� ����� ��� �״��, �ƴ� ��� ����� ���ҿ� ���� ������ ĥ������.
��� 3���� ��� �־�߸� ��ź�� ���������, ��ź�� ǰ���� ������ ���� ���ȴ�. ������ ���� ���¿��� ����, �Ķ�, �ʷ�, ������� ĥ���� �κ��� ǰ�� ���� ���� R, B, G, Y��� ���� ��,

(��ź�� ǰ��) = 7R + 5B + 3G + 2Y

��ź�� ����� ���� ����� �ĺ��� �־����� ��, ��Ḧ ������ �����ϰ� ��ġ�Ͽ� ���� �� �ִ� ��ź�� �ִ� ǰ���� ������.

�Է�
ù ��° �ٿ� ����� ������ ��Ÿ���� �ڿ��� n�� �־�����. (3 �� n �� 10)

�� ��° �ٺ��� n���� ��� ������ ������� �־�����. �� ����� ������ ������ ����. ���� 4���� �ٿ� ȿ���� ��Ÿ���� �� 4���� ������ ���̿� �ΰ� �־�����. ���� 4���� �ٿ� ���Ҹ� ��Ÿ���� ���� 4���� ������ ���̿� �ΰ� �־�����. �� ���ڴ� R, B, G, Y, W �� �ϳ����� ����ȴ�.

���
ù ��° �ٿ� ǰ���� �ִ��� ����Ѵ�.

Ǯ��:
��������...
����Ž�� �����Դϴ�.
ó���� �迭�� �Ź� ������ ���¸� ������־��µ� �ð��ʰ� -> ���͸� call by value�� ���ڷ� �����ϴ� �ƽ��ϴ�.
*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<vector>
#include<stack>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>
#define pic pair<int, char>
#define ll long long
#define vi vector<int>
#define vl vector<long long>
#define vii vector<pii>

struct state {
	int eff;
	int ele;

	state() { }
	state(int _eff, int _ele) : eff(_eff), ele(_ele) { }
};

int n;
int material[11][4][4][4][2];
int ans = 0;
bool used[11];
vector<vector<state>> v(5, vector<state>(5));

int sum(vector<vector<state>> gama) {
	int r = 0, b = 0, g = 0, y = 0;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (gama[i][j].ele == 1)
				r += gama[i][j].eff;
			if (gama[i][j].ele == 2)
				b += gama[i][j].eff;
			if (gama[i][j].ele == 3)
				g += gama[i][j].eff;
			if (gama[i][j].ele == 4)
				y += gama[i][j].eff;
		}
	}
	return r * 7 + b * 5 + g * 3 + y * 2;
}

vector<vector<state>> draw(vector<vector<state>> gama, int m, int r, int si, int sj) {

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			gama[i + si][j + sj].eff += material[m][r][i][j][0];
			if (gama[i + si][j + sj].eff < 0)
				gama[i + si][j + sj].eff = 0;
			else if (gama[i + si][j + sj].eff > 9)
				gama[i + si][j + sj].eff = 9;

			if (material[m][r][i][j][1] != 0)
				gama[i + si][j + sj].ele = material[m][r][i][j][1];
		}
	}
	return gama;
}

void BF(vector<vector<state>> gama, int cnt) {

	if (cnt == 3) {
		ans = max(ans, sum(gama));
		return;
	}

	for (int t = 0; t < n; t++)
	{
		if (!used[t]) {
			used[t] = true;

				for (int i = 0; i < 4; i++)
				{
					for (int si = 0; si <= 1; si++)
					{
						for (int sj = 0; sj <= 1; sj++)
						{
							vector<vector<state>> temp = draw(gama, t, i, si, sj);
							BF(temp, cnt + 1);
						}
					}
				}
				used[t] = false;
			}
		
	}
}

void rotate() {

	for (int l = 0; l < n; l++)
	{
		for (int r = 1; r < 4; r++)
		{
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					material[l][r][j][i][0] = material[l][r - 1][i][3 - j][0];
					material[l][r][j][i][1] = material[l][r - 1][i][3 - j][1];
				}
			}
		}
	}
}

int main(void) {
	FIO;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		used[i] = false;
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				cin >> material[i][0][j][k][0];
			}
		}

		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				char c;
				cin >> c;
				if (c == 'W')
					material[i][0][j][k][1] = 0;
				else if(c == 'R')
					material[i][0][j][k][1] = 1;
				else if(c == 'B')
					material[i][0][j][k][1] = 2;
				else if(c == 'G')
					material[i][0][j][k][1] = 3;
				else
					material[i][0][j][k][1] = 4;
			}
		}
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			v[i][j] = state(0, 0);
		}
	}

	rotate();

	BF(v, 0);

	cout << ans;
}