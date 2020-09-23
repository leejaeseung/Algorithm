/*
문제
N개의 직사각형 모양의 건물들이 주어졌을 때, 스카이라인을 구해내는 프로그램을 작성하시오. 스카이라인은 건물 전체의 윤곽을 의미한다. 즉, 각각의 건물을 직사각형으로 표현했을 때, 그러한 직사각형들의 합집합을 구하는 문제이다.



예를 들어 직사각형 모양의 건물들이 위와 같이 주어졌다고 하자. 각각의 건물은 왼쪽 x좌표와 오른쪽 x좌표, 그리고 높이로 나타난다. 모든 건물들은 편의상 같은 높이의 지면(땅) 위에 있다고 가정하자. 위의 예에서 스카이라인을 구하면 아래와 같다.



입력
첫째 줄에 건물의 개수 N(1 ≤ N ≤ 100,000)이 주어진다. 다음 N개의 줄에는 N개의 건물에 대한 정보가 주어진다. 건물에 대한 정보는 세 정수 L, H, R로 나타나는데, 각각 건물의 왼쪽 x좌표, 높이, 오른쪽 x좌표를 의미한다. (1 ≤ L < R ≤ 1,000,000,000, 1 ≤ H ≤ 1,000,000,000)

출력
첫째 줄에 스카이라인을 출력한다. 출력을 할 때에는 높이가 변하는 지점에 대해서, 그 지점의 x좌표와 그 지점에서의 높이를 출력한다.

풀이:
https://www.crocus.co.kr/1248
위 블로그를 참고함.
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
map<int, int> ans;
map<pii, int, greater<>> hm;
vector<pair<pii, pii>> vt;

int main(void) {
	FIO;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int left, h, right;
		cin >> left >> h >> right;

		
		vt.push_back({ {left, h}, {right, 1} });
		vt.push_back({ {right, h}, {left, 0} });
	}

	sort(vt.begin(), vt.end());

	int prv = -1;
	hm[{0, 0}] = 0;

	for (int i = 0; i < vt.size(); i++)
	{
		int nowP = vt[i].first.first;
		int nowH = vt[i].first.second;
		int otherP = vt[i].second.first;
		int isStart = vt[i].second.second;

		if (isStart) {
			hm[{nowH, nowP}] = otherP;
		}
		else {
			hm.erase(hm.find({ nowH, otherP }));
		}

		auto maxH = hm.begin();

		if (maxH->first.first != prv) {
			prv = maxH->first.first;

			if (isStart) {
				ans[nowP] = max(ans[nowP], prv);
			}
			else {
				if (ans.count(nowP) == 0)
					ans[nowP] = prv;
				else
					ans[nowP] = min(ans[nowP], prv);
			}
		}
	}

	prv = -1;
	for (auto iter = ans.begin(); iter != ans.end(); iter++)
	{
		if (iter->second != prv)
			cout << iter->first << " " << iter->second << " ";
		prv = iter->second;
	}
}