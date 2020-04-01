/*
A. Twins
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Imagine that you have a twin brother or sister. Having another person that looks exactly like you seems very unusual. It's hard to say if having something of an alter ego is good or bad. And if you do have a twin, then you very well know what it's like.

Now let's imagine a typical morning in your family. You haven't woken up yet, and Mom is already going to work. She has been so hasty that she has nearly forgotten to leave the two of her darling children some money to buy lunches in the school cafeteria. She fished in the purse and found some number of coins, or to be exact, n coins of arbitrary values a1, a2, ..., an. But as Mom was running out of time, she didn't split the coins for you two. So she scribbled a note asking you to split the money equally.

As you woke up, you found Mom's coins and read her note. "But why split the money equally?" — you thought. After all, your twin is sleeping and he won't know anything. So you decided to act like that: pick for yourself some subset of coins so that the sum of values of your coins is strictly larger than the sum of values of the remaining coins that your twin will have. However, you correctly thought that if you take too many coins, the twin will suspect the deception. So, you've decided to stick to the following strategy to avoid suspicions: you take the minimum number of coins, whose sum of values is strictly more than the sum of values of the remaining coins. On this basis, determine what minimum number of coins you need to take to divide them in the described manner.

Input
The first line contains integer n (1 ≤ n ≤ 100) — the number of coins. The second line contains a sequence of n integers a1, a2, ..., an (1 ≤ ai ≤ 100) — the coins' values. All numbers are separated with spaces.

Output
In the single line print the single number — the minimum needed number of coins.

문제 설명:
코인의 개수와 각 코인의 값들이 주어집니다.
코인을 가장 적게 가져가면서, 자신의 코인의 합이 나머지 코인의 값보다 크게 만들어야 합니다.

풀이:
그리디하게 코인을 내림차순으로 정렬하고, 가장 큰 값부터 코인을 가져가면서 서로의 총 합을 갱신해갑니다.
자신의 총 합이 더 커지는 때가 답이 됩니다.
*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<vector>
#include<queue>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>

int N;

int main(void) {
	FIO;

	cin >> N;

	int mySum = 0;
	int sSum = 0;
	priority_queue<int> pq;

	for (int i = 0; i < N; i++)
	{
		int n;
		cin >> n;

		pq.push(n);
		sSum += n;
	}

	int cnt = 0;

	while (!pq.empty() && mySum <= sSum) {
		int now = pq.top();	pq.pop();
		cnt++;

		mySum += now;
		sSum -= now;
	}
	cout << cnt;
}