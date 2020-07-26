/*
문제
길이가 N인 수식이 있다. 수식은 0보다 크거나 같고, 9보다 작거나 같은 정수와 연산자(+, -, ×)로 이루어져 있다. 곱하기의 연산자 우선순위가 더하기와 빼기보다 높기 때문에, 곱하기를 먼저 계산 해야 한다. 수식을 계산할 때는 왼쪽에서부터 순서대로 계산해야 한다. 예를 들어, 3+8×7-9×2의 결과는 41이다.

수식에 괄호를 추가하면, 괄호 안에 들어있는 식은 먼저 계산해야 한다. 예를 들어, 3+8×7-9×2에 괄호를 (3+8)×7-(9×2)와 같이 추가했으면, 식의 결과는 59가 된다. 중첩된 괄호도 사용할 수 있고, 괄호 안에 여러 개의 연산자가 들어 있어도 된다. 즉, 3+((8×7)-9)×2, 3+((8×7)-(9×2)), (3+8)×(7-9×2) 모두 올바른 식이고, 결과는 97, 41, -121이다.

수식이 주어졌을 때, 괄호를 적절히 추가해 만들 수 있는 식의 결과의 최댓값을 구하는 프로그램을 작성하시오. 추가하는 괄호 개수의 제한은 없으며, 추가하지 않아도 된다.

입력
첫째 줄에 수식의 길이 N(1 ≤ N ≤ 19)가 주어진다. 둘째 줄에는 수식이 주어진다. 수식에 포함된 정수는 모두 0보다 크거나 같고, 9보다 작거나 같다. 문자열은 정수로 시작하고, 연산자와 정수가 번갈아가면서 나온다. 연산자는 +, -, * 중 하나이다. 여기서 *는 곱하기 연산을 나타내는 × 연산이다. 항상 올바른 수식만 주어지기 때문에, N은 홀수이다.

출력
첫째 줄에 괄호를 적절히 추가해서 얻을 수 있는 결과의 최댓값을 출력한다. 정답은 231보다 작고, -231보다 크다.

풀이:
dp로 풀이하려다 막혀 시간복잡도를 계산해 보니 10! * 20 = 7천만 정도로 가능할 것 같아 Brute Force로 풀이했다.

숫자를 담을 벡터와 연산자를 담을 벡터를 따로 두고 Brute Force를 진행한다.

1 + 3 + 5 + 7

위와 같은 식이 있다면, 
숫자 벡터엔 1 3 5 7 , 연산자 벡터엔 + + + 이 처음에 들어가 있게 된다.

연속된 두 개의 숫자, 중간의 연산자를 묶어 계산한 뒤, 벡터를 복사하여 넘겨주는 식으로 진행한다.

1. 4 5 7 , + +
2. 1 8 7 , + +
3. 1 3 12 , + +

위 작업을 숫자 벡터의 크기가 1이 될 때까지 하고, max값을 갱신한다.

dp 풀이:

https://www.acmicpc.net/problem/11066 문제와 비슷한 방법으로 풀이한다.

maxdp[i][j] = i ~ j 까지의 최댓값
mindp[i][j] = i ~ j 까지의 최솟값

위 두 배열을 이용하여, i ~ j 가 작은 범위부터 0 ~ n 범위까지 구해가면 된다.

이 때, 음수로 인해 4가지 경우에 대해 모두 연산을 해 주어야 한다.(음수(최소) * 음수(최소) -> 최대일 수도 있기 때문)

최대, 최대
최대, 최소
최소, 최대
최소, 최소
*/
//Brute Force 풀이
#include<iostream>
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
int mv1[4] = { 0, 1, 0, -1 };
int mv2[4] = { 1, 0, -1, 0 };
int mv_all1[8] = { 0, 1, 0, -1, -1, -1, 1, 1 };
int mv_all2[8] = { 1, 0, -1, 0 , -1, 1, -1, 1 };

