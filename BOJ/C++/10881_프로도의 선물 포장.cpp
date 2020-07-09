/*
문제
프로도는 네오에게 줄 생일 선물을 세 개 샀다. 이 세 개의 선물은 직사각형 모양의 선물 상자에 각각 하나씩 담겨 있다. 프로도는 이 선물들을 적당한 크기의 직사각형 포장 상자에 넣어 포장하려 한다. 큰 포장 상자를 주문할수록 돈을 더 많이 써야 하기 때문에, 프로도는 최대한 작은 상자에 세 개의 선물을 모두 담으려고 한다.

사용하게 될 포장 상자의 크기는 선물 상자의 배치 방법에 따라 달라질 수 있다. 이때, 선물들이 안전하게 포장되기 위해서는 각 변이 상자의 가로와 세로에 평행하게 해야 하고, 선물 상자 전체가 포장 상자 안에 담겨 있어야 한다. 선물 상자가 포장 상자의 경계에 접하는 것은 허용되며, 선물 상자는 90도 단위로 회전 가능하다.

예를 들어, 선물 상자들의 크기 (가로×세로)가 각각 3×4, 5×6, 4×1인 선물 상자들을 아래와 같이 포장하면 사용할 포장 상자의 크기는 8 × 8 = 64이 된다.



하지만 아래와 같이 포장할 경우, 사용할 포장 상자의 크기는 5 × 10 = 50이 된다.



구매한 선물 상자들의 크기가 주어졌을 때, 선물들을 안전하게 포장하는 데 필요한 포장 상자의 최소 크기 (즉, 포장 상자의 넓이가 최소가 되는 경우)를 구하시오.

입력
첫 번째 줄에 테스트 케이스의 수 T (1 ≤ T ≤ 10,000)가 주어진다.

각 테스트 케이스마다 세 개의 줄에 각각 선물의 가로와 세로를 뜻하는 두 개의 정수 A, B (1 ≤ A, B ≤ 50)가 공백을 사이에 두고 주어진다.

출력
각 테스트 케이스에 대해 한 줄에 하나씩 선물을 모두 안전하게 포장하기 위해 필요한 포장 상자의 최소 크기를 출력한다.

풀이:
세 개의 박스에 대해 90도 회전한 값을 모두 저장한 가로, 세로 길이 배열을 만듭니다.(각각 6개의 값)

총 6가지 세트에 대해 박스의 중복을 방지하여 모든 가능한 경우를 구합니다.
경우는 두 가지 케이스가 있습니다.
1. 세 박스가 모두 일렬인 경우 -> 세 박스의 가로를 모두 더하고, 높이는 가장 높은 박스
2. 두 박스 위에 한 박스가 있는 경우 -> max(한 박스의 가로, 두 박스의 가로를 더한 값) = 가로, 두 박스 중 큰 높이 + 한 박스의 높이 = 세로
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
#define IMAX 2000000001
#define LMAX 1000000000000000000
#define DMAX 0xFFFFFFFFFFFFF
int mv1[4] = { 0, 1, 0, -1 };
int mv2[4] = { 1, 0, -1, 0 };

int t;
int w[6], h[6];
int ans;

int main(void) {
	FIO;

	cin >> t;

	while (t--) {

		ans = IMAX;

		for (int i = 0; i < 3; i++)
		{
			int r, c;
			cin >> r >> c;

			w[i] = r;
			h[i] = c;
			w[i + 3] = c;
			h[i + 3] = r;
		}

		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				for (int k = 0; k < 6; k++)
				{
					if (i % 3 == j % 3 || i % 3 == k % 3 || j % 3 == k % 3)	continue;

					int height, base;

					height = max(h[i], max(h[j], h[k]));
					base = w[i] + w[j] + w[k];

					ans = min(ans, height * base);

					height = max(h[i], h[j]) + h[k];
					base = max(w[i] + w[j], w[k]);

					ans = min(ans, height * base);
				}
			}
		}

		cout << ans << "\n";
	}
}