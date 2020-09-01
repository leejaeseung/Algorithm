//#include<iostream>
//#include<memory.h>
//#include<algorithm>
//#include<math.h>
//#include<string>
//#include<vector>
//#include<stack>
//#include<queue>
//#include<map>
//#include<set>
//using namespace std;
//#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
//#define pii pair<int, int>
//#define pdd pair<double, double>
//#define pic pair<int, char>
//#define ll long long
//#define vi vector<int>
//#define vl vector<long long>
//#define vc vector<char>
//#define vii vector<pii>
//#define IMAX 2000000001
//#define LMAX 1000000000000000000
//#define DMAX 0xFFFFFFFFFFFFF
//int mv1[4] = { 0, 0, 1, -1 };
//int mv2[4] = { 1, -1, 0, 0 };
//int mv_all1[8] = { 0, 1, 0, -1, -1, -1, 1, 1 };
//int mv_all2[8] = { 1, 0, -1, 0 , -1, 1, -1, 1 };
//
//int Answer;
//
//int main(int argc, char** argv)
//{
//	int T, test_case;
//
//	cin >> T;
//	for (test_case = 0; test_case < T; test_case++)
//	{
//		Answer = IMAX;
//
//		int n, k;
//		cin >> n >> k;
//
//		vector<int> A;
//		vector<int> B;
//
//		for (int i = 0; i < n; i++)
//		{
//			int v;
//			cin >> v;
//			A.push_back(v);
//		}
//
//		for (int i = 0; i < n; i++)
//		{
//			int v;
//			cin >> v;
//			B.push_back(v);
//		}
//
//		sort(A.begin(), A.end());
//		sort(B.begin(), B.end());
//
//		int left = 0, right = 0;
//
//		for (int i = 0; i < k; i++)
//		{
//			left = max(left, A[i] + B[k - i - 1]);
//		}
//
//		for (int i = 0; i < k; i++)
//		{
//			right = max(right, B[i] + A[k - i - 1]);
//		}
//
//		Answer = min(left, right);
//
//		cout << "Case #" << test_case + 1 << endl;
//		cout << Answer << endl;
//	}
//
//	return 0;
//}