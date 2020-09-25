/*
문제
오늘은 공주님이 태어난 경사스러운 날이다. 왕은 이 날을 기념하기 위해 늘 꽃이 피어있는 작은 정원을 만들기로 결정했다.

총 N개의 꽃이 있는 데, 꽃은 모두 같은 해에 피어서 같은 해에 진다. 하나의 꽃은 피는 날과 지는 날이 정해져 있다. 예를 들어, 5월 8일 피어서 6월 13일 지는 꽃은 5월 8일부터 6월 12일까지는 꽃이 피어 있고, 6월 13일을 포함하여 이후로는 꽃을 볼 수 없다는 의미이다. (올해는 4, 6, 9, 11월은 30일까지 있고, 1, 3, 5, 7, 8, 10, 12월은 31일까지 있으며, 2월은 28일까지만 있다.)

이러한 N개의 꽃들 중에서 다음의 두 조건을 만족하는 꽃들을 선택하고 싶다.

공주가 가장 좋아하는 계절인 3월 1일부터 11월 30일까지 매일 꽃이 한 가지 이상 피어 있도록 한다.
정원이 넓지 않으므로 정원에 심는 꽃들의 수를 가능한 적게 한다.
N개의 꽃들 중에서 위의 두 조건을 만족하는, 즉 3월 1일부터 11월 30일까지 매일 꽃이 한 가지 이상 피어 있도록 꽃들을 선택할 때, 선택한 꽃들의 최소 개수를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에는 꽃들의 총 개수 N (1<=N<=100,000)이 주어진다. 다음 N개의 줄에는 각 꽃이 피는 날짜와 지는 날짜가 주어진다. 하나의 날짜는 월과 일을 나타내는 두 숫자로 표현된다. 예를 들어서, 3 8 7 31은 꽃이 3월 8일에 피어서 7월 31일에 진다는 것을 나타낸다.

출력
첫째 줄에 선택한 꽃들의 최소 개수를 출력한다. 만약 두 조건을 만족하는 꽃들을 선택할 수 없다면 0을 출력한다.

풀이:
먼저, 월과 일로 주어지는 시작, 끝 점을 1 ~ 365 사이의 수로 전처리하는 과정이 필요하다.
각 점들을 직선 상의 선분들로 나타낸 뒤 시작점의 오름차순, 끝점의 내림차순으로 정렬해 스위핑한다.

end 점 : 현재까지 심은 꽃의 마지막 좌표
maxE 점 : end 점과 새로운 선분을 이을 때 가장 멀리 갈 수 있는 끝점 좌표

maxE 보다 새로운 선분의 시작 점이 크다면 선분은 중간에 끊어지게 되므로 카운트 0이 되고, 종료한다.(시작점에 대해 정렬되어 있으므로)
아니라면 현재 선분과 새로운 선분을 이을 수 있다. 다음과 같이 진행한다.

- end 보다 새로운 선분의 시작 점이 크다면 -> 새로운 선분을 이어야 한다.(카운트 1증가)
- 새로운 선분의 끝 점과 maxE를 비교해 maxE를 계속 갱신한다.
- maxE 가 11월 30일을 넘어가게 되면 그 선분과 바로 이으면 되므로 카운트 1을 증가시키고 종료한다.
(끝점에 대해 내림차순이므로 다음 선분은 더 짧다)
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
#define pll pair<ll, ll>
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vii vector<pii>
#define IMAX 2000000001
#define LMAX 1000000000000000000
#define DMAX 0xFFFFFFFFFFFFF
#define MOD 100003
int mv1[4] = { 0, 1, 0, -1 };
int mv2[4] = { 1, 0, -1, 0 };
int mv_all1[8] = { 0, 1, 0, -1, -1, -1, 1, 1 };
int mv_all2[8] = { 1, 0, -1, 0 , -1, 1, -1, 1 };

int n;
int mth[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
vector<pii> fw;
int ps = 60;  //3월1일
int pe = 335; //12월1일

pii toDay(int monthS, int dayS, int monthE, int dayE) {
	int s = dayS;
	int e = dayE;

	for (int i = 1; i < monthS; i++)
	{
		s += mth[i];
	}

	for (int i = 1; i < monthE; i++)
	{
		e += mth[i];
	}

	return { s , -e };
}

int main(void) {
	FIO;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int sm, sd, em, ed;
		cin >> sm >> sd >> em >> ed;
		
		fw.push_back(toDay(sm, sd, em, ed));
	}

	sort(fw.begin(), fw.end());

	int maxE = ps;
	int e = ps;
	int cnt = 0;

	for (int i = 0; i < n; i++)
	{
		int nowS = fw[i].first;
		int nowE = -fw[i].second;

		if (nowS > maxE) {
			cnt = 0;
			break;
		}
		else {

			if (nowS > e) {
				cnt++;
				e = maxE;
			}
			
			if (nowE > maxE) {
				maxE = nowE;
			}

			if (maxE >= pe) {
				cnt++;
				break;
			}

		}
	}

	if (maxE < pe)
		cnt = 0;

	cout << cnt;
}