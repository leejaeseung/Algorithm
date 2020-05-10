/*
문제
"피아의 아틀리에 ~신비한 대회의 연금술사~"는 가난한 연금술사 피아의 성장스토리를 담은 게임이다. 이 게임의 가장 중요한 부분은 "대회"인데, 연금술로 높은 품질의 물건을 만들어 상금을 타야만 피아가 먹고 살 수 있기 때문이다. 스토리는 매우 길지만 여백이 없어 생략하기로 하고, 여러분은 이 게임의 대회 기능을 확인해달라는 요청을 받았다. 여러분이 확인해야 하는 대회는 다음과 같다.

여러분은 5×5 격자 모양 가마에 서로 다른 재료 3개를 순서대로 넣어 최고 품질의 폭탄을 만들어야 한다. 재료는 대회에서 준비해주며, 넣을 수 있는 재료의 후보는 10개 이하이다. 주어진 재료 중 3개를 고른 뒤, 순서를 정해 가마에 잘 넣어야 한다.

가마의 각 칸에는 품질을 나타내는 숫자와 원소를 나타내는 색이 칠해져 있다. 초기에는 모든 칸의 품질은 0, 원소는 흰색이다. 재료는 4×4 모양으로 생겼으며, 재료의 i행 j열에는 2가지 정보가 있다.

효능: 가마 한 칸의 품질을 바꾸는 -9 이상 9 이하의 정수 xi,j
원소: 가마 한 칸의 원소를 바꿀 수 있는 색 ci,j (빨강 'R', 파랑 'B', 초록 'G', 노랑 'Y', 흰색 'W' 중 하나이다)
재료를 가마에 넣을 때는 5×5 격자를 벗어날 수 없다. 회전은 가능하나, 격자에 맞지 않게 기울여 넣을 수는 없다. 재료를 가마에 넣을 때, 가마의 상태는 다음과 같이 바뀐다.

재료가 위치하지 않는 가마의 격자칸은 아무런 변화가 생기지 않는다.
재료가 위치한 가마의 격자칸에 있는 품질과 원소값은 바뀔 수 있다.
격자의 품질은 재료의 효능이 더해진다. 더한 뒤의 값이 음수인 경우 0으로, 9 초과인 경우 9로 바뀐다.
격자의 색은 재료의 원소가 흰색인 경우 그대로, 아닌 경우 재료의 원소와 같은 색으로 칠해진다.
재료 3개를 모두 넣어야만 폭탄이 만들어지며, 폭탄의 품질은 다음과 같이 계산된다. 가마의 최종 상태에서 빨강, 파랑, 초록, 노랑으로 칠해진 부분의 품질 합을 각각 R, B, G, Y라고 했을 때,

(폭탄의 품질) = 7R + 5B + 3G + 2Y

폭탄을 만들기 위한 재료의 후보가 주어졌을 때, 재료를 적절히 선택하고 배치하여 만들 수 있는 폭탄의 최대 품질을 구하자.

입력
첫 번째 줄에 재료의 개수를 나타내는 자연수 n이 주어진다. (3 ≤ n ≤ 10)

두 번째 줄부터 n개의 재료 정보가 순서대로 주어진다. 각 재료의 정보는 다음과 같다. 먼저 4개의 줄에 효능을 나타내는 수 4개가 공백을 사이에 두고 주어진다. 다음 4개의 줄에 원소를 나타내는 글자 4개가 공백을 사이에 두고 주어진다. 이 글자는 R, B, G, Y, W 중 하나임이 보장된다.

출력
첫 번째 줄에 품질의 최댓값을 출력한다.

풀이:
ㅂㄷㅂㄷ...
완전탐색 문제입니다.
처음엔 배열로 매번 가마의 상태를 만들어주었는데 시간초과 -> 벡터를 call by value로 인자로 전달하니 됐습니다.
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
#define pic pair<int, char>
#define ll long long
#define vi vector<int>
#define vl vector<long long>
#define vii vector<pii>

struct state {
	int eff;
	int ele;

	state() { }
	state(int _eff, int _ele) : eff(_eff), ele(_ele) { }
};

int n;
int material[11][4][4][4][2];
int ans = 0;
bool used[11];
vector<vector<state>> v(5, vector<state>(5));

int sum(vector<vector<state>> gama) {
	int r = 0, b = 0, g = 0, y = 0;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (gama[i][j].ele == 1)
				r += gama[i][j].eff;
			if (gama[i][j].ele == 2)
				b += gama[i][j].eff;
			if (gama[i][j].ele == 3)
				g += gama[i][j].eff;
			if (gama[i][j].ele == 4)
				y += gama[i][j].eff;
		}
	}
	return r * 7 + b * 5 + g * 3 + y * 2;
}

vector<vector<state>> draw(vector<vector<state>> gama, int m, int r, int si, int sj) {

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			gama[i + si][j + sj].eff += material[m][r][i][j][0];
			if (gama[i + si][j + sj].eff < 0)
				gama[i + si][j + sj].eff = 0;
			else if (gama[i + si][j + sj].eff > 9)
				gama[i + si][j + sj].eff = 9;

			if (material[m][r][i][j][1] != 0)
				gama[i + si][j + sj].ele = material[m][r][i][j][1];
		}
	}
	return gama;
}

void BF(vector<vector<state>> gama, int cnt) {

	if (cnt == 3) {
		ans = max(ans, sum(gama));
		return;
	}

	for (int t = 0; t < n; t++)
	{
		if (!used[t]) {
			used[t] = true;

				for (int i = 0; i < 4; i++)
				{
					for (int si = 0; si <= 1; si++)
					{
						for (int sj = 0; sj <= 1; sj++)
						{
							vector<vector<state>> temp = draw(gama, t, i, si, sj);
							BF(temp, cnt + 1);
						}
					}
				}
				used[t] = false;
			}
		
	}
}

void rotate() {

	for (int l = 0; l < n; l++)
	{
		for (int r = 1; r < 4; r++)
		{
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					material[l][r][j][i][0] = material[l][r - 1][i][3 - j][0];
					material[l][r][j][i][1] = material[l][r - 1][i][3 - j][1];
				}
			}
		}
	}
}

int main(void) {
	FIO;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		used[i] = false;
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				cin >> material[i][0][j][k][0];
			}
		}

		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				char c;
				cin >> c;
				if (c == 'W')
					material[i][0][j][k][1] = 0;
				else if(c == 'R')
					material[i][0][j][k][1] = 1;
				else if(c == 'B')
					material[i][0][j][k][1] = 2;
				else if(c == 'G')
					material[i][0][j][k][1] = 3;
				else
					material[i][0][j][k][1] = 4;
			}
		}
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			v[i][j] = state(0, 0);
		}
	}

	rotate();

	BF(v, 0);

	cout << ans;
}