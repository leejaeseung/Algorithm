/*
문제
이하는 최근 사과나무 씨앗을 구매하여 농장 뒷뜰에 일렬로 번부터 번까지 심었다. 이 나무들의 초기 높이는 모두 이다.

사과나무를 무럭무럭 키우기 위해 이하는 물뿌리개 개를 준비했다. 한 물뿌리개는 나무 하나를 만큼 성장시키고, 다른 물뿌리개는 나무 하나를 만큼 성장시킨다. 이 물뿌리개들은 동시에 사용해야 하며, 물뿌리개를 나무가 없는 토양에 사용할 수는 없다. 두 물뿌리개를 한 나무에 사용하여 만큼 키울 수도 있다.

물뿌리개 관리 시스템을 전부 프로그래밍한 이하는 이제 사과나무를 키워보려고 했다. 그 순간, 갊자가 놀러와서 각 사과나무의 높이가 이런 배치가 되었으면 좋겠다고 말했다. 이제 이하는 약간 걱정이 되기 시작했는데, 갊자가 알려준 사과나무의 배치를 이 프로그램 상으로 만들어내지 못할 수도 있기 때문이다.

이하는 이제 프로그램을 다시 수정하느라 바쁘기 때문에, 두 물뿌리개를 이용해 갊자가 알려준 사과나무의 배치를 만들 수 있는지의 여부를 판단하는 과정은 여러분의 몫이 되었다.

입력
첫 번째 줄에는 자연수 이 주어진다. () 이는 이하가 뒷뜰에 심은 사과나무의 개수를 뜻한다.

두 번째 줄에는 개의 정수 이 공백으로 구분되어 주어진다. () 는 갊자가 바라는 번째 나무의 높이이다.

출력
첫 번째 줄에 모든 나무가 갊자가 바라는 높이가 되도록 물뿌리개를 통해 만들 수 있으면 “YES”를, 아니면 “NO”를 따옴표를 제외하고 출력한다.

풀이:
수학 문제 - 1의 개수와, 3의 배수 활용

1. 주어진 배열의 총 합이 3의 배수가 아니면, NO
2. 주어진 배열의 1의 개수만큼 다른 1보다 큰 수에서 2를 빼 주어야 함.(뺄 수 없다면 NO)
3. 2번에서 2를 뺴서 생긴 1의 개수만큼 2번을 다시 진행. -> 원래 있던 1은 무시
4. 2, 3번에서 생긴 1의 개수가 n과 같으면 NO
5. 4번까지 통과했다면(1을 제거하는 과정), 현재 배열엔 모든 수가 1보다 큼. -> 1보다 큰 모든 수를 MOD 3 했을 때, 
	나머지들의 합이 3의 배수라면 YES, 아니라면 NO
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
int height[100001];

int main(void) {
	FIO;

	cin >> n;

	int sum = 0;
	int one_cnt = 0;
	int remain_1 = 0;
	int remain_2 = 0;
	int all_one = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> height[i];
		sum += height[i];
		if (height[i] == 1)
			one_cnt++;
	}

	all_one = one_cnt;

	if (sum % 3 == 0) {
		//총 합이 3의 배수라면
		
		if (sum - (one_cnt * 3) < 0)
			//1의 개수만큼 2를 빼줄 수 없다면
			cout << "NO";
		else {
			while (one_cnt != 0) {
				//1의 개수만큼 계속해서 2를 빼줌
				for (int i = 0; i < n; i++)
				{
					if (height[i] == 1) continue;
					//원래 있던 1이라면 pass

					if (height[i] > 1 && one_cnt > 0) {
						int maximum = height[i] / 2;
						if (maximum > one_cnt) {
							height[i] -= (one_cnt * 2);
							one_cnt = 0;
						}
						else {
							one_cnt -= maximum;
							height[i] -= (maximum * 2);
						}
					}
					if (height[i] == 1) {
						//새롭게 생긴 1
						one_cnt++;
						all_one++;
					}
				}
				if (all_one == n) {
					//모든 수가 1이 되버리면 NO
					cout << "NO";
					exit(0);
				}
			}

			for (int i = 0; i < n; i++)
			{
				if (height[i] == 1)	continue;
				if (height[i] % 3 == 1)
					remain_1++;
				else if (height[i] % 3 == 2)
					remain_2++;
			}

			int all = remain_1 + remain_2 * 2;
			//1보다 큰 수들에 대해 MOD 3한 나머지들의 합이 3의 배수인지

			if (all % 3 == 0)
				cout << "YES";
			else
				cout << "NO";
		}
	}
	else {
		cout << "NO";
	}
}