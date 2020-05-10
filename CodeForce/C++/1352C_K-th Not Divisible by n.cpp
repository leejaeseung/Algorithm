/*
C. K-th Not Divisible by n
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given two positive integers n and k. Print the k-th positive integer that is not divisible by n.

For example, if n=3, and k=7, then all numbers that are not divisible by 3 are: 1,2,4,5,7,8,10,11,13…. The 7-th number among them is 10.

Input
The first line contains an integer t (1≤t≤1000) — the number of test cases in the input. Next, t test cases are given, one per line.

Each test case is two positive integers n (2≤n≤109) and k (1≤k≤109).

Output
For each test case print the k-th positive integer that is not divisible by n.

풀이:
예제 중 하나인 7 97 을 예를 들면,
97까지 7의 배수는 총 13개가 있습니다.
그러면 97개의 수에서 13개가 빠지게 되겠죠. 따라서 97번째 수는 110이 오게 됩니다.
그런데 97 ~ 110중에서도 7의 배수가 있기 때문에 다시 빼주어야 합니다.
(110 / 7) - (97 / 7) = 2 이 97 ~ 110 사이의 7의 배수의 개수입니다.
다시 빼주면 112가 되고, 110 ~ 112 사이엔 또 1개의 7의 배수가 있기 때문에 다시 빼줍니다.

빼야 하는 배수의 개수가 없을 때까지 반복합니다.
*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>
#define pic pair<int, char>
#define ll long long
#define vi vector<int>
#define vl vector<long long>
#define vii vector<pii>

int t, n, k;

int main(void) {
	FIO;

	cin >> t;

	while (t--) {
		cin >> n >> k;

		int add = 0;
		int now = k;
		int p = 0;
		int s = 0;

		while (true) {
			add = (now / n) - s;
			if (add <= 0)	break;

			now += add;
			//현재 보고있는 now번째 수
			p = add;
			//i ~ j 사이의 n의 배수의 개수
			s += p;
			//s = 현재 수까지 총 n의 배수의 개수
		}
		cout << now << "\n";
	}
}