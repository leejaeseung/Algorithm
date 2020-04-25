/*
문제
민식이는 수학학원에서 단어 수학 문제를 푸는 숙제를 받았다.

단어 수학 문제는 N개의 단어로 이루어져 있으며, 각 단어는 알파벳 대문자로만 이루어져 있다. 이때, 각 알파벳 대문자를 0부터 9까지의 숫자 중 하나로 바꿔서 N개의 수를 합하는 문제이다. 같은 알파벳은 같은 숫자로 바꿔야 하며, 두 개 이상의 알파벳이 같은 숫자로 바뀌어지면 안 된다.

예를 들어, GCF + ACDEB를 계산한다고 할 때, A = 9, B = 4, C = 8, D = 6, E = 5, F = 3, G = 7로 결정한다면, 두 수의 합은 99437이 되어서 최대가 될 것이다.

N개의 단어가 주어졌을 때, 그 수의 합을 최대로 만드는 프로그램을 작성하시오.

입력
첫째 줄에 단어의 개수 N(1 ≤ N ≤ 10)이 주어진다. 둘째 줄부터 N개의 줄에 단어가 한 줄에 하나씩 주어진다. 단어는 알파벳 대문자로만 이루어져있다. 모든 단어에 포함되어 있는 알파벳은 최대 10개이고, 수의 최대 길이는 8이다. 서로 다른 문자는 서로 다른 숫자를 나타낸다.

출력
첫째 줄에 주어진 단어의 합의 최댓값을 출력한다.

풀이:
중복을 제거한 모든 알파벳에 0~9 까지의 값을 넣어가며 푸는 백트래킹 방식과
수학적으로 풀이하는 방법이 있습니다.

기본적인 아이디어는 가장 자리수가 높은 알파벳에게 9부터 할당해가는 방법입니다.
ABC
BCA
위 예제같이 A와 B 둘 중 누구에게 9를 할당할 지 애매한 부분이 있습니다.

위 식을 다시 쓰면
100A + 10B + C
100B + 10C + A
즉 위 두 식을 모두 더했을 때
110B + 101A + 11C 
이므로 B가 가장 우선순위가 높아집니다.
따라서 B->A->C 순으로 큰 숫자들을 할당해주면 됩니다.
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