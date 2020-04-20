/*
문제
스도쿠는 매우 간단한 숫자 퍼즐이다. 9×9 크기의 보드가 있을 때, 각 행과 각 열, 그리고 9개의 3×3 크기의 보드에 1부터 9까지의 숫자가 중복 없이 나타나도록 보드를 채우면 된다. 예를 들어 다음을 보자.



위 그림은 참 잘도 스도쿠 퍼즐을 푼 경우이다. 각 행에 1부터 9까지의 숫자가 중복 없이 나오고, 각 열에 1부터 9까지의 숫자가 중복 없이 나오고, 각 3×3짜리 사각형(9개이며, 위에서 색깔로 표시되었다)에 1부터 9까지의 숫자가 중복 없이 나오기 때문이다.

하다 만 스도쿠 퍼즐이 주어졌을 때, 마저 끝내는 프로그램을 작성하시오.

입력
9개의 줄에 9개의 숫자로 보드가 입력된다. 아직 숫자가 채워지지 않은 칸에는 0이 주어진다.

출력
9개의 줄에 9개의 숫자로 답을 출력한다. 답이 여러 개 있다면 그 중 사전식으로 앞서는 것을 출력한다. 즉, 81자리의 수가 제일 작은 경우를 출력한다.

풀이:
좌표 i,y와 값 v 에 대하여 
해당 행에 v가 존재하는지 여부 = row[i][v]
해당 열에 v가 존재하는지 여부 = col[j][v]
해당 사각형에 v가 존재하는지 여부 = box[(i / 3) * 3 + j / 3][v]
를 체크해야 합니다.

map 이 0인(아직 값을 넣지 않은) 인덱스를 찾아 1~9 값을 넣어보고, 다음 좌표로 넘겨주며 진행합니다.
*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<string>
#include<vector>
#include<queue>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>

bool row[9][10];
bool col[9][10];
bool box[9][10];
int map[9][9];
int cnt = 0;

void recul(int x, int y, int c) {

	int next_x = x;
	int next_y = y + 1;
	if (next_y == 9) {
		next_x++;
		next_y = 0;
	}

	while (map[next_x][next_y] != 0) {
		next_y++;
		if (next_y == 9) {
			next_x++;
			next_y = 0;
		}
	}

	if (c == cnt) {
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				cout << map[i][j];
			}
			cout << '\n';
		}
		exit(0);
	}

	for (int k = 1; k < 10; k++)
	{
		if (!row[next_x][k] && !col[next_y][k] && !box[(next_x / 3) * 3 + next_y / 3][k]) {
			map[next_x][next_y] = k;
			row[next_x][k] = true;
			col[next_y][k] = true;
			box[(next_x / 3) * 3 + next_y / 3][k] = true;
			recul(next_x, next_y, c + 1);
			map[next_x][next_y] = 0;
			row[next_x][k] = false;
			col[next_y][k] = false;
			box[(next_x / 3) * 3 + next_y / 3][k] = false;
		}
	}
}

int main(void) {
	FIO;

	for (int i = 0; i < 9; i++)
	{
		string str;
		cin >> str;

		for (int j = 0; j < 9; j++)
		{
			int v = str[j] - '0';

			map[i][j] = v;
			row[i][v] = true;
			col[j][v] = true;
			box[(i / 3) * 3 + j / 3][v] = true;
			if (v == 0)
				cnt++;
		}
	}

	recul(0, -1, 0);
}