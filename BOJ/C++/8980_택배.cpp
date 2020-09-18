/*
문제
아래 그림과 같이 직선 도로상에 왼쪽부터 오른쪽으로 1번부터 차례대로 번호가 붙여진 마을들이 있다. 마을에 있는 물건을 배송하기 위한 트럭 한 대가 있고, 트럭이 있는 본부는 1번 마을 왼쪽에 있다. 이 트럭은 본부에서 출발하여 1번 마을부터 마지막 마을까지 오른쪽으로 가면서 마을에 있는 물건을 배송한다.



각 마을은 배송할 물건들을 박스에 넣어 보내며, 본부에서는 박스를 보내는 마을번호, 박스를 받는 마을번호와 보낼 박스의 개수를 알고 있다. 박스들은 모두 크기가 같다. 트럭에 최대로 실을 수 있는 박스의 개수, 즉 트럭의 용량이 있다. 이 트럭 한대를 이용하여 다음의 조건을 모두 만족하면서 최대한 많은 박스들을 배송하려고 한다.

조건 1: 박스를 트럭에 실으면, 이 박스는 받는 마을에서만 내린다.
조건 2: 트럭은 지나온 마을로 되돌아가지 않는다.
조건 3: 박스들 중 일부만 배송할 수도 있다.
마을의 개수, 트럭의 용량, 박스 정보(보내는 마을 번호, 받는 마을번호, 박스 개수)가 주어질 때, 트럭 한 대로 배송할 수 있는 최대 박스 수를 구하는 프로그램을 작성하시오. 단, 받는 마을번호는 보내는 마을번호보다 항상 크다.

예를 들어, 트럭 용량이 40이고 보내는 박스들이 다음 표와 같다고 하자.

보내는 마을	받는 마을	박스 개수
1	2	10
1	3	20
1	4	30
2	3	10
2	4	20
3	4	20
이들 박스에 대하여 다음과 같이 배송하는 방법을 고려해 보자.

(1) 1번 마을에 도착하면

다음과 같이 박스들을 트럭에 싣는다. (1번 마을에서 4번 마을로 보내는 박스는 30개 중 10개를 싣는다.)

보내는 마을	받는 마을	박스 개수
1	2	10
1	3	20
1	4	10
(2) 2번 마을에 도착하면

트럭에 실려진 박스들 중 받는 마을번호가 2인 박스 10개를 내려 배송한다. (이때 트럭에 남아있는 박스는 30개가 된다.)

그리고 다음과 같이 박스들을 싣는다. (이때 트럭에 실려 있는 박스는 40개가 된다.)

보내는 마을	받는 마을	박스 개수
2	3	10
(3) 3번 마을에 도착하면

트럭에 실려진 박스들 중 받는 마을번호가 3인 박스 30개를 내려 배송한다. (이때 트럭에 남아있는 박스는 10개가 된다.)

그리고 다음과 같이 박스들을 싣는다. (이때 트럭에 실려 있는 박스는 30개가 된다.)

보내는 마을	받는 마을	박스 개수
3	4	20
(4) 4번 마을에 도착하면

받는 마을번호가 4인 박스 30개를 내려 배송한다

위와 같이 배송하면 배송한 전체 박스는 70개이다. 이는 배송할 수 있는 최대 박스 개수이다.

입력
입력의 첫 줄은 마을 수 N과 트럭의 용량 C가 빈칸을 사이에 두고 주어진다. N은 2이상 2,000이하 정수이고, C는 1이상 10,000이하 정수이다. 다음 줄에, 보내는 박스 정보의 개수 M이 주어진다. M은 1이상 10,000이하 정수이다. 다음 M개의 각 줄에 박스를 보내는 마을번호, 박스를 받는 마을번호, 보내는 박스 개수(1이상 10,000이하 정수)를 나타내는 양의 정수가 빈칸을 사이에 두고 주어진다. 박스를 받는 마을번호는 보내는 마을번호보다 크다.

출력
트럭 한 대로 배송할 수 있는 최대 박스 수를 한 줄에 출력한다.

풀이:
https://jaimemin.tistory.com/764
위 글을 참고하여 풀이했다.
트럭은 뒤로 돌아가지 않기 때문에 시작 도시로부터 가장 가까운 도시를 먼저 탐색하는 게 최선이다.
도착 도시를 오름차순, 같다면 시작 도시를 오름차순 정렬하고, 시작 -> 도착 사이의 택배 개수 중
가장 많은 택배 개수를 골라 용량이 넘치치 않게 담는다.
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

int n, c, m;
int cap[2001];
vector<pair<pii, int>> vt;

int main(void) {
	FIO;

	cin >> n >> c >> m;

	for (int i = 0; i < m; i++)
	{
		int src, dst, cnt;
		cin >> src >> dst >> cnt;

		vt.push_back({ {dst, src}, cnt });
	}

	sort(vt.begin(), vt.end());

	int ans = 0;

	for (int i = 0; i < m; i++)
	{
		int src = vt[i].first.second;
		int dst = vt[i].first.first;
		int cnt = vt[i].second;

		int maxCnt = 0;

		for (int j = src; j < dst; j++)
		{
			maxCnt = max(maxCnt, cap[j]);
		}

		int plus = min(cnt, c - maxCnt);
		ans += plus;

		for (int j = src; j < dst; j++)
		{
			cap[j] += plus;
		}
	}

	cout << ans;
}