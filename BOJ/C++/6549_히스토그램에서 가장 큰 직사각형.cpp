/*
����
������׷��� ���簢�� ���� ���� �Ʒ������� ���ĵǾ� �ִ� �����̴�. �� ���簢���� ���� �ʺ� ������ ������, ���̴� ���� �ٸ� ���� �ִ�. ���� ���, ���� �׸��� ���̰� 2, 1, 4, 5, 1, 3, 3�̰� �ʺ� 1�� ���簢������ �̷���� ������׷��̴�.



������׷����� ���� ���̰� ū ���簢���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
�Է��� �׽�Ʈ ���̽� ���� ���� �̷���� �ִ�. �� �׽�Ʈ ���̽��� �� �ٷ� �̷���� �ְ�, ���簢���� �� n�� ���� ó������ �־�����. (1 �� n �� 100,000) �� ���� n���� ���� h1, ..., hn (0 �� hi �� 1,000,000,000)�� �־�����. �� ���ڵ��� ������׷��� �ִ� ���簢���� �����̸�, ���ʺ��� �����ʱ��� ������� �־�����. ��� ���簢���� �ʺ�� 1�̰�, �Է��� ������ �ٿ��� 0�� �ϳ� �־�����.

���
�� �׽�Ʈ ���̽��� ���ؼ�, ������׷����� ���� ���̰� ū ���簢���� ���̸� ����Ѵ�.

Ǯ��:
� ���̰� h �� ���簢���� �� ��, ���� ���� top �� ���� �۰ų� ������,
���� top�� ���̷� ���簢���� ���̸� ���ؾ� �Ѵ�.(���̰� �۾������Ƿ�)

h ���� ���� top�� ���̰� ���ų� ���� ��� ��Ÿ���� ���� �ش� ��Ÿ���� ���̷� �ϴ� ���簢���� ���̸� ���Ѵ�.
������ ���̴� ���� ~ ���� top�� ��Ÿ�� ��ġ - 1 �� �ȴ�.

��� ������ ���� �� ���� ��Ÿ���� ���ÿ� push �Ѵ�.
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
#define MOD 20091101
int mv1[4] = { 0, 0, 1, -1 };
int mv2[4] = { 1, -1, 0, 0 };
int mv_all1[8] = { 0, 1, 0, -1, -1, -1, 1, 1 };
int mv_all2[8] = { 1, 0, -1, 0 , -1, 1, -1, 1 };

int n;

int main(void) {
	FIO;

	while (true) {
		cin >> n;

		if (n == 0)	break;

		vector<ll> vt;
		stack<ll> st;

		ll ans = 0;
		
		for (int i = 0; i < n; i++)
		{
			int v;
			cin >> v;
			vt.push_back(v);
		}

		vt.push_back(0);

		for (ll i = 0; i <= n; i++)
		{
			while (!st.empty() && vt[st.top()] >= vt[i]) {
				ll prv = st.top();
				st.pop();

				ll width;
				if (st.empty())
					width = i;
				else
					width = (i - st.top() - 1);
				ans = max(ans, vt[prv] * width);
			}

			st.push(i);
		}

		cout << ans << "\n";
	}
}