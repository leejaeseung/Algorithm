/*
문제
It is game night and Alice and Bob are playing chess. After beating Bob at chess several times, Alice suggests they should play a chess variant instead called hexagonal chess. Although the game is very rarely played nowadays, Alice knows the rules very well and has obtained a hexagonal chessboard from her subscription to the magazine of Bizarre Artifacts for Playing Chess.



Figure H.1: The field naming of the hexagonal chess board and the directions in which a rook can move.

The hexagonal chess board, shown above, consists of 91 hexagonal cells arranged in the shape of a hexagon with side length 6 as depicted in the above diagrams. The board is divided into 11 columns, each called a file, and the files are labeled a to k from left to right. It is also divided into 11 v-shaped rows, each called a rank, which are labeled 1 to 11 from bottom to top. The unique cell in file x and rank y is then denoted by the coordinate xy. For example, rank 11 contains only a single cell f11 and rank 7 is occupied entirely by the black player’s pawns.

Alice begins by explaining how all the pieces move. The simplest piece is the rook, which can move an arbitrary positive number of steps in a straight line in the direction of any of its 6 adjacent cells, as depicted in the figure on the right. Bob immediately realises that the hexagonal rook already is more difficult to work with than its regular chess counterpart.

In order to attack one of the opponents pieces, it is useful to know which cells his rook can move to such that it attacks the opposing piece. The more of these cells there are, the more valuable the current position of his rook is. However, calculating this number is too much for Bob. After losing so many games of regular chess, Alice allows Bob to use a program to assist in his rook placement. While Alice explains the rest of the game you get busy coding.

As a small simplification, Bob will compute the number of ways his rook can move to the destination cell assuming there are no other pieces on the board, not even the piece he wants to attack.

입력
The input consists of one line, containing two different coordinates on the hexagonal chess board, the current positions of your rook and the piece you want to attack.
출력
Output a single integer, the number of ways the rook can move from its current position to the position of the piece it wants to attack in exactly two moves, assuming there are no other pieces on the board.

풀이:
그림과 같이 각 셀마다 번호가 unique하게 부여된다.
rook 을 정확히 두 번 움직여 상대 말을 잡을 수 있는 경로의 수를 찾는 문제이다.

내 rook 이 갈 수 있는 위치에 모두 check하고, 상대 rook 이 갈 수 있는 rook에 모두 check 한 뒤,
겹치는 곳의 수가 답이 된다.(자기 자신의 위치는 check를 풀어야 한다)

매번 움직일 때마다 file, rank의 변화 값이 바뀌므로 왼쪽 위, 오른쪽 위, 왼쪽 아래, 오른쪽 아래로 갈 때
현재 위치에 따라 다른 동작을 해줘야 한다.

모든 테두리를 각 방향에 맞게 막아주었다.
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
#define MOD 100003
int mv1[4] = { 0, 0, 1, -1 };
int mv2[4] = { 1, -1, 0, 0 };
int mv_all1[8] = { 0, 1, 0, -1, -1, -1, 1, 1 };
int mv_all2[8] = { 1, 0, -1, 0 , -1, 1, -1, 1 };

string s, e;
bool checkD[11][12];
bool checkS[11][12];
bool blocked[11][12][4];

void move(bool (*check)[12], pii pos, int dir) {

	if (blocked[pos.first][pos.second][dir])	return;

	pii ret = pos;

	if (pos.first > 5) {
		switch (dir) {
		case 0:
			ret.first--;
			ret.second++;
			break;
		case 1:
			ret.first++;
			break;
		case 2:
			ret.first++;
			ret.second--;
			break;
		case 3:
			ret.first--;
			break;
		}
	}
	else if (pos.first < 5) {
		switch (dir) {
		case 0:
			ret.first--;
			break;
		case 1:
			ret.first++;
			ret.second++;
			break;
		case 2:
			ret.first++;
			break;
		case 3:
			ret.first--;
			ret.second--;
			break;
		}
	}
	else {
		switch (dir) {
		case 0:
			ret.first--;
			break;
		case 1:
			ret.first++;
			break;
		case 2:
			ret.first++;
			ret.second--;
			break;
		case 3:
			ret.first--;
			ret.second--;
			break;
		}
	}

	check[ret.first][ret.second] = true;

	move(check, ret, dir);
}

void draw(bool (*check)[12], string str) {

	int f = str[0] - 'a';
	int r = str[1] - '0';

	if (str.size() > 2)
		r = r * 10 + (str[2] - '0');

	pii pos = { f, r };

	for (int i = 1; i <= 11 - abs(5 - f); i++)
	{
		check[f][i] = true;
	}

	move(check, pos, 0);
	move(check, pos, 1);
	move(check, pos, 2);
	move(check, pos, 3);

	check[f][r] = false;
}

void blockBorder() {
	for (int i = 1; i <= 6; i++)
	{
		blocked[0][i][3] = true;
		blocked[0][i][0] = true;
	}
	for (int i = 0; i <= 5; i++)
	{
		blocked[i][6 + i][0] = true;
	}

	int j = 11;

	for (int i = 5; i <= 10; i++)
	{
		blocked[i][j--][1] = true;
	}

	for (int i = 1; i <= 6; i++)
	{
		blocked[10][i][2] = true;
		blocked[10][i][1] = true;
	}

	for (int i = 5; i <= 10; i++)
	{
		blocked[i][1][2] = true;
	}
	for (int i = 0; i <= 5; i++)
	{
		blocked[i][1][3] = true;
	}
}

int main(void) {
	FIO;

	cin >> s >> e;

	blockBorder();

	draw(checkS, s);
	draw(checkD, e);

	int ans = 0;

	for (int i = 0; i < 11; i++)
	{
		for (int j = 1; j <= 11; j++)
		{
			if (checkS[i][j] && checkD[i][j])
				ans++;
		}
	}

	cout << ans;
}