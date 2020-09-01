/*
문제
N개의 정수로 이루어진 수열이 있을 때, 크기가 양수인 부분수열 중에서 그 수열의 원소를 다 더한 값이 S가 되는 경우의 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 정수의 개수를 나타내는 N과 정수 S가 주어진다. (1 ≤ N ≤ 20, |S| ≤ 1,000,000) 둘째 줄에 N개의 정수가 빈 칸을 사이에 두고 주어진다. 주어지는 정수의 절댓값은 100,000을 넘지 않는다.

출력
첫째 줄에 합이 S가 되는 부분수열의 개수를 출력한다.

풀이:
수열의 모든 부분 집합을 구하는 문제로, 비트마스크를 이용한 브루트 포스로 풀이했다.

for (int i = all; i > 0; i = ((i - 1) & all))

위 반복문에서 i에 모든 부분 집합이 담김을 기억하자.(원소의 개수가 0개인 것 제외)
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
#define MOD 100007
int mv1[4] = { 0, 0, 1, -1 };
int mv2[4] = { 1, -1, 0, 0 };
int mv_all1[8] = { 0, 1, 0, -1, -1, -1, 1, 1 };
int mv_all2[8] = { 1, 0, -1, 0 , -1, 1, -1, 1 };

int n, s;
int arr[20];

int main(void) {
	FIO;

	cin >> n >> s;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int all = 0;

	for (int i = 0; i < n; i++)
	{
		all = (all << 1) + 1;
	}

	int ans = 0;

	for (int i = all; i > 0; i = ((i - 1) & all))
	{
		int sum = 0;

		for (int j = 0; j < n; j++)
		{
			if ((i & (1 << j)) > 0) {
				sum += arr[j];
			}

		}

		if (sum == s)
			ans++;
	}

	cout << ans;
}