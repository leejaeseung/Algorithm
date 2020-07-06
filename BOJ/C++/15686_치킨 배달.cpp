/*
����
ũ�Ⱑ N��N�� ���ð� �ִ�. ���ô� 1��1ũ���� ĭ���� �������� �ִ�. ������ �� ĭ�� �� ĭ, ġŲ��, �� �� �ϳ��̴�. ������ ĭ�� (r, c)�� ���� ���·� ��Ÿ����, r�� c�� �Ǵ� ���������� r��° ĭ, ���ʿ������� c��° ĭ�� �ǹ��Ѵ�. r�� c�� 1���� �����Ѵ�.

�� ���ÿ� ��� ������� ġŲ�� �ſ� �����Ѵ�. ����, ������� "ġŲ �Ÿ�"��� ���� �ַ� ����Ѵ�. ġŲ �Ÿ��� ���� ���� ����� ġŲ�� ������ �Ÿ��̴�. ��, ġŲ �Ÿ��� ���� �������� ��������, ������ ���� ġŲ �Ÿ��� ������ �ִ�. ������ ġŲ �Ÿ��� ��� ���� ġŲ �Ÿ��� ���̴�.

������ �� ĭ (r1, c1)�� (r2, c2) ������ �Ÿ��� |r1-r2| + |c1-c2|�� ���Ѵ�.

���� ���, �Ʒ��� ���� ������ ���� ���ø� ���캸��.

0 2 0 1 0
1 0 1 0 0
0 0 0 0 0
0 0 0 1 1
0 0 0 1 2
0�� �� ĭ, 1�� ��, 2�� ġŲ���̴�.

(2, 1)�� �ִ� ���� (1, 2)�� �ִ� ġŲ������ �Ÿ��� |2-1| + |1-2| = 2, (5, 5)�� �ִ� ġŲ������ �Ÿ��� |2-5| + |1-5| = 7�̴�. ����, (2, 1)�� �ִ� ���� ġŲ �Ÿ��� 2�̴�.

(5, 4)�� �ִ� ���� (1, 2)�� �ִ� ġŲ������ �Ÿ��� |5-1| + |4-2| = 6, (5, 5)�� �ִ� ġŲ������ �Ÿ��� |5-5| + |4-5| = 1�̴�. ����, (5, 4)�� �ִ� ���� ġŲ �Ÿ��� 1�̴�.

�� ���ÿ� �ִ� ġŲ���� ��� ���� �����������̴�. ���������� ���翡���� ������ ������Ű�� ���� �Ϻ� ġŲ���� �����Ű���� �Ѵ�. ���� ���� ���� �� ���ÿ��� ���� ������ ���� �� �� �ִ�  ġŲ���� ������ �ִ� M����� ����� �˾Ƴ�����.

���ÿ� �ִ� ġŲ�� �߿��� �ִ� M���� ����, ������ ġŲ���� ��� ������Ѿ� �Ѵ�. ��� ����, ������ ġŲ �Ÿ��� ���� �۰� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� N(2 �� N �� 50)�� M(1 �� M �� 13)�� �־�����.

��° �ٺ��� N���� �ٿ��� ������ ������ �־�����.

������ ������ 0, 1, 2�� �̷���� �ְ�, 0�� �� ĭ, 1�� ��, 2�� ġŲ���� �ǹ��Ѵ�. ���� ������ 2N���� ���� ������, ��� 1���� �����Ѵ�. ġŲ���� ������ M���� ũ�ų� ����, 13���� �۰ų� ����.

���
ù° �ٿ� �����Ű�� ���� ġŲ���� �ִ� M���� ����� ��, ������ ġŲ �Ÿ��� �ּڰ��� ����Ѵ�.

Ǯ��:
�� ġŲ �������� �� �������� �Ÿ��� ��� ���մϴ�(�ִ� 13 * 100)

ġŲ ���� �ִ� m�� ���� �ϴµ�, ��� �ִ��� ���� ������� ������ ��� ġŲ ���� �߿��� m���� ������ ������� ������ �˴ϴ�.

������ ������� ���� ������� �ʾ��� �� �ð����� ����!
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

int n, m;
int maps[51][51];
int ch_to_home[13][100];
vector<pair<pii, bool>> chicken;
vector<pair<pii, int>> home;
int minLeng = IMAX;

int getDis(pii x1, pii x2) {
	return abs(x1.first - x2.first) + abs(x1.second - x2.second);
}

int getChicken() {

	int all_chicken = 0;

	for (int i = 0; i < chicken.size(); i++)
	{
		if (chicken[i].second) {
			for (int j = 0; j < home.size(); j++)
			{
				home[j].second = min(home[j].second, ch_to_home[i][j]);
			}
		}
	}

	for (int i = 0; i < home.size(); i++)
	{
		all_chicken += home[i].second;
		home[i].second = IMAX;
	}

	return all_chicken;
}

void recul(int idx, int cnt) {

	if (cnt == m) {
		int minAllChicken = getChicken();

		if (minAllChicken < minLeng) {
			minLeng = minAllChicken;
		}
		return;
	}

	for (int i = idx + 1; i < chicken.size(); i++)
		//������ ������� �ʱ� ���� ������ ���� idx�� �����ϰ� �������� ����
	{
		chicken[i].second = true;
		recul(i, cnt + 1);
		chicken[i].second = false;
	}
}

int main(void) {
	FIO;

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> maps[i][j];
			if (maps[i][j] == 2)
				chicken.push_back(make_pair(make_pair(i, j), false));
			if (maps[i][j] == 1)
				home.push_back(make_pair(make_pair(i, j), IMAX));
		}
	}

	for (int i = 0; i < chicken.size(); i++)
	{
		for (int j = 0; j < home.size(); j++)
		{
			ch_to_home[i][j] = getDis(make_pair(chicken[i].first.first, chicken[i].first.second), make_pair(home[j].first.first, home[j].first.second));
		}
	}

	recul(-1, 0);

	cout << minLeng;
}