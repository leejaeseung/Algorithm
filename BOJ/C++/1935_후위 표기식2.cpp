/*
����
���� ǥ��İ� �� �ǿ����ڿ� �����ϴ� ������ �־��� ���� ��, �� ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �ǿ������� ����(1 �� N �� 26) �� �־�����. �׸��� ��° �ٿ��� ���� ǥ����� �־�����. (���⼭ �ǿ����ڴ� A~Z�� ���빮���̸�, A���� ������� N���� ���빮�ڸ��� ���Ǹ�, ���̴� 100�� ���� �ʴ´�) �׸��� ��° �ٺ��� N+2��° �ٱ����� �� �ǿ����ڿ� �����ϴ� ���� �־�����. (3��° �ٿ��� A�� �ش��ϴ� ��, 4��° �ٿ��� B�� �ش��ϴ°� , 5��° �ٿ��� C ...�� �־�����, �׸��� �ǿ����ڿ� ���� �ϴ� ���� �����̴�)

���
��� ����� �Ҽ��� ��° �ڸ����� ����Ѵ�.

Ǯ��:
������ �̿��� ���� ǥ��� ��� �����̴�.
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