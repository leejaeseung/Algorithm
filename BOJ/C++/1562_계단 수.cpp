/*
����
45656�̶� ���� ����.

�� ���� ������ ��� �ڸ����� ���̰� 1�� ����. �̷� ���� ��� ����� �Ѵ�.

�׷�, ���õ� ���� �����̴� 0���� 9���� ��� �� �ڸ����� �ڸ����� �����ϸ鼭, ���� ���̰� N�� ��� ���� �� �� �ִ��� �ñ�������.

N�� �־��� ��, ���̰� N�̸鼭 0���� 9�� ��� �����ϴ� ��� ���� �� �� �� �ִ� �� ���ϴ� ���α׷��� �ۼ��Ͻÿ�. (0���� �����ϴ� ���� ����.)

�Է�
ù° �ٿ� N�� �־�����. N�� 1���� ũ�ų� ����, 100���� �۰ų� ���� �ڿ����̴�.

���
ù° �ٿ� ������ 1,000,000,000���� ���� �������� ����Ѵ�.

Ǯ��:
���ڸ� �ϳ��ϳ� �߰��ϸ� ���� ������ ���� ���� �־��� ���ڰ� �ٲ�� �˴ϴ�.
���� ���� ������ ���ڰ� 0 �̶�� 1 ��, 9 ��� 8 ��, 1 ~ 8 �̶�� +1 or -1 �� ���ڸ��� ������ �� �� �ֽ��ϴ�.

�������� 0 ~9 ������ ���ڰ� ��� ���� �Ѵٰ� �����Ƿ� 10 ���� ���ڿ� ���� ��Ʈ����ũ�� üũ�� ����� �մϴ�.
���� dp[������ ����][����][���ݱ��� ���� ���ڵ� ��Ʈ����ũ] �� ����� ���ڸ� �ϳ� �־��� ������ ���� ��Ʈ����ũ���� ���� ��� �����־�� �մϴ�.
*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>
#define pdd pair<double, double>
#define pic pair<int, char>
#define ll long long
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vii vector<pii>
#define IMAX 2000000001
#define LMAX 1000000000000000000
#define DMAX 0xFFFFFFFFFFFFF
int mv1[4] = { 0, 1, 0, -1 };
int mv2[4] = { 1, 0, -1, 0 };

int n;
ll divide = 1000000000;
ll dp[10][101][1024];

int main(void) {
	FIO;

	cin >> n;

	ll sum = 0;

	for (int i = 1; i < 10; i++)
	{
		//���� ���� 0�� �����ϰ� ��� 1�� �ʱ�ȭ
		dp[i][1][1 << i] = 1;
	}

		for (int i = 2; i <= n; i++)
		{

			for (int j = 0; j < 10; j++)
			{

				if (j == 0) {

					for (int k = 0; k < 1024; k++)
						//������ ��� ��Ʈ����ũ���� ������ ������
					{
						dp[j][i][k | (1 << 0)] = dp[j][i][k | (1 << 0)] % divide + dp[1][i - 1][k] % divide;
					}
				}
				else if (j == 9) {
					for (int k = 0; k < 1024; k++)
					{
						dp[j][i][k | (1 << 9)] = dp[j][i][k | (1 << 9)] % divide + dp[8][i - 1][k] % divide;
					}
				}
				else {
					for (int k = 0; k < 1024; k++)
					{
						dp[j][i][k | (1 << j)] = dp[j][i][k | (1 << j)] % divide + dp[j - 1][i - 1][k] % divide + dp[j + 1][i - 1][k] % divide;
					}
				}
			}
		}

		for (int i = 0; i < 10; i++)
		{
			//��Ʈ����ũ�� 1023�� ��쿡�� ���� ���� ���̹Ƿ� 1023�� dp�� ����.
			sum = ((sum % divide) + (dp[i][n][1023]) % divide) % divide;
		}

	cout << sum;
}