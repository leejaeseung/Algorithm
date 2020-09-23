/*
����
N���� ���簢�� ����� �ǹ����� �־����� ��, ��ī�̶����� ���س��� ���α׷��� �ۼ��Ͻÿ�. ��ī�̶����� �ǹ� ��ü�� ������ �ǹ��Ѵ�. ��, ������ �ǹ��� ���簢������ ǥ������ ��, �׷��� ���簢������ �������� ���ϴ� �����̴�.



���� ��� ���簢�� ����� �ǹ����� ���� ���� �־����ٰ� ����. ������ �ǹ��� ���� x��ǥ�� ������ x��ǥ, �׸��� ���̷� ��Ÿ����. ��� �ǹ����� ���ǻ� ���� ������ ����(��) ���� �ִٰ� ��������. ���� ������ ��ī�̶����� ���ϸ� �Ʒ��� ����.



�Է�
ù° �ٿ� �ǹ��� ���� N(1 �� N �� 100,000)�� �־�����. ���� N���� �ٿ��� N���� �ǹ��� ���� ������ �־�����. �ǹ��� ���� ������ �� ���� L, H, R�� ��Ÿ���µ�, ���� �ǹ��� ���� x��ǥ, ����, ������ x��ǥ�� �ǹ��Ѵ�. (1 �� L < R �� 1,000,000,000, 1 �� H �� 1,000,000,000)

���
ù° �ٿ� ��ī�̶����� ����Ѵ�. ����� �� ������ ���̰� ���ϴ� ������ ���ؼ�, �� ������ x��ǥ�� �� ���������� ���̸� ����Ѵ�.

Ǯ��:
https://www.crocus.co.kr/1248
�� ��α׸� ������.
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
map<int, int> ans;
map<pii, int, greater<>> hm;
vector<pair<pii, pii>> vt;

int main(void) {
	FIO;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int left, h, right;
		cin >> left >> h >> right;

		
		vt.push_back({ {left, h}, {right, 1} });
		vt.push_back({ {right, h}, {left, 0} });
	}

	sort(vt.begin(), vt.end());

	int prv = -1;
	hm[{0, 0}] = 0;

	for (int i = 0; i < vt.size(); i++)
	{
		int nowP = vt[i].first.first;
		int nowH = vt[i].first.second;
		int otherP = vt[i].second.first;
		int isStart = vt[i].second.second;

		if (isStart) {
			hm[{nowH, nowP}] = otherP;
		}
		else {
			hm.erase(hm.find({ nowH, otherP }));
		}

		auto maxH = hm.begin();

		if (maxH->first.first != prv) {
			prv = maxH->first.first;

			if (isStart) {
				ans[nowP] = max(ans[nowP], prv);
			}
			else {
				if (ans.count(nowP) == 0)
					ans[nowP] = prv;
				else
					ans[nowP] = min(ans[nowP], prv);
			}
		}
	}

	prv = -1;
	for (auto iter = ans.begin(); iter != ans.end(); iter++)
	{
		if (iter->second != prv)
			cout << iter->first << " " << iter->second << " ";
		prv = iter->second;
	}
}