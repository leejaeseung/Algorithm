/*
����
3��3 ǥ�� ������ ���� ���� ä���� �ִ�. ������ �Ʒ� ���� �� ĭ�� ��� �ִ� ĭ�̴�.

1	2	3
4	5	6
7	8
� ���� ������ �ִ� �� ���� ĭ �߿� �ϳ��� ��� ������, ���� �� ĭ���� �̵���ų ���� �ִ�. ���� ǥ �ٱ����� ������ ���� �Ұ����ϴ�. �츮�� ��ǥ�� �ʱ� ���°� �־����� ��, �ּ��� �̵����� ���� ���� ������ ���¸� ����� ���̴�. ������ ���� ����.

1	 	3
4	2	5
7	8	6
1	2	3
4	 	5
7	8	6
1	2	3
4	5
7	8	6
1	2	3
4	5	6
7	8
���� �� ���¿��� �� ���� �̵��� ���� ������ ���¸� ���� �� �ִ�. �̿� ���� �ּ� �̵� Ƚ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
�� �ٿ� ���ļ� ǥ�� ä���� �ִ� ��ȩ ���� ���� �־�����. �� �ٿ� �� ���� ���� �־�����, �� ĭ�� 0���� ��Ÿ����.

���
ù° �ٿ� �ּ��� �̵� Ƚ���� ����Ѵ�. �̵��� �Ұ����� ��� -1�� ����Ѵ�.

Ǯ��:
3x3 ���� ���� bfs�� ������ �� �� ������ �޸𸮰� �ſ� �۱� ������ �迭 ��� ���ڿ��� �̿��� bfs�� �ؾ� �Ѵ�.

�湮 üũ�� set�� �̿��ϰ�, ���ڿ����� 1, 3, -1, -3 ��ŭ �ε����� ���ذ��� bfs�ϴµ�,
�� ������ �� ĭ�� �� �̵��ϴ� ��찡 �����Ƿ� ��������.
*/
#include<iostream>
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
int next_idx[4] = { 1, 3, -1, -3 };

queue<pair<string, pii >> q;
set<string> s;
string dest = "123456780";

int main(void) {
	FIO;

	string start = "";
	int zero = -1;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			char v;
			cin >> v;

			start += v;
			if (v == '0')
				zero = i * 3 + j;
		}
	}

	s.insert(start);
	q.push(make_pair(start, make_pair(zero, 0)));

	while (!q.empty()) {

		string nowPuzzle = q.front().first;
		int zero_idx = q.front().second.first;
		int move = q.front().second.second;
		q.pop();

		if (nowPuzzle == dest) {
			cout << move;

			exit(0);
		}

		for (int i = 0; i < 4; i++)
		{
			int nxt = zero_idx + next_idx[i];


			if (zero_idx % 3 == 0 && i == 2)	continue;
			if (zero_idx % 3 == 2 && i == 0)	continue;
			if (nxt < 0 || nxt >= 9)	continue;

			string nextPuzzle = nowPuzzle;

			nextPuzzle[nxt] = '0';
			nextPuzzle[zero_idx] = nowPuzzle[nxt];

			if (s.find(nextPuzzle) != s.end()) continue;

			s.insert(nextPuzzle);
			q.push(make_pair(nextPuzzle, make_pair(nxt, move + 1)));
		}
	}

	cout << "-1";
}