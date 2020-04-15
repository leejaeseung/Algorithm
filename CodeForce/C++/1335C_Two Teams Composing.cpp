/*
C. Two Teams Composing
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You have n students under your control and you have to compose exactly two teams consisting of some subset of your students. Each student had his own skill, the i-th student skill is denoted by an integer ai (different students can have the same skills).

So, about the teams. Firstly, these two teams should have the same size. Two more constraints:

The first team should consist of students with distinct skills (i.e. all skills in the first team are unique).
The second team should consist of students with the same skills (i.e. all skills in the second team are equal).
Note that it is permissible that some student of the first team has the same skill as a student of the second team.

Consider some examples (skills are given):

[1,2,3], [4,4] is not a good pair of teams because sizes should be the same;
[1,1,2], [3,3,3] is not a good pair of teams because the first team should not contain students with the same skills;
[1,2,3], [3,4,4] is not a good pair of teams because the second team should contain students with the same skills;
[1,2,3], [3,3,3] is a good pair of teams;
[5], [6] is a good pair of teams.
Your task is to find the maximum possible size x for which it is possible to compose a valid pair of teams, where each team size is x (skills in the first team needed to be unique, skills in the second team should be the same between them). A student cannot be part of more than one team.

You have to answer t independent test cases.

Input
The first line of the input contains one integer t (1≤t≤104) — the number of test cases. Then t test cases follow.

The first line of the test case contains one integer n (1≤n≤2⋅105) — the number of students. The second line of the test case contains n integers a1,a2,…,an (1≤ai≤n), where ai is the skill of the i-th student. Different students can have the same skills.

It is guaranteed that the sum of n over all test cases does not exceed 2⋅105 (∑n≤2⋅105).

Output
For each test case, print the answer — the maximum possible size x for which it is possible to compose a valid pair of teams, where each team size is x.

풀이:
같은 수들을 많은 순서대로 정렬합니다.
서로 다른 숫자들의 개수를 세줍니다.
다음과 같은 세 가지의 경우가 있습니다.

같은 수 >= 서로 다른 수 + 1 -> 서로 다른 수
같은 수 == 서로 다른 수 -> 같은 수 - 1
그 외 경우 -> 같은 수

내림차순으로 정렬 된 같은 수들에 대해 위 값 중 최대값을 구합니다.
*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<string.h>
#include<queue>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>
#define ll long long

int N, T;
int same[200001];
bool replicate[200001];

int main(void) {
	FIO;

	cin >> T;

	while (T--) {
		cin >> N;

		memset(same, 0, sizeof(same));
		memset(replicate, false, sizeof(replicate));
		priority_queue<pii> pq;

		int re_cnt = 0;
		for (int i = 0; i < N; i++)
		{
			int v;
			cin >> v;
			
			same[v]++;
			if (!replicate[v]) {
				re_cnt++;
				replicate[v] = true;
			}
		}
		for (int i = 1; i < 200001; i++)
		{
			if (same[i] != 0)
				pq.push(make_pair(same[i], i));
		}
		int ans = 0;
		while (!pq.empty()) {
			int nowCnt = pq.top().first;
			int nowV = pq.top().second;	pq.pop();

			if (nowCnt >= re_cnt + 1) {
				ans = max(ans, re_cnt);
			}
			else if(nowCnt == re_cnt){
				ans = max(ans, nowCnt - 1);
			}
			else {
				ans = max(ans, nowCnt);
			}
		}
		cout << ans << "\n";
	}
}