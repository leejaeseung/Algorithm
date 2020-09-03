/*
����
�� �ʸ��� ��ȣ�� �߻���Ű�� �� ��ġ A, B�� �ִ�. �� ��ȣ�� ���ĺ� �ҹ����� ������ ǥ���ȴ�. A, B�κ��� �߻��� ��ȣ�� ������ ǥ���� SA, SB�� ���� ������ ����.

SA = [a, f, c, d, r, d, e, s, d, c, f, w, s, z, r]
SB = [g, e, d, s, r, d, d, e, m, z, r]
��ȣ ������ � ������ ���Ե� ������ ������ ������ ������ ������� �����ϸ� �� �� �������� ���С��� ���ٰ� �Ѵ�. �Ʒ����� �ڽ��� ǥ�õ� �κ��� �� ��ȣ SA, SB���� ������ ���� ������ ��Ÿ���� �ִ�.



�� ���� ���� ���� ������ ���� ������ ���̴� �� �������� �ݵ�� ���ƾ� �Ѵ�. �׸��� ���� ���� �� ������ �ϳ� �̻� ������ �� �ִ�. �츮�� �� ��ȣ ������ ���� �����ϴ� ���� ���� ���� �߿� �� ���� �� ���� ã������ �Ѵ�.

�Է�
ù �� �ٿ� ��ȣ ������ ���� ���� �ϳ��� ���ڿ��� ���� �־�����. �� ���ڿ��� ���� �ҹ��ڷθ� �����Ǿ� �ִ�. �� �Է� ���ڿ��� ũ�� N, M�� ������ 1 �� N, M �� 1,500 �̴�.

���
�� �������� ���� ������ ���� ���� �߿��� ���� �� ������ ã��, �� ������ ���̸� ����ؾ� �Ѵ�.

Ǯ��:
���-ī�� �˰����� ��¦ �����ϰ�, prefix sum�� �̿��� ���� Ž������ Ǯ���ߴ�.

��� ���ĺ��� ���� �ؽ� ���� ������ ���� �ξ���.
a = 1, b = 2, c = 3, d = 4 ...
��, aba = 1 + 2 + 1 = 4, baa = 2 + 1 + 1 �� �Ǿ� �ڸ��� �ٸ����� �� �ؽð��� ���ٸ� ������ ������ �����ϰ� �ȴ�.
������ bb = 2 + 2 = 4 == aba ó�� ���ڿ��� �ٸ����� �ؽð��� ���� �� �ֱ� ������ �浹�� ó���� �־�� �Ѵ�.

����, ���ڿ�1�� ���� ���-ī�� �˰���� ���� ������� ���̰� m �� �κ� ���ڿ��鿡 ���� ��� H ���� ���Ѵ�.
(��, ���̰� ���� ���� �ϹǷ� m�� �ִ� ���̺��� �����Ѵ�.)

�׸��� ������ H ����(50000�� ���� �ʴ´� -> 27 * 1500) �� ���� index�� üũ �迭�� push �Ѵ�.
�������� ���ڿ�2�� ���� ���� ������� H�� ���� �����µ� ���ڿ�1���� H�� ���Ծ��ٸ� -> �浹�̹Ƿ� �� �κ� ���ڿ��� �˻��Ѵ�.

�� �� �κ� ���ڿ��� ������ �˻��Ϸ��� N^2 �� �ð��� �ɸ� �� �����Ƿ� ���ڿ�1, ���ڿ�2�� ���� �� �ڸ������� 
���ĺ� �� prefix sum�� ���� ����, �� �κ� ���ڿ��� ������ ���� 26�� �ݺ����ָ� �� �κ� ���ڿ��� ��ġ�ϴ��� ���θ� �˾Ƴ� �� �ִ�.
*/
#include<iostream>
#include<memory.h>
#include<algorithm>
#include<math.h>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>
#define pdd pair<double, double>
#define pic pair<int, char>
#define ll long long
#define pll pair<ll, ll>
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vii vector<pii>
#define IMAX 2000000001
#define LMAX 1000000000000000000
#define DMAX 0xFFFFFFFFFFFFF
#define MOD 100003
int mv1[4] = { 0, 0, 1, -1 };
int mv2[4] = { 1, -1, 0, 0 };
int mv_all1[8] = { 0, 1, 0, -1, -1, -1, 1, 1 };
int mv_all2[8] = { 1, 0, -1, 0 , -1, 1, -1, 1 };

int sum1[1501][26];
int sum2[1501][26];
vector<int> visit[50000];

int main(void) {
	FIO;

	string str1;
	string str2;

	cin >> str1 >> str2;

	for (int i = 1; i <= str1.size(); i++)
	{
		for (int j = 0; j < 26; j++)
		{
			if (j == str1[i - 1] - 'a') {
				sum1[i][j] = sum1[i - 1][j] + 1;
			}
			else {
				sum1[i][j] = sum1[i - 1][j];
			}
		}
	}

	for (int i = 1; i <= str2.size(); i++)
	{
		for (int j = 0; j < 26; j++)
		{
			if (j == str2[i - 1] - 'a') {
				sum2[i][j] = sum2[i - 1][j] + 1;
			}
			else {
				sum2[i][j] = sum2[i - 1][j];
			}
		}
	}
	//�� ���ڿ��� ���� �� �ڸ������� ���ĺ����� ������ ����.

	int ans = 0;

	for (int mid = min(str1.size(), str2.size()); mid > 0; mid--) {

		int H = 0;
		for (int i = 0; i < 50000; i++)
		{
			visit[i].clear();
		}

		for (int i = 0; i <= str1.size() - mid; i++)
		{
			if (i == 0) {

				for (int j = 0; j < mid; j++)
				{
					H += (str1[j] - 'a' + 1);
				}
			}
			else {
				H = H - (str1[i - 1] - 'a' + 1) + (str1[i + mid - 1] - 'a' + 1);
			}

			visit[H].push_back(i);
		}

		H = 0;

		bool find = false;

		for (int i = 0; i <= str2.size() - mid; i++)
		{
			if (i == 0) {

				for (int j = 0; j < mid; j++)
				{
					H += (str2[j] - 'a' + 1);
				}
			}
			else {
				H = H - (str2[i - 1] - 'a' + 1) + (str2[i + mid - 1] - 'a' + 1);
			}

			if (visit[H].size()) {
				//�ؽ� �浹

				for (int j = 0; j < visit[H].size(); j++)
				{
					bool match = true;

					for (int k = 0; k < 26; k++)
					{
						//�� �κ� ���ڿ��� �������� ���ĺ��� ������ ��ġ�ϴ��� Ȯ��
						if (sum1[visit[H][j] + mid][k] - sum1[visit[H][j]][k] != sum2[i + mid][k] - sum2[i][k]) {
							match = false;
							break;
						}
					}
					if (match) {

						find = true;
						break;
					}
				}
			}

			if (find)
				break;
		}

		if (find) {
			ans = mid;
			break;
		}
	}

	cout << ans;
}