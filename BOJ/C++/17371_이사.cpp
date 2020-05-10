/*
문제
혜아는 답답한 3차원 세계를 벗어나 자유로운 2차원 좌표계 위로 집을 옮길 계획이다. 이 좌표계에는 그 어떤 위치에도 주거할 수 있는 시설이 있기 때문에 혜아는 두 실수 Hx, Hy 를 골라 좌표 (Hx, Hy)로 이사할 것이다.

이사할 집의 위치를 결정하기 위해 절대적으로 중요한 것은 편의시설이 집으로부터 얼마나 멀리 떨어져 있느냐는 점이다. 좌표계에는 N개의 편의시설이 있는데, 좌표계의 주거지역 정책에 따라 x, y 좌표가 모두 정수인 곳에만 편의시설이 있다.

혜아는 N개의 편의시설로 이동하는 데 드는 거리의 평균값이 최소가 되는 좌표로 이사를 가고 싶었지만, 이런 좌표를 찾는 것이 너무 어렵다는 것을 깨달았다. 그래서 그나마 좌표를 찾기 쉽도록 가장 가까운 편의시설까지의 거리와 가장 먼 편의시설까지의 거리의 평균이 최소가 되는 좌표로 이사하려고 한다. 이 좌표계에서 거리는 유클리드 거리를 사용하여, 두 좌표 (Ax, Ay)와 (Bx, By) 사이의 거리는 으로 나타난다고 할 때, 혜아를 도와 가능한 위치 중 하나를 구해 주는 프로그램을 작성해보자.

입력
첫 번째 줄에 편의시설의 개수 N(1 ≤ N ≤ 103)이 주어진다.

다음 N개의 줄의 각 줄에는 두 정수 x와 y(-104 ≤ x, y ≤ 104)가 공백 하나를 사이에 두고 주어진다. 이는 (x, y)에 편의시설이 하나 존재한다는 뜻이다.

출력
첫 번째 줄에 혜아가 이사할 곳의 좌표 (Hx, Hy)를 나타내는 두 실수 Hx, Hy를 공백 하나로 구분하여 출력한다. 가장 가까운 편의시설까지의 거리와 가장 먼 편의시설까지의 거리의 평균을 정답과 비교했을 때 절대오차 혹은 상대오차가 10-6 이하면 정답으로 인정한다.

풀이:
함정이 있는 문제였습니다.
이사할 수 있는 좌표는 무수히 많기 때문에 특정한 좌표를 찾는 건 불가능합니다.

문제의 조건엔 편의시설이 있는 곳으론 이사할 수 없다는 조건이 없기 때문에 가장 가까운 편의시설은 사실 혜아의 집입니다.
가장 가까운 편의시설을 자신의 집으로 고정시켜 두고 나머지 점들 중 가장 먼 점을 구하고, 
그 길이의 평균이 최소인지 모든 점에 대해 수행해 주면 됩니다.
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
#define ll long long
#define vi vector<int>
#define vii vector<pii>

int n;
vii vt;

double getDis(pii p1, pii p2) {
	return (double)sqrt(pow((double)p1.first - (double)p2.first, 2) + pow((double)p1.second - (double)p2.second, 2));
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

	double minDis = 2000000000.0;
	pii ans;

	for (int i = 0; i < vt.size(); i++)
	{
		pii near = vt[i];
		double maxdis = 0;
		for (int j = 0; j < vt.size(); j++)
		{
			pii far = vt[j];
			double tempDis = getDis(near, far);

			if (tempDis > maxdis) {
				maxdis = tempDis;
			}
		}
		if (minDis > maxdis / 2) {
			minDis = maxdis / 2;
			ans = near;
		}
	}
	cout << ans.first << " " << ans.second;
}