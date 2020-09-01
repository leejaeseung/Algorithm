/*
����
1���⿡ ��� �������� ����Ǫ���� �θ����� ���￡�� ���� N - 1���� ���� ������ �Բ� �ⱸ�� ���� ������ �������ߴٰ� �մϴ�. ���� ������� �θ��� �׺��ϴ��� ���� �ڻ����ڰ� �����߰�, �������� N���� ������� ��� �������� �ѷ��� �� ������� �ڻ��ϱ�� �߽��ϴ�. �� ����� �ڻ��ϸ�, �������� �� ������κ��� �ð� �������� K��° ��� �ִ� ����� �ڻ��ϴ� ���Դϴ�.

����Ǫ���� å�� ������ ����Ǫ���� �ٸ� ���� �ϳ����� ��Ƴ����� �� �̵��� ������ �ٲ� �θ��� �׺��ؼ� ��Ƴ��Ҵٰ� �մϴ�. ������ �� �� �� �ϳ��� �Ǳ� ���ؼ��� ����Ǫ���� ù ��° ����κ��� �� �ڸ� ������ ���� �־�� �������?

�Է�
�Է��� ù ��° �ٿ��� �׽�Ʈ ���̽��� ���� C (C��50)�� �־����ϴ�. �� �׽�Ʈ ���̽��� �� ���� ���� N, K�� �־����ϴ�(3��N��1000, 1��K��1000).

���
�� �׽�Ʈ ���̽��� �� ���� ������, ������ ��Ƴ��� �� ����� ��ȣ�� ������������ ����մϴ�. ù ��°�� �ڻ��ϴ� ������ ��ȣ�� 1�̸�, �ٸ� ������� ��ȣ�� ù ��° ���翡������ �ð� �������� �������ϴ�.

Ǯ��:
������ ���� ��ũ�帮��Ʈ�� ������ Ǯ���ߴ�.
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