/*
����
��� ������ �����Ͽ� ǥ���ϴ� ������ ������ ���� Ʈ��(Quad Tree)��� ����� �ִ�. �� ���� ��Ÿ���� 0�� ���� ���� ��Ÿ���� 1�θ� �̷���� ����(2���� �迭)���� ���� ������ ������ �� ���� ���� ����������, ���� Ʈ�������� �̸� �����Ͽ� ������ ǥ���� �� �ִ�.

�־��� ������ ��� 0���θ� �Ǿ� ������ ���� ����� "0"�� �ǰ�, ��� 1�θ� �Ǿ� ������ ���� ����� "1"�� �ȴ�. ���� 0�� 1�� ���� ������ ��ü�� �� ���� ��Ÿ������ ���ϰ�, ���� ��, ������ ��, ���� �Ʒ�, ������ �Ʒ�, �̷��� 4���� �������� ������ �����ϰ� �Ǹ�, �� 4���� ������ ������ ����� ���ʴ�� ��ȣ �ȿ� ��� ǥ���Ѵ�



�� �׸����� ������ ������ �������� �迭�� ���� ���ڷ� �־�����, �� ������ ���� Ʈ�� ������ �̿��Ͽ� �����ϸ� "(0(0011)(0(0111)01)1)"�� ǥ���ȴ�.  N ��N ũ���� ������ �־��� ��, �� ������ ������ ����� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ��� ������ ũ�⸦ ��Ÿ���� ���� N �� �־�����. N �� ������ 2�� �������� �־�����, 1��N ��64�� ������ ������. �� ��° �ٺ��ʹ� ���� N �� ���ڿ��� N �� ���´�. �� ���ڿ��� 0 �Ǵ� 1�� ���ڷ� �̷���� ������, ������ �� ������ ��Ÿ����.

���
������ ������ ����� ����Ѵ�.

Ǯ��:
��� �Լ��� ȣ���� ������ �ش� �Լ��� ���� x, y ��ǥ, size���� �Ѱ��־� �ش� ������ �˻��ϵ��� �ϰ�,
�ش� ������ 1�̳� 0���� �� �� �ִٸ� 1, 0 �� ���信 �߰��ϰ� return�Ѵ�.
4�� ������ �˻��ϱ� �� (�� ���̰�, 4�� ������ ��� �˻������� )�� ���δ�. 
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

int n;
int arr[65][65];
string ans = "";

void divide(int x, int y, int size) {
	int cnt0 = 0;
	int cnt1 = 0;

	for (int i = x; i < x + size; i++)
	{
		for (int j = y; j < y + size; j++)
		{
			if (arr[i][j] == 0)
				cnt0++;
			else
				cnt1++;
		}
	}

	if (cnt0 == 0) {
		ans += "1";
	}
	else if (cnt1 == 0) {
		ans += "0";
	}
	else {
		ans += "(";

		int mid = size / 2;

		divide(x, y, size / 2);
		divide(x, y + mid, size / 2);
		divide(x + mid, y, size / 2);
		divide(x + mid, y + mid, size / 2);
		ans += ")";
	}
}

int main(void) {
	FIO;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = str[j] - '0';
		}
	}

	divide(0, 0, n);
	cout << ans;
}