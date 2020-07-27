/*
문제
당신은 루머를 믿는가?

한 유명 심리학 실험에서는 사람들에게 두 개의 줄을 보여주고, 어떤 줄이 더 긴지 말하라 했다. 사실 한 사람을 제외하고 나머지는 실험자에 의해 사전에 조작된 사람들이었다. 조작된 사람들은 사실상 더 짧은 줄을 더 길다고 말했다. 주변 모두가 같은 답변을 하자, 진짜 피실험자 또한 짧은 줄이 더 길다고 말했다. 이 실험은 사람들이 주변인의 영향을 강하게 받는다는 것을 보여주었는데, 루머도 이와 같다.

루머는 최초 유포자로부터 시작한다. 최초 유포자는 여러 명일 수 있고, 최초 유포자를 제외하고 스스로 루머를 만들어 믿는 사람은 없다.

매분 루머를 믿는 사람은 모든 주변인에게 루머를 동시에 퍼트리며, 군중 속 사람은 주변인의 절반 이상이 루머를 믿을 때 본인도 루머를 믿는다.

루머를 믿는 순간부터 다른 말은 듣지 않기 때문에, 한번 믿은 루머는 계속 믿는다.

이때, 사람들이 루머를 처음 믿기 시작하는 시간을 알아내 보자.

입력
첫째 줄에 사람의 수 이 주어진다. () 이는 번 사람부터 번 사람까지 있음을 의미한다.

둘째 줄부터 개의 줄이 주어진다. 이 중 번째 줄에는 번 사람의 주변인들의 번호와 입력의 마지막을 나타내는 0이 공백으로 구분되어 주어진다. 번호는  이상  이하의 자연수이고, 같은 줄에 중복된 번호는 없다. 자기 자신이 주변인이거나 일방적으로 주변인인 경우는 없으며, 전체 양방향 주변인 관계는 개를 넘지 않는다.

다음 줄에는 루머를 퍼뜨리는 최초 유포자의 수 이 주어진다.
마지막 줄에는 최초 유포자의 번호가 공백으로 구분되어 주어진다. 최초 유포자의 번호는 중복되지 않는다.

출력
개의 정수 을 공백 단위로 출력한다. 는 번 사람이 루머를 처음 믿기 시작한 시간(분)이며, 충분히 많은 시간이 지나도 루머를 믿지 않을 경우 이다. 최초 유포자는 루머를 분부터 믿기 시작했다고 생각한다.

풀이:
bfs 응용 문제

현재 노드가 루머를 믿을 때 -> 주변 노드들에게 신뢰도를 1 증가시키고, 탐색
이 때, 다음 노드가 루머를 믿지 못 한다면, 탐색하지 않음.

현재 노드가 루머를 믿지 않을 때 -> 현재 노드를 시간을 증가시켜 큐에 추가

모두가 루머를 믿을 때 최악의 경우 최대 n - 1 시간만이 걸리므로 해당 시간을 초과하면 탐색을 중단.
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

int n, m;
vector<int> edge[200001];
queue<pii> q;
int ans[200001];
int trust_cnt[200001];

int main(void) {
	FIO;

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		while (true) {
			int near;
			cin >> near;
			if (near == 0)	break;

			edge[i].push_back(near);
		}
		ans[i] = -1;
	}

	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int p;
		cin >> p;
		q.push(make_pair(p, 0));
		ans[p] = 0;
	}

	while (!q.empty()) {
			int nowP = q.front().first;
			int nowTime = q.front().second;
			q.pop();

			if (nowTime > n)	break;
			if (ans[nowP] > nowTime)	continue;

			if (ans[nowP] != -1) {
				for (int i = 0; i < edge[nowP].size(); i++)
				{
					int nextP = edge[nowP][i];

					if (ans[nextP] == -1) {
						trust_cnt[nextP]++;

						int mid = edge[nextP].size() / 2;
						if (edge[nextP].size() % 2 != 0)
							mid++;

						if (trust_cnt[nextP] >= mid)
							ans[nextP] = nowTime + 1;

						if(ans[nextP] != -1)
							q.push(make_pair(nextP, nowTime + 1));
					}
					
				}
			}
			else {
				q.push(make_pair(nowP, nowTime + 1));
			}
	}

	for (int i = 1; i <= n; i++)
	{
		cout << ans[i] << " ";
	}
}