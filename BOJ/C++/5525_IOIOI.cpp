/*
����
N+1���� I�� N���� O�� �̷���� ������, I�� O�� ����� ������ ���ڿ��� PN�̶�� �Ѵ�.

P1 IOI
P2 IOIOI
P3 IOIOIOI
PN IOIOI...OI (O�� N��)
I�� O�θ� �̷���� ���ڿ� S�� ���� N�� �־����� ��, S�ȿ� PN�� �� ���� ���ԵǾ� �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� N�� �־�����. ��° �ٿ��� S�� ���� M�� �־�����, ��° �ٿ� S�� �־�����. (1 �� N �� 1,000,000, 2N+1 �� M �� 1,000,000)

���
S�� PN�� �� ���� ���ԵǾ� �ִ��� ����Ѵ�.

Ǯ��:
kmp �˰��� ���������ϴ�.
https://bowbowbow.tistory.com/6#comment5168448
�� ��α׸� �����߽��ϴ�.
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

int n, m;
int pi[1000001];
string origin, pattern = "";


int main(void) {
	FIO;

	cin >> n >> m >> origin;

	for (int i = 0; i < n; i++)
	{
		pattern += "IO";
	}
	pattern += "I";

	int j = 0;

	for (int i = 1; i < pattern.size(); i++)
	{	
		//���� �ֱٿ� prefix == suffix ���� ������ j�� ���� ����.
		while (j > 0 && pattern[i] != pattern[j])
			j = pi[j - 1];
		if (pattern[i] == pattern[j])
			pi[i] = ++j;
	}

	j = 0;
	int ans = 0;

	for (int i = 0; i < origin.size(); i++)
	{
		//���� ������ ��ġ�� �κ����� ���ư�
		while (j > 0 && origin[i] != pattern[j])
			j = pi[j - 1];

		if (origin[i] == pattern[j]) {
			j++;

			if (j == pattern.size()) {
				ans++;
				j = pi[j - 1];
			}
		}
	}

	cout << ans;
}