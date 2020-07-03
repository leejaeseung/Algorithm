/*
문제
평면상에 n개의 점 (P1, .... ,  Pn) 이 놓여져있다고 했을 때, 거리가 최소인 두 개의 점을 구하고 그 거리를 알고 싶다.

입력
입력은 첫 번째 줄에 정수로 된 점의 개수 n이 주어진다.

두 번째 줄부터 n+1번째 줄까지 2개의 정수 x,y가 공백을 사이에 두고 주어진다.

i+1번째 줄은 Pi 의 x,y 좌표를 의미하고 n개의 점에 대해서 주어지게 된다.

점의 개수는 2 ≦ n ≦ 500000 , 좌표의 범위는 -10000 ≦ x,y ≦10000로 주어진다.

또한, 모든 점의 좌표는 같은 것이 없이 다른 것으로 한다.

출력
가장 가까운 두 점 사이의 거리의 제곱을 출력하시오.

풀이:
분할-정복으로 풀이했습니다. 히스토그램 문제와 거의 비슷합니다.
어떤 구간에서의 가장 가까운 점은 다음 세 가지 중 하나입니다.

1.왼쪽 구간의 가까운 값
2. 오른쪽 구간의 가까운 값
3. 왼쪽, 오른쪽을 합쳤을 때 중앙 점으로부터 가장 가까운 값

1, 2번 경우는 분할 탐색으로 얻어옵니다.
3번에서, 중앙 점으로부터 떨어진 거리가 1, 2 번에서 구한 최소값보다 크다면, 계산할 필요가 없으므로 걸러줄 수 있습니다.

기저 조건으로는 점이 하나일 땐 거리를 구할 수 없으므로 2개인 경우에 거리를 반환합니다.
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
vector<pii> vt;

int getDis(pii x1, pii x2) {
	return pow(x1.first - x2.first, 2) + pow(x1.second - x2.second, 2);
}

int divide(int s, int e) {
	if (s == e)	return IMAX;	
	if (e - s + 1 == 2) {
		//점이 두 개일 때 점들의 거리를 반환
		return getDis(vt[s], vt[e]);
	}
	int mid = (s + e) / 2;

	int leftMin = divide(s, mid - 1);
	int rightMin = divide(mid + 1, e);

	int d = min(leftMin, rightMin);
	//왼쪽, 오른쪽 중 최소 거리
	int retMin = d;

	for (int i = s; i <= e; i++)
	{
		pii now = vt[i];

		if (mid == i)	continue;

		if (now.first >= vt[mid].first - d && now.first <= vt[mid].first + d && now.second >= vt[mid].second - d && now.second <= vt[mid].second + d) {
			retMin = min(retMin, getDis(vt[mid], now));
		}
	}
	return retMin;
}

int main(void) {
	FIO;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;

		vt.push_back(make_pair(x, y));
	}

	sort(vt.begin(), vt.end());

	cout << divide(0, vt.size() - 1);
}