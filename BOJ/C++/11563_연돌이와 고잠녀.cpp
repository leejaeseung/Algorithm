/*
����
�����̿� ������ ��ġ�� �������� ģ�� ģ������. ������ �� ������ �߸��� �������� ���� ���� ������ ����� �Ǿ���. ���̿��� �Ⱦ����� �� �� ���� �����̴�. �̸� ���ϰ� ���� ���䱳��� ����� ���θ� �ϳ� �����ֱ�� �ߴ�. ������ �������� ������ ������ ���̴� ������ �� ª�ƾ� �Ѵ�.

2���� ��� ���� ���̿� ����� �������ε��� ������ �ȾϿ� ����� �������ε��� ������ �־�����. �����̴� ���� ���� ���ؼ��� �̵��� �� �ְ�, �� ���ΰ� ������ �������� ���θ� ����Ż �� �ִ�. ���̿��� �Ⱦ����� �� �� �ֵ��� ���� ��ġ�� ������ �ּ� ���̸� �˷�����.

�Է�
ù �ٿ��� ���̿� ����� ������ ���� n�� �ȾϿ� ����� ������ ���� m(1 �� n, m �� 2,000)�� �־�����.

�̾����� n�ٿ� ���� xs, ys, xe, ye�� �־�����. (-10,000 �� xs, ys, xe, ye �� 10,000) �̴� ���̿� ����� ������ �� ������ ��ǥ�� (xs, ys), (xe, ye)���� �ǹ��Ѵ�. �̾����� m�ٿ� ���� xs, ys, xe, ye�� �־�����. (-50,000 �� xs, ys, xe, ye �� 50,000) �̴� �ȾϿ� ����� ������ �� ������ ��ǥ�� (xs, ys), (xe, ye)���� �ǹ��Ѵ�. ��� ��ǥ�� �Ҽ��� �Ʒ� �ִ� 20�ڸ����� �־�����.

���̿� ����� ������ �� ���ο� ���� �� ���ο��� ����ؼ� �ٸ� ���ο� �����ϴ� ���� �����ϰ�, �ȾϿ� ����� ������ �� ���ο� ���ؼ��� ���������̴�. ���� ���θ� ���� ������ ���̿� ����� ���ο��� ����ؼ� �ȾϿ� ����� ���ο� ������ �� ����.

���
���̿��� �Ⱦ����� ���� ���� ���� ���ƾ� �ϴ� �ּ� ������ ���̸� ����Ѵ�.

���� ����� ���� Ȥ�� �������� 1e-6 �̸��̸� �������� �����Ѵ�.

Ǯ��:
�� ���� ������ �������� ��, ��� ������ �ּ� �Ÿ��� ���ؾ� �մϴ�.

���� �⺻������ �� -> �� �� �����Ͽ� �� 4������ �ּ� �Ÿ��� ���մϴ�.(�� ������ �ٸ� ������ ���θ� �մ� ���)
������ ���� -> ���� �����ؾ� �մϴ�.(�� ������ �ٸ� ������ ���� �ͺ��� ���п� ������ ���� ������ �� ���� ���)
�� ��, ������ ���п� ������ ���� ���� �� �ִ��� �Ǻ��ؾ� �մϴ�.
���а� ������ �̷���� �ﰢ���� �׷��� �� ���� �ﰢ���� �׷��� ���� ������ ���� ���� �� �ֽ��ϴ�.

�Ǻ��� ��, ���� -> �� ������ �� 4���� ��쿡 ���� ���� ���� ���� �Ÿ� ������ ����� �ݴϴ�.
���� ���� �ڵ�� �����ϴ°� ��ٷο��� ���������ϴ�.
������ �������� ���� �� 0���� ������ ��츦 �����մϴ�.
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