/*
����
�����̴� �� û�Ҹ� �ϸ鼭 �ʿ� ���� ���� ������ ����鿡�� �����ַ��� �Ѵ�. ������ å�� ��ƺ��� �� N���̾���. å�� �ʹ� ���� ������ �����̴� å�� �����ϱ� ���� ���� 1���� N������ ���� ��ȣ�� �ߺ����� �ʰ� �Ű� �ξ���.

���縦 �� ���� å�� ���ϴ� �������б� �кλ��� �� M���̾���. �����̴� �� M���� ��û���� �� ���� a, b (1 �� a �� b �� N)�� ���� ����� �ߴ�. �׷��� �����̴� å ��ȣ�� a �̻� b ������ å �� �����ִ� å �� ���� ��� �� �л����� �ش�. ���� a������ b�������� ��� å�� �̹� �ٸ� �л����� �ְ� ���ٸ� �� �л����Դ� å�� ���� �ʴ´�.

�����̰� å�� �� �� �ִ� �ִ� �л� ���� ���Ͻÿ�.

�Է�
ù° �ٿ� �׽�Ʈ ���̽��� ���� �־�����.

�� ���̽��� ù �ٿ� ���� N(1 �� N �� 1,000)�� M(1 �� M �� 1,000)�� �־�����. ���� �ٺ��� M���� �ٿ��� ���� ���� ai, bi�� �־�����. (1 �� ai �� bi �� N)

���
�� �׽�Ʈ ���̽����� �����̰� å�� �� �� �ִ� �ִ� �л� ���� �� �ٿ� �ϳ��� ����Ѵ�.

Ǯ��:
a ~ b ������ ���� b�� �������� �������� �����ϸ� ������� ���� ��ȣ���� å�� �ְ� �Ǹ�
�ִ� ���� ���� �� �ִ�.(a�� ���ؼ� ��������, �������� ��� ����)

�ֳ��ϸ� �ִ� b ���� ���� �� �ֱ� ������ � ���� x ~ y �� �� ä���ٰ� �ص� �� ���� ���Ҵ� 
y���� �׻� ũ�ų� ���� ���� ������ �����̴�.(���ٸ� �� �� ���� ���)
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
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vii vector<pii>
#define IMAX 2000000001
#define LMAX 1000000000000000000
#define DMAX 0xFFFFFFFFFFFFF
int mv1[4] = { 0, 0, 1, -1 };
int mv2[4] = { 1, -1, 0, 0 };
int mv_all1[8] = { 0, 1, 0, -1, -1, -1, 1, 1 };
int mv_all2[8] = { 1, 0, -1, 0 , -1, 1, -1, 1 };

int n, m;

bool mySort(pii o1, pii o2) {
	if (o1.second == o2.second)
		return o1.first > o2.first;
	return o1.second < o2.second;
}

int main(void) {
	FIO;

	int t;
	cin >> t;

	while (t--) {
		cin >> n >> m;

		vector<pii> vt;
		bool check[1001];
		int ans = 0;

		for (int i = 0; i <= n; i++)
		{
			check[i] = false;
		}

		for (int i = 1; i <= m; i++)
		{
			int s, e;
			cin >> s >> e;
			
			vt.push_back(make_pair(s, e));
		}

		sort(vt.begin(), vt.end(), mySort);

		for (int i = 0; i < m; i++)
		{
			pii now = vt[i];

			for (int j = now.first; j <= now.second; j++)
			{
				if (!check[j]) {
					check[j] = true;
					ans++;
					break;
				}
			}
		}
		
		cout << ans << "\n";
	}
}