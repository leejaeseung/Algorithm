/*
����
������̶� ���� ������ ��������, � ������ �� ���ڵ��� Ư�� ���ڷ� �ٲٸ� �� ���ڰ� � �������� ���ߴ� �����̴�.

��ǥ������ SEND+MORE=MONEY�� �ִ�.

  SEND
+ MORE
------
 MONEY
S=9, E=5, N=6, D=7, M=1, O=0, R=8, Y=2�� �ٲٸ� ���� �����Ѵ�.

  9567
+ 1085
------
 10652
����� ������ �־��� ��, ���� �����ϴ��� ���θ� ����Ͻÿ�.

��, ���� ���ڴ� ���� ���ڿ� �����Ǿ�� �ϸ�, ���� �ٸ� ���ڴ� ���� �ٸ� ���ڸ� ��Ÿ����. ����, ���� 0���� ������ �� �ִ�.

�Է�
�� �ܾ ������ �ΰ� �־�����. ù ��° �ܾ�� �� ��° �ܾ ���� ����� �� ��° �ܾ����� �ǹ��Ѵ�.

�ܾ�� ���� ���� ���ĺ� �빮�ڷθ� �̷���� ������ �� �ܾ��� ���̴� 18�ڸ��� ���� �ʴ´�.

���
���Ŀ� �ش��� �����Ѵٸ� YES��, �׷��� �ʴٸ� NO�� �� �ٿ� ����Ѵ�.

Ǯ��:
���� Ž�� ���������ϴ�.
���ĺ����� ������ ��� �޾�(�ִ� 10��) ���� ���ĺ��� 0~9 �� ���� �Ҵ��ذ��� ���� �����ϴ��� �Ǵ��մϴ�.

���� ���ĺ��� �������� ������ �ð� �ʰ��� ���� �κ��� ���� �̻��� �� �����ϴ�.
*/
#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<vector>
#include<cstring>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>

string str1, str2, res, all;
vector<int> alpha;
int check[26];
bool visit[26];
bool checkNum[10];

int stringTonum(string s) {			//string�� ���ڷ� �ٲ�.
	int ret = 0;
	int mul = 1;
	for (int i = s.length() - 1; i >= 0; i--)
	{
		ret += check[s[i] - 'A'] * mul;
		mul *= 10;
	}
	return ret;
}

bool recul(int idx) {

	if (idx >= alpha.size()) {
		if (stringTonum(str1) + stringTonum(str2) == stringTonum(res))
			return true;
		return false;
	}

	for (int i = 0; i <= 9; i++)
	{
		if (checkNum[i])	continue;		//�̹� �Ҵ���� ���ڶ�� Pass
			check[alpha[idx]] = i;			//���ĺ��� ���ڸ� �Ҵ�
			checkNum[i] = true;				//���� �Ҵ� check
			if(recul(idx + 1))
				return true;
			check[alpha[idx]] = -1;			//�Ҵ��� Ǯ����
			checkNum[i] = false;			//��������
	}
	return false;
}

int main(void) {
	FIO;

	cin >> str1 >> str2 >> res;
	all = str1 + str2 + res;
	memset(check, -1, sizeof(int) * 26);

	for (int i = 0; i < all.length(); i++)
	{
		if (!visit[all[i] - 'A']) {
			//�ߺ��� �����Ͽ� ���ĺ��� ����.
			visit[all[i] - 'A'] = true;
			alpha.push_back(all[i] - 'A');		
		}
	}

	sort(alpha.begin(), alpha.end());

	if (alpha.size() <= 10) {
		if (recul(0))
			cout << "YES";
		else
			cout << "NO";
	}
	else
		cout << "NO";
}