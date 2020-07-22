/*
문제
N개의 수 중에서 어떤 수가 다른 수 두 개의 합으로 나타낼 수 있다면 그 수를 “좋다(GOOD)”고 한다.

N개의 수가 주어지면 그 중에서 좋은 수의 개수는 몇 개인지 출력하라.

입력
첫째 줄에는 수의 개수 N(1 ≤ N ≤ 2,000), 두 번째 줄에는 i번째 수를 나타내는 Ai가 N개 주어진다. (|Ai| ≤ 1,000,000,000, Ai는 정수)

출력
좋은 수의 개수를 첫 번째 줄에 출력한다.

풀이:
이분탐색 문제지만 multimap 으로 아슬아슬하게 통과했습니다.

배열의 수의 중복, 자기 자신을 제외한 두 수 등 예외처리해야 하는 게 많아 까다로운 문제입니다.

중복이 허용되는 multimap을 이용해 좋은 수들을 모두 map에 담는데, 이 때 두 수의 인덱스를 모두 저장합니다.
이제 좋은 수가 모두 map에 담겼으니 처음 배열을 모두 돌면서 해당 수가 좋은 수인지 판별해 줍니다.

- 좋은 수가 있을 때, 해당 좋은 수의 인덱스 두 개가 현재 배열의 인덱스와 겹친다면 세지 않습니다.
- 좋은 수를 만들 수 있는 여러 경우가 있기 때문에 lower_bound~upper_bound까지 모두 세어 줍니다.
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

int n;
ll arr[2001];
multimap<ll, pii> m;

int main(void) {
	FIO;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			m.insert(make_pair(arr[i] + arr[j], make_pair(i, j)));
		}
	}

	int cnt = 0;

	for (int i = 0; i < n; i++)
	{
		for (auto iter = m.lower_bound(arr[i]); iter != m.upper_bound(arr[i]); iter++)
		{
			pii idxes = iter->second;

			if (idxes.first != i && idxes.second != i) {
				cnt++;
				break;
			}

		}
	}

	cout << cnt;
}