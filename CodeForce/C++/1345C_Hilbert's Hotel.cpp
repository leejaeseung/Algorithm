/*
C. Hilbert's Hotel
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Hilbert's Hotel is a very unusual hotel since the number of rooms is infinite! In fact, there is exactly one room for every integer, including zero and negative integers. Even stranger, the hotel is currently at full capacity, meaning there is exactly one guest in every room. The hotel's manager, David Hilbert himself, decides he wants to shuffle the guests around because he thinks this will create a vacancy (a room without a guest).

For any integer k and positive integer n, let kmodn denote the remainder when k is divided by n. More formally, r=kmodn is the smallest non-negative integer such that k−r is divisible by n. It always holds that 0≤kmodn≤n−1. For example, 100mod12=4 and (−1337)mod3=1.

Then the shuffling works as follows. There is an array of n integers a0,a1,…,an−1. Then for each integer k, the guest in room k is moved to room number k+akmodn.

After this shuffling process, determine if there is still exactly one guest assigned to each room. That is, there are no vacancies or rooms with multiple guests.

Input
Each test consists of multiple test cases. The first line contains a single integer t (1≤t≤104) — the number of test cases. Next 2t lines contain descriptions of test cases.

The first line of each test case contains a single integer n (1≤n≤2⋅105) — the length of the array.

The second line of each test case contains n integers a0,a1,…,an−1 (−109≤ai≤109).

It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

Output
For each test case, output a single line containing "YES" if there is exactly one guest assigned to each room after the shuffling process, or "NO" otherwise. You can print each letter in any case (upper or lower).
문제 설명:
배열 a가 주어지고,
방 번호(임의의 정수) k에 대해 k -> k + a[k mod n] 으로 옮겨집니다.
즉 k 는 a[k mod n] 만큼 옮겨지게 됩니다.
이 때, 같은 방으로 옮겨진 사람이 있다면 NO 없다면 YES를 출력합니다.

풀이:
먼저 임의의 정수 k 에 대해 k mod n 은 0,1,2 ... n - 1 의 수로 좁혀집니다.
n = 4
a = [5,5,5,1]
위 예제에서, k mod n 의 값은 [0,1,2,3] 으로, 배열 a와 각각 (0,5),(1,5),(2,5),(3,1)에 대응합니다.

임의의 정수 k에 대해 k mod n = 0 일 때 k + 5 번째 방으로 이동되겠죠.
그리고, k mod n = 1 일 때 -> 즉 k + 1 은 다시 5를 더한 방인 k + 5 + 1 로 이동됩니다.
즉, k부터 시작한다고 하면, k + 5, k + 5 + 1, k + 5 + 2, k + 1 + 3 ... 이렇게 방을 이동하게 됩니다.

k + 1 + 3 다음엔 다시 a[0]으로 돌아가서 k + 5 + 4, k + 5 + 5 ... 이렇게 이어집니다.
즉, a[i] 값은 n번째마다 계속해서 반복되고 맨 마지막 숫자에 mod n을 하게 되면 역시 0,1,2,3 을 반복합니다.
어떤 정수 k를 가져와도 위 식을 계속 반복하게 되므로 0 ~ n-1 까지만 체크하면 됩니다.

즉, (i + a[i]) mod n 을 0 ~ n - 1 까지 수행할 때 겹치는 수가 나오는 지 여부를 체크하면 됩니다.
음수 나머지의 처리를 위해( + n) mod n 을 해줍니다. 
*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<vector>
#include<set>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>
#define ll long long
#define MAX 200001

int T, N;

int main(void) {
	FIO;

	cin >> T;

	while (T--) {
		cin >> N;

		set<ll> m;

		for (int i = 0; i < N; i++)
		{
			int v;
			cin >> v;

			ll next = ((i + v) % N + N) % N;
			m.insert(next);
		}

		if (m.size() != N)
			cout << "NO" << "\n";
		else
			cout << "YES" << "\n";
	}
}