/*
문제
Brainf**k 프로그램이 주어졌을 때, 이 프로그램이 끝나는지, 무한 루프에 빠지는지 알아내는 프로그램을 작성하시오.

Brainf**k 인터프리터는 정수를 담는 하나의 배열(unsigned 8-bit 정수)과, 그 배열의 칸 하나를 가리키는 포인터로 이루어져 있다. Brainf**k 프로그램은 다음과 같이 8개의 명령어로 이루어져 있다.

-	포인터가 가리키는 수를 1 감소시킨다. (modulo 28)
+	포인터가 가리키는 수를 1 증가시킨다. (modulo 28)
<	포인터를 왼쪽으로 움직인다.(1 감소)
>	포인터를 오른쪽으로 움직인다.(1 증가)
[	만약 포인터가 가리키는 수가 0과 같다면, [와 짝을 이루는 ]로 점프한다.
]	만약 포인터가 가리키는 수가 0이 아니라면, ]와 짝을 이루는 [로 점프한다.
.	포인터가 가리키는 수를 출력한다.
,	문자 하나를 읽고 포인터가 가리키는 곳에 저장한다. 입력의 마지막(EOF)인 경우에는 255를 저장한다.
인터프리터는 Brainf**k 프로그램의 첫 번째 명령부터 수행하고, 더이상 수행할 명령이 없다면, 프로그램을 종료한다. 각 명령을 수행하고 나면, 다음 명령을 수행한다. 물론 [이나 ]인 경우에는 다음 명령으로 이동하는 것이 아니라 점프를 한다.

데이터 배열의 크기는 문제에서 주어지는 값을 사용해야 한다. 또, 데이터 배열의 값이 underflow나 overflow를 일으켰을 때는 일반적인 방법을 따르면 된다. 프로그램을 수행하기 전에, 데이터 배열의 값은 0으로 초기화되어 있고, 포인터가 가리키는 칸은 0번 칸이다.

포인터를 왼쪽이나 오른쪽으로 움직일 때, 데이터 배열의 범위를 넘어간다면, 반대쪽으로 넘어가게 된다. 즉, 포인터가 0을 가리킬 때, 1을 감소시킨다면, 배열의 크기 - 1번째를 가리키게 된다.

[와 ]는 루프를 의미하며, 중첩될 수 있다. 입력으로 주어진 프로그램은 잘 짜여 있음이 보장된다. 즉 프로그램을 왼쪽에서 오른쪽으로 훑으면서 [의 개수에서 ]의 개수를 빼면 항상 0보다 크거나 같고, 맨 끝까지 훑으면 그 값은 0이 된다.

이 문제는 Brainf**k 프로그램이 무한 루프에 빠지는지 안 빠지는지를 검사하기만 하면 된다. 따라서, 출력은 무시한다.

입력
첫째 줄에 테스트 케이스의 개수 t (0 < t ≤ 20)가 주어진다. 각 테스트 케이스는 세 줄로 이루어져 있다. 첫째 줄에는 sm, sc, si가 주어진다. sm은 메모리(배열)의 크기이고, sc는 프로그램 코드의 크기, si는 입력의 크기이다. (0 < sm ≤ 100,000, 0 < sc, si < 4096)

둘째 줄에는 Brainf**k 프로그램이 주어진다. 프로그램은 sc개의 문자로 이루어져 있다.

셋째 줄에는 프로그램의 입력이 주어진다. (공백이 아니면서 출력할 수 있는 문자만 주어진다)

출력
각 테스트 케이스에 대해서, 프로그램이 종료된다면 "Terminates"를, 무한 루프에 빠지게 된다면 "Loops"를 출력한다. 무한 루프에 빠졌을 때는, 프로그램의 어느 부분이 무한 루프인지를 출력한다. ([와 ]의 위치) 프로그램이 명령어를 50,000,000번 이상 수행한 경우, 프로그램은 항상 종료되었거나 무한 루프에 빠져있다. 무한 루프일 경우, 해당 루프는 적어도 한 번 실행이 완료된 상태이며, 한 번의 무한 루프에서 실행되는 명령어의 개수는 50,000,000개 이하이다.

풀이:
스택과 배열을 이용한 단순 구현 문제였다.

주어지는 메모리배열과 명령어, 문자의 길이가 크지 않으므로 해당 길이만큼 선언하고,
명령어에 따라 적절히 조건문을 걸어준다.

무한루프를 찾아야 하므로 가장 중요한 명령어는 '[' 와 ']' 인데, 명령들을 수행하기 전에 미리 
'[' -> ']' , ']' -> '[' 처럼 인덱스를 찾아갈 수 있도록 스택을 이용해 전처리를 해주자.

'[' 을 만나면 스택에 넣고, ']' 을 만나면 스택에서 뺀 '[' 와 link를 연결해 주면 간단히 해결된다.

이제 남은 건 무한루프의 판별인데 ']' 명령을 잘 생각해보면 ']' 를 만났을 때 현재 포인터가 가르키는 수가 
단 한번이라도 0 이라면 그 ']' 는 무한루프가 아니란 걸 알 수 있다.(다른 곳에서 무한루프를 돌고 있거나 무한루프가 없다.)

따라서 모든 ']' 중에 단 한번도 현재 수가 0 이 나온적이 없던 ']' 와 그 짝 '[' 이 무한루프이다.
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

int main(void) {
	FIO;

	int t;
	cin >> t;

	while (t--) {
		int sm, sc, si;

		cin >> sm >> sc >> si;

		int* arr = (int*)malloc(sizeof(int) * sm);
		memset(arr, 0, sizeof(unsigned int) * sm);

		int* link = (int*)malloc(sizeof(int) * sc);
		memset(link, 0, sizeof(int) * sc);

		bool* isLoop = (bool*)malloc(sizeof(bool) * sc);
		memset(isLoop, false, sizeof(bool) * sc);

		string order, input;
		cin >> order >> input;

		stack<int> st;

		for (int i = 0; i < sc; i++)
		{
			//'[' 와 ']' 이어주기
			char o = order[i];

			if (o == '[') {
				st.push(i);
			}
			else if (o == ']') {
				int idx = st.top();	st.pop();

				link[i] = idx;
				link[idx] = i;
			}
		}

		int cnt = 0;
		int arr_ptr = 0;
		int order_ptr = 0;
		int input_ptr = 0;

		int cur = 0;

		while(++cnt < 50000000 && order_ptr < sc)
		{
			char o = order[order_ptr++];
			cur = arr[arr_ptr];		//메모리 배열의 현재 수

			switch (o)
			{
			case '+':
				arr[arr_ptr] = (arr[arr_ptr] + 1) % 256;
				break;
			case '-':
				arr[arr_ptr]--;
				if (arr[arr_ptr] < 0)
					arr[arr_ptr] = 255;
				break;
			case '>':
				arr_ptr = (arr_ptr + 1) % sm;
				break;
			case '<':
				arr_ptr--;
				if (arr_ptr < 0)
					arr_ptr = sm - 1;
				break;
			case '[':
				if (arr[arr_ptr] == 0)
					order_ptr = link[order_ptr - 1];
				break;
			case ']':
				if (cur == 0)		
					//단 한번이라도 현재 수가 0 이 나왔었다면 무한루프x
					isLoop[order_ptr - 1] = true;
				if (arr[arr_ptr] != 0)
					order_ptr = link[order_ptr - 1];
				break;
			case '.':
				break;
			case ',':
				if (input_ptr == (int)input.size())
					arr[arr_ptr] = 255;
				else
					arr[arr_ptr] = (int)input[input_ptr++];
				break;
			}
		}

		if (order_ptr >= sc) {
			cout << "Terminates\n";
		}
		else {
			int left, right;

			for (int i = 0; i < sc; i++)
			{
				if (order[i] == ']' && !isLoop[i]) {
					left = link[i];
					right = i;
					break;
				}
			}

			cout << "Loops " << left << " " << right << "\n";
		}

		free(arr);
		free(link);
		free(isLoop);
	}
}