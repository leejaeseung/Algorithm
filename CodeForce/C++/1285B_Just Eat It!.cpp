/*
B. Just Eat It!
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Today, Yasser and Adel are at the shop buying cupcakes. There are n cupcake types, arranged from 1 to n on the shelf, and there are infinitely many of each type. The tastiness of a cupcake of type i is an integer ai. There are both tasty and nasty cupcakes, so the tastiness can be positive, zero or negative.

Yasser, of course, wants to try them all, so he will buy exactly one cupcake of each type.

On the other hand, Adel will choose some segment [l,r] (1≤l≤r≤n) that does not include all of cupcakes (he can't choose [l,r]=[1,n]) and buy exactly one cupcake of each of types l,l+1,…,r.

After that they will compare the total tastiness of the cupcakes each of them have bought. Yasser will be happy if the total tastiness of cupcakes he buys is strictly greater than the total tastiness of cupcakes Adel buys regardless of Adel's choice.

For example, let the tastinesses of the cupcakes be [7,4,−1]. Yasser will buy all of them, the total tastiness will be 7+4−1=10. Adel can choose segments [7],[4],[−1],[7,4] or [4,−1], their total tastinesses are 7,4,−1,11 and 3, respectively. Adel can choose segment with tastiness 11, and as 10 is not strictly greater than 11, Yasser won't be happy :(

Find out if Yasser will be happy after visiting the shop.

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤104). The description of the test cases follows.

The first line of each test case contains n (2≤n≤105).

The second line of each test case contains n integers a1,a2,…,an (−109≤ai≤109), where ai represents the tastiness of the i-th type of cupcake.

It is guaranteed that the sum of n over all test cases doesn't exceed 105.

Output
For each test case, print "YES", if the total tastiness of cupcakes Yasser buys will always be strictly greater than the total tastiness of cupcakes Adel buys regardless of Adel's choice. Otherwise, print "NO".

문제 설명:
배열의 총 합보다 자기 자신이 아닌 연속된 부분 배열의 합이 총 합보다 크거나 같으면 "NO", 아니라면 "YES"를 출력합니다.

풀이:
왼쪽과 오른쪽에서 부터 각각 prefix sum을 구하여 0보다 작거나 같아질 때가 "NO" 입니다.
prefix sum이 0이하가 된다는 의미는 그 감소하는 구간이 없었다면 기존의 총합이 더 커질 수 있었다는 의미입니다.
따라서 감소하는 구간을 제외한 부분 배열이 총합보다 커지는 구간이 반드시 존재합니다.
*/
#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<vector>
#include<queue>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>

int T, N;
long long arr[100000];

int main(void) {
	FIO;

	cin >> T;

	while (T--) {
		cin >> N;

		long long sum = 0;

		for (int i = 0; i < N; i++)
		{
			cin >> arr[i];
			sum += arr[i];
		}

		long long leftSum = 0;
		long long rightSum = 0;
		bool flag = false;

		for (int i = 0; i < N; i++)
		{
			leftSum += arr[i];
			rightSum += arr[N - i - 1];

			if (leftSum <= 0 || rightSum <= 0) {
				flag = true;
				break;
			}
		}
		if (flag)
			cout << "NO\n";
		else
			cout << "YES\n";
	}
}