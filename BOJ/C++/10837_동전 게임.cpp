/*
문제
영희와 동수는 동전 던지기 게임을 하고 있다. 이 게임은 K번 라운드로 구성되고 다음과 같은 규칙들을 따른다:

한 라운드에서 영희와 동수는 한 번씩 동전을 던지고 항상 영희가 먼저 던진다.
동전을 던져 앞면이 나오면 1점을 얻고, 뒷면이 나오면 점수를 얻지 못한다.
한 명이 남은 기회에 모든 점수를 얻더라도 상대방이 현재까지 얻은 점수보다 작게 되면 게임 도중 어떤 시점에서도 게임은 바로 끝난다.
0이상 K이하인 임의의 정수 M과 N에 대해서, 이것이 항상 게임이 끝난 후 영희와 동수가 얻는 점수가 되는 것은 아니다. 예를 들어서, K = 2인 경우에, M과 N의 모든 경우에 대해서, 이것이 영희와 동수가 얻는 점수가 될 수 있는 지의 여부는 다음 표와 같다:

M	N	영희, 동수의 점수가 될 가능성
0	0	가능
0	1	가능
0	2	불가능
1	0	가능
1	1	가능
1	2	가능
2	0	가능
2	1	가능
2	2	가능
위 표에서 영희와 동수의 점수가 0과 2가 되는 것이 불가능한 이유는 두 번째 라운드에서 영희가 뒷면이 나와서 점수를 얻지 못하는 순간 게임의 규칙 3에 의해서 0과 1로 게임이 끝나기 때문이다.

0이상 K이하인 정수 M과 N이 주어질 때, 이 두 정수가 각각 영희와 동수의 점수가 될 수 있는지 여부를 판별하는 프로그램을 작성하시오.

입력
첫 줄에 게임의 라운드 수를 나타내는 정수 K(1 ≤ K ≤ 1,000)가 주어진다. 두 번째 줄에는 입력의 개수를 나타내는 정수 C(1 ≤ C ≤ 100,000)가 주어진다. 다음 이어지는 C개의 줄 각각에는 하나의 입력을 나타내는 두 정수 M과 N(0 ≤ M, N ≤ K)이 주어진다.

출력
출력은 C개의 줄로 구성된다. 게임에서 영희와 동수의 점수가 각각 M과 N이 될 수 있다면 1, 아니면 0을 각 줄에 출력한다.

풀이:
n(영희), m(동수) 에 대해 max(n, m) 이 해당 구간까지의 라운드 수로 생각하자.
그러면, n, m 중 큰 쪽이 이전 라운드에서 앞면이 나와 게임을 끝냈다고 생각할 수 있다.

1. 영희가 이기는 경우
- 이전 라운드, 즉 (n - 1), m 인 상태에서 남은 라운드(k - n + 1) + m 이 (n - 1) 보다 작다면 
이미 이전 라운드에서 게임이 끝나있으므로 동전을 던질 수 없기 때문에 0 을 출력한다.
(반대라면 1 출력)
2. 동수가 이기는 경우
- 1번과 같은 맥락에서 영희가 마지막에 0을 던져야 하므로 영희의 기회가 1번 사라진다.
즉 k - n + m < n - 1  -> 0 출력
3. 비기는 경우
- 항상 1이다.
*/
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

int k, c, n, m;

int main(void) {
	FIO;

	cin >> k >> c;

	for (int i = 0; i < c; i++)
	{
		cin >> n >> m;

		if (n > m) {
			if (m + k < n * 2 - 2)
				cout << "0\n";
			else
				cout << "1\n";
		}
		else if (n < m) {
			if (n + k < m * 2 - 1)
				cout << "0\n";
			else
				cout << "1\n";
		}
		else
			cout << "1\n";
	}
}