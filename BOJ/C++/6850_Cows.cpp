/*
문제
Your friend to the south is interested in building fences and turning plowshares into swords. In order to help with his overseas adventure, they are forced to save money on buying fence posts by using trees as fence posts wherever possible. Given the locations of some trees, you are to help farmers try to create the largest pasture that is possible. Not all the trees will need to be used.

However, because you will oversee the construction of the pasture yourself, all the farmers want to know is how many cows they can put in the pasture. It is well known that a cow needs at least 50 square metres of pasture to survive.

입력
The first line of input contains a single integer, n (1 ≤ n ≤ 10000), containing the number of trees that grow on the available land. The next n lines contain the integer coordinates of each tree given as two integers x and y separated by one space (where −1000 ≤ x, y ≤ 1000). The integer coordinates correlate exactly to distance in metres (e.g., the distance between coordinate (10, 11) and (11, 11) is one metre).

출력
You are to output a single integer value, the number of cows that can survive on the largest field you can construct using the available trees.

풀이:
볼록 껍질을 구하고, 만들어진 다각형의 넓이 / 50 을 하는 문제이다.

실수했던 부분 : 기준점의 좌표까지 포함시켜 반시계 방향으로 정렬했었다. 주의!
*/
#include<iostream>
#include<memory.h>
#include<algorithm>
#include<math.h>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
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
int mv1[4] = { 0, 0, 1, -1 };
int mv2[4] = { 1, -1, 0, 0 };
int mv_all1[8] = { 0, 1, 0, -1, -1, -1, 1, 1 };
int mv_all2[8] = { 1, 0, -1, 0 , -1, 1, -1, 1 };

int n;
vector<pii> point;
pii cp = make_pair(IMAX, IMAX);

int ccw(pii p1, pii p2, pii p3) {
	return (p1.first * p2.second + p2.first * p3.second + p3.first * p1.second) - (p1.second * p2.first + p2.second * p3.first + p3.second * p1.first);
}

bool comp(pii p1, pii p2) {
	if (ccw(cp, p1, p2) > 0)
		return true;
	return false;
}

int main(void) {
	FIO;

	cin >> n;

	int cp_idx = 0;

	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;

		point.push_back(make_pair(x, y));
		if (x < cp.first) {
			cp.first = x;
			cp.second = y;
			cp_idx = i;
		}
		else if (x == cp.first) {
			if (y < cp.second) {
				cp.first = x;
				cp.second = y;
				cp_idx = i;
			}
		}
	}

	pii temp = point[0];
	point[0] = cp;
	point[cp_idx] = temp;
	

	sort(point.begin() + 1, point.end(), comp);

	stack<pii> st;

	st.push(point[0]);
	st.push(point[1]);

	for (int i = 2; i < point.size(); i++)
	{
		pii next = point[i];

		if (st.size() < 2) {
			st.push(next);
			continue;
		}

		pii snd = st.top();	st.pop();
		pii fst = st.top();

		int s = ccw(fst, snd, next);

		if (s > 0) {
			//반시계 방향이면
			st.push(snd);
			st.push(next);

		}
		else {
			//시계 방향이면
			i--;
		}
	}

	cp = st.top();
	st.pop();

	double S = 0;

	while (st.size() > 1) {
		pii p1 = st.top();	st.pop();
		pii p2 = st.top();

		S += abs((double)ccw(cp, p1, p2)) / 2;
	}

	cout << (int)(S / 50) << "\n";
}