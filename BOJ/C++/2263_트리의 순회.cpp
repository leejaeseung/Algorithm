/*
����
n���� ������ ���� ���� Ʈ���� ������ 1���� n������ ��ȣ�� �ߺ� ���� �Ű��� �ִ�. �̿� ���� ���� Ʈ���� �ο����� ����Ʈ������ �־����� ��, ���������� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� n(1��n��100,000)�� �־�����. ���� �ٿ��� �ο����� ��Ÿ���� n���� �ڿ����� �־�����, �� ���� �ٿ��� ���� ������ ����Ʈ������ �־�����.

���
ù° �ٿ� ���������� ����Ѵ�.

Ǯ��:
��� ȣ���� �̿��� ���� ���� �����̴�.

http://melonicedlatte.com/algorithm/2018/02/04/145104.html
�� ��α׸� �����Ͽ� Ǯ���ߴ�.

post ������ ��� ����Ʈ������ �� ������ ���Ұ� root�� ���� �̿��� in����, post������ ����, ������
����Ʈ���� �������� �����ϸ� �ȴ�.
�� ��͸��� root�� leaf ��带 ����ϸ� �ȴ�.
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
int in[100001];
int post[100001];
int idx[100001];	//post���� ���� in���������� �ε����� ����

void make(int inS, int inE, int poS, int poE) {

	if(poS <= poE || inS <= inE)
		cout << post[poE] << " ";
	//��Ʈ, ���� ����� ���� ���

	if (poS >= poE || inS >= inE)	return;

	int mid = idx[post[poE]];
	//in������ �߰� ���� = root

	int size = mid - inS;

	make(inS, mid - 1, poS, poS + size - 1);
	//���� ����Ʈ��

	make(mid + 1, inE, poS + size, poE - 1);
	//������ ����Ʈ��
}

int main(void) {
	FIO;

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> in[i];
		idx[in[i]] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> post[i];
	}

	make(1, n, 1, n);
}