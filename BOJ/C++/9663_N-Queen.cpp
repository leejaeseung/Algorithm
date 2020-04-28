/*
����
N-Queen ������ ũ�Ⱑ N �� N�� ü���� ���� �� N���� ���� ������ �� ���� ���� �����̴�.

N�� �־����� ��, ���� ���� ����� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� N�� �־�����. (1 �� N < 15)

���
ù° �ٿ� �� N���� ���� ������ �� ���� ���� ����� ���� ����Ѵ�.

*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<vector>
#include<stack>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>

int N;
int cnt = 0;
bool rowCheck[17];
bool colCheck[17];
bool LRCheck[31];
bool RLCheck[31];

void check(int i, int j, bool ch) {
	rowCheck[i] = ch;
	colCheck[j] = ch;
	LRCheck[(N - 1) - (i - j)] = ch;
	RLCheck[i + j] = ch;
}

void recul(int i, int Q) {

	if (Q == N) {
		cnt++;
		return;
	}
	int a = i;

		for (int b = 0; b < N; b++)
		{
			if (colCheck[b])	continue;
			if (!rowCheck[a] && !colCheck[b] && !LRCheck[(N - 1) - (a - b)] && !RLCheck[a + b]) {
				check(a, b, true);
			
				recul(a + 1, Q + 1);
				
				check(a, b, false);
			}
		}
}

int main(void) {
	FIO;

	cin >> N;

	recul(0, 0);

	cout << cnt;
}