/*
문제
2차원 평면상에 N(3 ≤ N ≤ 10,000)개의 점으로 이루어진 다각형이 있다. 이 다각형의 면적을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N이 주어진다. 다음 N개의 줄에는 다각형을 이루는 순서대로 N개의 점의 x, y좌표가 주어진다. 좌표값은 절댓값이 100,000을 넘지 않는 정수이다.

출력
첫째 줄에 면적을 출력한다. 면적을 출력할 때에는 소수점 아래 둘째 자리에서 반올림하여 첫째 자리까지 출력한다.

풀이:
CCW를 이용한 문제로, 한 점을 잡고 다각형을 이루는 순서대로 두 개의 점을 바꿔가며 
삼각형의 넓이를 구해 더해줍니다.
이때, CCW를 이용한 넓이는 평행사변형의 넓이이므로 / 2 를 해주는데 넓이 가 홀수일 시
0.5 를 더해주어야 합니다.
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
#define ll long long
#define pll pair<ll, ll>

double getS(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
	ll S = ((x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1));
	if (S % 2 == 0)	return (double)(S / 2);
	return (double)(S / 2) + 0.5;
}

int main(void) {
	FIO;

	int N;
	cin >> N;

	vector < pll> vt;

	for (int i = 0; i < N; i++)
	{
		ll x, y;
		cin >> x >> y;
		vt.push_back(make_pair(x, y));
	}
	
	pll s = vt[0];

	double ans = 0;

	for (int i = 1; i < N - 1; i++)
	{
			pll m = vt[i];
			pll e = vt[i + 1];
			ans += getS(s.first, s.second, m.first, m.second, e.first, e.second);
	}

	printf("%.1lf", abs(ans));
}