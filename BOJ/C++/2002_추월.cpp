/*
문제
대한민국을 비롯한 대부분의 나라에서는 터널 내에서의 차선 변경을 법률로 금하고 있다. 조금만 관찰력이 있는 학생이라면 터널 내부에서는 차선이 파선이 아닌 실선으로 되어 있다는 것을 알고 있을 것이다. 이는 차선을 변경할 수 없음을 말하는 것이고, 따라서 터널 내부에서의 추월은 불가능하다.

소문난 명콤비 경찰 대근이와 영식이가 추월하는 차량을 잡기 위해 한 터널에 투입되었다. 대근이는 터널의 입구에, 영식이는 터널의 출구에 각각 잠복하고, 대근이는 차가 터널에 들어가는 순서대로, 영식이는 차가 터널에서 나오는 순서대로 각각 차량 번호를 적어 두었다.

N개의 차량이 지나간 후, 대근이와 영식이는 자신들이 적어 둔 차량 번호의 목록을 보고, 터널 내부에서 반드시 추월을 했을 것으로 여겨지는 차들이 몇 대 있다는 것을 알게 되었다. 대근이와 영식이를 도와 이를 구하는 프로그램을 작성해 보자.

입력
입력은 총 2N+1개의 줄로 이루어져 있다. 첫 줄에는 차의 대수 N(1≤N≤1,000)이 주어진다. 둘째 줄부터 N개의 줄에는 대근이가 적은 차량 번호 목록이 주어지고, N+2째 줄부터 N개의 줄에는 영식이가 적은 차량 번호 목록이 주어진다. 각 차량 번호는 6글자 이상 8글자 이하의 문자열로, 영어 대문자('A'~'Z')와 숫자('0'~'9')로만 이루어져 있다.

같은 차량 번호가 두 번 이상 주어지는 경우는 없다.

출력
첫째 줄에 터널 내부에서 반드시 추월을 했을 것으로 여겨지는 차가 몇 대인지 출력한다.

풀이:
처음엔 LIS 문제인 줄 알았지만 다음과 같은 반례가 있었습니다.
5
1 2 3 4 5
4 2 3 1 5

아이디어 :  모든 스트링을 들어간 순서로 번호를 매깁니다.(맵 이용)
추월을 하지 않았다면 나온 순서가 0 1 2 3 4 ... 순으로 나와야 하므로 이를 체크해 줍니다.
현재 idx 와 같지 않다면 추월한 것이므로 카운트를 증가시키고, 추월한 차의 번호를 체크합니다.
(체크된 번호는 이미 앞에 있기 때문에 idx를 다음 순번으로 정할 때 건너뜁니다.)
idx와 같다면, 다음에 올 번호로 idx를 업데이트 해줍니다.
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
map<string, int> m;
bool check[1001];

int main(void) {
	FIO;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		m[str] = i;
	}

	int cnt = 0;
	int idx = 0;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;

		int nowIdx = m[str];

		if (nowIdx == idx) {
			while (check[++idx]);
			//이미 앞에 나온 차는 건너뛰고 idx 증가
		}
		else {
			cnt++;
			check[nowIdx] = true;
		}
	}

	cout << cnt;
}