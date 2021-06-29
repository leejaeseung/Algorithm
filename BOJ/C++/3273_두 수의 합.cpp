/*
����
n���� ���� �ٸ� ���� ���� a1, a2, ..., an���� �̷���� ������ �ִ�. ai�� ���� 1���� ũ�ų� ����, 1000000���� �۰ų� ���� �ڿ����̴�. �ڿ��� x�� �־����� ��, ai + aj = x (1 �� i < j �� n)�� �����ϴ� (ai, aj)���� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ������ ũ�� n�� �־�����. ���� �ٿ��� ������ ���ԵǴ� ���� �־�����. ��° �ٿ��� x�� �־�����. (1 �� n �� 100000, 1 �� x �� 2000000)

���
������ ������ �����ϴ� ���� ������ ����Ѵ�.

Ǯ��:
�������� ��������, ������ ������ ũ�� �ʰ� ���ڰ� �ߺ����� �ʾ� �� ���� �迭�� ����� Ǯ���� ���� �־���.
�� ������ index�� üũ�ϴ� �迭�� �����, ���� �迭�� ���鼭 ���� x �� �Ǵ� ��� other ���� �����ϴ��� ����, �ε����� ���� ī��Ʈ�Ѵ�.
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
int mv1[4] = { 0, 1, -1, 0 };
int mv2[4] = { 1, 0, 0, -1 };

int n, x;
int arr[100001];
int idx[1000001];

int main() {
	FIO;

	cin >> n;

	fill(&idx[0], &idx[1000001], -1);

	for (int i = 0; i < n; i++)
	{
		int v;
		cin >> v;
		arr[i] = v;

		idx[v] = i;
	}
	
	cin >> x;

	int count = 0;
	
	for (int i = 0; i < n; i++)
	{
		int now = arr[i];
		int other = x - now;
		
		if (other <= 0)	continue;

		if (idx[other] > i) {
			count++;
		}
	}

	cout << count;
}