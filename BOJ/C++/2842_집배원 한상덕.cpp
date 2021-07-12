/*
����
����̴� ��� ���� �ִ� ������ ��ü���� ������ �����. ������ N��N ��ķ� ��Ÿ�� �� �ִ�. ��ķ� �������� �� ������ ��ü���� 'P', ���� 'K', �������� '.' �� �ϳ��� ��Ÿ�� �� �ִ�. ��, �� ������ ���� �˰� �ִ�.

���� ��ħ ����̴� ������ ��� ���� ������ ����ؾ� �Ѵ�. ����� ������ �ϳ��ۿ� ���� ��ü�� 'P'�� �ִ� ������ �����Ѵ�. ����̴� ���� �ִ� ĭ�� ����, ����, �밢������ ������ ĭ���� �̵��� �� �ִ�. ������ ������ ����ϰ� �� ���Ŀ��� �ٽ� ��ü������ ���ƿ;� �Ѵ�.

����̴� �̷��� ���� ��ħ ����� �ϴ� ���� �󸶳� ������ �ñ�������. ����̰� ����ϸ鼭 �湮�� ĭ �� ���� ���� ���� ���� ���� �� ���̸� �Ƿε���� ����. �̶�, ���� ���� �Ƿε��� ��� ���� ����� �Ϸ��� ��� �ؾ� �ϴ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� N�� �־�����. (2 �� N �� 50)

���� N�� �ٿ��� ������ ��Ÿ���� ����� �־�����. 'P'�� �� ���� �־�����, 'K'�� ��� �� �� �־�����.

���� N�� �ٿ��� ��ķ� �������� ������ ���� ��� ���·� �־�����. ���� 1,000,000���� �۰ų� ���� �ڿ����̴�.

���
ù° �ٿ� ���� ���� �Ƿε��� ����Ѵ�.

Ǯ��:
�� �����Ϳ� BFS ����� Ǯ���ߴ�.
��� ���� �ߺ��� ������ set���� �����ϰ�, ����̰� �� �� �ִ� ���� left ~ right �� �����ͷ� �д�.
�����͸� �Űܰ��� BFS�� ��� ���� �� �� �ִ��� ���ϻ��, �� �� �ִٸ� �ּ� �� ���̸� �����ϸ� �ȴ�.
*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<regex>
#include<set>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define pic pair<int, char>
#define ll long long
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vii vector<pii>
#define IMAX 2147483647
#define LMAX 1000000000000500000
#define DMAX 0xFFFFFFFFFFFFF
int mv1[8] = { 0, 1, -1, 0, -1, -1, 1, 1 };
int mv2[8] = { 1, 0, 0, -1, -1, 1, -1, 1 };

int n;
int sx, sy;
bool town[51][51];
int height[51][51];
bool visit[51][51];
int homeCnt = 0;

bool bfs(int s, int e) {
	if (height[sx][sy] < s || height[sx][sy] > e)	return false;

	queue<pii> q;
	fill(&visit[0][0], &visit[50][50], false);

	visit[sx][sy] = true;
	q.push({sx, sy});

	int cnt = 0;

	while (!q.empty()) {
		pii now = q.front();
		q.pop();

		for (int i = 0; i < 8; i++)
		{
			int nx = now.first + mv1[i];
			int ny = now.second + mv2[i];
			
			if (nx < 0 || nx >= n || ny < 0 || ny >= n)	continue;

			if (height[nx][ny] >= s && height[nx][ny] <= e && !visit[nx][ny]) {
				visit[nx][ny] = true;

				if (town[nx][ny]) {

					cnt++;

					if (cnt == homeCnt)	return true;
				}

				q.push( {nx, ny} );
			}
		}
	}

	return false;
}

int main(void) {
	FIO;

	cin >> n;

	set<int> hset;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < n; j++)
		{
			if (str[j] == 'P') {
				sx = i;
				sy = j;
				town[i][j] = true;
			}
			else if (str[j] == 'K') {
				town[i][j] = true;
				homeCnt++;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> height[i][j];
			hset.insert(height[i][j]);
		}
	}

	auto l = hset.begin();
	auto r = hset.begin();

	int ans = IMAX;

	while (r != hset.end()) {
		
		while (*l <= *r) {
			
			if (bfs(*l, *r)) {
				ans = min(ans, *r - *l);

				if (l == r)	break;
				l++;
			}
			else {
				break;
			}
		}
		r++;
	}

	cout << ans;
}