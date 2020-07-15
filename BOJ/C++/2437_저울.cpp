/*
문제
하나의 양팔 저울을 이용하여 물건의 무게를 측정하려고 한다. 이 저울의 양 팔의 끝에는 물건이나 추를 올려놓는 접시가 달려 있고, 양팔의 길이는 같다. 또한, 저울의 한쪽에는 저울추들만 놓을 수 있고, 다른 쪽에는 무게를 측정하려는 물건만 올려놓을 수 있다.



무게가 양의 정수인 N개의 저울추가 주어질 때, 이 추들을 사용하여 측정할 수 없는 양의 정수 무게 중 최솟값을 구하는 프로그램을 작성하시오.

예를 들어, 무게가 각각 3, 1, 6, 2, 7, 30, 1인 7개의 저울추가 주어졌을 때, 이 추들로 측정할 수 없는 양의 정수 무게 중 최솟값은 21이다.

입력
첫 째 줄에는 저울추의 개수를 나타내는 양의 정수 N이 주어진다. N은 1 이상 1,000 이하이다. 둘째 줄에는 저울추의 무게를 나타내는 N개의 양의 정수가 빈칸을 사이에 두고 주어진다. 각 추의 무게는 1이상 1,000,000 이하이다.

출력
첫째 줄에 주어진 추들로 측정할 수 없는 양의 정수 무게 중 최솟값을 출력한다.

풀이:
무게가 가장 작은 추부터 하나씩 다음 추를 보며 그리디하게 풀이합니다.

minWeight = 현재까지 만들 수 있는 최대 추의 무게 로 정의하고,
다음 추의 무게가 minWeight + 1 보다 크지 않다면, minWeight에 다음 추의 무게를 더해줍니다.

왜냐하면, minWeight + 1 보다 크지 않다는 의미는 현재 minWeight까지 모든 무게를 만들 수 있는 상태인데,
다음 추의 무게에 minWeight 까지의 모든 조합을 사용하면 minWeight + (다음 추 무게) 까지 모두 커버가 가능하기 때문입니다.
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
priority_queue<int> pq;

int main(void) {
	FIO;

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		int v;
		cin >> v;

		pq.push(-v);
	}
	
	int minWeight = 0;

	while (!pq.empty()) {
		int nowWeight = -pq.top();	pq.pop();

		if (nowWeight <= minWeight + 1) {
			minWeight += nowWeight;
		}
		else {
			break;
		}
	}

	cout << minWeight + 1;
}