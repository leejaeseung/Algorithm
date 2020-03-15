/*#include<iostream>
#include<algorithm>
using namespace std;

int N;
int parent[200001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	int now = -1;
	int size = 0;

	for (int i = 0; i < N; i++)
	{
		int next;
		size = max(size, next);
		cin >> next;

		if(i == 0){
			parent[next] = -1;
		}
		else {
			if (next != parent[now])
				parent[next] = now;
		}
		now = next;
	}
	cout << size + 1 << "\n";
	for (int i = 0; i <= size; i++)
	{
		cout << parent[i] << " ";
	}
}*/