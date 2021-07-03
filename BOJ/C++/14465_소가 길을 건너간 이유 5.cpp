/*
문제
농부 존의 농장에 원형 길이 있다고 했지만, 길은 그뿐만이 아니다. 그 옆에 일자형 길이 있는데, 1번부터 N번까지의 번호가 붙은 횡단보도 N (1 ≤ N ≤ 100,000)개로 이루어져 있다. 교통사고를 방지하기 위해 존은 각 횡단보도에 신호등을 설치해 놓았다. 그러던 어느 날, 강력한 뇌우로 인해 몇몇 신호등이 망가졌다. 존은 연속한 K개의 신호등이 존재하도록 신호등을 수리하고 싶다. 이번에도 우리가 존을 도와주자.

입력
첫 줄에 N, K, B (1 ≤ B,K ≤ N)가 주어진다. 그 다음 B줄에는 고장난 신호등의 번호가 하나씩 주어진다.

출력
정상적으로 작동하는 연속 K개의 신호등이 존재하려면 최소 몇 개의 신호등을 수리해야 하는지 출력한다.

풀이:
k 의 길이를 갖는 투 포인터를 한 칸씩 옮겨가며 최소 수리 개수를 찾는다.
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
#define IMAX 2147483647
#define LMAX 1000000000000500000
#define DMAX 0xFFFFFFFFFFFFF
int mv1[4] = { 0, 1, -1, 0 };
int mv2[4] = { 1, 0, 0, -1 };

int n, k, b;
int broke[100001];

int main() {
	FIO;

	cin >> n >> k >> b;

	for (int i = 0; i < b; i++)
	{
		int v;
		cin >> v;
		broke[v] = 1;
	}

	int l = 1;
	int r = k;
	int brokeCnt = 0;
	int minBroke = IMAX;

	for (int i = 1; i <= k; i++)
	{
		if (broke[i]) {
			brokeCnt++;
		}
	}

	while (r <= n) {	
		minBroke = min(minBroke, brokeCnt);

		brokeCnt = brokeCnt + broke[++r] - broke[l++];
	}

	cout << minBroke;
}