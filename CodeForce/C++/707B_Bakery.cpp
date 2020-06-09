/*
B. Bakery
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Masha wants to open her own bakery and bake muffins in one of the n cities numbered from 1 to n. There are m bidirectional roads, each of whose connects some pair of cities.

To bake muffins in her bakery, Masha needs to establish flour supply from some storage. There are only k storages, located in different cities numbered a1, a2, ..., ak.

Unforunately the law of the country Masha lives in prohibits opening bakery in any of the cities which has storage located in it. She can open it only in one of another n - k cities, and, of course, flour delivery should be paid — for every kilometer of path between storage and bakery Masha should pay 1 ruble.

Formally, Masha will pay x roubles, if she will open the bakery in some city b (ai ≠ b for every 1 ≤ i ≤ k) and choose a storage in some city s (s = aj for some 1 ≤ j ≤ k) and b and s are connected by some path of roads of summary length x (if there are more than one path, Masha is able to choose which of them should be used).

Masha is very thrifty and rational. She is interested in a city, where she can open her bakery (and choose one of k storages and one of the paths between city with bakery and city with storage) and pay minimum possible amount of rubles for flour delivery. Please help Masha find this amount.

Input
The first line of the input contains three integers n, m and k (1 ≤ n, m ≤ 105, 0 ≤ k ≤ n) — the number of cities in country Masha lives in, the number of roads between them and the number of flour storages respectively.

Then m lines follow. Each of them contains three integers u, v and l (1 ≤ u, v ≤ n, 1 ≤ l ≤ 109, u ≠ v) meaning that there is a road between cities u and v of length of l kilometers .

If k > 0, then the last line of the input contains k distinct integers a1, a2, ..., ak (1 ≤ ai ≤ n) — the number of cities having flour storage located in. If k = 0 then this line is not presented in the input.

Output
Print the minimum possible amount of rubles Masha should pay for flour delivery in the only line.

If the bakery can not be opened (while satisfying conditions) in any of the n cities, print  - 1 in the only line.

풀이:
storage 가 있는 도시를 시작점으로 하여 시작점에서 갈 수 있는 도시 중(storage가 아닌)
최소 거리를 구하면 됩니다.
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
#define pll pair<long long, long long>
#define pdd pair<double, double>
#define pic pair<int, char>
#define ll long long
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vii vector<pii>
#define vll vector<pll>
#define IMAX 2000000001
#define LMAX 1000000000000000000
#define DMAX 0xFFFFFFFFFFFFF
int mv1[4] = { 0, 1, 0, -1 };
int mv2[4] = { 1, 0, -1, 0 };

int n, m, k;
priority_queue<pll> pq[100001];
queue<int> q;
int check[100001];

int main(void) {
	FIO;

	cin >> n >> m >> k;

	for (int i = 0; i < m; i++)
	{
		int from, to;
		ll v;
		cin >> from >> to >> v;

		pq[from].push(make_pair(-v, to));
		pq[to].push(make_pair(-v, from));
	}

	for (int i = 0; i < k; i++)
	{
		int a;
		cin >> a;
		q.push(a);
		check[a] = true;
	}

	ll ans = LMAX;

	while (!q.empty()) {
		int now = q.front();	q.pop();

		while (!pq[now].empty())
		{
			int next = pq[now].top().second;
			ll leng = -pq[now].top().first;
			pq[now].pop();

			if (!check[next])
				ans = min(ans, leng);
		}
	}

	if (ans == LMAX)
		cout << "-1";
	else
		cout << ans;
}