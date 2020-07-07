/*
����
è�Ǿ� ���� ������� �յΰ� �ִ� ��ü���� ������Ƽ���� ���� �۰Ž� ������ �̹� ��⿡ 4-4-2 ���̾Ƹ�� ������ ����Ϸ��� �Ѵ�.

���� ������� �� ���� ���� 11���� �̸� ���ξ�����, � ������ ��� �����ǿ� ��ġ�ؾ� ���� ���� �������� ���ߴ�.

������ġ ����ũ ����� 11���� ������ ������ �����ǿ����� �ɷ��� 0���� 100������ ������ ��ġȭ �ߴ�. 0�� �� ������ �� �����ǿ� �������� �ʴٴ� ���̴�.

�̶�, ��� ������ �������� ���ϴ� ���α׷��� �ۼ��Ͻÿ�. ��� �����ǿ� ������ ��ġ�ؾ� �ϰ�, �� ������ �ɷ�ġ�� 0�� �����ǿ� ��ġ�� �� ����.

�Է�
�Է��� ���� ���� �׽�Ʈ ���̽��� �̷���� �ִ�. ù° �ٿ��� �׽�Ʈ ���̽��� ���� C�� �־�����. ������ ���̽��� 11�ٷ� �̷���� �ְ�, i�� ���� 0�� 100������ 11���� ���� sij�� �����ϰ� �ִ�. sij�� i�������� j�� �����ǿ��� �� ���� �ɷ��̴�. ��� �������� ������ �������� ���� �ִ� 5���̴�. (�ɷ�ġ�� 0���� ũ��)

���
������ �׽�Ʈ ���̽��� ���ؼ�, ��� �������� ������ ä���� ��, �ɷ�ġ�� ���� �ִ��� ����Ѵ�. �׻� �ϳ� �̻��� �ùٸ� ���ξ��� ���� �� �ִ�.

Ǯ��:
��Ʈ����ũ �����Դϴ�.

"��� �������� ä���� ��" �̹Ƿ� 11�� �����ǿ� ���� ��Ʈ����ũ�� �����Ͽ� �޸������̼��� ����ϸ� �ȴٴ� ���� �� �� �ֽ��ϴ�.
������ �����ǿ� ���ؼ��� üũ�� ���ָ� ���� �����ǿ� ���� ������ ������ �� �ֽ��ϴ�. ���� �޸������̼ǰ� ������ 
11���� ������ ���� ��Ʈ����ũ�� ����� �ش� ������ �̹� ������ �������� üũ���־�� �մϴ�.
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

int t;
int pos[11][11];
int memo[1 << 11];

void recul(int value, int bm_pos, int bm_man) {

	//�����ǿ� ���� �޸������̼�
	if (memo[bm_pos] >= value)	return;
	memo[bm_pos] = value;

	for (int i = 0; i < 11; i++)
	{
		if ((bm_man & (1 << i)) != 0)	continue;
		//������ �̹� �������� �ִٸ� �ǳʶ�

		for (int j = 0; j < 11; j++)
		{
			if (pos[i][j] == 0)	continue;
			if ((bm_pos & (1 << j)) != 0)	continue;
			//�������� �̹� �����Ǿ��ٸ� �ǳʶ�

			recul(value + pos[i][j], bm_pos | (1 << j), bm_man | (1 << i));
		}
	}
}

int main(void) {
	FIO;

	cin >> t;

	while (t--) {

		for (int i = 0; i < (1 << 11); i++)
		{
			memo[i] = -1;
		}

		for (int i = 0; i < 11; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				cin >> pos[i][j];
			}
		}

		recul(0, 0, 0);

		cout << memo[(1 << 11) - 1] << "\n";
	}
}