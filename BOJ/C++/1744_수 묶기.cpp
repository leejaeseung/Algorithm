/*
����
���̰� N�� ������ �־����� ��, �� ������ ���� ���Ϸ��� �Ѵ�. ������, �׳� �� ������ ���� ��� ���ؼ� ���ϴ� ���� �ƴ϶�, ������ �� ���� �������� �Ѵ�. � ���� �������� �� ��, ��ġ�� ������� ���� �� �ִ�. ������, ���� ��ġ�� �ִ� ��(�ڱ� �ڽ�)�� ���� ���� �Ұ����ϴ�. �׸��� � ���� ���� �Ǹ�, ������ ���� ���� �� ���� ���� ���� ���� �Ŀ� ���Ѵ�.

���� ���, � ������ {0, 1, 2, 4, 3, 5}�� ��, �׳� �� ������ ���� ���ϸ� 0+1+2+4+3+5 = 15�̴�. ������, 2�� 3�� ����, 4�� 5�� ���� �Ǹ�, 0+1+(2*3)+(4*5) = 27�� �Ǿ� �ִ밡 �ȴ�.

������ ��� ���� �� �ѹ��� ���ų�, �ƴϸ� ���� �ʾƾ��Ѵ�.

������ �־����� ��, ������ �� ���� ������ ������ ��, �� ���� �ִ밡 �ǰ� �ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ������ ũ�� N�� �־�����. N�� 10,000���� �۴�. ��° �ٺ��� N���� �ٿ�, ������ �� ���� �־�����. ������ ���� -10,000���� ũ�ų� ����, 10,000���� �۰ų� ���� �����̴�.

���
���� ���� �ִ밡 ������ ������ �� ���� ����Ѵ�. ������ �׻� 231���� �۴�.

Ǯ��:
�⺻���� ���̵��� ����� ������� �������� ����, ������ �������� �������� �����Ͽ�
ū ������ 2���� ����� ���ذ��� ���̴�.
�� ��, ����� 1�� ���ϸ� �����̹Ƿ� 1�� �����ֱ⸸ �ؾ� �Ѵ�.
���� ������ Ȧ�� ���� �� ������ �����ϴµ� �̶� 0�� �ϳ��� �����ߴٸ� �� ������ ������ �� �ִ�.
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

int n;
vector<int> p;
vector<int> m;

int main(void) {
	FIO;

	cin >> n;

	int sum = 0;
	bool isZero = false;

	for (int i = 0; i < n; i++)
	{
		int v;
		cin >> v;
		if (v > 0) {
			if (v == 1)
				sum++;
			else
				p.push_back(-v);
		}
		else if (v < 0)
			m.push_back(v);
		else
			isZero = true;
	}

	sort(p.begin(), p.end());

	if (p.size() > 0) {

		for (int i = 0; i < p.size() - 1; i += 2)
		{
			sum += (-p[i] * -p[i + 1]);
		}

		if (p.size() % 2 != 0)
			sum += (-p[p.size() - 1]);

	}

	if (m.size() > 0) {

		sort(m.begin(), m.end());

		for (int i = 0; i < m.size() - 1; i += 2)
		{
			sum += (m[i] * m[i + 1]);
		}

		if (m.size() % 2 != 0) {
			if(!isZero)
				sum += (m[m.size() - 1]);
		}

	}

	cout << sum;
}