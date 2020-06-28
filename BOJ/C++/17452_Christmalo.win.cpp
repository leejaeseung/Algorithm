/*
����
�������� Ki-pop ��ǳ�� �̲��� �ִ� Ű�Ĵ� ���翡 ���� �� �ٹ��� ��ø� �յΰ� ��ο� ������.

���� ���� ����?

Ű���� �ٹ��� �׻� ���� ������� ���� �ܾ ����ϴ� ������ �ִ�. ���뿡 ������, Ű�Ĵ� �ٹ��� ��︮�� �ܾ� �� ���� ������ ���� �� �ܾ�� ����� ���ĺ��� �ϳ� �����ϰ�, �տ� �� �ܾ�� �� ���ĺ� ���� ���ڵ��� �����, �ڿ� �� �ܾ���� �� ���ĺ� ���� ���ڵ��� ���� �� �� �ܾ ���ļ� ���ο� �ٹ��� ������ ���Ѵ�. ���� ���ĺ��� ���� �� �����Ѵٸ� ���� ���ϴ� ���� �ƹ��ų� �����Ѵ�.

���� ��� christmas�� halloween�� �����ߴٸ�, ����� ���ĺ� a�� �����Ͽ� christma�� alloween�� ����� �� ���� ���ļ� christmalloween�� �ȴ�.

Ű�Ĵ� �ٹ��� ��︮�� �ܾ� N���� ������ ������, ������ ���ϴ� ���� �������� ������ ������ �ּҰ� �ǰ� ���� �޶�� ��Ź�� �Բ� ��ſ��� �ð� �ΰ� ������ �Ϸ� ������. Ű���� ���ݻ� ����� Ű�İ� ���ƿ��� ���� ������ ���ؾ� �Ѵ�!

�Է�
ù° �ٿ� ���ڿ��� ���� N�� �־�����. ���� N�� �ٿ� ���� �ٸ� ���ڿ� Si�� �־�����. ������ ���ڿ��� 20�� ������ ���ĺ� �ҹ��ڸ����� �����Ǿ� �ִ�.

2 �� N �� 105
2 �� |Si| �� 20
Si �� Sj if i �� j
���
�־��� ���ǿ� �°� ������ ������ ������ �ּҷ� �ϴ� �ܾ ������� ��, ������ ������ ������ ����Ѵ�. �־��� ���ǿ� �´� �ܾ ���� �� ���� ��� -1�� ����Ѵ�.

Ǯ��:
�� ���ڿ����� ���� �۾��� ���ݴϴ�.

�ش� ���ڿ��� ���ĺ� x�� ���� ��, �� �ʿ��� x�� ó�� ���� ������ ���� ������ �� �ʿ��� x�� ó�� ���� ������ ���� ������ �����ݴϴ�.

�� ����, ��� 26���� ���ĺ��� ���Ͽ�, ���ĺ��� �ϳ� ���ϰ� �� ���ĺ��� ���ʿ� �ִ� ������ ���� ���� ���ڿ��� ����, 
���������� ���ʿ� �ִ� ������ ���� ���� ���ڿ��� ���ϴ�. (���ڿ��� �ߺ��ǰų�, ���ĺ��� ������ ���� �ʴ� ��츦 �ɷ��ݴϴ�.)

����, ������ ������ ���� ���� ���� �ּ��� ���ĺ��� ���� ������ �˴ϴ�.
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
int front[100001][26];
int back[100001][26];
bool check[100001];

int main(void) {

	FIO;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		
		for (int j = 0; j < 26; j++)
		{
			front[i][j] = -1;
			back[i][j] = -1;


			char findAlpha = j + 'a';
			for (int k = 0; k < str.length(); k++)
			{
				char c = str[k];

				if (c == findAlpha) {
					front[i][j] = k;
					break;
				}
			}

			for (int k = str.length() - 1; k >= 0; k--)
			{
				char c = str[k];

				if (c == findAlpha) {
					back[i][j] = str.length() - k - 1;
					break;
				}
			}
		}
	}

	int ans = IMAX;

	for (int i = 0; i < 26; i++)
	{
		for (int i = 0; i < n; i++)
		{
			check[i] = false;
		}

		int minF = IMAX;
		int minB = IMAX;

		int checkIdx = -1;

		for (int j = 0; j < n; j++)
		{
			if (front[j][i] == -1)continue;
			if (minF > front[j][i]) {
				minF = front[j][i];
				checkIdx = j;
			}
		}
		if (checkIdx == -1)	continue;
		check[checkIdx] = true;

		for (int j = 0; j < n; j++)
		{
			if (front[j][i] == -1)continue;
			if (check[j])	continue;
			if (minB > back[j][i]) {
				minB = back[j][i];
			}
		}
		if (minB == IMAX)	continue;

		ans = min(ans, minB + minF);
	}
	if (ans == IMAX)
		cout << "-1";
	else
		cout << ans;
	
}