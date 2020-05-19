/*
E. LIS of Sequence
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
The next "Data Structures and Algorithms" lesson will be about Longest Increasing Subsequence (LIS for short) of a sequence. For better understanding, Nam decided to learn it a few days before the lesson.

Nam created a sequence a consisting of n (1 ≤ n ≤ 105) elements a 1, a 2, ..., a n (1 ≤ a i ≤ 105). A subsequence a i 1, a i 2, ..., a i k where 1 ≤ i 1 < i 2 < ... < i k ≤ n is called increasing if a i 1 < a i 2 < a i 3 < ... < a i k. An increasing subsequence is called longest if it has maximum length among all increasing subsequences.

Nam realizes that a sequence may have several longest increasing subsequences. Hence, he divides all indexes i (1 ≤ i ≤ n), into three groups:

group of all i such that a i belongs to no longest increasing subsequences.
group of all i such that a i belongs to at least one but not every longest increasing subsequence.
group of all i such that a i belongs to every longest increasing subsequence.
Since the number of longest increasing subsequences of a may be very large, categorizing process is very difficult. Your task is to help him finish this job.

Input
The first line contains the single integer n (1 ≤ n ≤ 105) denoting the number of elements of sequence a.

The second line contains n space-separated integers a 1, a 2, ..., a n (1 ≤ a i ≤ 105).

Output
Print a string consisting of n characters. i-th character should be '1', '2' or '3' depending on which group among listed above index i belongs to.

풀이:
1번 경우를 먼저 나누고, 2번3번 경우를 나눠주면서 풀이합니다.

먼저 1번 경우를 판별하기 위해 i번째 수가 LIS에서 몇 번째 자릿수인지 구합니다.그리고 LIS 뒤에서부터 몇 번째 자릿수인지도 구해야 합니다.
ex)
4
1 5 2 3
0 1 1 2 -> 앞에서부터의 자릿수
2 0 1 0 -> 뒤에서부터의 자릿수

위에서 이미 LIS의 최대 길이를 구했으므로 i번째 수가 최장 LIS에 포함되는지 여부를 위 자릿수들로 구할 수 있습니다.
LIS의 최대 길이 - 1 == 앞 자릿수 + 뒷 자릿수 -> 최장 LIS에 포함됩니다.

이제 최장 LIS에 포함되는 수들만 따로 생각해야 합니다.
i번째 수의 왼쪽에 i번째 수 보다 큰 수가 있다면 그 수로 만들 수 있는 다른 LIS가 있다는 의미이므로 i번째 수는 2번째 경우에 해당됩니다.
i번째 수의 오른쪽에 i번째 수 보다 작은 수가 있다면 -> 마찬가지입니다.

즉 자신보다 왼쪽, 오른쪽이 모두 연속적으로 증가한다면 3번 경우입니다. 
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

int n;
int pos_in[100005];
int pos_de[100005];
int maxL[100005];
int minL[100005];
vector<int> list;
vector<int> dp;
vector<int> dp2;

int LB(int v) {
	int s = 0, e = dp.size();
	while (s < e) {
		int mid = (s + e) / 2;
		if (dp[mid] >= v)
			e = mid;
		else
			s = mid + 1;
	}
	return s;
}

int LB2(int v) {
	int s = 0, e = dp2.size();
	while (s < e) {
		int mid = (s + e) / 2;
		if (dp2[mid] >= v)
			e = mid;
		else
			s = mid + 1;
	}
	return s;
}

int main(void) {
	FIO;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int v;
		cin >> v;
		list.push_back(v);
	}

	dp.push_back(list[0]);

	for (int i = 1; i < list.size(); i++)
	{
		int v = list[i];
		int idx = LB(v);

		if (idx == dp.size()) {
			dp.push_back(v);
		}
		else {
			dp[idx] = v;
		}
		pos_in[i] = idx;
	}

	dp2.push_back(list[list.size() - 1] * -1);

	for (int i = list.size() - 2; i >= 0; i--)
	{
		int v = list[i] * -1;
		int idx = LB2(v);

		if (idx == dp2.size()) {
			dp2.push_back(v);
		}
		else {
			dp2[idx] = v;
		}
		pos_de[i] = idx;
	}

	int maxV = 0, minV = IMAX;

	for (int i = 0; i < n; i++)
	{
		int left = list[i];
		int right = list[n - i - 1];

		if (pos_in[i] + pos_de[i] != dp.size() - 1) {
			left = maxV;
		}

		if (pos_in[n - i - 1] + pos_de[n - i - 1] != dp.size() - 1) {
			right = minV;
		}

		maxV = max(maxV, left);
		maxL[i] = maxV;

		minV = min(minV, right);
		minL[n - i - 1] = minV;
	}

	if (n == 1)
		cout << "3";
	else {
		for (int i = 0; i < n; i++)
		{
			if (pos_in[i] + pos_de[i] == dp.size() - 1)
			{
				if (i != 0 && i != n - 1) {
					if (maxL[i - 1] < list[i] && minL[i + 1] > list[i])
						cout << "3";
					else
						cout << "2";
				}
				else if (i == 0) {
					if (minL[i + 1] > list[i])
						cout << "3";
					else
						cout << "2";
				}
				else {
					if (maxL[i - 1] < list[i])
						cout << "3";
					else
						cout << "2";
				}
			}
			else
				cout << "1";
		}
	}
}