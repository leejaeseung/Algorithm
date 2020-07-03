/*
����
�� ���ڿ��� �־����� ��, �� ���ڿ��� ��� ���Ե� ���� �� ���� �κ� ���ڿ��� ã�� ���α׷��� �ۼ��Ͻÿ�.

� ���ڿ� s�� �κ� ���ڿ� t��, s�� t�� �������� ��Ÿ���� ���� ���Ѵ�. ���� ���, ���ڿ� ABRACADABRA�� �κ� ���ڿ��� ABRA, RAC, D, ACADABRA, ABRACADABRA, �� ���ڿ� ���̴�. ������, ABRC, RAA, BA, K�� �κ� ���ڿ��� �ƴϴ�.

�� ���ڿ� ABRACADABRA�� ECADADABRBCRDARA�� ���� �κ� ���ڿ��� CA, CADA, ADABR, �� ���ڿ� ���� �ִ�. �� �߿��� ���� �� ���� �κ� ���ڿ��� ADABR�̸�, ���̴� 5�̴�. ��, �� ���ڿ��� UPWJCIRUCAXIIRGL�� SBQNYBSBZDFNEV�� ��쿡�� ���� �� ���� �κ� ���ڿ��� �� ���ڿ��̴�.

�Է�
ù° �ٰ� ��° �ٿ� ���ڿ��� �־�����. ���ڿ��� �빮�ڷ� �����Ǿ� ������, ���̴� 1 �̻� 4000 �����̴�.

���
ù° �ٿ� �� ���ڿ��� ��� ���� �� �κ� ���ڿ� �� ���� �� ���� ���̸� ����Ѵ�.

Ǯ��:
LCS�� �ٸ� ���� �����Դϴ�.

���� �� ���ӵ� ���� ���ڿ��� ���ؾ� �ϹǷ� ���� LCS���� ����, �� ���� max�� ���ϴ� ������� �ϸ� �ȵ˴ϴ�.
(������ �а� �Ǳ� ������)

���, ����, ���� ��, �� �� ���� ���� min�� ���ϰ�, ��� dp �� �� �ִ� ���� ���ϸ� �˴ϴ�.
dp ����� ���ӵ� ���ڿ����� �밢�� �Ʒ��� ���������� �����ϰ� �˴ϴ�.
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

string s1, s2;
int dp[4001][4001];

int main(void) {
	FIO;

	cin >> s1 >> s2;

	int maxLeng = 0;

	for (int i = 1; i <= s1.size(); i++)
	{
		char now = s1[i - 1];
		for (int j = 1; j <= s2.size(); j++)
		{
			char comp = s2[j - 1];

			if (now == comp) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
			}
			
		maxLeng = max(maxLeng, dp[i][j]);
		}
	}

	cout << maxLeng;
}