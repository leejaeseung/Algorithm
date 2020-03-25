/*
����
N�ٿ� 0 �̻� 9 ������ ���ڰ� �� ���� ���� �ִ�. �������� ������ �ϰ� �ִµ�, �� ������ ù �ٿ��� �����ؼ� ������ �ٿ��� ������ �Ǵ� �����̴�.

���� ó���� ���� �ִ� �� ���� ���� �߿��� �ϳ��� ��� �����ϰ� �ȴ�. �׸��� ���� �ٷ� �������µ�, ���� �ٷ� ������ ������ ������ ���� ���� ������ �ִ�. �ٷ� �Ʒ��� ���� �Ѿ�ų�, �ƴϸ� �ٷ� �Ʒ��� ���� �پ� �ִ� ���θ� �̵��� �� �ִٴ� ���̴�. �� ���� ������ �׸����� ��Ÿ���� ���� ������ ����.



��ǥ�� ���� ��ġ�̰�, �� �Ʒ� ���� �Ķ� ���׶�̴� �����̰� ���� �ٷ� ������ �� �ִ� ��ġ�̸�, ���� ����ǥ�� �����̰� ������ �� ���� ��ġ�� �ȴ�. ����ǥ�� �־��� ���� ��, ���� �� �ִ� �ִ� ����, �ּ� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�. ������ �����̰� ��ġ�� ���� ���� ���̴�.

�Է�
ù° �ٿ� N(1 �� N �� 100,000)�� �־�����. ���� N���� �ٿ��� ���ڰ� �� ���� �־�����. ���ڴ� 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 ���� �ϳ��� �ȴ�.

���
ù° �ٿ� ���� �� �ִ� �ִ� ������ �ּ� ������ �� ����Ѵ�.

Ǯ��:
�޸� ������ 4MB �̱⶧���� N���� �迭�� ����ϸ� �޸��ʰ��� ���ϴ�.
���� �׸����ϰ� dp[3] �� �迭�� �����Ͽ� Ǯ���߽��ϴ�.

slide[i][j] = i~j�� �ּ� or �ִ밪,
slide �迭�� ���� dp������ ������ �� ������ �ּ� or �ִ밪�� ������ �����Ƿ� ���� dp���� �˸°� �����ָ� �˴ϴ�.
*/
#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<vector>
#include<queue>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>

int N;
int slideMin[3][3];
int slideMax[3][3];
int dpMin[3];
int dpMax[3];

int main(void) {
	FIO;

	cin >> N;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			slideMin[i][j] = 1000000000;
			slideMax[i][j] = 0;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 3; j++) {
			int n;
			cin >> n;
			
			if (i == 0) {
				slideMin[j][j] = n;
				slideMax[j][j] = n;
			}
			else {
				slideMin[j][j] = dpMin[j];
				slideMax[j][j] = dpMax[j];
			}
			dpMin[j] = n;
			dpMax[j] = n;
		}
		if (i > 0) {
			for (int i = 0; i < 3; i++)
			{
				for (int j = i + 1; j < 3; j++)
				{
					for (int k = i; k <= j ; k++)
					{
						slideMin[i][j] = min(slideMin[i][k], slideMin[k][j]);
						slideMax[i][j] = max(slideMax[i][k], slideMax[k][j]);
					}
					
				}
			}
			dpMin[0] += slideMin[0][1];
			dpMin[1] += slideMin[0][2];
			dpMin[2] += slideMin[1][2];
			dpMax[0] += slideMax[0][1];
			dpMax[1] += slideMax[0][2];
			dpMax[2] += slideMax[1][2];

			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					slideMin[i][j] = 1000000000;
					slideMax[i][j] = 0;
				}
			}
		}
	}
	int max_ans = max(dpMax[0], max(dpMax[1], dpMax[2]));
	int min_ans = min(dpMin[0], min(dpMin[1], dpMin[2]));
	cout << max_ans << " " << min_ans;
}