/*
����
���ؿ� ��� ������ �������� �л����� �ǵ����̸� ���� �ܾ ���� �� �ֵ��� �Ϸ��� �Ѵ�. �׷��� �����³�ȭ�� ���� ������ ��Ƽ� �� �б��� �������� ������, �������� K���� ���ڸ� ����ĥ �ð� �ۿ� ����. �������� ����ġ�� �� �Ŀ���, �л����� �� K���� ���ڷθ� �̷���� �ܾ�� ���� �� �ִ�. �������� � K���� ���ڸ� �����ľ� �л����� ���� �� �ִ� �ܾ��� ������ �ִ밡 �Ǵ��� ��ο� ������.

���ؾ���� ��� �ܾ�� "anta"�� ���۵ǰ�, "tica"�� ������. ���ؾ� �ܾ�� N�� �ۿ� ���ٰ� �����Ѵ�. �л����� ���� �� �ִ� �ܾ��� �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �ܾ��� ���� N�� K�� �־�����. N�� 50���� �۰ų� ���� �ڿ����̰�, K�� 26���� �۰ų� ���� �ڿ��� �Ǵ� 0�̴�. ��° �ٺ��� N���� �ٿ� ���� ����� �ܾ �־�����. �ܾ�� ���� �ҹ��ڷθ� �̷���� �ְ�, ���̰� 8���� ũ�ų� ����, 15���� �۰ų� ����. ��� �ܾ�� �ߺ����� �ʴ´�.

���
ù° �ٿ� �������� K���� ���ڸ� ����ĥ ��, �л����� ���� �� �ִ� �ܾ� ������ �ִ��� ����Ѵ�.

Ǯ��:
��Ʈ����ũ, ���Ʈ����, ���ڿ� ó�� ���������ϴ�.
26���� ���ĺ� �� k���� �̾��� �� �� �� �ִ� �ܾ��� ���� �ִ밡 �Ǿ� �մϴ�.

��� �ܾ ���� �ش� �ܾ��� ���ĺ��鿡 ���� ��Ʈ����ũ�� ���س���, 
26�� ���ĺ� �� k���� �̾��� �� ��� �ܾ��� ���ذ��� ��Ʈ����ũ�� ��ġ�� ��� ī��Ʈ�� �÷��ָ� �˴ϴ�.

a,n,t,i,c �� �׻� ���ԵǹǷ� ��Ʈ����ũ�� �� ó���� �߰��� �־� �ð��� ������ �� �ֽ��ϴ�.
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
#define IMAX 2100000001
#define LMAX 1000000000000000000
#define DMAX 0xFFFFFFFFFFFFF
int mv1[4] = { 0, 1, 0, -1 };
int mv2[4] = { -1, 0, 1, 0 };

int n, k;
int word_bitmask[51];
int ans = 0;

void recul(int now_bitmask, int word_cnt, int prev) {

	if (word_cnt == k) {
		//k���� ���ĺ��� �̾��� ��

		int cnt = 0;

		for (int i = 0; i < n; i++)
		{
			if ((word_bitmask[i] | now_bitmask) == now_bitmask)
				cnt++;
		}

		ans = max(ans, cnt);

		return;
	}

	for (int i = prev; i < 26; i++)
		//������ ������� ����
	{
		int nextBit = 1 << i;

		if ((now_bitmask & nextBit) == 0) {
			//��Ʈ����ũ�� ������� ��
			recul(now_bitmask | nextBit, word_cnt + 1, i + 1);
		}
	}
}

int main(void) {
	FIO;

	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;

		for (int j = 0; j < str.size(); j++)
		{
			int c = str[j] - 'a';

			word_bitmask[i] |= (1 << c);
		}
	}

	int init_bitmask = 0;

	for (int i = 0; i < 26; i++)
	{
		if (i == 'a' - 'a' || i == 'n' - 'a' || i == 'i' - 'a' || i == 'c' - 'a' || i == 't' - 'a') {
			init_bitmask |= (1 << i);
		}
	}

	recul(init_bitmask, 5, 1);

	cout << ans;
}