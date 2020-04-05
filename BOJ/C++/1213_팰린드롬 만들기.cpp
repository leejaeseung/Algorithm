/*
����
���Ѽ��� �ӹ����� ���� ����ϴ� �����̴�.

���Ѽ��� ���󿡼� �Ӹ������ ���ڿ��� �ʹ� �����ϱ� ������, ���� ������ ����ؼ� �ӹ����� �Ӹ������ �������ַ��� �Ѵ�.

�ӹ����� ���Ѽ��� ���� �̸����� �Ӹ������ ������� �ϴµ�, ���Ѽ��� ���� �̸��� ���ĺ� ������ ������ �ٲ㼭 �Ӹ������ ������� �Ѵ�.

�ӹ����� ���� ���Ѽ��� ���� �̸��� �Ӹ�������� �ٲٴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ���Ѽ��� ���� �̸��� �ִ�. ���ĺ� �빮�ڷθ� �� �ִ� 50�����̴�.

���
ù° �ٿ� ������ ������ ����Ѵ�. ���� �Ұ����� ���� "I'm Sorry Hansoo"�� ����Ѵ�. ������ ���� ���� ��쿡�� ���������� �ռ��� ���� ����Ѵ�.

Ǯ��:
Ȧ���� ���ĺ� ������ 2�� �̻��̸� �Ӹ������ ���� �� �����ϴ�.

�׸����ϰ� ���� ���ĺ����� �� ���ĺ��� ���� / 2 ���� �ٿ����� ���� ������ �����, 
������ �������� �����ʿ� �ٿ��ݴϴ�.
���� Ȧ�� ���� ���ĺ��� �ϳ� �־��ٸ� �߰��� �����־� �ݴϴ�.
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

string str;
int alpha[26];
int leng;

int main(void) {
	FIO;

	cin >> str;
	leng = str.size();

	for (int i = 0; i < str.size(); i++)
	{
		alpha[str.at(i) - 'A']++;
	}

	int flag = 0;
	int mid = -1;

	for (int i = 0; i < 26; i++)
	{
		if (alpha[i] > 0 && alpha[i] % 2 == 1) {
			flag++;
			alpha[i]--;
			mid = i;
		}
	}

	if (flag > 1)
		cout << "I'm Sorry Hansoo";
	else {
		string ans = "", temp;

		for (int i = 0; i < 26; i++)
		{
			if (alpha[i] > 0) {
				for (int j = 0; j < alpha[i] / 2; j++)
				{
					ans += i + 'A';
				}
			}
		}
		temp = ans;
		reverse(temp.begin(), temp.end());

		if(mid != -1)
		ans += mid + 'A';

		cout << ans + temp;
	}
}