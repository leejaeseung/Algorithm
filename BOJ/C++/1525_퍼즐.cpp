/*
문제
3×3 표에 다음과 같이 수가 채워져 있다. 오른쪽 아래 가장 끝 칸은 비어 있는 칸이다.

1	2	3
4	5	6
7	8
어떤 수와 인접해 있는 네 개의 칸 중에 하나가 비어 있으면, 수를 그 칸으로 이동시킬 수가 있다. 물론 표 바깥으로 나가는 경우는 불가능하다. 우리의 목표는 초기 상태가 주어졌을 때, 최소의 이동으로 위와 같은 정리된 상태를 만드는 것이다. 다음의 예를 보자.

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
가장 윗 상태에서 세 번의 이동을 통해 정리된 상태를 만들 수 있다. 이와 같이 최소 이동 횟수를 구하는 프로그램을 작성하시오.

입력
세 줄에 걸쳐서 표에 채워져 있는 아홉 개의 수가 주어진다. 한 줄에 세 개의 수가 주어지며, 빈 칸은 0으로 나타낸다.

출력
첫째 줄에 최소의 이동 횟수를 출력한다. 이동이 불가능한 경우 -1을 출력한다.

풀이:
3x3 맵을 통한 bfs로 생각해 볼 수 있지만 메모리가 매우 작기 때문에 배열 대신 문자열을 이용해 bfs를 해야 한다.

방문 체크는 set을 이용하고, 문자열에서 1, 3, -1, -3 만큼 인덱스를 더해가며 bfs하는데,
양 끝에서 한 칸을 못 이동하는 경우가 있으므로 주의하자.
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