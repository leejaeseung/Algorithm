/*
문제
예전에는 운영체제에서 크로아티아 알파벳을 입력할 수가 없었다. 따라서, 다음과 같이 크로아티아 알파벳을 변경해서 입력했다.

크로아티아 알파벳	변경
č	c=
ć	c-
dž	dz=
đ	d-
lj	lj
nj	nj
š	s=
ž	z=
예를 들어, ljes=njak은 크로아티아 알파벳 6개(lj, e, š, nj, a, k)로 이루어져 있다. 단어가 주어졌을 때, 몇 개의 크로아티아 알파벳으로 이루어져 있는지 출력한다.

dž는 무조건 하나의 알파벳으로 쓰이고, d와 ž가 분리된 것으로 보지 않는다. lj와 nj도 마찬가지이다. 위 목록에 없는 알파벳은 한 글자씩 센다.

입력
첫째 줄에 최대 100글자의 단어가 주어진다. 알파벳 소문자와 '-', '='로만 이루어져 있다.

단어는 크로아티아 알파벳으로 이루어져 있다. 문제 설명의 표에 나와있는 알파벳은 변경된 형태로 입력된다.

출력
입력으로 주어진 단어가 몇 개의 크로아티아 알파벳으로 이루어져 있는지 출력한다.

풀이:
주어진 조건에 맞게 각 알파벳을 만날 때마다 조건을 걸어주면 됩니다.
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

string str;

int main(void) {

	cin >> str;

	int cnt = 0;
	for (int i = 0; i < str.size(); i++)
	{
		int now = str[i];

		switch (now) {
		case 'c':
			if (i < str.size() - 1 && (str[i + 1] == '-' || str[i + 1] == '=')) {				
				i++;
			}
			cnt++;
			break;
		case 'd':
			if (i < str.size() - 2 && str[i + 1] == 'z' && str[i + 2] == '=') {
				i += 2;
			}
			else if (i < str.size() - 1 && str[i + 1] == '-') {
				i++;
			}
			cnt++;
			break;
		case 'l':
			if (i < str.size() - 1 && str[i + 1] == 'j') {
				i++;
			}
			cnt++;
			break;
		case 'n':
			if (i < str.size() - 1 && str[i + 1] == 'j') {
				i++;
			}
			cnt++;
			break;
		case 's':
			if (i < str.size() - 1 && str[i + 1] == '=') {
				i++;
			}
			cnt++;
			break;
		case 'z':
			if (i < str.size() - 1 && str[i + 1] == '=') {
				i++;
			}
			cnt++;
			break;
		default:
			cnt++;
			break;
		}
	}

	cout << cnt;
}