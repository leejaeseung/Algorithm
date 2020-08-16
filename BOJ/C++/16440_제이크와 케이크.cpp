/*
문제
제이크는 레이니콘으로부터 긴 모양의 케이크를 선물 받았습니다.

케이크 위에는 N개의 과일 조각이 올려져 있는데 케이크 위에는 딸기 N/2개와 키위 N/2개가 일정한 간격을 두고 일렬로 올려져 있습니다. 여기서 N은 4의 배수입니다.

제이크는 케이크를 핀과 올려진 과일의 종류를 포함하여 케이크를 정확히 절반씩 먹기 위해 받은 케이크를 잘라서 나누어 가지려고 합니다. 이때 제이크가 받은 딸기가 N/4개여야 하며 키위도 N/4개 있어야 합니다. 핀도 제이크와 같은 개수의 딸기와 키위를 받아야 합니다.

제이크와 핀은 케이크를 자르기 귀찮으므로 그 횟수를 최소화하고자 합니다. 핀과 제이크가 똑같이 나누어 먹기 위해 케이크를 잘라야 하는 최소 횟수와 방법을 알려주세요.

입력
첫 번째 줄에는 케이크 위에 있는 과일의 개수 N (4 ≤ N ≤ 200,000) 이 주어집니다.

두 번째 줄에는 케이크의 정보가 담긴 길이가 N인 문자열이 주어집니다. i번째 문자가 's'이면 i번째 칸에는 딸기가 'k'이면 키위가 올려져 있음을 의미합니다.

출력
첫 번째 줄에 최소 횟수 k (1 ≤ k ≤ N - 1) 를 출력합니다.

두 번째 줄에는 k개의 정수 c1, c2, ..., ck (1 ≤ c1 < c2 < ... < ck  ≤ N - 1) 를 출력합니다. 여기서 ci는 ci 번째 과일이 있는 곳과 ci +1번째 과일이 있는 곳 사이를 자른다는 의미입니다.

자르는 방법이 여러 개인 경우 그 중 하나만 출력합니다.

풀이:
분할 정복, 양방향 탐색 등등 여러 방법을 고민해봤는데 알고보니 정말 간단한 문제였다.

아무리 복잡하게 배열되어 있어도 자르는 최대 횟수는 2를 넘지 않는다.
(즉, 답은 항상 1 아니면 2)

답이 1인 경우는 간단하다.
중간을 기준으로 왼쪽, 오른쪽의 s, k 수가 같을 경우이다.

답이 2인 경우는 조각이 총 3개 생긴다.
이 때, 3개의 조각 중 중간의 조각은 항상 완성된 조각이다.
따라서 왼쪽부터 잘라보며 왼쪽 조각, 오른쪽 조각의 s, k 개수가 조건을 만족하는 경우 해당 지점을 잘라주면 된다.

오른쪽 조각의 s, k 개수를 prefix Sum을 이용해 배열에 미리 저장해두고 풀이해야 시간 초과를 피할 수 있다.
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
int rightSum[200004][2];
int leftSum[2];
string cake;
vector<int> vt;

int main(void) {
	FIO;

	cin >> n >> cake;

	for (int i = 0; i < n; i++)
	{
		if (cake[i] == 's')
			vt.push_back(0);
		else
			vt.push_back(1);
	}

	for (int i = n - 1; i >= 0; i--)
		//오른쪽에서부터 s, k 의 개수를 미리 구해놓음
	{
		int now = vt[i];

		rightSum[i][now] = rightSum[i + 1][now] + 1;
		rightSum[i][(now + 1) % 2] = rightSum[i + 1][(now + 1) % 2];
	}

	int jump = n / 2 + 1;

	if (rightSum[n / 2][0] == n / 4 && rightSum[n / 2][1] == n / 4) {
		//중앙에서 자를 때
		cout << "1\n" << n / 2;
	}
	else {
		//세 조각으로 나눌 때
		for (int i = 0; i < n / 2; i++)
		{
			int now = vt[i];

			leftSum[now]++;

			if (leftSum[0] + rightSum[i + jump][0] == n / 4 && leftSum[1] + rightSum[i + jump][1] == n / 4) {
				cout << "2\n" << i + 1 << " " << i + jump;
				break;
			}
		}
	}
}