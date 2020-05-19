/*
A. Most Unstable Array
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given two integers n and m. You have to construct the array a of length n consisting of non-negative integers (i.e. integers greater than or equal to zero) such that the sum of elements of this array is exactly m and the value ∑i=1n−1|ai−ai+1| is the maximum possible. Recall that |x| is the absolute value of x.

In other words, you have to maximize the sum of absolute differences between adjacent (consecutive) elements. For example, if the array a=[1,3,2,5,5,0] then the value above for this array is |1−3|+|3−2|+|2−5|+|5−5|+|5−0|=2+1+3+0+5=11. Note that this example doesn't show the optimal answer but it shows how the required value for some array is calculated.

You have to answer t independent test cases.

Input
The first line of the input contains one integer t (1≤t≤104) — the number of test cases. Then t test cases follow.

The only line of the test case contains two integers n and m (1≤n,m≤109) — the length of the array and its sum correspondingly.

Output
For each test case, print the answer — the maximum possible value of ∑i=1n−1|ai−ai+1| for the array a consisting of n non-negative integers with the sum m.

풀이:
이웃한 두 원소의 절댓값이 최소가 되게 하려면 0을 포함해야 합니다.
따라서 최대한 0이 아닌 값과 0을 붙여가며 배열을 만들어야 합니다.
배열 원소 값엔 제한이 없으므로
n = 5 , m = 99 일 때
0 99 0 0 0
과 같이 배열을 만들어도 됩니다. 그럼 99를 두 번 더할 수 있으므로 최댓값도 구할 수 있습니다.(즉, m * 2)
단, n = 1 일 땐 항상 0이고, n = 2 일 땐 m 입니다.
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

int t, n, m;

int main(void) {
	FIO;

	cin >> t;

	while (t--) {
		cin >> n >> m;

		if (n == 1)
			cout << "0\n";
		else if(n == 2)
			cout << m << "\n";
		else
			cout << m * 2 << "\n";
	}
}