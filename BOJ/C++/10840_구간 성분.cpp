/*
문제
매 초마다 신호를 발생시키는 두 장치 A, B가 있다. 이 신호는 알파벳 소문자의 서열로 표현된다. A, B로부터 발생한 신호를 서열로 표시한 SA, SB의 예는 다음과 같다.

SA = [a, f, c, d, r, d, e, s, d, c, f, w, s, z, r]
SB = [g, e, d, s, r, d, d, e, m, z, r]
신호 서열의 어떤 구간에 포함된 문자의 종류와 개수가 순서에 상관없이 동일하면 이 두 ‘구간의 성분’은 같다고 한다. 아래에서 박스로 표시된 부분은 두 신호 SA, SB에서 성분이 같은 구간을 나타내고 있다.



즉 위의 예와 같이 성분이 같은 구간의 길이는 두 서열에서 반드시 같아야 한다. 그리고 같은 성분 의 구간은 하나 이상 존재할 수 있다. 우리는 두 신호 서열에 각각 존재하는 같은 성분 구간 중에 서 가장 긴 것을 찾으려고 한다.

입력
첫 두 줄에 신호 서열이 공백 없는 하나의 문자열로 각각 주어진다. 이 문자열은 영문 소문자로만 구성되어 있다. 두 입력 문자열의 크기 N, M의 범위는 1 ≤ N, M ≤ 1,500 이다.

출력
두 서열에서 같은 성분을 가진 구간 중에서 가장 긴 구간을 찾아, 그 구간의 길이를 출력해야 한다.

풀이:
라빈-카프 알고리즘을 살짝 변형하고, prefix sum을 이용해 선형 탐색으로 풀이했다.

모든 알파벳에 대한 해시 값을 다음과 같이 두었다.
a = 1, b = 2, c = 3, d = 4 ...
즉, aba = 1 + 2 + 1 = 4, baa = 2 + 1 + 1 이 되어 자리가 다르더라도 총 해시값이 같다면 문제의 조건을 충족하게 된다.
하지만 bb = 2 + 2 = 4 == aba 처럼 문자열이 다르더라도 해시값이 같을 수 있기 때문에 충돌을 처리해 주어야 한다.

먼저, 문자열1에 대해 라빈-카프 알고리즘과 같은 방식으로 길이가 m 인 부분 문자열들에 대해 모든 H 값을 구한다.
(단, 길이가 가장 길어야 하므로 m은 최대 길이부터 감소한다.)

그리고 구해진 H 값들(50000을 넘지 않는다 -> 27 * 1500) 의 시작 index를 체크 배열에 push 한다.
다음으로 문자열2에 대해 같은 방식으로 H를 구해 나가는데 문자열1에서 H가 나왔었다면 -> 충돌이므로 두 부분 문자열을 검사한다.

이 때 부분 문자열을 일일히 검사하려면 N^2 의 시간이 걸릴 수 있으므로 문자열1, 문자열2에 대해 각 자리마다의 
알파벳 수 prefix sum을 구해 놓고, 두 부분 문자열의 구간에 대해 26번 반복해주면 두 부분 문자열이 일치하는지 여부를 알아낼 수 있다.
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
#define pll pair<ll, ll>
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vii vector<pii>
#define IMAX 2000000001
#define LMAX 1000000000000000000
#define DMAX 0xFFFFFFFFFFFFF
#define MOD 100003
int mv1[4] = { 0, 0, 1, -1 };
int mv2[4] = { 1, -1, 0, 0 };
int mv_all1[8] = { 0, 1, 0, -1, -1, -1, 1, 1 };
int mv_all2[8] = { 1, 0, -1, 0 , -1, 1, -1, 1 };

int sum1[1501][26];
int sum2[1501][26];
vector<int> visit[50000];

int main(void) {
	FIO;

	string str1;
	string str2;

	cin >> str1 >> str2;

	for (int i = 1; i <= str1.size(); i++)
	{
		for (int j = 0; j < 26; j++)
		{
			if (j == str1[i - 1] - 'a') {
				sum1[i][j] = sum1[i - 1][j] + 1;
			}
			else {
				sum1[i][j] = sum1[i - 1][j];
			}
		}
	}

	for (int i = 1; i <= str2.size(); i++)
	{
		for (int j = 0; j < 26; j++)
		{
			if (j == str2[i - 1] - 'a') {
				sum2[i][j] = sum2[i - 1][j] + 1;
			}
			else {
				sum2[i][j] = sum2[i - 1][j];
			}
		}
	}
	//두 문자열에 대해 각 자리수마다 알파벳들의 개수를 구함.

	int ans = 0;

	for (int mid = min(str1.size(), str2.size()); mid > 0; mid--) {

		int H = 0;
		for (int i = 0; i < 50000; i++)
		{
			visit[i].clear();
		}

		for (int i = 0; i <= str1.size() - mid; i++)
		{
			if (i == 0) {

				for (int j = 0; j < mid; j++)
				{
					H += (str1[j] - 'a' + 1);
				}
			}
			else {
				H = H - (str1[i - 1] - 'a' + 1) + (str1[i + mid - 1] - 'a' + 1);
			}

			visit[H].push_back(i);
		}

		H = 0;

		bool find = false;

		for (int i = 0; i <= str2.size() - mid; i++)
		{
			if (i == 0) {

				for (int j = 0; j < mid; j++)
				{
					H += (str2[j] - 'a' + 1);
				}
			}
			else {
				H = H - (str2[i - 1] - 'a' + 1) + (str2[i + mid - 1] - 'a' + 1);
			}

			if (visit[H].size()) {
				//해시 충돌

				for (int j = 0; j < visit[H].size(); j++)
				{
					bool match = true;

					for (int k = 0; k < 26; k++)
					{
						//두 부분 문자열의 구간마다 알파벳의 개수가 일치하는지 확인
						if (sum1[visit[H][j] + mid][k] - sum1[visit[H][j]][k] != sum2[i + mid][k] - sum2[i][k]) {
							match = false;
							break;
						}
					}
					if (match) {

						find = true;
						break;
					}
				}
			}

			if (find)
				break;
		}

		if (find) {
			ans = mid;
			break;
		}
	}

	cout << ans;
}