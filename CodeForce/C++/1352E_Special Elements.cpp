/*
E. Special Elements
time limit per test1 second
memory limit per test64 megabytes
inputstandard input
outputstandard output
Pay attention to the non-standard memory limit in this problem.

In order to cut off efficient solutions from inefficient ones in this problem, the time limit is rather strict. Prefer to use compiled statically typed languages (e.g. C++). If you use Python, then submit solutions on PyPy. Try to write an efficient solution.

The array a=[a1,a2,…,an] (1≤ai≤n) is given. Its element ai is called special if there exists a pair of indices l and r (1≤l<r≤n) such that ai=al+al+1+…+ar. In other words, an element is called special if it can be represented as the sum of two or more consecutive elements of an array (no matter if they are special or not).

Print the number of special elements of the given array a.

For example, if n=9 and a=[3,1,4,1,5,9,2,6,5], then the answer is 5:

a3=4 is a special element, since a3=4=a1+a2=3+1;
a5=5 is a special element, since a5=5=a2+a3=1+4;
a6=9 is a special element, since a6=9=a1+a2+a3+a4=3+1+4+1;
a8=6 is a special element, since a8=6=a2+a3+a4=1+4+1;
a9=5 is a special element, since a9=5=a2+a3=1+4.
Please note that some of the elements of the array a may be equal — if several elements are equal and special, then all of them should be counted in the answer.

Input
The first line contains an integer t (1≤t≤1000) — the number of test cases in the input. Then t test cases follow.

Each test case is given in two lines. The first line contains an integer n (1≤n≤8000) — the length of the array a. The second line contains integers a1,a2,…,an (1≤ai≤n).

It is guaranteed that the sum of the values of n for all test cases in the input does not exceed 8000.

Output
Print t numbers — the number of special elements for each of the given arrays.

풀이:
모든 i ~ j 구간에 대해 구간 합을 구해야 하는 문제입니다.
prefix sum 으로 구간 합을 미리 구하고, 2중 반복문을 통해 모든 구간의 구간 합을 구해줍니다.
배열 내의 숫자 값이 몇 갠지 미리 구해두고, 각 구간 합이 배열 안에 있는 숫자 중 하나라면 체크합니다.

체크된 값들의 합을 구하여 출력하면 됩니다.
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

int num[8001];
bool sp[8001];
int sum[8001];
int t, n;

int main(void) {
	FIO;

	cin >> t;

	while (t--) {
		cin >> n;

		vector<int> vt;

		for (int i = 0; i <= n; i++)
		{
			sum[i] = 0;
			sp[i] = false;
			num[i] = 0;
		}

		for (int i = 1; i <= n; i++)
		{
			int v;
			cin >> v;

			num[v]++;
			sum[i] += sum[i - 1] + v;
		}

		int ans = 0;

		for (int i = 1; i <= n - 1; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				int s = sum[j] - sum[i - 1];
				if (s > 8000)	continue;
				if (num[s] != 0)
					sp[s] = true;
			}
		}

		for (int i = 1; i <= n; i++)
		{
			if (sp[i]) {
				ans += num[i];
			}
		}

		cout << ans << "\n";
	}
}