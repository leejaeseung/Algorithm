/*
문제
다각형의 임의의 두 꼭짓점을 연결하는 선분이 항상 다각형 내부에 존재하는 다각형을 볼록 다각형이라고 한다. 아래 그림에서 (a)는 볼록 다각형이며, (b)는 볼록 다각형이 아니다.



조금만 생각해 보면 다각형의 모든 내각이 180도 이하일 때 볼록 다각형이 된다는 것을 알 수 있다. 편의상 이 문제에서는 180도 미만인 경우만을 볼록 다각형으로 한정하도록 한다.

2차원 평면에 N개의 점이 주어졌을 때, 이들 중 몇 개의 점을 골라 볼록 다각형을 만드는데, 나머지 모든 점을 내부에 포함하도록 할 수 있다. 이를 볼록 껍질 (CONVEX HULL) 이라 한다. 아래 그림은 N=10인 경우의 한 예이다.



점의 집합이 주어졌을 때, 볼록 껍질을 이루는 점의 개수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 점의 개수 N(3 ≤ N ≤ 100,000)이 주어진다. 둘째 줄부터 N개의 줄에 걸쳐 각 점의 x좌표와 y좌표가 빈 칸을 사이에 두고 주어진다. 주어지는 모든 점의 좌표는 다르다고 가정해도 좋다. x좌표와 y좌표의 범위는 절댓값 40,000을 넘지 않는다. 입력으로 주어지는 다각형의 모든 점이 일직선을 이루는 경우는 없다.

출력
첫째 줄에 볼록 껍질을 이루는 점의 개수를 출력한다.

볼록 껍질의 변에 점이 여러 개 있는 경우에는 가장 양 끝 점만 개수에 포함한다.

풀이:
볼록 껍질(Convex Hull) 문제였습니다. 다음과 같이 진행합니다.

1. 기준점을 잡는다 -> y 가 가장 작은 점, y 가 같다면 x가 가장 작은 점
2. 점들을 반시계 방향으로 정렬한다. -> CCW를 이용해 기준점, p1, p2를 비교해 
세 점이 반시계 방향이라면 True, 시계 방향이라면 False, 일직선일 때 p1이 기준점과 가까우면 True, 멀면 False을 리턴하는 Comparator로 정렬합니다.
3. 정렬된 점들에 대해 그라함 스캔 알고리즘을 사용합니다.
- 스택의 마지막 - 1 = first
- 스택의 마지막 = second
- 현재 비교하는 점 = next

위 세 점 first, second, next에 대해 CCW를 수행합니다.
CCW > 0  -> 스택에 next를 넣습니다.
CCW <= 0 -> 볼록껍질이 아니므로 이전의 first, second로 되돌리기 위해 스택을 pop 합니다.(이 작업을 CCW > 0 이 될 때까지 수행합니다.)

남은 스택의 크기가 정답이 됩니다.
*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<string.h>
#include<vector>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>
#define pll pair<long long, long long>
#define ll long long

int N;
vector <pll> vt;
pll start = make_pair(100001, 100001);

void findStart() {

	for (int i = 0; i < N; i++)
	{
		int x = vt[i].first;
		int y = vt[i].second;

		if (start.second > y) {
			start.first = x;
			start.second = y;
		}
		else if (start.second == y) {
			if (start.first > x) {
				start.first = x;
				start.second = y;
			}
		}
	}
}

ll dist(pll p1, pll p2) {
	return (p2.first - p1.first) * (p2.first - p1.first) + (p2.second - p1.second) * (p2.second - p1.second);
}

int CCW(pll p1, pll p2, pll p3) {
	ll S = (p2.first - p1.first) * (p3.second - p1.second) - (p2.second - p1.second) * (p3.first - p1.first);

	if (S > 0)	return 1;
	else if (S == 0)	return 0;
	else
		return -1;
}

int myCom(pll p1, pll p2) {
	int ret;
	int com = CCW(start, p1, p2);

	if (com == 0) {
		ret = (dist(start, p1) < dist(start, p2));
	}
	else if (com == 1) {
		ret = 1;
	}
	else {
		ret = 0;
	}
	return ret;
}

int main(void) {
	FIO;

	cin >> N;

	int ans = 0;

	for (int i = 0; i < N; i++)
	{
		int x, y;
		cin >> x >> y;

		vt.push_back(make_pair(x, y));
	}

	findStart();

	sort(vt.begin(), vt.end(), myCom);

	vector<pll> st;
	st.push_back(vt[0]);

	for (int i = 1; i < vt.size(); i++)
	{

		pll next = vt[i];

		while (st.size() > 1 && CCW(st[st.size() - 2], st[st.size() - 1], next) <= 0) {
			st.pop_back();
		}
		st.push_back(next);
	}

	cout << st.size();
}