/*
문제
승범이는 평소 래퍼 도끼를 흠모해왔지만, 도끼만큼 랩을 잘할 수 없다는 것을 깨닫고 도끼만큼 돈이라도 벌자는 결심을 한다. 그래서 휴학 후 ㈜승범이네를 창업했다.

㈜승범이네는 판매원들로만 이루어진 다단계 회사이다.

승범이를 제외한 모든 판매원은 사수가 배정되는데, 사수는 한 회원당 단 한 명씩만 배정된다. 만약 판매원 A가 B의 사수라면, B를 A의 부사수라고 부른다.

㈜승범이네의 수익구조는 기형적이다.

판매원들은 제품을 자비로 사서 판매한다. 이때 제품을 구매가격보다 저렴하게 판매하게 되면 손해를 보게 되는데, 어떤 회원 A가 손해를 보면 그 회원의 모든 부사수도 같은 만큼의 손해를 보게 된다. 그러면 부사수들의 부사수들도 손해를 보게 되고, 그들의 부사수들도 손해를 보게 되고, … ,결국 A와 A 밑의 모든 판매원이 A가 잃은 만큼의 손해를 보게 된다.

반대로 판매원 A가 제품을 비싸게 팔아 이익이 생길 경우, A와 A밑의 모든 판매원이 같은 이익을 얻을 수 있다.

승범이는 직원들이 현재 얼마만큼 돈을 벌었는지 감시하기 위해 다음 두 종류의 명령을 처리하려고 한다.

1 i w : 직원 i가 w만큼 이익/손해를 본다. (이익은 양수로, 손해는 음수로 주어진다)
2 i : 직원 i의 현재 통장 잔액을 출력한다.
직원들은 빈 통장을 갖고 일을 시작하며, 이익과 손해가 실시간으로 통장에 기록된다. 물론 통장 잔액은 음수일 수도 있다.

일을 시작하기 직전에 플래티넘 승급전을 남겨두고 온 것을 떠올린 승범이는 우리에게 일을 맡기고 집으로 달려가버렸다.

만년 골드 승범이를 위해 문제를 대신 해결해주자.

입력
첫 번째 줄에 승범이를 포함한 판매원들의 수 N(1 ≤ N ≤ 100,000), 명령의 수 M(1 ≤ M ≤ 100,000)이 주어진다. 판매원들은 1번부터 N번까지 번호가 매겨지며, 승범이는 항상 1번이다.

두 번째 줄에 판매원 1번부터 N번까지의 사수가 순서대로 공백으로 구분되어 주어진다. 승범이는 사수가 없으므로 -1이 주어진다.

세 번째 줄부터 M개의 줄에 걸쳐 위에서 설명한 명령(i, w는 정수, 1 ≤ i ≤ N, -10,000 ≤ w ≤ 10,000) 이 주어진다.

출력
2번 명령이 주어질 때마다 한 줄에 하나씩 해당하는 직원 i의 잔고 상황을 출력한다.

풀이:
기존의 트리는 자식이 여럿이기 때문에 세그먼트 트리를 적용할 수 없습니다.
따라서 전위 탐색으로 트리를 탐색하면서 number를 다시 부여해주고, 해당 노드의 자식이 몇 번까지인지(몇 번까지 전파해야하는지) 표시해줘야 합니다.
즉, last[3] = 6 이라면, 3번이 이익을 보면, 3~6번까지 전파해주면 된다는 의미입니다.

새롭게 만들어진 트리에 대해(초기값은 모두 0이므로 따로 초기화할 필요가 없고, get 함수로 해당 인덱스의 값만 가져옵니다. 구간합x) 레이지 프로파게이션을 적용하면 됩니다. 
*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include<stack>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>

int N, Q;
vector<int> tree[100001];
int num = 1;
int new_num[100001];
long long lazy[400001];
long long new_tree[400001];
int last[100001];

int newNum(int now) {
	

	last[now] = new_num[now] = num++;
	for (int i = 0; i < tree[now].size(); i++)
	{
		last[now] = newNum(tree[now].at(i));
	}
	return last[now];
}

void propagate(int now, int l, int r) {
	if (lazy[now] != 0) {

		if (l != r) {
			lazy[now * 2] += lazy[now];
			lazy[now * 2 + 1] += lazy[now];
		}

		new_tree[now] += lazy[now] * (r - l + 1);
		lazy[now] = 0;
	}
}

void Update(int now, int l, int r, int s, int e, int v) {
	propagate(now, l, r);
	
	if (l > e || r < s)	return;
	if (s <= l && e >= r) {
		lazy[now] += v;
		propagate(now, l, r);
		return;
	}
	
	Update(now * 2, l, (l + r) / 2, s, e,  v);
	Update(now * 2 + 1, (l + r) / 2 + 1, r, s, e, v);
	new_tree[now] = new_tree[now * 2] + new_tree[now * 2 + 1];
}

void get(int now, int l, int r, int idx) {
	propagate(now, l, r);

	if (idx < l || idx > r)	return;
	if (l == r) {
		cout << new_tree[now] << "\n";
		return;
	}
	get(now * 2, l, (l + r) / 2, idx);
	get(now * 2 + 1, (l + r) / 2 + 1, r, idx);
}

int main(void) {
	FIO;

	cin >> N >> Q;

	for (int i = 1; i <= N; i++)
	{
		int n;
		cin >> n;
		if (n != -1)
			tree[n].push_back(i);
	}

	newNum(1);
	
	for (int i = 0; i < Q; i++)
	{
		int q, a, w;
		
		cin >> q >> a;

		if (q == 1) {
			cin >> w;

			Update(1,1, N, new_num[a], last[a], w);
		}
		else {
			get(1, 1, N, new_num[a]);
		}
	}
}