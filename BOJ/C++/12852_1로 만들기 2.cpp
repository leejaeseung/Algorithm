/*
문제
정수 X에 사용할 수 있는 연산은 다음과 같이 세 가지 이다.

X가 3으로 나누어 떨어지면, 3으로 나눈다.
X가 2로 나누어 떨어지면, 2로 나눈다.
1을 뺀다.
정수 N이 주어졌을 때, 위와 같은 연산 세 개를 적절히 사용해서 1을 만들려고 한다. 연산을 사용하는 횟수의 최솟값을 출력하시오.

입력
첫째 줄에 1보다 크거나 같고, 106보다 작거나 같은 자연수 N이 주어진다.

출력
첫째 줄에 연산을 하는 횟수의 최솟값을 출력한다.

둘째 줄에는 N을 1로 만드는 방법에 포함되어 있는 수를 공백으로 구분해서 순서대로 출력한다. 정답이 여러 가지인 경우에는 아무거나 출력한다.

풀이:
BFS 문제
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