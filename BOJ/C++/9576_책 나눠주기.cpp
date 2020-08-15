/*
문제
백준이는 방 청소를 하면서 필요 없는 전공 서적을 사람들에게 나눠주려고 한다. 나눠줄 책을 모아보니 총 N권이었다. 책이 너무 많기 때문에 백준이는 책을 구분하기 위해 각각 1부터 N까지의 정수 번호를 중복되지 않게 매겨 두었다.

조사를 해 보니 책을 원하는 서강대학교 학부생이 총 M명이었다. 백준이는 이 M명에게 신청서에 두 정수 a, b (1 ≤ a ≤ b ≤ N)를 적어 내라고 했다. 그러면 백준이는 책 번호가 a 이상 b 이하인 책 중 남아있는 책 한 권을 골라 그 학생에게 준다. 만약 a번부터 b번까지의 모든 책을 이미 다른 학생에게 주고 없다면 그 학생에게는 책을 주지 않는다.

백준이가 책을 줄 수 있는 최대 학생 수를 구하시오.

입력
첫째 줄에 테스트 케이스의 수가 주어진다.

각 케이스의 첫 줄에 정수 N(1 ≤ N ≤ 1,000)과 M(1 ≤ M ≤ 1,000)이 주어진다. 다음 줄부터 M개의 줄에는 각각 정수 ai, bi가 주어진다. (1 ≤ ai ≤ bi ≤ N)

출력
각 테스트 케이스마다 백준이가 책을 줄 수 있는 최대 학생 수를 한 줄에 하나씩 출력한다.

풀이:
a ~ b 구간에 대해 b를 기준으로 오름차순 정렬하면 순서대로 작은 번호부터 책을 주게 되면
최대 값을 구할 수 있다.(a에 대해선 내림차순, 오름차순 상관 없음)

왜냐하면 최대 b 까지 받을 수 있기 때문에 어떤 구간 x ~ y 를 다 채웠다고 해도 그 다음 원소는 
y보다 항상 크거나 같은 값을 가지기 때문이다.(같다면 줄 수 없는 경우)
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

int n, m;

bool mySort(pii o1, pii o2) {
	if (o1.second == o2.second)
		return o1.first > o2.first;
	return o1.second < o2.second;
}

int main(void) {
	FIO;

	int t;
	cin >> t;

	while (t--) {
		cin >> n >> m;

		vector<pii> vt;
		bool check[1001];
		int ans = 0;

		for (int i = 0; i <= n; i++)
		{
			check[i] = false;
		}

		for (int i = 1; i <= m; i++)
		{
			int s, e;
			cin >> s >> e;
			
			vt.push_back(make_pair(s, e));
		}

		sort(vt.begin(), vt.end(), mySort);

		for (int i = 0; i < m; i++)
		{
			pii now = vt[i];

			for (int j = now.first; j <= now.second; j++)
			{
				if (!check[j]) {
					check[j] = true;
					ans++;
					break;
				}
			}
		}
		
		cout << ans << "\n";
	}
}