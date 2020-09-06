/*
����
2���� ���� m���� �������� n���� �������� �̷���� ���� ������ ���θ��� �ִ�. �Ʒ� �׸��� 7���� �������� 6���� �������� �̷���� ���θ��� ���̴�.



�������� ������ ������ �������� �� ���� ���� �Ʒ� ���� ��ġ�� (1,1)�̰�, ���� ������ �� ���� ��ǥ�� (m,n)�̴�. �� ���θ��� �����ϴ� �������� k�� �ְ�, ��  ������ �ϳ��� ���� ���� �� ������ ���� �����̳� �ϳ��� ������ ���� �� ������ ���� ������ �պ� �����Ѵ�. �� ������ �����ϴ� ���� ������ ��� ������(������ �� �� ������ ����)���� �����Ѵ�.

����� �������� ������ ������ (������� �������� �ٸ�)�� �־��� ��, ��������� �������� �������� �̿��Ͽ� ������ �Ѵ�. �̿��ϴ� ������ �ּ� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

���� ���,  8���� ������ ������ ���� �����Ѵٰ� ����.

1�� ����: (2, 1) - (2, 2)

2�� ����: (1, 1) - (5, 1)

3�� ����: (3, 2) - (6, 2)

4�� ����: (5, 6) - (5, 1)

5�� ����: (1, 5) - (7, 5)

6�� ����: (7, 3) - (7, 6)

7�� ����: (2, 1) - (2, 6)

8�� ����: (3, 5) - (6, 5)

������� (2, 1)�̰� �������� (7, 4)�� ����. �� ���� �������, ó���� 2�� ������ Ÿ�� ������ (5, 1)���� ����, 4�� ������ Ÿ�� (5, 5)���� ������, 5�� ������ ź �� (7, 5)���� ����, ���������� 6�� ������ Ÿ�� ������ (7, 4)���� ������. �׷��� �̿��ϴ� ���� ���� 4�̴�. �ٸ� �������, 7�� ������ Ÿ�� (2, 5)���� ����, 5�� ������ Ÿ�� (7, 5)���� ���� ��, ���������� 6�� ������ Ÿ�� ������ (7, 4)���� ������. �׷��� �̿��ϴ� ���� ���� 3�̰� �̰��� �ּ��̴�.

�Է�
ù ��° �ٿ� �������� �� m�� ������ �� n�� ��ĭ�� ���̿� �ΰ� �־����� (1 �� m,n �� 100,000). �� ��° �ٿ� ������ �� k (1 �� k �� 5,000)�� �־�����. �� ��° �ٺ��� k �ٿ� ���� �� �ٿ� ������ ���౸���� ��Ÿ���� 5���� �� b, x1, y1, x2, y2�� ��ĭ�� ���̿� �ΰ� �־�����. ���⼭ b (1 �� b �� k) �� ������ ��ȣ, (x1,y1) �� (x2, y2)�� �� ������ �����ϴ� ���� �� �������� ��ǥ�� ��Ÿ����. ������ �ٿ� ������� ������ ��ǥ�� ��Ÿ���� �� ���� �� sx, sy, dx, dy�� ��ĭ�� ���̿� �ΰ� �־�����. ���⼭ (sx, sy)�� ����� ��ǥ�̰� (dx, dy)�� ������ ��ǥ�̴�.  1 �� x1, x2, sx, dx �� m�̰�, 1 �� y1, y2, sy, dy �� n�̴�.

��� �Է¿� ���Ͽ�, ������� �������� �ٸ��� �־����� ��������� �������� ���� ����� �� ���� �̻� �����Ѵ�.

���
ù° �ٿ� �̿��ϴ� �ּ� ���� ���� ����Ѵ�.

Ǯ��:
������ ��θ� ����, ������ ��ġ�� �� ������ �������� �̾��ش�.
(ccw �� �̿��� �� ������ ���� ���θ� Ȯ�� = N^2)
�������� �����ϴ� ������ ��� �켱���� ť�� �ְ� ���ͽ�Ʈ�� �˰����� ����� Ǯ���ߴ�.
�������� �����ϴ� ������ �� �Ÿ��� �ּ��� ���� ���� �ȴ�.

��ǥ�� ũ�Ⱑ �ִ� 100000 �̹Ƿ� ccw�� ���� �� �����÷ο찡 �߻��� �� �ִ�.
*/
/*#include<iostream>
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

int m, n, k, sx, sy, dx, dy;
pair<pll, pll> bus[5001];
pll start;
pll dest;
vector<int> edge[5001];
bool isEnd[5001];
int dist[5001];
priority_queue<pii> pq;

int ccw(pll p1, pll p2, pll p3) {
	ll S = (p1.first * p2.second + p2.first * p3.second + p3.first * p1.second) 
		- (p1.second * p2.first + p2.second * p3.first + p3.second * p1.first);

	if (S > 0)
		//�ݽð�
		return -1;
	else if (S < 0)
		//�ð�
		return 1;
	else
		//������
		return 0;
}

bool cross(pair<pll, pll> L1, pair<pll, pll> L2) {
	pll a = L1.first;
	pll b = L1.second;
	pll c = L2.first;
	pll d = L2.second;

	int abL2 = ccw(a, b, c) * ccw(a, b, d);
	int cdL1 = ccw(c, d, a) * ccw(c, d, b);

	if (abL2 == 0 && cdL1 == 0) {
		if (a > b)	swap(a, b);
		if (c > d)	swap(c, d);
		return c <= b && a <= d;
	}
	return abL2 <= 0 && cdL1 <= 0;
}

int main(void) {
	FIO;

	cin >> m >> n >> k;

	for (int i = 0; i < k; i++)
	{
		int b, x1, y1, x2, y2;
		cin >> b >> x1 >> y1 >> x2 >> y2;

		bus[b] = { {x1, y1}, {x2, y2} };
	}

	cin >> sx >> sy >> dx >> dy;

	fill(&dist[0], &dist[5001], IMAX);

	start = { sx, sy };
	dest = { dx, dy };

	for (int i = 1; i <= k; i++)
	{
		if (cross(bus[i], { dest, dest }))
			isEnd[i] = true;
		if (cross(bus[i], { start, start })) {
			dist[i] = 1;
			pq.push({ 1, i });
		}
		if (i <= k - 1) {
			for (int j = i + 1; j <= k; j++)
			{
				if (cross(bus[i], bus[j])) {
					edge[i].push_back(j);
					edge[j].push_back(i);
				}
			}
		}
	}

	while (!pq.empty()) {
		int nowDist = -pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (dist[now] < nowDist)	continue;

		for (int i = 0; i < edge[now].size(); i++)
		{
			int next = edge[now][i];

			if (dist[next] > dist[now] + 1) {
				dist[next] = dist[now] + 1;

				pq.push({ -dist[next], next });
			}
		}
	}

	int ans = IMAX;

	for (int i = 1; i <= k; i++)
	{
		if(isEnd[i])
			ans = min(ans, dist[i]);
	}

	cout << ans;
}*/