/*
A. Reposts
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
One day Polycarp published a funny picture in a social network making a poll about the color of his handle. Many of his friends started reposting Polycarp's joke to their news feed. Some of them reposted the reposts and so on.

These events are given as a sequence of strings "name1 reposted name2", where name1 is the name of the person who reposted the joke, and name2 is the name of the person from whose news feed the joke was reposted. It is guaranteed that for each string "name1 reposted name2" user "name1" didn't have the joke in his feed yet, and "name2" already had it in his feed by the moment of repost. Polycarp was registered as "Polycarp" and initially the joke was only in his feed.

Polycarp measures the popularity of the joke as the length of the largest repost chain. Print the popularity of Polycarp's joke.

Input
The first line of the input contains integer n (1 ≤ n ≤ 200) — the number of reposts. Next follow the reposts in the order they were made. Each of them is written on a single line and looks as "name1 reposted name2". All the names in the input consist of lowercase or uppercase English letters and/or digits and have lengths from 2 to 24 characters, inclusive.

We know that the user names are case-insensitive, that is, two names that only differ in the letter case correspond to the same social network user.

Output
Print a single integer — the maximum length of a repost chain.

풀이:
문자열을 트리 인덱스로 적절하게 변환해주고, 트리의 최대 깊이 + 1 을 구하면 됩니다.
*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<vector>
#include<stack>
#include<map>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>
#define ll long long

int N;
map<string, int> m;
vector<int> edge[201];
int maxD = 0;

void DFS(int now, int d) {
	
	maxD = max(maxD, d);

	for (int i = 0; i < edge[now].size(); i++)
	{
		DFS(edge[now][i], d + 1);
	}
}

int main(void) {
	FIO;

	cin >> N;

	int idx = 1;
	m.insert(make_pair("polycarp", 0));

	for (int i = 0; i < N; i++)
	{
		string from, to, trash;
		cin >> to >> trash >> from;

		transform(to.begin(), to.end(), to.begin(), tolower);
		transform(from.begin(), from.end(), from.begin(), tolower);

		if (m.find(from) == m.end()) {
			m.insert(make_pair(from, idx++));
		}

		m.insert(make_pair(to, idx++));

		edge[m.find(from)->second].push_back(m.find(to)->second);
	}

	DFS(0, 1);

	cout << maxD;
}