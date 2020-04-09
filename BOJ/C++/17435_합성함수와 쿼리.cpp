/*
����
�Լ� f : {1, 2, ..., m}��{1, 2, ..., m}�� �ִ�. �̶� fn : {1, 2, ..., m}��{1, 2, ..., m}�� ������ ���� ��������.

f1(x) = f(x)
fn+1(x) = f(fn(x))
���� ��� f4(1) = f(f(f(f(1))))�̴�.

n�� x�� �־��� �� fn(x)�� ����ϴ� ������ �����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù �ٿ� ���� m�� �־�����. (1 �� m �� 200,000)

���� �ٿ� f(1), f(2), ..., f(m)�� ���ʴ�� �־�����.

���� �ٿ� ������ ���� Q�� �־�����. (1 �� Q �� 200,000)

���� Q���� �ٿ� ���� ���� n�� x�� �־�����. (1 �� n �� 500,000; 1 �� x �� m)

���
�־����� n, x���� fn(x)�� ����Ѵ�.

Ǯ��:
��� ���̺��� �̿��� ���������ϴ�.

https://blog.naver.com/PostView.nhn?blogId=kks227&logNo=220793361738
�� ��α׸� �����߽��ϴ�.
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

int N, Q;
int jump[200001][19];


int main(void) {
	FIO;

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> jump[i][0];
	}

	for (int i = 1; i < 19; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			jump[j][i] = jump[jump[j][i - 1]][i - 1];
		}
	}

	cin >> Q;

	while (Q--) {
		int n, x;

		cin >> n >> x;

		int start = 1;

		for (int i = 18; i >= 0; i--)
		{
			if (n >= (1 << i)) {
				n -= (1 << i);
				x = jump[x][i];
			}
		}
		cout << x << "\n";
	}
}