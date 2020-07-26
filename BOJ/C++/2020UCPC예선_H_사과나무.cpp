/*
����
���ϴ� �ֱ� ������� ������ �����Ͽ� ���� �޶㿡 �Ϸķ� ������ ������ �ɾ���. �� �������� �ʱ� ���̴� ��� �̴�.

��������� �������� Ű��� ���� ���ϴ� ���Ѹ��� ���� �غ��ߴ�. �� ���Ѹ����� ���� �ϳ��� ��ŭ �����Ű��, �ٸ� ���Ѹ����� ���� �ϳ��� ��ŭ �����Ų��. �� ���Ѹ������� ���ÿ� ����ؾ� �ϸ�, ���Ѹ����� ������ ���� ��翡 ����� ���� ����. �� ���Ѹ����� �� ������ ����Ͽ� ��ŭ Ű�� ���� �ִ�.

���Ѹ��� ���� �ý����� ���� ���α׷����� ���ϴ� ���� ��������� Ű�������� �ߴ�. �� ����, ���ڰ� ��ͼ� �� ��������� ���̰� �̷� ��ġ�� �Ǿ����� ���ڴٰ� ���ߴ�. ���� ���ϴ� �ణ ������ �Ǳ� �����ߴµ�, ���ڰ� �˷��� ��������� ��ġ�� �� ���α׷� ������ ������ ���� ���� �ֱ� �����̴�.

���ϴ� ���� ���α׷��� �ٽ� �����ϴ��� �ٻڱ� ������, �� ���Ѹ����� �̿��� ���ڰ� �˷��� ��������� ��ġ�� ���� �� �ִ����� ���θ� �Ǵ��ϴ� ������ �������� ���� �Ǿ���.

�Է�
ù ��° �ٿ��� �ڿ��� �� �־�����. () �̴� ���ϰ� �޶㿡 ���� ��������� ������ ���Ѵ�.

�� ��° �ٿ��� ���� ���� �� �������� ���еǾ� �־�����. () �� ���ڰ� �ٶ�� ��° ������ �����̴�.

���
ù ��° �ٿ� ��� ������ ���ڰ� �ٶ�� ���̰� �ǵ��� ���Ѹ����� ���� ���� �� ������ ��YES����, �ƴϸ� ��NO���� ����ǥ�� �����ϰ� ����Ѵ�.

Ǯ��:
���� ���� - 1�� ������, 3�� ��� Ȱ��

1. �־��� �迭�� �� ���� 3�� ����� �ƴϸ�, NO
2. �־��� �迭�� 1�� ������ŭ �ٸ� 1���� ū ������ 2�� �� �־�� ��.(�� �� ���ٸ� NO)
3. 2������ 2�� ���� ���� 1�� ������ŭ 2���� �ٽ� ����. -> ���� �ִ� 1�� ����
4. 2, 3������ ���� 1�� ������ n�� ������ NO
5. 4������ ����ߴٸ�(1�� �����ϴ� ����), ���� �迭�� ��� ���� 1���� ŭ. -> 1���� ū ��� ���� MOD 3 ���� ��, 
	���������� ���� 3�� ������ YES, �ƴ϶�� NO
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
int mv1[4] = { 0, 1, 0, -1 };
int mv2[4] = { 1, 0, -1, 0 };
int mv_all1[8] = { 0, 1, 0, -1, -1, -1, 1, 1 };
int mv_all2[8] = { 1, 0, -1, 0 , -1, 1, -1, 1 };

int n;
int height[100001];

int main(void) {
	FIO;

	cin >> n;

	int sum = 0;
	int one_cnt = 0;
	int remain_1 = 0;
	int remain_2 = 0;
	int all_one = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> height[i];
		sum += height[i];
		if (height[i] == 1)
			one_cnt++;
	}

	all_one = one_cnt;

	if (sum % 3 == 0) {
		//�� ���� 3�� ������
		
		if (sum - (one_cnt * 3) < 0)
			//1�� ������ŭ 2�� ���� �� ���ٸ�
			cout << "NO";
		else {
			while (one_cnt != 0) {
				//1�� ������ŭ ����ؼ� 2�� ����
				for (int i = 0; i < n; i++)
				{
					if (height[i] == 1) continue;
					//���� �ִ� 1�̶�� pass

					if (height[i] > 1 && one_cnt > 0) {
						int maximum = height[i] / 2;
						if (maximum > one_cnt) {
							height[i] -= (one_cnt * 2);
							one_cnt = 0;
						}
						else {
							one_cnt -= maximum;
							height[i] -= (maximum * 2);
						}
					}
					if (height[i] == 1) {
						//���Ӱ� ���� 1
						one_cnt++;
						all_one++;
					}
				}
				if (all_one == n) {
					//��� ���� 1�� �ǹ����� NO
					cout << "NO";
					exit(0);
				}
			}

			for (int i = 0; i < n; i++)
			{
				if (height[i] == 1)	continue;
				if (height[i] % 3 == 1)
					remain_1++;
				else if (height[i] % 3 == 2)
					remain_2++;
			}

			int all = remain_1 + remain_2 * 2;
			//1���� ū ���鿡 ���� MOD 3�� ���������� ���� 3�� �������

			if (all % 3 == 0)
				cout << "YES";
			else
				cout << "NO";
		}
	}
	else {
		cout << "NO";
	}
}