/*
문제
N줄에 0 이상 9 이하의 숫자가 세 개씩 적혀 있다. 내려가기 게임을 하고 있는데, 이 게임은 첫 줄에서 시작해서 마지막 줄에서 끝나게 되는 놀이이다.

먼저 처음에 적혀 있는 세 개의 숫자 중에서 하나를 골라서 시작하게 된다. 그리고 다음 줄로 내려가는데, 다음 줄로 내려갈 때에는 다음과 같은 제약 조건이 있다. 바로 아래의 수로 넘어가거나, 아니면 바로 아래의 수와 붙어 있는 수로만 이동할 수 있다는 것이다. 이 제약 조건을 그림으로 나타내어 보면 다음과 같다.



별표는 현재 위치이고, 그 아랫 줄의 파란 동그라미는 원룡이가 다음 줄로 내려갈 수 있는 위치이며, 빨간 가위표는 원룡이가 내려갈 수 없는 위치가 된다. 숫자표가 주어져 있을 때, 얻을 수 있는 최대 점수, 최소 점수를 구하는 프로그램을 작성하시오. 점수는 원룡이가 위치한 곳의 수의 합이다.

입력
첫째 줄에 N(1 ≤ N ≤ 100,000)이 주어진다. 다음 N개의 줄에는 숫자가 세 개씩 주어진다. 숫자는 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 중의 하나가 된다.

출력
첫째 줄에 얻을 수 있는 최대 점수와 최소 점수를 띄어서 출력한다.

풀이:
메모리 제한이 4MB 이기때문에 N개의 배열을 사용하면 메모리초과가 납니다.
따라서 그리디하게 dp[3] 의 배열을 재사용하여 풀이했습니다.

slide[i][j] = i~j중 최소 or 최대값,
slide 배열은 이전 dp값들을 가지고 각 구간의 최소 or 최대값을 가지고 있으므로 현재 dp값에 알맞게 더해주면 됩니다.
*/
#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<vector>
#include<queue>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>

int N;
int slideMin[3][3];
int slideMax[3][3];
int dpMin[3];
int dpMax[3];

int main(void) {
	FIO;

	cin >> N;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			slideMin[i][j] = 1000000000;
			slideMax[i][j] = 0;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 3; j++) {
			int n;
			cin >> n;
			
			if (i == 0) {
				slideMin[j][j] = n;
				slideMax[j][j] = n;
			}
			else {
				slideMin[j][j] = dpMin[j];
				slideMax[j][j] = dpMax[j];
			}
			dpMin[j] = n;
			dpMax[j] = n;
		}
		if (i > 0) {
			for (int i = 0; i < 3; i++)
			{
				for (int j = i + 1; j < 3; j++)
				{
					for (int k = i; k <= j ; k++)
					{
						slideMin[i][j] = min(slideMin[i][k], slideMin[k][j]);
						slideMax[i][j] = max(slideMax[i][k], slideMax[k][j]);
					}
					
				}
			}
			dpMin[0] += slideMin[0][1];
			dpMin[1] += slideMin[0][2];
			dpMin[2] += slideMin[1][2];
			dpMax[0] += slideMax[0][1];
			dpMax[1] += slideMax[0][2];
			dpMax[2] += slideMax[1][2];

			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					slideMin[i][j] = 1000000000;
					slideMax[i][j] = 0;
				}
			}
		}
	}
	int max_ans = max(dpMax[0], max(dpMax[1], dpMax[2]));
	int min_ans = min(dpMin[0], min(dpMin[1], dpMin[2]));
	cout << max_ans << " " << min_ans;
}