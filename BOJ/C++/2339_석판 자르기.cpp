/*
문제
하나 이상의 불순물과 보석 결정체로 이루어진 석판을 여러 조각으로 나누어 가공해서, 보다 높은 가치를 얻을 수 있도록 만들려고 한다. 이때, 높은 가치의 석판을 만들기 위해서는 석판을 여러 조각으로 나누되, 각 조각에는 불순물이 없도록 해야하며, 보석 결정체도 단 하나씩만 포함하고 있어야 한다.

또한, 석판에서 불순물을 빼내기 위해서는 불순물을 포함하고 있는 지점을 중심으로 잘라야 되는데, 석판의 결 때문에 가로 또는 세로 방향으로만 석판을 자를 수 있다. 석판을 자를 때에는 이전에 자른 방향과 같은 방향으로는 자를 수 없다. (단, 처음에 자를 때는 가로방향이나, 세로방향 모두 가능하다.)

석판에 있는 불순물과 보석 결정체의 정보가 주어질 때, 이 석판에서 불순물들을 없애면서 석판을 나누되, 각 조각에 반드시 하나의 보석 결정체만이 들어 있도록 석판을 나누는 방법이 모두 몇 가지 존재하는지 계산하시오.



위의 그림은 초기 석판의 상태에서 불순물을 제거하면서 석판을 잘랐을 때, 최종적으로 나뉘어진 석판의 모습이다. 회색 선은 불순물을 중심으로 가로 또는 세로 방향으로 자른 경계선이고, 노란 색은 보석을 하나씩만 포함하고 있는 석판이다. 석판을 자를 때 ②번이나 ③번은 이전에 잘려진 방향, 즉 ①번의 방향과 같은 방향으로 자를 수 없으며, ④ 번도 마찬가지로 ②번과는 같은 방향으로 자를 수 없다. 단순하게 자르는 순서를 의미하는 것이 아니므로, ④번 방향이 ③번 방향과 같을 수도 있다.

잘라진 석판은 반드시 두 개의 석판이 나뉘어진 것이어야 한다. 또한 결정체가 있는 곳은 자를 수 없으며, 최종적으로 나뉘어진 석판에 두 개 이상의 결정체가 오면 안 된다.

입력
첫 번째 줄에는 석판의 크기 N(1≤N≤20)이 들어온다. 다음 줄부터 N줄에 걸쳐서 석판의 상태가 입력으로 들어온다. 여기서 1은 불순물을 의미하며, 2는 보석 결정체, 0은 불순물과 보석결정체가 존재하지 않는 곳을 의미한다. 이때, 보석 결정체의 수는 15개를 넘지 않으며, 각 줄에 주어지는 석판의 정보는 공백 하나로 구분한다.

출력
각각의 석판 안에 불순물이 없으면서 단 하나의 보석 결정체만이 있도록 주어진 석판을 나눌 때, 모두 몇 가지의 경우가 존재하는지를 출력하시오. 이때 가능한 경우가 존재하지 않으면 -1을 출력한다.

풀이:
divide 함수는 사각형의 영역을 받고, 해당 영역에 대해 보석의 개수, 불순물의 개수를 세어 
보석의 개수 = 1, 불순물의 개수 = 0 일 경우에 1을 반환합니다.(완성된 석판)

만약 아니라면, 해당 영역에 존재하는 불순물들을 모두 보고, 이전 dir 값에 따라 불순물을 기준으로 쪼개어 
새로운 영역의 divide를 호출합니다.

경우의 수를 세는 법은 자신이 호출한 divide 두 개의 반환값의 곱으로 나타낼 수 있습니다.
(현재 상태로 만들 수 없다면 0을 반환, 따라서 만들 수 없다면 0 * x 가 됩니다.)
모든 불순물로 만들 수 있는 divide에 대해 반환값들을 모두 더한 뒤, 반환하면 됩니다.
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

int n;
int m[21][21];
vector<pii> bul_vt;

int divide(int x, int y, int size_x, int size_y, int dir) {

	if (x >= n || y >= n || size_x == 0 || size_y == 0)	return 1;
	//영역을 벗어날 경우 곱셈의 항등원인 1 반환.

	int bul_cnt = 0;
	int bo_cnt = 0;

	for (int i = x; i < x + size_x; i++)
	{
		for (int j = y; j < y + size_y; j++)
		{
			if (m[i][j] == 1) {
				bul_cnt++;
			}
			else if (m[i][j] == 2)
				bo_cnt++;
		}
	}

	if (bul_cnt == 0 && bo_cnt == 1) {
		//석판을 잘 쪼갠 경우
		return 1;
	}
	else {
		int ret = 0;

		for (int i = 0; i < bul_vt.size(); i++)
		{
			int bul_x = bul_vt[i].first;
			int bul_y = bul_vt[i].second;
			bool flag = true;
			if (bul_x < x || bul_y < y || bul_x >= x + size_x || bul_y >= y + size_y)	continue;
			//불순물이 현재 영역에 있는지 판단

			if (dir == 1) {
				//세로
				for (int j = x; j < x + size_x; j++)
				{
					if (m[j][bul_y] == 2) {
						//보석이 존재한다면 나눌 수 없음
						flag = false;
						break;
					}
				}
				if (flag)
					ret += (divide(x, y, size_x, bul_y - y, 2) * divide(x, bul_y + 1, size_x, y + size_y - bul_y - 1, 2));
					//두 가지 상황의 결과 수를 곱함
			}
			else if (dir == 2) {
				//가로
				for (int j = y; j < y + size_y; j++)
				{
					if (m[bul_x][j] == 2) {
						//보석이 존재한다면 나눌 수 없음
						flag = false;
						break;
					}
				}
				if (flag)
					ret += (divide(x, y, bul_x - x, size_y, 1) * divide(bul_x + 1, y, x + size_x - bul_x - 1, size_y, 1));
				//두 가지 상황의 결과 수를 곱함
			}
			else {
				//가로, 세로
				for (int j = x; j < x + size_x; j++)
				{
					if (m[j][bul_y] == 2) {
						//보석이 존재한다면 나눌 수 없음
						flag = false;
						break;
					}
				}
				if (flag)
					ret += (divide(x, y, size_x, bul_y - y, 2) * divide(x, bul_y + 1, size_x, y + size_y - bul_y - 1, 2));
				//두 가지 상황의 결과 수를 곱함

				flag = true;
				for (int j = y; j < y + size_y; j++)
				{
					if (m[bul_x][j] == 2) {
						//보석이 존재한다면 나눌 수 없음
						flag = false;
						break;
					}
				}
				if (flag)
					ret += (divide(x, y, bul_x - x, size_y, 1) * divide(bul_x + 1, y, x + size_x - bul_x - 1, size_y, 1));
				//두 가지 상황의 결과 수를 곱함
			}
		}

		return ret;
	}
}

int main(void) {
	FIO;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> m[i][j];
			if (m[i][j] == 1)
				bul_vt.push_back(make_pair(i, j));
		}
	}
	int ans = divide(0, 0, n, n, 0);
	if (ans == 0)
		cout << "-1";
	else
		cout << ans;
}