int n;
string str;
ll maxV = -LMAX;

ll calculate(char op, ll n1, ll n2) {
	if (op == '+')
		return n1 + n2;
	else if (op == '-')
		return n1 - n2;
	else
		return n1 * n2;
}

void recul(vector<ll> num, vector<char> oper) {

	if (num.size() == 1) {
		maxV = max(maxV, num[0]);
		return;
	}

	for (int i = 0; i < oper.size(); i++)
	{
		ll res = calculate(oper[i], num[i], num[i + 1]);

		vector<ll> nextNum;
		vector<char> nextOper;

		for (int j = 0; j < i; j++)
		{
			nextNum.push_back(num[j]);
		}

		nextNum.push_back(res);

		for (int j = i + 2; j < num.size(); j++)
		{
			nextNum.push_back(num[j]);
		}

		for (int j = 0; j < oper.size(); j++)
		{
			if (i != j)
				nextOper.push_back(oper[j]);
		}

		recul(nextNum, nextOper);
	}
}

int main(void) {
	FIO;

	cin >> n >> str;

	vector<char> oper;
	vector<ll> num;

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] >= '0' && str[i] <= '9') {
			num.push_back(str[i] - '0');
		}
		else {
			oper.push_back(str[i]);
		}
	}

	recul(num, oper);

	cout << maxV;
}


//dp 풀이
#include<iostream>
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
int mv1[4] = { 0, 1, 0, -1 };
int mv2[4] = { 1, 0, -1, 0 };
int mv_all1[8] = { 0, 1, 0, -1, -1, -1, 1, 1 };
int mv_all2[8] = { 1, 0, -1, 0 , -1, 1, -1, 1 };

int n;
string str;
ll maxdp[19][19];
ll mindp[19][19];

ll calculate(char op, ll n1, ll n2) {
	if (op == '+')
		return n1 + n2;
	else if (op == '-')
		return n1 - n2;
	else
		return n1 * n2;
}

int main(void) {
	FIO;

	cin >> n >> str;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			maxdp[i][j] = -LMAX;
			mindp[i][j] = LMAX;
			if (i == j && i % 2 == 0) {
				maxdp[i][j] = str[i] - '0';
				mindp[i][j] = str[i] - '0';
			}
		}
	}

	for (int range = 2; range < n; range += 2)
	{
		for (int s = 0; s + range < n; s += 2)
		{
			int e = s + range;

			ll maxV = -LMAX;
			ll minV = LMAX;

			if (range == 2) {
				maxV = calculate(str[s + 1], str[s] - '0', str[e] - '0');
				minV = calculate(str[s + 1], str[s] - '0', str[e] - '0');
			}
			else {
				for (int mid = s + 1; mid < e; mid += 2)
				{
					maxV = max(maxV, calculate(str[mid], maxdp[s][mid - 1], maxdp[mid + 1][e]));
					maxV = max(maxV, calculate(str[mid], mindp[s][mid - 1], mindp[mid + 1][e]));
					maxV = max(maxV, calculate(str[mid], mindp[s][mid - 1], maxdp[mid + 1][e]));
					maxV = max(maxV, calculate(str[mid], maxdp[s][mid - 1], mindp[mid + 1][e]));

					minV = min(minV, calculate(str[mid], maxdp[s][mid - 1], maxdp[mid + 1][e]));
					minV = min(minV, calculate(str[mid], mindp[s][mid - 1], mindp[mid + 1][e]));
					minV = min(minV, calculate(str[mid], mindp[s][mid - 1], maxdp[mid + 1][e]));
					minV = min(minV, calculate(str[mid], maxdp[s][mid - 1], mindp[mid + 1][e]));
				}
			}

			maxdp[s][e] = maxV;
			mindp[s][e] = minV;
		}
	}

	cout << max(mindp[0][n - 1], maxdp[0][n - 1]);
}