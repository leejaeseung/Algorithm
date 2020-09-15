/*
문제
매일 코딩만 하던 상헌이는 두뇌가 너무 코드에만 범벅이 되고 있는 것 같아 두뇌를 다른 방면으로 몰입시킬 수 있는 깃발춤 공연을 보러 가기로 했다. 깃발춤 공연은 N명의 공연자들이 일렬로 서서 깃발을 박력 있게 흔들며 진행된다. 깃발을 들고 있는 공연자들은 각각 카리스마의 정도 ci를 지니고 있어, 몇몇 공연자들은 보다 절도 있게 깃발을 흔든다.

상헌이는 깃발춤을 보다가, 문득 깃발춤 공연 중 몇몇 연속된 공연자들이 깃발을 교대로 흔드는 것을 목격했다. 상헌이는 이를 '교대 깃발춤'이라 명명하였다. 교대 깃발춤은 L번째 공연자부터 R번째 공연자까지 깃발을 각자 왼쪽 또는 오른쪽으로 흔드는 동작인데, L번째 공연자를 포함하여 L번째 공연자과의 거리가 짝수인 공연자는 깃발을 왼쪽으로 흔들고, 거리가 홀수인 공연자는 오른쪽으로 흔든 뒤, 다시 깃발을 몸 쪽으로 원위치시킨다. 여기서 x번째 공연자와 y번째 공연자 사이의 거리는 |x - y|로 표현된다.

문제 해결에서 벗어날 수 없었던 상헌이는 교대 깃발춤에서 왼쪽으로 깃발을 흔든 공연자들의 카리스마의 합과 오른쪽으로 깃발을 흔든 공연자들의 카리스마의 합의 차이의 절댓값을 교대 깃발춤의 균일도라고 부르기로 하였다. 교대 깃발춤의 균일도가 큰 값을 가지면, 한쪽이 다른 쪽보다 압도적으로 카리스마가 느껴진다는 뜻이기에 비대칭적으로 보일 수 있다. 상헌이는 교대 깃발춤의 균일도가 중요한 의미를 지닌다고 생각한다. 또 깃발을 흔드는 공연자들은 공연의 열기와 순간순간의 실수에 휩쓸리기 때문에, 공연자들의 카리스마가 증가하거나 감소할 수 있다. 이런 모든 상황을 고려하며 상헌이는 매 교대 깃발춤의 균일도를 구하고 싶어졌다. 상헌이를 도와주자!

입력
첫 번째 줄에는 깃발춤을 진행하는 공연자의 명수인 자연수 N과 상황 변화의 개수인 자연수 Q가 공백으로 구분되어 주어진다. (1 ≤ N ≤ 300,000, 1 ≤ Q ≤ 300,000)
두 번째 줄에는 정수 c1, c2, ..., cN 이 공백으로 구분되어 주어지며, ci 는 i 번째 공연자의 카리스마를 의미한다. (-100,000 ≤ ci ≤ 100,000)
세 번째 줄부터 Q 개의 줄에 걸쳐 다음 형식 중 하나로 세 정수가 공백으로 구분되어 주어진다.
- 1 L R : L 번째 공연자부터 R 번째 공연자까지 구성된 교대 깃발춤이 시연된다. (1 ≤ L ≤ R ≤ N)
- 2 L x : L 번째 공연자의 카리스마가 정수 x만큼 증가한다. (1 ≤ L ≤ N, -100,000 ≤ x ≤ 100,000)
첫 번째 종류('1 L R' 꼴)의 쿼리는 한 번 이상 주어짐이 보장된다.

출력
첫 번째 종류의 쿼리가 입력될 때마다 매 줄에 해당하는 교대 깃발춤의 균일도를 출력한다.

풀이:
규칙을 보면 쿼리에서 L을 기준으로 두 칸씩 건너 뛴 애들이 짝수합이 되고, L + 1을 기준으로 두 칸씩 건너 뛴 애들이
홀수합이 된다.
두 개의 세그먼트 트리를 만들어 1, 3, 5, 7, 9 ... 의 구간합을 저장하고, 2, 4 , 6 , 8 ... 의 구간합을 저장한 뒤
L이 짝수인지 홀수인지에 따라 두 트리의 구간 합의 차를 구하면 된다.
*/
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
#define pll pair<ll, ll>
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vii vector<pii>
#define IMAX 2000000001
#define LMAX 1000000000000000000
#define DMAX 0xFFFFFFFFFFFFF
#define MOD 100003
int mv1[4] = { 0, 0, 1, -1 };
int mv2[4] = { 1, -1, 0, 0 };
int mv_all1[8] = { 0, 1, 0, -1, -1, -1, 1, 1 };
int mv_all2[8] = { 1, 0, -1, 0 , -1, 1, -1, 1 };

int n, q;
ll tree1[1400000];
ll tree2[1400000];

void update(ll* nowTree, int now, int s, int e, int idx, int add) {
	if (idx < s || idx > e)	return;

	if (s == e) {
		nowTree[now] += add;
		return;
	}

	update(nowTree, now * 2, s, (s + e) / 2, idx, add);
	update(nowTree, now * 2 + 1, (s + e) / 2 + 1, e, idx, add);

	nowTree[now] = nowTree[now * 2] + nowTree[now * 2 + 1];
}

ll get(ll* nowTree, int now, int s, int e, int l, int r) {
	if (r < s || l > e)	return 0;

	if (l <= s && r >= e)	return nowTree[now];

	return get(nowTree, now * 2, s, (s + e) / 2, l, r) + get(nowTree, now * 2 + 1, (s + e) / 2 + 1, e, l, r);
}

int main(void) {
	FIO;

	cin >> n >> q;

	for (int i = 1; i <= n; i++)
	{
		int v;
		cin >> v;

		if (i % 2 != 0)
			update(tree1, 1, 1, n, i, v);
		else
			update(tree2, 1, 1, n, i, v);
	}

	for (int i = 0; i < q; i++)
	{
		int Q, L, R;
		cin >> Q >> L >> R;

		if (Q == 1) {
			ll even = 0, odd = 0;

			if (L % 2 != 0) {
				even = get(tree1, 1, 1, n, L, R);
				odd = get(tree2, 1, 1, n, L, R);
			}
			else {
				even = get(tree2, 1, 1, n, L, R);
				odd = get(tree1, 1, 1, n, L, R);
			}

			cout << abs(even - odd) << "\n";
		}
		else {
			if (L % 2 != 0)
				update(tree1, 1, 1, n, L, R);
			else
				update(tree2, 1, 1, n, L, R);
		}
	}
}