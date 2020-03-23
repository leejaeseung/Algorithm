/*
문제


영만이네 집은 너무 오래되어서 변기에 물이 줄줄 샌다. 보다 못한 영만이는 마침 집에 파이프가 남아 있어서 직접 배수 공사를 하려고 한다.

하지만 파이프를 자르는 비용이 너무나 비싸기 때문에, 가난한 영만이는 남은 파이프들을 적절히 모아서 원하는 길이로 만들어야 한다.

영만이가 가지고 있는 파이프의 길이와 그 수량을 알고 있을 때, 파이프를 적당히 합쳐서 x만큼의 길이를 만드는 방법의 수를 구하시오. 파이프를 합치는 순서는 고려하지 않는다.

입력
영만이가 가지고 있는 파이프의 종류의 수 N과 만들고 싶은 합친 파이프의 길이 x가 주어진다. (1 ≤ N ≤ 100 이며, 1 ≤ x ≤ 10 000 이다.)

다음 N개의 줄에 걸쳐서 파이프의 길이 Li 와 수량 Ci 이 공백을 사이에 두고 주어진다. 길이가 짧은 것부터 순서대로 입력되며, 0 < Li ≤ x, 0 < Ci ≤ 100 이다. 또한, 입력되는 파이프의 길이는 서로 다르다.

출력
합친 파이프의 길이 x를 만들 수 있는 방법의 수를 출력한다. 방법의 수가 2,147,483,647를 넘는 경우는 없다.

풀이:
https://onedaycoding.tistory.com/102
를 참고했습니다.

dp[i][j] 를 i번째 파이프까지 j 길이를 만드는 경우의 수로 생각합니다.
*/
#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<vector>
#include<cstring>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>

int N, x;
int dp[101][10001];
pii p[100];

int recul(int now, int leng) {

	if (leng == x)	return 1;
	if (leng > x)	return 0;
	if (now >= N)	return 0;
	

	int& ret = dp[now][leng];
	if (ret != -1)	return ret;

	ret = 0;
	for (int i = 0; i <= p[now].second; ++i)
	{
		ret += recul(now + 1, leng + p[now].first * i);
	}
	return ret;
}

int main(void) {
	FIO;

	cin >> N >> x;

	for (int i = 0; i < N; i++)
	{
		int L, C;

		cin >> L >> C;

		p[i] = make_pair(L, C);
	}
	memset(dp, -1, sizeof(int) * 101 * 10001);
	cout << recul(0, 0);
}