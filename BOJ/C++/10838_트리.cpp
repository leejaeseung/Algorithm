/*
문제
N개의 노드로 구성된 루트가 있는 트리가 다음과 같이 주어진다. 각 노드는 0부터 N-1까지의 번호로 구별되고, 0번 노드는 루트 노드이고, 나머지 노드 각각은 0번 노드의 자식 노드이다.

트리에 적용할 수 있는 연산은 세 종류이며, 이를 통해 트리의 모양을 바꾸거나 트리 에지에 색칠을 할 수 있다. 각 연산과 그 의미는 다음과 같다.

paint(a, b, c): a번 노드와 b번 노드를 잇는 최단 경로를 찾은 후, 경로 상에 있는 모든 에지를 색깔 c로 칠한다.
move(a, b): a번 노드의 부모 노드를 b번 노드로 바꾼다. 단, b번 노드는 a번 노드를 루트로 하는 부트리(subtree)에 속하지 않는다. 부모 노드를 바꾸기 전 a번 노드의 부모 노드를 p라 할 때, 새로운 에지 (a,b)는 원래의 에지 (a,p)의 색깔을 갖는다.
count(a, b): a번 노드와 b번 노드를 잇는 최단경로를 찾은 후, 그 경로 사이에 있는 에지에 칠해진 서로 다른 색깔의 개수를 출력한다.
에지에 칠하는 색깔 c를 정수로 표시한다. 그리고 처음에는 모든 에지의 색깔이 0이라고 가정한다.

예를 들어, 그림 1에서 보인 것처럼 6개의 노드로 구성된 초기 트리에 적용된 연산이 차례로

move(1,3); move(5,3); paint(5,4,8); move(3,4); paint(0,3,7); count(2,5);

일 때, 각 연산을 실행한 후 어떻게 트리의 모양과 에지 색깔이 바뀌는지를 아래 그림 2부터 그림 4에서 차례대로 보였다.



그림 1. 초기 형태



그림 2. 좌측: move(1,3)을 실행한 후, 우측: move(5,3)을 실행 한 후



그림 3. paint(5,4,8)을 실행한 후



그림 4. 좌측: move(3,4)를 실행한 후, 우측: paint(0,3,7)을 실행한 후

그리고, 마지막 연산 count(2,5)에 대한 결과로는 3을 출력하게 된다. 왜냐하면, 그림 4의 우측 그림에서 보듯이 2번 노드와 5번 노드 사이의 최단 경로 상에 있는 에지들에 칠해진 색깔이 {0,7,8}로 3가지이기 때문이다.

트리에 대한 정보와 일련의 연산이 주어질 때, 각 연산을 효과적으로 실행하는 프로그램을 작성하시오.

입력
첫째 줄에는 앞에서 설명한 트리의 노드 개수를 나타내는 정수 N(1 ≤ N ≤ 105)과 연산의 개수를 나타내는 정수 K(1 ≤ K ≤ 3×105)가 주어진다. 이어서 K 줄에 걸쳐 각 연산에 관한 정보가 한 줄에 하나씩 주어지는데, 각 줄에는 연산의 종류를 나타내는 정수 r(1 ≤ r ≤ 3)이 첫 번째로 주어진다.

r = 1일 경우엔 연산이 paint 임을 의미하며, 세 정수 (a,b,c)가 추가로 같은 줄에 주어지는데, 여기서 a, b(0 ≤ a, b ≤ N-1)는 노드 번호를, c(0 ≤ c ≤109)는 색의 번호를 나타낸다.
r = 2일 경우엔 연산이 move임을 의미하며, 두 정수 a, b(1 ≤ a ≤ N-1, 0 ≤ b ≤ N-1)가 추가로 같은 줄에 주어지는데, 이는 노드 번호를 나타낸다.
r = 3일 경우엔 연산이 count임을 의미하며, 두 정수 a, b(0 ≤ a, b ≤ N-1)가 추가로 같은 줄에 주어지는데, 이는 노드 번호를 나타낸다.
노드의 개수가 N인 트리의 초기 모양은 그림 1에서 보인 것처럼 0번 노드가 루트이고, 나머지 노드들의 부모 노드는 0번 노드이며, 초기 트리의 모든 에지 색깔은 0이라고 가정한 사실을 기억하기 바란다.

또한, paint와 count 연산 시 a번 노드와 b번 노드 사이의 최단경로의 길이는 항상 1,000 이하이다.

출력
입력에서 주어진 count 연산 각각에 대해, 그 순서대로 그 때의 결과 값을 한 줄에 출력한다.

풀이:
조건에 최단 거리가 최대 1000임을 인지해야 한다.
그러면 최대 3억번의 연산만으로 가능하다.
단, LCA(최소 조상) 을 찾을 때도 1000번 이상 찾을 이유가 없기 때문에 예외처리를 해주어야 시간 초과가 안난다.
색의 범위가 매우 크므로 좌표 압축을 하거나 set을 사용하면 된다.
set 을 사용했을 때가 시간이 덜 걸렸다.
*/

//좌표 압축 코드

#include<iostream>
#include<memory.h>
#include<algorithm>
#include<math.h>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
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
int mv1[4] = { 0, 0, 1, -1 };
int mv2[4] = { 1, -1, 0, 0 };
int mv_all1[8] = { 0, 1, 0, -1, -1, -1, 1, 1 };
int mv_all2[8] = { 1, 0, -1, 0 , -1, 1, -1, 1 };

