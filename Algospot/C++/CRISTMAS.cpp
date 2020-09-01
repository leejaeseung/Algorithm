/*
문제
크리스마스를 맞이하여 산타 할아버지는 전세계의 착한 어린이 K명에게 인형을 사주려고 한다. 산타 할아버지는 인형을 구입하기 위해서 유명한 인형가게인 "놀이터"에 찾아갔다. 놀이터에는 N개의 인형 상자가 한 줄로 진열되어 있고, 각 인형 상자에는 한 개 이상의 인형이 들어 있다. 그리고 놀이터에서는 주문의 편의성을 위해 각 상자에 번호를 붙여 놓았고, 주문은 "H번 상자부터 T번 상자까지 다 주세요."라고만 할 수 있다. (H ≤ T)

산타 할아버지는 한 번 주문할 때마다, 주문한 상자에 있는 인형들을 모두 꺼내서 각각을 K명에게 정확히 같은 수만큼 나누어 주고, 남는 인형이 없도록 한다.

한 번 주문할 수 있다면, 가능한 주문 방법은 몇 가지인가?
여러 번 주문할 수 있다면, 주문이 겹치지 않게 최대 몇 번 주문할 수 있는가? (주문이 겹친다는 것은 어떤 두 주문에 같은 번호의 인형 상자가 포함되는 것을 말한다.)
입력
첫 번째 줄에는 테스트 케이스의 개수 T가 주어진다. ( T ≤ 60 )

각 테스트 케이스의 첫 번째 줄에는 인형 상자의 개수 N과 어린이의 수 K가 주어진다.(1 ≤ N, K ≤ 100000)

두 번째 줄에는 1번 인형 상자부터 N번 인형 상자까지 각 인형 상자에 들어 있는 인형의 개수 Di가 주어진다. ( 1 ≤ i ≤ N, 1 ≤ Di ≤ 100000 )

출력
1번에 대한 답과 2번에 대한 답을 한 줄에 하나의 빈칸으로 나누어 출력한다. 1번 답은 매우 클 수 있으므로 20091101로 나눈 나머지를 출력한다.

풀이:
어떤 구간 i ~ j 에 대하여 i ~ j 가 k 로 나누어 떨어지는지 여부를 구하기 위해
sum[j] MOD k == sum[i - 1] MOD k 를 이용한다.
즉, sum 배열을 모두 mod k 했을 때, 같은 수가 2개 이상 있다면, 그 수들을 
중복을 허용하지 않고 2개씩 뽑는 경우의 수를 구하고, 모두 더하면 된다.(1번)

2번은 dp로 해결 가능하다.
어떤 지점 x 에서의 sum 값을(mod k 한) 최근에 보았다면(해당 지점 = i - 1)
sum[j] MOD k == sum[i - 1] MOD k 에 의해 i - 1 까지 끊은 뒤, i ~ x 까지 다시 합칠 수 있다.
따라서 dp[x - 1] 와 dp[이전 지점] + 1 중 최댓 값을 dp[x] 에 저장한다.

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
#define MOD 20091101
int mv1[4] = { 0, 0, 1, -1 };
int mv2[4] = { 1, -1, 0, 0 };
int mv_all1[8] = { 0, 1, 0, -1, -1, -1, 1, 1 };
int mv_all2[8] = { 1, 0, -1, 0 , -1, 1, -1, 1 };

int t, n, k;
int sum[100001];
ll counts[100001];
int dp[100001];
int prv[100001];

int main(void) {
	FIO;

	cin >> t;

	while (t--) {
		cin >> n >> k;

		ll ans = 0;

		for (int i = 0; i < 100001; i++)
		{
			prv[i] = -1;
			counts[i] = 0;
			dp[i] = 0;
			sum[i] = 0;
		}

		for (int i = 1; i <= n; i++)
		{
			int v;
			cin >> v;
			sum[i] = (sum[i - 1] +  v) % k;
			counts[sum[i]]++;
		}

		counts[0]++;

		for (int i = 0; i < k; i++)
		{
			if (counts[i] >= 2)
				ans = ((ans % MOD) + (counts[i] * (counts[i] - 1) / 2) % MOD) % MOD;
		}

		for (int i = 0; i <= n; i++)
		{
			//i 가 0부터 시작하는 이유 = 맨 처음부터 자르는 경우를 생각하기 위해
			if (i == 0)
				dp[i] = 0;
			else
				dp[i] = dp[i - 1];

			if (prv[sum[i]] != -1)
				dp[i] = max(dp[i], dp[prv[sum[i]]] + 1);

			prv[sum[i]] = i;
		}

		cout << ans << " " << dp[n] << "\n";
	}
}