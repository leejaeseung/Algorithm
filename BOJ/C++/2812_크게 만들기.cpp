/*
����
N�ڸ� ���ڰ� �־����� ��, ���⼭ ���� K���� ������ ���� �� �ִ� ���� ū ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� N�� K�� �־�����. (1 �� K < N �� 500,000)

��° �ٿ� N�ڸ� ���ڰ� �־�����. �� ���� 0���� �������� �ʴ´�.

���
�Է����� �־��� ���ڿ��� K���� ������ �� ���� �� �ִ� ���� ū ���� ����Ѵ�.

Ǯ��:
������ Ȱ���� �׸��� �˰��� �����Դϴ�.

���ÿ� �ϳ��� ���ڸ� �־��, ������ top���� ū ���� ������ ������ top�� �� ũ�ų� ������ ������ ������ pop�մϴ�.
��, pop�� �ִ� k�� ��ŭ�� �����ؾ� �մϴ�.
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

int n, k;
string num;
stack<int> st;

int main(void) {
	FIO;

	cin >> n >> k >> num;

	for (int i = 0; i < num.size(); i++)
	{
		int now = num[i] - '0';

		while (k > 0 && !st.empty() && st.top() < now) {
			st.pop();
			k--;
		}
		st.push(now);
	}

	while (k--) {
		st.pop();
	}

	stack<int> out;

	while (!st.empty()) {
		out.push(st.top());
		st.pop();
	}

	while (!out.empty()) {
		cout << out.top();
		out.pop();
	}
}