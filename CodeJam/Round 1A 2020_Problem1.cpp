/*
Problem
Many terminals use asterisks (*) to signify "any string", including the empty string. For example, when listing files matching BASH*, a terminal may list BASH, BASHER and BASHFUL. For *FUL, it may list BEAUTIFUL, AWFUL and BASHFUL. When listing B*L, BASHFUL, BEAUTIFUL and BULL may be listed.

In this problem, formally, a pattern is a string consisting of only uppercase English letters and asterisks (*), and a name is a string consisting of only uppercase English letters. A pattern p matches a name m if there is a way of replacing every asterisk in p with a (possibly empty) string to obtain m. Notice that each asterisk may be replaced by a different string.

Given N patterns, can you find a single name of at most 104 letters that matches all those patterns at once, or report that it cannot be done?

Input
The first line of the input gives the number of test cases, T. T test cases follow. Each test case starts with a line with a single integer N: the number of patterns to simultaneously match. Then, N lines follow, each one containing a single string Pi representing the i-th pattern.

Output
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is any name containing at most 104 letters such that each Pi matches y according to the definition above, or * (i.e., just an asterisk) if there is no such name.

Limits
Time limit: 20 seconds per test set.
Memory limit: 1GB.
1 ¡Â T ¡Â 100.
2 ¡Â N ¡Â 50.
2 ¡Â length of Pi ¡Â 100, for all i.
Each character of Pi is either an uppercase English letter or an asterisk (*), for all i.
At least one character of Pi is an uppercase English letter, for all i.

Test set 1 (Visible Verdict)
Exactly one character of Pi is an asterisk (*), for all i.
The leftmost character of Pi is the only asterisk (*), for all i.

Test set 2 (Visible Verdict)
Exactly one character of Pi is an asterisk (*), for all i.

Test set 3 (Visible Verdict)
At least one character of Pi is an asterisk (*), for all i.

Sample

Input

Output

2
5
*CONUTS
*COCONUTS
*OCONUTS
*CONUTS
*S
2
*XZ
*XYZ


Case #1: COCONUTS
Case #2: *


In Sample Case #1, there are other possible answers, including COCOCONUTS and ILIKECOCONUTS. Neither COCONUTSAREGREAT nor COCOANUTS would be acceptable. Notice that the same pattern may appear more than once within a test case.

In Sample Case #2, there is no acceptable name, so the answer is *.

The following cases could not appear in Test Set 1, but could appear in Test Set 2 or Test Set 3:

  4
  H*O
  HELLO*
  *HELLO
  HE*
HELLO and HELLOGOODBYEHELLO are examples of acceptable answers. OTHELLO and HELLOO would not be acceptable.

  2
  CO*DE
  J*AM
There is no name that matches both patterns, so the answer would be *.

  2
  CODE*
  *JAM
CODEJAM is one example of an acceptable answer.

The following cases could not appear in Test Set 1 or Test Set 2, but could appear in Test Set 3:

  2
  A*C*E
  *B*D*
ABCDE and ABUNDANCE are among the possible acceptable answers, but BOLDFACE is not.

  2
  A*C*E
  *B*D
There is no name that matches both patterns, so the answer would be *.

  2
  **Q**
  *A*
QUAIL and AQ are among the possible acceptable answers here.
*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<string.h>
#include<vector>
#include<string.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>
#define pll pair<long long, long long>

int T, N;
char fix[20001];

int main(void) {
	FIO;

	cin >> T;
	int cnt = 1;
	while (T--) {
		cin >> N;

		vector<string> temp;
		bool flag = true;
		string ans = "";

		memset(fix, NULL, sizeof(fix));

		for (size_t k = 0; k < N; k++)
		{
			
			string str;
			cin >> str;

			int i = 0, j = str.size() - 1;

			if (str[0] == '*' && str[str.size() - 1] == '*') {
				str.erase(remove(str.begin(), str.end(), '*'), str.end());
				temp.push_back(str);
				continue;
			}
			if (str[0] != '*') {
				int f_cnt = 0;

				for (i = 0; str[i] != '*'; i++)
				{
					if (fix[f_cnt] == NULL) {
						fix[f_cnt++] = str[i];
						continue;
					}

					if (fix[f_cnt] != str[i]) {
						flag = false;
						break;
					}
					else {
						fix[f_cnt++] = str[i];
					}
				}
			}
			if(str[str.size() - 1] != '*'){
				int f_cnt = 20000;

				for (j = str.size() - 1; str[j] != '*'; j--)
				{
					if (fix[f_cnt] == NULL) {
						fix[f_cnt--] = str[j];
						continue;
					}

					if (fix[f_cnt] != str[j]) {
						flag = false;
						break;
					}
					else {
						fix[f_cnt--] = str[j];
					}
				}
			}
			string t;
			for (int l = i; l <= j ; l++)
			{
				if (str[l] == '*')	continue;
				t += str[l];
			}
			temp.push_back(t);
		}
		if (!flag)
			cout << "Case #" << cnt++ << ": " << "*\n";
		else {
			string front = "";
			for (int i = 0; fix[i] != NULL; i++)
			{
				front += fix[i];
			}
			string back = "";
			for (int i = 20000; fix[i] != NULL; i--)
			{
				back += fix[i];
			}
			reverse(back.begin(), back.end());

			ans += front;

			for (int i = 0; i < temp.size() ; i++)
			{
				ans += temp[i];
			}
			ans += back;

			cout << "Case #" << cnt++ << ": " << ans << "\n";
		}

	}
}