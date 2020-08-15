/*
문제
기숙사에서 살고 있는 준규는 한 개의 멀티탭을 이용하고 있다. 준규는 키보드, 헤어드라이기, 핸드폰 충전기, 디지털 카메라 충전기 등 여러 개의 전기용품을 사용하면서 어쩔 수 없이 각종 전기용품의 플러그를 뺐다 꽂았다 하는 불편함을 겪고 있다. 그래서 준규는 자신의 생활 패턴을 분석하여, 자기가 사용하고 있는 전기용품의 사용순서를 알아내었고, 이를 기반으로 플러그를 빼는 횟수를 최소화하는 방법을 고안하여 보다 쾌적한 생활환경을 만들려고 한다.

예를 들어 3 구(구멍이 세 개 달린) 멀티탭을 쓸 때, 전기용품의 사용 순서가 아래와 같이 주어진다면,

키보드
헤어드라이기
핸드폰 충전기
디지털 카메라 충전기
키보드
헤어드라이기
키보드, 헤어드라이기, 핸드폰 충전기의 플러그를 순서대로 멀티탭에 꽂은 다음 디지털 카메라 충전기 플러그를 꽂기 전에 핸드폰충전기 플러그를 빼는 것이 최적일 것이므로 플러그는 한 번만 빼면 된다.

입력
첫 줄에는 멀티탭 구멍의 개수 N (1 ≤ N ≤ 100)과 전기 용품의 총 사용횟수 K (1 ≤ K ≤ 100)가 정수로 주어진다. 두 번째 줄에는 전기용품의 이름이 K 이하의 자연수로 사용 순서대로 주어진다. 각 줄의 모든 정수 사이는 공백문자로 구분되어 있다.

출력
하나씩 플러그를 빼는 최소의 횟수를 출력하시오.

풀이:
1. 콘센트가 꽉 찰 때까지 모두 꽂는다.
2. 콘센트가 꽉 찬 경우
2-1. 이후에 쓰이지 않는 콘센트 중 아무거나 하나 뽑는다.
2-2. 꼽힌 콘센트 중 다음에 가장 늦게 나타나는 콘센트를 뽑는다.
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

int n, k;
bool check[101];
int cnts[101];
vector<int> order;

int main(void) {
	FIO;

	cin >> n >> k;

	for (int i = 0; i < k; i++)
	{
		int o;
		cin >> o;

		cnts[o]++;
		order.push_back(o);
	}

	vector<int> use;

	int ans = 0;

	for (int i = 0; i < k; i++)
	{
		int now = order[i];
		cnts[now]--;

		if (!check[now]) {
			check[now] = true;

			if (use.size() == n) {

				int maxCnt = -1;
				int out = 0;

				for (int j = 0; j < n; j++)
				{
					int comp = use[j];

					if (cnts[comp] == 0) {
						//다음에 나타나지 않을 시
						out = j;
						break;
					}

					int cnt = 0;

					for (int l = i + 1; l < k; l++)
					{
						if (comp == order[l]) {
							break;
						}
						cnt++;
					}

					if (maxCnt < cnt) {
						//가장 늦게(cnt가 가장 큰) 나타나는 콘센트를 뽑는다.
						maxCnt = cnt;
						out = j;
					}
				}

				check[use[out]] = false;
				use[out] = now;
				ans++;
			}
			else {
				use.push_back(now);
			}
		}
	}

	cout << ans;
}