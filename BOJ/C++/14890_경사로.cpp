/*
����
ũ�Ⱑ N��N�� ������ �ִ�. ������ �� ĭ���� �� ���� ���̰� ������ �ִ�.

������ �� �������� ������ �� �ִ� ���� �� �� �ִ��� �˾ƺ����� �Ѵ�. ���̶� �� �� �Ǵ� �� �� ���θ� ��Ÿ����, ���� ������ �ٸ��� ������ �������� ���̴�.

������ ���� N=6�� ��� ������ ���캸��.



�̶�, ���� �� 2N���� ������, �Ʒ��� ����.



���� ������ �� �������� �濡 ���� ��� ĭ�� ���̰� ��� ���ƾ� �Ѵ�. �Ǵ�, ���θ� ���Ƽ� ������ �� �ִ� ���� ���� �� �ִ�. ���δ� ���̰� �׻� 1�̸�, ���̴� L�̴�. ��, ������ �ſ� ���� ������ ���� ����. ���δ� ���� ĭ�� ���� ĭ�� �����ϸ�, �Ʒ��� ���� ������ �����ؾ��Ѵ�.

���δ� ���� ĭ�� ������, L���� ���ӵ� ĭ�� ������ �ٴ��� ��� ���ؾ� �Ѵ�.
���� ĭ�� ���� ĭ�� ���� ���̴� 1�̾�� �Ѵ�.
���θ� ���� ���� ĭ�� ���̴� ��� ���ƾ� �ϰ�, L���� ĭ�� ���ӵǾ� �־�� �Ѵ�.
�Ʒ��� ���� ��쿡�� ���θ� ���� �� ����.

���θ� ���� ���� �� ���θ� ���� ���
���� ĭ�� ���� ĭ�� ���� ���̰� 1�� �ƴ� ���
���� ������ ĭ�� ���̰� ��� ���� �ʰų�, L���� ���ӵ��� ���� ���
���θ� ���ٰ� ������ ����� ���
L = 2�� ��쿡 ���θ� ���� �� �ִ� ��츦 �׸����� ��Ÿ���� �Ʒ��� ����.



���θ� ���� �� ���� ���� �Ʒ��� ����.



���� �׸��� ���� ���ʺ��� 1��, 2��, 3��, 4�� ������� ���� ��, 1���� ���� ���̰� 1�� �ƴ϶�, 2���� ���θ� �ٴڰ� ���ϰ� ���� �ʾƼ�, 3���� ���ļ� ���Ƽ�, 4���� ����̰� ���Ƽ� �Ұ����� ����̴�.

���� ���� �־��� �׸� ���� ��쿡 ������ �� �ִ� ���� �ʷϻ�����, ������ �� ���� ���� ���������� ǥ�õǾ� ������, �Ʒ��� ����. ������ ���� L = 2�̴�.



������ �־����� ��, ������ �� �ִ� ���� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� N (2 �� N �� 100)�� L (1 �� L �� N)�� �־�����. ��° �ٺ��� N���� �ٿ� ������ �־�����. �� ĭ�� ���̴� 10���� �۰ų� ���� �ڿ����̴�.

���
ù° �ٿ� ������ �� �ִ� ���� ������ ����Ѵ�.

Ǯ��:
�� �ϳ��� vector�� �޾� �ش� ���� �� �� �ִ��� ��� ��츦 üũ�� �ִ� �Լ��� �����.
12������ �濡 ���� üũ���ָ� �ȴ�.
*/
#include<iostream>
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

int N, L;
int maps[101][101];

bool checkRoad(vector<int> road) {
	int prevH = road[0];
	bool check[101];

	for (int i = 0; i < N; i++)
	{
		check[i] = false;
	}

	for (int i = 1; i < road.size(); i++)
	{
		int nowH = road[i];

		if (abs(nowH - prevH) > 1)	return false;
		//���̰� 2�̻��̸� false

		if (nowH > prevH) {
			
			for (int j = 0; j < L; j++)
				//�� ĭ�鿡 ���� ���θ� ���� �� �ִ��� ����
			{
				int check_idx = i - j - 1;
				if (check_idx < 0)	return false;
				if (check[check_idx])	return false;
				if (road[check_idx] != prevH)	return false;
				check[check_idx] = true;
			}

		}
		else if (nowH < prevH) {
			for (int j = 0; j < L; j++)
				//�� ĭ�鿡 ���� ���θ� ���� �� �ִ��� ����
			{
				int check_idx = i + j;
				if (check_idx >= N)	return false;
				if (road[check_idx] != nowH)	return false;
				check[check_idx] = true;
			}
		}
		prevH = nowH;
	}
	return true;
}

int main(void) {
	FIO;

	cin >> N >> L;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> maps[i][j];
		}
	}

	int ans = 0;

	for (int i = 0; i < N; i++)
	{
		vector<int> vt;

		for (int j = 0; j < N; j++)
		{
			vt.push_back(maps[i][j]);
		}

		if (checkRoad(vt))
			ans++;
	}

	for (int i = 0; i < N; i++)
	{
		vector<int> vt;

		for (int j = 0; j < N; j++)
		{
			vt.push_back(maps[j][i]);
		}

		if (checkRoad(vt))
			ans++;
	}

	cout << ans;
}