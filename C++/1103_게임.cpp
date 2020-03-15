/*
����
�����̴� 1���� 9������ ���ڿ�, ������ �ִ� ���簢�� ���忡�� ��մ� ������ �Ѵ�.

�ϴ� ������ ���� ���� ���� ������ �ϳ� �÷����´�. �״����� ������ ���� ������ �����δ�.

������ �ִ� ���� ���� �ִ� ���� X�� ����.
��, �Ʒ�, ����, ������ ���� �߿� �Ѱ����� ����.
������ ������ �� �������� X��ŭ �����δ�. �̶�, �߰��� �ִ� ������ �����Ѵ�.
���� ������ ���ۿ� �����ų�, ������ �ٱ����� �����ٸ� ������ ����ȴ�. �����̴� �� ��մ� ������ �ǵ����̸� ���� �ϰ� �ʹ�.

������ ���°� �־����� ��, �����̰� �ִ� �� �� ������ ������ �� �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
�ٿ� ������ ���� ũ�� N�� ���� ũ�� M�� �־�����. �� ���� ��� 50���� �۰ų� ���� �ڿ����̴�. ��° �ٺ��� N���� �ٿ� ������ ���°� �־�����. ���� �ִ� ���ڴ� 1���� 9������ �ڿ��� �Ǵ� H�̴�. ���� ���� ��ĭ�� H�� �ƴϴ�. H�� �����̴�.

���
ù° �ٿ� ������ ������ ����Ѵ�. ���� �����̰� ������ ���ѹ� ������ �� �ִٸ� -1�� ����Ѵ�.

Ǯ��:

dp[][] �迭�� �ش� ��ǥ������ �ִ� ī��Ʈ ���� �����մϴ�.
�̹� �湮��(dp �迭�� ī��Ʈ�� �ö�) ���̶�� ���� ī��Ʈ + 1 �� �ش� ��ǥ�� dp ���� ���մϴ�.
�ش� ��ǥ�� �� ũ�ٸ� ���� �ٽ� �鸮�� �ʾƵ� �˴ϴ�.
*/

#include<iostream>
#include<queue>
#include<math.h>
#include<utility>
using namespace std;

int N, M;
int dp[50][50];
char map[50][50];
char s[51];
int mv1[4] = { 0,0,1,-1 };
int mv2[4] = { 1,-1,0,0 };

int BFS() {
	queue<pair<int, pair<int, int> > > q;

	q.push(pair<int, pair<int, int> >(0, pair<int, int>(0, 0)));

	int max_v = 0;

	while (!q.empty()) {
		int cnt = q.front().first;
		int x = q.front().second.first;
		int y = q.front().second.second;
		q.pop();

		max_v = max(max_v, dp[x][y]);
		if (max_v > 2500)
			return -1;

		for (int i = 0; i < 4; i++)
		{
			int next_x = x + mv1[i] * (int)(map[x][y] - '0');
			int next_y = y + mv2[i] * (int)(map[x][y] - '0');

			if (next_x < 0 || next_y < 0 || next_x >= N || next_y >= M)	continue;

			if(cnt + 1 > dp[next_x][next_y]){
				dp[next_x][next_y] = cnt + 1;

				if (map[next_x][next_y] == 'H')
					continue;
				
				q.push(pair<int, pair<int, int> >(cnt + 1, pair<int, int>(next_x, next_y)));
			}
		}
	}
	return max_v + 1;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> s;
		for (int j = 0; j < M; j++)
		{
			map[i][j] = s[j];
		}
	}
	cout << BFS();

}