/*
문제
Sogang ACM-ICPC Team은 전통적으로 1학기에 신입생들에게 C언어를 가르쳐준다. 올해는 상근이가 C언어를 가르쳐 주기로 했다.

어느 날, 링크드 리스트를 설명하는 날이었다. 상근이는 앞에서, 구조체와 malloc을 이용해 링크드 리스트를 구현하는 방법을 설명하고 있었다.

2시간에 걸친 설명을 듣던 중, 지루해진 N명의 학생들은 남은 M분 동안 상근이 몰래 YouTube를 보기로 했다.

YouTube에는 K개의 동영상이 있고, 1번부터 K번까지 번호가 매겨져 있다. 동영상을 볼 때, 우측에는 추천 동영상이 떠있다.

모든 학생은 메인 페이지에서 동영상 하나를 시청한다. 동영상을 시청하고 1분이 지나면, 추천 동영상 중 가장 위에 있는 동영상을 시청한다. (모든 동영상은 정확히 1분만 시청한다)

각 학생이 처음에 시청한 동영상 번호와, 각 동영상의 추천 동영상 중 가장 위에 있는 동영상의 번호가 주어졌을 때, M분에 각 학생이 시청한 동영상 번호를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 N, K, M이 주어진다. (1 ≤ N,K ≤ 100,000) (1 ≤  M ≤  1,000,000,000) N은 학생의 수, K는 동영상의 개수, M은 남은 수업 시간이다.

둘째 줄에는 1보다 크거나 같고, K보다 작거나 같은 수가 N개 주어진다. 이 수는 각 학생이 제일 처음 시청하는 동영상 번호이다.

셋째 줄에는 1보다 크거나 같고, K보다 작거나 같은 수 K개가 주어진다. 이 숫자는 각 동영상의 추천 동영상 중, 가장 위에 있는 동영상의 번호이다.

출력
첫째 줄에 각 학생이 M분에 시청하는 동영상 번호를 공백으로 구분해서 출력한다.

풀이:
17435_합성함수와 쿼리 문제와 똑같은 문제입니다.

이동거리가 커졌기 때문에 희소 테이블의 개수만 늘려주면 됩니다.
M - 1 이 이동거리인 것에 주의합니다.
*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<string.h>
#include<vector>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>

int N, K, M;
int start[100001];
int jump[100001][31];

int main(void) {
	FIO;

	cin >> N >> K >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> start[i];
	}

	for (int i = 1; i <= K; i++)
	{
		cin >> jump[i][0];
	}

	for (int i = 1; i < 31; i++)
	{
		for (int j = 1; j <= K; j++)
		{
			jump[j][i] = jump[jump[j][i - 1]][i - 1];
		}
	}

	for (int i = 0; i < N; i++)
	{
		int s = start[i];
		int move = M - 1;

		for (int j = 30; j >= 0; j--)
		{
			if (move >= 1 << j) {
				move -= 1 << j;
				s = jump[s][j];
			}
		}
		cout << s << " ";
	}
}