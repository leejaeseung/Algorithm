/*
문제
세계적인 Ki-pop 열풍을 이끌고 있는 키파는 역사에 남을 새 앨범의 출시를 앞두고 고민에 빠졌다.

제목 뭐로 하지?

키파의 앨범은 항상 같은 방법으로 만든 단어를 사용하는 전통이 있다. 전통에 따르면, 키파는 앨범에 어울리는 단어 두 개를 선택한 다음 이 단어에서 공통된 알파벳을 하나 선택하고, 앞에 올 단어에서 그 알파벳 뒤의 문자들을 지우고, 뒤에 올 단어에서는 그 알파벳 앞의 문자들을 지운 후 두 단어를 합쳐서 새로운 앨범의 제목을 정한다. 같은 알파벳이 여러 번 등장한다면 그중 원하는 것을 아무거나 선택한다.

예를 들어 christmas와 halloween을 선택했다면, 공통된 알파벳 a를 선택하여 christma와 alloween을 만들고 이 둘을 합쳐서 christmalloween이 된다.

키파는 앨범에 어울리는 단어 N개를 선택해 놨지만, 제목을 정하는 일은 지워지는 문자의 개수가 최소가 되게 정해 달라는 부탁과 함께 당신에게 맡겨 두고 녹음을 하러 떠났다. 키파의 성격상 당신은 키파가 돌아오기 전에 제목을 정해야 한다!

입력
첫째 줄에 문자열의 개수 N이 주어진다. 이후 N개 줄에 서로 다른 문자열 Si가 주어진다. 각각의 문자열은 20개 이하의 알파벳 소문자만으로 구성되어 있다.

2 ≤ N ≤ 105
2 ≤ |Si| ≤ 20
Si ≠ Sj if i ≠ j
출력
주어진 조건에 맞게 지워진 문자의 개수를 최소로 하는 단어를 만들었을 때, 지워진 문자의 개수를 출력한다. 주어진 조건에 맞는 단어를 만들 수 없는 경우 -1을 출력한다.

풀이:
각 문자열마다 다음 작업을 해줍니다.

해당 문자열에 알파벳 x가 있을 때, 앞 쪽에서 x를 처음 만날 때까지 지운 개수와 뒤 쪽에서 x를 처음 만날 때까지 지운 개수를 구해줍니다.

그 다음, 모든 26가지 알파벳에 대하여, 알파벳을 하나 정하고 그 알파벳의 앞쪽에 있는 개수가 가장 적은 문자열을 고르고, 
마찬가지로 뒤쪽에 있는 개수가 가장 적은 문자열을 고릅니다. (문자열이 중복되거나, 알파벳을 가지고 있지 않는 경우를 걸러줍니다.)

앞쪽, 뒤쪽의 개수를 합한 값이 가장 최소인 알파벳의 값이 정답이 됩니다.
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
int front[100001][26];
int back[100001][26];
bool check[100001];

int main(void) {

	FIO;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		
		for (int j = 0; j < 26; j++)
		{
			front[i][j] = -1;
			back[i][j] = -1;


			char findAlpha = j + 'a';
			for (int k = 0; k < str.length(); k++)
			{
				char c = str[k];

				if (c == findAlpha) {
					front[i][j] = k;
					break;
				}
			}

			for (int k = str.length() - 1; k >= 0; k--)
			{
				char c = str[k];

				if (c == findAlpha) {
					back[i][j] = str.length() - k - 1;
					break;
				}
			}
		}
	}

	int ans = IMAX;

	for (int i = 0; i < 26; i++)
	{
		for (int i = 0; i < n; i++)
		{
			check[i] = false;
		}

		int minF = IMAX;
		int minB = IMAX;

		int checkIdx = -1;

		for (int j = 0; j < n; j++)
		{
			if (front[j][i] == -1)continue;
			if (minF > front[j][i]) {
				minF = front[j][i];
				checkIdx = j;
			}
		}
		if (checkIdx == -1)	continue;
		check[checkIdx] = true;

		for (int j = 0; j < n; j++)
		{
			if (front[j][i] == -1)continue;
			if (check[j])	continue;
			if (minB > back[j][i]) {
				minB = back[j][i];
			}
		}
		if (minB == IMAX)	continue;

		ans = min(ans, minB + minF);
	}
	if (ans == IMAX)
		cout << "-1";
	else
		cout << ans;
	
}