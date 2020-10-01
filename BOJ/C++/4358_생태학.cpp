/*
����
�����п��� ������ �������� �����ϴ� ���� �߿��ϴ�. �׷��Ƿ� ����� �̱� ������ �������� �־����� ��, �� ���� ��ü���� �� %�� �����ϴ��� ���ϴ� ���α׷��� ������ �Ѵ�.

�Է�
���α׷��� ���� �ٷ� �̷���� ������, �� �ٿ� �ϳ��� ���� �� �̸��� �־�����. � �� �̸��� 30���ڸ� ���� ������, �Է¿��� �ִ� 10,000���� ���� �־����� �ִ� 1,000,000�׷��� ������ �־�����.

���
�־��� �� ���� �̸��� ���������� ����ϰ�, �� ���� �����ϴ� ������ ������� �Ҽ��� 4°�ڸ����� �Բ� ����Ѵ�.

Ǯ��:
Ʈ���� �˰��� �⺻ �����Դϴ�.
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

class node {
public:
	double cnt = 0;
	string nowStr = "";
	node* next[127];
};

node* root;
double allCnt = 0;
vector<pair<string, double>> ans;

void search(node* now) {


	for (int i = 0; i < 127; i++)
	{
		if (now->next[i] == NULL)	continue;

		search(now->next[i]);
	}

	if (now->cnt != 0) {
		ans.push_back({ now->nowStr, now->cnt / allCnt * 100 });
	}
}

int main(void) {
	FIO;

	root = new node();

	string str;

	while (getline(cin, str)) {

		allCnt++;
		node* nowNode = root;

		for (int i = 0; i < str.size(); i++)
		{
			int now = str[i];

			if (nowNode->next[now] == NULL) {
				nowNode->next[now] = new node();
				nowNode->next[now]->nowStr = nowNode->nowStr + (char)now;
			}
			nowNode = nowNode->next[now];
		}
		nowNode->cnt++;
	}

	cout.precision(4);
	cout << fixed;
	search(root);

	sort(ans.begin(), ans.end());

	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i].first << " " << ans[i].second << "\n";
	}
}