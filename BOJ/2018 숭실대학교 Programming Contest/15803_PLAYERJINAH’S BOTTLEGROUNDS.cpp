#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<pair<int, int> > man;

	for (int i = 0; i < 3; i++)
	{
		int n, m;
		cin >> n >> m;

		man.push_back(make_pair(n, m));
	}
	sort(man.begin(), man.end());

	int x = man.at(1).first - man.at(0).first;
	int y = man.at(1).second - man.at(0).second;

	if (x != 0 && y != 0) {
		if (x >= y && x % y == 0) {
			x = x / y;
			y = 1;
		}
		else if (y >= x && y % x == 0) {
			y = y / x;
			x = 1;
		}
	}
	else if (x == 0)
		y = 1;
	else
		x = 1;

	bool find = false;
	int next_x = man.at(0).first;
	int next_y = man.at(0).second;

	while (true) {
		next_x = next_x + x;
		next_y = next_y + y;

		if (next_x <= 0 || next_y <= 0 || next_x > 1000 || next_y > 1000)	break;

		if (next_x == man.at(2).first && next_y == man.at(2).second) {
			find = true;
			break;
		}
	}
	if (find)
		cout << "WHERE IS MY CHICKEN?";
	else
		cout << "WINNER WINNER CHICKEN DINNER!";
}