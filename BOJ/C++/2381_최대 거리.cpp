/*
문제
N(1 ≤ N ≤ 50,000)개의 점들이 있을 때, 최대 L1-metric 거리를 찾으시오.

두 점의 좌표가 (a, b), (c, d)일 때, 두 점의 L1-metric 거리는 |a-c|+|b-d|이다.

입력
첫째 줄에 N이 주어진다. 다음 N개의 줄에는 각 점의 x, y좌표가 주어진다. 각 좌표의 범위는 -1,000,000이상 1,000,000이하이다.

출력
첫째 줄에 최대 거리를 출력한다.

풀이:
모든 점을 포함하는 직사각형을 하나 그립니다.
그 직사각형의 두 대각선 중 최대값(L1-metric으로)이 구하고자 하는 값입니다.

각 꼭지점은 임의의 점이므로 각 꼭지점에서 L1-metric이 가장 가까운 점을 찾아 새로운 꼭지점으로 생각하여 풀이합니다.
*/
#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<vector>
#include<queue>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>

int N;
vector<pii> point;

int L1met(int x1, int y1, int x2, int y2) {
	return abs(x1 - x2) + abs(y1 - y2);
}

int main(void) {
	FIO;

	cin >> N;
	int left = 1000001;
	int up = -1000001;
	int right = -1000001;
	int down = 1000001;

	for (int i = 0; i < N; i++)
	{
		int x, y;
		cin >> x >> y;
		point.push_back(make_pair(x, y));
		
		//직사각형의 4개의 변을 구합니다.
		left = min(left, x);
		up = max(up, y);
		right = max(right, x);
		down = min(down, y);
	}
	
	int leftup_dist = 3000000;
	int rightdown_dist = 3000000;
	int rightup_dist = 3000000;
	int leftdown_dist = 3000000;
	for (int i = 0; i < N; i++)
	{
		int x = point[i].first;
		int y = point[i].second;

		//각 꼭짓점으로부터 가장 가까운 점까지의 거리를 구합니다.
		leftup_dist = min(leftup_dist, L1met(left, up, x, y));
		rightdown_dist = min(rightdown_dist, L1met(right, down, x, y));
		rightup_dist = min(rightup_dist, L1met(right, up, x, y));
		leftdown_dist = min(leftdown_dist, L1met(left, down, x, y));
	}
	int res = 3000000;
	int half = abs(right - left) + abs(up - down);
	res = max(half - leftup_dist - rightdown_dist, half - rightup_dist - leftdown_dist);

	cout << res;
}