/*
문제
n개의 정수로 이루어진 임의의 수열이 주어진다. 우리는 이 중 연속된 몇 개의 수를 선택해서 구할 수 있는 합 중 가장 큰 합을 구하려고 한다. 단, 수는 한 개 이상 선택해야 한다. 또, 수열에서 수를 하나 제거할 수 있다. (제거하지 않아도 된다)

예를 들어서 10, -4, 3, 1, 5, 6, -35, 12, 21, -1 이라는 수열이 주어졌다고 하자. 여기서 수를 제거하지 않았을 때의 정답은 12+21인 33이 정답이 된다.

만약, -35를 제거한다면, 수열은 10, -4, 3, 1, 5, 6, 12, 21, -1이 되고, 여기서 정답은 10-4+3+1+5+6+12+21인 54가 된다.

입력
첫째 줄에 정수 n(1 ≤ n ≤ 100,000)이 주어지고 둘째 줄에는 n개의 정수로 이루어진 수열이 주어진다. 수는 -1,000보다 크거나 같고, 1,000보다 작거나 같은 정수이다.

출력
첫째 줄에 답을 출력한다.

풀이:
왼쪽, 오른쪽에서부터 누적합을 모두 구하는데
i 까지의 누적합이 음수고 i가 양수라면 i부터 누적합이 다시 시작하게끔 한다.

매번 누적합을 구할 때마다 현재까지의 누적합 or 현재 값의 최댓값을 계속 저장한다.(안 뺐을 때의 최댓값)

누적합을 모두 구한 뒤 수열 중 음수만 빼보고, 양쪽의 해당 index의 누적합의 합 + (뺀 수 * -2)(중복으로 2번 빼졌으므로)
의 최댓값을 구한다.

단, n == 1 일 때 적어도 하난 골라야 하므로 예외처리 해준다.
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

int n;
vector<int> vt;
int leftMax[100001];
int rightMax[100001];

int main(void) {
	FIO;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int v;
		cin >> v;
		vt.push_back(v);
	}

	int maxV = -IMAX;
	int sum = 0;

	int lm = -IMAX;
	int rm = -IMAX;

	for (int i = 0; i < n; i++)
	{
		int now = vt[i];

		sum += now;
		maxV = sum;

		if (sum - now < 0) {
			if (now >= 0) {
				maxV = now;
				sum = now;
			}
		}

		//왼쪽 누적합 갱신
		leftMax[i] = maxV;
		lm = max(lm, max(maxV, now));
	}
		
	maxV = -IMAX;
	sum = 0;

	for (int i = n - 1; i >= 0; i--)
	{
		int now = vt[i];

		sum += now;
		maxV = sum;

		if (sum - now < 0) {
			if (now >= 0) {
				maxV = now;
				sum = now;
			}
		}

		//오른쪽 누적합 갱신
		rightMax[i] = maxV;
		rm = max(rm, max(maxV, now));
	}

	int ans = -IMAX;

	ans = max(lm, rm);

	if (n > 1) {
		//적어도 하난 선택한다.
		for (int i = 0; i < n; i++)
		{
			int now = vt[i];

			if (now < 0)
				ans = max(ans, leftMax[i] + rightMax[i] + abs(now) * 2);
		}
	}

	cout << ans;
}