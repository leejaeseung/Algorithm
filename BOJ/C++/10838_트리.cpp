/*
����
N���� ���� ������ ��Ʈ�� �ִ� Ʈ���� ������ ���� �־�����. �� ���� 0���� N-1������ ��ȣ�� �����ǰ�, 0�� ���� ��Ʈ ����̰�, ������ ��� ������ 0�� ����� �ڽ� ����̴�.

Ʈ���� ������ �� �ִ� ������ �� �����̸�, �̸� ���� Ʈ���� ����� �ٲٰų� Ʈ�� ������ ��ĥ�� �� �� �ִ�. �� ����� �� �ǹ̴� ������ ����.

paint(a, b, c): a�� ���� b�� ��带 �մ� �ִ� ��θ� ã�� ��, ��� �� �ִ� ��� ������ ���� c�� ĥ�Ѵ�.
move(a, b): a�� ����� �θ� ��带 b�� ���� �ٲ۴�. ��, b�� ���� a�� ��带 ��Ʈ�� �ϴ� ��Ʈ��(subtree)�� ������ �ʴ´�. �θ� ��带 �ٲٱ� �� a�� ����� �θ� ��带 p�� �� ��, ���ο� ���� (a,b)�� ������ ���� (a,p)�� ������ ���´�.
count(a, b): a�� ���� b�� ��带 �մ� �ִܰ�θ� ã�� ��, �� ��� ���̿� �ִ� ������ ĥ���� ���� �ٸ� ������ ������ ����Ѵ�.
������ ĥ�ϴ� ���� c�� ������ ǥ���Ѵ�. �׸��� ó������ ��� ������ ������ 0�̶�� �����Ѵ�.

���� ���, �׸� 1���� ���� ��ó�� 6���� ���� ������ �ʱ� Ʈ���� ����� ������ ���ʷ�

move(1,3); move(5,3); paint(5,4,8); move(3,4); paint(0,3,7); count(2,5);

�� ��, �� ������ ������ �� ��� Ʈ���� ���� ���� ������ �ٲ������ �Ʒ� �׸� 2���� �׸� 4���� ���ʴ�� ������.



�׸� 1. �ʱ� ����



�׸� 2. ����: move(1,3)�� ������ ��, ����: move(5,3)�� ���� �� ��



�׸� 3. paint(5,4,8)�� ������ ��



�׸� 4. ����: move(3,4)�� ������ ��, ����: paint(0,3,7)�� ������ ��

�׸���, ������ ���� count(2,5)�� ���� ����δ� 3�� ����ϰ� �ȴ�. �ֳ��ϸ�, �׸� 4�� ���� �׸����� ������ 2�� ���� 5�� ��� ������ �ִ� ��� �� �ִ� �����鿡 ĥ���� ������ {0,7,8}�� 3�����̱� �����̴�.

Ʈ���� ���� ������ �Ϸ��� ������ �־��� ��, �� ������ ȿ�������� �����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ��� �տ��� ������ Ʈ���� ��� ������ ��Ÿ���� ���� N(1 �� N �� 105)�� ������ ������ ��Ÿ���� ���� K(1 �� K �� 3��105)�� �־�����. �̾ K �ٿ� ���� �� ���꿡 ���� ������ �� �ٿ� �ϳ��� �־����µ�, �� �ٿ��� ������ ������ ��Ÿ���� ���� r(1 �� r �� 3)�� ù ��°�� �־�����.

r = 1�� ��쿣 ������ paint ���� �ǹ��ϸ�, �� ���� (a,b,c)�� �߰��� ���� �ٿ� �־����µ�, ���⼭ a, b(0 �� a, b �� N-1)�� ��� ��ȣ��, c(0 �� c ��109)�� ���� ��ȣ�� ��Ÿ����.
r = 2�� ��쿣 ������ move���� �ǹ��ϸ�, �� ���� a, b(1 �� a �� N-1, 0 �� b �� N-1)�� �߰��� ���� �ٿ� �־����µ�, �̴� ��� ��ȣ�� ��Ÿ����.
r = 3�� ��쿣 ������ count���� �ǹ��ϸ�, �� ���� a, b(0 �� a, b �� N-1)�� �߰��� ���� �ٿ� �־����µ�, �̴� ��� ��ȣ�� ��Ÿ����.
����� ������ N�� Ʈ���� �ʱ� ����� �׸� 1���� ���� ��ó�� 0�� ��尡 ��Ʈ�̰�, ������ ������ �θ� ���� 0�� ����̸�, �ʱ� Ʈ���� ��� ���� ������ 0�̶�� ������ ����� ����ϱ� �ٶ���.

����, paint�� count ���� �� a�� ���� b�� ��� ������ �ִܰ���� ���̴� �׻� 1,000 �����̴�.

���
�Է¿��� �־��� count ���� ������ ����, �� ������� �� ���� ��� ���� �� �ٿ� ����Ѵ�.

Ǯ��:
���ǿ� �ִ� �Ÿ��� �ִ� 1000���� �����ؾ� �Ѵ�.
�׷��� �ִ� 3����� ���길���� �����ϴ�.
��, LCA(�ּ� ����) �� ã�� ���� 1000�� �̻� ã�� ������ ���� ������ ����ó���� ���־�� �ð� �ʰ��� �ȳ���.
���� ������ �ſ� ũ�Ƿ� ��ǥ ������ �ϰų� set�� ����ϸ� �ȴ�.
set �� ������� ���� �ð��� �� �ɷȴ�.
*/

