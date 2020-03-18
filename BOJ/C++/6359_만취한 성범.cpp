/*
	Ǯ�� : N���� boolean �迭�� ����� ������ ������ true,false�� ������ ���� �ٲ��ش�.
*/
#include<iostream>
#include<vector>


using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int N;
		cin >> N;
		vector<bool> vt;
		vt.resize(N+1);
		
		for (int i = 2; i <= N; i++)
		{
			for (int j = 1; i*j<=N; j++)
			{
				if(vt.at(i*j))
					vt.at(i*j) = false;
				else
					vt.at(i*j) = true;
			}
		}
		int cnt = 0;
		for (int i = 1; i <=N ; i++)
		{
			if (!vt.at(i))
				cnt++;
		}
		cout << cnt << endl;
	}

}