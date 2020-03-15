/*
	풀이 : 이차원 배열[N+1][10] 을 선언해 [x][y] 엔 x번째 자릿수가 y일 때의 개수를 넣어준다. 
	그 개수는 x-1번째의 y보다 큰 값들의 합이다.
*/
#include<iostream>
#include<vector>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int N;
		cin >> N;
		vector<vector<long long>> vt;
		vt.resize(N + 1);
		for (int j = 1; j <= N; j++)
		{
			vt.at(j).resize(10);
			if (j == 1) {
				for (int k = 0; k < 10; k++)
				{
					vt.at(j).at(k)= 1;
				}
			}
		}
		for (int j = 2; j <= N; j++)
		{
			for (int k = 0; k < 10; k++) {
				for (int l = k; l <10; l++) {
					vt.at(j).at(k) += vt.at(j - 1).at(l);
				}
			}
		}
		long long res = 0;
		for (int i = 0; i <10; i++)
		{
			res += vt.at(N).at(i);
		}
		cout << res << endl;
	}
}