/*
A. Level Statistics
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Polycarp has recently created a new level in this cool new game Berlio Maker 85 and uploaded it online. Now players from all over the world can try his level.

All levels in this game have two stats to them: the number of plays and the number of clears. So when a player attempts the level, the number of plays increases by 1. If he manages to finish the level successfully then the number of clears increases by 1 as well. Note that both of the statistics update at the same time (so if the player finishes the level successfully then the number of plays will increase at the same time as the number of clears).

Polycarp is very excited about his level, so he keeps peeking at the stats to know how hard his level turns out to be.

So he peeked at the stats n times and wrote down n pairs of integers — (p1,c1),(p2,c2),…,(pn,cn), where pi is the number of plays at the i-th moment of time and ci is the number of clears at the same moment of time. The stats are given in chronological order (i.e. the order of given pairs is exactly the same as Polycarp has written down).

Between two consecutive moments of time Polycarp peeked at the stats many players (but possibly zero) could attempt the level.

Finally, Polycarp wonders if he hasn't messed up any records and all the pairs are correct. If there could exist such a sequence of plays (and clears, respectively) that the stats were exactly as Polycarp has written down, then he considers his records correct.

Help him to check the correctness of his records.

For your convenience you have to answer multiple independent test cases.

Input
The first line contains a single integer T (1≤T≤500) — the number of test cases.

The first line of each test case contains a single integer n (1≤n≤100) — the number of moments of time Polycarp peeked at the stats.

Each of the next n lines contains two integers pi and ci (0≤pi,ci≤1000) — the number of plays and the number of clears of the level at the i-th moment of time.

Note that the stats are given in chronological order.

Output
For each test case print a single line.

If there could exist such a sequence of plays (and clears, respectively) that the stats were exactly as Polycarp has written down, then print "YES".

Otherwise, print "NO".

You can print each letter in any case (upper or lower).
*/
/*#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<string.h>
#include<vector>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>

int T, N;

int main(void) {
	FIO;

	cin >> T;

	while (T--) {
		cin >> N;

		int p = 0, c = 0;
		bool flag = true;

		for (int i = 0; i < N; i++)
		{
			int a, b;

			cin >> a >> b;

			if (p > a || c > b)	flag = false;
			if (abs(p - a) < abs(c - b))	flag = false;
			p = a;
			c = b;
		}
		if (p < c)	flag = false;

		if (flag)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}*/