/*
문제
동현이는 로그라이크 던전 탐험 게임을 개발하고 있다. 이 게임에서 던전은 행 열의 격자 형태로 방이 놓여 있는 구조이다. 아래쪽에서 번째 행의 왼쪽에서 번째에 있는 방을 라고 하자.

던전의 각 방에는 R 또는 U가 적혀 있다. 플레이어는 던전의 임의의 방에서부터 시작해 방을 하나씩 깨 나가는데, 이번에 깬 방이 일 때 그 방에 R이 적혀 있었다면 로 이동하고, U가 적혀 있었다면 로 이동한다. 만약 새로 이동할 좌표에 해당하는 방이 없다면 던전을 탈출하게 된다.

동현이는 던전 지도를 효율적으로 만들기 위해 다음과 같은 방식을 사용하였다.

지도의 한 행을 구성하는 종류의 블록을 미리 만들어 놓고, 각 블록에 알파벳 대문자의 처음 글자 중 하나를 대응시킨다. 각 블록은 R과 U로만 이루어진 길이 의 문자열이다.
알파벳 대문자의 처음 종류로 이루어진 길이 의 문자열을 하나 생성한 뒤, 그 문자열의 번째 글자에 대응되는 블록으로 던전의 아래에서 번째 행을 만든다.
던전의 가장 오른쪽 위, 즉 은 보스 방으로, 던전에서 가장 어려운 방인 대신 깨면 막대한 보상이 주어진다. 시작 위치에 따라 보스 방에 도달 가능할 수도 있고 없을 수도 있는데, 동현이는 지금 만든 지도에서 과연 보스 방에 도달할 수 있는 시작 방이 몇 개나 되는지 궁금해졌다.

하지만, 동현이는 지도 생성 말고도 할 일이 많다. 여러분이 동현이를 대신해 의문점을 해결해 주자!

입력
첫 번째 줄에 던전의 행 개수 , 열 개수 , 블록의 종류 가 공백으로 구분되어 주어진다. (, )

두 번째 줄부터 개의 줄에 R과 U로만 이루어진 길이 의 문자열이 주어진다. 이 개의 줄 중 번째 줄은 번째 알파벳 대문자에 대응되는 블록이다.

그 다음 줄에 알파벳 대문자의 처음 종류로만 이루어진 길이 의 문자열이 주어진다. 이 문자열의 번째 글자는 던전의 아래에서 번째 행을 구성하는 블록을 의미한다.

출력
첫 번째 줄에 주어진 지도에서 에 도달할 수 있는 시작 방의 개수를 출력한다. 도 시작 방이 될 수 있음에 유의하라.

풀이:
200000 개의 행과 200000 개의 열이 주어질 수 있기 때문에 일반적인 탐색 알고리즘을 사용하면
당연히 시간 초과가 나는 문제이다.

따라서 투 포인터를 이용해 200000개의 행만 탐색함으로써 O(n) 만에 풀이할 수 있다.
투 포인터의 구간 = 현재 행에서 보스 방으로 갈 수 있는 구간

왼쪽(LP), 오른쪽(RP) 포인터를 다음과 같이 정의한다.(오른쪽부터 탐색했을 때 - 보스방이 오른쪽 위이므로)

LP = 다음 U 가 나오기 바로 전의 인덱스
RP = 다음 번 U의 인덱스(그대로 내려올 수도 있다.)

보스 방에서부터 구간을 차례대로 내려오면 구간이 계단 모양 혹은 그대로 내려오게 되는데,
매번 해당 구간의 수를 세어주면 된다.

매 행마다 U를 찾으면 시간 초과가 나므로 미리 26가지의 행에 대해 U의 next 인덱스 정보를 전처리 해 주어야 한다.
*/
#include<iostream>
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
int mv1[4] = { 0, 1, 0, -1 };
int mv2[4] = { 1, 0, -1, 0 };
int mv_all1[8] = { 0, 1, 0, -1, -1, -1, 1, 1 };
int mv_all2[8] = { 1, 0, -1, 0 , -1, 1, -1, 1 };

int n, m, k;
int nextU[26][200001];

int main(void) {
	FIO;

	cin >> n >> m >> k;

	for (int i = 0; i < k; i++)
	{
		string block;
		cin >> block;

		int prevU = -1;

		for (int j = 0; j < m; j++)
		{
			
			if (block[j] == 'U') {
				prevU = j;
			}
			nextU[i][j] = prevU;
			//현재 idx에서 다음 번 U의 idx
		}
	}

	string order;
	cin >> order;

	ll l = 0;

	if(m > 1)
		l = nextU[order[n - 1] - 'A'][m - 2] + 1;

	ll r = (ll)m - 1;

	ll ans = r - l + 1;

	for (int i = n - 2; i >= 0; i--)
	{
		int nowRow = order[i] - 'A';

		r = nextU[nowRow][r];
		if(l > 0)
			l = nextU[nowRow][l - 1] + 1;

		if (r < l)	break;
		//구간이 사라지면 break

		ans += r - l + 1;
	}

	cout << ans;
}