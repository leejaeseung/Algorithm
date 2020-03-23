/*
문제
종빈이는 아주 큰 그룹의 총수다. 이 그룹은 1부터 N번까지의 번호로 구분할 수 있는 N개의 기업을 운영하고 있다. 현재 각 기업은 서로 독립적인 자체 컴퓨팅 및 통신센터를 가지고 있다.

어느 날 종빈이는 계열사의 CTO인 서현이에게 서비스 개선을 위해 각 기업의 서버를 네트워크로 연결하여 단일 통신센터에서 관리 가능한 클러스터 형태로 구성할 것을 제안했다. 종빈이의 제안을 들은 서현이는 다음과 같은 병합 과정을 고안해냈다.

클러스터 A를 제공하는 기존에 존재하는 센터 I를 고른다.
클러스터 B를 제공하는 기업 J를 고른다. B는 A가 아닌 임의의 클러스터이며, J는 센터가 아닐 수 있다.
I와 J를 통신 라인으로 연결한다. 이때 기업 I와 J를 잇는 라인의 길이는 |I – J|(mod 1000)이다.
위 방식을 통해 클러스터 A와 B는 새로운 클러스터로 합쳐지며, 이 클러스터는 B의 센터에 의해 제공된다.
이러한 병합 과정을 거치던 중에, 각 기업에서 현재 센터까지 연결되는 라인의 길이가 총 얼마나 되는지에 관한 문의가 들어왔다. 서현이를 위해 병합하는 과정과 그 과정에서 통신센터와 각 기업을 잇는 라인의 길이를 구하는 프로그램을 작성해보자.

입력
입력은 여러 개의 테스트케이스로 주어진다. 입력의 첫 번째 줄에는 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스에는 기업의 수를 나타내는 N(4 ≤ N ≤ 20,000)이 주어진다. 다음은 몇 개의 줄에 걸쳐 아래 두 가지 종류의 명령어가 들어온다.

E I – 기업 I와 현재 I의 센터까지의 거리를 출력한다.
I I J – 센터 I를 기업 J에 연결한다.
각 테스트케이스의 끝에는 단어 O가 주어진다. 각 테스트케이스에서 명령어의 총 개수는 200,000개를 넘지 않으며, 그중 I 명령어의 개수는 N개보다 작다.

출력
E 명령어가 들어올 때마다 한 줄에 해당 거리를 출력한다.

풀이:
센터와 기업을 잇는 연산은 단순히 I의 부모를 J로 설정하고, I -> J의 코스트(I에서 루트로의)를 설정하면 됩니다.
find 함수를 통해 자식 노드들을 루트 노드에 붙여주면서 자식 노드들은 자신의 부모 노드의 간선 값을 cost에 더해갑니다.

처음엔 I a b 했을 때 b가 새로운 센터가 되는 줄 알았는데 parent[b] 가 센터이므로 parent[a] = b 만 해주면 find()에서
알아서 루트를 찾아가게 됩니다.
*/
#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<vector>
#include<queue>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pii pair<int, int>

int N;
int parent[20001];
int cost[20001];

int find(int now) {
	if (now == parent[now])
		return now;
	int p = find(parent[now]);

	cost[now] += cost[parent[now]];
	return parent[now] = p;
}

void merge(int x, int y) {
		parent[x] = y;
		cost[x] = abs(x - y) % 1000;
}

int main(void) {
	FIO; 

	int T;
	cin >> T;
	while (T--) {
		cin >> N;

		char order;
		int a, b;
		for (int i = 0; i <= N; i++)
		{
			parent[i] = i;
			cost[i] = 0;
		}

		while (true) {
			cin >> order;

			if (order == 'O')	break;
			else if (order == 'I') {
				cin >> a >> b;

				merge(a, b);
			}
			else {
				cin >> a;
				find(a);
				cout << cost[a] << "\n";
			}
		}
	}
}