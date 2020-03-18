/*
����
�����̴� �������� "����� ���ؿ�" ������ �������ְ� �ִ�. �����̰� ������ �ϳ��� ��ĥ������ ������ ���ݱ��� �����̰� ���� �� �߿��� �߰����� ���ؾ� �Ѵ�. ����, �׵��� �����̰� ��ģ ���� ������ ¦������� �߰��� �ִ� �� �� �߿��� ���� ���� ���ؾ� �Ѵ�.

���� ��� �����̰� �������� 1, 5, 2, 10, -99, 7, 5�� ������� ���ƴٰ� �ϸ�, ������ 1, 1, 2, 2, 2, 2, 5�� ���ʴ�� ���ؾ� �Ѵ�. �����̰� ��ġ�� ���� �־����� ��, ������ ���ؾ� �ϴ� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ��� �����̰� ��ġ�� ������ ���� N�� �־�����. N�� 1���� ũ�ų� ����, 100,000���� �۰ų� ���� �ڿ����̴�. �� ���� N�ٿ� ���ļ� �����̰� ��ġ�� ������ ���ʴ�� �־�����. ������ -10,000���� ũ�ų� ����, 10,000���� �۰ų� ����.

���
�� �ٿ� �ϳ��� N�ٿ� ���� �������� ������ ���ؾ��ϴ� ���� ������� ����Ѵ�.

Ǯ��:

�ִ� ���� �ּ� �� �ΰ��� ����Ͽ�, �ִ� ���� top�� �׻� �߰����� ����Ű�� �����.

Heap�� ������ �̿��Ͽ� �߾Ӱ����� ���� ������ MaxHeap��, �߾Ӱ����� ū ������ MinHeap�� �־��ش�.

1. �ϴ� ó���� ���ʺ���(MaxHeap) �ִ´�.

2. ������(MinHeap)�� ����ְų�, �������� �ּҰ����� ���� ���� ���� ��� MaxHeap�� �־��ش�.

3. MaxHeap�� MinHeap�� ����� �����ϰ� ���ش�.

3-1. MaxHeap�� ����� MinHeap�� ������� 2�� �̻� ���� �� MaxHeap�� top���� MinHeap���� �̵������ش�.

3-2. MinHeap�� ����� MaxHeap�� ������� Ŀ�� ���� MinHeap�� top���� MaxHeap���� �̵������ش�.

4. Ȧ����° ���� �־��� ������ MaxHeap�� Top���� ����Ѵ�.
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
using namespace std;

int N;
priority_queue<int> max_q;
priority_queue<int> min_q;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int  i = 1; i <= N; i++)
	{
		int now;
		cin >> now;

		if (min_q.empty() || min_q.top() * -1 > now) {
			max_q.push(now);
		}
		else
			min_q.push(now * -1);
		if (max_q.size() >= min_q.size() + 2) {
			min_q.push(max_q.top() * -1);
			max_q.pop();
		}
		if (max_q.size() < min_q.size()) {
			max_q.push(min_q.top() * -1);
			min_q.pop();
		}
		if (i % 2 == 0) {
			cout << min(max_q.top(), min_q.top() * -1);
		}
		else {
			cout << max_q.top();
		}
		cout << "\n";
	}
}