/*
C. Painting Fence
time limit per test1 second
memory limit per test512 megabytes
inputstandard input
outputstandard output
Bizon the Champion isn't just attentive, he also is very hardworking.

Bizon the Champion decided to paint his old fence his favorite color, orange. The fence is represented as n vertical planks, put in a row. Adjacent planks have no gap between them. The planks are numbered from the left to the right starting from one, the i-th plank has the width of 1 meter and the height of ai meters.

Bizon the Champion bought a brush in the shop, the brush's width is 1 meter. He can make vertical and horizontal strokes with the brush. During a stroke the brush's full surface must touch the fence at all the time (see the samples for the better understanding). What minimum number of strokes should Bizon the Champion do to fully paint the fence? Note that you are allowed to paint the same area of the fence multiple times.

Input
The first line contains integer n (1 ≤ n ≤ 5000) — the number of fence planks. The second line contains n space-separated integers a1, a2, ..., an (1 ≤ ai ≤ 109).

Output
Print a single integer — the minimum number of strokes needed to paint the whole fence.
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

int N;
int fence[5001];

int recul(int s, int e) {
	int vans, hans;

	vans = e - s + 1;
	int mins = fence[s];

	for (int i = s + 1; i <= e; i++)
	{
		mins = min(mins, fence[i]);
	}
	for (int i = s; i <= e; i++)
	{
		fence[i] -= mins;
	}

	hans = mins;
	int i;
	for (i = s; i <= e;)
	{
		if (fence[i] != 0) {
			int a = i, b = i;

			while (b <= e && fence[b] != 0)	b++;

			hans += recul(a, b - 1);
			i = b;
		}
		else {
			i++;
		}
	}
	return min(vans, hans);
}

int main(void) {
	FIO;

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> fence[i];
	}

	cout << recul(1, N);
}*/