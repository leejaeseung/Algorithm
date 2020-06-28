/*
문제
상근이는 영화 DVD 수집가이다. 상근이는 그의 DVD 콜렉션을 쌓아 보관한다.

보고 싶은 영화가 있을 때는, DVD의 위치를 찾은 다음 쌓아놓은 콜렉션이 무너지지 않게 조심스럽게 DVD를 뺀다. 영화를 다 본 이후에는 가장 위에 놓는다.

상근이는 DVD가 매우 많기 때문에, 영화의 위치를 찾는데 시간이 너무 오래 걸린다. 각 DVD의 위치는, 찾으려는 DVD의 위에 있는 영화의 개수만 알면 쉽게 구할 수 있다. 각 영화는 DVD 표지에 붙어있는 숫자로 쉽게 구별할 수 있다.

각 영화의 위치를 기록하는 프로그램을 작성하시오. 상근이가 영화를 한 편 볼 때마다 그 DVD의 위에 몇 개의 DVD가 있었는지를 구해야 한다.

입력
첫째 줄에 테스트 케이스의 개수가 주어진다. 테스트 케이스의 개수는 100개를 넘지 않는다.

각 테스트 케이스의 첫째 줄에는 상근이가 가지고 있는 영화의 수 n과 보려고 하는 영화의 수 m이 주어진다. (1 ≤ n, m ≤ 100,000) 둘째 줄에는 보려고 하는 영화의 번호가 순서대로 주어진다.

영화의 번호는 1부터 n까지 이며, 가장 처음에 영화가 쌓여진 순서는 1부터 증가하는 순서이다. 가장 위에 있는 영화의 번호는 1이다.

출력
각 테스트 케이스에 대해서 한 줄에 m개의 정수를 출력해야 한다. i번째 출력하는 수는 i번째로 영화를 볼 때 그 영화의 위에 있었던 DVD의 개수이다. 상근이는 매번 영화를 볼 때마다 본 영화 DVD를 가장 위에 놓는다.

풀이:
위 아래로 쌓는 게 아니라 양 옆으로 펼쳐두면 쉽게 풀립니다.
n + m 크기의 책장이 있다고 생각하면, n = 5, m = 3 일 때 다음과 같이 나타낼 수 있습니다.(f = 이번에 옮길 위치)

- - - 1 2 3 4 5
    f

m번만 dvd를 옮기므로 빈 칸은 m칸이면 충분합니다.
4번 dvd를 옮길 때 맨 처음부터 4의 바로 앞까지의 구간 합을 구하면 됩니다.

- - 4 1 2 3 - 5
  f

위와 같이 변하고, 각 dvd 번호가 옮겨진 위치를 따로 idx[] 배열에 저장하면 됩니다.
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

int t, n, m;
int tree[800005];
int idx[100001];

int update(int now, int s, int e, int idx, int v) {
	if (s > idx || e < idx)	return tree[now];
	if (s == e) {
		return tree[now] = v;
	}
	return tree[now] = update(now * 2, s, (s + e) / 2, idx, v) + update(now * 2 + 1, (s + e) / 2 + 1, e, idx, v);
}

int get(int now, int s, int e, int l, int r) {

	if (e < l || s > r)	return 0;
	if (l <= s && r >= e) {
		return tree[now];
	}
	return get(now * 2, s, (s + e) / 2, l, r) + get(now * 2 + 1, (s + e) / 2 + 1, e, l, r);
}

int main(void) {
	FIO;

	cin >> t;

	while (t--) {
		cin >> n >> m;

		for (int i = 0; i < 800005; i++)
		{
			tree[i] = 0;
		}
		for (int i = 0; i < 100001; i++)
		{
			idx[i] = 0;
		}

		for (int i = m + 1; i <= n + m; i++)
		{
			//오른쪽에 dvd를 몰아넣음
			update(1, 1, n + m, i, 1);
			idx[i - m] = i;
		}

		int front = m;

		for (int i = 0; i < m; i++)
		{
			int v;
			cin >> v;

			//옮길 dvd의 바로 앞까지 구간합을 구함.
			cout << get(1, 1, n + m, 1, idx[v] - 1) << " ";
				
			if (idx[v] != front) {
				//맨 앞 dvd가 아닌 경우 dvd를 옮김
				update(1, 1, n + m, idx[v], 0);
				idx[v] = --front;
				update(1, 1, n + m, idx[v], 1);

			}
		}
		cout << "\n";
	}
}