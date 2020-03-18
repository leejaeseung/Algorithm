/*
����
���� A(1��A��100), ���� B(1��B��100) ũ���� ���� �ִ�. �� �� ���� �κ����� N(1��N��100)�� �ִ�.



�κ����� �ʱ� ��ġ�� x��ǥ�� y��ǥ�� ��Ÿ����. ���� �׸����� ���� x��ǥ�� ���ʺ���, y��ǥ�� �Ʒ��ʺ��� ������ �Ű�����. ���� �� �κ��� �� ó���� NWES �� �ϳ��� ������ ���� �� �ִ�. �ʱ⿡ �� �ִ� �κ����� ��ġ�� ���� �ٸ���.

�̷��� �κ��鿡 M(1��M��100)���� ����� �������� �Ѵ�. ������ ����� ���������� ����ȴ�. ��, �ϳ��� ����� �� �κ����� ��������, �� ����� �ϼ��� ������ �� �κ��� �ٸ� ��� �κ����� �ٸ� ����� ���� �� ����. ������ �κ��� ���� �����ϴ� ����� ������ �� ������ �ִ�.

L: �κ��� ���ϰ� �ִ� ������ �������� �������� 90�� ȸ���Ѵ�.
R: �κ��� ���ϰ� �ִ� ������ �������� ���������� 90�� ȸ���Ѵ�.
F: �κ��� ���ϰ� �ִ� ������ �������� ������ �� ĭ �����δ�.
��Ȥ �κ��鿡�� ������ ����� �߸��� ���� �ֱ� ������, ����� �κ��鿡�� ����� ������ ���� �� �� �ùķ��̼��� �� ���鼭 �������� �����Ϸ� �Ѵ�. �̸� �����ִ� ���α׷��� �ۼ��Ͻÿ�.

�߸��� ��ɿ��� ������ �� ������ ���� �� �ִ�.

Robot X crashes into the wall: X�� �κ��� ���� �浹�ϴ� ����̴�. ��, �־��� ���� ������ ����� ��찡 �ȴ�.
Robot X crashes into robot Y: X�� �κ��� �����̴ٰ� Y�� �κ��� �浹�ϴ� ����̴�.
�Է�
ù° �ٿ� �� ���� A, B�� �־�����. ���� �ٿ��� �� ���� N, M�� �־�����. ���� N���� �ٿ��� �� �κ��� �ʱ� ��ġ(x, y��ǥ ��) �� ������ �־�����. ���� M���� �ٿ��� �� ����� ����� ������ ������� �־�����. ������ ����� ����� ������ �κ�, ����� ����(���� ���� �ִ�), ����� �ݺ� ȸ���� ��Ÿ����. �� ����� �ݺ� ȸ���� 1�̻� 100�����̴�.

���
ù° �ٿ� �ùķ��̼� ����� ����Ѵ�. ������ ���� ��쿡�� OK��, �� ���� ��쿡�� ���� ���Ĵ�� ����� �Ѵ�. ���� �浹�� ���� �� �߻��ϴ� ��쿡�� ���� ���� �߻��ϴ� �浹�� ����ϸ� �ȴ�.
Ǯ�� : ��ɵ��� ��� ť�� ����ְ� ��ɸ��� �κ��� ���������� Ǯ��.
*/

#include<iostream>
#include<utility>
#include<vector>
#include<queue>
using namespace std;

int map[101][101];
int hor, ver, N, M;
int mv1[4] = { 1, 0, -1, 0 };			//�� �� �� ��
int mv2[4] = { 0, -1, 0, 1 }; 
vector<pair<int, pair<int, int> > > robot;
queue<pair<int, char > > order;

void move() {

	while (!order.empty()) {
		int now_robot = order.front().first;
		char od = order.front().second;
		order.pop();
		
		if (od == 'L') {
			robot.at(now_robot).first = (robot.at(now_robot).first + 1) % 4;
		}
		else if (od == 'R') {
			robot.at(now_robot).first = (robot.at(now_robot).first + 3) % 4;
		}
		else {
			map[robot.at(now_robot).second.second][robot.at(now_robot).second.first] = 0;
			int new_x = robot.at(now_robot).second.first + mv1[robot.at(now_robot).first];
			int new_y = robot.at(now_robot).second.second + mv2[robot.at(now_robot).first];

			if (new_x < 0 || new_x > hor || new_y < 0 || new_y > ver) {
				cout << "Robot " << now_robot << " crashes into the wall";
				return;
			}
			if (map[new_y][new_x] != 0) {
				cout << "Robot " << now_robot << " crashes into robot " << map[new_y][new_x];
				return;
			}
			robot.at(now_robot).second.first = new_x;
			robot.at(now_robot).second.second = new_y;
			map[new_y][new_x] = now_robot;
		}
	}
	cout << "OK";
}

int main(void) {
	ios_base::sync_with_stdio;
	cin.tie(NULL);

	cin >> hor >> ver;
	cin >> N >> M;

	robot.push_back(pair<int, pair<int, int> >{0, pair<int, int>{0, 0}});
	for (int i = 1; i <= N; i++)
	{
		int x, y, p;
		char pos;
		cin >> x >> y >> pos;
		if (pos == 'E')
			p = 0;
		if (pos == 'N')
			p = 1;
		if (pos == 'W')
			p = 2;
		if (pos == 'S')
			p = 3;
		robot.push_back(pair<int, pair<int, int> >{p, pair<int, int>{x - 1, ver - y}});
		map[ver - y][x - 1] = i;
	}
	for (int i = 0; i < M; i++)
	{
		int r, c;
		char o;
		cin >> r >> o >> c;
		for (int i = 0; i < c; i++)
		{
			order.push(pair<int, char >{r, o});
		}
	}
	move();
}