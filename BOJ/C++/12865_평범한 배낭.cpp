/*
문제
이 문제는 아주 평범한 배낭에 관한 문제이다.

한 달 후면 국가의 부름을 받게 되는 준서는 여행을 가려고 한다. 세상과의 단절을 슬퍼하며 최대한 즐기기 위한 여행이기 때문에, 가지고 다닐 배낭 또한 최대한 가치 있게 싸려고 한다.

준서가 여행에 필요하다고 생각하는 N개의 물건이 있다. 각 물건은 무게 W와 가치 V를 가지는데, 해당 물건을 배낭에 넣어서 가면 준서가 V만큼 즐길 수 있다. 아직 행군을 해본 적이 없는 준서는 최대 K무게까지의 배낭만 들고 다닐 수 있다. 준서가 최대한 즐거운 여행을 하기 위해 배낭에 넣을 수 있는 물건들의 가치의 최댓값을 알려주자.

입력
첫 줄에 물품의 수 N(1 ≤ N ≤ 100)과 준서가 버틸 수 있는 무게 K(1 ≤ K ≤ 100,000)가 주어진다. 두 번째 줄부터 N개의 줄에 거쳐 각 물건의 무게 W(1 ≤ W ≤ 100,000)와 해당 물건의 가치 V(0 ≤ V ≤ 1,000)가 주어진다.

입력으로 주어지는 모든 수는 정수이다.

출력
한 줄에 배낭에 넣을 수 있는 물건들의 가치합의 최댓값을 출력한다.

풀이:
유명한 knapsack 문제입니다.

dp[현재 가방의 용량][j번째 물건] 

각각의 용량에 대해 물건을 넣어가며 진행합니다.
물건이 용량보다 크면, 용량은 그대로 두고, 그 물건 이전의(j - 1) dp 값을 그대로 갖고 옵니다.

물건이 용량보다 작거나 같다면

dp[i - w[j]][j - 1] = (물건만큼 용량을 뺐을 때 현재 물건을 넣기 전)
+ 현재 물건의 가치

와 현재 물건을 넣기 전의 값(dp[i][j - 1] 중 큰 값을 dp[i][j]에 넣습니다.
*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<string.h>
#include<vector>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>

int N, K;
int dp[100001][101];
pii arr[101];

int main(void) {
	FIO;

	cin >> N >> K;

	for (int i = 1; i <= N; i++)
	{
		int W, V;
		cin >> W >> V;

		arr[i] = make_pair(W, V);
	}

	for (int i = 0; i <= K; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (i >= arr[j].first) {
				dp[i][j] = max(dp[i][j - 1], dp[i - arr[j].first][j - 1] + arr[j].second);
			}
			else {
				dp[i][j] = dp[i][j - 1];
			}
		}
	}
	cout << dp[K][N];
}