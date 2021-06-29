/*
문제
n개의 서로 다른 양의 정수 a1, a2, ..., an으로 이루어진 수열이 있다. ai의 값은 1보다 크거나 같고, 1000000보다 작거나 같은 자연수이다. 자연수 x가 주어졌을 때, ai + aj = x (1 ≤ i < j ≤ n)을 만족하는 (ai, aj)쌍의 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 수열의 크기 n이 주어진다. 다음 줄에는 수열에 포함되는 수가 주어진다. 셋째 줄에는 x가 주어진다. (1 ≤ n ≤ 100000, 1 ≤ x ≤ 2000000)

출력
문제의 조건을 만족하는 쌍의 개수를 출력한다.

풀이:
투포인터 문제지만, 숫자의 범위가 크지 않고 숫자가 중복되지 않아 두 개의 배열을 사용해 풀이할 수도 있었다.
각 수들의 index를 체크하는 배열을 만들고, 숫자 배열을 돌면서 합이 x 가 되는 상대 other 수가 존재하는지 세고, 인덱스를 비교해 카운트한다.
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
int mv1[4] = { 0, 1, -1, 0 };
int mv2[4] = { 1, 0, 0, -1 };

int n, x;
int arr[100001];
int idx[1000001];

int main() {
	FIO;

	cin >> n;

	fill(&idx[0], &idx[1000001], -1);

	for (int i = 0; i < n; i++)
	{
		int v;
		cin >> v;
		arr[i] = v;

		idx[v] = i;
	}
	
	cin >> x;

	int count = 0;
	
	for (int i = 0; i < n; i++)
	{
		int now = arr[i];
		int other = x - now;
		
		if (other <= 0)	continue;

		if (idx[other] > i) {
			count++;
		}
	}

	cout << count;
}