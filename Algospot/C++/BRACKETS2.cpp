/*
문제
Best White is a mathematics graduate student at T1 University. Recently, he finished writing a paper and he decided to polish it. As he started to read it from the beginning, he realized that some of the formulas have problems: some of the brackets are mismatched! Since there are so many formulas in his paper, he decided to check their validity with a computer program.

The following kinds of brackets are included in Best White’s paper.

Round brackets are opened by a ( and closed by a ).
Curly brackets are opened by a { and closed by a }.
Square brackets are opened by a [ and closed by a ].
A formula is said well-matched when the following conditions are met:

Every bracket has a corresponding pair. ( corresponds to ), [ corresponds to ], et cetera.
Every bracket pair is opened first, and closed later.
No two pairs "*cross*" each other. For example, [(]) is not well-matched.
Write a program to help Best White by checking if each of his formulas is well-matched. To make the problem easier, everything other than brackets are removed from the formulas.

입력
The first line of the input will contain the number of test cases C (1≤C≤100). Each test is given in a single line as a character string. The strings will only include characters in "[](){}" (quotes for clarity). The length of the string will not exceed 10,000.

출력
For each test case, print a single line "YES" when the formula is well-matched; print "NO" otherwise. (quotes for clarity)

풀이:
스택에 open 괄호를 넣어가며 진행한다.
close 괄호를 만나면, 스택의 top 에 맞는 짝의 open 괄호가 있다면 통과이고, 스택이 비어있거나 짝이 안 맞는다면 No이다.

마지막에 ()(){ 처럼 스택이 비어있지 않는 경우도 NO 이다.
*/
#include<iostream>
#include<memory.h>
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
#define pll pair<ll, ll>
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vii vector<pii>
#define IMAX 2000000001
#define LMAX 1000000000000000000
#define DMAX 0xFFFFFFFFFFFFF
#define MOD 20091101
int mv1[4] = { 0, 0, 1, -1 };
int mv2[4] = { 1, -1, 0, 0 };
int mv_all1[8] = { 0, 1, 0, -1, -1, -1, 1, 1 };
int mv_all2[8] = { 1, 0, -1, 0 , -1, 1, -1, 1 };

int t;

int main(void) {
	FIO;

	cin >> t;

	while (t--) {
		string str;
		cin >> str;

		stack<char> st;

		bool flag = true;

		for (int i = 0; i < str.size(); i++)
		{
			char c = str[i];

			if (c == '(' || c == '{' || c == '[') {
				st.push(c);
			}
			else {
				if (!st.empty()) {
					if (st.top() == '(' && c != ')') {
						flag = false;
						break;
					}
					else if (st.top() == '{' && c != '}') {
						flag = false;
						break;
					}
					else if (st.top() == '[' && c != ']') {
						flag = false;
						break;
					}
					st.pop();
				}
				else {
					flag = false;
					break;
				}
			}
		}
		if (!st.empty())
			flag = false;

		if (flag)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}