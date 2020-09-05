/*
문제
태영이의 고향 "위" 도시에는 순환 고속도로가 있다. 이 고속도로에는 총 개의 주유소가 있고, 각 주유소는 번부터 번까지 번호가 붙어있다. 어느 날 태영이는 이 고속도로 한 바퀴를 드라이브하려는 원대한 계획을 세우고, 하나의 주유소를 골라 순환 여행을 시작하려고 한다. 그런데 이 도시는 특이하여 한 주유소에서 구입할 수 있는 기름의 양은 정해져 있고, 각 주유소에서 구입할 수 있는 기름의 양을 모두 합해야 간신히 고속도로 한 바퀴를 순환할 수 있는 기름이 나온다. 가난한 태영이에게는 기름이 한 방울도 없으므로, 도시를 잘못 고르면 운전을 하다가 자동차가 서버릴 지도 모른다!



이 그림에서 세 주유소에서 기름을 최대 2만큼 구입할 수 있고, 1번 주유소-2번 주유소 도로와 2번 주유소-3번 주유소 도로가 기름이 1만큼 필요하고 3번 주유소-1번 주유소 도로가 4만큼 필요하다면, 1번 주유소에서 시작해 무사히 고속도로를 순환할 수 있다.

태영이를 위해 태영이의 차가 중간에 서버리지 않도록 하기 위해 골라야 하는 시작 주유소 위치의 개수를 구해주자. 그런 주유소가 없다면 0을 출력하면 된다.

입력
첫 번째 줄에 주유소의 개수 이 주어진다. 두 번째 줄 번째 정수는 번 주유소에서 구입할 수 있는 기름의 양 이다. 세 번째 줄 번째 정수는 번 주유소에서 번 주유소 (번 주유소는 번 주유소와 같다)로 가는 길에 소비해야 하는 기름의 양 이다. 이때 들의 합과 들의 합은 같다.

출력
태영이의 자동차가 주유소에 도착하지 못하고 멈춰버리는 일 없이 고속도로를 순환할 수 있게 하는 출발 주유소의 개수를 출력한다.

풀이:
시작점 i 에서 출발해서 j 주유소에 도착해서 주유하기 전까지의 기름의 양을 모두 구해본다.
그러면 시작점(0의 위치)만 계속 바뀌고, 값들의 배열 형태는 동일하다는 것을 알 수 있다.
시작점을 아무거나 하나 잡고 위 배열을 만든 뒤, 배열의 최소값의 개수가 답이 된다.
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
ll node[500001];
ll road[500001];
ll oil[500001];

int main(void) {
	FIO;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> node[i];
	}

	for (int i = 0; i < n; i++)
	{
		cin >> road[i];
	}

	ll minV = 0;
	oil[0] = 0;

	for (int i = 1; i < n; i++)
	{
		oil[i] = oil[i - 1] + node[i - 1] - road[i - 1];
		minV = min(minV, oil[i]);
	}

	int ans = 0;

	for (int i = 0; i < n; i++)
	{
		if (oil[i] == minV)
			ans++;
	}

	cout << ans;
}