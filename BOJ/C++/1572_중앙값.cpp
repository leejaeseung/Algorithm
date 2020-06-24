/*
문제
중앙값이란, 수열을 정렬했고, 그 크기가 N일 때, 1부터 시작해서 (N+1)/2번째 있는 원소가 그 수열의 중앙값이다. 예를 들어, {1, 2, 6, 5, 4, 3}에서는 3이고, {11, 13, 12, 15, 14}에서는 13이다.

오세준은 1초에 온도를 하나씩 재는 온도계를 만들었다. 이 온도계에는 작은 디스플레이 창이 하나 있는데, 이 창에는 지금부터 최근 K초 까지 온도의 중앙값을 표시해 준다. (온도를 재기시작한지 K초부터 표시한다. 그 전에는 아무것도 출력되지 않는다.)

오세준은 온도를 N초동안 쟀다. 그 시간 동안 온도계의 디스플레이 창에 뜨는 숫자의 합을 구하는 프로그램을 작성하시오.

다른 말로 하면, 길이가 N인 수열이 주어진다. 이 수열은 N-K+1 개의 길이가 K인 연속된 부분 수열이 존재한다. 이 부분 수열의 중앙값의 합을 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 N과 K가 주어진다. N은 250,000보다 작거나 같은 자연수이고, K는 5,000보다 작거나 같은 자연수이다. N은 항상 K보다 크거나 같다. 둘째 줄부터 N개의 수가 한 줄에 하나씩 주어진다. 입력으로 주어지는 수는 65536보다 작거나 같은 자연수 또는 0이다.

출력
둘째 줄에 정답을 출력한다. 정답은 int64범위다.

풀이:
세그먼트 트리 응용 문제입니다.
배열이 가질 수 있는 값의 범위는 0 ~ 65536으로 상당히 적습니다.
위 범위로 세그먼트 트리를 만드는데, 초가 지날 때마다 해당 온도에 해당하는 tree의 구간 합 값을 1증가시켜 줍니다.

그럼 세그먼트 트리엔 현재 구간에 각 온도값이 몇 개 존재하는지 구간 합으로 나타내어 집니다.
중앙값을 구하려면, 루트부터 왼쪽 오른쪽을 보면서 
mid값((k + 1) / 2) 보다 구간합이 크거나 같다면 -> 왼쪽
작다면 -> 오른쪽(이 때, mid값을 왼쪽 구간합만큼 빼주어야 합니다.)

leaf 노드가 해당 구간의 중앙값이 됩니다.
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

int n, k;
int tree[300000];
int arr[250001];
ll sum = 0;

int update(int now, int s, int e, int v, int idx) {
	if (idx < s || idx > e)	return tree[now];
	if (s == e) {
		return tree[now] += v;
	}
	
	return tree[now] = update(now * 2, s, (s + e) / 2, v, idx) + update(now * 2 + 1, (s + e) / 2 + 1, e, v, idx);
}

void get(int now, int s, int e, int mid) {
	
	if (s == e) {
		sum += s;
		return;
	}
	int left = tree[now * 2];
	int right = tree[now * 2 + 1];

	if (left >= mid) {
		get(now * 2, s, (s + e) / 2, mid);
	}
	else {
		get(now * 2 + 1, (s + e) / 2 + 1, e, mid - left);
	}
}

int main(void) {
	FIO;

	cin >> n >> k;

	for (int i = 1; i <= n; i++)
	{
		int v;
		cin >> v;
		arr[i] = v;
	}

	for (int i = 1; i <= n; i++)
	{
		update(1, 0, 65536, 1, arr[i]);
		if (i > k) 
			update(1, 0, 65536, -1, arr[i - k]);
		
		if(i >= k)
			get(1, 0, 65536, (k + 1) / 2);
	}

	cout << sum;
}