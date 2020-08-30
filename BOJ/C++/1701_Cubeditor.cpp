/*
문제
Cubelover는 프로그래밍 언어 Whitespace의 코딩을 도와주는 언어인 Cubelang을 만들었다. Cubelang을 이용해 코딩을 하다보니, 점점 이 언어에 맞는 새로운 에디터가 필요하게 되었다. 오랜 시간 고생한 끝에 새로운 에디터를 만들게 되었고, 그 에디터의 이름은 Cubeditor이다.

텍스트 에디터는 찾기 기능을 지원한다. 대부분의 에디터는 찾으려고 하는 문자열이 단 한 번만 나와도 찾는다. Cubelover는 이 기능은 Cubelang에 부적합하다고 생각했다. Cubelang에서 필요한 기능은 어떤 문자열 내에서 부분 문자열이 두 번 이상 나오는 문자열을 찾는 기능이다. 이때, 두 부분 문자열은 겹쳐도 된다.

예를 들어, abcdabc에서 abc는 두 번 나오기 때문에 검색이 가능하지만, abcd는 한 번 나오기 때문에 검색이 되지를 않는다.

이렇게 어떤 문자열에서 두 번 이상 나오는 부분 문자열은 매우 많을 수도 있다. 이러한 부분 문자열 중에서 가장 길이가 긴 것을 구하는 프로그램을 작성하시오.

예를 들어, abcabcabc에서 abc는 세 번 나오기 때문에 검색할 수 있다. 또, abcabc도 두 번 나오기 때문에 검색할 수 있다. 하지만, abcabca는 한 번 나오기 때문에 검색할 수 없다. 따라서, 두 번 이상 나오는 부분 문자열 중에서 가장 긴 것은 abcabc이기 때문에, 이 문자열이 답이 된다.

입력
첫째 줄에 문자열이 주어진다. 문자열의 길이는 최대 5,000이고, 문자열은 모두 소문자로만 이루어져 있다.

출력
입력에서 주어진 문자열의 두 번이상 나오는 부분문자열 중에서 가장 긴 길이를 출력한다.

풀이:
https://www.acmicpc.net/problem/3033
위 문제에서 N 만 작은 문제이다.
KMP, 라빈-카프 모두 가능하다.
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
int mod(ll num) {
	if (num >= 0)	return num % MOD;
	else
		return (num % MOD + MOD) % MOD;
}

vector<int> pos[MOD];

int main(void) {
	FIO;

	string str;
	cin >> str;

	int s = 0;
	int e = str.size();
	int ans = 0;

	while (s < e){

		int mid = (s + e) / 2;

		int H = 0;
		int mul = 1;
		bool find = false;

		for (int i = 0; i < MOD; i++)
		{
			pos[i].clear();
		}

		for (int i = 0; i <= str.size() - mid; i++)
		{
			if (i == 0) {

				for (int j = mid - 1; j >= 0; j--)
				{
					H = mod(H + (str[j] - 'a') * mul);
					if (j > 0)
						mul = mod(mul * 2);
				}
			}
			else
				H = mod((H - (str[i - 1] - 'a') * mul) * 2 + (str[i + mid - 1] - 'a'));


			if (!pos[H].empty()) {

				for (int j = 0; j < pos[H].size(); j++)
				{
					int start = pos[H][j];
					bool match = true;

					for (int k = 0; k < mid; k++)
					{
						if (str[i + k] != str[start + k]) {
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

			if (find)	break;
			else
				pos[H].push_back(i);
		}

		if (find) {
			ans = mid;
			s = mid + 1;
		}
		else {
			e = mid;
		}
	}

	cout << ans;
}