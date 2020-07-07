/*
문제
챔피언스 리그 결승전을 앞두고 있는 맨체스터 유나이티드의 명장 퍼거슨 감독은 이번 경기에 4-4-2 다이아몬드 전술을 사용하려고 한다.

오늘 결승전에 뛸 선발 선수 11명은 미리 골라두었지만, 어떤 선수를 어느 포지션에 배치해야 할지 아직 결정하지 못했다.

수석코치 마이크 펠란은 11명의 선수가 각각의 포지션에서의 능력을 0부터 100까지의 정수로 수치화 했다. 0은 그 선수가 그 포지션에 적합하지 않다는 뜻이다.

이때, 모든 선수의 포지션을 정하는 프로그램을 작성하시오. 모든 포지션에 선수를 배치해야 하고, 각 선수는 능력치가 0인 포지션에 배치될 수 없다.

입력
입력은 여러 개의 테스트 케이스로 이루어져 있다. 첫째 줄에는 테스트 케이스의 개수 C가 주어진다. 각각의 케이스는 11줄로 이루어져 있고, i번 줄은 0과 100사이의 11개의 정수 sij를 포함하고 있다. sij는 i번선수가 j번 포지션에서 뛸 때의 능력이다. 모든 선수에게 적합한 포지션의 수는 최대 5개이다. (능력치가 0보다 크다)

출력
각각의 테스트 케이스에 대해서, 모든 포지션의 선수를 채웠을 때, 능력치의 합의 최댓값을 출력한다. 항상 하나 이상의 올바른 라인업을 만들 수 있다.

풀이:
비트마스크 문제입니다.

"모든 포지션을 채웠을 때" 이므로 11개 포지션에 대해 비트마스크를 적용하여 메모이제이션을 사용하면 된다는 것을 알 수 있습니다.
하지만 포지션에 대해서만 체크를 해주면 같은 포지션에 여러 선수가 배정될 수 있습니다. 따라서 메모이제이션과 별개로 
11명의 선수에 대한 비트마스크를 만들어 해당 선수가 이미 배정된 상태인지 체크해주어야 합니다.
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

int t;
int pos[11][11];
int memo[1 << 11];

void recul(int value, int bm_pos, int bm_man) {

	//포지션에 대해 메모이제이션
	if (memo[bm_pos] >= value)	return;
	memo[bm_pos] = value;

	for (int i = 0; i < 11; i++)
	{
		if ((bm_man & (1 << i)) != 0)	continue;
		//선수가 이미 포지션이 있다면 건너뜀

		for (int j = 0; j < 11; j++)
		{
			if (pos[i][j] == 0)	continue;
			if ((bm_pos & (1 << j)) != 0)	continue;
			//포지션이 이미 배정되었다면 건너뜀

			recul(value + pos[i][j], bm_pos | (1 << j), bm_man | (1 << i));
		}
	}
}

int main(void) {
	FIO;

	cin >> t;

	while (t--) {

		for (int i = 0; i < (1 << 11); i++)
		{
			memo[i] = -1;
		}

		for (int i = 0; i < 11; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				cin >> pos[i][j];
			}
		}

		recul(0, 0, 0);

		cout << memo[(1 << 11) - 1] << "\n";
	}
}