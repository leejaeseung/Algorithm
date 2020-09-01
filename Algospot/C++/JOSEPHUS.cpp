/*
문제
1세기에 살던 역사학자 조세푸스는 로마와의 전쟁에서 패해 N - 1명의 동료 병사들과 함께 출구가 없는 동굴에 포위당했다고 합니다. 동료 병사들은 로마에 항복하느니 차라리 자살하자고 결의했고, 포위당한 N명의 사람들이 모두 원형으로 둘러선 뒤 순서대로 자살하기로 했습니다. 한 사람이 자살하면, 다음에는 그 사람으로부터 시계 방향으로 K번째 살아 있는 사람이 자살하는 것입니다.

조세푸스의 책에 따르면 조세푸스와 다른 병사 하나만이 살아남았을 때 이들은 마음을 바꿔 로마에 항복해서 살아남았다고 합니다. 마지막 두 명 중 하나가 되기 위해서는 조세푸스는 첫 번째 병사로부터 몇 자리 떨어진 곳에 있어야 했을까요?

입력
입력의 첫 번째 줄에는 테스트 케이스의 개수 C (C≤50)가 주어집니다. 각 테스트 케이스는 두 개의 정수 N, K로 주어집니다(3≤N≤1000, 1≤K≤1000).

출력
각 테스트 케이스에 두 개의 정수로, 마지막 살아남는 두 사람의 번호를 오름차순으로 출력합니다. 첫 번째로 자살하는 병사의 번호가 1이며, 다른 사람들의 번호는 첫 번째 병사에서부터 시계 방향으로 정해집니다.

풀이:
간단한 원형 링크드리스트를 구현해 풀이했다.
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
#define MOD 20091101
int mv1[4] = { 0, 0, 1, -1 };
int mv2[4] = { 1, -1, 0, 0 };
int mv_all1[8] = { 0, 1, 0, -1, -1, -1, 1, 1 };
int mv_all2[8] = { 1, 0, -1, 0 , -1, 1, -1, 1 };

int t, n, k;

struct NODE{
	int num;
	NODE* next;
	NODE* prev;
};

void killNode(NODE* node) {
	node->prev->next = node->next;
	node->next->prev = node->prev;
}

int main(void) {
	FIO;

	cin >> t;

	while (t--) {
		cin >> n >> k;

		NODE* head = (NODE*)malloc(sizeof(NODE));
		NODE* now = head;
		
		for (int i = 1; i <= n; i++)
		{
			NODE* temp = (NODE*)malloc(sizeof(NODE));
			temp->num = i;
			temp->prev = now;
			now->next = temp;
			now = now->next;
		}

		now->next = head->next;
		head->next->prev = now;

		now = head->next;

		for (int i = 0; i < n - 2; i++)
		{
			killNode(now);

			for (int j = 0; j < k; j++)
			{
				now = now->next;
			}
		}

		int n1 = now->num;
		int n2 = now->next->num;

		cout << min(n1, n2) << " " << max(n1, n2) << "\n";
	}
}