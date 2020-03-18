/*
문제
지질 탐사의 결과 지하 깊숙이 묻힌 금강석 정보를 나타내는 지도가 아래 그림처럼 만들어졌다. 지도에는 같은 간격으로 수직선과 수평선들이 그어져 있다. 금강석은 항상 수직선(경계선 포함)과 수평선(경계선 포함)이 만나는 곳에 위치하며 굵은 점으로 표시된다. 앞으로 지도의 왼쪽 변에서 A 칸 떨어진 수직선과 지도의 아래쪽 변에서 B 칸 떨어진 수평선이 만나는 곳을 (A, B)라고 표시하자.

이제 땅을 파서 금강석을 캐려고 한다. 굴착할 영역은 항상 각 변이 지도의 경계선과 평행한 정사각형이다. 현재 보유하고 있는 예산과 굴착 기술로는 한 변의 길이가 K인 정사각형 영역에 대해 단 한 번만 팔 수 있다. 그래서 정사각형 영역에 가장 많은 금강석이 포함될 수 있도록 하려고 한다. 단, 굴착할 영역인 정사각형의 모든 꼭짓점들은 지도의 수직선(경계선 포함)과 수평선(경계선 포함)이 만나는 곳에 위치해야 하고, 정사각형 변에 놓인 금강석도 이 정사각형에 포함된 것으로 본다.

예를 들어, 아래 그림에서 K=3인 경우 가장 많은 금강석을 포함하는 정사각형은 5개의 금강석을 포함한다.



지질 탐사 지도에 대한 정보를 입력받아 가장 많은 금강석을 포함하는 정사각형을 구하는 프로그램을 작성하라.

입력
첫째 줄에 4개의 정수 N, M, T, K가 빈칸을 사이에 두고 주어진다. N은 지도의 너비를 나타내고, M은 지도의 높이를 나타낸다(1 ≤ N, M ≤ 1,000,000).  T는 금강석의 개수를 나타내고, K는 정사각형의 크기(한 변의 길이)를 나타낸다. T는 1 이상 100 이하이고, K는 1 이상 1,000,000 이하로서 N과 M보다 크지 않다. 둘째 줄부터 T개의 줄에는 각 줄마다 각 금강석의 위치 (A, B)를 나타내는 두 개의 정수 A와 B가 빈칸을 사이에 두고 주어진다. A는 0 이상 N 이하이고, B는 0 이상 M 이하이다. 입력으로 주어진 금강석의 좌표들은 모두 다르다.

출력
첫째 줄에 정사각형의 왼쪽 위 꼭짓점의 위치 (X, Y)를 나타내는 두 개의 정수 X, Y를 빈칸을 사이에 두고 출력한다. 둘째 줄에는 이 정사각형에 포함되는 금강석의 개수를 출력한다. 답이 여러 개 있는 경우에는 그 중 하나만 출력하라.

정사각형은 지도 밖으로 벗어날 수 없다.

풀이:
모든 두 점의 쌍에 대하여 다음 작업을 수행한다.(T^2)
정사각형은 오른쪽아래로 쭉 잡아당겼다고 생각하면 두 점은 왼쪽변, 오른쪽 변에 있게 된다.
위와 같은 정사각형에 대해 모든 점을 비교해서(T) 카운트하며 풀이한다.
총 시간복잡도 = T^3
*/
#include<iostream>
#include <vector>
#include<utility>
#include<algorithm>
using namespace std;

int N, M, T, K;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> M >> N >> T >> K;

	vector<pair<int, int> > vt;

	for (int k = 0; k < T; k++)
	{
		int x, y;
		cin >> x >> y;
		vt.push_back(make_pair(x, y));
	}
	
	int ans_max = 0;
	int ans_x, ans_y;
	for (int i = 0; i < T; i++)
	{
		for (int j = 0; j < T; j++)
		{
			int cnt = 0;
			int sq_x = min(vt[i].first, vt[j].first);
			int sq_y = max(vt[i].second, vt[j].second);
			
			if (max(vt[i].first, vt[j].first) - sq_x > K)	continue;
			if (sq_y - min(vt[i].second, vt[j].second) > K)	continue;

			if (sq_x + K > M) {
				sq_x = M - K;
			}
			if (sq_y - K < 0) {
				sq_y = K;
			}

			for (int k = 0; k < T; k++)
			{
				int now_x = vt[k].first;
				int now_y = vt[k].second;

				if (now_x >= sq_x && now_x <= sq_x + K && now_y <= sq_y && now_y >= sq_y - K)	cnt++;
			}
			if (ans_max < cnt) {
				ans_max = cnt;
				
				ans_x = sq_x;
				ans_y = sq_y;
			}
		}
	}
	cout << ans_x << " " << ans_y << "\n" << ans_max;
}