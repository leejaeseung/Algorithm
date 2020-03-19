/*
문제
준석이는 영어 단어를 외우려고 한다. 사전에는 N가지 단어가 적혀 있다. 모든 단어는 소문자이다. 단어 안에 있는 모든 알파벳을 알 때, 그 단어를 완전히 안다고 한다.

다음과 같은 쿼리들이 주어진다.

1 x : 알파벳 x를 잊는다.
2 x : 알파벳 x를 기억해 낸다.
처음에 모든 알파벳을 기억하는 상태고, 모음은 완벽하게 외웠기 때문에 절대 잊지 않는다.

각 쿼리마다 완전히 알고 있는 단어의 개수를 출력하여라.

입력
첫 번째 줄에는 정수 N (1 ≤ N ≤ 104)과 M (1 ≤ M ≤ 5×104)이 주어진다.

다음 N개의 줄에는 문자열이 하나씩 주어진다. 문자열의 길이는 103을 넘지 않는다.

다음 M개의 줄에는 정수 o와 문자 x가 한 줄씩 주어진다. o는 1, 2중 하나이고, x는 알파벳 소문자이다.

o가 1이면 x를 잊는다는 뜻이고, o가 2면 x를 기억해낸다는 뜻이다. o가 1일 때는 x를 기억하고 있었음이 보장되고, o가 2일 때는 x를 잊고 있었음이 보장된다.

출력
각 쿼리마다 정수 하나를 출력한다.

풀이:
비트마스크를 이용한 문제였습니다.
알파벳을 알고 있다면 1, 잊었다면 0으로 나타냅니다.
알게 되면 | 연산, 잊는다면 ^ 연산으로 원래 알고있던 비트와 연산을 해주어 알고있는 비트를 업데이트합니다.
*/
#include<iostream>
#include<string>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pii pair<int, int>;

int N, M;
int bit[10000];

int main(void) {
	FIO;

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;

		for (int j = 0; j < str.size(); j++)
		{
			bit[i] = bit[i] | (1 << (str.at(j) - 'a'));
		}
	}
	int know = 67108863;

	for (int i = 0; i < M; i++)
	{
		int q;
		char x;
		int cnt = 0;
		
		cin >> q >> x;
		
		if (q == 1) {
			know = know ^ (1 << (x - 'a'));
			for (int j = 0; j < N; j++)
			{
				if ((know & bit[j]) == bit[j])
					cnt++;
			}
		}
		else {
			know = know | (1 << (x - 'a'));
			for (int j = 0; j < N; j++)
			{
				if ((know & bit[j]) == bit[j])
					cnt++;
			}
		}
		cout << cnt << "\n";
	}
}