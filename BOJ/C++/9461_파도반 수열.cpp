/*
	Ǯ�� : 6��°���� i��° = i-1���� + i-5 ��°�� ��ȭ�� �����̴�.
*/
#include<iostream>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio;
	cin.tie(NULL);

	int T;
	cin >> T;
	long long arr[101];
	arr[1] = 1;
	arr[2] = 1;
	arr[3] = 1;
	arr[4] = 2;
	arr[5] = 2;
	for (int i = 6; i <= 100; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 5];
	}
	for (int i = 0; i < T; i++)
	{
		int N;
		cin >> N;
		cout << arr[N] << endl;
	}
}