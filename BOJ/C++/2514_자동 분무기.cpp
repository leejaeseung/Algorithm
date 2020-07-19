/*
문제
어떤 농장은 다음 그림과 같이 가로 세로 8*8의 단위 구역으로 나누어져 있다. 이 농장에는 많은 곡식을 생산하기 위하여 비료액 또는 제초제를 뿌리는 자동분무기가 단위 구역에 설치되어 있다. 이 자동분무기는 놓인 위치에서 상하좌우 4방향으로 액체를 뿌린다. 예를 들어 X 구역에 자동분무기가 놓여있다면 그 장치로 부터 액체가 뿌려지는 단위 구역은 {X,a, b,c,d,e,f,g,h,i,j,k,l,m,n}이다. 만일 Y 구역에 자동분무기가 놓여있다면 액체가 뿌려지는 단위 구역은 {Y,A,B,c,C,D,E,F,G,H, I,J,k,K,L}이다.



자동분무기를 설치하지 않았을 때에는 각 단위 구역의 생산량은 모두 정확하게 같고, 이를 기본 생산량이라고 하자. 자동분무기를 설치한 후, 비료액이 뿌려진 단위 구역은 생산량이 1씩 증가하고, 제초제가 뿌려진 단위 구역은 잡초와 해충은 제거되지만 생산량이 1씩 감소한다. 기본 생산량이 30이라고 하자. X 구역에 비료액 자동분무기를, 그리고 Y 구역에 제초제 자동분무기를 설치하면 최종 생산량은 다음과 같다.



단, 한 단위 구역에 배치될 수 있는 자동분무기는 최대 1대이다. 따라서 한 단위 구역에 제초제 자동분무기와 비료액 자동분무기가 동시에 배치되거나 같은 종류의 자동분무기가 2대 이상 설치될 수 없다.

기본 생산량이 M인  농장의 최종 생산량 자료가 주어졌을 때, 자동분무기가 놓인 위치와 종류를 찾아내는 프로그램을 작성하시오.

입력
첫 줄에는 기본 생산량 M (30<=M<=40)이 주어진다. 두 번째 줄에는 이 농장에 놓인 자동분무기의 개수 K (1<=K<=63)가 주어진다. 그 다음에는 전체 8*8 농장의 최종 생산량이 위에서 아래로 한 줄씩 총 8줄에 걸쳐서 주어진다. 같은 줄에 있는 8개의 단위 구역의 생산량은 빈칸을 사이에 두고 구분된다. 모든 값은 양의 정수이다.

출력
파일의 각 줄에는 입력에서 읽은 순서대로, 각 단위 구역마다 자동분무기의 유무와 종류 정보를 총 8줄에 출력한다. 비료액 자동분무기가 놓인 단위 구역은 ‘+’ 기호로, 제초제 자동분무기가 놓인 단위 구역은 ‘-’(마이너스) 기호로,  자동분무기가 없는 단위 구역은 ‘.’ 기호로 표현한다. 같은 줄에 있는 단위 구역 정보는 하나의 빈칸을 사이에 두고 출력한다.

풀이:
분무기의 종류를 판단하는 부분은 아래 블로그를 참고했습니다.
https://milkclouds.github.io/2019/02/10/BOJ-2514-%EC%9E%90%EB%8F%99%EB%B6%84%EB%AC%B4%EA%B8%B0/

p(i, j) 칸에 만약 분무기가 존재한다면, p(i, j)의 가로, 세로 총 15칸을 더한 값이 짝수라면 m이 홀수여야 하고,
홀수라면 m이 짝수여야 합니다.

왜냐하면 해당 칸이 분무기라면 자신을 포함해 15칸에 15를 더하거나 빼게 되는데, 첫 값인 m의 짝수, 홀수 여부에 따라 
15를 더하거나 뺀 값도 짝수, 홀수 여부가 정해지기 때문입니다.(짝수 + 홀수(15) = 홀수, 홀수 + 홀수(15) = 짝수)

이제 분무기의 모든 위치를 구했기 때문에 분무기의 종류를 구분하면 됩니다.(위 블로그 참고)
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

int m, k;
int maps[8][8];
int map_sum[8][8];
int allB[8][8];
int allB_sum[8][8];

int main(void) {
	FIO;

	cin >> m >> k;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			int v;
			cin >> v;

			maps[i][j] = v;
			allB[i][j] = m;
		}
	}

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			for (int l = 0; l < 8; l++)
			{
				if(l != j)
					map_sum[i][j] += maps[i][l];
				map_sum[i][j] += maps[l][j];
			}
		}
	}

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (map_sum[i][j] % 2 != m % 2) {
				for (int l = 0; l < 8; l++)
				{
					if (l != j)
						allB[i][l]++;
					allB[l][j]++;
				}
			}
		}
	}

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			for (int l = 0; l < 8; l++)
			{
				if (l != j)
					allB_sum[i][j] += allB[i][l];
				allB_sum[i][j] += allB[l][j];
			}
		}
	}

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (map_sum[i][j] % 2 != m % 2) {
				if ((allB_sum[i][j] - map_sum[i][j]) % 4 == 2)
					cout << "- ";
				else
					cout << "+ ";
				continue;
			}
			cout << ". ";
		}
		cout << "\n";
	}
}