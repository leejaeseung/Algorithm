/*
����
Farmer John has opened a swimming pool for his cows, figuring it will help them relax and produce more milk.

To ensure safety, he hires  cows as lifeguards, each of which has a shift that covers some contiguous interval of time during the day. For simplicity, the pool is open from time  until time  on a daily basis, so each shift can be described by two integers, giving the time at which a cow starts and ends her shift. For example, a lifeguard starting at time  and ending at time  covers three units of time (note that the endpoints are "points" in time).

Unfortunately, Farmer John hired 1 more lifeguard than he has the funds to support. Given that he must fire exactly one lifeguard, what is the maximum amount of time that can still be covered by the shifts of the remaining lifeguards? An interval of time is covered if at least one lifeguard is present.

�Է�
The first line of input contains  (). Each of the next  lines describes a lifeguard in terms of two integers in the range , giving the starting and ending point of a lifeguard's shift. All such endpoints are distinct. Shifts of different lifeguards might overlap.

���
Please write a single number, giving the maximum amount of time that can still be covered if Farmer John fires 1 lifeguard.

Ǯ��:
���� ������ �־����µ�, �� �ϳ��� ���� �������� �� ������ ��ġ�� ���̸� �ִ�ȭ�ϴ� �����̴�.

���� ��ġ�� �κ�(fixLine) �� ��ġ�� �ʴ� �ڽŸ��� ������ ����(line)�� �����־�� �Ѵ�.
��ġ�� �κе��� �������Ͽ� �� ���̸� ���ϰ�, �ڽŸ��� ���� �� ���� ���� ���� �����ϰ� �����ָ� ���� �ȴ�.

�������� �� ���� �������� �����Ͽ� �������Ѵ�.

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
	//���� ���� �ִ� ���� �� ��

	ll end = -pq.top().first;
	//������ �� �ִ� ���� �� ��
	pq.pop();

	while (!pq.empty())
	{
		ll nowS = -pq.top().first;
		ll nowE = -pq.top().second;
		pq.pop();

		if (nowS >= maxE) {
			//���ݱ����� ���а� ���ο� ������ ��ġ�� ������ �������� �ʴ´�. 
			//end ~ maxE = ���ݱ��� ���� �� ��ġ�� �ʴ� ���� ������ ����
			
			line.push(-(maxE - end));

			end = nowS;
			maxE = nowE;
		}
		else {
			if (end <= nowS) {
				//���ο� ���а� ������ ��ģ ���� �߰� �κ� = ��� ���а��� ��ġ�� �ʴ´�.
				line.push(-(nowS - end));
			}

			if (maxE <= nowE) {
				//���ο� ������ �� ���� maxE�� �Ѿ�� ���ο� ������ ���� ~ ���� maxE ���� ��ģ��.
				end = maxE;
				maxE = nowE;

				fixLine.push({ -nowS, -end });
			}
			else if(nowE >= end){
				//���ο� ������ �� ���� maxE���� ������ end ���� ũ�ٸ� ���ο� ������ ��� ���� ���п� ���Եȴ�.
				//�� ���ο� ������ �����ϴ°� ���� �̵��̹Ƿ� line�� 0�� �߰��Ѵ�.
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

	//�⺻���� ���� ���������� ��ġ�� ������ �� ���̸� ���Ѵ�.
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

	//���� ª�� ���� ����
	line.pop();

	while (!line.empty()) {
		ans -= line.top();
		line.pop();
	}

	cout << ans;

}