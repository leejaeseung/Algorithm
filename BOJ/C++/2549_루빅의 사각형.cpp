/*
����
4��4 �����ǿ� 1���� 16���� ���� ��ȣ�� �Ű��� 16�� Ÿ���� ���Ƿ� ������ �ִ�. Ÿ���� ������ �׸� 1�� ���� Ÿ���� ���̰� �Ϸ��� �Ѵ�.



�׸� 1

Ÿ���� �����̴� ����� �ϳ��� ��(������)�� ���������� ���ϴ� ĭ ����ŭ ��ȯ������ �����̰ų�, �ϳ��� ��(������)�� ���ϴ� ĭ ����ŭ �Ʒ������� ��ȯ������ �����̴� ���̴�. �׸� 2�� �׸� 1�� 2��° ���� ���������� 2ĭ ������ ���̴�. �׸� 1�� 2��° ���� ������ ���� �ִ� 7�� Ÿ�ϰ� 8�� Ÿ���� ������ ��踦 �Ѿ�� ���� ������ �Űܰ���.



�׸� 2

�׸� 3�� �׸� 2�� 3��° ���� �Ʒ������� 1ĭ ������ ���̴�. �׸� 2�� 3��° ���� ���� �Ʒ��� �ִ� 15�� Ÿ���� ���� �������� �Űܰ���.



�׸� 3

�׸� 3�� ���� Ÿ���� ������ �������� �־����ٸ� 3��° ���� 3ĭ ������ ����, 2��° ���� 2ĭ �����̸� �׸� 1�� ���� Ÿ���� ���̰� �ȴ�. ���� 2�� �����̸� �ȴ�.

1���� 16���� ��ȣ�� �Ű��� Ÿ���� ���Ƿ� ������ ���� �� �׸� 1�� ���� Ÿ���� ���� �� �ֵ��� Ÿ���� �����̴� ������ ����ϴ� ���α׷��� �ۼ��Ͻÿ�. ���⼭ �����̴� Ƚ���� �ּҷ� �Ͽ��� �Ѵ�.

�Է�
4��4 �����ǿ� ������ Ÿ�� ��ȣ�� ��� ���� 4�� �ٿ� �־�����. Ÿ�� ��ȣ�� 1���� 16������ �����̴�.

�� �ٿ��� �ش��ϴ� �࿡ �������� 4�� Ÿ���� ��ȣ�� ��ĭ�� ���̿� �ΰ� ������� �־�����.

���
ù ��° �ٿ��� �����̴� Ƚ����, �� ��° �ٺ��ʹ� �� �ٿ� �ϳ��� Ÿ���� �����̴� ����� ������� ����Ѵ�.

�̶�, �������� i��° ���� kĭ �������ٸ� ���� 1�� i�� k�� ��ĭ�� ���̿� �ΰ� �� �ٿ� ����Ѵ�. �׸��� �������� i��° ���� kĭ �������ٸ� ���� 2�� i�� k�� ��ĭ�� ���̿� �ΰ� �� �ٿ� ����Ѵ�. ���⼭ i�� 1 �̻� 4 ����, k�� 1 �̻� 3 ������ �����̴�.

Ǯ��:
��� ���� �̵��ϴ� ��찡 8�����̹Ƿ� 0~7�� ��ȣ�� �Ű� ��Ÿ�½��ϴ�.
�� �̵��� ���� ĭ�� 1~3 �� ���� ��� ��츦 Ž���մϴ�.

�� ��, 16���� ĭ �߿� �°� �� ������ ��ġ���� �������� �մϴ�.
���� ������ 16���̸� �ش� ��θ� �����մϴ�.

������ ��, �� 16���� ��� �°� ���� �� �� Ȥ�� ���� �� �� �����̰� �Ǹ� �� 4���� Ʋ���� �˴ϴ�.(12���� �°� ���� �˴ϴ�.)
���� ������ ������ 12�� �̸��̸� �ּ� 2���� �� �������� ������ ���� �� �ִٴ� ���ϴ�.
���� ������� ������ ������ 9�� �̸��̸� �ּ� 3��, 6�� �̸��̸� �ּ� 4���� �� �������� �ϹǷ� ����ġ�� ������ �߰����ָ� �ð��� ���� �� �ֽ��ϴ�.
*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include<stack>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>

int map[5][5];
int ans = 9;
vector<pii> route;

int getcnt() {
	int count = 1;
	int ret = 0;
	for (int i = 1; i < 5; i++)
	{
		for (int j = 1; j < 5; j++)
		{
			if (map[i][j] == count)
				ret++;
			count++;
		}
	}
	return ret;
}

void moveTile(int tile, int move) {
	bool flag = false;
	if (tile > 3)	flag = true;
	tile = tile % 4 + 1;
	
	for (int i = 0; i < move; i++)
	{
		if (flag) {
			int temp = map[1][tile];
			map[1][tile] = map[4][tile];
			map[4][tile] = map[3][tile];
			map[3][tile] = map[2][tile];
			map[2][tile] = temp;
		}
		else {
			int temp = map[tile][1];
			map[tile][1] = map[tile][4];
			map[tile][4] = map[tile][3];
			map[tile][3] = map[tile][2];
			map[tile][2] = temp;
		}
	}
}

void recul(int tile, int move, int cnt, vector<pii> now_route, int diff) {
	
	if (cnt >= ans || cnt == 8)	return;

	if (diff == 16) {
		route.clear();
		ans = min(ans, cnt);

		for (int i = 0; i < now_route.size(); i++)
		{
			route.push_back(now_route[i]);
		}
		return;
	}

	if (diff < 12 && cnt + 2 >= ans)	return;
	if (diff < 9 && cnt + 3 >= ans)	return;
	if (diff < 6 && cnt + 4 >= ans)	return;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			now_route.push_back(make_pair(i, j));
			moveTile(i, j);
			recul(i, j, cnt + 1, now_route, getcnt());
			moveTile(i, 4 - j);
			now_route.pop_back();
		}
	}
}

int main(void) {
	FIO;

	int diff = 0;
	int count = 1;
	for (int i = 1; i < 5; i++)
	{
		for (int j = 1; j < 5; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == count)
				diff++;
			count++;
		}
	}

	vector<pii> vt;
	recul(0, 0, 0, vt, diff);

	cout << ans << "\n";
	for (int i = 0; i < route.size(); i++)
	{
		int r = route[i].first;
		int c = route[i].second;

		if (r > 3) {
			cout << "2 " << r - 3 << " " << c << "\n";
		}
		else {
			cout << "1 " << r + 1 << " " << c << "\n";
		}
	}
}