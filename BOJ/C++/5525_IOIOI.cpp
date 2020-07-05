/*
문제
N+1개의 I와 N개의 O로 이루어져 있으면, I와 O이 교대로 나오는 문자열을 PN이라고 한다.

P1 IOI
P2 IOIOI
P3 IOIOIOI
PN IOIOI...OI (O가 N개)
I와 O로만 이루어진 문자열 S와 정수 N이 주어졌을 때, S안에 PN이 몇 군데 포함되어 있는지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N이 주어진다. 둘째 줄에는 S의 길이 M이 주어지며, 셋째 줄에 S가 주어진다. (1 ≤ N ≤ 1,000,000, 2N+1 ≤ M ≤ 1,000,000)

출력
S에 PN이 몇 군데 포함되어 있는지 출력한다.

풀이:
kmp 알고리즘 문제였습니다.
https://bowbowbow.tistory.com/6#comment5168448
위 블로그를 참고했습니다.
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
		//가장 최근에 prefix == suffix 였던 곳으로 j를 돌려 놓음.
		while (j > 0 && pattern[i] != pattern[j])
			j = pi[j - 1];
		if (pattern[i] == pattern[j])
			pi[i] = ++j;
	}

	j = 0;
	int ans = 0;

	for (int i = 0; i < origin.size(); i++)
	{
		//가장 왼쪽의 겹치는 부분으로 돌아감
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