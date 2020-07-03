/*
문제
N자리 숫자가 주어졌을 때, 여기서 숫자 K개를 지워서 얻을 수 있는 가장 큰 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N과 K가 주어진다. (1 ≤ K < N ≤ 500,000)

둘째 줄에 N자리 숫자가 주어진다. 이 수는 0으로 시작하지 않는다.

출력
입력으로 주어진 숫자에서 K개를 지웠을 때 얻을 수 있는 가장 큰 수를 출력한다.

풀이:
스택을 활용한 그리디 알고리즘 문제입니다.

스택에 하나씩 숫자를 넣어가며, 스택의 top보다 큰 값을 만나면 스택의 top이 더 크거나 같아질 때까지 스택을 pop합니다.
단, pop은 최대 k번 만큼만 수행해야 합니다.
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

int n, k;
string num;
stack<int> st;

int main(void) {
	FIO;

	cin >> n >> k >> num;

	for (int i = 0; i < num.size(); i++)
	{
		int now = num[i] - '0';

		while (k > 0 && !st.empty() && st.top() < now) {
			st.pop();
			k--;
		}
		st.push(now);
	}

	while (k--) {
		st.pop();
	}

	stack<int> out;

	while (!st.empty()) {
		out.push(st.top());
		st.pop();
	}

	while (!out.empty()) {
		cout << out.top();
		out.pop();
	}
}