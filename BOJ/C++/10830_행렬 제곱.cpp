/*
문제
크기가 N*N인 행렬 A가 주어진다. 이때, A의 B제곱을 구하는 프로그램을 작성하시오. 수가 매우 커질 수 있으니, A^B의 각 원소를 1,000으로 나눈 나머지를 출력한다.

입력
첫째 줄에 행렬의 크기 N과 B가 주어진다. (2 ≤ N ≤  5, 1 ≤ B ≤ 100,000,000,000)

둘째 줄부터 N개의 줄에 행렬의 각 원소가 주어진다. 행렬의 각 원소는 1,000보다 작거나 같은 자연수 또는 0이다.

출력
첫째 줄부터 N개의 줄에 걸쳐 행렬 A를 B제곱한 결과를 출력한다.

풀이:
2 1
1000 1000
1000 1000
과 같은 테스트 케이스만 조심하면 됩니다.
0 0
0 0
이 나와야 합니다.
*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<vector>
#include<stack>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>
#define ll long long

ll N, B;
int dv = 1000;
vector<vector<ll>> mat(5, vector<ll>(5, 0));

vector<vector<ll>> matMul(vector<vector<ll>> A, vector<vector<ll>> B) {
	vector<vector<ll>> res(5, vector<ll>(5, 0));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
			{
				res[i][j] = ((res[i][j]) % dv + ((A[i][k]) % dv * (B[k][j]) % dv) % dv) % dv;
			}
			res[i][j] %= dv;
		}
	}
	return res;
}

vector<vector<ll>> matpow(vector<vector<ll>> now, ll p) {

	if (p == 1 || p == 0) {
		return now;
	}

	vector<vector<ll>> temp = matpow(now, p / 2);

	if (p % 2 == 0) {
		return matMul(temp, temp);
	}
	else {
		return matMul(matMul(temp, temp), mat);
	}
}

int main(void) {
	FIO;

	cin >> N >> B;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> mat[i][j];
		}
	}

	vector<vector<ll>> out = matpow(mat, B);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (out[i][j] == 1000)
				out[i][j] = 0;
			cout << out[i][j] << " ";
		}
		cout << "\n";
	}
}