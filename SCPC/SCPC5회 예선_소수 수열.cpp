/*
수학과 프로그래밍을 좋아하는 A와 B 두 사람이 다음과 같은 게임을 하고 있다.
둘은 각각 1 이상  30,000 미만의 수 하나를 고른다.
이 수를 가지고 점수를 계산하여 큰 쪽이 이기는 게임이다.
어떤 수의 점수는, 이 수부터 시작해서 한 자리를 골라 이 자리의 숫자를 지워서 소수를 만들고, 이 과정을 연속해서 최대로 많이 만들 수 있는 소수의 개수이다.
이 과정에는 입력받은 원래의 수도 포함된다.

예를 들어, 127은 자신이 소수이다. 만약 7을 지우면 12가 되고, 이는 소수가 아니다.
그러나, 7을 지우는 대신 2를 지워서 17, 다시 1을 지워서 7을 만들면 총 3개의 소수를 연속해서 만들 수 있으며, 127의 점수는 3, 즉 127에서 규칙을 지키면서 소수를 최대로 많이 만들 수 있는 경우라는 것을 쉽게 보일 수 있다.
어떤 숫자를 지우더라도 소수를 만들 수 없다면 종료한다.

A와 B가 제시한 수에서 규칙에 의해 소수의 수열을 만들었을 때, 더 높은 점수를 얻는 수를 제시한 쪽이 이긴다.
둘이 제시한 수의 점수가 같다면 무승부이다.
규칙상, 소수가 아닌 수를 낸다면 이 수를 낸 쪽이 지거나, 비기는 경우 두 가지만 가능하다.

예를 들어, 128을 냈다면 이 수는 소수가 아니므로 이 수의 점수는 0점이고, 상대방도 합성수를 낸다면 비기고, 그렇지 않다면 지게 된다.
또한, 1은 소수가 아니다. A와 B가 제시하는 수의 어느 자리에도 0이 들어 있지 않다.
즉, 107과 같은 수를 제시할 수 없다.

A, B가 고른 두 수를 가지고 승패를 결정하는 프로그램을 작성하시오.

- 제한시간: 전체 테스트 케이스는 20개 이하이며, 전체 수행 시간은 1초 이내. (Java 2초 이내)
	제한 시간을 초과하면 제출한 소스코드의 프로그램이 즉시 종료되며,
	그때까지 수행한 결과에서 테스트 케이스를 1개 그룹 이상 통과하였더라도 점수는 0점이 됩니다.
	그러나, 제한 시간을 초과하더라도 테스트 케이스를 1개 그룹 이상 통과하였다면 '부분 점수(0< 점수< 만점)'를 받을 수 있으며,
	이를 위해서는, C / C++ 에서 "printf 함수" 사용할 경우, 프로그램 시작부분에서 "setbuf(stdout, NULL);"를 한번만 사용하십시오.
	C++에서는 "setbuf(stdout, NULL);"와 "printf 함수" 대신 "cout"를 사용하고, Java에서는 "System.out.printIn"을 사용하시면,
	제한 시간을 초과하더라도 '부분 점수'를 받을 수 있습니다.
	※ 언어별 기본 제공 소스코드 내용 참고
	만약, 제한 시간을 초과하지 않았는데도 '부분 점수'를 받았다면, 일부 테스트 케이스를 통과하지 못한 경우 입니다.

- 메모리 사용 제한 : heap, global, static 총계 256MB, stack 100MB
- 제출 제한 : 최대 10회 (제출 횟수를 반영하여 순위 결정 → 동점자의 경우 제출 횟수가 적은 사람에게 높은 순위 부여)

풀이:
30000까지의 모든 수에 대해 해당 수까지의 최대 개수를 저장하는 dp배열을 만든다.
30000까지 모두 돌면서, 수 x 가 소수라면 dp[x] 에 1을 더하고, 
x의 모든 자리를 한번씩 지워보고, 지운 수도 소수라면 그 수의 dp 값을 더한다.
지워볼 때마다 최댓값을 현재 dp[x]에 갱신한다.
(에라토스테네스의 체를 이용해 30000까지의 소수 배열을 미리 만든다)
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

int t;
bool isPrime[30001];
int dp[30001];
//0 일 땐 자기 자신
//1 ~ 5 일 땐 1의 자리부터 1,2,3,4,5 번째 수를 지웠을 때

int getCnt(int n) {
	int temp = 10;
	int ret = 1;

	while (n / temp != 0) {
		if (n % temp == 0)
			return -1;
		n /= temp;
		ret++;
	}

	return ret;
}

int cut(int n, int p) {
	int temp = pow(10, p);

	return (n / temp) * (temp / 10) + (n % (temp / 10));
}

int main(void) {
	FIO;

	isPrime[1] = true;

	for (int i = 2; i <= sqrt(30000); i++)
	{
		if (isPrime[i])	continue;
		for (int j = i * 2; j <= 30000; j += i)
		{
			isPrime[j] = true;
		}
	}

	for (int i = 2; i <= 30000; i++)
	{
		int cnt = getCnt(i);

		if (cnt == -1)	continue;

		if (!isPrime[i])
			dp[i]++;

		if (cnt == 1)	continue;

		for (int j = 1; j <= cnt; j++)
		{
			int next = cut(i, j);

			if (!isPrime[next]) {
				if(!isPrime[i])
					dp[i] = max(dp[i], dp[next] + 1);
				else
					dp[i] = max(dp[i], dp[next]);
			}
		}
	}
	
	cin >> t;

	for (int i = 1; i <= t; i++)
	{
		int a, b;

		cin >> a >> b;

		cout << "Case #" << i << "\n";
		if (dp[a] > dp[b])
			cout << "1\n";
		else if (dp[a] < dp[b])
			cout << "2\n";
		else
			cout << "3\n";
	}
}