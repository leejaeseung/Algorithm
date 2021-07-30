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