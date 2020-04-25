/*
문제
KOI 사냥터에는 N 마리의 동물들이 각각 특정한 위치에 살고 있다. 사냥터에 온 사냥꾼은 일직선 상에 위치한 M 개의 사대(총을 쏘는 장소)에서만 사격이 가능하다. 편의상, 일직선을 x-축이라 가정하고, 사대의 위치 x1, x2, ..., xM은 x-좌표 값이라고 하자. 각 동물이 사는 위치는 (a1, b1), (a2, b2), ..., (aN, bN)과 같이 x,y-좌표 값으로 표시하자. 동물의 위치를 나타내는 모든 좌표 값은 양의 정수이다.

사냥꾼이 가지고 있는 총의 사정거리가 L이라고 하면, 사냥꾼은 한 사대에서 거리가 L 보다 작거나 같은 위치의 동물들을 잡을 수 있다고 한다. 단, 사대의 위치 xi와 동물의 위치 (aj, bj) 간의 거리는 |xi-aj| + bj로 계산한다.

예를 들어, 아래의 그림과 같은 사냥터를 생각해 보자. (사대는 작은 사각형으로, 동물의 위치는 작은 원으로 표시되어 있다.) 사정거리 L이 4라고 하면, 점선으로 표시된 영역은 왼쪽에서 세 번째 사대에서 사냥이 가능한 영역이다.



사대의 위치와 동물들의 위치가 주어졌을 때, 잡을 수 있는 동물의 수를 출력하는 프로그램을 작성하시오.

입력
입력의 첫 줄에는 사대의 수 M (1 ≤ M ≤ 100,000), 동물의 수 N (1 ≤ N ≤ 100,000), 사정거리 L (1 ≤ L ≤ 1,000,000,000)이 빈칸을 사이에 두고 주어진다. 두 번째 줄에는 사대의 위치를 나타내는 M개의 x-좌표 값이 빈칸을 사이에 두고 양의 정수로 주어진다. 이후 N개의 각 줄에는 각 동물의 사는 위치를 나타내는 좌표 값이 x-좌표 값, y-좌표 값의 순서로 빈칸을 사이에 두고 양의 정수로 주어진다. 사대의 위치가 겹치는 경우는 없으며, 동물들의 위치가 겹치는 경우도 없다. 모든 좌표 값은 1,000,000,000보다 작거나 같은 양의 정수이다.

출력
출력은 단 한 줄이며, 잡을 수 있는 동물의 수를 음수가 아닌 정수로 출력한다.

풀이:
사대와 동물을 x좌표의 오름차순으로 정렬합니다.
동물을 잡기 위해선 동물의 가장 가까운 왼쪽, 오른쪽 사대만 보면 됩니다.

따라서 어떤 사대보다 동물이 왼쪽에 있으면, 그 동물은 그 사대만 잡을 수 있습니다.
또, 동물이 사대보다 오른쪽에 있고, x좌표가  (현재 사대 + 다음 사대) / 2 보다 작거나 같다면 현재 사대가 그 동물을 책임져야 합니다.
*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<string>
#include<vector>
#include<queue>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>

int M, N, L;
priority_queue<int> sadae;
priority_queue<pii> animal;

bool check(int x, int a, int b) {
	if (abs(x - a) + b <= L)
		return true;
	return false;
}

int main(void) {
	FIO;

	cin >> M >> N >> L;

	for (int i = 0; i < M; i++)
	{
		int x;
		cin >> x;
		sadae.push(-x);
	}

	for (int i = 0; i < N; i++)
	{
		int x, y;
		cin >> x >> y;
		animal.push(make_pair(-x, -y));
	}

	int ans = 0;
	int mid = 2000000100;

	while (!sadae.empty()) {
		int ns = -sadae.top();	sadae.pop();
		if (!sadae.empty())
			mid = (ns - sadae.top()) / 2;
			//현재 사대와 다음 사대의 중간점
		else
			mid = 2000000100;
			//맨 오른쪽의 사대는 mid 값이 무한입니다.

		while (!animal.empty()) {
			int ax = -animal.top().first;
			int ay = -animal.top().second;

			if (check(ns, ax, ay)) {
				ans++;
				animal.pop();
			}
			else if (ax <= mid)
				animal.pop();
				//현재 사대가 책임질 수 있는 마지노선
			else
				break;
		}
	}
	cout << ans;
}