int n, k;
int parent[100001];
int color[100001];
set<int> color_set;
vector<int> colors;
bool visit[300001];
int ancCheck[100001];
int anc_idx = 1;

int getAnc(int n1, int n2) {
	//최소 조상을 구할 때, 최대 1000번의 이동만 한다.

	int move = 0;

	while (n1 != 0 && move <= 1000) {
		ancCheck[n1] = anc_idx;
		n1 = parent[n1];
		move++;
	}

	move = 0;

	while (n2 != 0 && move <= 1000) {
		if (ancCheck[n2] == anc_idx) {
			anc_idx++;
			return n2;
		}
		n2 = parent[n2];
		move++;
	}

	anc_idx++;
	return n1;
}

void paint(int n1, int n2, int c) {
	
	int anc = getAnc(n1, n2);

	while (n1 != anc) {
		color[n1] = c;
		n1 = parent[n1];
	}

	while (n2 != anc) {
		color[n2] = c;
		n2 = parent[n2];
	}
}

int cnt(int n1, int n2) {

	vector<int> check;

	int ret = 0;
	int anc = getAnc(n1, n2);

	while (n1 != anc) {
		int nowC = lower_bound(colors.begin(), colors.end(), color[n1]) - colors.begin();

		if (!visit[nowC]) {
				ret++;
				visit[nowC] = true;
				check.push_back(nowC);
		}

		n1 = parent[n1];
	}

	while (n2 != anc) {
		int nowC = lower_bound(colors.begin(), colors.end(), color[n2]) - colors.begin();

		if (!visit[nowC]) {
			ret++;
			visit[nowC] = true;
			check.push_back(nowC);
		}

		n2 = parent[n2];
	}

	for (int i = 0; i < check.size(); i++)
	{
		visit[check[i]] = false;
	}

	return ret;
}

int main(void) {
	FIO;

	cin >> n >> k;

	queue<pair<pii, pii>> query;

	parent[0] = -1;
	color_set.insert(0);

	for (int i = 1; i <= n; i++)
	{
		parent[i] = 0;
	}

	for (int i = 0; i < k; i++)
	{
		int r, a, b, c;
		cin >> r >> a >> b;

		if (r == 1) {
			cin >> c;
			query.push({ {r, a}, {b, c} });
			color_set.insert(c);
		}
		else {
			query.push({ {r, a}, {b, -1} });
		}
	}

	for (auto iter = color_set.begin(); iter != color_set.end(); iter++)
	{
		//좌표 압축
		colors.push_back(*iter);
	}

	while (!query.empty()) {
		int r = query.front().first.first;
		int a = query.front().first.second;
		int b = query.front().second.first;
		int c = query.front().second.second;
		query.pop();

		if (r == 1) {
			paint(a, b, c);
		}
		else if (r == 2) {
			parent[a] = b;
		}
		else {
			cout << cnt(a, b) << "\n";
		}
	}
}

//map 사용 코드

/*#include<iostream>
#include<memory.h>
#include<algorithm>
#include<math.h>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
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
int mv1[4] = { 0, 0, 1, -1 };
int mv2[4] = { 1, -1, 0, 0 };
int mv_all1[8] = { 0, 1, 0, -1, -1, -1, 1, 1 };
int mv_all2[8] = { 1, 0, -1, 0 , -1, 1, -1, 1 };

int n, k;
int parent[100001];
int color[100001];
int ancCheck[100001];
int anc_idx = 1;

int getAnc(int n1, int n2) {

	int move = 0;

	while (n1 != 0 && move <= 1000) {
		ancCheck[n1] = anc_idx;
		n1 = parent[n1];
		move++;
	}

	move = 0;

	while (n2 != 0 && move <= 1000) {
		if (ancCheck[n2] == anc_idx) {
			anc_idx++;
			return n2;
		}
		n2 = parent[n2];
		move++;
	}

	anc_idx++;
	return n1;
}

void paint(int n1, int n2, int c) {

	int anc = getAnc(n1, n2);

	while (n1 != anc) {
		color[n1] = c;
		n1 = parent[n1];
	}

	while (n2 != anc) {
		color[n2] = c;
		n2 = parent[n2];
	}
}

int cnt(int n1, int n2) {

	set<int> visit;

	int ret = 0;
	int anc = getAnc(n1, n2);

	while (n1 != anc) {
		int nowC = color[n1];

		if (visit.find(nowC) == visit.end()) {
			ret++;
			visit.insert(nowC);
		}

		n1 = parent[n1];
	}

	while (n2 != anc) {
		int nowC = color[n2];

		if (visit.find(nowC) == visit.end()) {
			ret++;
			visit.insert(nowC);
		}

		n2 = parent[n2];
	}

	return ret;
}

int main(void) {
	FIO;

	cin >> n >> k;

	parent[0] = -1;

	for (int i = 1; i <= n; i++)
	{
		parent[i] = 0;
	}

	for (int i = 0; i < k; i++)
	{
		int r, a, b, c;
		cin >> r >> a >> b;

		if (r == 1) {
			cin >> c;
			paint(a, b, c);
		}
		else if (r == 2) {
			parent[a] = b;
		}
		else {
			cout << cnt(a, b) << "\n";
		}
	}
}*/