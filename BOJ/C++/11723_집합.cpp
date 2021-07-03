/*
문제
비어있는 공집합 S가 주어졌을 때, 아래 연산을 수행하는 프로그램을 작성하시오.

add x: S에 x를 추가한다. (1 ≤ x ≤ 20) S에 x가 이미 있는 경우에는 연산을 무시한다.
remove x: S에서 x를 제거한다. (1 ≤ x ≤ 20) S에 x가 없는 경우에는 연산을 무시한다.
check x: S에 x가 있으면 1을, 없으면 0을 출력한다. (1 ≤ x ≤ 20)
toggle x: S에 x가 있으면 x를 제거하고, 없으면 x를 추가한다. (1 ≤ x ≤ 20)
all: S를 {1, 2, ..., 20} 으로 바꾼다.
empty: S를 공집합으로 바꾼다.
입력
첫째 줄에 수행해야 하는 연산의 수 M (1 ≤ M ≤ 3,000,000)이 주어진다.

둘째 줄부터 M개의 줄에 수행해야 하는 연산이 한 줄에 하나씩 주어진다.

출력
check 연산이 주어질때마다, 결과를 출력한다.

풀이:
비트 연산 연습 문제
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
#define IMAX 2147483647
#define LMAX 1000000000000500000
#define DMAX 0xFFFFFFFFFFFFF
int mv1[4] = { 0, 1, -1, 0 };
int mv2[4] = { 1, 0, 0, -1 };

int m;
int bit = 0;

int main() {
	FIO;

	cin >> m;

	for (int i = 0; i < m; i++)
	{
		string str;
		int x;
		cin >> str;

		if (str != "all" && str != "empty") {
			cin >> x;
			x = 1 << x;
		}

		if (str == "add") {
			bit |= x;
		}
		else if (str == "remove") {
			bit &= ~x;
		}
		else if (str == "check") {
			cout << (bool)(bit & x) << "\n";
		}
		else if (str == "toggle") {
			bit = ~(bit ^ ~x);
		}
		else if (str == "all") {
			bit = 0xFFFFFFFF;
		}
		else {
			bit = 0;
		}
	}
}