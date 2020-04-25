/*
����
�ν��̴� �����п����� �ܾ� ���� ������ Ǫ�� ������ �޾Ҵ�.

�ܾ� ���� ������ N���� �ܾ�� �̷���� ������, �� �ܾ�� ���ĺ� �빮�ڷθ� �̷���� �ִ�. �̶�, �� ���ĺ� �빮�ڸ� 0���� 9������ ���� �� �ϳ��� �ٲ㼭 N���� ���� ���ϴ� �����̴�. ���� ���ĺ��� ���� ���ڷ� �ٲ�� �ϸ�, �� �� �̻��� ���ĺ��� ���� ���ڷ� �ٲ������ �� �ȴ�.

���� ���, GCF + ACDEB�� ����Ѵٰ� �� ��, A = 9, B = 4, C = 8, D = 6, E = 5, F = 3, G = 7�� �����Ѵٸ�, �� ���� ���� 99437�� �Ǿ �ִ밡 �� ���̴�.

N���� �ܾ �־����� ��, �� ���� ���� �ִ�� ����� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �ܾ��� ���� N(1 �� N �� 10)�� �־�����. ��° �ٺ��� N���� �ٿ� �ܾ �� �ٿ� �ϳ��� �־�����. �ܾ�� ���ĺ� �빮�ڷθ� �̷�����ִ�. ��� �ܾ ���ԵǾ� �ִ� ���ĺ��� �ִ� 10���̰�, ���� �ִ� ���̴� 8�̴�. ���� �ٸ� ���ڴ� ���� �ٸ� ���ڸ� ��Ÿ����.

���
ù° �ٿ� �־��� �ܾ��� ���� �ִ��� ����Ѵ�.

Ǯ��:
�ߺ��� ������ ��� ���ĺ��� 0~9 ������ ���� �־�� Ǫ�� ��Ʈ��ŷ ��İ�
���������� Ǯ���ϴ� ����� �ֽ��ϴ�.

�⺻���� ���̵��� ���� �ڸ����� ���� ���ĺ����� 9���� �Ҵ��ذ��� ����Դϴ�.
ABC
BCA
�� �������� A�� B �� �� �������� 9�� �Ҵ��� �� �ָ��� �κ��� �ֽ��ϴ�.

�� ���� �ٽ� ����
100A + 10B + C
100B + 10C + A
�� �� �� ���� ��� ������ ��
110B + 101A + 11C 
�̹Ƿ� B�� ���� �켱������ �������ϴ�.
���� B->A->C ������ ū ���ڵ��� �Ҵ����ָ� �˴ϴ�.
*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<vector>
#include<queue>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>

int N;
vector<string> vt;
vector<pair<int, char>> alpha;
vector<char> newA;
int v[26];
bool visit[26];
int value[26];

int ans = 0;

int StoI(string s) {
	int ret = 0;

	for (int i = 0; i < s.size(); i++)
	{
		char now = s[i] - 'A';

		ret += value[now];
		ret *= 10;
	}
	return ret / 10;
}

int calc() {
	int ret = 0;
	for (int i = 0; i < N; i++)
	{
		ret += StoI(vt[i]);
	}

	return ret;
}

int main(void) {
	FIO;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		vt.push_back(s);

		for (int i = 0; i < s.size(); i++)
		{
			char now = s[i] - 'A';

				alpha.push_back(make_pair((int)pow(10, (int)s.size() - i - 1), now));
		}
	}

	for (int i = 0; i < alpha.size(); i++)
	{
		int n = alpha[i].first;
		char now = alpha[i].second;

		v[now] += n;

		if (!visit[now]) {
			visit[now] = true;
			newA.push_back(now);
		}
	}

	priority_queue<pair<int, char>> pq;

	for (int i = 0; i < newA.size(); i++)
	{
		pq.push(make_pair(v[newA[i]], newA[i]));
	}

	int number = 9;
	while (!pq.empty()) {
		char now = pq.top().second;
		pq.pop();

		value[now] = number--;
	}

	cout << calc();
}

//#include<iostream>
//#include<algorithm>
//#include<math.h>
//#include<string>
//#include<vector>
//#include<stack>
//using namespace std;
//#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
//#define pii pair<int, int>
//
//int N;
//vector<string> vt;
//vector<pair<int, char>> alpha;
//vector<char> newA;
//bool visit[26];
//int value[26];
//bool num[10];
//
//int ans = 0;
//
//void recul(int cnt) {
//	if (cnt >= newA.size()) {
//
//		int sum = 0;
//		for (int i = 0; i < N; i++) {
//			int num = 0;
//			for (int j = 0; j < vt[i].length(); j++) {
//				char now = vt[i][j] - 'A';
//
//				num *= 10;
//				num += value[now];
//			}
//			sum += num;
//		}
//
//		ans = max(ans, sum);
//		return;
//	}
//
//	char now = newA[cnt];
//
//		for (int i = 9; i >= 0; i--)
//		{
//			if (!num[i]) {
//				value[now] = i;
//				num[i] = true;
//				recul(cnt + 1);
//				value[now] = 0;
//				num[i] = false;
//			}
//		}
//}
//
//int main(void) {
//	FIO;
//
//	cin >> N;
//
//	for (int i = 0; i < N; i++)
//	{
//		string s;
//		cin >> s;
//		vt.push_back(s);
//
//		for (int i = 0; i < s.size(); i++)
//		{
//			char now = s[i] - 'A';
//
//			alpha.push_back(make_pair(-((int)s.size() - i - 1), now));
//		}
//	}
//
//	sort(alpha.begin(), alpha.end());
//
//	for (int i = 0; i < alpha.size(); i++)
//	{
//		char now = alpha[i].second;
//
//		if (!visit[now]) {
//			visit[now] = true;
//			newA.push_back(now);
//		}
//	}
//
//	recul(0);
//
//	cout << ans;
//}