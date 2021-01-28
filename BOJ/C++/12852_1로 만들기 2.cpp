/*
����
���� X�� ����� �� �ִ� ������ ������ ���� �� ���� �̴�.

X�� 3���� ������ ��������, 3���� ������.
X�� 2�� ������ ��������, 2�� ������.
1�� ����.
���� N�� �־����� ��, ���� ���� ���� �� ���� ������ ����ؼ� 1�� ������� �Ѵ�. ������ ����ϴ� Ƚ���� �ּڰ��� ����Ͻÿ�.

�Է�
ù° �ٿ� 1���� ũ�ų� ����, 106���� �۰ų� ���� �ڿ��� N�� �־�����.

���
ù° �ٿ� ������ �ϴ� Ƚ���� �ּڰ��� ����Ѵ�.

��° �ٿ��� N�� 1�� ����� ����� ���ԵǾ� �ִ� ���� �������� �����ؼ� ������� ����Ѵ�. ������ ���� ������ ��쿡�� �ƹ��ų� ����Ѵ�.

Ǯ��:
BFS ����
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
int mv1[4] = { 0, 0, 1, 1 };
int mv2[4] = { 0, 1, 0, 1 };

queue<pii> q;
int prv[1000001];
bool visit[1000001];

int main() {
	FIO;

	int n;
	cin >> n;

	q.push({n, 0});
	visit[n] = false;
	prv[n] = -1;

	while (!q.empty()) {
		int now = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (now == 1) {
			cout << cnt << "\n";
			break;
		}

		if (now % 3 == 0) {
			if (!visit[now / 3]) {
				visit[now / 3] = true;
				prv[now / 3] = now;
				q.push({ now / 3, cnt + 1 });
			}
		}
		
		if (now % 2 == 0) {
			if (!visit[now / 2]) {
				visit[now / 2] = true;
				prv[now / 2] = now;
				q.push({ now / 2, cnt + 1 });
			}
		}

		if (!visit[now - 1]) {
			visit[now - 1] = true;
			prv[now - 1] = now;
			q.push({ now - 1, cnt + 1 });
		}
	}

	stack<int> st;
	int tmp = 1;
	while (tmp != -1) {
		st.push(tmp);
		tmp = prv[tmp];
	}

	while (!st.empty()) {
		cout << st.top() << " ";
		st.pop();
	}

}