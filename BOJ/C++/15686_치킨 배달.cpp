/*
문제
크기가 N×N인 도시가 있다. 도시는 1×1크기의 칸으로 나누어져 있다. 도시의 각 칸은 빈 칸, 치킨집, 집 중 하나이다. 도시의 칸은 (r, c)와 같은 형태로 나타내고, r행 c열 또는 위에서부터 r번째 칸, 왼쪽에서부터 c번째 칸을 의미한다. r과 c는 1부터 시작한다.

이 도시에 사는 사람들은 치킨을 매우 좋아한다. 따라서, 사람들은 "치킨 거리"라는 말을 주로 사용한다. 치킨 거리는 집과 가장 가까운 치킨집 사이의 거리이다. 즉, 치킨 거리는 집을 기준으로 정해지며, 각각의 집은 치킨 거리를 가지고 있다. 도시의 치킨 거리는 모든 집의 치킨 거리의 합이다.

임의의 두 칸 (r1, c1)과 (r2, c2) 사이의 거리는 |r1-r2| + |c1-c2|로 구한다.

예를 들어, 아래와 같은 지도를 갖는 도시를 살펴보자.

0 2 0 1 0
1 0 1 0 0
0 0 0 0 0
0 0 0 1 1
0 0 0 1 2
0은 빈 칸, 1은 집, 2는 치킨집이다.

(2, 1)에 있는 집과 (1, 2)에 있는 치킨집과의 거리는 |2-1| + |1-2| = 2, (5, 5)에 있는 치킨집과의 거리는 |2-5| + |1-5| = 7이다. 따라서, (2, 1)에 있는 집의 치킨 거리는 2이다.

(5, 4)에 있는 집과 (1, 2)에 있는 치킨집과의 거리는 |5-1| + |4-2| = 6, (5, 5)에 있는 치킨집과의 거리는 |5-5| + |4-5| = 1이다. 따라서, (5, 4)에 있는 집의 치킨 거리는 1이다.

이 도시에 있는 치킨집은 모두 같은 프랜차이즈이다. 프렌차이즈 본사에서는 수익을 증가시키기 위해 일부 치킨집을 폐업시키려고 한다. 오랜 연구 끝에 이 도시에서 가장 수익을 많이 낼 수 있는  치킨집의 개수는 최대 M개라는 사실을 알아내었다.

도시에 있는 치킨집 중에서 최대 M개를 고르고, 나머지 치킨집은 모두 폐업시켜야 한다. 어떻게 고르면, 도시의 치킨 거리가 가장 작게 될지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N(2 ≤ N ≤ 50)과 M(1 ≤ M ≤ 13)이 주어진다.

둘째 줄부터 N개의 줄에는 도시의 정보가 주어진다.

도시의 정보는 0, 1, 2로 이루어져 있고, 0은 빈 칸, 1은 집, 2는 치킨집을 의미한다. 집의 개수는 2N개를 넘지 않으며, 적어도 1개는 존재한다. 치킨집의 개수는 M보다 크거나 같고, 13보다 작거나 같다.

출력
첫째 줄에 폐업시키지 않을 치킨집을 최대 M개를 골랐을 때, 도시의 치킨 거리의 최솟값을 출력한다.

풀이:
각 치킨 집에서의 각 집까지의 거리를 모두 구합니다(최대 13 * 100)

치킨 집을 최대 m개 골라야 하는데, 사실 최대라는 말은 상관없기 때문에 모든 치킨 집들 중에서 m개를 순서에 상관없이 뽑으면 됩니다.

순서를 고려했을 때와 고려하지 않았을 때 시간차이 주의!
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

int n, m;
int maps[51][51];
int ch_to_home[13][100];
vector<pair<pii, bool>> chicken;
vector<pair<pii, int>> home;
int minLeng = IMAX;

int getDis(pii x1, pii x2) {
	return abs(x1.first - x2.first) + abs(x1.second - x2.second);
}

int getChicken() {

	int all_chicken = 0;

	for (int i = 0; i < chicken.size(); i++)
	{
		if (chicken[i].second) {
			for (int j = 0; j < home.size(); j++)
			{
				home[j].second = min(home[j].second, ch_to_home[i][j]);
			}
		}
	}

	for (int i = 0; i < home.size(); i++)
	{
		all_chicken += home[i].second;
		home[i].second = IMAX;
	}

	return all_chicken;
}

void recul(int idx, int cnt) {

	if (cnt == m) {
		int minAllChicken = getChicken();

		if (minAllChicken < minLeng) {
			minLeng = minAllChicken;
		}
		return;
	}

	for (int i = idx + 1; i < chicken.size(); i++)
		//순서를 고려하지 않기 위해 이전에 뽑은 idx는 무시하고 다음부터 진행
	{
		chicken[i].second = true;
		recul(i, cnt + 1);
		chicken[i].second = false;
	}
}

int main(void) {
	FIO;

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> maps[i][j];
			if (maps[i][j] == 2)
				chicken.push_back(make_pair(make_pair(i, j), false));
			if (maps[i][j] == 1)
				home.push_back(make_pair(make_pair(i, j), IMAX));
		}
	}

	for (int i = 0; i < chicken.size(); i++)
	{
		for (int j = 0; j < home.size(); j++)
		{
			ch_to_home[i][j] = getDis(make_pair(chicken[i].first.first, chicken[i].first.second), make_pair(home[j].first.first, home[j].first.second));
		}
	}

	recul(-1, 0);

	cout << minLeng;
}