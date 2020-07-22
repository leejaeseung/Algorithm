/*
����
N���� �� �߿��� � ���� �ٸ� �� �� ���� ������ ��Ÿ�� �� �ִٸ� �� ���� ������(GOOD)���� �Ѵ�.

N���� ���� �־����� �� �߿��� ���� ���� ������ �� ������ ����϶�.

�Է�
ù° �ٿ��� ���� ���� N(1 �� N �� 2,000), �� ��° �ٿ��� i��° ���� ��Ÿ���� Ai�� N�� �־�����. (|Ai| �� 1,000,000,000, Ai�� ����)

���
���� ���� ������ ù ��° �ٿ� ����Ѵ�.

Ǯ��:
�̺�Ž�� �������� multimap ���� �ƽ��ƽ��ϰ� ����߽��ϴ�.

�迭�� ���� �ߺ�, �ڱ� �ڽ��� ������ �� �� �� ����ó���ؾ� �ϴ� �� ���� ��ٷο� �����Դϴ�.

�ߺ��� ���Ǵ� multimap�� �̿��� ���� ������ ��� map�� ��µ�, �� �� �� ���� �ε����� ��� �����մϴ�.
���� ���� ���� ��� map�� ������� ó�� �迭�� ��� ���鼭 �ش� ���� ���� ������ �Ǻ��� �ݴϴ�.

- ���� ���� ���� ��, �ش� ���� ���� �ε��� �� ���� ���� �迭�� �ε����� ��ģ�ٸ� ���� �ʽ��ϴ�.
- ���� ���� ���� �� �ִ� ���� ��찡 �ֱ� ������ lower_bound~upper_bound���� ��� ���� �ݴϴ�.
*/
#include<iostream>
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
int mv1[4] = { 0, 1, 0, -1 };
int mv2[4] = { 1, 0, -1, 0 };

int n;
ll arr[2001];
multimap<ll, pii> m;

int main(void) {
	FIO;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			m.insert(make_pair(arr[i] + arr[j], make_pair(i, j)));
		}
	}

	int cnt = 0;

	for (int i = 0; i < n; i++)
	{
		for (auto iter = m.lower_bound(arr[i]); iter != m.upper_bound(arr[i]); iter++)
		{
			pii idxes = iter->second;

			if (idxes.first != i && idxes.second != i) {
				cnt++;
				break;
			}

		}
	}

	cout << cnt;
}