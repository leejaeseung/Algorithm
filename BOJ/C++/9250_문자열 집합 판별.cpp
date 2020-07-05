/*
문제
집합 S는 크기가 N이고, 원소가 문자열인 집합이다. Q개의 문자열이 주어졌을 때, 각 문자열의 부분 문자열이 집합 S에 있는지 판별하는 프로그램을 작성하시오. 문자열의 여러 부분 문자열 중 하나라도 집합 S에 있으면 'YES'를 출력하고, 아무것도 없으면 'NO'를 출력한다.

예를 들어, 집합 S = {"www","woo","jun"} 일 때, "myungwoo"의 부분 문자열인 "woo" 가 집합 S에 있으므로 답은 'YES'이고, "hongjun"의 부분 문자열 "jun"이 집합 S에 있으므로 답은 'YES'이다. 하지만, "dooho"는 모든 부분 문자열이 집합 S에 없기 때문에 답은 'NO'이다.

입력
첫째 줄에 집합 S의 크기 N이 주어진다. (1 ≤ N ≤ 1000)

다음 N개 줄에 집합 S의 원소들이 주어진다. 이 문자열의 길이는 100을 넘지 않는다.

다음 줄에 답을 판별해야 하는 문자열의 개수 Q가 주어진다. (1 ≤ Q ≤ 1000)

다음 Q개 줄에 답을 판별해야 하는 문자열이 주어진다. 이 문자열의 길이는 10000을 넘지 않는다.

입력으로 주어지는 모든 문자열은 알파벳 소문자로만 이루어져 있다.

출력
Q개 줄에 각 문자열에 대한 답을 출력한다.

풀이:
아호코라식 알고리즘 문제입니다.
https://m.blog.naver.com/kks227/220992598966
위 블로그를 참고했습니다.

기존 Trie 자료구조에서 부분 문자열을 찾아 따라가는데, 다음 문자가 없을 때
back-link를 연결해주어 그곳부터 다시 찾아나가는 방식입니다.
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