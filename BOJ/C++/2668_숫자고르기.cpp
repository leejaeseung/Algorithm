/*
����
���� �� ��, ���η� N���� ĭ���� �̷���� ǥ�� �ִ�. ù° ���� �� ĭ���� ���� 1, 2, ��, N�� ���ʴ�� ��� �ְ� ��° ���� �� ĭ���� 1�̻� N������ ������ ��� �ִ�. ù° �ٿ��� ���ڸ� ������ ������, �� ���� �������� �̷�� ���հ�, ���� �������� �ٷ� ���� ��° �ٿ� ����ִ� �������� �̷�� ������ ��ġ�Ѵ�. �̷��� ������ ������Ű���� �������� �̵�, �ִ�� ���� �̴� ����� ã�� ���α׷��� �ۼ��Ͻÿ�. ���� ���, N=7�� ��� �Ʒ��� ���� ǥ�� �־����ٰ� ����.



�� ��쿡�� ù° �ٿ��� 1, 3, 5�� �̴� ���� ���̴�. ù° ���� 1, 3, 5�ؿ��� ���� 3, 1, 5�� ������ �� ������ ��ġ�Ѵ�. �̶� ������ ũ��� 3�̴�. ���� ù° �ٿ��� 1�� 3�� ������, �̵� �ٷ� �ؿ��� ���� 3�� 1�� �����Ƿ� �� ������ ��ġ�Ѵ�. �׷���, �� ��쿡 ���� ������ ������ �ִ밡 �ƴϹǷ� ���� �� �� ����.

�Է�
ù° �ٿ��� N(1��N��100)�� ��Ÿ���� ���� �ϳ��� �־�����. �� ���� �ٺ��ʹ� ǥ�� ��° �ٿ� ���� �������� ������� �� �ٿ� �ϳ��� �Էµȴ�.

���
ù° �ٿ� ���� �������� ������ ����ϰ�, �� ���� �ٺ��ʹ� ���� �������� ���� ������ ū ���� ������ �� �ٿ� �ϳ��� ����Ѵ�.

Ǯ��:
1~N ������ ������ �ܹ��� �׷����� ���� ��, �� �������� �ڱ� �ڽ����� ���ƿ� �� �ִ��� �Ǻ��ϴ� �����Դϴ�.
dfs �˰����� �̿��ϸ� ���� Ǯ���� �� �ֽ��ϴ�.
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

int n;
int link[101];
bool visit[101];
int cnt = 0;
vector<int> ans;

void dfs(int start, int now) {
	
	if (link[now] == start) {
		cnt++;
		ans.push_back(start);
		return;
	}
	else {
		if (!visit[link[now]]) {
			visit[link[now]] = true;
			dfs(start, link[now]);
		}
	}
}

int main(void) {
	FIO;

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		int next;
		cin >> next;

		link[i] = next;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			visit[j] = false;
		}
		dfs(i, i);
	}
	cout << cnt << "\n";
	for (int i = 0; i < cnt; i++)
	{
		cout << ans[i] << "\n";
	}
}