/*
����
Cubelover�� ���α׷��� ��� Whitespace�� �ڵ��� �����ִ� ����� Cubelang�� �������. Cubelang�� �̿��� �ڵ��� �ϴٺ���, ���� �� �� �´� ���ο� �����Ͱ� �ʿ��ϰ� �Ǿ���. ���� �ð� ����� ���� ���ο� �����͸� ����� �Ǿ���, �� �������� �̸��� Cubeditor�̴�.

�ؽ�Ʈ �����ʹ� ã�� ����� �����Ѵ�. ��κ��� �����ʹ� ã������ �ϴ� ���ڿ��� �� �� ���� ���͵� ã�´�. Cubelover�� �� ����� Cubelang�� �������ϴٰ� �����ߴ�. Cubelang���� �ʿ��� ����� � ���ڿ� ������ �κ� ���ڿ��� �� �� �̻� ������ ���ڿ��� ã�� ����̴�. �̶�, �� �κ� ���ڿ��� ���ĵ� �ȴ�.

���� ���, abcdabc���� abc�� �� �� ������ ������ �˻��� ����������, abcd�� �� �� ������ ������ �˻��� ������ �ʴ´�.

�̷��� � ���ڿ����� �� �� �̻� ������ �κ� ���ڿ��� �ſ� ���� ���� �ִ�. �̷��� �κ� ���ڿ� �߿��� ���� ���̰� �� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

���� ���, abcabcabc���� abc�� �� �� ������ ������ �˻��� �� �ִ�. ��, abcabc�� �� �� ������ ������ �˻��� �� �ִ�. ������, abcabca�� �� �� ������ ������ �˻��� �� ����. ����, �� �� �̻� ������ �κ� ���ڿ� �߿��� ���� �� ���� abcabc�̱� ������, �� ���ڿ��� ���� �ȴ�.

�Է�
ù° �ٿ� ���ڿ��� �־�����. ���ڿ��� ���̴� �ִ� 5,000�̰�, ���ڿ��� ��� �ҹ��ڷθ� �̷���� �ִ�.

���
�Է¿��� �־��� ���ڿ��� �� ���̻� ������ �κй��ڿ� �߿��� ���� �� ���̸� ����Ѵ�.

Ǯ��:
https://www.acmicpc.net/problem/3033
�� �������� N �� ���� �����̴�.
KMP, ���-ī�� ��� �����ϴ�.
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
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vii vector<pii>
#define IMAX 2000000001
#define LMAX 1000000000000000000
#define DMAX 0xFFFFFFFFFFFFF
#define MOD 100007
int mv1[4] = { 0, 0, 1, -1 };
int mv2[4] = { 1, -1, 0, 0 };
int mv_all1[8] = { 0, 1, 0, -1, -1, -1, 1, 1 };
int mv_all2[8] = { 1, 0, -1, 0 , -1, 1, -1, 1 };
int mod(ll num) {
	if (num >= 0)	return num % MOD;
	else
		return (num % MOD + MOD) % MOD;
}

vector<int> pos[MOD];

int main(void) {
	FIO;

	string str;
	cin >> str;

	int s = 0;
	int e = str.size();
	int ans = 0;

	while (s < e){

		int mid = (s + e) / 2;

		int H = 0;
		int mul = 1;
		bool find = false;

		for (int i = 0; i < MOD; i++)
		{
			pos[i].clear();
		}

		for (int i = 0; i <= str.size() - mid; i++)
		{
			if (i == 0) {

				for (int j = mid - 1; j >= 0; j--)
				{
					H = mod(H + (str[j] - 'a') * mul);
					if (j > 0)
						mul = mod(mul * 2);
				}
			}
			else
				H = mod((H - (str[i - 1] - 'a') * mul) * 2 + (str[i + mid - 1] - 'a'));


			if (!pos[H].empty()) {

				for (int j = 0; j < pos[H].size(); j++)
				{
					int start = pos[H][j];
					bool match = true;

					for (int k = 0; k < mid; k++)
					{
						if (str[i + k] != str[start + k]) {
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

			if (find)	break;
			else
				pos[H].push_back(i);
		}

		if (find) {
			ans = mid;
			s = mid + 1;
		}
		else {
			e = mid;
		}
	}

	cout << ans;
}