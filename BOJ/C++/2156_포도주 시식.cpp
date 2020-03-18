/*
	문제
효주는 포도주 시식회에 갔다. 그 곳에 갔더니, 테이블 위에 다양한 포도주가 들어있는 포도주 잔이 일렬로 놓여 있었다. 효주는 포도주 시식을 하려고 하는데, 여기에는 다음과 같은 두 가지 규칙이 있다.

포도주 잔을 선택하면 그 잔에 들어있는 포도주는 모두 마셔야 하고, 마신 후에는 원래 위치에 다시 놓아야 한다.
연속으로 놓여 있는 3잔을 모두 마실 수는 없다.
효주는 될 수 있는 대로 많은 양의 포도주를 맛보기 위해서 어떤 포도주 잔을 선택해야 할지 고민하고 있다. 1부터 n까지의 번호가 붙어 있는 n개의 포도주 잔이 순서대로 테이블 위에 놓여 있고, 각 포도주 잔에 들어있는 포도주의 양이 주어졌을 때, 효주를 도와 가장 많은 양의 포도주를 마실 수 있도록 하는 프로그램을 작성하시오. 

예를 들어 6개의 포도주 잔이 있고, 각각의 잔에 순서대로 6, 10, 13, 9, 8, 1 만큼의 포도주가 들어 있을 때, 첫 번째, 두 번째, 네 번째, 다섯 번째 포도주 잔을 선택하면 총 포도주 양이 33으로 최대로 마실 수 있다.

입력
첫째 줄에 포도주 잔의 개수 n이 주어진다. (1≤n≤10,000) 둘째 줄부터 n+1번째 줄까지 포도주 잔에 들어있는 포도주의 양이 순서대로 주어진다. 포도주의 양은 1,000 이하의 음이 아닌 정수이다.

출력
첫째 줄에 최대로 마실 수 있는 포도주의 양을 출력한다.
	풀이 :
	점화식 문제.
	처음엔 재귀함수를 이용해 풀었지만 피보나치와 비슷한 구조라 시간이 오래걸림.
	dp배열을 만들어 반복문을 통해 해결.
*/
#include<iostream>
#include<stdlib.h>

using namespace std;

//int find(int *grape, int index);
int max(int a, int b);

int main(void) {
	int N;
	cin >> N;

	int *grape = (int*)malloc(sizeof(int)*(N+1));
	int *dp= (int*)malloc(sizeof(int)*(N+1));

	for (int i = 1; i <= N; i++)
	{
		cin >> grape[i];
	}
	if (N > 2) {
		dp[1] = grape[1];
		dp[2] = grape[1] + grape[2];
		for (int i = 3; i <= N; i++)
		{
			dp[i] = max(max(dp[i - 2] + grape[i], dp[i -3] + grape[i - 1] + grape[i]), dp[i- 1]);
		}
		cout << dp[N];
	}
	else if (N == 1) {
		cout << grape[1];
	}
	else {
		cout << grape[1] + grape[2];
	}
}
/*
int find(int *grape, int index) {
	int sum = 0;
	if (index == 0) {
		return grape[0];
	}
	if (index == 1) {
		return grape[1]+grape[0];
	}
	if (index < 0)
		return 0;

	sum += max(max(find(grape, index - 2) + grape[index], find(grape, index - 3) +grape[index-1]+ grape[index]), find(grape, index - 1));

	return sum;
}*/
int max(int a, int b) {
	if (a >= b)
		return a;
	else
		return b;
}