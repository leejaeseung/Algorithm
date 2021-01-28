/*
데이터 구조 성공분류 Platinum IV
자료 구조세그먼트 트리
난이도 제공: solved.ac — 난이도 투표하러 가기
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
2 초	512 MB	976	351	264	35.772%
문제
자연수를 저장하는 데이터베이스 S에 대해 다음의 쿼리를 처리합시다.

유형 1 : S에 자연수 X를 추가한다.

유형 2 : S에 포함된 숫자 중 X번째로 작은 수를 응답하고 그 수를 삭제한다.

입력
첫째 줄에 사전에 있는 쿼리의 수 N 이 주어집니다. (1 ≤ N ≤ 2,000,000)

둘째 줄부터 N개의 줄에 걸쳐 각 쿼리를 나타내는 2개의 정수 T X가 주어집니다.

T가 1이라면 S에 추가할 X가 주어지는 것입니다. (1 ≤ X ≤ 2,000,000)

T가 2라면 X는 S에서 삭제해야 할 몇 번째로 작은 수인지를 나타냅니다. S에 최소 X개의 원소가 있음이 보장됩니다.

출력
유형 2의 쿼리 개수만큼의 줄에 각 쿼리에 대한 답을 출력합니다.

풀이:
세그먼트 트리를 이용한 정렬 문제이다.
수의 범위인 1 ~ 2000000 을 구간으로 놓고 각 수를 카운트하여 해결한다.
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

int tree[9000000];
int ans = 0;

int update(int now, int l, int r, int idx) {
	if (r < idx || l > idx)	return tree[now];

	if (r == l) return ++tree[now];

	return tree[now] = update(now * 2, l, (l + r) / 2, idx) + update(now * 2 + 1, (l + r) / 2 + 1, r, idx);
}

int deleteNum(int now, int l, int r, int i) {

	if (l == r) {
		ans = l;
		return --tree[now];
	}

	int left = tree[now * 2];
	int right = tree[now * 2 + 1];

	if (left >= i) {
		return tree[now] = deleteNum(now * 2, l, (l + r) / 2, i) + tree[now * 2 + 1];
	}
	else {
		return tree[now] = tree[now * 2] + deleteNum(now * 2 + 1, (l + r) / 2 + 1, r, i - left);
	}


}

int main() {
	FIO;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int t, x;
		cin >> t >> x;

		if (t == 1) {
			update(1, 1, 2000000, x);
		}
		else {
			deleteNum(1, 1, 2000000, x);
			cout << ans << "\n";
		}
	}
}