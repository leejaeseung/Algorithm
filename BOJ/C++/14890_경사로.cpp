/*
문제
크기가 N×N인 지도가 있다. 지도의 각 칸에는 그 곳의 높이가 적혀져 있다.

오늘은 이 지도에서 지나갈 수 있는 길이 몇 개 있는지 알아보려고 한다. 길이란 한 행 또는 한 열 전부를 나타내며, 한쪽 끝에서 다른쪽 끝까지 지나가는 것이다.

다음과 같은 N=6인 경우 지도를 살펴보자.



이때, 길은 총 2N개가 있으며, 아래와 같다.



길을 지나갈 수 있으려면 길에 속한 모든 칸의 높이가 모두 같아야 한다. 또는, 경사로를 놓아서 지나갈 수 있는 길을 만들 수 있다. 경사로는 높이가 항상 1이며, 길이는 L이다. 또, 개수는 매우 많아 부족할 일이 없다. 경사로는 낮은 칸과 높은 칸을 연결하며, 아래와 같은 조건을 만족해야한다.

경사로는 낮은 칸에 놓으며, L개의 연속된 칸에 경사로의 바닥이 모두 접해야 한다.
낮은 칸과 높은 칸의 높이 차이는 1이어야 한다.
경사로를 놓을 낮은 칸의 높이는 모두 같아야 하고, L개의 칸이 연속되어 있어야 한다.
아래와 같은 경우에는 경사로를 놓을 수 없다.

경사로를 놓은 곳에 또 경사로를 놓는 경우
낮은 칸과 높은 칸의 높이 차이가 1이 아닌 경우
낮은 지점의 칸의 높이가 모두 같지 않거나, L개가 연속되지 않은 경우
경사로를 놓다가 범위를 벗어나는 경우
L = 2인 경우에 경사로를 놓을 수 있는 경우를 그림으로 나타내면 아래와 같다.



경사로를 놓을 수 없는 경우는 아래와 같다.



위의 그림의 가장 왼쪽부터 1번, 2번, 3번, 4번 예제라고 했을 때, 1번은 높이 차이가 1이 아니라서, 2번은 경사로를 바닥과 접하게 놓지 않아서, 3번은 겹쳐서 놓아서, 4번은 기울이게 놓아서 불가능한 경우이다.

가장 위에 주어진 그림 예의 경우에 지나갈 수 있는 길은 초록색으로, 지나갈 수 없는 길은 빨간색으로 표시되어 있으며, 아래와 같다. 경사로의 길이 L = 2이다.



지도가 주어졌을 때, 지나갈 수 있는 길의 개수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N (2 ≤ N ≤ 100)과 L (1 ≤ L ≤ N)이 주어진다. 둘째 줄부터 N개의 줄에 지도가 주어진다. 각 칸의 높이는 10보다 작거나 같은 자연수이다.

출력
첫째 줄에 지나갈 수 있는 길의 개수를 출력한다.

풀이:
길 하나를 vector로 받아 해당 길을 갈 수 있는지 모든 경우를 체크해 주는 함수를 만든다.
12가지의 길에 대해 체크해주면 된다.
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
int mv1[4] = { 0, 0, 1, -1 };
int mv2[4] = { 1, -1, 0, 0 };
int mv_all1[8] = { 0, 1, 0, -1, -1, -1, 1, 1 };
int mv_all2[8] = { 1, 0, -1, 0 , -1, 1, -1, 1 };

int N, L;
int maps[101][101];

bool checkRoad(vector<int> road) {
	int prevH = road[0];
	bool check[101];

	for (int i = 0; i < N; i++)
	{
		check[i] = false;
	}

	for (int i = 1; i < road.size(); i++)
	{
		int nowH = road[i];

		if (abs(nowH - prevH) > 1)	return false;
		//차이가 2이상이면 false

		if (nowH > prevH) {
			
			for (int j = 0; j < L; j++)
				//뒤 칸들에 대해 경사로를 놓을 수 있는지 조사
			{
				int check_idx = i - j - 1;
				if (check_idx < 0)	return false;
				if (check[check_idx])	return false;
				if (road[check_idx] != prevH)	return false;
				check[check_idx] = true;
			}

		}
		else if (nowH < prevH) {
			for (int j = 0; j < L; j++)
				//앞 칸들에 대해 경사로를 놓을 수 있는지 조사
			{
				int check_idx = i + j;
				if (check_idx >= N)	return false;
				if (road[check_idx] != nowH)	return false;
				check[check_idx] = true;
			}
		}
		prevH = nowH;
	}
	return true;
}

int main(void) {
	FIO;

	cin >> N >> L;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> maps[i][j];
		}
	}

	int ans = 0;

	for (int i = 0; i < N; i++)
	{
		vector<int> vt;

		for (int j = 0; j < N; j++)
		{
			vt.push_back(maps[i][j]);
		}

		if (checkRoad(vt))
			ans++;
	}

	for (int i = 0; i < N; i++)
	{
		vector<int> vt;

		for (int j = 0; j < N; j++)
		{
			vt.push_back(maps[j][i]);
		}

		if (checkRoad(vt))
			ans++;
	}

	cout << ans;
}