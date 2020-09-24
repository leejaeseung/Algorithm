/*
문제
Farmer John has opened a swimming pool for his cows, figuring it will help them relax and produce more milk.

To ensure safety, he hires  cows as lifeguards, each of which has a shift that covers some contiguous interval of time during the day. For simplicity, the pool is open from time  until time  on a daily basis, so each shift can be described by two integers, giving the time at which a cow starts and ends her shift. For example, a lifeguard starting at time  and ending at time  covers three units of time (note that the endpoints are "points" in time).

Unfortunately, Farmer John hired 1 more lifeguard than he has the funds to support. Given that he must fire exactly one lifeguard, what is the maximum amount of time that can still be covered by the shifts of the remaining lifeguards? An interval of time is covered if at least one lifeguard is present.

입력
The first line of input contains  (). Each of the next  lines describes a lifeguard in terms of two integers in the range , giving the starting and ending point of a lifeguard's shift. All such endpoints are distinct. Shifts of different lifeguards might overlap.

출력
Please write a single number, giving the maximum amount of time that can still be covered if Farmer John fires 1 lifeguard.

풀이:
여러 선들이 주어지는데, 단 하나의 선만 제거했을 때 선들이 겹치는 길이를 최대화하는 문제이다.

선이 겹치는 부분(fixLine) 과 겹치지 않는 자신만의 구간의 길이(line)을 구해주어야 한다.
겹치는 부분들을 스위핑하여 총 길이를 구하고, 자신만의 길이 중 가장 작은 값을 제외하고 더해주면 답이 된다.

시작점과 끝 점을 오름차순 정렬하여 스위핑한다.

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

int main(void) {
	FIO;

	cin >> n;

	priority_queue<pll> pq;
	priority_queue<ll> line;
	priority_queue<pll> fixLine;

	for (int i = 0; i < n; i++)
	{
		ll s, e;
		cin >> s >> e;
		pq.push({ -s, -e });
	}

	ll maxE = -pq.top().second;	
	//현재 보고 있는 가장 끝 점

	ll end = -pq.top().first;
	//겹쳐질 수 있는 가장 끝 점
	pq.pop();

	while (!pq.empty())
	{
		ll nowS = -pq.top().first;
		ll nowE = -pq.top().second;
		pq.pop();

		if (nowS >= maxE) {
			//지금까지의 선분과 새로운 선분이 겹치는 구간이 존재하지 않는다. 
			//end ~ maxE = 지금까지 선분 중 겹치지 않는 가장 오른쪽 선분
			
			line.push(-(maxE - end));

			end = nowS;
			maxE = nowE;
		}
		else {
			if (end <= nowS) {
				//새로운 선분과 마지막 겹친 곳의 중간 부분 = 어느 선분과도 겹치지 않는다.
				line.push(-(nowS - end));
			}

			if (maxE <= nowE) {
				//새로운 선분의 끝 점이 maxE를 넘어가면 새로운 선분의 시작 ~ 기존 maxE 까지 겹친다.
				end = maxE;
				maxE = nowE;

				fixLine.push({ -nowS, -end });
			}
			else if(nowE >= end){
				//새로운 선분의 끝 점이 maxE보다 작지만 end 보다 크다면 새로운 선분은 모두 현재 선분에 포함된다.
				//이 새로운 선분을 제거하는게 가장 이득이므로 line에 0을 추가한다.
				line.push(0);
				fixLine.push({ -nowS, -nowE });
				end = nowE;
			}
		}
	}

	line.push(-(maxE - end));

	ll s = 0;
	ll e = 0;
	ll ans = 0;

	//기본적인 라인 스위핑으로 겹치는 구간의 총 길이를 구한다.
	while (!fixLine.empty()) {
		ll nowS = -fixLine.top().first;
		ll nowE = -fixLine.top().second;
		fixLine.pop();

		if (s <= nowS && e >= nowS && e <= nowE) {
			e = nowE;
		}
		else if (e <= nowS) {
			ans += e - s;

			s = nowS;
			e = nowE;
		}
	}

	ans += e - s;

	//가장 짧은 선분 제거
	line.pop();

	while (!line.empty()) {
		ans -= line.top();
		line.pop();
	}

	cout << ans;

}