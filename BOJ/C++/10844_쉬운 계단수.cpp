/*
	����
45656�̶� ���� ����.

�� ���� ������ ��� �ڸ����� ���̰� 1�� ����. �̷� ���� ��� ����� �Ѵ�.

�����̴� ���� ���̰� N�� ��� ���� �� �� �ִ��� �ñ�������.

N�� �־��� ��, ���̰� N�� ��� ���� �� �� �� �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�. (0���� �����ϴ� ���� ����.)

�Է�
ù° �ٿ� N�� �־�����. N�� 1���� ũ�ų� ����, 100���� �۰ų� ���� �ڿ����̴�.

���
ù° �ٿ� ������ 1,000,000,000���� ���� �������� ����Ѵ�.
	Ǯ�� :
	���ڸ� ���������� �ϳ��ϳ� �ٿ��� �� 0�� 9 ����� x�� ���� ���� ���� ���鿡�� x-1�� x+1�� ��츦 ���ѰͰ� ����.
	0�� 9�� ������ 1�� 8�� �����ϹǷ� ������ 1�� 8�� ������ �����ָ� �ȴ�.
*/
#include<iostream>

using namespace std;

#define MOD 1000000000

int main(void) {

	int N;
	cin >> N;
	int num_before[10];
	int num_after[10];

	num_before[0] = 0;
	for (int i = 1; i < 10; i++)
	{
		num_before[i] = 1;
	}

	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < 10; j++) {
			if (j == 0) {
				num_after[j] = num_before[1]%MOD;
			}
			else if (j == 9) {
				num_after[j] = num_before[8]%MOD;
			}
			else {
				num_after[j] = (num_before[j - 1]%MOD + num_before[j + 1]%MOD)%MOD;
			}
		}
		for (int k = 0; k < 10; k++) {
			num_before[k] = num_after[k]%MOD;
		}
	}
	int sum = 0;
	for (int i = 0; i < 10; i++)
	{
		sum =(sum%MOD+ num_before[i]%MOD)%MOD;
	}
	cout << sum;
}