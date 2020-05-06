/*
B. Phoenix and Beauty
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Phoenix loves beautiful arrays. An array is beautiful if all its subarrays of length k have the same sum. A subarray of an array is any sequence of consecutive elements.

Phoenix currently has an array a of length n. He wants to insert some number of integers, possibly zero, into his array such that it becomes beautiful. The inserted integers must be between 1 and n inclusive. Integers may be inserted anywhere (even before the first or after the last element), and he is not trying to minimize the number of inserted integers.

Input
The input consists of multiple test cases. The first line contains an integer t (1≤t≤50) — the number of test cases.

The first line of each test case contains two integers n and k (1≤k≤n≤100).

The second line of each test case contains n space-separated integers (1≤ai≤n) — the array that Phoenix currently has. This array may or may not be already beautiful.

Output
For each test case, if it is impossible to create a beautiful array, print -1. Otherwise, print two lines.

The first line should contain the length of the beautiful array m (n≤m≤104). You don't need to minimize m.

The second line should contain m space-separated integers (1≤bi≤n) — a beautiful array that Phoenix can obtain after inserting some, possibly zero, integers into his array a. You may print integers that weren't originally in array a.

If there are multiple solutions, print any. It's guaranteed that if we can make array a beautiful, we can always make it with resulting length no more than 104.

풀이:
수열에 쓰인 숫자를 종류별로 하나씩 모아 벡터에 넣습니다.
이 숫자들을 N번 반복해나가면 원하는 수열을 얻을 수 있습니다.
수열에 쓰인 숫자의 개수가 K보다 크다면 -1을 출력합니다.
*/

#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<vector>
#include<set>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>
#define ll long long

int T, N, K;

int main(void) {
	FIO;

	cin >> T;

	while (T--) {
		cin >> N >> K;

		vector<int> ans;
		vector<int> used;
		bool visit[101];
		for (int i = 0; i < 101; i++)
		{
			visit[i] = false;
		}
		bool flag = true;

		for (int i = 0; i < N; i++)
		{
			int v;
			cin >> v;
			
			if (!visit[v]) {
				visit[v] = true;
				used.push_back(v);
			}
			if (used.size() > K)	flag = false;
		}

		if (!flag)
			cout << "-1\n";
		else {
			
			for (int i = 0; i < N; i++)
			{
				int idx = 0;
				for (int j = 0; j < K ; j++)
				{
					ans.push_back(used[idx]);
					idx = (idx + 1) % (used.size());
				}
			}

			cout << ans.size() << "\n";
			for (int i = 0; i < ans.size(); i++)
			{
				cout << ans[i] << " ";
			}
			cout << "\n";
		}

	}
}