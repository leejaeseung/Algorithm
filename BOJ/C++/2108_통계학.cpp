/*
문제
수를 처리하는 것은 통계학에서 상당히 중요한 일이다. 통계학에서 N개의 수를 대표하는 기본 통계값에는 다음과 같은 것들이 있다. 단, N은 홀수라고 가정하자.

산술평균 : N개의 수들의 합을 N으로 나눈 값
중앙값 : N개의 수들을 증가하는 순서로 나열했을 경우 그 중앙에 위치하는 값
최빈값 : N개의 수들 중 가장 많이 나타나는 값
범위 : N개의 수들 중 최댓값과 최솟값의 차이
N개의 수가 주어졌을 때, 네 가지 기본 통계값을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 수의 개수 N(1 ≤ N ≤ 500,000)이 주어진다. 그 다음 N개의 줄에는 정수들이 주어진다. 입력되는 정수의 절댓값은 4,000을 넘지 않는다.

출력
첫째 줄에는 산술평균을 출력한다. 소수점 이하 첫째 자리에서 반올림한 값을 출력한다.

둘째 줄에는 중앙값을 출력한다.

셋째 줄에는 최빈값을 출력한다. 여러 개 있을 때에는 최빈값 중 두 번째로 작은 값을 출력한다.

넷째 줄에는 범위를 출력한다.

풀이:
하라는게 많은 문제..
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

int n;
priority_queue<int> pq;
int cnt[8003];

int main(void) {
	FIO;

	cin >> n;

	int sum = 0;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		sum += num;
		cnt[num + 4000]++;

		pq.push(num);
	}

	int maxV = pq.top();

	for (int i = 0; i < n / 2; i++)
	{
		pq.pop();
	}

	int mid = pq.top();

	while (pq.size() > 1) {
		pq.pop();
	}

	int minV = pq.top();	pq.pop();
	int maxCnt = 0;
	for (int i = 0; i < 8003; i++)
	{
		maxCnt = max(maxCnt, cnt[i]);
	}

	for (int i = 0; i < 8003; i++)
	{
		if (maxCnt == cnt[i]) {
			pq.push(-(i - 4000));
		}
	}

	int maxE = -pq.top();

	if (pq.size() > 1) {
		pq.pop();
		maxE = -pq.top();
	}

	int range = maxV - minV;
	double everage = (double)sum / (double)n;
	
	cout << round(everage) << "\n";
	cout << mid << "\n";
	cout << maxE << "\n";
	cout << range << "\n";
}