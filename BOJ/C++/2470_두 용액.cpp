/*
문제
KOI 부설 과학연구소에서는 많은 종류의 산성 용액과 알칼리성 용액을 보유하고 있다. 각 용액에는 그 용액의 특성을 나타내는 하나의 정수가 주어져있다.  산성 용액의 특성값은 1부터 1,000,000,000까지의 양의 정수로 나타내고, 알칼리성 용액의 특성값은 -1부터 -1,000,000,000까지의 음의 정수로 나타낸다.

같은 양의 두 용액을 혼합한 용액의 특성값은 혼합에 사용된 각 용액의 특성값의 합으로 정의한다. 이 연구소에서는 같은 양의 두 용액을 혼합하여 특성값이 0에 가장 가까운 용액을 만들려고 한다.

예를 들어, 주어진 용액들의 특성값이 [-2, 4, -99, -1, 98]인 경우에는 특성값이 -99인 용액과 특성값이 98인 용액을 혼합하면 특성값이 -1인 용액을 만들 수 있고, 이 용액이 특성값이 0에 가장 가까운 용액이다. 참고로, 두 종류의 알칼리성 용액만으로나 혹은 두 종류의 산성 용액만으로 특성값이 0에 가장 가까운 혼합 용액을 만드는 경우도 존재할 수 있다.

산성 용액과 알칼리성 용액의 특성값이 주어졌을 때, 이 중 두 개의 서로 다른 용액을 혼합하여 특성값이 0에 가장 가까운 용액을 만들어내는 두 용액을 찾는 프로그램을 작성하시오.

입력
첫째 줄에는 전체 용액의 수 N이 입력된다. N은 2 이상 100,000 이하이다. 둘째 줄에는 용액의 특성값을 나타내는 N개의 정수가 빈칸을 사이에 두고 주어진다. 이 수들은 모두 -1,000,000,000 이상 1,000,000,000 이하이다. N개의 용액들의 특성값은 모두 다르고, 산성 용액만으로나 알칼리성 용액만으로 입력이 주어지는 경우도 있을 수 있다.

출력
첫째 줄에 특성값이 0에 가장 가까운 용액을 만들어내는 두 용액의 특성값을 출력한다. 출력해야 하는 두 용액은 특성값의 오름차순으로 출력한다. 특성값이 0에 가장 가까운 용액을 만들어내는 경우가 두 개 이상일 경우에는 그 중 아무것이나 하나를 출력한다.

풀이:
먼저, 배열을 오름차순으로 정렬하면 정답은 다음 세 가지 케이스 중 하나에서 나온다.

case 1 : 연속된 음수
ex) -2 -1 100 101 에서 -2, -1 이 정답

case 2 : 연속된 양수
ex) -100 -99 1 2 에서 1, 2 이 정답

case 3 : 음수와 양수의 조합
ex) -99 -4 1 4 55 에서 -4, 4 가 정답

case 1 과 2 는 O(1) 만에 구할 수 있으므로 미리 구해두고,
case 3 는 음수의 가장 작은 지점과 양수의 가장 작은 지점(case 3의 예시에서 -4 와 1)부터 투 포인터를 사용한다.
음수, 양수 두 값의 합이 양수라면 음수가 더 필요하므로 음수를 한 칸 옮기고,
두 값의 합이 음수라면 양수가 더 필요하므로 양수를 한 칸 옮기며 탐색하면 된다.
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
#define IMAX 2147483647
#define LMAX 1000000000000500000
#define DMAX 0xFFFFFFFFFFFFF
int mv1[4] = { 0, 1, -1, 0 };
int mv2[4] = { 1, 0, 0, -1 };

int n;
int arr[100001];

int main() {
	FIO;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + n);

	int m = -1 , p = 0;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] >= 0) {
			m = i - 1;
			p = i;
			break;
		}
		else {
			m++;
		}
	}
	int minV = IMAX;
	int ansM, ansP;

	if (p < n - 1 && minV > abs(arr[p] + arr[p + 1])) {
		minV = abs(arr[p] + arr[p + 1]);
		ansM = p;
		ansP = p + 1;
	}
	if (m > 0 && minV > abs(arr[m - 1] + arr[m])) {
		minV = abs(arr[m - 1] + arr[m]);
		ansM = m - 1;
		ansP = m;
	}
		
	while (m < n - 1 && m > -1 && p < n) {
		int dif = arr[p] + arr[m];

		if (abs(dif) < minV) {
			minV = abs(dif);
			ansM = m;
			ansP = p;
		}

		if (dif == 0) {
			break;
		}
		else if (dif > 0) {
			m--;
		}
		else {
			p++;
		}
	}

	cout << arr[ansM] << " " << arr[ansP];
}