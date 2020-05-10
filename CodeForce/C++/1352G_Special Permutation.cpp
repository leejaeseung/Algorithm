/*
G. Special Permutation
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
A permutation of length n is an array p=[p1,p2,…,pn], which contains every integer from 1 to n (inclusive) and, moreover, each number appears exactly once. For example, p=[3,1,4,2,5] is a permutation of length 5.

For a given number n (n≥2), find a permutation p in which absolute difference (that is, the absolute value of difference) of any two neighboring (adjacent) elements is between 2 and 4, inclusive. Formally, find such permutation p that 2≤|pi−pi+1|≤4 for each i (1≤i<n).

Print any such permutation for the given integer n or determine that it does not exist.

Input
The first line contains an integer t (1≤t≤100) — the number of test cases in the input. Then t test cases follow.

Each test case is described by a single line containing an integer n (2≤n≤1000).

Output
Print t lines. Print a permutation that meets the given requirements. If there are several such permutations, then print any of them. If no such permutation exists, print -1.

풀이:
처음엔 기본적인 DFS로 2,3,4,-2,-3,-4 값을 더해가며 풀이했었지만 당연히 시간 초과가 났습니다.
그래서 DFS를 할 때 next 수에 대해 가지치기를 추가했습니다.
next 수에 대해 2,3,4,-2,-3,-4 값을 더했을 때 해당 수가 존재하는지 체크를 해줘서 하나라도 존재하면 next값을 사용해도 됩니다.

그리고 dfs 시작 값을 0 으로 하면 n = 999 에서 무한 루프를 돌고, 시작 값을 -1로 하면 n = 1000에서 무한 루프를 돌길래
n 이 홀수 , 짝수일 때를 나눴더니 통과가 됐습니다.
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
#define pic pair<int, char>
#define ll long long
#define vi vector<int>
#define vl vector<long long>
#define vii vector<pii>

int t, n;
deque<int> ans;
bool check[1001];
int p[6] = { 2, 3, 4, -2, -3, -4 };
bool can[1001][6];
map<int, int> m;

bool dfs(int now, int leng) {

	if (leng == n) {

		while (!ans.empty()) {
			cout << ans.front() << " ";
			ans.pop_front();
		}
		return true;
	}

	for (size_t i = 0; i < 6; i++)
	{
		int next = now + p[i];
		bool flag = false;

		if (next <= 0 || next > n)	continue;
		if (check[next])	continue;

		for (int j = 0; j < 6; j++)
		{
			if (next + p[j] <= 0 || next + p[j] > n)	continue;
			can[next + p[j]][m[-p[i]]] = false;
			for (int k = 0; k < 6; k++)
			{
				if (can[next + p[j]][k]) {
					flag = true;
					break;
				}
			}
		}
		if (!flag) {
			for (int j = 0; j < 6; j++)
			{
				if (next + p[j] <= 0 || next + p[j] > n)	continue;
				can[next + p[j]][m[-p[i]]] = true;
			}
			continue;
		}

		ans.push_back(next);
		check[next] = true;

		if (dfs(next, leng + 1))
			return true;

		for (int j = 0; j < 6; j++)
		{
			if (next + p[j] <= 0 || next + p[j] > n)	continue;
			can[next + p[j]][m[-p[i]]] = true;
		}

		ans.pop_back();
		check[next] = false;
	}
	return false;
}

int main(void) {
	FIO;

	cin >> t;

	for (int i = 0; i < 6; i++)
	{
		m[p[i]] = i;
	}

	while (t--) {
		cin >> n;

		for (int i = 1; i <= n; i++)
		{
			check[i] = false;
			for (int j = 0; j < 6; j++)
			{
				can[i][j] = true;
			}
		}

		if (n % 2 == 0)
			dfs(0, 0);
		else
			dfs(-1, 0);
			
		if (n == 2 || n == 3)
			cout << "-1\n";
		else
			cout << "\n";
	}
}