/*
	문제
        7
      3   8
    8   1   0
  2   7   4   4
4   5   2   6   5
위 그림은 크기가 5인 정수 삼각형의 한 모습이다.

맨 위층 7부터 시작해서 아래에 있는 수 중 하나를 선택하여 아래층으로 내려올 때, 이제까지 선택된 수의 합이 최대가 되는 경로를 구하는 프로그램을 작성하라. 아래층에 있는 수는 현재 층에서 선택된 수의 대각선 왼쪽 또는 대각선 오른쪽에 있는 것 중에서만 선택할 수 있다.

삼각형의 크기는 1 이상 500 이하이다. 삼각형을 이루고 있는 각 수는 모두 정수이며, 범위는 0 이상 9999 이하이다.

입력
첫째 줄에 삼각형의 크기 n(1 ≤ n ≤ 500)이 주어지고, 둘째 줄부터 n+1번째 줄까지 정수 삼각형이 주어진다.

출력
첫째 줄에 합이 최대가 되는 경로에 있는 수의 합을 출력한다.

	풀이 :
	[500][500] 크기의 배열을 만들어 [j][i]는 j행i열까지 가는 데에 최대 합으로 하여 구한다.
	[j][i]는 이전 두 수 중 최대값과 현재 값을 더한 값이다.
	양 모서리일 때는 이전 값만 더한다.
*/
#include<iostream>

using namespace std;

int max(int a, int b);

int main(void) {

	int N;
	cin >> N;
	int triagle[501][501];
	int output = 0;

	cin >> triagle[1][1];
	if (N >= 2) {
		for (int i = 2; i <= N; i++)
		{
			for (int j = 1; j <= i; j++)
			{
				int temp;
				cin >> temp;

				if (j == 1) {
					triagle[i][j] = temp + triagle[i - 1][j];
				}
				else if (j == i) {
					triagle[i][j] = temp + triagle[i - 1][j-1];
				}
				else {
					triagle[i][j] = max(triagle[i - 1][j - 1] + temp, triagle[i - 1][j] + temp);
				}
				if (output < triagle[i][j])
					output = triagle[i][j];
			}
		}
		cout << output;
	}
	else {
		cout << triagle[1][1];
	}
	return 0;
}
int max(int a,int b) {
	if (a >= b)
		return a;
	else
		return b;
}