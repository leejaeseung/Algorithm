/*
문제
복면산이란 수학 퍼즐의 일종으로, 어떤 계산식의 각 숫자들을 특정 문자로 바꾸면 각 문자가 어떤 숫자인지 맞추는 퍼즐이다.

대표적으로 SEND+MORE=MONEY가 있다.

  SEND
+ MORE
------
 MONEY
S=9, E=5, N=6, D=7, M=1, O=0, R=8, Y=2로 바꾸면 식이 성립한다.

  9567
+ 1085
------
 10652
복면산 문제가 주어질 때, 답이 존재하는지 여부를 출력하시오.

단, 같은 문자는 같은 숫자에 대응되어야 하며, 서로 다른 문자는 서로 다른 숫자를 나타낸다. 또한, 수는 0으로 시작할 수 있다.

입력
세 단어가 공백을 두고 주어진다. 첫 번째 단어와 두 번째 단어를 더한 결과가 세 번째 단어임을 의미한다.

단어는 공백 없이 알파벳 대문자로만 이루어져 있으며 각 단어의 길이는 18자리를 넘지 않는다.

출력
계산식에 해답이 존재한다면 YES를, 그렇지 않다면 NO를 한 줄에 출력한다.

풀이:
완전 탐색 문제였습니다.
알파벳들의 종류를 모두 받아(최대 10개) 각각 알파벳에 0~9 의 값을 할당해가며 식이 성립하는지 판단합니다.

받은 알파벳을 정렬하지 않으면 시간 초과가 나는 부분은 조금 이상한 것 같습니다.
*/
#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<vector>
#include<cstring>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>

string str1, str2, res, all;
vector<int> alpha;
int check[26];
bool visit[26];
bool checkNum[10];

int stringTonum(string s) {			//string을 숫자로 바꿈.
	int ret = 0;
	int mul = 1;
	for (int i = s.length() - 1; i >= 0; i--)
	{
		ret += check[s[i] - 'A'] * mul;
		mul *= 10;
	}
	return ret;
}

bool recul(int idx) {

	if (idx >= alpha.size()) {
		if (stringTonum(str1) + stringTonum(str2) == stringTonum(res))
			return true;
		return false;
	}

	for (int i = 0; i <= 9; i++)
	{
		if (checkNum[i])	continue;		//이미 할당받은 숫자라면 Pass
			check[alpha[idx]] = i;			//알파벳에 숫자를 할당
			checkNum[i] = true;				//숫자 할당 check
			if(recul(idx + 1))
				return true;
			check[alpha[idx]] = -1;			//할당을 풀어줌
			checkNum[i] = false;			//마찬가지
	}
	return false;
}

int main(void) {
	FIO;

	cin >> str1 >> str2 >> res;
	all = str1 + str2 + res;
	memset(check, -1, sizeof(int) * 26);

	for (int i = 0; i < all.length(); i++)
	{
		if (!visit[all[i] - 'A']) {
			//중복은 제거하여 알파벳을 받음.
			visit[all[i] - 'A'] = true;
			alpha.push_back(all[i] - 'A');		
		}
	}

	sort(alpha.begin(), alpha.end());

	if (alpha.size() <= 10) {
		if (recul(0))
			cout << "YES";
		else
			cout << "NO";
	}
	else
		cout << "NO";
}