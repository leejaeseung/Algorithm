/*
����
������ ��Ŀ â���̴� ��� ��ȣ�� ���� ����� �߰��ߴ�. �� ����� �󵵸� �����ϴ� ���̴�.

â���̴� ���� �� ���� ����� �̿��ؼ� ���찡 �����̿��� ������ �޽����� ȹ���ߴ�. �� �޽����� ���� N���� �̷���� �����̰�, ���ڴ� ��� C���� �۰ų� ����. â���̴� �� ���ڸ� ���� �����ϴ� �󵵼���� �����Ϸ��� �Ѵ�.

����, ������ �� �� X�� Y�� ���� ��, X�� Y���� �������� ���� �����ϴ� ��쿡�� X�� Y���� �տ� �־�� �Ѵ�. ����, �����ϴ� Ƚ���� ���ٸ�, ���� ���� ���� �տ� �־�� �Ѵ�.

�̷��� �����ϴ� ����� �� �����̶�� �Ѵ�.

������ �־����� ��, �� ������ �ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù�� �ٿ� �޽����� ���� N�� C�� �־�����. (1 �� N �� 1,000, 1 �� C �� 1,000,000,000)

��° �ٿ� �޽��� ������ �־�����.

���
ù° �ٿ� �Է����� �־��� ������ �� ������ ���� ����Ѵ�.

Ǯ��:
�ʿ� �� ���� �� ���� �ε����� pair�� �־� �󵵼��� ū ��, �ε����� ���� ������ �����Ͽ� ����մϴ�.
*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<queue>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>

string arr[1001];
map<string, pair<int, int> > m;
priority_queue<pair<pair<int, int >, string > > pq;

int main(void) {
	FIO;

	int N, C;
	cin >> N >> C;

	for (int i = 0; i < N ; i++)
	{
		string str;
		cin >> str;
		arr[i] = str;

		if (m.find(str) == m.end())
			m.insert(make_pair(str, make_pair(1, i)));
		else
			m[str].first++;
	}
	for (int i = 0; i < N; i++)
	{
		if (m[arr[i]].first != 0) {
			pq.push(make_pair(make_pair(m[arr[i]].first, -m[arr[i]].second), arr[i]));

			m[arr[i]].first = 0;
		}
	}
	while (!pq.empty()) {
		string nowstr = pq.top().second;
		int cnt = pq.top().first.first;
		pq.pop();
		while (cnt--)
			cout << nowstr << " ";
	}
}