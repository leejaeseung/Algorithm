/*
����
������ ���ִ��� �¾ ��罺���� ���̴�. ���� �� ���� ����ϱ� ���� �� ���� �Ǿ��ִ� ���� ������ ������ �����ߴ�.

�� N���� ���� �ִ� ��, ���� ��� ���� �ؿ� �Ǿ ���� �ؿ� ����. �ϳ��� ���� �Ǵ� ���� ���� ���� ������ �ִ�. ���� ���, 5�� 8�� �Ǿ 6�� 13�� ���� ���� 5�� 8�Ϻ��� 6�� 12�ϱ����� ���� �Ǿ� �ְ�, 6�� 13���� �����Ͽ� ���ķδ� ���� �� �� ���ٴ� �ǹ��̴�. (���ش� 4, 6, 9, 11���� 30�ϱ��� �ְ�, 1, 3, 5, 7, 8, 10, 12���� 31�ϱ��� ������, 2���� 28�ϱ����� �ִ�.)

�̷��� N���� �ɵ� �߿��� ������ �� ������ �����ϴ� �ɵ��� �����ϰ� �ʹ�.

���ְ� ���� �����ϴ� ������ 3�� 1�Ϻ��� 11�� 30�ϱ��� ���� ���� �� ���� �̻� �Ǿ� �ֵ��� �Ѵ�.
������ ���� �����Ƿ� ������ �ɴ� �ɵ��� ���� ������ ���� �Ѵ�.
N���� �ɵ� �߿��� ���� �� ������ �����ϴ�, �� 3�� 1�Ϻ��� 11�� 30�ϱ��� ���� ���� �� ���� �̻� �Ǿ� �ֵ��� �ɵ��� ������ ��, ������ �ɵ��� �ּ� ������ ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ��� �ɵ��� �� ���� N (1<=N<=100,000)�� �־�����. ���� N���� �ٿ��� �� ���� �Ǵ� ��¥�� ���� ��¥�� �־�����. �ϳ��� ��¥�� ���� ���� ��Ÿ���� �� ���ڷ� ǥ���ȴ�. ���� ��, 3 8 7 31�� ���� 3�� 8�Ͽ� �Ǿ 7�� 31�Ͽ� ���ٴ� ���� ��Ÿ����.

���
ù° �ٿ� ������ �ɵ��� �ּ� ������ ����Ѵ�. ���� �� ������ �����ϴ� �ɵ��� ������ �� ���ٸ� 0�� ����Ѵ�.

Ǯ��:
����, ���� �Ϸ� �־����� ����, �� ���� 1 ~ 365 ������ ���� ��ó���ϴ� ������ �ʿ��ϴ�.
�� ������ ���� ���� ���е�� ��Ÿ�� �� �������� ��������, ������ ������������ ������ �������Ѵ�.

end �� : ������� ���� ���� ������ ��ǥ
maxE �� : end ���� ���ο� ������ ���� �� ���� �ָ� �� �� �ִ� ���� ��ǥ

maxE ���� ���ο� ������ ���� ���� ũ�ٸ� ������ �߰��� �������� �ǹǷ� ī��Ʈ 0�� �ǰ�, �����Ѵ�.(�������� ���� ���ĵǾ� �����Ƿ�)
�ƴ϶�� ���� ���а� ���ο� ������ ���� �� �ִ�. ������ ���� �����Ѵ�.

- end ���� ���ο� ������ ���� ���� ũ�ٸ� -> ���ο� ������ �̾�� �Ѵ�.(ī��Ʈ 1����)
- ���ο� ������ �� ���� maxE�� ���� maxE�� ��� �����Ѵ�.
- maxE �� 11�� 30���� �Ѿ�� �Ǹ� �� ���а� �ٷ� ������ �ǹǷ� ī��Ʈ 1�� ������Ű�� �����Ѵ�.
(������ ���� ���������̹Ƿ� ���� ������ �� ª��)
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
#define pll pair<ll, ll>
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vii vector<pii>
#define IMAX 2000000001
#define LMAX 1000000000000000000
#define DMAX 0xFFFFFFFFFFFFF
#define MOD 100003
int mv1[4] = { 0, 1, 0, -1 };
int mv2[4] = { 1, 0, -1, 0 };
int mv_all1[8] = { 0, 1, 0, -1, -1, -1, 1, 1 };
int mv_all2[8] = { 1, 0, -1, 0 , -1, 1, -1, 1 };

int n;
int mth[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
vector<pii> fw;
int ps = 60;  //3��1��
int pe = 335; //12��1��

pii toDay(int monthS, int dayS, int monthE, int dayE) {
	int s = dayS;
	int e = dayE;

	for (int i = 1; i < monthS; i++)
	{
		s += mth[i];
	}

	for (int i = 1; i < monthE; i++)
	{
		e += mth[i];
	}

	return { s , -e };
}

int main(void) {
	FIO;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int sm, sd, em, ed;
		cin >> sm >> sd >> em >> ed;
		
		fw.push_back(toDay(sm, sd, em, ed));
	}

	sort(fw.begin(), fw.end());

	int maxE = ps;
	int e = ps;
	int cnt = 0;

	for (int i = 0; i < n; i++)
	{
		int nowS = fw[i].first;
		int nowE = -fw[i].second;

		if (nowS > maxE) {
			cnt = 0;
			break;
		}
		else {

			if (nowS > e) {
				cnt++;
				e = maxE;
			}
			
			if (nowE > maxE) {
				maxE = nowE;
			}

			if (maxE >= pe) {
				cnt++;
				break;
			}

		}
	}

	if (maxE < pe)
		cnt = 0;

	cout << cnt;
}