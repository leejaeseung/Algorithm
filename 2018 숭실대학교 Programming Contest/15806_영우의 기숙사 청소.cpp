/*
����
������ �ʹ����� �ϱ� �Ⱦ��� ����� �ᱹ �б��� ����翡 ����. ������ ���뿡�� �ع�� ��ݵ� ���, �б� ����翡���� ���� �Ⱓ���� û�� �˻縦 �Ѵٴ� ����� �˰� �Ǿ���. û�� �˻翡�� ���� ������ ������ ������ �ް� �ǰ�, ������ ���� ���̸� ����翡�� ��� �ؾ� �Ѵ�. ����� � ��쿡 ������ �޴��� �ñ��Ͽ� ����翡�� �����ϴ� û�� �˻� �ý��ۿ� ���� �ڼ��� ������ ���Ҵ�. ����� û�� �˻� �ý����� ���÷κ��� ��Ȯ�� t ���� ������ �˻縦 �ϸ�, �˻� �ð� ������ ���� ���� Ư�� �κи� �˻��Ѵ�. ������ �˻��ϴ� Ư�� �κ� �� �� ���̶� �����ٸ� ����� ������ �ް� �ȴ�. ���찡 ��� ���� N * N ���簢�� ���̸�, ����� ��ٴڿ��� �����̰� �����ϰ� �ִ�. �����̴� 1 ���� ���� ������ Ư���� ������� �����ϴµ�, �׸� 1(a)�� �����̴� 1 ���� ������ �׸� 1(b)�� ���� 8 ������ ���ĵǰ�, ������ �����̴� �������. ���� �����̰� �����ؾ� �ϴ� �κ��� ������ ���� �ִٸ�, �װ����δ� �������� ���Ѵ�. �׸� 2 �� �� ������ �����̰� 1 ���� ���� �� ����̴�.



�׸� 1(a)                                                                     �׸� 1(b)



�׸� 2(a)                                                                   �׸� 2(b)

���п��� �غ��ϴ��� �ٻ� ����� û�� �˻翡�� ������ ���� �ʴ´ٸ�, ���� û������ �������� �Ѵ�. �ٻ� ���츦 ���� �������� ���찡 û�Ҹ� �ؾ� �ϴ��� �ƴ����� �˷�����.

�Է�
���α׷��� �Է��� ǥ�� �Է����� �޴´�. ù �ٿ� ������ ���� ũ��, �濡 �ִ� �������� ����, û�� �˻� �ý����� �˻��ϴ� ��ٴ� ��ǥ�� ����, û�� �˻簡 �ǽ� �Ǳ���� ���� �ϼ��� N M K t �� �־�����. (1 �� N �� 300, 0 �� M �� N2, 0 �� K �� N2, 1 �� t �� 10000)

��° �ٺ��� M ���� �ٿ� ���� ������ �濡 �ִ� �������� ��ġ�� Mx My�� �־�����.(1 �� Mx, My �� N)

���� �ٺ��� K ���� �ٿ� ���� �˻���� �˻��ϴ� ��ٴ��� ��ġ�� Kx Ky�� �־�����.(1 �� Kx, Ky �� N)

Ǯ��:
¦�� ��°���� ���ڸ��� ���ƿ��� ���� �̿��� �湮�� üũ���ش�.
*/
/*#include<iostream>
#include<algorithm>
#include<queue>
#include<utility>
#include<vector>
using namespace std;

int N, M, K, T;
bool room[301][301][2];
vector<pair<int, int >> check;
int mv1[8] = { -2,-2,2,2,-1,-1,1,1 };
int mv2[8] = { 1,-1,1,-1,2,-2,2,-2 };
queue<pair<int, int>> q;

void BFS() {

	int cnt = 0;
	while (!q.empty()) {
		int size = q.size();
		cnt++;
		if (cnt > T)
			return;

		for (int i = 0; i < size; i++)
		{
			int nowx = q.front().first;
			int nowy = q.front().second;
			q.pop();

			for (int j = 0; j < 8; j++)
			{
				int nextx = nowx + mv1[j];
				int nexty = nowy + mv2[j];

				if (nextx <= 0 || nexty <= 0 || nextx > N || nexty > N)	continue;
				if (!room[nextx][nexty][cnt % 2]) {
					room[nextx][nexty][cnt % 2] = true;
					q.push(make_pair(nextx, nexty));
				}
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> K >> T;
	bool clean = true;

	for (int i = 0; i < M; i++)
	{
		int x, y;
		cin >> x >> y;
		q.push(make_pair(N - y + 1, x));
		room[N - y + 1][x][0] = true;
	}
	for (int i = 0; i < K; i++)
	{
		int x, y;
		cin >> x >> y;
		check.push_back(make_pair(N - y + 1, x));
	}
	BFS();
	for (int i = 0; i < check.size(); i++)
	{
		if (room[check[i].first][check[i].second][T % 2]) {
			clean = false;
		}
	}

	if (clean)
		cout << "NO";
	else
		cout << "YES";

}*/