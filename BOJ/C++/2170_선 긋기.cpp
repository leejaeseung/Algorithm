/*
����
�ſ� ū ��ȭ���� �ڸ� ��� ���� �������� �Ѵ�. ���� ���� ������ ���� �� ������ �ٸ� �� ������ �߰� �ȴ�. ���� ���� ������ �̹� ���� �ִ� ��ġ�� ���ļ� �׸� ���� �ִµ�, ���� �� ���� ���� �� �� ���� ���� ���̸� ������ �� ���ٰ� ����.

�̿� ���� ������ ���� �׾��� ��, �׷��� ��(��)�� �� ���̸� ���ϴ� ���α׷��� �ۼ��Ͻÿ�. ���� ���� �� �׷��� ���� �� ������ ����Ѵ�.

�Է�
ù° �ٿ� ���� ���� Ƚ�� N(1��N��1,000,000)�� �־�����. ���� N���� �ٿ��� ���� ���� �� ������ �� ���� �־�����. ������ ������ -1,000,000,000 �̻� 1,000,000,000 ������ �����̴�.

���
ù° �ٿ� ���� ���� �� ���̸� ����Ѵ�.

Ǯ��:
���� ���� ���� ������������ �����ϰ�, ������ ���ʴ�� ���鼭 ������ �������ٸ� ���ο� ������ ����ϴ�.
��ġ�� �ʴ´ٸ� �������� ���� ���� ���̸� �信 ���ϰ� �ٽ� �����մϴ�.
*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<string>
#include<vector>
#include<queue>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>

int N;
vector<pii> vt;

int main(void) {
	FIO;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int x, y;
		cin >> x >> y;
		vt.push_back(make_pair(min(x, y), max(x, y)));
	}

	sort(vt.begin(), vt.end());
	
	int maxS = vt[0].first;
	int maxE = vt[0].second;
	int ans = maxE - maxS;
	int realAns = 0;

	for (int i = 1; i < N; i++)
	{
		int nowS = vt[i].first;
		int nowE = vt[i].second;

		if (nowS <= maxE) {
			maxE = max(nowE, maxE);
		}
		else {
			realAns += ans;
			ans = 0;
			maxS = nowS;
			maxE = nowE;
		}
		ans = max(ans, maxE - maxS);
	}
	cout << realAns + ans;
}