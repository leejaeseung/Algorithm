/*
����
�����̴� �ſ� ��ڱ� ������, ȿ���̿��� ������ �̸�Ƽ���� S�� �������� �Ѵ�.

�����̴� �̹� ȭ�鿡 �̸�Ƽ�� 1���� �Է��ߴ�. ����, ������ ���� 3���� ���길 ����ؼ� �̸�Ƽ���� S�� ����� ������ �Ѵ�.

ȭ�鿡 �ִ� �̸�Ƽ���� ��� �����ؼ� Ŭ�����忡 �����Ѵ�.
Ŭ�����忡 �ִ� ��� �̸�Ƽ���� ȭ�鿡 �ٿ��ֱ� �Ѵ�.
ȭ�鿡 �ִ� �̸�Ƽ�� �� �ϳ��� �����Ѵ�.
��� ������ 1�ʰ� �ɸ���. ��, Ŭ�����忡 �̸�Ƽ���� �����ϸ� ������ Ŭ�����忡 �ִ� ������ ����Ⱑ �ȴ�. Ŭ�����尡 ����ִ� ���¿��� �ٿ��ֱ⸦ �� �� ������, �Ϻθ� Ŭ�����忡 ������ ���� ����. ����, Ŭ�����忡 �ִ� �̸�Ƽ�� �� �Ϻθ� ������ �� ����. ȭ�鿡 �̸�Ƽ���� �ٿ��ֱ� �ϸ�, Ŭ�����忡 �ִ� �̸�Ƽ���� ������ ȭ�鿡 �߰��ȴ�.

�����̰� S���� �̸�Ƽ���� ȭ�鿡 ����µ� �ɸ��� �ð��� �ּڰ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� S (2 �� S �� 1000) �� �־�����.

���
ù° �ٿ� �̸�Ƽ���� S�� ����� ���� �ʿ��� �ð��� �ּڰ��� ����Ѵ�.

Ǯ��:
bfs�� Ǯ���߽��ϴ�.
(���� ��, Ŭ������ ���簪) ���� �湮 üũ�� �ذ��� bfs Ž���ϸ� �˴ϴ�.
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

int s;
bool visit[5000][5000];
int cnt[10000];

int main(void) {
	FIO;

	cin >> s;

	queue<pair<pii, int>> q;
	q.push(make_pair(make_pair(1, 0), 0));

	int ans = IMAX;

	while (!q.empty()) {
		int now = q.front().first.first;
		int now_cnt = q.front().first.second;
		int clip = q.front().second;
		q.pop();

		if (ans <= now_cnt)	continue;
		if(now == s)
			ans = min(ans, now_cnt);

		if (now < 1)	continue;
		if (visit[now][clip])	continue;
		visit[now][clip] = true;

		//1�� ����
		q.push(make_pair(make_pair(now + clip, now_cnt + 1), clip));
		//2�� ����
		q.push(make_pair(make_pair(now, now_cnt + 1), now));
		//3�� ����
		q.push(make_pair(make_pair(now - 1, now_cnt + 1), clip));
	}

	cout << ans;
}