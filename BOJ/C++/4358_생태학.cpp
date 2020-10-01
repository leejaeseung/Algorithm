/*
문제
생태학에서 나무의 분포도를 측정하는 것은 중요하다. 그러므로 당신은 미국 전역의 나무들이 주어졌을 때, 각 종이 전체에서 몇 %를 차지하는지 구하는 프로그램을 만들어야 한다.

입력
프로그램은 여러 줄로 이루어져 있으며, 한 줄에 하나의 나무 종 이름이 주어진다. 어떤 종 이름도 30글자를 넘지 않으며, 입력에는 최대 10,000개의 종이 주어지고 최대 1,000,000그루의 나무가 주어진다.

출력
주어진 각 종의 이름을 사전순으로 출력하고, 그 종이 차지하는 비율을 백분율로 소수점 4째자리까지 함께 출력한다.

풀이:
트라이 알고리즘 기본 문제입니다.
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