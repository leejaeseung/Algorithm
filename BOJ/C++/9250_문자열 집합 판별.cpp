/*
����
���� S�� ũ�Ⱑ N�̰�, ���Ұ� ���ڿ��� �����̴�. Q���� ���ڿ��� �־����� ��, �� ���ڿ��� �κ� ���ڿ��� ���� S�� �ִ��� �Ǻ��ϴ� ���α׷��� �ۼ��Ͻÿ�. ���ڿ��� ���� �κ� ���ڿ� �� �ϳ��� ���� S�� ������ 'YES'�� ����ϰ�, �ƹ��͵� ������ 'NO'�� ����Ѵ�.

���� ���, ���� S = {"www","woo","jun"} �� ��, "myungwoo"�� �κ� ���ڿ��� "woo" �� ���� S�� �����Ƿ� ���� 'YES'�̰�, "hongjun"�� �κ� ���ڿ� "jun"�� ���� S�� �����Ƿ� ���� 'YES'�̴�. ������, "dooho"�� ��� �κ� ���ڿ��� ���� S�� ���� ������ ���� 'NO'�̴�.

�Է�
ù° �ٿ� ���� S�� ũ�� N�� �־�����. (1 �� N �� 1000)

���� N�� �ٿ� ���� S�� ���ҵ��� �־�����. �� ���ڿ��� ���̴� 100�� ���� �ʴ´�.

���� �ٿ� ���� �Ǻ��ؾ� �ϴ� ���ڿ��� ���� Q�� �־�����. (1 �� Q �� 1000)

���� Q�� �ٿ� ���� �Ǻ��ؾ� �ϴ� ���ڿ��� �־�����. �� ���ڿ��� ���̴� 10000�� ���� �ʴ´�.

�Է����� �־����� ��� ���ڿ��� ���ĺ� �ҹ��ڷθ� �̷���� �ִ�.

���
Q�� �ٿ� �� ���ڿ��� ���� ���� ����Ѵ�.

Ǯ��:
��ȣ�ڶ�� �˰��� �����Դϴ�.
https://m.blog.naver.com/kks227/220992598966
�� ��α׸� �����߽��ϴ�.

���� Trie �ڷᱸ������ �κ� ���ڿ��� ã�� ���󰡴µ�, ���� ���ڰ� ���� ��
back-link�� �������־� �װ����� �ٽ� ã�Ƴ����� ����Դϴ�.
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

int n, q;

class node {
public:
	bool out = false;
	node* back = NULL;
	node* next[26];
};

node* root;

void bfs() {
	queue<node*> q;
	root->back = root;
	q.push(root);

	while (!q.empty()) {
		node* now = q.front();
		q.pop();

		for (int i = 0; i < 26; i++)
		{
			node* next = now->next[i];
			if (next == NULL)	continue;

			if (now == root)
				next->back = root;
			else {
				node* dest = now->back;

				while (dest != root && dest->next[i] == NULL)
					dest = dest->back;
				
				if (dest->next[i] != NULL)
					dest = dest->next[i];
					
				next->back = dest;
			}

			now->out = next->back->out;

			q.push(next);
		}
	}
}

int main(void) {
	FIO;

	root = new node();

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;

		node* nowNode = root;

		for (int i = 0; i < str.size(); i++)
		{
			int now = str[i] - 'a';

			if(nowNode->next[now] == NULL) {
				nowNode->next[now] = new node();
			}

			nowNode = nowNode->next[now];
		}
		nowNode->out = true;
	}

	bfs();

	cin >> q;

	for (int i = 0; i < q; i++)
	{
		string str;
		cin >> str;

		bool find = false;
		node* nowNode = root;

		for (int i = 0; i < str.size(); i++)
		{
			int nowC = str[i] - 'a';

			while (nowNode != root && nowNode->next[nowC] == NULL)
				nowNode = nowNode->back;
				
			if (nowNode->next[nowC] != NULL)
				nowNode = nowNode->next[nowC];

			if (nowNode->out) {
				find = true;
				break;
			}
		}
		
		if(find)
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";
	}
}