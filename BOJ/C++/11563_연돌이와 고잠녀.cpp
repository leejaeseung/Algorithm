/*
문제
연돌이와 고잠녀는 유치원 시절부터 친한 친구였다. 하지만 한 순간의 잘못된 선택으로 인해 서로 만나기 힘들게 되었다. 신촌에서 안암으로 갈 수 없기 때문이다. 이를 딱하게 여긴 국토교통부 장관은 도로를 하나 놓아주기로 했다. 하지만 재정상의 문제로 도로의 길이는 가능한 한 짧아야 한다.

2차원 평면 위에 신촌에 연결된 직선도로들의 정보와 안암에 연결된 직선도로들의 정보가 주어진다. 연돌이는 도로 위를 통해서만 이동할 수 있고, 두 도로가 만나는 지점에서 도로를 갈아탈 수 있다. 신촌에서 안암으로 갈 수 있도록 새로 설치할 도로의 최소 길이를 알려주자.

입력
첫 줄에는 신촌에 연결된 도로의 개수 n과 안암에 연결된 도로의 개수 m(1 ≤ n, m ≤ 2,000)이 주어진다.

이어지는 n줄에 걸쳐 xs, ys, xe, ye가 주어진다. (-10,000 ≤ xs, ys, xe, ye ≤ 10,000) 이는 신촌에 연결된 도로의 양 끝점의 좌표가 (xs, ys), (xe, ye)임을 의미한다. 이어지는 m줄에 걸쳐 xs, ys, xe, ye가 주어진다. (-50,000 ≤ xs, ys, xe, ye ≤ 50,000) 이는 안암에 연결된 도로의 양 끝점의 좌표가 (xs, ys), (xe, ye)임을 의미한다. 모든 좌표는 소수점 아래 최대 20자리까지 주어진다.

신촌에 연결된 임의의 두 도로에 대해 한 도로에서 출발해서 다른 도로에 도착하는 것이 가능하고, 안암에 연결된 임의의 두 도로에 대해서도 마찬가지이다. 새로 도로를 놓기 전에는 신촌에 연결된 도로에서 출발해서 안암에 연결된 도로에 도착할 수 없다.

출력
신촌에서 안암으로 가기 위해 새로 놓아야 하는 최소 도로의 길이를 출력한다.

실제 답과의 절대 혹은 상대오차가 1e-6 미만이면 정답으로 인정한다.

풀이:
두 개의 선분을 선택했을 때, 모든 가능한 최소 거리를 구해야 합니다.

먼저 기본적으로 점 -> 점 만 생각하여 총 4가지의 최소 거리를 구합니다.(한 점에서 다른 점으로 도로를 잇는 경우)
다음은 선분 -> 점을 생각해야 합니다.(한 점에서 다른 점으로 가는 것보다 선분에 수선의 발을 내리는 게 빠른 경우)
이 때, 점에서 선분에 수선의 발을 내릴 수 있는지 판별해야 합니다.
선분과 점으로 이루어진 삼각형을 그렸을 때 예각 삼각형이 그려질 때만 수선의 발을 내릴 수 있습니다.

판별한 후, 선분 -> 점 각각의 총 4가지 경우에 대해 점과 선분 사이 거리 공식을 사용해 줍니다.
수학 식을 코드로 구현하는게 까다로웠던 문제였습니다.
직선의 방정식을 구할 때 0으로 나누는 경우를 주의합니다.
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
#define vii vector<pii>
#define IMAX 2000000001
#define LMAX 100000000000000
#define DMAX 0xFFFFFFFFFFFFF
int mv1[4] = { 0, 0, 1, -1 };
int mv2[4] = { 1, -1, 0, 0 };

int n, m;
vector<pair<pdd, pdd>> yeon;
vector<pair<pdd, pdd>> go;
double minV = DMAX;

double getDist2(pdd p, double a, double b) {
	return abs(-a * p.first + p.second - b) / sqrt(pow(a, 2) + 1);
}

bool check(double leng1, double leng2, double leng_ori) {
	if (pow(leng_ori, 2) + pow(min(leng2, leng1), 2) > pow(max(leng2, leng1), 2))
		return true;
	else
		return false;
}

double getDist(pdd p1, pdd p2) {
	return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}

int main(void) {
	FIO;

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		double x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		yeon.push_back(make_pair(make_pair(x1, y1), make_pair(x2, y2)));
	}
	for (int i = 0; i < m; i++)
	{
		double x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		go.push_back(make_pair(make_pair(x1, y1), make_pair(x2, y2)));
	}

	for (int i = 0; i < n; i++)
	{
		pdd yp1 = yeon[i].first;
		pdd yp2 = yeon[i].second;

		double ya, yb;
		bool yflag = false;
		
		if (yp2.first - yp1.first == 0)
			yflag = true;
		else {
			if (yp2.second - yp1.second == 0)
				ya = 0;
			else
				ya = (yp2.second - yp1.second) / (yp2.first - yp1.first);
		}
		if (!yflag) {
			yb = yp1.second - yp1.first * ya;
		}

		for (int j = 0; j < m; j++)
		{
			pdd gp1 = go[j].first;
			pdd gp2 = go[j].second;

			double ga, gb;
			bool gflag = false;

			if (gp2.first - gp1.first == 0)
				gflag = true;
			else {
				if (gp2.second - gp1.second == 0)
					ga = 0;
				else
					ga = (gp2.second - gp1.second) / (gp2.first - gp1.first);
			}
			if (!gflag) {
				gb = gp1.second - gp1.first * ga;
			}

			if (check(getDist(gp1, yp1), getDist(gp1, yp2), getDist(yp1, yp2))) {
				if (yflag) {
					minV = min(minV, abs(gp1.first));
				}
				else {
					minV = min(minV, getDist2(gp1, ya, yb));
				}
			}

			if (check(getDist(gp2, yp1), getDist(gp2, yp2), getDist(yp1, yp2))) {
				if (yflag) {
					minV = min(minV, abs(gp2.first));
				}
				else {
					minV = min(minV, getDist2(gp2, ya, yb));
				}
			}

			if (check(getDist(yp1, gp1), getDist(yp1, gp2), getDist(gp1, gp2))) {
				if (gflag) {
					minV = min(minV, abs(yp1.first));
				}
				else {
					minV = min(minV, getDist2(yp1, ga, gb));
				}
			}

			if (check(getDist(yp2, gp1), getDist(yp2, gp2), getDist(gp1, gp2))) {
				if (gflag) {
					minV = min(minV, abs(yp2.first));
				}
				else {
					minV = min(minV, getDist2(yp2, ga, gb));
				}
			}

			minV = min(minV, min(min(min(getDist(yp1, gp1), getDist(yp1, gp2)), getDist(yp2, gp1)), getDist(yp2, gp2)));
		}
	}
	cout.precision(16);
	cout << minV;
}