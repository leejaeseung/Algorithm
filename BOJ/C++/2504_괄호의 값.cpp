/*
문제
4개의 기호 ‘(’, ‘)’, ‘[’, ‘]’를 이용해서 만들어지는 괄호열 중에서 올바른 괄호열이란 다음과 같이 정의된다.

한 쌍의 괄호로만 이루어진 ‘()’와 ‘[]’는 올바른 괄호열이다.
만일 X가 올바른 괄호열이면 ‘(X)’이나 ‘[X]’도 모두 올바른 괄호열이 된다.
X와 Y 모두 올바른 괄호열이라면 이들을 결합한 XY도 올바른 괄호열이 된다.
예를 들어 ‘(()[[]])’나 ‘(())[][]’ 는 올바른 괄호열이지만 ‘([)]’ 나 ‘(()()[]’ 은 모두 올바른 괄호열이 아니다. 우리는 어떤 올바른 괄호열 X에 대하여 그 괄호열의 값(괄호값)을 아래와 같이 정의하고 값(X)로 표시한다.

‘()’ 인 괄호열의 값은 2이다.
‘[]’ 인 괄호열의 값은 3이다.
‘(X)’ 의 괄호값은 2×값(X) 으로 계산된다.
‘[X]’ 의 괄호값은 3×값(X) 으로 계산된다.
올바른 괄호열 X와 Y가 결합된 XY의 괄호값은 값(XY)= 값(X)+값(Y) 로 계산된다.
예를 들어 ‘(()[[]])([])’ 의 괄호값을 구해보자. ‘()[[]]’ 의 괄호값이 2 + 3×3=11 이므로 ‘(()[[]])’의 괄호값은 2×11=22 이다. 그리고 ‘([])’의 값은 2×3=6 이므로 전체 괄호열의 값은 22 + 6 = 28 이다.

여러분이 풀어야 할 문제는 주어진 괄호열을 읽고 그 괄호값을 앞에서 정의한대로 계산하여 출력하는 것이다.

입력
첫째 줄에 괄호열을 나타내는 문자열(스트링)이 주어진다. 단 그 길이는 1 이상, 30 이하이다.

출력
첫째 줄에 그 괄호열의 값을 나타내는 정수를 출력한다. 만일 입력이 올바르지 못한 괄호열이면 반드시 0을 출력해야 한다.

풀이:
닫히는 괄호를 만났을 때, 현재까지 계산된 닫힌 괄호 안쪽의 값들을 모두 더해준 뒤, *2 혹은 *3 을 해주면 된다.
단, 계산된 값이 없는 경우 1에 *2 혹은 *3 을 한다.
*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<regex>
#include<set>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define pic pair<int, char>
#define ll long long
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vii vector<pii>
#define IMAX 2147483647
#define LMAX 1000000000000500000
#define DMAX 0xFFFFFFFFFFFFF
int mv1[4] = { 0, 1, -1, 0 };
int mv2[4] = { 1, 0, 0, -1 };

stack<string> st;

int getSum() {
	int ret = 0;

	while (!st.empty() && st.top()[0] != '(' && st.top()[0] != '[') {
		ret += stoi(st.top());
		st.pop();
	}

	if (ret == 0)
		ret = 1;

	return ret;
}

void out() {
	cout << '0';
	exit(0);
}

int main() {
	FIO;

	string str;

	cin >> str;

	int cnt1_op = 0;
	int cnt2_op = 0;
	int cnt1_cl = 0;
	int cnt2_cl = 0;

	for (int i = 0; i < str.length(); i++)
	{
		char now = str[i];

		if (now == '(') {
			st.push(string(1, now));
			cnt1_op++;
		}
		else if (now == ')') {
			cnt1_cl++;
			if (cnt1_op < cnt1_cl)
				out();

			int sum = getSum();
			if (st.top()[0] == '[' || st.empty())
				out();

			st.pop();

			st.push(to_string(sum * 2));
		}
		else if (now == '[') {
			st.push(string(1, now));
			cnt2_op++;
		}
		else {
			cnt2_cl++;
			if (cnt2_op < cnt2_cl)
				out();

			int sum = getSum();
			if (st.top()[0] == '(' || st.empty())
				out();
			
			st.pop();

			st.push(to_string(sum * 3));
		}
	}

	int res = getSum();

	if (!st.empty() && (st.top()[0] == '(' || st.top()[0] == '[' || st.top()[0] == ')' || st.top()[0] == ']'))
		out();

	cout << res;
}