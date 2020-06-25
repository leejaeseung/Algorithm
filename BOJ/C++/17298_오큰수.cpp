/*
문제
크기가 N인 수열 A = A1, A2, ..., AN이 있다. 수열의 각 원소 Ai에 대해서 오큰수 NGE(i)를 구하려고 한다. Ai의 오큰수는 오른쪽에 있으면서 Ai보다 큰 수 중에서 가장 왼쪽에 있는 수를 의미한다. 그러한 수가 없는 경우에 오큰수는 -1이다.

예를 들어, A = [3, 5, 2, 7]인 경우 NGE(1) = 5, NGE(2) = 7, NGE(3) = 7, NGE(4) = -1이다. A = [9, 5, 4, 8]인 경우에는 NGE(1) = -1, NGE(2) = 8, NGE(3) = 8, NGE(4) = -1이다.

입력
첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000,000)이 주어진다. 둘째에 수열 A의 원소 A1, A2, ..., AN (1 ≤ Ai ≤ 1,000,000)이 주어진다.

출력
총 N개의 수 NGE(1), NGE(2), ..., NGE(N)을 공백으로 구분해 출력한다.

풀이:
스택 문제인데, 우선순위 큐로도 풀이가 가능한 문제입니다.
1번째 원소부터 끝까지 우선순위 큐에 넣으며 풀이합니다.

현재 수를 큐에 넣기 전, 큐의 top(오름차순으로 정렬합니다.) 이 현재 넣으려는 수보다 크다면, 그 수가 오큰수이므로
현재 수 -> 큐의 top으로 연결해줍니다.
현재 수보다 큐의 top이 작거나 같아질 때까지 반복합니다.
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
int mv1[4] = { 0, 1, 0, -1 };
int mv2[4] = { 1, 0, -1, 0 };

int n;
int arr[1000001];
int value[1000001];
priority_queue<pii> pq;

int main(void) {
	FIO;

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int v;
		cin >> v;
		arr[i] = v;
		value[i] = -1;
	}

	pq.push(make_pair(-arr[1], 1));

	for (int i = 2; i <= n; i++)
	{
		int now = arr[i];

		while (!pq.empty() && now > -pq.top().first) {
			value[pq.top().second] = now;
			//오큰수 연결
			pq.pop();
		}
		pq.push(make_pair(-now, i));
	}

	for (int i = 1; i <= n; i++)
	{
		cout << value[i] << " ";
	}
}