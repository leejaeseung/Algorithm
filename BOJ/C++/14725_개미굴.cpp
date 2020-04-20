/*
문제
개미는(뚠뚠) 오늘도(뚠뚠) 열심히(뚠뚠)  일을 하네.

개미는 아무말도 하지 않지만 땀을 뻘뻘 흘리면서 매일 매일을 살길 위해서 열심히 일을 하네.

한 치 앞도(뚠뚠) 모르는(뚠뚠) 험한 이 세상(뚠뚠) 그렇지만(뚠뚠) 오늘도 행복한 개미들!

우리의 천재 공학자 윤수는 이 개미들이 왜 행복한지 궁금해졌다.

행복의 비결이 개미가 사는 개미굴에 있다고 생각한 윤수는 개미굴의 구조를 알아보기 위해 로봇 개미를 만들었다.

로봇 개미는 센서가 있어 개미굴의 각 층에 먹이가 있는 방을 따라 내려가다 더 이상 내려갈 수 없으면 그 자리에서 움직이지 않고 신호를 보낸다.

이 신호로 로봇 개미는 개미굴 각 층을 따라 내려오면서 알게 된 각 방에 저장된 먹이 정보를 윤수한테 알려줄 수 있다.



로봇 개미 개발을 완료한 윤수는 개미굴 탐사를 앞두고 로봇 개미를 테스트 해보기 위해 위 그림의 개미굴에 로봇 개미를 투입했다. (로봇 개미의 수는 각 개미굴의 저장소를 모두 확인할 수 있을 만큼 넣는다.)

다음은 로봇 개미들이 윤수에게 보내준 정보다.

KIWI BANANA
KIWI APPLE
APPLE APPLE
APPLE BANANA KIWI
(공백을 기준으로 왼쪽부터 순서대로 로봇 개미가 각 층마다 지나온 방에 있는 먹이 이름을 뜻한다.)

윤수는 로봇 개미들이 보내준 정보를 바탕으로 다음과 같이 개미굴의 구조를 손으로 그려봤다.

APPLE
--APPLE
--BANANA
----KIWI
KIWI
--APPLE
--BANANA
(개미굴의 각 층은 "--" 로 구분을 하였다.

또 같은 층에 여러 개의 방이 있을 때에는 사전 순서가 앞서는 먹이 정보가 먼저 나온다.)

우리의 천재 공학자 윤수는 복잡한 개미굴들을 일일이 손으로 그리기 힘들어 우리에게 그려달라고 부탁했다.

한치 앞도 모르는 험한 이세상 그렇지만 오늘도 행복한 개미들!

행복의 비결을 알기 위해 윤수를 도와 개미굴이 어떤 구조인지 확인해보자.

입력
첫 번째 줄은 로봇 개미가 각 층을 따라 내려오면서 알게 된 먹이의 정보 개수 N개가 주어진다.  (1 ≤ N ≤ 1000)

두 번째 줄부터 N+1 번째 줄까지, 각 줄의 시작은 로봇 개미 한마리가 보내준 먹이 정보 개수 K가 주어진다. (1 ≤ K ≤ 15)

다음 K개의 입력은 로봇 개미가 왼쪽부터 순서대로 각 층마다 지나온 방에 있는 먹이 정보이며 먹이 이름 길이 t는 (1 ≤ t ≤ 15) 이다.

출력
개미굴의 시각화된 구조를 출력하여라.

개미굴의 각 층을 "--" 로 구분하며, 같은 층에 여러개의 방이 있을 때에는 사전 순서가 앞서는 먹이 정보가 먼저 나온다.

풀이:
각 정보들을 사전 순서대로 정렬합니다.

정렬된 각 정보들을 공백마다 끊어가며 탐색합니다.
현재까지 탐색된 문자열을 map을 이용해 방문을 체크하고

만약 방문한 곳이면 "--"을 depth에 추가만 하고 더 탐색합니다.
만약 방문하지 않았다면 현재 depth + (현재 층의 문자열) 을 출력 문자열에 추가합니다. 
그리고 출력 문자열에 개행 문자를 추가하고, depth 에 "--"을 추가해 층을 늘려줍니다.

모든 문자열에 대해 위 작업을 수행합니다.
*/

#include<iostream>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<string>
#include<vector>
#include<queue>
#include<map>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>

int N;
priority_queue<string, vector<string>, greater<string>> pq;
map<string, bool> hm;

int main(void) {
	FIO;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;

		string all = "";

		for (int j = 0; j < x; j++)
		{
			string str;
			cin >> str;

			all += str + ' ';
		}
		pq.push(all);
	}
	while (!pq.empty())
	{
		string str = pq.top();	pq.pop();
		string out = "";
		string depth = "";

		int s = 0;
		for (int i = 0; i < str.size(); i++)
		{

			if (str[i] == ' ') {
				string sub = str.substr(s, i - s);
				s = i + 1;

				if (hm.find(str.substr(0, i)) != hm.end()) {
					depth += "--";
					continue;
				}
				else {
					hm.insert(make_pair(str.substr(0, i), true));
					out += depth + sub;
				}
				
			}
			else {
				continue;
			}
			out += "\n";
			depth += "--";
		}
		cout << out;
	}
	
}