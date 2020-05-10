/*
문제
아기 석환은 아기다. 아기 석환이는 집안을 돌아다니며 사탕을 뿌려 놓는 것을 즐긴다. 성원이는 아기 석환이때문에 집이 더럽혀져서 골치가 아프다. 이를 해결하기 위해 성원이는 작은 청소로봇을 만들었다.

성원이네 집은 n개의 방과 m개의 복도로 이루어져 있고, 하나의 복도는 서로 다른 두 개의 방을 연결하여 두 방 사이를 자유롭게 오갈 수 있도록 한다. 각 방에는 1번부터 n번까지 번호가 붙어있다. 아기 석환이는 복도에만 사탕을 뿌려 두었다. 따라서 현재 각 복도에는 일정량의 사탕이 존재하고, 방 안에는 사탕이 없다.

성원이가 만든 로봇은 다음과 같이 동작한다.

성원이가 로봇에 시작방 번호와 도착방 번호, 로봇의 이동경로를 입력하고 그 로봇을 시작방에 놓아두면, 로봇이 알아서 입력한 경로를 따라 도착방까지 움직인다.
로봇은 사탕이 존재하는 복도만 지나갈 수 있다. 그리고 복도 하나를 지나갈 때 그 복도에 있는 사탕 중 딱 1개만 주워 지나간다. 성원이는 이 조건을 만족하는 경로만 입력할 수 있다.
성원이는 이 로봇을 이용해 아기 석환이가 어지럽혀 놓은 집을 청소하면서도 본인의 흥미를 추구할 방법을 생각했다. 모든 로봇이 1번 방에서 출발해 n번 방으로 도착하게 하면서도 경로를 각각 잘 설정하면, 로봇들이 집안을 적절하게 돌아다니며 사탕을 주울 것이다. 이때, 성원이는 로봇을 최대 몇 개나 세팅할 수 있을지를 알고 싶다. 여러분이 성원이의 궁금증을 해결해주자.

입력
첫 번째 줄에 성원이네 집안에 있는 방의 개수를 나타내는 자연수 n(2 ≤ n ≤ 300)과 복도의 개수를 나타내는 자연수 m(1 ≤ m ≤ 5,000)이 공백으로 구분되어 주어진다.

두 번째 줄부터 m개의 줄에 걸쳐 복도의 정보가 한 줄에 하나씩 주어진다. 각 줄에는 세 개의 자연수 a, b, c가 주어지는데, 이는 a번 방과 b번 방 사이에 복도가 있고 그 복도에는 c개의 사탕이 놓여있다는 것을 의미한다. (a ≠ b,  1 ≤ a, b ≤ n,  1 ≤ c ≤ 100)

출력
첫 번째 줄에 성원이가 세팅할 수 있는 로봇의 최댓값을 출력한다.

풀이:
최대 유량 기본 문제.
*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>
#define pic pair<int, char>
#define ll long long
#define vi vector<int>
#define vl vector<long long>
#define vii vector<pii>

int n, m;
int c[301][301];
int f[301][301];
vector<int> edge[301];
int pre[301];

void bfs() {

	queue<int> q;
	q.push(1);

	while (!q.empty()) {
		int now = q.front();	q.pop();

		for (size_t i = 0; i < edge[now].size(); i++)
		{
			int next = edge[now][i];

			if (pre[next] != -1)	continue;
			if (next == 1)	continue;

			if (c[now][next] - f[now][next] > 0) {
				
				pre[next] = now;
				q.push(next);
				

				if (next == n)	break;
			}
		}
	}
}

int main(void) {
	FIO;

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b, v;
		cin >> a >> b >> v;

		edge[a].push_back(b);
		edge[b].push_back(a);
		c[a][b] += v;
		c[b][a] += v;
	}

	int ans = 0;

	while (1) {

		for (int i = 0; i <= n; i++)
		{
			pre[i] = -1;
		}

		bfs();

		if (pre[n] == -1)	break;

		int now = n;
		int maxC = 1000000000;

		while (pre[now] != -1) {
			maxC = min(maxC, c[pre[now]][now] - f[pre[now]][now]);

			now = pre[now];
		}

		now = n;

		while (pre[now] != -1) {
			f[now][pre[now]] -= maxC;
			f[pre[now]][now] += maxC;

			now = pre[now];
		}

		ans += maxC;
	}

	cout << ans;
}