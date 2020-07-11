/*
문제
승현이는 수열을 찾는 사람들을 위해 길이가 N 인 수열 a1, a2, ··· , aN을 만드는 일을 하고 있다. 승현이는 경력이 짧아서 각 원소가 -2 이상 2 이하의 정수인 수열만 만들 수 있고, 그래서인지 수열을 찾는 고객이 많지 않아 승현이는 생활고에 시달리고 있다.

이를 지켜보던 지학이는 안타까운 마음에 승현이에게 수열을 하나 만들어달라고 의뢰했고, 승현이는 기쁜 마음으로 수열을 만들어 주었다. 지학이는 이 수열에서 임의의 연속하는 부분 ai, ai+1, ··· , aj−1, aj (1 ≤ i ≤ j ≤ N)를 선택하여, 선택한 부분의 원소들의 곱 ai × ai+1 × · · · × aj−1 × aj 가 최대가 되게 하려고 한다. (단 i = j 이면 곱의 결과를 ai 로 정의한다.)

승현이가 만든 수열이 주어질 때, 지학이가 만들 수 있는 곱의 최댓값을 구하는 프로그램을 작성하라.

입력
첫 줄에 테스트 케이스의 수 T (1 ≤ T ≤ 100,000)가 입력된다. 이후 T 개의 테스트 케이스가 주어진다.

각 테스트 케이스의 첫 번째 줄에는 승현이가 만든 수열의 길이 N (2 ≤ N ≤ 100,000)이 주어지고, 두 번째 줄에는 승현이가 만든 수열의 각 원소 a1, a2, ··· , aN (−2 ≤ ai ≤ 2)이 공백을 사이에 두고 주어진다.

모든 테스트 케이스에 대한 N 의 총합이 300,000을 넘지 않음이 보장된다.

출력
각 테스트 케이스에 대해, 지학이가 만들 수 있는 곱의 최댓값을 1,000,000,007 (= 109+7)으로 나눈 나머지를 한 줄에 하나씩 출력한다.

풀이:
나올 수 있는 수는 -2, -1, 0, 1, 2 로 5개고, 최댓값을 만들기 위해선 음수의 개수가 짝수인 경우를 체크해줘야 합니다.
그리고 1은 결과에 상관이 없으므로 무시합니다.

정답인 경우는, 음수의 개수가 짝수개 이면서 2의 개수가 최대가 되는 지점입니다.
만약 현재까지의 음수의 개수가 홀수개 였는데, 음수를 한번 더 만나면 현재까지의 수를 모두 곱한 값이 최대가 됩니다.
따라서 그리디하게 풀이할 수 있습니다.

단, 0을 만났을 시 다시 음수의 개수, 2의 개수를 카운트해줘야 합니다.
그리고 

2 2 2 -1 2 2 2 2 2 2 2
와 같이 왼쪽 -> 오른쪽을 탐색할 때의 오른쪽 -> 왼쪽을 탐색할 때의 결과값이 다르므로 양쪽에서 모두 진행해 줍니다.

배열을 끝까지 탐색하면서 음수가 짝수개가 될 때 현재까지의 2의 개수를 계속 갱신해주고, 최종 2의 개수만큼 곱해주면 답이 됩니다.
2가 하나도 안 나온 경우엔 -1, 0, 1 세 값 중 하나가 정답이므로 예외처리 해주면 됩니다.
*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
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

int t, n;
ll MOD = 1000000007;
ll ans_two;
ll ans;

int main(void) {
	FIO;

	cin >> t;

	while (t--) {
		cin >> n;

		ans_two = 0;
		ans = -3;
		vector<ll> vt;

		for (int i = 0; i < n; i++)
		{
			ll v;
			cin >> v;

			vt.push_back(v);
			ans = max(ans, v);
			//한 개만 보았을 때 최댓값
		}

		ll now_two = 0;
		ll now_minus = 0;

		for (int i = 0; i < n; i++)
		{
			if (vt[i] == 0) {
				//0을 만나면 카운트를 다시 세줌
				now_two = 0;
				now_minus = 0;
				continue;
			}
			else if(vt[i] < 0){
				now_minus++;

				if (vt[i] == -2)
					now_two++;
			}
			else {
				if (vt[i] == 2)
					now_two++;
			}


			if (now_minus % 2 == 0) {
				//현재까지 음수의 개수가 짝수개면 2의 개수를 갱신
				ans_two = max(ans_two, now_two);
				ans = 1;
				//2의 개수가 0개인 경우를 대비함. -> 음수의 개수가 짝수개면 최댓값은 1이므로
				now_minus = 0;
			}
		}

		now_two = 0;
		now_minus = 0;

		for (int i = n - 1; i >= 0; i--)
			//반대 방향에 대해서도 수행
		{
			if (vt[i] == 0) {
				now_two = 0;
				now_minus = 0;
				continue;
			}
			else if (vt[i] < 0) {
				now_minus++;

				if (vt[i] == -2)
					now_two++;
			}
			else {
				if (vt[i] == 2)
					now_two++;
			}


			if (now_minus % 2 == 0) {
				ans_two = max(ans_two, now_two);
				ans = 1;
				now_minus = 0;
			}
		}

		if (ans_two != 0) {
			ans = 1;

			while (ans_two--) {
				//2의 개수만큼 곱해줌
				ans = ((ans % MOD) * 2) % MOD;
			}
		}

		cout << ans << "\n";
	}
}