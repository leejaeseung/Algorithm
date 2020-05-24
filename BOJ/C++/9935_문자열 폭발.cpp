/*
����
����̴� ���ڿ��� ���� ���ڿ��� �ɾ� ���Ҵ�. ���� ���ڿ��� �����ϸ� �� ���ڴ� ���ڿ����� �������, ���� ���ڿ��� �������� �ȴ�.

������ ������ ���� �������� ����ȴ�.

���ڿ��� ���� ���ڿ��� �����ϰ� �ִ� ��쿡, ��� ���� ���ڿ��� �����ϰ� �ȴ�. ���� ���ڿ��� ������� �̾� �ٿ� ���ο� ���ڿ��� �����.
���� ���� ���ڿ��� ���� ���ڿ��� ���ԵǾ� ���� ���� �ִ�.
������ ���� ���ڿ��� ���ڿ��� ���� ������ ��ӵȴ�.
����̴� ��� ������ ���� �Ŀ� � ���ڿ��� ������ ���غ����� �Ѵ�. �����ִ� ���ڰ� ���� ��찡 �ִ�. �̶��� "FRULA"�� ����Ѵ�.

���� ���ڿ��� ���� ���ڸ� �� �� �̻� �������� �ʴ´�.

�Է�
ù° �ٿ� ���ڿ��� �־�����. ���ڿ��� ���̴� 1���� ũ�ų� ����, 1,000,000���� �۰ų� ����.

��° �ٿ� ���� ���ڿ��� �־�����. ���̴� 1���� ũ�ų� ����, 36���� �۰ų� ����.

�� ���ڿ��� ��� ���ĺ� �ҹ��ڿ� �빮��, ���� 0, 1, ..., 9�θ� �̷���� �ִ�.

���
ù° �ٿ� ��� ������ ���� �� ���� ���ڿ��� ����Ѵ�.

Ǯ��:
���ڿ��� �ϳ��� �о�鼭 ���ÿ� �ֽ��ϴ�.
�׸��� �Ź� ���� ���ڿ��� ���̸�ŭ ���ÿ��� ���� ���ϰ�, ���� ���ڿ��� �ٸ��ٸ� �ٽ� ���ÿ� �־��ݴϴ�.
(���� �ΰ� �̿�)
���ٸ�, ���� ���ڵ��� �����ݴϴ�.
�������� ���ÿ� �����ִ� ���ڵ��� ������� ����մϴ�.
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
						//���� ���ڿ��� �ƴϹǷ� �ٽ� ���ÿ� ����.
						while (!temp.empty()) {
							st.push(temp.top());	temp.pop();
						}
						break;
					}
				}
			}
			while (!temp.empty())
				temp.pop();
			//���� ���ڿ��� ����.
			
		}
		if (st.empty())
			cout << "FRULA";
		else {
			//�������� ����Ǿ� �����Ƿ� �ٽ� �������� �ٲ���.
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