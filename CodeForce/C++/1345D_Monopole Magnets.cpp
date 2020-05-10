/*
D. Monopole Magnets
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
A monopole magnet is a magnet that only has one pole, either north or south. They don't actually exist since real magnets have two poles, but this is a programming contest problem, so we don't care.

There is an n×m grid. Initially, you may place some north magnets and some south magnets into the cells. You are allowed to place as many magnets as you like, even multiple in the same cell.

An operation is performed as follows. Choose a north magnet and a south magnet to activate. If they are in the same row or the same column and they occupy different cells, then the north magnet moves one unit closer to the south magnet. Otherwise, if they occupy the same cell or do not share a row or column, then nothing changes. Note that the south magnets are immovable.

Each cell of the grid is colored black or white. Let's consider ways to place magnets in the cells so that the following conditions are met.

There is at least one south magnet in every row and every column.
If a cell is colored black, then it is possible for a north magnet to occupy this cell after some sequence of operations from the initial placement.
If a cell is colored white, then it is impossible for a north magnet to occupy this cell after some sequence of operations from the initial placement.
Determine if it is possible to place magnets such that these conditions are met. If it is possible, find the minimum number of north magnets required (there are no requirements on the number of south magnets).

Input
The first line contains two integers n and m (1≤n,m≤1000)  — the number of rows and the number of columns, respectively.

The next n lines describe the coloring. The i-th of these lines contains a string of length m, where the j-th character denotes the color of the cell in row i and column j. The characters "#" and "." represent black and white, respectively. It is guaranteed, that the string will not contain any other characters.

Output
Output a single integer, the minimum possible number of north magnets required.

If there is no placement of magnets that satisfies all conditions, print a single integer −1.

풀이:
검은 영역 하나의 덩이엔 하나의 N 자석만이 필요합니다.
따라서 dfs로 각 검은 영역 덩이의 개수를 세줍니다.

이 문제는 불가능한 경우를 찾는 문제였습니다.
다음 두 가지 경우에 불가능하므로 다음 경우들을 걸러줘야 합니다.
1. 검은 영역과 검은 영역 사이에 하얀 영역이 있을 때 -> 조건 3 만족x
2. 한 열(행)이 모두 하얀 영역인데, 그 열(행)중에 모든 행(열)이 하얀 영역인 곳이 없을 때 -> 조건 1 만족x
*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<vector>
#include<stack>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>
#define ll long long

int T, N, M;
stack<pii> st;
bool visit[1001][1001];
int group[1001][1001];
char map[1001][1001];
int mv1[4] = { 0, 0, 1, -1 };
int mv2[4] = { 1, -1, 0, 0 };
int ans = 0;
int row[1001];
int col[1001];

bool canRow() {

	for (int i = 0; i < N; i++)
	{
		int cnt = 0;
		bool flag = false;

		if (row[i] == 0) {
			for (int j = 0; j < M; j++)
			{
				if (col[j] == 0)
					flag = true;
			}
			if (!flag)
				return false;
		}
		else {
			for (int j = 0; j < M; j++)
			{
				if (row[i] == cnt)	break;

				if (flag && map[i][j] == '.')
					return false;
				if (map[i][j] == '#') {
					flag = true;
					cnt++;
				}
			}
		}
	}
	return true;
}

bool canCol() {

	for (int i = 0; i < M; i++)
	{
		int cnt = 0;
		bool flag = false;

		if (col[i] == 0) {
			for (int j = 0; j < M; j++)
			{
				if (row[j] == 0)
					flag = true;
			}
			if (!flag)
				return false;
		}
		else {
			for (int j = 0; j < N; j++)
			{
				if (col[i] == cnt)	break;

				if (flag && map[j][i] == '.')
					return false;
				if (map[j][i] == '#') {
					flag = true;
					cnt++;
				}
			}
		}
	}
	return true;
}

void BFS() {


	while (!st.empty()) {
		pii now = st.top();	st.pop();

		if (group[now.first][now.second] == 0) {
			group[now.first][now.second] = ++ans;
		}


		for (int i = 0; i < 4; i++)
		{
			int next_x = now.first + mv1[i];
			int next_y = now.second + mv2[i];

			if (next_x < 0 || next_y < 0 || next_x >= N || next_y >= M)	continue;

			if (map[next_x][next_y] == '.')	continue;

			if (!visit[next_x][next_y]) {
				visit[next_x][next_y] = true;
				
				group[next_x][next_y] = group[now.first][now.second];

				st.push(make_pair(next_x, next_y));
			}
		}
	}
}

int main(void) {
	FIO;

		cin >> N >> M;

		ans = 0;

		for (int i = 0; i < N; i++)
		{
			string str;
			cin >> str;
			for (int j = 0; j < M; j++)
			{
				map[i][j] = str[j];
				visit[i][j] = false;

				if (str[j] == '#') {
					st.push(make_pair(i, j));
					row[i]++;
					col[j]++;
				}
				
				group[i][j] = 0;
			}
		}

		BFS();
		if (canRow() && canCol())
			cout << ans;
		else
			cout << "-1";

}