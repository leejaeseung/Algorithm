/*
D. Anti-Sudoku
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given a correct solution of the sudoku puzzle. If you don't know what is the sudoku, you can read about it here.

The picture showing the correct sudoku solution:



Blocks are bordered with bold black color.

Your task is to change at most 9 elements of this field (i.e. choose some 1≤i,j≤9 and change the number at the position (i,j) to any other number in range [1;9]) to make it anti-sudoku. The anti-sudoku is the 9×9 field, in which:

Any number in this field is in range [1;9];
each row contains at least two equal elements;
each column contains at least two equal elements;
each 3×3 block (you can read what is the block in the link above) contains at least two equal elements.
It is guaranteed that the answer exists.

You have to answer t independent test cases.

Input
The first line of the input contains one integer t (1≤t≤104) — the number of test cases. Then t test cases follow.

Each test case consists of 9 lines, each line consists of 9 characters from 1 to 9 without any whitespaces — the correct solution of the sudoku puzzle.

Output
For each test case, print the answer — the initial field with at most 9 changed elements so that the obtained field is anti-sudoku. If there are several solutions, you can print any. It is guaranteed that the answer exists.

풀이:
이유는 정확히 모르지만 2를 1로 바꿔주면 되는 문제였습니다..
*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<string.h>
#include<queue>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>
#define ll long long

int map[9][9];

int main(void) {
	FIO;

	int T;
	cin >> T;

	while (T--) {
		for (int i = 0; i < 9; i++)
		{
			string str;
			cin >> str;
			for (int j = 0; j < 9; j++)
			{
				map[i][j] = str[j] - '0';
			}
		}
		

			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 9; j++)
				{
					if (map[i][j] == 2)
						map[i][j] = 1;
				}
			}

		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				cout << map[i][j];
			}
			cout << "\n";
		}
	}
}