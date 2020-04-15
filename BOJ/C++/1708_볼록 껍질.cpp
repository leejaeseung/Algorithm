/*
����
�ٰ����� ������ �� �������� �����ϴ� ������ �׻� �ٰ��� ���ο� �����ϴ� �ٰ����� ���� �ٰ����̶�� �Ѵ�. �Ʒ� �׸����� (a)�� ���� �ٰ����̸�, (b)�� ���� �ٰ����� �ƴϴ�.



���ݸ� ������ ���� �ٰ����� ��� ������ 180�� ������ �� ���� �ٰ����� �ȴٴ� ���� �� �� �ִ�. ���ǻ� �� ���������� 180�� �̸��� ��츸�� ���� �ٰ������� �����ϵ��� �Ѵ�.

2���� ��鿡 N���� ���� �־����� ��, �̵� �� �� ���� ���� ��� ���� �ٰ����� ����µ�, ������ ��� ���� ���ο� �����ϵ��� �� �� �ִ�. �̸� ���� ���� (CONVEX HULL) �̶� �Ѵ�. �Ʒ� �׸��� N=10�� ����� �� ���̴�.



���� ������ �־����� ��, ���� ������ �̷�� ���� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ���� ���� N(3 �� N �� 100,000)�� �־�����. ��° �ٺ��� N���� �ٿ� ���� �� ���� x��ǥ�� y��ǥ�� �� ĭ�� ���̿� �ΰ� �־�����. �־����� ��� ���� ��ǥ�� �ٸ��ٰ� �����ص� ����. x��ǥ�� y��ǥ�� ������ ���� 40,000�� ���� �ʴ´�. �Է����� �־����� �ٰ����� ��� ���� �������� �̷�� ���� ����.

���
ù° �ٿ� ���� ������ �̷�� ���� ������ ����Ѵ�.

���� ������ ���� ���� ���� �� �ִ� ��쿡�� ���� �� �� ���� ������ �����Ѵ�.

Ǯ��:
���� ����(Convex Hull) ���������ϴ�. ������ ���� �����մϴ�.

1. �������� ��´� -> y �� ���� ���� ��, y �� ���ٸ� x�� ���� ���� ��
2. ������ �ݽð� �������� �����Ѵ�. -> CCW�� �̿��� ������, p1, p2�� ���� 
�� ���� �ݽð� �����̶�� True, �ð� �����̶�� False, �������� �� p1�� �������� ������ True, �ָ� False�� �����ϴ� Comparator�� �����մϴ�.
3. ���ĵ� ���鿡 ���� �׶��� ��ĵ �˰����� ����մϴ�.
- ������ ������ - 1 = first
- ������ ������ = second
- ���� ���ϴ� �� = next

�� �� �� first, second, next�� ���� CCW�� �����մϴ�.
CCW > 0  -> ���ÿ� next�� �ֽ��ϴ�.
CCW <= 0 -> ���ϲ����� �ƴϹǷ� ������ first, second�� �ǵ����� ���� ������ pop �մϴ�.(�� �۾��� CCW > 0 �� �� ������ �����մϴ�.)

���� ������ ũ�Ⱑ ������ �˴ϴ�.
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
#define pll pair<long long, long long>
#define ll long long

int N;
vector <pll> vt;
pll start = make_pair(100001, 100001);

void findStart() {

	for (int i = 0; i < N; i++)
	{
		int x = vt[i].first;
		int y = vt[i].second;

		if (start.second > y) {
			start.first = x;
			start.second = y;
		}
		else if (start.second == y) {
			if (start.first > x) {
				start.first = x;
				start.second = y;
			}
		}
	}
}

ll dist(pll p1, pll p2) {
	return (p2.first - p1.first) * (p2.first - p1.first) + (p2.second - p1.second) * (p2.second - p1.second);
}

int CCW(pll p1, pll p2, pll p3) {
	ll S = (p2.first - p1.first) * (p3.second - p1.second) - (p2.second - p1.second) * (p3.first - p1.first);

	if (S > 0)	return 1;
	else if (S == 0)	return 0;
	else
		return -1;
}

int myCom(pll p1, pll p2) {
	int ret;
	int com = CCW(start, p1, p2);

	if (com == 0) {
		ret = (dist(start, p1) < dist(start, p2));
	}
	else if (com == 1) {
		ret = 1;
	}
	else {
		ret = 0;
	}
	return ret;
}

int main(void) {
	FIO;

	cin >> N;

	int ans = 0;

	for (int i = 0; i < N; i++)
	{
		int x, y;
		cin >> x >> y;

		vt.push_back(make_pair(x, y));
	}

	findStart();

	sort(vt.begin(), vt.end(), myCom);

	vector<pll> st;
	st.push_back(vt[0]);

	for (int i = 1; i < vt.size(); i++)
	{

		pll next = vt[i];

		while (st.size() > 1 && CCW(st[st.size() - 2], st[st.size() - 1], next) <= 0) {
			st.pop_back();
		}
		st.push_back(next);
	}

	cout << st.size();
}