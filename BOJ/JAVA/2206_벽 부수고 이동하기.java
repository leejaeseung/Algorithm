/*
문제
N×M의 행렬로 표현되는 맵이 있다. 맵에서 0은 이동할 수 있는 곳을 나타내고, 1은 이동할 수 없는 벽이 있는 곳을 나타낸다. 당신은 (1, 1)에서 (N, M)의 위치까지 이동하려 하는데, 이때 최단 경로로 이동하려 한다. 최단경로는 맵에서 가장 적은 개수의 칸을 지나는 경로를 말하는데, 이때 시작하는 칸과 끝나는 칸도 포함해서 센다.

만약에 이동하는 도중에 한 개의 벽을 부수고 이동하는 것이 좀 더 경로가 짧아진다면, 벽을 한 개 까지 부수고 이동하여도 된다.

맵이 주어졌을 때, 최단 경로를 구해 내는 프로그램을 작성하시오.

입력
첫째 줄에 N(1 ≤ N ≤ 1,000), M(1 ≤ M ≤ 1,000)이 주어진다. 다음 N개의 줄에 M개의 숫자로 맵이 주어진다. (1, 1)과 (N, M)은 항상 0이라고 가정하자.

출력
첫째 줄에 최단 거리를 출력한다. 불가능할 때는 -1을 출력한다.

풀이:
BFS를 돌 때 현재 벽을 깼는지 안 깼는지에 대한 visit을 추가로 만들어 탐색한다.(isBreak 가 1이면 벽을 깨고옴)
 */
import java.io.*;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    public static int N, M;
    public static int[][] map;
    public static boolean[][][] visit;
    public static int[] mv1 = {0,0,1,-1};
    public static int[] mv2 = {1,-1,0,0};
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        map = new int[N][M];
        visit = new boolean[N][M][2];

        for (int i = 0; i < N ; i++) {
            String str = br.readLine();
            for (int j = 0; j < M ; j++) {
                map[i][j] = str.charAt(j) - '0';
            }
        }
        System.out.println(BFS());

    }
    public static int BFS(){
        Queue<XY> q = new LinkedList<>();

        q.offer(new XY(0, 0, 0, 1));
        visit[0][0][0] = true;

        while(!q.isEmpty()){
            XY now = q.poll();

            if(now.x == N - 1 && now.y == M - 1)
                return now.cnt;

            for (int i = 0; i < 4 ; i++) {
                int next_x = now.x + mv1[i];
                int next_y = now.y + mv2[i];

                if(next_x < 0 || next_y < 0 || next_x >= N || next_y >= M)  continue;
                if(map[next_x][next_y] == 1 && now.isBreak == 1) continue;
                if(!visit[next_x][next_y][now.isBreak]){
                    visit[next_x][next_y][now.isBreak] = true;

                    if(map[next_x][next_y] == 1)
                        q.offer(new XY(next_x, next_y, 1, now.cnt + 1));
                    else
                        q.offer(new XY(next_x, next_y, now.isBreak, now.cnt + 1));
                }
            }
        }
        return -1;
    }
}

class XY{
    int x;
    int y;
    int isBreak;
    int cnt;
    public XY(int x, int y, int isBreak, int cnt){
        this.x = x;
        this.y = y;
        this.isBreak = isBreak;
        this.cnt = cnt;
    }
}