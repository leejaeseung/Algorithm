/*
����
����ũ�� ���̴������κ��� �� ����� ����ũ�� ���� �޾ҽ��ϴ�.

����ũ ������ N���� ���� ������ �÷��� �ִµ� ����ũ ������ ���� N/2���� Ű�� N/2���� ������ ������ �ΰ� �Ϸķ� �÷��� �ֽ��ϴ�. ���⼭ N�� 4�� ����Դϴ�.

����ũ�� ����ũ�� �ɰ� �÷��� ������ ������ �����Ͽ� ����ũ�� ��Ȯ�� ���ݾ� �Ա� ���� ���� ����ũ�� �߶� ������ �������� �մϴ�. �̶� ����ũ�� ���� ���Ⱑ N/4������ �ϸ� Ű���� N/4�� �־�� �մϴ�. �ɵ� ����ũ�� ���� ������ ����� Ű���� �޾ƾ� �մϴ�.

����ũ�� ���� ����ũ�� �ڸ��� �������Ƿ� �� Ƚ���� �ּ�ȭ�ϰ��� �մϴ�. �ɰ� ����ũ�� �Ȱ��� ������ �Ա� ���� ����ũ�� �߶�� �ϴ� �ּ� Ƚ���� ����� �˷��ּ���.

�Է�
ù ��° �ٿ��� ����ũ ���� �ִ� ������ ���� N (4 �� N �� 200,000) �� �־����ϴ�.

�� ��° �ٿ��� ����ũ�� ������ ��� ���̰� N�� ���ڿ��� �־����ϴ�. i��° ���ڰ� 's'�̸� i��° ĭ���� ���Ⱑ 'k'�̸� Ű���� �÷��� ������ �ǹ��մϴ�.

���
ù ��° �ٿ� �ּ� Ƚ�� k (1 �� k �� N - 1) �� ����մϴ�.

�� ��° �ٿ��� k���� ���� c1, c2, ..., ck (1 �� c1 < c2 < ... < ck  �� N - 1) �� ����մϴ�. ���⼭ ci�� ci ��° ������ �ִ� ���� ci +1��° ������ �ִ� �� ���̸� �ڸ��ٴ� �ǹ��Դϴ�.

�ڸ��� ����� ���� ���� ��� �� �� �ϳ��� ����մϴ�.

Ǯ��:
���� ����, ����� Ž�� ��� ���� ����� ����غôµ� �˰��� ���� ������ ��������.

�ƹ��� �����ϰ� �迭�Ǿ� �־ �ڸ��� �ִ� Ƚ���� 2�� ���� �ʴ´�.
(��, ���� �׻� 1 �ƴϸ� 2)

���� 1�� ���� �����ϴ�.
�߰��� �������� ����, �������� s, k ���� ���� ����̴�.

���� 2�� ���� ������ �� 3�� �����.
�� ��, 3���� ���� �� �߰��� ������ �׻� �ϼ��� �����̴�.
���� ���ʺ��� �߶󺸸� ���� ����, ������ ������ s, k ������ ������ �����ϴ� ��� �ش� ������ �߶��ָ� �ȴ�.

������ ������ s, k ������ prefix Sum�� �̿��� �迭�� �̸� �����صΰ� Ǯ���ؾ� �ð� �ʰ��� ���� �� �ִ�.
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
int mv1[4] = { 0, 0, 1, -1 };
int mv2[4] = { 1, -1, 0, 0 };
int mv_all1[8] = { 0, 1, 0, -1, -1, -1, 1, 1 };
int mv_all2[8] = { 1, 0, -1, 0 , -1, 1, -1, 1 };

int n;
int rightSum[200004][2];
int leftSum[2];
string cake;
vector<int> vt;

int main(void) {
	FIO;

	cin >> n >> cake;

	for (int i = 0; i < n; i++)
	{
		if (cake[i] == 's')
			vt.push_back(0);
		else
			vt.push_back(1);
	}

	for (int i = n - 1; i >= 0; i--)
		//�����ʿ������� s, k �� ������ �̸� ���س���
	{
		int now = vt[i];

		rightSum[i][now] = rightSum[i + 1][now] + 1;
		rightSum[i][(now + 1) % 2] = rightSum[i + 1][(now + 1) % 2];
	}

	int jump = n / 2 + 1;

	if (rightSum[n / 2][0] == n / 4 && rightSum[n / 2][1] == n / 4) {
		//�߾ӿ��� �ڸ� ��
		cout << "1\n" << n / 2;
	}
	else {
		//�� �������� ���� ��
		for (int i = 0; i < n / 2; i++)
		{
			int now = vt[i];

			leftSum[now]++;

			if (leftSum[0] + rightSum[i + jump][0] == n / 4 && leftSum[1] + rightSum[i + jump][1] == n / 4) {
				cout << "2\n" << i + 1 << " " << i + jump;
				break;
			}
		}
	}
}