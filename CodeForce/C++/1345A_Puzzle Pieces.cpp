/*
A. Puzzle Pieces
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given a special jigsaw puzzle consisting of n⋅m identical pieces. Every piece has three tabs and one blank, as pictured below.


The jigsaw puzzle is considered solved if the following conditions hold:

The pieces are arranged into a grid with n rows and m columns.
For any two pieces that share an edge in the grid, a tab of one piece fits perfectly into a blank of the other piece.
Through rotation and translation of the pieces, determine if it is possible to solve the jigsaw puzzle.

Input
The test consists of multiple test cases. The first line contains a single integer t (1≤t≤1000) — the number of test cases. Next t lines contain descriptions of test cases.

Each test case contains two integers n and m (1≤n,m≤105).

Output
For each test case output a single line containing "YES" if it is possible to solve the jigsaw puzzle, or "NO" otherwise. You can print each letter in any case (upper or lower).
풀이:
N = 2, M = 2
N = 1
M = 1
위 세 가지 경우에만 퍼즐을 만들 수 있습니다.
*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<vector>
#include<queue>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>
#define ll long long

int T, N, M;

int main(void) {
	FIO;

	cin >> T;

	while (T--) {
		cin >> N >> M;

		if (N == 2 && M == 2)
			cout << "YES" << "\n";
		else if (N == 1) 
			cout << "YES" << "\n";
		else if (M == 1) 
			cout << "YES" << "\n";
		else 
			cout << "NO" << "\n";
		}
}