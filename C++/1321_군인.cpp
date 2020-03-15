/*
문제
캠프 내내 그랬듯이, 여전히 옆 나라와의 전쟁이 한창이다.

전쟁에는 N개의 부대가 투입되었는데, 전쟁이 장기전이 되다 보니 군사의 적절한 배치를 위해 각 부대에 군인이 늘어나기도 하고 줄어들기도 하고 있다.

행정의 편의를 위해 각 군인들에겐 번호가 붙어 있는데, 군인들은 1번 부대부터 군번순서대로 차례차례 배치된다. 예를 들어 1번 부대에 4명, 2번 부대에 3명, 3번 부대에 7명의 군인이 있다면 군번이 6번인 군인은 2번 부대에 배치되게 된다.

문제는 어떤 부대의 인원이 늘어나거나 줄어들었을 때 i번 군인이 어디에 배치되는지 인데, 이럴 때에는 군인도 군번도 처음부터 다시 배치하게 된다. 위의 예에서와 같이 1번 부대에 4명, 2번 부대에 3명, 3번 부대에 7명의 군인이 있었는데, 1번 부대에서 3명의 감원이 일어난다면, 6번 군인은 3번 부대에 재배치 받게 된다.

전쟁 때는 부대의 감원과 증원이 많아 군사 재배치도 자주 일어나게 되는데, 이렇게 자주 배치가 바뀌자 군인들은 자기가 도대체 어떤 부대에 속하는 지 헷갈리게 되었다. 다행히도 바뀐 군번은 다들 정확하게 숙지하고 있다.

부대의 개수 N과 각 부대에 속해 있는 군인의 수가 N개 주어질 때, 부대의 감원과 증원을 한 후, 혹은 그 중에 군번 i번의 군인이 몇 번 부대에 속하는 지를 물어봤을 때, 그 질문에 대답을 해 줄 수 있는 프로그램을 작성하시오.

i번 부대에 증원이나 감원을 할 때엔 "1 i a"의 형태로 명령이 주어지고, 이는 i번 부대에 a명을 더한다는 뜻이다. 감원을 할 때엔 a가 0보다 작은 수로 주어진다. 감원을 해서 부대의 인원수가 0보다 작아지는 입력은 들어오지 않는다. a는 절댓값이 1보다 크거나 같고, 1000보다 작거나 같은 정수이다.

군번 i번의 군인이 어떤 부대에 배치 받았는지 알고 싶을 때는 "2 i"의 형태로 명령이 주어지고, 이런 명령을 받았을 때는 i번 군인이 몇 번 부대에 배치 받았는지를 출력해야 한다. i는 전체 군인 수보다 작거나 같은 자연수이다.

입력
첫째 줄에 부대의 개수 N(1≤N≤500,000)이 주어지고, 이어서 각 부대의 군사 수를 나타내는 정수가 N개 주어진다. 각 부대의 군사 수는 1000보다 작거나 같은 자연수이다. 그 다음 줄에 명령의 개수 M(1≤M≤10,000)개가 주어지고, 이어서 M줄에 걸쳐 명령이 주어진다.

출력
질문한 군인이 몇 번 부대에 배치 받았는지를 한 줄에 하나씩 출력한다.

풀이:
구간합 세그먼트 트리를 구현하고, 트리를 update 해가며 풀이합니다.
2번 질의에 대해 찾고자하는 번호를 향해 leaf노드를 탐색하는데, 1번부터 봐야하므로 왼쪽 먼저 탐색하고,
 왼쪽 구간합에 해당하지 않는다면 오른쪽 구간합을 볼 때, 왼쪽 구간합의 값을 빼줍니다.
*/

#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
#include<memory.h>
using namespace std;

int N, M;
int* tree;

void update(int now, int l, int r, int idx, int diff) {
	if (idx > r || idx < l)	return;
	tree[now] += diff;
	if (r == l)	return;
	
	update(now * 2, l, (l + r) / 2, idx, diff);
	update(now * 2 + 1, (l + r) / 2 + 1, r, idx, diff);
}

int searchNum(int now, int l, int r, int v) {
	if (r == l) {
		return l;
	}
	if (tree[now * 2] >= v) {
		return searchNum(now * 2, l, (l + r) / 2, v);
	}
	else {
		//오른쪽의 구간합은 왼쪽값이 들어있지 않으므로 (v - 왼쪽 구간합)
		return searchNum(now * 2 + 1, (l + r) / 2 + 1, r, v - tree[now * 2]);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	double H = ceil(log2(N));
	tree = (int*)malloc(sizeof(int) * (int)pow(2, H + 1));
	memset(tree, 0, sizeof(int) * (int)pow(2, H + 1));

	for (int i = 1; i <= N; i++)
	{
		int n;
		cin >> n;
		update(1, 1, N, i, n);
	}
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int q, a, b;
		cin >> q;

		if (q == 1) {
			cin >> a >> b;

			update(1, 1, N, a, b);
		}
		else {
			cin >> a;

			cout << searchNum(1, 1, N, a) << "\n";
		}
	}
}