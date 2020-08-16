/*
문제
유클리드 게임은 두 명이서 하는 게임이고, 자연수 2개로 시작한다. 동혁이와 동규는 유클리드 게임을 하려고 한다. 동혁이가 먼저 시작한다. 동혁이는 큰 수를 작은 수의 배수만큼 뺀다. 이때, 큰 수는 음이 아닌 정수가 되어야 한다.  그런 다음 동규는 동혁이가 한 것과 똑같이 큰 수를 작은 수의 배수만큼 뺀다. 이런식으로 두 플레이어는 서로 번갈아가면서 게임을 한다. 이때, 큰 수를 0으로 만든 사람이 게임을 승리하게 된다.

예를 들어, 다음과 같이 (25, 7)로 시작한 게임을 생각해보자.

25 7
11 7
4 7
4 3
1 3
1 0
위와 같이 게임을 하게 되면, 동혁이가 이기게 된다. (큰 수와 작은 수는 각 턴에서 큰 수와 작은 수이다.)

시작하는 두 자연수가 주어졌을 때, 두 플레이어가 최적의 방법으로 게임을 할 때, 누가 이기는지 구하는 프로그램을 작성하시오.

입력
입력은 여러 줄로 이루어져 있다. 각 줄은 게임을 시작하는 두 숫자이다. 항상 동혁이가 먼저 게임을 시작한다. 두 자연수는 231-1보다 작거나 같다. 입력의 마지막 줄에는 0 두 개가 주어진다.

출력
각 입력에 대해서 동혁이가 이기면 A wins를, 동규가 이기면 B wins를 출력한다.

풀이:
기본적으로 유클리드 호제법을 이용해 게임을 진행한다.(각 턴값을 바꿔가며)

이 때, 큰 수를 a, 작은 수를 b 라고 하면 게임의 승패는 다음과 같다.
1. a % b == 0 -> 바로 나누면 되므로 현재 턴이 무조건 승리한다.
2. a / b >= 2 -> a 에서 b 를 얼마나 뺄 지 선택할 수 있다. 즉, 현재 상황에서 너무 많이 빼서 결국 게임이 지게 된다면 
현재 상황에서 덜 빼고, 다음 턴이 밀리게 되므로 현재 턴이 무조건 이긴다.
3. a / b < 2 -> 할 수 있는게 a - b 밖에 없으므로 다음을 지켜본다.
*/
#include<iostream>
#include<memory.h>
#include<algorithm>
#include<math.h>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
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
int mv1[4] = { 0, 0, 1, -1 };
int mv2[4] = { 1, -1, 0, 0 };
int mv_all1[8] = { 0, 1, 0, -1, -1, -1, 1, 1 };
int mv_all2[8] = { 1, 0, -1, 0 , -1, 1, -1, 1 };

int gcb(int a, int b) {
	int turn = 1;

	while (b != 0) {
		turn *= -1;

		if (a % b == 0 || a / b >= 2)
			return turn;

		int temp = a % b;
		a = b;
		b = temp;
	}

	return turn;
}

int main(void) {
	FIO;

	while (true) {

		int a, b;
		cin >> a >> b;

		if (a == 0 && b == 0)
			break;

		int mx = max(a, b);
		int mn = min(a, b);

		int ans = gcb(mx, mn);

		if (ans < 0)
			cout << "A wins\n";
		else
			cout << "B wins\n";
	}
}