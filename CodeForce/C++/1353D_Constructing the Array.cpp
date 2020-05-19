/*
D. Constructing the Array
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given an array a of length n consisting of zeros. You perform n actions with this array: during the i-th action, the following sequence of operations appears:

Choose the maximum by length subarray (continuous subsegment) consisting only of zeros, among all such segments choose the leftmost one;
Let this segment be [l;r]. If r−l+1 is odd (not divisible by 2) then assign (set) a[l+r2]:=i (where i is the number of the current action), otherwise (if r−l+1 is even) assign (set) a[l+r−12]:=i.
Consider the array a of length 5 (initially a=[0,0,0,0,0]). Then it changes as follows:

Firstly, we choose the segment [1;5] and assign a[3]:=1, so a becomes [0,0,1,0,0];
then we choose the segment [1;2] and assign a[1]:=2, so a becomes [2,0,1,0,0];
then we choose the segment [4;5] and assign a[4]:=3, so a becomes [2,0,1,3,0];
then we choose the segment [2;2] and assign a[2]:=4, so a becomes [2,4,1,3,0];
and at last we choose the segment [5;5] and assign a[5]:=5, so a becomes [2,4,1,3,5].
Your task is to find the array a of length n after performing all n actions. Note that the answer exists and unique.

You have to answer t independent test cases.

Input
The first line of the input contains one integer t (1≤t≤104) — the number of test cases. Then t test cases follow.

The only line of the test case contains one integer n (1≤n≤2⋅105) — the length of a.

It is guaranteed that the sum of n over all test cases does not exceed 2⋅105 (∑n≤2⋅105).

Output
For each test case, print the answer — the array a of length n after performing n actions described in the problem statement. Note that the answer exists and unique.

풀이:
재귀함수를 이용하여 풀이했습니다.

각 함수는 호출될 때마다 시작(s), 끝(e)을 가지고 있고, s와 e를 이용해 길이를 구하고, 세 가지 정보를 우선순위 큐에 넣습니다.
큐는 길이가 긴 순서, 길이가 같다면 시작 점이 작은 순서로 정렬되며 나중에 큐의 각 값들을 가지고 배열을 만들게 됩니다.

문제의 조건에 맞게 왼쪽, 오른쪽을 나눠가며 재귀호출하고
큐의 값들로 배열의 값들을 변경해줍니다.
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
#define pic pair<int, char>
#define ll long long
#define vi vector<int>
#define vl vector<long long>
#define vii vector<pii>
#define IMAX 2000000001
int mv1[4] = { 0, 0, 1, -1 };
int mv2[4] = { 1, -1, 0, 0 };

int t, n;
priority_queue<pair<int, pii>> pq;

void recul(int s, int e) {
	int leng = e - s + 1;
	if (leng == 0) {
		return;
	}
	pq.push(make_pair(leng, make_pair(-s, e)));
	

	int mid;
	if (leng % 2 == 0)
		mid = (e + s - 1) / 2;
	else
		mid = (e + s) / 2;

	
	recul(s, mid - 1);
	//왼쪽
	recul(mid + 1, e);
	//오른쪽
}

int main(void) {
	FIO;

	cin >> t;

	while (t--) {
		cin >> n;

		vector<int> vt(n + 1);
		

		int idx = 1;

		recul(1, n);

		while (!pq.empty()) {
			int s = -pq.top().second.first;
			int e = pq.top().second.second;
			pq.pop();
			int leng = e - s + 1;

			int mid;
			if (leng % 2 == 0)
				mid = (e + s - 1) / 2;
			else
				mid = (e + s) / 2;

			vt[mid] = idx++;
			//배열 만듬.
		}
		for (int i = 1; i <= n; i++)
		{
			cout << vt[i] << " ";
		}
		cout << "\n";
	}
}