/*
문제
One of the main goals in sending Curiosity to Mars is to search for more evidence that Mars may have had water on its surface in the past, or perhaps even in the present? To figure out whether there was water, scientists use various clues from images, such as rust and other evidence of oxidation. In this question, you are to explore pictures of Mars surface, and find evidence of water in them if it exists.

Each picture will be given to you as a rectangle of h × w pixels, with 1 ≤ h,w ≤ 50. Each pixel may be indicative of different types of material, which will be denoted by a letter from the upper-case alphabet ‘A’–‘Z’. (No other values will occur.) Some of these letters will be marked as special, in that they indicate a clue for water. You will be given a minimum size 1 ≤ m ≤ min(h,w), and are to find the largest density of special letters in any subrectangle of size at least m × m.

입력
The first line is the number K of input data sets, followed by the K data sets, each of the following form:

The first line contains three integers h,w,m, the height of the image, the width of the image, and the minimum rectangle size.

Next is a line with a string of 1–26 letters from ‘A’–‘Z’, with no repetitions (but not necessarily sorted). These are the special, water-indicating letters.

This is followed by h lines, each consisting of w upper-case letters (and nothing else), each describing one row of the image.

출력
For each data set, output “Data Set x:” on a line by itself, where x is its number. On the next line, output the maximum density of water-indicating pixels in any m × m or larger rectangle. This should be output as a fraction x/y, where x is the number of water-indicating pixels, and y is the number of total pixels in the maximizing rectangle. If there are multiple rectangles of different sizes giving the same ratio, then output the ratio with the largest number y of pixels in the rectangle. Each data set should be followed by a blank line.

풀이:
제시되는 special 문자의 밀도가 가장 큰 직사각형을 찾는 문제이다.
같은 밀도일 땐 분모가 큰 직사각형을 출력한다.

문제가 조금 애매한데, m x m 보다 사이즈가 작은 직사각형은 제외시켜야 한다.
넓이로 하는 줄 알았으나 가로, 세로가 모두 m 이상인 경우였다.
그리고 각 출력 결과마다 한 칸을 더 띄어야 한다.

맵에 대해 2차원 dp를 구하고, 점을 두 개 잡아 직사각형들의 부분 합을 구해나갔다.
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
int mv1[4] = { 0, 0, 1, -1 };
int mv2[4] = { 1, -1, 0, 0 };
int mv_all1[8] = { 0, 1, 0, -1, -1, -1, 1, 1 };
int mv_all2[8] = { 1, 0, -1, 0 , -1, 1, -1, 1 };

int h, w, m;
int dp[51][51];
bool check[26];
string special;

int main(void) {
	FIO;
	
	int t;
	cin >> t;

	for (int test = 1; test <= t; test++)
	{
		cin >> h >> w >> m >> special;

		fill(&check[0], &check[26], false);
		fill(&dp[0][0], &dp[50][51], 0);

		for (int i = 0; i < special.size(); i++)
		{
			check[special[i] - 'A'] = true;
		}

		for (int i = 1; i <= h; i++)
		{
			string str;
			cin >> str;
			for (int j = 1; j <= w; j++)
			{
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
				if (check[str[j - 1] - 'A']) {
					dp[i][j]++;
				}
			}
		}

		double maxDensity = 0.0;
		int maxY = 0;
		int x = 0;

		for (int x1 = 1; x1 <= h; x1++)
		{
			for (int y1 = 1; y1 <= w; y1++)
			{
				for (int x2 = x1; x2 <= h; x2++)
				{
					for (int y2 = y1; y2 <= w; y2++)
					{
						int height = x2 - x1 + 1;
						int width = y2 - y1 + 1;

						if (width < m || height < m)	continue;

						int cnt = dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1] ;

						double nowDensity = (double)cnt / (double)(width * height);

						if (maxDensity < nowDensity) {
							maxDensity = nowDensity;
							maxY = width * height;
							x = cnt;
						}
						else if (maxDensity == nowDensity) {
							if (maxY < width * height) {
								maxY = width * height;
								x = cnt;
							}
						}
					}
				}
			}
		}

		cout << "Data Set " << test << ":\n";
		cout << x << "/" << maxY << "\n\n";
	}

}