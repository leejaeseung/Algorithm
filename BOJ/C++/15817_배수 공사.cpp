/*
����


�����̳� ���� �ʹ� �����Ǿ ���⿡ ���� ���� ����. ���� ���� �����̴� ��ħ ���� �������� ���� �־ ���� ��� ���縦 �Ϸ��� �Ѵ�.

������ �������� �ڸ��� ����� �ʹ��� ��α� ������, ������ �����̴� ���� ���������� ������ ��Ƽ� ���ϴ� ���̷� ������ �Ѵ�.

�����̰� ������ �ִ� �������� ���̿� �� ������ �˰� ���� ��, �������� ������ ���ļ� x��ŭ�� ���̸� ����� ����� ���� ���Ͻÿ�. �������� ��ġ�� ������ ������� �ʴ´�.

�Է�
�����̰� ������ �ִ� �������� ������ �� N�� ����� ���� ��ģ �������� ���� x�� �־�����. (1 �� N �� 100 �̸�, 1 �� x �� 10 000 �̴�.)

���� N���� �ٿ� ���ļ� �������� ���� Li �� ���� Ci �� ������ ���̿� �ΰ� �־�����. ���̰� ª�� �ͺ��� ������� �ԷµǸ�, 0 < Li �� x, 0 < Ci �� 100 �̴�. ����, �ԷµǴ� �������� ���̴� ���� �ٸ���.

���
��ģ �������� ���� x�� ���� �� �ִ� ����� ���� ����Ѵ�. ����� ���� 2,147,483,647�� �Ѵ� ���� ����.

Ǯ��:
https://onedaycoding.tistory.com/102
�� �����߽��ϴ�.

dp[i][j] �� i��° ���������� j ���̸� ����� ����� ���� �����մϴ�.
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

int N, x;
int dp[101][10001];
pii p[100];

int recul(int now, int leng) {

	if (leng == x)	return 1;
	if (leng > x)	return 0;
	if (now >= N)	return 0;
	

	int& ret = dp[now][leng];
	if (ret != -1)	return ret;

	ret = 0;
	for (int i = 0; i <= p[now].second; ++i)
	{
		ret += recul(now + 1, leng + p[now].first * i);
	}
	return ret;
}

int main(void) {
	FIO;

	cin >> N >> x;

	for (int i = 0; i < N; i++)
	{
		int L, C;

		cin >> L >> C;

		p[i] = make_pair(L, C);
	}
	memset(dp, -1, sizeof(int) * 101 * 10001);
	cout << recul(0, 0);
}