/*
����
���̰� N�� ������ �ִ�. ������ 0���� ũ�ų� ����, 9���� �۰ų� ���� ������ ������(+, -, ��)�� �̷���� �ִ�. ���ϱ��� ������ �켱������ ���ϱ�� ���⺸�� ���� ������, ���ϱ⸦ ���� ��� �ؾ� �Ѵ�. ������ ����� ���� ���ʿ������� ������� ����ؾ� �Ѵ�. ���� ���, 3+8��7-9��2�� ����� 41�̴�.

���Ŀ� ��ȣ�� �߰��ϸ�, ��ȣ �ȿ� ����ִ� ���� ���� ����ؾ� �Ѵ�. ���� ���, 3+8��7-9��2�� ��ȣ�� (3+8)��7-(9��2)�� ���� �߰�������, ���� ����� 59�� �ȴ�. ��ø�� ��ȣ�� ����� �� �ְ�, ��ȣ �ȿ� ���� ���� �����ڰ� ��� �־ �ȴ�. ��, 3+((8��7)-9)��2, 3+((8��7)-(9��2)), (3+8)��(7-9��2) ��� �ùٸ� ���̰�, ����� 97, 41, -121�̴�.

������ �־����� ��, ��ȣ�� ������ �߰��� ���� �� �ִ� ���� ����� �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�. �߰��ϴ� ��ȣ ������ ������ ������, �߰����� �ʾƵ� �ȴ�.

�Է�
ù° �ٿ� ������ ���� N(1 �� N �� 19)�� �־�����. ��° �ٿ��� ������ �־�����. ���Ŀ� ���Ե� ������ ��� 0���� ũ�ų� ����, 9���� �۰ų� ����. ���ڿ��� ������ �����ϰ�, �����ڿ� ������ �����ư��鼭 ���´�. �����ڴ� +, -, * �� �ϳ��̴�. ���⼭ *�� ���ϱ� ������ ��Ÿ���� �� �����̴�. �׻� �ùٸ� ���ĸ� �־����� ������, N�� Ȧ���̴�.

���
ù° �ٿ� ��ȣ�� ������ �߰��ؼ� ���� �� �ִ� ����� �ִ��� ����Ѵ�. ������ 231���� �۰�, -231���� ũ��.

Ǯ��:
dp�� Ǯ���Ϸ��� ���� �ð����⵵�� ����� ���� 10! * 20 = 7õ�� ������ ������ �� ���� Brute Force�� Ǯ���ߴ�.

���ڸ� ���� ���Ϳ� �����ڸ� ���� ���͸� ���� �ΰ� Brute Force�� �����Ѵ�.

1 + 3 + 5 + 7

���� ���� ���� �ִٸ�, 
���� ���Ϳ� 1 3 5 7 , ������ ���Ϳ� + + + �� ó���� �� �ְ� �ȴ�.

���ӵ� �� ���� ����, �߰��� �����ڸ� ���� ����� ��, ���͸� �����Ͽ� �Ѱ��ִ� ������ �����Ѵ�.

1. 4 5 7 , + +
2. 1 8 7 , + +
3. 1 3 12 , + +

�� �۾��� ���� ������ ũ�Ⱑ 1�� �� ������ �ϰ�, max���� �����Ѵ�.

dp Ǯ��:

https://www.acmicpc.net/problem/11066 ������ ����� ������� Ǯ���Ѵ�.

maxdp[i][j] = i ~ j ������ �ִ�
mindp[i][j] = i ~ j ������ �ּڰ�

�� �� �迭�� �̿��Ͽ�, i ~ j �� ���� �������� 0 ~ n �������� ���ذ��� �ȴ�.

�� ��, ������ ���� 4���� ��쿡 ���� ��� ������ �� �־�� �Ѵ�.(����(�ּ�) * ����(�ּ�) -> �ִ��� ���� �ֱ� ����)

�ִ�, �ִ�
�ִ�, �ּ�
�ּ�, �ִ�
�ּ�, �ּ�
*/
//Brute Force Ǯ��
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
int mv_all1[8] = { 0, 1, 0, -1, -1, -1, 1, 1 };
int mv_all2[8] = { 1, 0, -1, 0 , -1, 1, -1, 1 };

