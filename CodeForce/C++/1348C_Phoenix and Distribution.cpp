/*
C. Phoenix and Distribution
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Phoenix has a string s consisting of lowercase Latin letters. He wants to distribute all the letters of his string into k non-empty strings a1,a2,…,ak such that every letter of s goes to exactly one of the strings ai. The strings ai do not need to be substrings of s. Phoenix can distribute letters of s and rearrange the letters within each string ai however he wants.

For example, if s= baba and k=2, Phoenix may distribute the letters of his string in many ways, such as:

ba and ba
a and abb
ab and ab
aa and bb
But these ways are invalid:

baa and ba
b and ba
baba and empty string (ai should be non-empty)
Phoenix wants to distribute the letters of his string s into k strings a1,a2,…,ak to minimize the lexicographically maximum string among them, i. e. minimize max(a1,a2,…,ak). Help him find the optimal distribution and print the minimal possible value of max(a1,a2,…,ak).

String x is lexicographically less than string y if either x is a prefix of y and x≠y, or there exists an index i (1≤i≤min(|x|,|y|)) such that xi < yi and for every j (1≤j<i) xj=yj. Here |x| denotes the length of the string x.

Input
The input consists of multiple test cases. The first line contains an integer t (1≤t≤1000) — the number of test cases. Each test case consists of two lines.

The first line of each test case consists of two integers n and k (1≤k≤n≤105) — the length of string s and the number of non-empty strings, into which Phoenix wants to distribute letters of s, respectively.

The second line of each test case contains a string s of length n consisting only of lowercase Latin letters.

It is guaranteed that the sum of n over all test cases is ≤105.

Output
Print t answers — one per test case. The i-th answer should be the minimal possible value of max(a1,a2,…,ak) in the i-th test case.

풀이:
먼저, 문자열 s 를 사전순서로 정렬합니다.
문자열을 k개로 나눠야 하므로 정렬한 문자열 s 에서 맨 처음 문자와 K번째의 문자가 같지 않다면
K번째 문자 하나만을 택하는게 최선의 선택입니다. -> 그 앞에 오는 문자들을 K번째 문자를 제외하고 모두 합칠 수 있습니다.

맨 처음 문자와 K번째 문자가 같다면, 첫번쨰~K번째까지 모두 같은 문자라는 뜻입니다.
따라서 모든 문자열에 첫번째 문자를 붙일 수 있습니다.
그리고 K + 1번째 문자와 마지막 문자가 다르다면 K + 1번째 문자부터 마지막 문자까지 더해주고,
아니라면 모든 문자가 같으므로 짝수 길이의 해당 문자가 정답이 됩니다.(가장 긴)
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

		string s;
		cin >> s;

		sort(s.begin(), s.end());

		if (s[0] != s[K - 1]) {
			cout << s[K - 1];
		}
		else {
			cout << s[0];

			if (s[K] != s[N - 1]) {
				for (int i = K; i < N; i++)
				{
					cout << s[i];
				}
			}
			else {
				for (int i = 0; i < (N - 1) / K; i++)
				{
					cout << s[N - 1];
				}
			}
		}
		cout << "\n";
	}
}