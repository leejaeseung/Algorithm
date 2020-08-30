/*
����
�� N���� ���ڿ��� �̷���� ���� S�� �־�����.

�Է����� �־����� M���� ���ڿ� �߿��� ���� S�� ���ԵǾ� �ִ� ���� �� �� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ���ڿ��� ���� N�� M (1 �� N �� 10,000, 1 �� M �� 10,000)�� �־�����.

���� N���� �ٿ��� ���� S�� ���ԵǾ� �ִ� ���ڿ����� �־�����.

���� M���� �ٿ��� �˻��ؾ� �ϴ� ���ڿ����� �־�����.

�Է����� �־����� ���ڿ��� ���ĺ� �ҹ��ڷθ� �̷���� ������, ���̴� 500�� ���� �ʴ´�. ���� S�� ���� ���ڿ��� ���� �� �־����� ���� ����.

���
ù° �ٿ� M���� ���ڿ� �߿� �� �� ���� ���� S�� ���ԵǾ� �ִ��� ����Ѵ�.

Ǯ��:
�ɽ�Ǯ��
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
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vii vector<pii>
#define IMAX 2000000001
#define LMAX 1000000000000000000
#define DMAX 0xFFFFFFFFFFFFF
#define MOD 100007
int mv1[4] = { 0, 0, 1, -1 };
int mv2[4] = { 1, -1, 0, 0 };
int mv_all1[8] = { 0, 1, 0, -1, -1, -1, 1, 1 };
int mv_all2[8] = { 1, 0, -1, 0 , -1, 1, -1, 1 };

int n, m;
set<string> s;

int main(void) {
	FIO;

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;

		s.insert(str);
	}

	int ans = 0;

	for (int i = 0; i < m; i++)
	{
		string str;
		cin >> str;

		if (s.find(str) != s.end())
			ans++;
	}

	cout << ans;
}
