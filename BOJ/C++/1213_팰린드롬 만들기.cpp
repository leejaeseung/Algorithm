/*
문제
임한수와 임문빈은 서로 사랑하는 사이이다.

임한수는 세상에서 팰린드롬인 문자열을 너무 좋아하기 때문에, 둘의 백일을 기념해서 임문빈은 팰린드롬을 선물해주려고 한다.

임문빈은 임한수의 영어 이름으로 팰린드롬을 만들려고 하는데, 임한수의 영어 이름의 알파벳 순서를 적절히 바꿔서 팰린드롬을 만들려고 한다.

임문빈을 도와 임한수의 영어 이름을 팰린드롬으로 바꾸는 프로그램을 작성하시오.

입력
첫째 줄에 임한수의 영어 이름이 있다. 알파벳 대문자로만 된 최대 50글자이다.

출력
첫째 줄에 문제의 정답을 출력한다. 만약 불가능할 때는 "I'm Sorry Hansoo"를 출력한다. 정답이 여러 개일 경우에는 사전순으로 앞서는 것을 출력한다.

풀이:
홀수인 알파벳 개수가 2개 이상이면 팰린드롬을 만들 수 없습니다.

그리디하게 작은 알파벳부터 그 알파벳의 개수 / 2 개씩 붙여가며 왼쪽 절반을 만들고, 
왼쪽을 역전시켜 오른쪽에 붙여줍니다.
만약 홀수 개인 알파벳이 하나 있었다면 중간에 끼워넣어 줍니다.
*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<vector>
#include<stack>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>

string str;
int alpha[26];
int leng;

int main(void) {
	FIO;

	cin >> str;
	leng = str.size();

	for (int i = 0; i < str.size(); i++)
	{
		alpha[str.at(i) - 'A']++;
	}

	int flag = 0;
	int mid = -1;

	for (int i = 0; i < 26; i++)
	{
		if (alpha[i] > 0 && alpha[i] % 2 == 1) {
			flag++;
			alpha[i]--;
			mid = i;
		}
	}

	if (flag > 1)
		cout << "I'm Sorry Hansoo";
	else {
		string ans = "", temp;

		for (int i = 0; i < 26; i++)
		{
			if (alpha[i] > 0) {
				for (int j = 0; j < alpha[i] / 2; j++)
				{
					ans += i + 'A';
				}
			}
		}
		temp = ans;
		reverse(temp.begin(), temp.end());

		if(mid != -1)
		ans += mid + 'A';

		cout << ans + temp;
	}
}