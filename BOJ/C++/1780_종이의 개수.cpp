/*
문제
N×N크기의 행렬로 표현되는 종이가 있다. 종이의 각 칸에는 -1, 0, 1의 세 값 중 하나가 저장되어 있다. 우리는 이 행렬을 적절한 크기로 자르려고 하는데, 이때 다음의 규칙에 따라 자르려고 한다.

만약 종이가 모두 같은 수로 되어 있다면 이 종이를 그대로 사용한다.
(1)이 아닌 경우에는 종이를 같은 크기의 9개의 종이로 자르고, 각각의 잘린 종이에 대해서 (1)의 과정을 반복한다.
이와 같이 종이를 잘랐을 때, -1로만 채워진 종이의 개수, 0으로만 채워진 종이의 개수, 1로만 채워진 종이의 개수를 구해내는 프로그램을 작성하시오.

입력
첫째 줄에 N(1≤N≤3^7, N은 3^k 꼴)이 주어진다. 다음 N개의 줄에는 N개의 정수로 행렬이 주어진다.

출력
첫째 줄에 -1로만 채워진 종이의 개수를, 둘째 줄에 0으로만 채워진 종이의 개수를, 셋째 줄에 1로만 채워진 종이의 개수를 출력한다.

풀이:
https://www.acmicpc.net/problem/1992 문제와 비슷하게 풀이하였습니다.
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
int square[2188][2188];
int ans1 = 0, ans2 = 0, ans3 = 0;		//-1, 0, 1

void divide(int x, int y, int size) {
	int cnt1 = 0, cnt2 = 0, cnt3 = 0;		//-1, 0, 1

	for (int i = x; i < x + size; i++)
	{
		for (int j = y; j < y + size; j++)
		{
			if (square[i][j] == -1) {
				cnt1++;
			}
			else if (square[i][j] == 0) {
				cnt2++;
			}
			else {
				cnt3++;
			}
		}
	}

	if (cnt1 == size * size) {
		ans1++;
	}
	else if (cnt2 == size * size) {
		ans2++;
	}
	else if (cnt3 == size * size) {
		ans3++;
	}
	else {
		int newSize = size / 3;

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				divide(x + i * newSize, y + j * newSize, newSize);
			}
		}
	}
}

int main(void) {
	FIO;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> square[i][j];
		}
	}

	divide(0, 0, n);

	cout << ans1 << "\n";
	cout << ans2 << "\n";
	cout << ans3 << "\n";
}