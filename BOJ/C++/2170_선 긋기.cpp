/*
문제
매우 큰 도화지에 자를 대고 선을 그으려고 한다. 선을 그을 때에는 자의 한 점에서 다른 한 점까지 긋게 된다. 선을 그을 때에는 이미 선이 있는 위치에 겹쳐서 그릴 수도 있는데, 여러 번 그은 곳과 한 번 그은 곳의 차이를 구별할 수 없다고 하자.

이와 같은 식으로 선을 그었을 때, 그려진 선(들)의 총 길이를 구하는 프로그램을 작성하시오. 선이 여러 번 그려진 곳은 한 번씩만 계산한다.

입력
첫째 줄에 선을 그은 횟수 N(1≤N≤1,000,000)이 주어진다. 다음 N개의 줄에는 선을 그을 때 선택한 두 점이 주어진다. 선택한 지점은 -1,000,000,000 이상 1,000,000,000 이하의 정수이다.

출력
첫째 줄에 그은 선의 총 길이를 출력한다.

풀이:
왼쪽 점에 대해 오름차순으로 정렬하고, 선분을 차례대로 보면서 선분이 겹쳐진다면 새로운 선분을 만듭니다.
겹치지 않는다면 이전까지 만든 선분 길이를 답에 더하고 다시 진행합니다.
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

int N;
vector<pii> vt;

int main(void) {
	FIO;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int x, y;
		cin >> x >> y;
		vt.push_back(make_pair(min(x, y), max(x, y)));
	}

	sort(vt.begin(), vt.end());
	
	int maxS = vt[0].first;
	int maxE = vt[0].second;
	int ans = maxE - maxS;
	int realAns = 0;

	for (int i = 1; i < N; i++)
	{
		int nowS = vt[i].first;
		int nowE = vt[i].second;

		if (nowS <= maxE) {
			maxE = max(nowE, maxE);
		}
		else {
			realAns += ans;
			ans = 0;
			maxS = nowS;
			maxE = nowE;
		}
		ans = max(ans, maxE - maxS);
	}
	cout << realAns + ans;
}