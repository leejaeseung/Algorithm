/*
	풀이 : 팀원이 N/2가 되는 경우마다 최소값을 구한다.
	모든 경우의 수를 재귀로 탐색한다.
*/
#include<iostream>
#include<cstdlib>
using namespace std;

int map[20][20];
bool team[20];
int N;
int MIN = INT32_MAX;

int cal_man(int i, int j) {
	return map[i][j] + map[j][i];
}
void cal_team() {
	int start = 0, link = 0, res = 0;
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (team[i] == team[j]) {
				if (team[i]) {
					start += cal_man(i, j);
				}
				else {
					link += cal_man(i, j);
				}
			}
		}
	}
	if (MIN > (res = abs(start - link))) {
		MIN = res;
	}
}

void BF(int teamsize,int now) {
	team[now] = true;
	if (teamsize == N / 2) {
		cal_team();
		team[now] = false;
		teamsize--;
	}
		for (int i = 1; i < N; i++)
		{
			if (now + i < N) {
					BF(teamsize + 1, now + i);
			}
		}
		team[now] = false;
}


int main(void) {
	ios_base::sync_with_stdio;
	cin.tie(NULL);
	
	
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++) {
			int n;
			cin >> n;
			map[i][j] = n;
		}
	}
	BF(1, 0);
	cout << MIN << endl;
}