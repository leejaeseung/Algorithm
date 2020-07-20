/*
A. Acacius and String
time limit per test1 second
memory limit per test512 megabytes
inputstandard input
outputstandard output
Acacius is studying strings theory. Today he came with the following problem.

You are given a string s of length n consisting of lowercase English letters and question marks. It is possible to replace question marks with lowercase English letters in such a way that a string "abacaba" occurs as a substring in a resulting string exactly once?

Each question mark should be replaced with exactly one lowercase English letter. For example, string "a?b?c" can be transformed into strings "aabbc" and "azbzc", but can't be transformed into strings "aabc", "a?bbc" and "babbc".

Occurrence of a string t of length m in the string s of length n as a substring is a index i (1≤i≤n−m+1) such that string s[i..i+m−1] consisting of m consecutive symbols of s starting from i-th equals to string t. For example string "ababa" has two occurrences of a string "aba" as a substring with i=1 and i=3, but there are no occurrences of a string "aba" in the string "acba" as a substring.

Please help Acacius to check if it is possible to replace all question marks with lowercase English letters in such a way that a string "abacaba" occurs as a substring in a resulting string exactly once.

Input
First line of input contains an integer T (1≤T≤5000), number of test cases. T pairs of lines with test case descriptions follow.

The first line of a test case description contains a single integer n (7≤n≤50), length of a string s.

The second line of a test case description contains string s of length n consisting of lowercase English letters and question marks.

Output
For each test case output an answer for it.

In case if there is no way to replace question marks in string s with a lowercase English letters in such a way that there is exactly one occurrence of a string "abacaba" in the resulting string as a substring output "No".

Otherwise output "Yes" and in the next line output a resulting string consisting of n lowercase English letters. If there are multiple possible strings, output any.

You may print every letter in "Yes" and "No" in any case you want (so, for example, the strings yEs, yes, Yes, and YES will all be recognized as positive answer).

풀이:
? 문자를 포함한 문자열이 주어질 때, ? 문자를 다른 문자로 바꿔서 "abacaba" 란 부분 문자열이 
단 하나만 존재할 수 있게 할 수 있는지 묻는 문제였습니다.

먼저, 문자열 s의 모든 시작점 i로부터 "abacaba"를 만들 수 있는지 조사합니다.(? 문자 포함)
만들 수 없다면, 다음 번 i를 조사합니다.

만들 수 있다면, 해당 지점을 "abacaba"로 만들어보고, 다른 ? 문자는 z 등으로 바꿉니다.(절대 "abacaba"를 만들 수 없게)
그런 뒤 해당 문자열에 "abacaba"가 몇 개 나오는지 조사하고, 만약 1개라면 Yes를 출력합니다.

Yes가 출력되지 않았다면, No를 출력합니다.
*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>
#define pdd pair<double, double>
#define pic pair<int, char>
#define ll long long
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vii vector<pii>
#define IMAX 2000000001
#define LMAX 1000000000000000000
#define DMAX 0xFFFFFFFFFFFFF
int mv1[4] = { 0, 1, 0, -1 };
int mv2[4] = { 1, 0, -1, 0 };

int t, n;
string com = "abacaba";

int count(string str) {
	int ret = 0;
	
	for (int i = 0; i <= n - 7; i++)
	{
		bool flag = true;

		for (int j = 0; j < 7; j++)
		{
			if (com[j] != str[i + j]) {
				flag = false;
				break;
			}
		}
		if (flag)
			ret++;
	}
	return ret;
}

int main(void) {
	FIO;

	cin >> t;
	
	while (t--) {
		string s;
		cin >> n >> s;

		int cnt = 0;
		bool can = false;

		for (int i = 0; i <= n - 7; i++)
		{
			string temp = s;

			bool flag = true;
			for (int j = 0; j < 7; j++)
			{
				if (com[j] != temp[i + j] && temp[i + j] != '?') {
					flag = false;
					break;
				}
			}
			if (flag) {
				for (int j = 0; j < 7; j++)
				{
					temp[i + j] = com[j];
				}

				for (int j = 0; j < n; j++)
				{
					if (temp[j] == '?')
						temp[j] = 'z';
				}

				if (count(temp) == 1) {
					cout << "Yes\n" << temp << "\n";
					can = true;
					break;
				}
			}
		}

		if (!can) {
			cout << "No\n";
		}
	}
}