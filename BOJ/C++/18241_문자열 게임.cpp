/*
문제
문자열 게임이 있다. 게임의 진행 방식은 아래와 같다.

알파벳 소문자로 이루어진 문자열 W가 주어진다.
알파벳 소문자로 이루어진 문자열 S가 주어진다.
문자열 S에서 문자열 W를 모두 제거하는 사람이 승리한다.
병서는 문자열 W를 모두 제거하기 위해 프로그램을 만들려고 한다.

병서가 구상한 프로그램은 아래의 명령 중 주어진 명령을 수행하는 작업을 N번 반복한다.

L : 문자열 S의 왼쪽에서부터 처음으로 등장하는 문자열 W를 찾아, S에서 해당 부분문자열을 제거한다.
R : 문자열 S의 오른쪽에서부터 처음으로 등장하는 문자열 W를 찾아, S에서 해당 부분문자열을 제거한다.
명령을 수행할 때, 제거해야 하는 문자열 W가 없다면 명령을 실패하고, 아무 일도 일어나지 않는다.

병서를 위해 N개의 명령에 따라 문자열 S에서 문자열 W를 제거하는 프로그램을 제작해주자!

입력
첫 번째 줄과 두 번째 줄에 길이가 1 이상인 문자열 W와 문자열 S가 각각 주어진다. W와 S는 알파벳 소문자로 이루어져 있다.

W는 최대 10자, S는 최대 300,000자이다.

세 번째 줄에 명령의 개수 N이 주어진다. (1 ≤ N ≤ 30,000)

네 번째 줄부터 N개의 줄에 명령이 주어진다.

출력
첫 번째 줄에 성공한 명령의 개수를, 두 번째 줄에 프로그램을 실행한 후의 문자열 S를 출력한다.

프로그램 실행 후에 문자열이 비어있는 경우는 존재하지 않는다.

세 번째 줄에 프로그램을 실행한 후의 문자열 S에 문자열 W가 남아있으면 You Lose!를, 문자열 W를 모두 제거했으면 Perfect!를 출력한다.

풀이:
https://hellogaon.tistory.com/75
위 블로그를 참고하여 풀이했습니다. 구현이 까다로운 문제였습니다.

왼쪽 덱(DL), 오른쪽 덱(DR)을 각각 만들어 그리디(?)하게
L연산 시에는 왼쪽부터 가장 처음 나오는 W문자열을 지워주고,
R연산 시에는 오른쪽부터 가장 처음 나오는 W문자열을 지워줍니다.
(왼쪽, 오른쪽부터 두 개의 포인터를 두어 두 포인터가 겹칠 때까지 진행합니다.)

두 포인터가 겹친다면, DL 엔 왼쪽의 문자열들, DR 엔 오른쪽의 문자열들이 모두 있기 때문에
DL의 오른쪽, DR의 왼쪽을 합쳤을 때 W문자열이 존재할 수 있습니다.

DL의 오른쪽을 pop -> DR의 왼쪽에 push 해가며 W문자열을 만들 수 있는지 조사하면 됩니다.

Perfect 인지 You Lose 인지 여부는 n개의 L, R 연산 뒤에 임의의 연산 L 을 추가하여 해결했습니다.
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
#define IMAX 2100000001
#define LMAX 1000000000000000000
#define DMAX 0xFFFFFFFFFFFFF
int mv1[4] = { 0, 1, 0, -1 };
int mv2[4] = { -1, 0, 1, 0 };

deque<char> DL;
deque<char> DR;
string W, S;
int n;

int main(void) {
	FIO;

	cin >> W >> S;

	cin >> n;
	
	int l_idx = 0;
	int r_idx = S.size() - 1;

	int cnt = 0;
	int temp_cnt = 0;
	string ans = "";

	for (int i = 0; i < n + 1; i++)
	{
		char q;
		if (i != n)
			cin >> q;
		else {
			temp_cnt = cnt;
			//수행한 연산의 갯수 저장

			for (int i = 0; i < DL.size(); i++)
			{
				ans += DL[i];
			}

			for (int i = l_idx; i <= r_idx; i++)
			{
				ans += S[i];
			}

			for (int i = 0; i < DR.size(); i++)
			{
				ans += DR[i];
			}

			q = 'L';
			//마지막 문자열에 W가 존재하는지 판단하기 위해 임의의 L 연산 추가
		}

		if (l_idx <= r_idx) {
			//겹치지 않는다면
			if (q == 'L') {

				bool find = false;

				while (!find) {
					DL.push_back(S[l_idx++]);

					if (DL.size() < W.size() && l_idx < r_idx)	continue;

					int W_idx = 0;
					bool match = true;

					if (DL.size() < W.size())
						match = false;

					for (int i = DL.size() - W.size(); i < DL.size(); i++)
					{
						if ( DL[i] != W[W_idx++]) {
							match = false;
							break;
						}
					}

					if (match) {
						cnt++;
						find = true;

						for (int i = 0; i < W.size(); i++)
						{
							DL.pop_back();
						}
					}

					if (l_idx > r_idx)	break;
				}

			}
			else {
				bool find = false;

				while (!find) {
					DR.push_front(S[r_idx--]);

					if (DR.size() < W.size() && l_idx < r_idx)	continue;

					bool match = true;

					if (DR.size() < W.size())
						match = false;

					for (int i = 0; i < W.size(); i++)
					{
						if (DR[i] != W[i]) {
							match = false;
							break;
						}
					}

					if (match) {
						cnt++;
						find = true;

						for (int i = 0; i < W.size(); i++)
						{
							DR.pop_front();
						}
					}
					if (l_idx > r_idx)	break;
				}
			}
		}

		if (l_idx > r_idx) {
			//두 포인터가 겹쳤을 경우

			while (!DL.empty()) {
				DR.push_front(DL.back());	DL.pop_back();

				bool match = true;

				if (DR.size() >= W.size()) {
					for (int i = 0; i < W.size(); i++)
					{
						if (DR[i] != W[i]) {
							match = false;
							break;
						}
					}
					if (!match)	continue;


					for (int i = 0; i < W.size(); i++)
					{
						DR.pop_front();
					}

					cnt++;
					break;
				}
			}
		}
	}

	cout << temp_cnt << "\n";

	cout << ans << "\n";

	if (cnt == temp_cnt)		//마지막 연산으로 cnt 값이 증가하면 실패
		cout << "Perfect!";
	else
		cout << "You Lose!";
}