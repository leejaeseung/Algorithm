/*
����
�����̴� ����� +, -, �׸��� ��ȣ�� ������ ���̰� �ִ� 50�� ���� �������. �׸��� ���� �����̴� ��ȣ�� ��� ������.

�׸��� ���� �����̴� ��ȣ�� ������ �ļ� �� ���� ���� �ּҷ� ������� �Ѵ�.

��ȣ�� ������ �ļ� �� ���� ���� �ּҷ� ����� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ���� �־�����. ���� ��0��~��9��, ��+��, �׸��� ��-�������� �̷���� �ְ�, ���� ó���� ������ ���ڴ� �����̴�. �׸��� �����ؼ� �� �� �̻��� �����ڰ� ��Ÿ���� �ʰ�, 5�ڸ����� ���� ���ӵǴ� ���ڴ� ����. ���� 0���� ������ �� �ִ�.

���
ù° �ٿ� ������ ����Ѵ�.

Ǯ��:
- �� ������ ������ ���� ���ϴٰ� - �� �� ���̶� ������ �� ������ ������ ��� ���ݴϴ�.
*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<string>
#include<vector>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>

int p = 0;
string str;

int getNum() {

	int ret = str[p++] - '0';
	int mul = 10;
	while (str[p] >= '0' && str[p] <= '9') {
		ret = ret * mul + (str[p] - '0');
		p++;
	}
	return ret;
}

int main(void) {
	FIO;

	cin >> str;

	int sum = 0;
	int minus = 1;

	while (true) {
		sum += getNum() * minus;

		if (p >= str.size())	break;
		if (str[p] == '-' && minus == 1) {
			minus = -1;
		}
		p++;
	}
	cout << sum;
}