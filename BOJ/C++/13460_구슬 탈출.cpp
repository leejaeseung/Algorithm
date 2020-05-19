/*
����
��ŸƮ��ũ���� �Ǹ��ϴ� ��̿� �峭�� �߿��� ���� �αⰡ ���� ��ǰ�� ���� Ż���̴�. ���� Ż���� ���簢�� ���忡 ���� ������ �Ķ� ������ �ϳ��� ���� ����, ���� ������ ������ ���� ������ �����̴�.

������ ���� ũ��� N, ���� ũ��� M�̰�, ���ǻ� 1��1ũ���� ĭ���� �������� �ִ�. ���� �ٱ� ��� ���� ��� ������ �ְ�, ���忡�� ������ �ϳ� �ִ�. ���� ������ �Ķ� ������ ũ��� ���忡�� 1��1ũ���� ĭ�� ���� ä��� �������̰�, ���� �ϳ��� �� �ִ�. ������ ��ǥ�� ���� ������ ������ ���ؼ� ������ ���̴�. �̶�, �Ķ� ������ ���ۿ� ���� �� �ȴ�.

�̶�, ������ ������ �ǵ帱 ���� ����, �߷��� �̿��ؼ� �̸� ���� ������ �Ѵ�. �������� ����̱�, ���������� ����̱�, �������� ����̱�, �Ʒ������� ����̱�� ���� �� ���� ������ �����ϴ�.

������ ���ۿ��� ���� ���ÿ� �����δ�. ���� ������ ���ۿ� ������ ����������, �Ķ� ������ ���ۿ� ������ �����̴�. ���� ������ �Ķ� ������ ���ÿ� ���ۿ� ������ �����̴�. ���� ������ �Ķ� ������ ���ÿ� ���� ĭ�� ���� �� ����. ��, ���� ������ �Ķ� ������ ũ��� �� ĭ�� ��� �����Ѵ�. ����̴� ������ �׸��ϴ� ���� �� �̻� ������ �������� ���� �� �����̴�.

������ ���°� �־����� ��, �ּ� �� �� ���� ���� ������ ������ ���� ���� �� �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù ��° �ٿ��� ������ ����, ���� ũ�⸦ �ǹ��ϴ� �� ���� N, M (3 �� N, M �� 10)�� �־�����. ���� N���� �ٿ� ������ ����� ��Ÿ���� ���� M�� ���ڿ��� �־�����. �� ���ڿ��� '.', '#', 'O', 'R', 'B' �� �̷���� �ִ�. '.'�� �� ĭ�� �ǹ��ϰ�, '#'�� ���� �̵��� �� ���� ��ֹ� �Ǵ� ���� �ǹ��ϸ�, 'O'�� ������ ��ġ�� �ǹ��Ѵ�. 'R'�� ���� ������ ��ġ, 'B'�� �Ķ� ������ ��ġ�̴�.

�ԷµǴ� ��� ������ �����ڸ����� ��� '#'�� �ִ�. ������ ������ �� �� �̸�, ���� ������ �Ķ� ������ �׻� 1���� �־�����.

���
�ּ� �� �� ���� ���� ������ ������ ���� ���� �� �ִ��� ����Ѵ�. ����, 10�� ���Ϸ� �������� ���� ������ ������ ���� ���� �� ������ -1�� ����Ѵ�.

Ǯ��:
DFS�� Ǯ���Ͽ����ϴ�.
10x10 ������ 10�� ���Ϸ� Ž���ϹǷ� ��� ��θ� Ž�����ָ� �˴ϴ�.
R�� B�� ��ĥ �� �����Ƿ� ���� ��ġ�� ��쿡 R�� B�� �� ���� �̵��� ������ ��ǥ�� �ѹ� ���ݴϴ�.

�׸��� �ð� ������ ���� ���� R,B �� ��ǥ�� �� ���� Ƚ���� �湮üũ�� �־����ϴ�.(5���� �迭)
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
#define pic pair<int, char>
#define ll long long
#define vi vector<int>
#define vl vector<long long>
#define vii vector<pii>
#define IMAX 2000000001
int mv1[4] = { 0, 0, 1, -1 };
int mv2[4] = { 1, -1, 0, 0 };

int n, m;
char maps[11][11];
bool visit[11][11][11][11][11];
int ans = IMAX;

void recul(pii pos_R, pii pos_B, int cnt) {

	if (cnt > 9)	return;

	for (int i = 0; i < 4; i++)
	{
		int nxR = pos_R.first;
		int nyR = pos_R.second;
		int nxB = pos_B.first;
		int nyB = pos_B.second;
		int f1 = 0;
		int f2 = 0;
		bool out1 = false;
		bool out2 = false;
		bool imp = false;
		bool succ = false;

		while (true) {
			if (maps[nxB][nyB] == 'O') {
				imp = true;
				break;
			}
			if (maps[nxR][nyR] == 'O') {
				succ = true;
			}

			if (out1 && out2)	break;

			if (nxR + mv1[i] >= 0 && nyR + mv2[i] >= 0 && nxR + mv1[i] < n && nyR + mv2[i] < m && maps[nxR + mv1[i]][nyR + mv2[i]] != '#') {
				f1++;
				nxR += mv1[i];
				nyR += mv2[i];
			}
			else
				out1 = true;

			if (nxB + mv1[i] >= 0 && nyB + mv2[i] >= 0 && nxB + mv1[i] < n && nyB + mv2[i] < m && maps[nxB + mv1[i]][nyB + mv2[i]] != '#') {
				f2++;
				nxB += mv1[i];
				nyB += mv2[i];
			}
			else
				out2 = true;

			
		}
		if (!imp) {
			if (succ) {
				ans = min(ans, cnt + 1);
				return;
			}
			if (nxR == nxB && nyR == nyB) {
				if (f1 > f2) {
					nxR -= mv1[i];
					nyR -= mv2[i];
				}
				else {
					nxB -= mv1[i];
					nyB -= mv2[i];
				}
			}

			if (!visit[nxR][nyR][nxB][nyB][cnt] && cnt < 9) {
				visit[nxR][nyR][nxB][nyB][cnt] = true;
				recul(make_pair(nxR, nyR), make_pair(nxB, nyB), cnt + 1);
			}
		}
	}
}

int main(void) {
	FIO;

	cin >> n >> m;

	pii pr, pb;

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			maps[i][j] = s[j];
			if (s[j] == 'R')
				pr = make_pair(i, j);
			if (s[j] == 'B')
				pb = make_pair(i, j);
		}
	}

	visit[pr.first][pr.second][pb.first][pb.second][0] = true;
	recul(pr, pb, 0);

	if (ans == IMAX)
		cout << "-1";
	else
		cout << ans;
}