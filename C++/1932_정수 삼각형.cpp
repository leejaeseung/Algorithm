/*
	����
        7
      3   8
    8   1   0
  2   7   4   4
4   5   2   6   5
�� �׸��� ũ�Ⱑ 5�� ���� �ﰢ���� �� ����̴�.

�� ���� 7���� �����ؼ� �Ʒ��� �ִ� �� �� �ϳ��� �����Ͽ� �Ʒ������� ������ ��, �������� ���õ� ���� ���� �ִ밡 �Ǵ� ��θ� ���ϴ� ���α׷��� �ۼ��϶�. �Ʒ����� �ִ� ���� ���� ������ ���õ� ���� �밢�� ���� �Ǵ� �밢�� �����ʿ� �ִ� �� �߿����� ������ �� �ִ�.

�ﰢ���� ũ��� 1 �̻� 500 �����̴�. �ﰢ���� �̷�� �ִ� �� ���� ��� �����̸�, ������ 0 �̻� 9999 �����̴�.

�Է�
ù° �ٿ� �ﰢ���� ũ�� n(1 �� n �� 500)�� �־�����, ��° �ٺ��� n+1��° �ٱ��� ���� �ﰢ���� �־�����.

���
ù° �ٿ� ���� �ִ밡 �Ǵ� ��ο� �ִ� ���� ���� ����Ѵ�.

	Ǯ�� :
	[500][500] ũ���� �迭�� ����� [j][i]�� j��i������ ���� ���� �ִ� ������ �Ͽ� ���Ѵ�.
	[j][i]�� ���� �� �� �� �ִ밪�� ���� ���� ���� ���̴�.
	�� �𼭸��� ���� ���� ���� ���Ѵ�.
*/
#include<iostream>

using namespace std;

int max(int a, int b);

int main(void) {

	int N;
	cin >> N;
	int triagle[501][501];
	int output = 0;

	cin >> triagle[1][1];
	if (N >= 2) {
		for (int i = 2; i <= N; i++)
		{
			for (int j = 1; j <= i; j++)
			{
				int temp;
				cin >> temp;

				if (j == 1) {
					triagle[i][j] = temp + triagle[i - 1][j];
				}
				else if (j == i) {
					triagle[i][j] = temp + triagle[i - 1][j-1];
				}
				else {
					triagle[i][j] = max(triagle[i - 1][j - 1] + temp, triagle[i - 1][j] + temp);
				}
				if (output < triagle[i][j])
					output = triagle[i][j];
			}
		}
		cout << output;
	}
	else {
		cout << triagle[1][1];
	}
	return 0;
}
int max(int a,int b) {
	if (a >= b)
		return a;
	else
		return b;
}