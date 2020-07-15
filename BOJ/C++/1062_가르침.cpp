/*
문제
남극에 사는 김지민 선생님은 학생들이 되도록이면 많은 단어를 읽을 수 있도록 하려고 한다. 그러나 지구온난화로 인해 얼음이 녹아서 곧 학교가 무너지기 때문에, 김지민은 K개의 글자를 가르칠 시간 밖에 없다. 김지민이 가르치고 난 후에는, 학생들은 그 K개의 글자로만 이루어진 단어만을 읽을 수 있다. 김지민은 어떤 K개의 글자를 가르쳐야 학생들이 읽을 수 있는 단어의 개수가 최대가 되는지 고민에 빠졌다.

남극언어의 모든 단어는 "anta"로 시작되고, "tica"로 끝난다. 남극언어에 단어는 N개 밖에 없다고 가정한다. 학생들이 읽을 수 있는 단어의 최댓값을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 단어의 개수 N과 K가 주어진다. N은 50보다 작거나 같은 자연수이고, K는 26보다 작거나 같은 자연수 또는 0이다. 둘째 줄부터 N개의 줄에 남극 언어의 단어가 주어진다. 단어는 영어 소문자로만 이루어져 있고, 길이가 8보다 크거나 같고, 15보다 작거나 같다. 모든 단어는 중복되지 않는다.

출력
첫째 줄에 김지민이 K개의 글자를 가르칠 때, 학생들이 읽을 수 있는 단어 개수의 최댓값을 출력한다.

풀이:
비트마스크, 브루트포스, 문자열 처리 문제였습니다.
26개의 알파벳 중 k개를 뽑았을 때 알 수 있는 단어의 수가 최대가 되야 합니다.

모든 단어에 대해 해당 단어의 알파벳들에 대한 비트마스크를 구해놓고, 
26개 알파벳 중 k개를 뽑았을 때 모든 단어들과 비교해가며 비트마스크가 겹치는 경우 카운트를 늘려주면 됩니다.

a,n,t,i,c 는 항상 포함되므로 비트마스크를 맨 처음에 추가해 주어 시간을 단축할 수 있습니다.
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
#define IMAX 2100000001
#define LMAX 1000000000000000000
#define DMAX 0xFFFFFFFFFFFFF
int mv1[4] = { 0, 1, 0, -1 };
int mv2[4] = { -1, 0, 1, 0 };

int n, k;
int word_bitmask[51];
int ans = 0;

void recul(int now_bitmask, int word_cnt, int prev) {

	if (word_cnt == k) {
		//k개의 알파벳을 뽑았을 때

		int cnt = 0;

		for (int i = 0; i < n; i++)
		{
			if ((word_bitmask[i] | now_bitmask) == now_bitmask)
				cnt++;
		}

		ans = max(ans, cnt);

		return;
	}

	for (int i = prev; i < 26; i++)
		//순서에 상관없이 뽑음
	{
		int nextBit = 1 << i;

		if ((now_bitmask & nextBit) == 0) {
			//비트마스크가 비어있을 때
			recul(now_bitmask | nextBit, word_cnt + 1, i + 1);
		}
	}
}

int main(void) {
	FIO;

	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;

		for (int j = 0; j < str.size(); j++)
		{
			int c = str[j] - 'a';

			word_bitmask[i] |= (1 << c);
		}
	}

	int init_bitmask = 0;

	for (int i = 0; i < 26; i++)
	{
		if (i == 'a' - 'a' || i == 'n' - 'a' || i == 'i' - 'a' || i == 'c' - 'a' || i == 't' - 'a') {
			init_bitmask |= (1 << i);
		}
	}

	recul(init_bitmask, 5, 1);

	cout << ans;
}