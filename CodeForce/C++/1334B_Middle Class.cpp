/*
B. Middle Class
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Many years ago Berland was a small country where only n people lived. Each person had some savings: the i-th one had ai burles.

The government considered a person as wealthy if he had at least x burles. To increase the number of wealthy people Berland decided to carry out several reforms. Each reform looked like that:

the government chooses some subset of people (maybe all of them);
the government takes all savings from the chosen people and redistributes the savings among the chosen people equally.
For example, consider the savings as list [5,1,2,1]: if the government chose the 1-st and the 3-rd persons then it, at first, will take all 5+2=7 burles and after that will return 3.5 burles to the chosen people. As a result, the savings will become [3.5,1,3.5,1].

A lot of data was lost from that time, so we don't know how many reforms were implemented and to whom. All we can do is ask you to calculate the maximum possible number of wealthy people after several (maybe zero) reforms.

Input
The first line contains single integer T (1≤T≤1000) — the number of test cases.

Next 2T lines contain the test cases — two lines per test case. The first line contains two integers n and x (1≤n≤105, 1≤x≤109) — the number of people and the minimum amount of money to be considered as wealthy.

The second line contains n integers a1,a2,…,an (1≤ai≤109) — the initial savings of each person.

It's guaranteed that the total sum of n doesn't exceed 105.

Output
Print T integers — one per test case. For each test case print the maximum possible number of wealthy people after several (maybe zero) reforms.
*/
/*#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<string.h>
#include<queue>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>

int T, N, X;

int main(void) {
	FIO;

	cin >> T;

	while (T--) {
		cin >> N >> X;

		priority_queue<long long> pq;
		int cnt = 0;

		for (int i = 1; i <= N; i++)
		{
			long long x;
			cin >> x;

			pq.push(x);
		}

		long long remain = 0;

		while (!pq.empty()) {
			long long now = pq.top() + remain;	pq.pop();

			if (now >= X) {
				cnt++;
				remain = now - X;
			}
			else
				break;
		}
		cout << cnt << "\n";
	}
}*/