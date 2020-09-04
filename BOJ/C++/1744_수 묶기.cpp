/*
문제
길이가 N인 수열이 주어졌을 때, 그 수열의 합을 구하려고 한다. 하지만, 그냥 그 수열의 합을 모두 더해서 구하는 것이 아니라, 수열의 두 수를 묶으려고 한다. 어떤 수를 묶으려고 할 때, 위치에 상관없이 묶을 수 있다. 하지만, 같은 위치에 있는 수(자기 자신)를 묶는 것은 불가능하다. 그리고 어떤 수를 묶게 되면, 수열의 합을 구할 때 묶은 수는 서로 곱한 후에 더한다.

예를 들면, 어떤 수열이 {0, 1, 2, 4, 3, 5}일 때, 그냥 이 수열의 합을 구하면 0+1+2+4+3+5 = 15이다. 하지만, 2와 3을 묶고, 4와 5를 묶게 되면, 0+1+(2*3)+(4*5) = 27이 되어 최대가 된다.

수열의 모든 수는 단 한번만 묶거나, 아니면 묶지 않아야한다.

수열이 주어졌을 때, 수열의 각 수를 적절히 묶었을 때, 그 합이 최대가 되게 하는 프로그램을 작성하시오.

입력
첫째 줄에 수열의 크기 N이 주어진다. N은 10,000보다 작다. 둘째 줄부터 N개의 줄에, 수열의 각 수가 주어진다. 수열의 수는 -10,000보다 크거나 같고, 10,000보다 작거나 같은 정수이다.

출력
수를 합이 최대가 나오게 묶었을 때 합을 출력한다. 정답은 항상 231보다 작다.

풀이:
기본적인 아이디어는 양수는 양수끼리 내림차순 정렬, 음수는 음수끼리 내림차순 정렬하여
큰 수부터 2개씩 묶어가며 더해가는 것이다.
이 때, 양수는 1을 곱하면 손해이므로 1은 더해주기만 해야 한다.
만약 음수가 홀수 개일 때 무조건 빼야하는데 이때 0이 하나라도 존재했다면 그 음수를 제거할 수 있다.
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
#define MOD 100003
int mv1[4] = { 0, 0, 1, -1 };
int mv2[4] = { 1, -1, 0, 0 };
int mv_all1[8] = { 0, 1, 0, -1, -1, -1, 1, 1 };
int mv_all2[8] = { 1, 0, -1, 0 , -1, 1, -1, 1 };

int n;
vector<int> p;
vector<int> m;

int main(void) {
	FIO;

	cin >> n;

	int sum = 0;
	bool isZero = false;

	for (int i = 0; i < n; i++)
	{
		int v;
		cin >> v;
		if (v > 0) {
			if (v == 1)
				sum++;
			else
				p.push_back(-v);
		}
		else if (v < 0)
			m.push_back(v);
		else
			isZero = true;
	}

	sort(p.begin(), p.end());

	if (p.size() > 0) {

		for (int i = 0; i < p.size() - 1; i += 2)
		{
			sum += (-p[i] * -p[i + 1]);
		}

		if (p.size() % 2 != 0)
			sum += (-p[p.size() - 1]);

	}

	if (m.size() > 0) {

		sort(m.begin(), m.end());

		for (int i = 0; i < m.size() - 1; i += 2)
		{
			sum += (m[i] * m[i + 1]);
		}

		if (m.size() % 2 != 0) {
			if(!isZero)
				sum += (m[m.size() - 1]);
		}

	}

	cout << sum;
}