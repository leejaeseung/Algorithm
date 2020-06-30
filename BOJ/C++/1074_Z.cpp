/*
문제
한수는 2차원 배열 (항상 2^N * 2^N 크기이다)을 Z모양으로 탐색하려고 한다. 예를 들어, 2*2배열을 왼쪽 위칸, 오른쪽 위칸, 왼쪽 아래칸, 오른쪽 아래칸 순서대로 방문하면 Z모양이다.



만약, 2차원 배열의 크기가 2^N * 2^N라서 왼쪽 위에 있는 칸이 하나가 아니라면, 배열을 4등분 한 후에 (크기가 같은 2^(N-1)로) 재귀적으로 순서대로 방문한다.

다음 예는 2^2 * 2^2 크기의 배열을 방문한 순서이다.



N이 주어졌을 때, (r, c)를 몇 번째로 방문하는지 출력하는 프로그램을 작성하시오.

다음 그림은 N=3일 때의 예이다.



입력
첫째 줄에 N r c가 주어진다. N은 15보다 작거나 같은 자연수이고, r과 c는 0보다 크거나 같고, 2^N-1보다 작거나 같은 정수이다

출력
첫째 줄에 문제의 정답을 출력한다.

풀이:
처음엔 각 영역에 대해 size가 2인 경우에 Z 자로 탐색을 매번 해주었는데, 통과는 했지만 시간이 매우 많이 걸렸습니다.

영역을 탐색하기 전에, 해당 영역에 r,c 가 존재하지 않는다면(범위로 체크) 해당 영역 크기만큼 카운트값을 늘려주기만 하면 됩니다.
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
int mv1[4] = { 0, 0, 1, 1 };
int mv2[4] = { 0, 1, 0, 1 };

int n, r, c, N;
int cnt = 0;

void traverse(int x, int y, int size) {

	if (!(x <= r && r < x + size && y <= c && c < y + size)) {
		cnt += size * size;
		return;
	}

	if (size == 2) {
		for (int i = 0; i < 4; i++)
		{
			int now_x = x + mv1[i];
			int now_y = y + mv2[i];

			if (now_x == r && now_y == c) {
				cout << cnt;
				exit(0);
			}
			cnt++;
		}
	}
	else{
		int mid = size / 2;

		traverse(x, y, size / 2);
		traverse(x, y + mid, size / 2);
		traverse(x + mid, y, size / 2);
		traverse(x + mid, y + mid, size / 2);
	}
}

int main(void) {
	FIO;

	cin >> n >> r >> c;

	N = pow(2, n);

	traverse(0, 0, N);
}