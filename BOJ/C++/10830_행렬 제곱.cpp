/*
����
ũ�Ⱑ N*N�� ��� A�� �־�����. �̶�, A�� B������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�. ���� �ſ� Ŀ�� �� ������, A^B�� �� ���Ҹ� 1,000���� ���� �������� ����Ѵ�.

�Է�
ù° �ٿ� ����� ũ�� N�� B�� �־�����. (2 �� N ��  5, 1 �� B �� 100,000,000,000)

��° �ٺ��� N���� �ٿ� ����� �� ���Ұ� �־�����. ����� �� ���Ҵ� 1,000���� �۰ų� ���� �ڿ��� �Ǵ� 0�̴�.

���
ù° �ٺ��� N���� �ٿ� ���� ��� A�� B������ ����� ����Ѵ�.

Ǯ��:
2 1
1000 1000
1000 1000
�� ���� �׽�Ʈ ���̽��� �����ϸ� �˴ϴ�.
0 0
0 0
�� ���;� �մϴ�.
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