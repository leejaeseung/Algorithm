/*
����


1���� N���� ���� N���� �̷���� ������ ��Ÿ���� ����� ���� ������ �ִ�. ���� ���, 8���� ���� �̷���� ���� (3, 2, 7, 8, 1, 4, 5, 6)�� �迭�� �̿��� ǥ���ϸ�  �� ����. �Ǵ�, Figure 1�� ���� ���� �׷����� ��Ÿ�� ���� �ִ�.

������ �迭�� �̿���  �� ��Ÿ�´ٸ�, i���� ��i�� ������ �̾� �׷����� ���� �� �ִ�.

Figure 1�� �����ִ� �� ó��, ���� �׷��� (3, 2, 7, 8, 1, 4, 5, 6) ���� �� 3���� ����Ŭ�� �ִ�. �̷��� ����Ŭ�� "���� ����Ŭ" �̶�� �Ѵ�.

N���� ������ �̷���� ������ �־����� ��, ���� ����Ŭ�� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �׽�Ʈ ���̽��� ���� T�� �־�����. �� �׽�Ʈ ���̽��� ù° �ٿ��� ������ ũ�� N (2 �� N �� 1,000)�� �־�����. ��° �ٿ��� ������ �־�����, �� ������ �������� ���еǾ� �ִ�.

���
�� �׽�Ʈ ���̽�����, �Է����� �־��� ������ �����ϴ� ���� ����Ŭ�� ������ ����Ѵ�.

Ǯ��:
������ �׷��� Ž�� �����̴�. N^2 ���� Ǯ���ߴ�.
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
int mv1[4] = { 0, 0, 1, -1 };
int mv2[4] = { 1, -1, 0, 0 };
int mv_all1[8] = { 0, 1, 0, -1, -1, -1, 1, 1 };
int mv_all2[8] = { 1, 0, -1, 0 , -1, 1, -1, 1 };


int main(void) {
	FIO;

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> vt(n + 1, 0);
		vector<bool> visit(n + 1, false);

		for (int i = 1; i <= n; i++)
		{
			cin >> vt[i];
		}

		int ans = 0;

		for (int i = 1; i <= n; i++)
		{
			int now = i;
			if (!visit[now]) {
				ans++;

				while (!visit[now]) {
					visit[now] = true;
					now = vt[now];
				}
			}
		}

		cout << ans << "\n";
	}
}