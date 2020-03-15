#include<iostream>
#include<queue>

using namespace std;

int main(void) {
	
	priority_queue<int> pq;
	int a, b, c;
	
	cin >> a >> b >> c;

	pq.push(a);
	pq.push(b);
	pq.push(c);


	pq.pop();
	cout << pq.top()<<endl;
	return 0;
	}