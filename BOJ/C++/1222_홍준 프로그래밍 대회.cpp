/*
문제
홍준이는 프로그래밍 대회를 개최했다. 이 대회는 사람들이 팀을 이루어서 참가해야 하며, 팀원의 수는 홍준이가 정해준다. 팀원이 홍준이가 정한 값보다 부족하다면, 그 팀은 대회에 참여할 수 없다. 모든 팀은 같은 수의 팀원으로 이루어져 있다.

대회에 참여 의사를 밝힌 학교는 총 N개이다. 각 학교는 모든 학생이 참여할 수 있는 경우에만 대회에 참가한다. 즉, 남는 사람 없이 모든 학생이 팀에 들어갈 수 있어야 한다.

대회는 예선과 본선으로 구성되어 있다. 모든 팀은 같은 학교 소속으로 이루어져 있어야 한다. 예선에서 각 학교 1등팀만 본선에 진출한다.

홍준이의 대회는 올해가 첫 해이기 때문에, 많은 관심이 필요하다. 따라서, 본선에 참가하는 사람의 수를 최대가 되도록 팀원의 수를 정하려고 한다. 또, 본선이 지루해지는 것을 막기 위해 적어도 두 팀이 본선에 참가할 수 있어야 한다.

홍준이가 팀원을 몇 명으로 정해야 본선에 참가하는 사람의 수가 최대가 되는지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 홍준이의 대회에 참여 의사를 밝힌 학교의 수 N (2 ≤ N ≤ 200,000)이 주어진다.

둘째 줄에는 각 학교 학생의 수가 주어진다. 학생의 수는 구간 [1, 2,000,000]에 포함된다.

출력
첫째 줄에 홍준이의 대회 본선에 참가하는 사람의 수의 최댓값을 출력한다.

풀이:
약수를 구하는 알고리즘을 최적화하여 풀이한다.

문제의 답은 (원소들의 공통된 약수) * (그 약수를 가진 원소의 개수) 중 최대인 값인데,
각 원소마다 약수를 선형으로 구하게 되면 200000 * 2000000 이 되어 시간이 초과된다.

원소 v의 루트까지만 약수를 구하는 최적화 알고리즘을 사용해 200000 * 루트(2000000) 으로 줄일 수 있다.
*/
#include<iostream>
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
int mv1[4] = { 0, 1, 0, -1 };
int mv2[4] = { 1, 0, -1, 0 };
int mv_all1[8] = { 0, 1, 0, -1, -1, -1, 1, 1 };
int mv_all2[8] = { 1, 0, -1, 0 , -1, 1, -1, 1 };

int n;
ll cnt[2000001];

int main(void) {
	FIO;

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		int v;
		cin >> v;

		for (int j = 1; j * j <= v; j++)
		{
			if (v % j == 0) {
				if (j * j != v) {
					cnt[j]++;
				}
				cnt[v / j]++;
			}
		}
	}

	ll ans = 0;

	for (ll i = 1; i <= 2000000 ; i++)
	{
		if (cnt[i] >= 2) {
			ans = max(ans, i * cnt[i]);
		}
	}
	cout << ans;
}