int n;
string str;
ll maxV = -LMAX;

ll calculate(char op, ll n1, ll n2) {
	if (op == '+')
		return n1 + n2;
	else if (op == '-')
		return n1 - n2;
	else
		return n1 * n2;
}

void recul(vector<ll> num, vector<char> oper) {

	if (num.size() == 1) {
		maxV = max(maxV, num[0]);
		return;
	}

	for (int i = 0; i < oper.size(); i++)
	{
		ll res = calculate(oper[i], num[i], num[i + 1]);

		vector<ll> nextNum;
		vector<char> nextOper;

		for (int j = 0; j < i; j++)
		{
			nextNum.push_back(num[j]);
		}

		nextNum.push_back(res);

		for (int j = i + 2; j < num.size(); j++)
		{
			nextNum.push_back(num[j]);
		}

		for (int j = 0; j < oper.size(); j++)
		{
			if (i != j)
				nextOper.push_back(oper[j]);
		}

		recul(nextNum, nextOper);
	}
}

int main(void) {
	FIO;

	cin >> n >> str;

	vector<char> oper;
	vector<ll> num;

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] >= '0' && str[i] <= '9') {
			num.push_back(str[i] - '0');
		}
		else {
			oper.push_back(str[i]);
		}
	}

	recul(num, oper);

	cout << maxV;
}


//dp Ǯ��
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
int mv_all1[8] = { 0, 1, 0, -1, -1, -1, 1, 1 };
int mv_all2[8] = { 1, 0, -1, 0 , -1, 1, -1, 1 };

int n;
string str;
ll maxdp[19][19];
ll mindp[19][19];

ll calculate(char op, ll n1, ll n2) {
	if (op == '+')
		return n1 + n2;
	else if (op == '-')
		return n1 - n2;
	else
		return n1 * n2;
}

int main(void) {
	FIO;

	cin >> n >> str;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			maxdp[i][j] = -LMAX;
			mindp[i][j] = LMAX;
			if (i == j && i % 2 == 0) {
				maxdp[i][j] = str[i] - '0';
				mindp[i][j] = str[i] - '0';
			}
		}
	}

	for (int range = 2; range < n; range += 2)
	{
		for (int s = 0; s + range < n; s += 2)
		{
			int e = s + range;

			ll maxV = -LMAX;
			ll minV = LMAX;

			if (range == 2) {
				maxV = calculate(str[s + 1], str[s] - '0', str[e] - '0');
				minV = calculate(str[s + 1], str[s] - '0', str[e] - '0');
			}
			else {
				for (int mid = s + 1; mid < e; mid += 2)
				{
					maxV = max(maxV, calculate(str[mid], maxdp[s][mid - 1], maxdp[mid + 1][e]));
					maxV = max(maxV, calculate(str[mid], mindp[s][mid - 1], mindp[mid + 1][e]));
					maxV = max(maxV, calculate(str[mid], mindp[s][mid - 1], maxdp[mid + 1][e]));
					maxV = max(maxV, calculate(str[mid], maxdp[s][mid - 1], mindp[mid + 1][e]));

					minV = min(minV, calculate(str[mid], maxdp[s][mid - 1], maxdp[mid + 1][e]));
					minV = min(minV, calculate(str[mid], mindp[s][mid - 1], mindp[mid + 1][e]));
					minV = min(minV, calculate(str[mid], mindp[s][mid - 1], maxdp[mid + 1][e]));
					minV = min(minV, calculate(str[mid], maxdp[s][mid - 1], mindp[mid + 1][e]));
				}
			}

			maxdp[s][e] = maxV;
			mindp[s][e] = minV;
		}
	}

	cout << max(mindp[0][n - 1], maxdp[0][n - 1]);
}