/*
문제
함수 f : {1, 2, ..., m}→{1, 2, ..., m}이 있다. 이때 fn : {1, 2, ..., m}→{1, 2, ..., m}을 다음과 같이 정의하자.

f1(x) = f(x)
fn+1(x) = f(fn(x))
예를 들어 f4(1) = f(f(f(f(1))))이다.

n과 x가 주어질 때 fn(x)를 계산하는 쿼리를 수행하는 프로그램을 작성하시오.

입력
첫 줄에 정수 m이 주어진다. (1 ≤ m ≤ 200,000)

다음 줄에 f(1), f(2), ..., f(m)이 차례대로 주어진다.

다음 줄에 쿼리의 개수 Q가 주어진다. (1 ≤ Q ≤ 200,000)

다음 Q개의 줄에 각각 정수 n과 x가 주어진다. (1 ≤ n ≤ 500,000; 1 ≤ x ≤ m)

출력
주어지는 n, x마다 fn(x)를 출력한다.

풀이:
희소 테이블을 이용한 문제였습니다.

https://blog.naver.com/PostView.nhn?blogId=kks227&logNo=220793361738
위 블로그를 참고했습니다.
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

int N, Q;
int jump[200001][19];


int main(void) {
	FIO;

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> jump[i][0];
	}

	for (int i = 1; i < 19; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			jump[j][i] = jump[jump[j][i - 1]][i - 1];
		}
	}

	cin >> Q;

	while (Q--) {
		int n, x;

		cin >> n >> x;

		int start = 1;

		for (int i = 18; i >= 0; i--)
		{
			if (n >= (1 << i)) {
				n -= (1 << i);
				x = jump[x][i];
			}
		}
		cout << x << "\n";
	}
}