//��ǥ ���� �ڵ�

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

int n, k;
int parent[100001];
int color[100001];
set<int> color_set;
vector<int> colors;
bool visit[300001];
int ancCheck[100001];
int anc_idx = 1;

int getAnc(int n1, int n2) {
	//�ּ� ������ ���� ��, �ִ� 1000���� �̵��� �Ѵ�.

	int move = 0;

	while (n1 != 0 && move <= 1000) {
		ancCheck[n1] = anc_idx;
		n1 = parent[n1];
		move++;
	}

	move = 0;

	while (n2 != 0 && move <= 1000) {
		if (ancCheck[n2] == anc_idx) {
			anc_idx++;
			return n2;
		}
		n2 = parent[n2];
		move++;
	}

	anc_idx++;
	return n1;
}

void paint(int n1, int n2, int c) {
	
	int anc = getAnc(n1, n2);

	while (n1 != anc) {
		color[n1] = c;
		n1 = parent[n1];
	}

	while (n2 != anc) {
		color[n2] = c;
		n2 = parent[n2];
	}
}

int cnt(int n1, int n2) {

	vector<int> check;

	int ret = 0;
	int anc = getAnc(n1, n2);

	while (n1 != anc) {
		int nowC = lower_bound(colors.begin(), colors.end(), color[n1]) - colors.begin();

		if (!visit[nowC]) {
				ret++;
				visit[nowC] = true;
				check.push_back(nowC);
		}

		n1 = parent[n1];
	}

	while (n2 != anc) {
		int nowC = lower_bound(colors.begin(), colors.end(), color[n2]) - colors.begin();

		if (!visit[nowC]) {
			ret++;
			visit[nowC] = true;
			check.push_back(nowC);
		}

		n2 = parent[n2];
	}

	for (int i = 0; i < check.size(); i++)
	{
		visit[check[i]] = false;
	}

	return ret;
}

int main(void) {
	FIO;

	cin >> n >> k;

	queue<pair<pii, pii>> query;

	parent[0] = -1;
	color_set.insert(0);

	for (int i = 1; i <= n; i++)
	{
		parent[i] = 0;
	}

	for (int i = 0; i < k; i++)
	{
		int r, a, b, c;
		cin >> r >> a >> b;

		if (r == 1) {
			cin >> c;
			query.push({ {r, a}, {b, c} });
			color_set.insert(c);
		}
		else {
			query.push({ {r, a}, {b, -1} });
		}
	}

	for (auto iter = color_set.begin(); iter != color_set.end(); iter++)
	{
		//��ǥ ����
		colors.push_back(*iter);
	}

	while (!query.empty()) {
		int r = query.front().first.first;
		int a = query.front().first.second;
		int b = query.front().second.first;
		int c = query.front().second.second;
		query.pop();

		if (r == 1) {
			paint(a, b, c);
		}
		else if (r == 2) {
			parent[a] = b;
		}
		else {
			cout << cnt(a, b) << "\n";
		}
	}
}

//map ��� �ڵ�

/*#include<iostream>
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

int n, k;
int parent[100001];
int color[100001];
int ancCheck[100001];
int anc_idx = 1;

int getAnc(int n1, int n2) {

	int move = 0;

	while (n1 != 0 && move <= 1000) {
		ancCheck[n1] = anc_idx;
		n1 = parent[n1];
		move++;
	}

	move = 0;

	while (n2 != 0 && move <= 1000) {
		if (ancCheck[n2] == anc_idx) {
			anc_idx++;
			return n2;
		}
		n2 = parent[n2];
		move++;
	}

	anc_idx++;
	return n1;
}

void paint(int n1, int n2, int c) {

	int anc = getAnc(n1, n2);

	while (n1 != anc) {
		color[n1] = c;
		n1 = parent[n1];
	}

	while (n2 != anc) {
		color[n2] = c;
		n2 = parent[n2];
	}
}

int cnt(int n1, int n2) {

	set<int> visit;

	int ret = 0;
	int anc = getAnc(n1, n2);

	while (n1 != anc) {
		int nowC = color[n1];

		if (visit.find(nowC) == visit.end()) {
			ret++;
			visit.insert(nowC);
		}

		n1 = parent[n1];
	}

	while (n2 != anc) {
		int nowC = color[n2];

		if (visit.find(nowC) == visit.end()) {
			ret++;
			visit.insert(nowC);
		}

		n2 = parent[n2];
	}

	return ret;
}

int main(void) {
	FIO;

	cin >> n >> k;

	parent[0] = -1;

	for (int i = 1; i <= n; i++)
	{
		parent[i] = 0;
	}

	for (int i = 0; i < k; i++)
	{
		int r, a, b, c;
		cin >> r >> a >> b;

		if (r == 1) {
			cin >> c;
			paint(a, b, c);
		}
		else if (r == 2) {
			parent[a] = b;
		}
		else {
			cout << cnt(a, b) << "\n";
		}
	}
}*/