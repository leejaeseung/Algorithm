/*
문제
n개의 정점을 갖는 이진 트리의 정점에 1부터 n까지의 번호가 중복 없이 매겨져 있다. 이와 같은 이진 트리의 인오더와 포스트오더가 주어졌을 때, 프리오더를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 n(1≤n≤100,000)이 주어진다. 다음 줄에는 인오더를 나타내는 n개의 자연수가 주어지고, 그 다음 줄에는 같은 식으로 포스트오더가 주어진다.

출력
첫째 줄에 프리오더를 출력한다.

풀이:
재귀 호출을 이용한 분할 정복 문제이다.

http://melonicedlatte.com/algorithm/2018/02/04/145104.html
위 블로그를 참고하여 풀이했다.

post 오더는 어느 서브트리에서 맨 마지막 원소가 root인 점을 이용해 in오더, post오더를 왼쪽, 오른쪽
서브트리로 나눠가며 진행하면 된다.
매 재귀마다 root나 leaf 노드를 출력하면 된다.
*/
#include<iostream>
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
int mv1[4] = { 0, 1, 0, -1 };
int mv2[4] = { 1, 0, -1, 0 };
int mv_all1[8] = { 0, 1, 0, -1, -1, -1, 1, 1 };
int mv_all2[8] = { 1, 0, -1, 0 , -1, 1, -1, 1 };

int n;
int in[100001];
int post[100001];
int idx[100001];	//post오더 값의 in오더에서의 인덱스를 저장

void make(int inS, int inE, int poS, int poE) {

	if(poS <= poE || inS <= inE)
		cout << post[poE] << " ";
	//루트, 리프 노드일 때만 출력

	if (poS >= poE || inS >= inE)	return;

	int mid = idx[post[poE]];
	//in오더의 중간 지점 = root

	int size = mid - inS;

	make(inS, mid - 1, poS, poS + size - 1);
	//왼쪽 서브트리

	make(mid + 1, inE, poS + size, poE - 1);
	//오른쪽 서브트리
}

int main(void) {
	FIO;

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> in[i];
		idx[in[i]] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> post[i];
	}

	make(1, n, 1, n);
}