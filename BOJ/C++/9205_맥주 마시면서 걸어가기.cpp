/*����
�۵��� ��� ����̿� ģ������ �۵����� ������ ��Ÿ��Ʈ �� �佺Ƽ���� ������ �Ѵ�. ���ش� ���ָ� ���ø鼭 �ɾ��� �ߴ�. ����� ����̳� ������ �ϰ�, ���� �� �ڽ��� ��� ����Ѵ�. ���� �� �ڽ����� ���ְ� 20�� ����ִ�. ���� ������ �ȵǱ� ������ 50���Ϳ� �� ���� ���÷��� �Ѵ�.

������� ������ �佺Ƽ���� ������ ���� �ſ� �� �Ÿ��̴�. ����, ���ָ� �� �����ؾ� �� ���� �ִ�. �̸� ���ͳ����� ���縦 �غ��� �������� ���ָ� �Ĵ� �������� �ִ�. �������� ����� ��, �� ���� ������ �� ���� ���� �� �� �ִ�. ������, �ڽ��� ����ִ� ���ִ� 20���� ���� �� ����.

������, ����̳� ��, ��Ÿ��Ʈ �� �佺Ƽ���� ��ǥ�� �־�����. ����̿� ģ������ �ູ�ϰ� �佺Ƽ���� ������ �� �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �׽�Ʈ ���̽��� ���� t�� �־�����. (t �� 50)

�� �׽�Ʈ ���̽��� ù° �ٿ��� ���ָ� �Ĵ� �������� ���� n�� �־�����. (0 �� n �� 100).

���� n+2�� �ٿ��� ����̳� ��, ������, ��Ÿ��Ʈ �� �佺Ƽ�� ��ǥ�� �־�����. �� ��ǥ�� �� ���� x�� y�� �̷���� �ִ�. (�� �� ��� ����, -32768 �� x, y �� 32767)

�۵��� ���簢�� ������� ���� �����̴�. �� ��ǥ ������ �Ÿ��� x ��ǥ�� ���� + y ��ǥ�� ���� �̴�. (����ư �Ÿ�)

���
�� �׽�Ʈ ���̽��� ���ؼ� ����̿� ģ������ �ູ�ϰ� �佺Ƽ���� �� �� ������ "happy", �߰��� ���ְ� �ٴڳ��� "sad"�� ����Ѵ�. 

Ǯ�� : �Ÿ��� 1000������ ���鸸 ť�� �־� BFS
*/

#include<iostream>
#include<vector>
#include<math.h>
#include<queue>
using namespace std;

typedef struct point {
	int x;
	int y;
	bool visit;
}PT;

int N;


bool CanGo(int x1,int y1,int x2,int y2) {
	if (abs(x1 - x2) + abs(y1 - y2) <= 1000)
		return true;
	else
		return false;
}

bool BFS(PT start,PT Dst, vector<PT> vt) {
	queue<PT> q;
	q.push(start);

	while (!q.empty()) {
		PT temp = q.front();
		q.pop();
		if (CanGo(Dst.x, Dst.y, temp.x, temp.y))
			return true;

		for (int i = 0; i < N; i++)
		{
			
			if (!vt.at(i).visit && CanGo( temp.x , temp.y , vt.at(i).x , vt.at(i).y )) {
				vt.at(i).visit = true;
				q.push(vt.at(i));
			}
		}
	}
	return false;
}

int main(void) {
	ios_base::sync_with_stdio;
	cin.tie(NULL);

	int t;
	cin >> t;
	
	for (int i = 0; i < t; i++)
	{
		int x, y;
		cin >> N;

		vector<PT> vt;
		cin >> x >> y;
		PT start = { x , y , true};
		for (int i = 0; i < N; i++)
		{
			cin >> x >> y;
			PT CV = { x , y , false};
			vt.push_back(CV);
		}
		cin >> x >> y;
		PT Dst = { x , y , false};

		if (BFS(start, Dst, vt))
			cout << "happy" << "\n";
		else
			cout << "sad" << "\n";
	}
}