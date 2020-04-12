/*
����
ũ�Ⱑ N��M�� ��� A�� M��K�� B�� ���� �� �ʿ��� ���� ������ ���� �� N��M��K���̴�. ��� N���� ���ϴµ� �ʿ��� ���� ������ ���� ����� ���ϴ� ������ ���� �޶����� �ȴ�.

���� ���, A�� ũ�Ⱑ 5��3�̰�, B�� ũ�Ⱑ 3��2, C�� ũ�Ⱑ 2��6�� ��쿡 ����� �� ABC�� ���ϴ� ��츦 �����غ���.

AB�� ���� ���ϰ� C�� ���ϴ� ��� (AB)C�� �ʿ��� ���� ������ ���� 5��3��2 + 5��2��6 = 30 + 60 = 90���̴�.
BC�� ���� ���ϰ� A�� ���ϴ� ��� A(BC)�� �ʿ��� ���� ������ ���� 3��2��6 + 5��3��6 = 36 + 90 = 126���̴�.
���� ����������, ������ �ϴ� ������ ���� ���� ������ ���� �޶�����.

��� N���� ũ�Ⱑ �־����� ��, ��� ����� ���ϴµ� �ʿ��� ���� ���� Ƚ���� �ּڰ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�. �Է����� �־��� ����� ������ �ٲٸ� �� �ȴ�.

�Է�
ù° �ٿ� ����� ���� N(1 �� N �� 500)�� �־�����.

��° �ٺ��� N�� �ٿ��� ����� ũ�� r�� c�� �־�����. (1 �� r, c �� 500)

�׻� ������� ������ �� �� �ִ� ũ�⸸ �Է����� �־�����.

���
ù° �ٿ� �Է����� �־��� ����� ���ϴµ� �ʿ��� ���� ������ �ּڰ��� ����Ѵ�. ������ 231-1 ���� �۰ų� ���� �ڿ����̴�. ����, �־��� ������ �����ص� ���� Ƚ���� 231-1���� �۰ų� ����.

Ǯ��:
11066�� ���� ��ġ��� ���� ������� Ǯ���ϴ� ���������ϴ�.
��, ����� ���̹Ƿ� ������ ���� �� ���� ��츦 �����մϴ�.

1. A * (B * C * D) -> ������ �ϳ��� ���, �������� ���� ���� ���
2. (A * B) * (C * D) -> ����, ������ ��� ���� ���� ���
3. (A * B * C) * D -> ������ ���� ���� ���, �������� �ϳ��� ���

���� ��ġ�� ������ ���������� ���� ���� ����� �̹� �ּҰ��� ���Ǿ��ٰ� ������ �� �ֽ��ϴ�.
���� dp �� �� �� + �� ��� ��ġ�� �� �� �ּҰ��� �������ָ� �˴ϴ�.
*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<string.h>
#include<vector>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>

int N;
vector<pii> vt;
pair<long long, pii> dp[501][501];

int main(void) {
	FIO;

	cin >> N;

	for (int i = 0; i < 501; i++)
	{
		for (int j = 0; j < 501; j++)
		{
			dp[i][j].first = 10000000000;
		}
	}

	for (int i = 1; i <= N; i++)
	{
		int a, b;
		cin >> a >> b;

		dp[i][i].second = make_pair(a, b);
		dp[i][i].first = 0;
	}

	for (int itv = 1; itv < N; itv++)
	{
		for (int start = 1; start + itv <= N; start++)
		{
			for (int mid = start; mid <= start + itv; mid++)
			{
				if (dp[start][start + itv].first > dp[start][mid].first + dp[mid + 1][start + itv].first + dp[start][start].second.first * dp[mid][mid].second.second * dp[start + itv][start + itv].second.second) {
					dp[start][start + itv].first = dp[start][mid].first + dp[mid + 1][start + itv].first + dp[start][start].second.first * dp[mid][mid].second.second * dp[start + itv][start + itv].second.second;
				}
			}
		}
	}
	cout << dp[1][N].first;
}