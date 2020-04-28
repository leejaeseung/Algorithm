/*
C. Journey
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
There are n cities and n - 1 roads in the Seven Kingdoms, each road connects two cities and we can reach any city from any other by the roads.

Theon and Yara Greyjoy are on a horse in the first city, they are starting traveling through the roads. But the weather is foggy, so they can’t see where the horse brings them. When the horse reaches a city (including the first one), it goes to one of the cities connected to the current city. But it is a strange horse, it only goes to cities in which they weren't before. In each such city, the horse goes with equal probabilities and it stops when there are no such cities.

Let the length of each road be 1. The journey starts in the city 1. What is the expected length (expected value of length) of their journey? You can read about expected (average) value by the link https://en.wikipedia.org/wiki/Expected_value.

Input
The first line contains a single integer n (1 ≤ n ≤ 100000) — number of cities.

Then n - 1 lines follow. The i-th line of these lines contains two integers u i and v i (1 ≤ u i, v i ≤ n, u i ≠ v i) — the cities connected by the i-th road.

It is guaranteed that one can reach any city from any other by the roads.

Output
Print a number — the expected length of their journey. The journey starts in the city 1.

Your answer will be considered correct if its absolute or relative error does not exceed 10 - 6.

Namely: let's assume that your answer is a, and the answer of the jury is b. The checker program will consider your answer correct, if .
문제 설명:
각 리프 노드까지 걸리는 거리와 모든 거리에 대한 기댓값을 출력하는 문제입니다.
풀이:
기댓값은 거리 * (노드까지 갈 확률) 의 총 합으로 구할 수 있습니다.
리프 노드들을 DFS로 탐색하면서 그 때의 거리와 확률값에 따라 계산해주면 됩니다.
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
#define ll long long

int N;
vector<int> vt[100001];
bool visit[100001];
double sum = 0;

void DFS(int now, int length, double pos) {

	if (now != 1 && vt[now].size() == 1) {
		sum += (1 / pos) * (double)(length);
		//기댓값을 계산
	}

	for (int i = 0; i < vt[now].size(); i++)
	{
		int next = vt[now][i];
		if (!visit[next]) {
			visit[next] = true;
			DFS(next, length + 1, pos * (vt[now].size() - 1));
			//다음 노드로 갈 확률 =  현재 확률 * 자식노드들의 개수
		}
	}
}

int main(void) {
	FIO;

	cin >> N;

	for (int i = 0; i < N - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		vt[a].push_back(b);
		vt[b].push_back(a);
	}

	vt[1].push_back(0);
	visit[0] = true;

	visit[1] = true;
	DFS(1, 0, 1);

	cout.precision(10);
	cout << sum;
}