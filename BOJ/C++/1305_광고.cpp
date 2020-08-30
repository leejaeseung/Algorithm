/*
����
�����̴� �� �Ѱ������ �������� �Ĵٺ��� �־���. �����ǿ��� ���� ���ĺ����� �귯������ �־���. ������ �������� �Ĵٺ� �����̴� �� ���� �ǹ��ϴ� ���� �������� �ñ������� �����ߴ�.

�����ǿ��� ���� ������ ������ ������ �ݺ��Ǿ� ���´�. ��, �������� ũ��� �����ǿ��� �ѹ��� ���̴� �ִ� ���ڼ��� ��Ÿ����. ���� �������� ũ�Ⱑ L�̶��, �ѹ��� L���� ���ڸ� ǥ���� �� �ִ� ���̴�.

������ڴ� �ִ����� ����ȿ���� ���� ���ؼ� ���̰� N�� ���� ������ �ٿ��� �����Ѵ�.

���� ���, ���� ���� �������� �����ϰ� ���� ������ aaba �̰�, �������� ũ�Ⱑ 6�̶�� �� ó���� ���̴� ������ aabaaa �̴�. �ð��� 1�ʰ� ���� ������, ���ڴ� �� ĭ�� ������ �̵��Ѵ�. ���� ó���� aabaaa�� �������� �� �������� abaaab�� ���δ�. �� �������� baaaba�� ���δ�.

�����̰� ��� ���� �������� �Ĵٺ��� ��, �� �� ���� �ִ� ���ڰ� �Է����� �־����� ��, ������ ������ ������ ���� ª�� ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �������� ũ�� L�� �־�����, ��° �ٿ� ���� �����ǿ� ���̴� ���ڿ��� �־�����. L�� �鸸���� �۰ų� ���� �ڿ����̴�.

���
ù° �ٿ� ������ ������ ������ ���� ª�� ���� ���̸� ����Ѵ�.

Ǯ��:
KMP �˰��򿡼� pi �迭�� Ȱ���ϴ� �����̴�.
pi �迭�� index ������ �κ� ���ڿ����� ���λ�� ���̻簡 ��ġ�ϴ� ���� �� ���̸� �����Ѵ�.

��ü ���ڿ��� ���� - pi[L - 1] �� ���� �ȴ�.

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

int P[1000001];

int main(void) {
	FIO;

	int L;
	string str;

	cin >> L >> str;

	int leng = 0;

	for (int i = 1; i < L; i++)
	{
		while (str[leng] != str[i] && leng > 0) {
			leng = P[leng - 1];
		}

		if (str[leng] == str[i]) {
			P[i] = ++leng;
		}
	}

	cout << L - P[L - 1];
}