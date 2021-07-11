/*
문제
수정이는 어린 동생을 달래기 위해서 사탕을 사용한다. 수정이는 평소에 여러 개의 사탕을 사서 사탕상자에 넣어두고, 동생이 말을 잘 들을 때면 그 안에서 사탕을 꺼내서 주곤 한다.

각각의 사탕은 그 맛의 좋고 나쁨이 1부터 1,000,000까지의 정수로 구분된다. 1이 가장 맛있는 사탕을 의미하며, 1,000,000은 가장 맛없는 사탕을 의미한다. 수정이는 동생이 말을 잘 들은 정도에 따라서, 사탕상자 안에 있는 사탕들 중 몇 번째로 맛있는 사탕을 꺼내주곤 한다. 예를 들어 말을 매우 잘 들었을 때에는 사탕상자에서 가장 맛있는 사탕을 꺼내주고, 말을 조금 잘 들었을 때에는 사탕상자에서 여섯 번째로 맛있는 사탕을 꺼내주는 식이다.

수정이가 보관하고 있는 사탕은 매우 많기 때문에 매번 사탕상자를 뒤져서 꺼낼 사탕을 골라내는 일은 매우 어렵다. 수정이를 도와주는 프로그램을 작성하시오.

입력
첫째 줄에 수정이가 사탕상자에 손을 댄 횟수 n(1≤n≤100,000)이 주어진다. 다음 n개의 줄에는 두 정수 A, B, 혹은 세 정수 A, B, C가 주어진다. A가 1인 경우는 사탕상자에서 사탕을 꺼내는 경우이다. 이때에는 한 정수만 주어지며, B는 꺼낼 사탕의 순위를 의미한다. 이 경우 사탕상자에서 한 개의 사탕이 꺼내지게 된다. 또, A가 2인 경우는 사탕을 넣는 경우이다. 이때에는 두 정수가 주어지는데, B는 넣을 사탕의 맛을 나타내는 정수이고 C는 그러한 사탕의 개수이다. C가 양수일 경우에는 사탕을 넣는 경우이고, 음수일 경우에는 빼는 경우이다. 맨 처음에는 빈 사탕상자에서 시작한다고 가정하며, 사탕의 총 개수는 2,000,000,000을 넘지 않는다. 또한 없는 사탕을 꺼내는 경우와 같은 잘못된 입력은 주어지지 않는다.

출력
A가 1인 모든 입력에 대해서, 꺼낼 사탕의 맛의 번호를 출력한다. 물론, A=2 이면서 C<0 일 때는 출력하지 않는다.

풀이:
1 ~ 1000000 의 범위를 갖는 세그먼트 트리를 만들고 순위에 따라 트리를 이분 탐색하며 찾으면 된다.
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
#define IMAX 2147483647
#define LMAX 1000000000000500000
#define DMAX 0xFFFFFFFFFFFFF
int mv1[4] = { 0, 1, -1, 0 };
int mv2[4] = { 1, 0, 0, -1 };

int n;
int tree[4005001];
int ans;

int update(int now, int s, int e,int idx, int v) {
	if (s > idx || e < idx)	return tree[now];

	if (s == e) {
		return tree[now] += v;
	}

	return tree[now] = update(now * 2, s, (s + e) / 2, idx, v) + update(now * 2 + 1, (s + e) / 2 + 1, e, idx, v);
}

int get(int now, int s, int e, int rank) {
	if (s == e) {
		tree[now]--;
		ans = s;
		return tree[now];
	}


	int left = tree[now * 2];
	int right = tree[now * 2 + 1];

	if (left < rank) {
		return tree[now] = tree[now * 2] + get(now * 2 + 1, (s + e) / 2 + 1, e, rank - left);
	}
	else {
		return tree[now] = get(now * 2, s, (s + e) / 2, rank) + tree[now * 2 + 1];
	}
}

int main(void) {
	FIO;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int a, b, c;
		cin >> a >> b;

		if (a == 1) {
			get(1, 1, 1000000, b);
			cout << ans << "\n";
		}
		else {
			cin >> c;

			update(1, 1, 1000000, b, c);
		}
	}
}