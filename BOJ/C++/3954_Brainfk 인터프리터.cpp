/*
����
Brainf**k ���α׷��� �־����� ��, �� ���α׷��� ��������, ���� ������ �������� �˾Ƴ��� ���α׷��� �ۼ��Ͻÿ�.

Brainf**k ���������ʹ� ������ ��� �ϳ��� �迭(unsigned 8-bit ����)��, �� �迭�� ĭ �ϳ��� ����Ű�� �����ͷ� �̷���� �ִ�. Brainf**k ���α׷��� ������ ���� 8���� ��ɾ�� �̷���� �ִ�.

-	�����Ͱ� ����Ű�� ���� 1 ���ҽ�Ų��. (modulo 28)
+	�����Ͱ� ����Ű�� ���� 1 ������Ų��. (modulo 28)
<	�����͸� �������� �����δ�.(1 ����)
>	�����͸� ���������� �����δ�.(1 ����)
[	���� �����Ͱ� ����Ű�� ���� 0�� ���ٸ�, [�� ¦�� �̷�� ]�� �����Ѵ�.
]	���� �����Ͱ� ����Ű�� ���� 0�� �ƴ϶��, ]�� ¦�� �̷�� [�� �����Ѵ�.
.	�����Ͱ� ����Ű�� ���� ����Ѵ�.
,	���� �ϳ��� �а� �����Ͱ� ����Ű�� ���� �����Ѵ�. �Է��� ������(EOF)�� ��쿡�� 255�� �����Ѵ�.
���������ʹ� Brainf**k ���α׷��� ù ��° ��ɺ��� �����ϰ�, ���̻� ������ ����� ���ٸ�, ���α׷��� �����Ѵ�. �� ����� �����ϰ� ����, ���� ����� �����Ѵ�. ���� [�̳� ]�� ��쿡�� ���� ������� �̵��ϴ� ���� �ƴ϶� ������ �Ѵ�.

������ �迭�� ũ��� �������� �־����� ���� ����ؾ� �Ѵ�. ��, ������ �迭�� ���� underflow�� overflow�� �������� ���� �Ϲ����� ����� ������ �ȴ�. ���α׷��� �����ϱ� ����, ������ �迭�� ���� 0���� �ʱ�ȭ�Ǿ� �ְ�, �����Ͱ� ����Ű�� ĭ�� 0�� ĭ�̴�.

�����͸� �����̳� ���������� ������ ��, ������ �迭�� ������ �Ѿ�ٸ�, �ݴ������� �Ѿ�� �ȴ�. ��, �����Ͱ� 0�� ����ų ��, 1�� ���ҽ�Ų�ٸ�, �迭�� ũ�� - 1��°�� ����Ű�� �ȴ�.

[�� ]�� ������ �ǹ��ϸ�, ��ø�� �� �ִ�. �Է����� �־��� ���α׷��� �� ¥�� ������ ����ȴ�. �� ���α׷��� ���ʿ��� ���������� �����鼭 [�� �������� ]�� ������ ���� �׻� 0���� ũ�ų� ����, �� ������ ������ �� ���� 0�� �ȴ�.

�� ������ Brainf**k ���α׷��� ���� ������ �������� �� ���������� �˻��ϱ⸸ �ϸ� �ȴ�. ����, ����� �����Ѵ�.

�Է�
ù° �ٿ� �׽�Ʈ ���̽��� ���� t (0 < t �� 20)�� �־�����. �� �׽�Ʈ ���̽��� �� �ٷ� �̷���� �ִ�. ù° �ٿ��� sm, sc, si�� �־�����. sm�� �޸�(�迭)�� ũ���̰�, sc�� ���α׷� �ڵ��� ũ��, si�� �Է��� ũ���̴�. (0 < sm �� 100,000, 0 < sc, si < 4096)

��° �ٿ��� Brainf**k ���α׷��� �־�����. ���α׷��� sc���� ���ڷ� �̷���� �ִ�.

��° �ٿ��� ���α׷��� �Է��� �־�����. (������ �ƴϸ鼭 ����� �� �ִ� ���ڸ� �־�����)

���
�� �׽�Ʈ ���̽��� ���ؼ�, ���α׷��� ����ȴٸ� "Terminates"��, ���� ������ ������ �ȴٸ� "Loops"�� ����Ѵ�. ���� ������ ������ ����, ���α׷��� ��� �κ��� ���� ���������� ����Ѵ�. ([�� ]�� ��ġ) ���α׷��� ��ɾ 50,000,000�� �̻� ������ ���, ���α׷��� �׻� ����Ǿ��ų� ���� ������ �����ִ�. ���� ������ ���, �ش� ������ ��� �� �� ������ �Ϸ�� �����̸�, �� ���� ���� �������� ����Ǵ� ��ɾ��� ������ 50,000,000�� �����̴�.

Ǯ��:
���ð� �迭�� �̿��� �ܼ� ���� ��������.

�־����� �޸𸮹迭�� ��ɾ�, ������ ���̰� ũ�� �����Ƿ� �ش� ���̸�ŭ �����ϰ�,
��ɾ ���� ������ ���ǹ��� �ɾ��ش�.

���ѷ����� ã�ƾ� �ϹǷ� ���� �߿��� ��ɾ�� '[' �� ']' �ε�, ��ɵ��� �����ϱ� ���� �̸� 
'[' -> ']' , ']' -> '[' ó�� �ε����� ã�ư� �� �ֵ��� ������ �̿��� ��ó���� ������.

'[' �� ������ ���ÿ� �ְ�, ']' �� ������ ���ÿ��� �� '[' �� link�� ������ �ָ� ������ �ذ�ȴ�.

���� ���� �� ���ѷ����� �Ǻ��ε� ']' ����� �� �����غ��� ']' �� ������ �� ���� �����Ͱ� ����Ű�� ���� 
�� �ѹ��̶� 0 �̶�� �� ']' �� ���ѷ����� �ƴ϶� �� �� �� �ִ�.(�ٸ� ������ ���ѷ����� ���� �ְų� ���ѷ����� ����.)

���� ��� ']' �߿� �� �ѹ��� ���� ���� 0 �� �������� ���� ']' �� �� ¦ '[' �� ���ѷ����̴�.
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

int main(void) {
	FIO;

	int t;
	cin >> t;

	while (t--) {
		int sm, sc, si;

		cin >> sm >> sc >> si;

		int* arr = (int*)malloc(sizeof(int) * sm);
		memset(arr, 0, sizeof(unsigned int) * sm);

		int* link = (int*)malloc(sizeof(int) * sc);
		memset(link, 0, sizeof(int) * sc);

		bool* isLoop = (bool*)malloc(sizeof(bool) * sc);
		memset(isLoop, false, sizeof(bool) * sc);

		string order, input;
		cin >> order >> input;

		stack<int> st;

		for (int i = 0; i < sc; i++)
		{
			//'[' �� ']' �̾��ֱ�
			char o = order[i];

			if (o == '[') {
				st.push(i);
			}
			else if (o == ']') {
				int idx = st.top();	st.pop();

				link[i] = idx;
				link[idx] = i;
			}
		}

		int cnt = 0;
		int arr_ptr = 0;
		int order_ptr = 0;
		int input_ptr = 0;

		int cur = 0;

		while(++cnt < 50000000 && order_ptr < sc)
		{
			char o = order[order_ptr++];
			cur = arr[arr_ptr];		//�޸� �迭�� ���� ��

			switch (o)
			{
			case '+':
				arr[arr_ptr] = (arr[arr_ptr] + 1) % 256;
				break;
			case '-':
				arr[arr_ptr]--;
				if (arr[arr_ptr] < 0)
					arr[arr_ptr] = 255;
				break;
			case '>':
				arr_ptr = (arr_ptr + 1) % sm;
				break;
			case '<':
				arr_ptr--;
				if (arr_ptr < 0)
					arr_ptr = sm - 1;
				break;
			case '[':
				if (arr[arr_ptr] == 0)
					order_ptr = link[order_ptr - 1];
				break;
			case ']':
				if (cur == 0)		
					//�� �ѹ��̶� ���� ���� 0 �� ���Ծ��ٸ� ���ѷ���x
					isLoop[order_ptr - 1] = true;
				if (arr[arr_ptr] != 0)
					order_ptr = link[order_ptr - 1];
				break;
			case '.':
				break;
			case ',':
				if (input_ptr == (int)input.size())
					arr[arr_ptr] = 255;
				else
					arr[arr_ptr] = (int)input[input_ptr++];
				break;
			}
		}

		if (order_ptr >= sc) {
			cout << "Terminates\n";
		}
		else {
			int left, right;

			for (int i = 0; i < sc; i++)
			{
				if (order[i] == ']' && !isLoop[i]) {
					left = link[i];
					right = i;
					break;
				}
			}

			cout << "Loops " << left << " " << right << "\n";
		}

		free(arr);
		free(link);
		free(isLoop);
	}
}