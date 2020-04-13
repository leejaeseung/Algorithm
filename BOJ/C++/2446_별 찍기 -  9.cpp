/*
문제
예제를 보고 규칙을 유추한 뒤에 별을 찍어 보세요.

입력
첫째 줄에 N(1 ≤ N ≤ 100)이 주어진다.

출력
첫째 줄부터 2×N-1번째 줄까지 차례대로 별을 출력한다.
*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<string.h>
#include<vector>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>

int N;
bool flag = false;

void recul(int left, int right, int cnt) {

	if (cnt >= 2 * N - 1)	exit(0);

	for (int i = 0; i < left; i++)
	{
		cout << " ";
	}
	for (int i = left; i < right; i++)
	{
		cout << "*";
	}
	cout << "\n";
	if (left + 1 == right)
		flag = true;
	if(!flag)
		recul(left + 1, right - 1, cnt + 1);
	else
		recul(left -1, right + 1, cnt + 1);
}

int main(void) {
	FIO;

	cin >> N;

	recul(0, 2 * N - 1, 0);
}