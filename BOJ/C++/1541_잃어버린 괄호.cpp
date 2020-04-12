/*
문제
세준이는 양수와 +, -, 그리고 괄호를 가지고 길이가 최대 50인 식을 만들었다. 그리고 나서 세준이는 괄호를 모두 지웠다.

그리고 나서 세준이는 괄호를 적절히 쳐서 이 식의 값을 최소로 만들려고 한다.

괄호를 적절히 쳐서 이 식의 값을 최소로 만드는 프로그램을 작성하시오.

입력
첫째 줄에 식이 주어진다. 식은 ‘0’~‘9’, ‘+’, 그리고 ‘-’만으로 이루어져 있고, 가장 처음과 마지막 문자는 숫자이다. 그리고 연속해서 두 개 이상의 연산자가 나타나지 않고, 5자리보다 많이 연속되는 숫자는 없다. 수는 0으로 시작할 수 있다.

출력
첫째 줄에 정답을 출력한다.

풀이:
- 를 만나기 전까진 수를 더하다가 - 를 한 번이라도 만나면 그 이후의 값들은 모두 빼줍니다.
*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<string>
#include<vector>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>

int p = 0;
string str;

int getNum() {

	int ret = str[p++] - '0';
	int mul = 10;
	while (str[p] >= '0' && str[p] <= '9') {
		ret = ret * mul + (str[p] - '0');
		p++;
	}
	return ret;
}

int main(void) {
	FIO;

	cin >> str;

	int sum = 0;
	int minus = 1;

	while (true) {
		sum += getNum() * minus;

		if (p >= str.size())	break;
		if (str[p] == '-' && minus == 1) {
			minus = -1;
		}
		p++;
	}
	cout << sum;
}