/*
문제
정렬된 두 묶음의 숫자 카드가 있다고 하자. 각 묶음의 카드의 수를 A, B라 하면 보통 두 묶음을 합쳐서 하나로 만드는 데에는 A+B 번의 비교를 해야 한다. 이를테면, 20장의 숫자 카드 묶음과 30장의 숫자 카드 묶음을 합치려면 50번의 비교가 필요하다.

매우 많은 숫자 카드 묶음이 책상 위에 놓여 있다. 이들을 두 묶음씩 골라 서로 합쳐나간다면, 고르는 순서에 따라서 비교 횟수가 매우 달라진다. 예를 들어 10장, 20장, 40장의 묶음이 있다면 10장과 20장을 합친 뒤, 합친 30장 묶음과 40장을 합친다면 (10+20)+(30+40) = 100번의 비교가 필요하다. 그러나 10장과 40장을 합친 뒤, 합친 50장 묶음과 20장을 합친다면 (10+40)+(50+20) = 120 번의 비교가 필요하므로 덜 효율적인 방법이다.

N개의 숫자 카드 묶음의 각각의 크기가 주어질 때, 최소한 몇 번의 비교가 필요한지를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N이 주어진다. (1≤N≤100,000) 이어서 N개의 줄에 걸쳐 숫자 카드 묶음의 각각의 크기가 주어진다.

출력
첫째 줄에 최소 비교 횟수를 출력한다. (21억 이하)

풀이:
최소 힙을 이용한 문제입니다. 살짝 그리디 알고리즘이기도 합니다.
항상 묶음 두 개를 고를 수 있기 때문에 그 시점에 가장 작은 두 개를 뽑아가는 것이 최선입니다.

즉, 우선순위 큐에서 두 개를 뽑고, 결과를 다시 큐에 넣어가며 풀이합니다.
*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<vector>
#include<queue>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>

int N;

int main(void) {
	FIO;

	priority_queue<long long> pq;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		long long n;
		cin >> n;
		pq.push(-n);
	}
	long long sum = 0;

	while (pq.size() >= 2) {
		long long A = -pq.top();	pq.pop();
		long long B = -pq.top();	pq.pop();
		sum += -(A + B);
		pq.push(-(A + B));
	}
	cout << -sum;
}