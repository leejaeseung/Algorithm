/*
����
���ڿ� ������ �ִ�. ������ ���� ����� �Ʒ��� ����.

���ĺ� �ҹ��ڷ� �̷���� ���ڿ� W�� �־�����.
���ĺ� �ҹ��ڷ� �̷���� ���ڿ� S�� �־�����.
���ڿ� S���� ���ڿ� W�� ��� �����ϴ� ����� �¸��Ѵ�.
������ ���ڿ� W�� ��� �����ϱ� ���� ���α׷��� ������� �Ѵ�.

������ ������ ���α׷��� �Ʒ��� ��� �� �־��� ����� �����ϴ� �۾��� N�� �ݺ��Ѵ�.

L : ���ڿ� S�� ���ʿ������� ó������ �����ϴ� ���ڿ� W�� ã��, S���� �ش� �κй��ڿ��� �����Ѵ�.
R : ���ڿ� S�� �����ʿ������� ó������ �����ϴ� ���ڿ� W�� ã��, S���� �ش� �κй��ڿ��� �����Ѵ�.
����� ������ ��, �����ؾ� �ϴ� ���ڿ� W�� ���ٸ� ����� �����ϰ�, �ƹ� �ϵ� �Ͼ�� �ʴ´�.

������ ���� N���� ��ɿ� ���� ���ڿ� S���� ���ڿ� W�� �����ϴ� ���α׷��� ����������!

�Է�
ù ��° �ٰ� �� ��° �ٿ� ���̰� 1 �̻��� ���ڿ� W�� ���ڿ� S�� ���� �־�����. W�� S�� ���ĺ� �ҹ��ڷ� �̷���� �ִ�.

W�� �ִ� 10��, S�� �ִ� 300,000���̴�.

�� ��° �ٿ� ����� ���� N�� �־�����. (1 �� N �� 30,000)

�� ��° �ٺ��� N���� �ٿ� ����� �־�����.

���
ù ��° �ٿ� ������ ����� ������, �� ��° �ٿ� ���α׷��� ������ ���� ���ڿ� S�� ����Ѵ�.

���α׷� ���� �Ŀ� ���ڿ��� ����ִ� ���� �������� �ʴ´�.

�� ��° �ٿ� ���α׷��� ������ ���� ���ڿ� S�� ���ڿ� W�� ���������� You Lose!��, ���ڿ� W�� ��� ���������� Perfect!�� ����Ѵ�.

Ǯ��:
https://hellogaon.tistory.com/75
�� ��α׸� �����Ͽ� Ǯ���߽��ϴ�. ������ ��ٷο� ���������ϴ�.

���� ��(DL), ������ ��(DR)�� ���� ����� �׸���(?)�ϰ�
L���� �ÿ��� ���ʺ��� ���� ó�� ������ W���ڿ��� �����ְ�,
R���� �ÿ��� �����ʺ��� ���� ó�� ������ W���ڿ��� �����ݴϴ�.
(����, �����ʺ��� �� ���� �����͸� �ξ� �� �����Ͱ� ��ĥ ������ �����մϴ�.)

�� �����Ͱ� ��ģ�ٸ�, DL �� ������ ���ڿ���, DR �� �������� ���ڿ����� ��� �ֱ� ������
DL�� ������, DR�� ������ ������ �� W���ڿ��� ������ �� �ֽ��ϴ�.

DL�� �������� pop -> DR�� ���ʿ� push �ذ��� W���ڿ��� ���� �� �ִ��� �����ϸ� �˴ϴ�.

Perfect ���� You Lose ���� ���δ� n���� L, R ���� �ڿ� ������ ���� L �� �߰��Ͽ� �ذ��߽��ϴ�.
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
#define IMAX 2100000001
#define LMAX 1000000000000000000
#define DMAX 0xFFFFFFFFFFFFF
int mv1[4] = { 0, 1, 0, -1 };
int mv2[4] = { -1, 0, 1, 0 };

deque<char> DL;
deque<char> DR;
string W, S;
int n;

int main(void) {
	FIO;

	cin >> W >> S;

	cin >> n;
	
	int l_idx = 0;
	int r_idx = S.size() - 1;

	int cnt = 0;
	int temp_cnt = 0;
	string ans = "";

	for (int i = 0; i < n + 1; i++)
	{
		char q;
		if (i != n)
			cin >> q;
		else {
			temp_cnt = cnt;
			//������ ������ ���� ����

			for (int i = 0; i < DL.size(); i++)
			{
				ans += DL[i];
			}

			for (int i = l_idx; i <= r_idx; i++)
			{
				ans += S[i];
			}

			for (int i = 0; i < DR.size(); i++)
			{
				ans += DR[i];
			}

			q = 'L';
			//������ ���ڿ��� W�� �����ϴ��� �Ǵ��ϱ� ���� ������ L ���� �߰�
		}

		if (l_idx <= r_idx) {
			//��ġ�� �ʴ´ٸ�
			if (q == 'L') {

				bool find = false;

				while (!find) {
					DL.push_back(S[l_idx++]);

					if (DL.size() < W.size() && l_idx < r_idx)	continue;

					int W_idx = 0;
					bool match = true;

					if (DL.size() < W.size())
						match = false;

					for (int i = DL.size() - W.size(); i < DL.size(); i++)
					{
						if ( DL[i] != W[W_idx++]) {
							match = false;
							break;
						}
					}

					if (match) {
						cnt++;
						find = true;

						for (int i = 0; i < W.size(); i++)
						{
							DL.pop_back();
						}
					}

					if (l_idx > r_idx)	break;
				}

			}
			else {
				bool find = false;

				while (!find) {
					DR.push_front(S[r_idx--]);

					if (DR.size() < W.size() && l_idx < r_idx)	continue;

					bool match = true;

					if (DR.size() < W.size())
						match = false;

					for (int i = 0; i < W.size(); i++)
					{
						if (DR[i] != W[i]) {
							match = false;
							break;
						}
					}

					if (match) {
						cnt++;
						find = true;

						for (int i = 0; i < W.size(); i++)
						{
							DR.pop_front();
						}
					}
					if (l_idx > r_idx)	break;
				}
			}
		}

		if (l_idx > r_idx) {
			//�� �����Ͱ� ������ ���

			while (!DL.empty()) {
				DR.push_front(DL.back());	DL.pop_back();

				bool match = true;

				if (DR.size() >= W.size()) {
					for (int i = 0; i < W.size(); i++)
					{
						if (DR[i] != W[i]) {
							match = false;
							break;
						}
					}
					if (!match)	continue;


					for (int i = 0; i < W.size(); i++)
					{
						DR.pop_front();
					}

					cnt++;
					break;
				}
			}
		}
	}

	cout << temp_cnt << "\n";

	cout << ans << "\n";

	if (cnt == temp_cnt)		//������ �������� cnt ���� �����ϸ� ����
		cout << "Perfect!";
	else
		cout << "You Lose!";
}