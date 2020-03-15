/*
문제
여행을 떠난 세준이는 지도를 하나 구하였다. 이 지도는 아래 그림과 같이 직사각형 모양이며 여러 칸으로 나뉘어져 있다. 한 칸은 한 지점을 나타내는데 각 칸에는 그 지점의 높이가 쓰여 있으며, 각 지점 사이의 이동은 지도에서 상하좌우 이웃한 곳끼리만 가능하다.



현재 제일 왼쪽 위 칸이 나타내는 지점에 있는 세준이는 제일 오른쪽 아래 칸이 나타내는 지점으로 가려고 한다. 그런데 가능한 힘을 적게 들이고 싶어 항상 높이가 더 낮은 지점으로만 이동하여 목표 지점까지 가고자 한다. 위와 같은 지도에서는 다음과 같은 세 가지 경로가 가능하다.





지도가 주어질 때 이와 같이 제일 왼쪽 위 지점에서 출발하여 제일 오른쪽 아래 지점까지 항상 내리막길로만 이동하는 경로의 개수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에는 지도의 세로의 크기 M과 가로의 크기 N이 빈칸을 사이에 두고 주어진다. 이어 다음 M개 줄에 걸쳐 한 줄에 N개씩 위에서부터 차례로 각 지점의 높이가 빈 칸을 사이에 두고 주어진다. M과 N은 각각 500이하의 자연수이고, 각 지점의 높이는 10000이하의 자연수이다.

출력
첫째 줄에 이동 가능한 경로의 수 H를 출력한다. 모든 입력에 대하여 H는 10억 이하의 음이 아닌 정수이다.

풀이:
DFS와 DP를 이용한다.
재귀적으로 도착점부터 시작해 (0,0) 까지 DFS를 하는데, 처음 방문한다면 이후 방문할 경로들을 모두 더해주며 재귀 호출한다.
이미 방문했다면 그 점의 dp 값을 그대로 리턴한다.
 */
import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static int N,M;
    public static int[][] map;
    public static int[][] dp;
    public static int[] mv1 = {1,-1,0,0};
    public static int[] mv2 = {0,0,1,-1};

    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        M = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());

        map = new int[M][N];
        dp = new int[M][N];

        for (int i = 0; i < M ; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N ; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
                dp[i][j] = -1;
            }
        }

        bw.write(Integer.toString(DFS(M - 1, N - 1)));
        bw.flush();
        bw.close();
    }
    public static int DFS(int x, int y){
        if(x == 0 && y == 0)
            return 1;

        if(dp[x][y] == -1) {
            dp[x][y] = 0;
            for (int i = 0; i < 4; i++) {
                int next_x = x + mv1[i];
                int next_y = y + mv2[i];

                if(next_x < 0 || next_y < 0 || next_x >= M || next_y >= N)  continue;
                if(map[x][y] < map[next_x][next_y]){
                    dp[x][y] += DFS(next_x, next_y);
                }
            }
        }
        return dp[x][y];
    }
}