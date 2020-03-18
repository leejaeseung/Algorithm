#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio;
	cin.tie(NULL);

	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int size;
		string str;
		int count_one = 0;
		int count_q = 0;
		int max = -1;
		int min = -1;
		cin >> size >> str;
		for (int i = 0; i < size; i++)
		{
			if (str[i] == '1')
				count_one++;
			if (str[i] == '?')
				count_q++;
			if ((str[i] == '1' || str[i] == '?') && max == -1) {
				max = size * 2 - i - 1;
			}
			if (str[i] == '1' && min == -1) {
				min = size * 2 - i - 1;
			}
			if (count_one + count_q > 1 && count_one > 1)
				break;
		}
		if (count_one + count_q > 1)
			max++;
		if (count_one > 1)
			min++;

		if (count_one == 0 && count_q == 0)
			cout << 1 << " ";
		else
			cout << max << " ";
		if (count_one == 0)
			cout << 1 << "\n";
		else
			cout << min << "\n";
	}
}