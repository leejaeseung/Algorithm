/*
����
������׷��� ���ؼ� �˰� �ִ°�? ������׷��� �Ʒ��� ���� ����׷����� ���Ѵ�.



�� ĭ�� ������ �����ϰ�, ���̴� � ������ �־�����. �� �׸��� ��� ���̰� ���� 2 1 4 5 1 3 3�̴�.

�̷��� ������׷��� ���ο� ���� ���̰� ū ���簢���� �׸����� �Ѵ�. �Ʒ� �׸��� ���� ģ �κ��� �� ���̴�. �� ���簢���� �غ��� �׻� ������׷��� �Ʒ����� �����ϰ� �׷����� �Ѵ�.



�־��� ������׷��� ����, ���� ū ���簢���� ���̸� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù �࿡�� N (1 �� N �� 100,000) �� �־�����. N�� ������׷��� ���� ĭ�� ���̴�. ���� N �࿡ ���� �� ĭ�� ���̰� ���ʿ������� ���ʴ�� �־�����. �� ĭ�� ���̴� 1,000,000,000���� �۰ų� ���� �ڿ��� �Ǵ� 0�̴�.

���
ù° �ٿ� ���� ū ���簢���� ���̸� ����Ѵ�. �� ���� 20���� ���� �ʴ´�.

Ǯ��:
����- �������� Ǯ���߽��ϴ�.

����, ������ �������� ������, ���İ��� �ִ��� �����ϴµ�, � ���� s~e ���� �ִ��� ������ ����մϴ�.

1. ���ʿ����� �ִ�
2. �����ʿ����� �ִ�
3. ����, �������� ��ģ ���� �������� �߰��������� �����ؼ� �� ������ ���η� ĥ�غ����� ���� �ִ�

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

ll n;
ll arr[100001];

ll getMax(ll s, ll e) {
	if (s == e) {
		return arr[s];
	}

	ll mid = (s + e) / 2;

	ll ret = max(getMax(s, mid), getMax(mid + 1, e));

	ll l = mid, r = mid + 1;
	ll h = min(arr[l], arr[r]);

	ret = max(ret, h * (r - l + 1));

	while (l > s || r < e) {
		if (r < e && (l == s || arr[r + 1] > arr[l - 1])) {
			h = min(h, arr[++r]);
		}
		else {
			h = min(h, arr[--l]);
		}
		ret = max(ret, h * (r - l + 1));
	}
	return ret;
}

int main(void) {
	FIO;

		cin >> n;

		for (int i = 1; i <= n; i++)
		{
			cin >> arr[i];
		}

		cout << getMax(1, n);
}