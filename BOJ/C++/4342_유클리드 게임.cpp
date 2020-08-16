/*
����
��Ŭ���� ������ �� ���̼� �ϴ� �����̰�, �ڿ��� 2���� �����Ѵ�. �����̿� ���Դ� ��Ŭ���� ������ �Ϸ��� �Ѵ�. �����̰� ���� �����Ѵ�. �����̴� ū ���� ���� ���� �����ŭ ����. �̶�, ū ���� ���� �ƴ� ������ �Ǿ�� �Ѵ�.  �׷� ���� ���Դ� �����̰� �� �Ͱ� �Ȱ��� ū ���� ���� ���� �����ŭ ����. �̷������� �� �÷��̾�� ���� �����ư��鼭 ������ �Ѵ�. �̶�, ū ���� 0���� ���� ����� ������ �¸��ϰ� �ȴ�.

���� ���, ������ ���� (25, 7)�� ������ ������ �����غ���.

25 7
11 7
4 7
4 3
1 3
1 0
���� ���� ������ �ϰ� �Ǹ�, �����̰� �̱�� �ȴ�. (ū ���� ���� ���� �� �Ͽ��� ū ���� ���� ���̴�.)

�����ϴ� �� �ڿ����� �־����� ��, �� �÷��̾ ������ ������� ������ �� ��, ���� �̱���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
�Է��� ���� �ٷ� �̷���� �ִ�. �� ���� ������ �����ϴ� �� �����̴�. �׻� �����̰� ���� ������ �����Ѵ�. �� �ڿ����� 231-1���� �۰ų� ����. �Է��� ������ �ٿ��� 0 �� ���� �־�����.

���
�� �Է¿� ���ؼ� �����̰� �̱�� A wins��, ���԰� �̱�� B wins�� ����Ѵ�.

Ǯ��:
�⺻������ ��Ŭ���� ȣ������ �̿��� ������ �����Ѵ�.(�� �ϰ��� �ٲ㰡��)

�� ��, ū ���� a, ���� ���� b ��� �ϸ� ������ ���д� ������ ����.
1. a % b == 0 -> �ٷ� ������ �ǹǷ� ���� ���� ������ �¸��Ѵ�.
2. a / b >= 2 -> a ���� b �� �󸶳� �� �� ������ �� �ִ�. ��, ���� ��Ȳ���� �ʹ� ���� ���� �ᱹ ������ ���� �ȴٸ� 
���� ��Ȳ���� �� ����, ���� ���� �и��� �ǹǷ� ���� ���� ������ �̱��.
3. a / b < 2 -> �� �� �ִ°� a - b �ۿ� �����Ƿ� ������ ���Ѻ���.
*/
#include<iostream>
#include<memory.h>
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
int mv1[4] = { 0, 0, 1, -1 };
int mv2[4] = { 1, -1, 0, 0 };
int mv_all1[8] = { 0, 1, 0, -1, -1, -1, 1, 1 };
int mv_all2[8] = { 1, 0, -1, 0 , -1, 1, -1, 1 };

int gcb(int a, int b) {
	int turn = 1;

	while (b != 0) {
		turn *= -1;

		if (a % b == 0 || a / b >= 2)
			return turn;

		int temp = a % b;
		a = b;
		b = temp;
	}

	return turn;
}

int main(void) {
	FIO;

	while (true) {

		int a, b;
		cin >> a >> b;

		if (a == 0 && b == 0)
			break;

		int mx = max(a, b);
		int mn = min(a, b);

		int ans = gcb(mx, mn);

		if (ans < 0)
			cout << "A wins\n";
		else
			cout << "B wins\n";
	}
}