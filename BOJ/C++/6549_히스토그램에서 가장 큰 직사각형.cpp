/*
문제
히스토그램은 직사각형 여러 개가 아래쪽으로 정렬되어 있는 도형이다. 각 직사각형은 같은 너비를 가지고 있지만, 높이는 서로 다를 수도 있다. 예를 들어, 왼쪽 그림은 높이가 2, 1, 4, 5, 1, 3, 3이고 너비가 1인 직사각형으로 이루어진 히스토그램이다.



히스토그램에서 가장 넓이가 큰 직사각형을 구하는 프로그램을 작성하시오.

입력
입력은 테스트 케이스 여러 개로 이루어져 있다. 각 테스트 케이스는 한 줄로 이루어져 있고, 직사각형의 수 n이 가장 처음으로 주어진다. (1 ≤ n ≤ 100,000) 그 다음 n개의 정수 h1, ..., hn (0 ≤ hi ≤ 1,000,000,000)가 주어진다. 이 숫자들은 히스토그램에 있는 직사각형의 높이이며, 왼쪽부터 오른쪽까지 순서대로 주어진다. 모든 직사각형의 너비는 1이고, 입력의 마지막 줄에는 0이 하나 주어진다.

출력
각 테스트 케이스에 대해서, 히스토그램에서 가장 넓이가 큰 직사각형의 넓이를 출력한다.

풀이:
어떤 높이가 h 인 직사각형을 볼 때, 현재 스택 top 의 보다 작거나 같으면,
스택 top의 높이로 직사각형의 넓이를 구해야 한다.(높이가 작아졌으므로)

h 보다 스택 top의 높이가 높거나 같은 모든 울타리에 대해 해당 울타리를 높이로 하는 직사각형의 넓이를 구한다.
가로의 길이는 현재 ~ 스택 top의 울타리 위치 - 1 이 된다.

모든 연산이 끝난 뒤 현재 울타리를 스택에 push 한다.
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

int n;

int main(void) {
	FIO;

	while (true) {
		cin >> n;

		if (n == 0)	break;

		vector<ll> vt;
		stack<ll> st;

		ll ans = 0;
		
		for (int i = 0; i < n; i++)
		{
			int v;
			cin >> v;
			vt.push_back(v);
		}

		vt.push_back(0);

		for (ll i = 0; i <= n; i++)
		{
			while (!st.empty() && vt[st.top()] >= vt[i]) {
				ll prv = st.top();
				st.pop();

				ll width;
				if (st.empty())
					width = i;
				else
					width = (i - st.top() - 1);
				ans = max(ans, vt[prv] * width);
			}

			st.push(i);
		}

		cout << ans << "\n";
	}
}