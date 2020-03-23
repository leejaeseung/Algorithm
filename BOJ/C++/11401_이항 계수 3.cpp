/*
����
�ڿ��� �� ���� �� �־����� �� ���� ��� �� 1,000,000,007�� ���� �������� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �� �� �־�����. (1 ��  �� 4,000,000, 0 ��  �� )

���
 �� 1,000,000,007�� ���� �������� ����Ѵ�.

 �Է��� 4000000 �̹Ƿ� Nlog(N) �� Ǯ�̷� Ǯ��� �ϴ� �����Դϴ�.
 �丣���� �������� �����Ͽ� Ǯ���߽��ϴ�.

 https://kyunstudio.tistory.com/60
*/
#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<vector>
#include<bitset>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pii pair<int, int>;

int N, K;
long long divide = 1000000007;

long long myPow(long long x, int n) {
	if (n == 1)
		return x % divide;

	long long temp = myPow(x, n / 2);
	if (n % 2 == 0) {
		return ((temp % divide) * (temp % divide)) % divide;
	}
	else {
		return ((((temp % divide) * (temp % divide)) % divide) * (x % divide)) % divide;
	}
}

long long factorial(long long x) {
	long long ret = 1;
	for (int i = 1; i <= x; i++)
	{
		ret = ((ret % divide) * (i % divide)) % divide;
	}
	return ret % divide;
}

int main(void) {
	FIO;

	cin >> N >> K;
	
	cout << ((factorial(N) % divide) * (myPow(((factorial(K) % divide) * (factorial(N - K) % divide)) % divide, divide - 2) % divide)) % divide;
}