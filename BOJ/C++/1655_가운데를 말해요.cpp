/*
문제
수빈이는 동생에게 "가운데를 말해요" 게임을 가르쳐주고 있다. 수빈이가 정수를 하나씩 외칠때마다 동생은 지금까지 수빈이가 말한 수 중에서 중간값을 말해야 한다. 만약, 그동안 수빈이가 외친 수의 개수가 짝수개라면 중간에 있는 두 수 중에서 작은 수를 말해야 한다.

예를 들어 수빈이가 동생에게 1, 5, 2, 10, -99, 7, 5를 순서대로 외쳤다고 하면, 동생은 1, 1, 2, 2, 2, 2, 5를 차례대로 말해야 한다. 수빈이가 외치는 수가 주어졌을 때, 동생이 말해야 하는 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에는 수빈이가 외치는 정수의 개수 N이 주어진다. N은 1보다 크거나 같고, 100,000보다 작거나 같은 자연수이다. 그 다음 N줄에 걸쳐서 수빈이가 외치는 정수가 차례대로 주어진다. 정수는 -10,000보다 크거나 같고, 10,000보다 작거나 같다.

출력
한 줄에 하나씩 N줄에 걸쳐 수빈이의 동생이 말해야하는 수를 순서대로 출력한다.

풀이:

최대 힙과 최소 힙 두개를 사용하여, 최대 힙의 top이 항상 중간값을 가르키게 만든다.

Heap의 성질을 이용하여 중앙값보다 작을 값들은 MaxHeap에, 중앙값보다 큰 값들은 MinHeap에 넣어준다.

1. 일단 처음에 왼쪽부터(MaxHeap) 넣는다.

2. 오른쪽(MinHeap)이 비어있거나, 오른쪽의 최소값보다 작은 값이 들어올 경우 MaxHeap에 넣어준다.

3. MaxHeap과 MinHeap의 사이즈를 공평하게 해준다.

3-1. MaxHeap의 사이즈가 MinHeap의 사이즈보다 2개 이상 많을 때 MaxHeap의 top값을 MinHeap으로 이동시켜준다.

3-2. MinHeap의 사이즈가 MaxHeap의 사이즈보다 커질 때는 MinHeap의 top값을 MaxHeap으로 이동시켜준다.

4. 홀수번째 수가 주어질 때마다 MaxHeap의 Top값을 출력한다.
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
using namespace std;

int N;
priority_queue<int> max_q;
priority_queue<int> min_q;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int  i = 1; i <= N; i++)
	{
		int now;
		cin >> now;

		if (min_q.empty() || min_q.top() * -1 > now) {
			max_q.push(now);
		}
		else
			min_q.push(now * -1);
		if (max_q.size() >= min_q.size() + 2) {
			min_q.push(max_q.top() * -1);
			max_q.pop();
		}
		if (max_q.size() < min_q.size()) {
			max_q.push(min_q.top() * -1);
			min_q.pop();
		}
		if (i % 2 == 0) {
			cout << min(max_q.top(), min_q.top() * -1);
		}
		else {
			cout << max_q.top();
		}
		cout << "\n";
	}
}