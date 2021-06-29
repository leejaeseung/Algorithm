/*
문제
후위 표기식과 각 피연산자에 대응하는 값들이 주어져 있을 때, 그 식을 계산하는 프로그램을 작성하시오.

입력
첫째 줄에 피연산자의 개수(1 ≤ N ≤ 26) 가 주어진다. 그리고 둘째 줄에는 후위 표기식이 주어진다. (여기서 피연산자는 A~Z의 영대문자이며, A부터 순서대로 N개의 영대문자만이 사용되며, 길이는 100을 넘지 않는다) 그리고 셋째 줄부터 N+2번째 줄까지는 각 피연산자에 대응하는 값이 주어진다. (3번째 줄에는 A에 해당하는 값, 4번째 줄에는 B에 해당하는값 , 5번째 줄에는 C ...이 주어진다, 그리고 피연산자에 대응 하는 값은 정수이다)

출력
계산 결과를 소숫점 둘째 자리까지 출력한다.

풀이:
스택을 이용한 후위 표기식 계산 문제이다.
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
int mv1[4] = { 0, 1, -1, 0 };
int mv2[4] = { 1, 0, 0, -1 };

int n;
double alpha[27];
string str;

int main() {
	FIO;

	cin >> n;
	cin >> str;

	fill(&alpha[0], &alpha[27], 0);

	stack<double> st;

	for (int i = 0; i < n; i++)
	{
		double v;
		cin >> v;
		
		alpha[i] = v;
	}

	for (int i = 0; i < str.length(); i++)
	{
		char temp = str[i];

		if (temp >= 'A' && temp <= 'Z') {
			double nowV = alpha[temp - 'A'];

			st.push(nowV);
		}
		else {
			double right = st.top(); st.pop();
			double left = st.top(); st.pop();

			switch (temp)
			{
			case '-':
				st.push(left - right);
				break;
			case '+':
				st.push(left + right);
				break;
			case '/':
				st.push(left / right);
				break;
			case '*':
				st.push(left * right);
				break;
			default:
				break;
			}
		}
	}

	cout << fixed;
	cout.precision(2);
	cout << st.top();
}