/*
문제
상근이는 꿈에서 길이가 L인 문자열을 외웠다.

꿈에서 깬 상근이는 이 문자열을 종이에 적었다. 종이를 적던 중에 어떤 문자열은 두 번 이상 등장하는 것 같은 느낌을 받았다.

문자열이 주어졌을 때, 두 번 이상 등장한 부분 문자열 중 가장 길이가 긴 것을 찾는 프로그램을 작성하시오. (부분문자열은 겹쳐서 등장할 수도 있다)

입력
첫째 줄에 L이 주어진다. (1 ≤ L ≤ 200,000) 다음 줄에는 길이가 L이면서 알파벳 소문자로 이루어진 문자열이 주어진다.

출력
첫째 줄에 두 번 이상 등장하는 부분 문자열 중 길이가 가장 긴 것의 길이를 출력한다. 만약 그러한 문자열이 없을 때는 0을 출력한다.

풀이:
라빈-카프와 이분 탐색을 이용한 문제이다.
https://m.blog.naver.com/PostView.nhn?blogId=kks227&logNo=220927272165&proxyReferer=https:%2F%2Fwww.google.com%2F
위 블로그를 참고해 풀이함.

K 길이의 부분 문자열이 2개 이상 있다면 당연히 K 이하의 부분 문자열도 2개 이상 있다.
따라서 이분 탐색을 적용할 수 있다.
(K 길이의 부분 문자열이 2개 이상 있으면 -> K 보다 큰 부분 문자열들에 대해 조사)

K 의 길이에 대해 이분 탐색을 진행하고, 문자열 S 에 대해 길이가 K 인 모든 부분 문자열의 해시값을
라빈-카프 알고리즘을 사용해 구한다.

모듈러 연산 시에 뺄셈 연산을 고려해 양수로 바꿔줘야 한다.
나머지 값이 같더라도 다른 문자열일 수 있으므로(해시 충돌) 겹치는 문자열들에 대해
정말 같은 문자열인지 일일히 확인해주면 된다.
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
int mv1[4] = { 0, 0, 1, -1 };
int mv2[4] = { 1, -1, 0, 0 };
int mv_all1[8] = { 0, 1, 0, -1, -1, -1, 1, 1 };
int mv_all2[8] = { 1, 0, -1, 0 , -1, 1, -1, 1 };

const int MOD = 100003;
vector<int> visit[MOD];

int mod(ll n) {
	if (n >= 0)	return n % MOD;
	else
		return ((-n / MOD + 1) * MOD + n) % MOD;
	//음수일 경우의 모듈러 연산
}

int main(void) {
	FIO;

	int leng, ans = 0;
	string str;
	cin >> leng >> str;

	int s = 0;
	int e = leng;

	while (s < e) {

		int m = (s + e) / 2;
		ll H = 0;
		ll mul = 1;
		bool flag = false;
		for (int i = 0; i < MOD; i++)
		{
			visit[i].clear();
		}

		for (int i = 0; i <= leng - m; i++)
		{
			if (i == 0) {

				for (int j = m - 1; j >= 0; j--)
				{
					H = mod(H + (str[j] - 'a') * mul);
					if (j > 0)
						mul = mod(mul * 2);
				}
			}
			else {
				H = mod(2 * (H - (str[i - 1] - 'a') * mul) + (str[i + m - 1] - 'a'));
			}

			if (!visit[H].empty()) {

			for (int start = 0; start < visit[H].size(); start++)
				{
				bool match = true;
					for (int j = 0; j < m; j++)
					{
						if (str[visit[H][start] + j] != str[i + j]) {
							match = false;
							break;
						}
					}
					if (match) {
						flag = true;
						break;
					}
				}
			}
			if (flag)
				break;
			else
				visit[H].push_back(i);
			//충돌 발생x , 해시값의 시작 위치 저장
		}

		if (flag) {
			ans = m;
			s = m + 1;
		}
		else {
			e = m;
		}
	}

	cout << ans;
}