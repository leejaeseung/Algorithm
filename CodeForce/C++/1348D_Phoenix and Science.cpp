/*
D. Phoenix and Science
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Phoenix has decided to become a scientist! He is currently investigating the growth of bacteria.

Initially, on day 1, there is one bacterium with mass 1.

Every day, some number of bacteria will split (possibly zero or all). When a bacterium of mass m splits, it becomes two bacteria of mass m2 each. For example, a bacterium of mass 3 can split into two bacteria of mass 1.5.

Also, every night, the mass of every bacteria will increase by one.

Phoenix is wondering if it is possible for the total mass of all the bacteria to be exactly n. If it is possible, he is interested in the way to obtain that mass using the minimum possible number of nights. Help him become the best scientist!

Input
The input consists of multiple test cases. The first line contains an integer t (1≤t≤1000) — the number of test cases.

The first line of each test case contains an integer n (2≤n≤109) — the sum of bacteria masses that Phoenix is interested in.

Output
For each test case, if there is no way for the bacteria to exactly achieve total mass n, print -1. Otherwise, print two lines.

The first line should contain an integer d  — the minimum number of nights needed.

The next line should contain d integers, with the i-th integer representing the number of bacteria that should split on the i-th day.

If there are multiple solutions, print any.

풀이:
mass의 크기는 절반으로 쪼개져도 결국 총 합은 같으므로 소수점을 고려할 필요가 없었습니다.
즉, 하루가 지날 때마다 +1 씩 늘어나는 것만 고려하면 됩니다.

박테리아가 가장 최대로 번식할 경우는 
1 -> 2 -> 4 -> 8 -> 16 ....
0	 1    2    3    4  .... day
위와 같이 증가하는데, 2day엔 최대 7까지 만들 수 있고, 3day엔 최대 15까지 만들 수 있습니다.
즉, N이 어느 구간에 있는지에 따라 day를 고정할 수 있습니다.
N 이 8~15 일 땐 3day, 16~31 일 땐 4day 등등...

day를 고정하면 그리디하게 풀이할 수 있습니다.
하루가 지날 때마다 현재 박테리아 수를 N에서 뺴주는데, 현재 박테리아 수를 구할 때 둘 중 한가지로 고릅니다.
1. (남은 N) / (남은 일 수)
2. 1에서 구한 박테리아 수를 전 날 박테리아로 만들 수 없을 때 -> 만들 수 있는 최대 박테리아를 구해야 하므로 2를 곱해줍니다.

늘어난 박테리아 - 원래 박테리아를 매번 출력해줍니다.
모든 N에 대해 구할 수 있으므로 -1을 출력할 필요가 없었습니다.
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
#define ll long long

int T, N;

int main(void) {
	FIO;

	cin >> T;

	while (T--) {
		cin >> N;
		int day = 0;
		int temp = N;

		while (temp / 2 != 0) {
			temp /= 2;
			day++;
		}

		int BC = 1;
		N -= 1;

		string ans = "";
		ans += to_string(day) + "\n";

		for (int i = 0; i < day; i++)
		{
			int left = day - i;
			int maximum = N / left;
			int ori_BC = BC;

			if (BC * 2 < maximum) {
				//maximum만큼의 박테리아를 만들 수 없을때
				BC *= 2;
			}
			else
				BC = maximum;
			N -= BC;
			ans += to_string(BC - ori_BC) + " ";
		}

		
		if (N == 0)
			cout << ans;
		else
			cout << "-1\n";
		cout << "\n";
	}
}