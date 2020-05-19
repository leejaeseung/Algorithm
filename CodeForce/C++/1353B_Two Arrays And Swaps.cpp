/*
B. Two Arrays And Swaps
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given two arrays a and b both consisting of n positive (greater than zero) integers. You are also given an integer k.

In one move, you can choose two indices i and j (1≤i,j≤n) and swap ai and bj (i.e. ai becomes bj and vice versa). Note that i and j can be equal or different (in particular, swap a2 with b2 or swap a3 and b9 both are acceptable moves).

Your task is to find the maximum possible sum you can obtain in the array a if you can do no more than (i.e. at most) k such moves (swaps).

You have to answer t independent test cases.

Input
The first line of the input contains one integer t (1≤t≤200) — the number of test cases. Then t test cases follow.

The first line of the test case contains two integers n and k (1≤n≤30;0≤k≤n) — the number of elements in a and b and the maximum number of moves you can do. The second line of the test case contains n integers a1,a2,…,an (1≤ai≤30), where ai is the i-th element of a. The third line of the test case contains n integers b1,b2,…,bn (1≤bi≤30), where bi is the i-th element of b.

Output
For each test case, print the answer — the maximum possible sum you can obtain in the array a if you can do no more than (i.e. at most) k swaps.

풀이:
그리디 알고리즘입니다.
배열 a의 현재 최소값보다 배열 b의 현재 최댓값이 크다면 b의 원소를 사용합니다.(최대 k번, b를 사용할 때마다 a의 최소값을 갱신해줌)
k번 수행하거나 a의 현재 최소값이 더 크면 a의 원소를 사용합니다.

두 개의 우선순위 큐를 사용했습니다.
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
#define IMAX 2000000001
int mv1[4] = { 0, 0, 1, -1 };
int mv2[4] = { 1, -1, 0, 0 };

int t, n, k;

int main(void) {
	FIO;

	cin >> t;
	while (t--) {
		cin >> n >> k;

		priority_queue<int> a;
		priority_queue<int> b;

		for (int i = 0; i < n; i++)
		{
			int v;
			cin >> v;
			a.push(-v);

		}

		for (int i = 0; i < n; i++)
		{
			int v;
			cin >> v;
			b.push(v);
		}

		int sum = 0;
		int cnt = k;

		for (int i = 0; i < n; i++)
		{
			if (i >= k || b.top() <= -a.top()) {
				sum += -a.top();
				a.pop();
			}
			else {
				sum += b.top();
				b.pop();
				a.pop();
			}
		}
		cout << sum << "\n";
	}
}