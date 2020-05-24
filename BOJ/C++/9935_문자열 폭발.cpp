/*
문제
상근이는 문자열에 폭발 문자열을 심어 놓았다. 폭발 문자열이 폭발하면 그 문자는 문자열에서 사라지며, 남은 문자열은 합쳐지게 된다.

폭발은 다음과 같은 과정으로 진행된다.

문자열이 폭발 문자열을 포함하고 있는 경우에, 모든 폭발 문자열이 폭발하게 된다. 남은 문자열을 순서대로 이어 붙여 새로운 문자열을 만든다.
새로 생긴 문자열에 폭발 문자열이 포함되어 있을 수도 있다.
폭발은 폭발 문자열이 문자열에 없을 때까지 계속된다.
상근이는 모든 폭발이 끝난 후에 어떤 문자열이 남는지 구해보려고 한다. 남아있는 문자가 없는 경우가 있다. 이때는 "FRULA"를 출력한다.

폭발 문자열은 같은 문자를 두 개 이상 포함하지 않는다.

입력
첫째 줄에 문자열이 주어진다. 문자열의 길이는 1보다 크거나 같고, 1,000,000보다 작거나 같다.

둘째 줄에 폭발 문자열이 주어진다. 길이는 1보다 크거나 같고, 36보다 작거나 같다.

두 문자열은 모두 알파벳 소문자와 대문자, 숫자 0, 1, ..., 9로만 이루어져 있다.

출력
첫째 줄에 모든 폭발이 끝난 후 남은 문자열을 출력한다.

풀이:
문자열을 하나씩 읽어가면서 스택에 넣습니다.
그리고 매번 폭발 문자열의 길이만큼 스택에서 꺼내 비교하고, 폭발 문자열과 다르다면 다시 스택에 넣어줍니다.
(스택 두개 이용)
같다면, 꺼낸 문자들은 버려줍니다.
마지막에 스택에 남아있는 문자들을 순서대로 출력합니다.
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
#define vii vector<pii>
#define IMAX 2000000001
#define LMAX 1000000000000000000
#define DMAX 0xFFFFFFFFFFFFF
int mv1[4] = { 0, 1, 0, -1 };
int mv2[4] = { 1, 0, -1, 0 };

string str, boom;
stack<char> st;
stack<char> temp;

int main(void) {
	FIO;

	cin >> str >> boom;

	if (str.size() < boom.size())
		cout << str;
	else {
		for (int i = 0; i < boom.size() - 1; i++)
		{
			st.push(str[i]);
		}

		for (int i = boom.size() - 1; i < str.size(); i++)
		{
			st.push(str[i]);

			for (int i = boom.size() - 1; i >= 0 ; i--)
			{
				if (!st.empty()) {
					char now = st.top();	st.pop();
					temp.push(now);

					if (now != boom[i]) {
						//폭발 문자열이 아니므로 다시 스택에 넣음.
						while (!temp.empty()) {
							st.push(temp.top());	temp.pop();
						}
						break;
					}
				}
			}
			while (!temp.empty())
				temp.pop();
			//폭발 문자열을 버림.
			
		}
		if (st.empty())
			cout << "FRULA";
		else {
			//역순으로 저장되어 있으므로 다시 역순으로 바꿔줌.
			while (!st.empty()) {
				temp.push(st.top());	st.pop();
			}
			while (!temp.empty()) {
				cout << temp.top();
				temp.pop();
			}
		}

	}

}