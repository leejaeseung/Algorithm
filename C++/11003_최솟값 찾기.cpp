//덱 이용하는 구데기 문제.

#include<iostream>
#include<deque>
using namespace std;

int value[5000001];
deque<int> dq;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, L, v;;
	cin >> N >> L;

	for (int i = 0; i < N; i++)
	{
		cin >> value[i];

		while (!dq.empty() && value[dq.back()] > value[i])	dq.pop_back();
		dq.push_back(i);

		if (dq.front() <= i - L)	dq.pop_front();

		cout << value[dq.front()] << " ";
	}
}