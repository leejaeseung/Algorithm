/*
����
n��m�� 0, 1�� �� �迭�� �ִ�. �� �迭���� 1�� �� ���� ū ���簢���� ũ�⸦ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

0	1	0	0
0	1	1	1
1	1	1	0
0	0	1	0
���� ���� ���������� ����� 2��2 �迭�� ���� ū ���簢���̴�.

�Է�
ù° �ٿ� n, m(1 �� n, m �� 1,000)�� �־�����. ���� n���� �ٿ��� m���� ���ڷ� �迭�� �־�����.

���
ù° �ٿ� ���� ū ���簢���� ���̸� ����Ѵ�.

Ǯ��:
dp[i][j]�� (i,j)�� ������ �Ʒ� ���������� �ϴ� ���簢���� �� ���� ���̷� �����Ѵ�.
���� ���������� Ž���ذ��鼭 ����, ���� ��, ���� �� �ּڰ� + 1 �� dp[i][j] �� �ȴ�.
dp[i][j] �� 0�� ���� ���簢���� ���� �� �����Ƿ� �״�� 0�̴�.
*/
#include<iostream>
#include<algorithm>
using namespace std;

int N, M;
int dp[1001][1001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	char s[1001];

	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> s;
		for (int j = 0; j < M; j++)
		{
			if (s[j] - '0' == 0)	continue;
			if (i == 0 && j == 0) {
				dp[i][j] = s[j] - '0';
			}
			else if (i == 0) {
				dp[i][j] = 1;
			}
			else if (j == 0) {
				dp[i][j] = 1;
			}
			else {
				dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
			}
			ans = max(ans, dp[i][j]);
		}
		
	}

	cout << ans * ans;
}