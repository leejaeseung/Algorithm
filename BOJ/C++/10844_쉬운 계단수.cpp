/*
	문제
45656이란 수를 보자.

이 수는 인접한 모든 자리수의 차이가 1이 난다. 이런 수를 계단 수라고 한다.

세준이는 수의 길이가 N인 계단 수가 몇 개 있는지 궁금해졌다.

N이 주어질 때, 길이가 N인 계단 수가 총 몇 개 있는지 구하는 프로그램을 작성하시오. (0으로 시작하는 수는 없다.)

입력
첫째 줄에 N이 주어진다. N은 1보다 크거나 같고, 100보다 작거나 같은 자연수이다.

출력
첫째 줄에 정답을 1,000,000,000으로 나눈 나머지를 출력한다.
	풀이 :
	숫자를 오른쪽으로 하나하나 붙여갈 때 0과 9 말고는 x가 나올 경우는 이전 수들에서 x-1과 x+1의 경우를 더한것과 같다.
	0과 9는 이전이 1과 8만 가능하므로 이전의 1과 8의 개수를 더해주면 된다.
*/
#include<iostream>

using namespace std;

#define MOD 1000000000

int main(void) {

	int N;
	cin >> N;
	int num_before[10];
	int num_after[10];

	num_before[0] = 0;
	for (int i = 1; i < 10; i++)
	{
		num_before[i] = 1;
	}

	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < 10; j++) {
			if (j == 0) {
				num_after[j] = num_before[1]%MOD;
			}
			else if (j == 9) {
				num_after[j] = num_before[8]%MOD;
			}
			else {
				num_after[j] = (num_before[j - 1]%MOD + num_before[j + 1]%MOD)%MOD;
			}
		}
		for (int k = 0; k < 10; k++) {
			num_before[k] = num_after[k]%MOD;
		}
	}
	int sum = 0;
	for (int i = 0; i < 10; i++)
	{
		sum =(sum%MOD+ num_before[i]%MOD)%MOD;
	}
	cout << sum;
}