/*
문제
도도는 시공의 폭풍으로 빨려 들어간 에아를 찾으러 나섰습니다. 에아가 지금으로부터 미래로 (-n)년과 n년 사이에 있다는 정보만 알고서 타임머신을 찾아 나선 도도는, 검은 마법사로부터 신기한 문을 알아냈습니다.

이 문은 앞면과 뒷면이 있으며, 앞면이 뒷면보다 항상 1년 미래입니다. 즉, 문을 앞에서 뒤로 들어가면 1년 과거로 갈 수 있고, 뒤에서 앞으로 들어가면 1년 미래로 갈 수 있습니다.

악마 같은 검은 마법사는 이 문을 그냥 줄 수는 없다면서, n개의 문을 이어붙인 통로를 주겠다고 했습니다. 도도는 오랜 연구 끝에 특정 문의 조합을 180도 돌릴 수 있는 m개의 스위치를 설치했습니다. 이제 이 스위치를 사용하여 에아를 구하러 갑시다!

입력
첫째 줄에 n(1 ≤ n ≤ 100)과 m(1 ≤ m ≤ 20)이 주어집니다.

둘째 줄에 길이 n의 0과 1로만 구성된 문자열이 주어집니다. 모든 1 ≤ j ≤ n에 대해, 이 문자열의 j번째 문자는 j번째 문의 초기 상태를 나타내며, 0이라면 문의 앞면, 1이라면 문의 뒷면이 도도를 향하고 있음을 나타냅니다.

셋째 줄부터 (m+2)번째 줄까지 길이 n의 0과 1로만 구성된 문자열 m개가 주어집니다. 모든 1 ≤ i ≤ m, 1 ≤ j ≤ n에 대해 (i+2)번째 줄의 j번째 문자는 i번 스위치가 j번 문을 180도 돌리는지 여부를 나타내며, 0이라면 돌리지 않음을, 1이라면 돌림을 의미합니다.

출력
총 (2n+1)개의 줄을 출력합니다. 모든 -n ≤ i ≤ n에 대해, (i+n+1)번째 줄에는 미래로 i년을 가려고 할 때에 해당하는 답을 출력합니다.

각 줄에는, 정답이 존재한다면 눌러야 하는 스위치의 개수 k(0 ≤ k ≤ m)와 스위치 번호를 공백을 사이에 두고 출력합니다. 정답이 존재하지 않으면 -1을 출력합니다.

눌러야 하는 스위치의 조합이 여러 가지라면 아무거나 하나를 출력합니다.

풀이:

문과 스위치의 값을 bitset을 이용해 bit값으로 바꿔줍니다.
그 뒤, 스위치들에 대하여 모든 경우를 탐색하면서(문을 바꿔가며 -> 문과 스위치의 ^ 연산) 현재 문의 상태로 갈 수 있는 년도를 구합니다.
년도는 n 이 100이하이므로 100년을 시작년도로 생각하였습니다.
방문 배열을 만들어 현재 어떤 스위치를 켰는지(bitMask 이용)에 대한 방문 여부를 걸러줍니다.
그렇게 하면 하나의 스위치 상태에 대해 하나의 년도만 나오게 됩니다.
즉, rt[해당 년도] = 스위치의 bitMask
100 - N 년부터 100 + N 년까지 스위치의 bitMask를 적절히 출력하면 됩니다.
*/
#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<vector>
#include<bitset>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pii pair<int, int>;

int N, M;
bitset<101> swit[21];
bitset<101> door;
int rt[202];
int sizeY[202];
bool visit[1048577];

void BF(bitset<101> now, int cnt, int switBit) {
	if (cnt > M)	return;
	if (visit[switBit])	return;
	visit[switBit] = true;
	for (int i = 1; i <= M; i++)
	{
		int bit = (1 << (i - 1));
		BF(now ^ swit[i], cnt + 1, switBit | bit);
	}

	int year = 100 - N + (now.count() * 2);

	sizeY[year] = cnt;

	rt[year] = switBit;
}

int main(void) {
	FIO;

	cin >> N >> M;

	string start;
	cin >> start;

	for (int i = 0; i < start.size(); i++)
	{
		if (start.at(i) == '1')
			door.set(100 - i, true);
	}
	for (int i = 1; i <= M; i++)
	{
		string s;
		cin >> s;

		for (int j = 0; j < s.size(); j++)
		{
			if (s.at(j) == '1')
				swit[i].set(100 - j, true);
		}
	}
	for (int i = 0; i < 202; i++)
	{
		sizeY[i] = -1;
	}

	BF(door, 0, 0);

	int y = 100 - N;
	while (y <= 100 + N) {
		cout << sizeY[y] << " ";

		int cnt = 1;
		while (rt[y] != 0) {
			if ((rt[y] & 1) != 0)
				cout << cnt << " ";

			cnt++;
			rt[y] = rt[y] >> 1;
		}
		cout << "\n";
		y++;
	}
}