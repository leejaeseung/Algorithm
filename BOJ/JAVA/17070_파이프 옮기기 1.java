/*

문제
유현이가 새 집으로 이사했다. 새 집의 크기는 N×N의 격자판으로 나타낼 수 있고, 1×1크기의 정사각형 칸으로 나누어져 있다. 각각의 칸은 (r, c)로 나타낼 수 있다. 여기서 r은 행의 번호, c는 열의 번호이고, 행과 열의 번호는 1부터 시작한다. 각각의 칸은 빈 칸이거나 벽이다.

오늘은 집 수리를 위해서 파이프 하나를 옮기려고 한다. 파이프는 아래와 같은 형태이고, 2개의 연속된 칸을 차지하는 크기이다.



파이프는 회전시킬 수 있으며, 아래와 같이 3가지 방향이 가능하다.



파이프는 매우 무겁기 때문에, 유현이는 파이프를 밀어서 이동시키려고 한다. 벽에는 새로운 벽지를 발랐기 때문에, 파이프가 벽을 긁으면 안 된다. 즉, 파이프는 항상 빈 칸만 차지해야 한다.

파이프를 밀 수 있는 방향은 총 3가지가 있으며, →, ↘, ↓ 방향이다. 파이프는 밀면서 회전시킬 수 있다. 회전은 45도만 회전시킬 수 있으며, 미는 방향은 오른쪽, 아래, 또는 오른쪽 아래 대각선 방향이어야 한다.

파이프가 가로로 놓여진 경우에 가능한 이동 방법은 총 2가지, 세로로 놓여진 경우에는 2가지, 대각선 방향으로 놓여진 경우에는 3가지가 있다.

아래 그림은 파이프가 놓여진 방향에 따라서 이동할 수 있는 방법을 모두 나타낸 것이고, 꼭 빈 칸이어야 하는 곳은 색으로 표시되어져 있다.



가로



세로



대각선

가장 처음에 파이프는 (1, 1)와 (1, 2)를 차지하고 있고, 방향은 가로이다. 파이프의 한쪽 끝을 (N, N)로 이동시키는 방법의 개수를 구해보자.

입력
첫째 줄에 집의 크기 N(3 ≤ N ≤ 16)이 주어진다. 둘째 줄부터 N개의 줄에는 집의 상태가 주어진다. 빈 칸은 0, 벽은 1로 주어진다. (1, 1)과 (1, 2)는 항상 빈 칸이다.

출력
첫째 줄에 파이프의 한쪽 끝을 (N, N)으로 이동시키는 방법의 수를 출력한다. 이동시킬 수 없는 경우에는 0을 출력한다. 방법의 수는 항상 1,000,000보다 작거나 같다.
풀이 : dp 를 이용한 풀이
 */
import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static int[][] map;
    public static int N;
    public static int[][][] cost;
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        N = Integer.parseInt(br.readLine());
        map = new int[N + 2][N + 2];
        cost = new int[N + 2][N + 2][3];

        for (int i = 1; i <= N ; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= N ; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        cost[1][2][0] = 1;

        for (int i = 1; i <= N ; i++) {
            for (int j = 1; j <= N ; j++) {
                if(map[i][j + 1] == 0)
                    cost[i][j + 1][0] += cost[i][j][0] + cost[i][j][2];
                if(map[i + 1][j] == 0)
                    cost[i + 1][j][1] += cost[i][j][1] + cost[i][j][2];
                if(map[i + 1][j] == 0 && map[i][j + 1] == 0 && map[i + 1][j + 1] == 0)
                    cost[i + 1][j + 1][2] += cost[i][j][0] + cost[i][j][1] +cost[i][j][2];
            }
        }


        bw.write(Integer.toString(cost[N][N][0] + cost[N][N][1] + cost[N][N][2]));
        bw.flush();
        bw.close();
    }
}
/*
스택을 이용한 풀이
import java.io.*;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

    public static int[][] map;
    public static int N;
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        N = Integer.parseInt(br.readLine());
        map = new int[N + 1][N + 1];

        for (int i = 1; i <= N ; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= N ; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        bw.write(Integer.toString(BFS()));
        bw.flush();
        bw.close();
    }
    public static int BFS(){
        Stack<XY> q = new Stack<>();
        q.push(new XY(1,2, 1));
        int cnt = 0;

        while(!q.isEmpty()){
            XY now = q.pop();

            if(now.x == N && now.y == N)
                cnt++;

            if(now.state == 1){
                if(now.y + 1 <= N && map[now.x][now.y + 1] == 0)
                    q.push(forward(now.x, now.y, 1));
                if(now.y + 1 <= N && now.x + 1 <= N && map[now.x][now.y + 1] == 0 && map[now.x + 1][now.y] == 0 && map[now.x + 1][now.y + 1] == 0)
                    q.push(down(now.x, now.y, 1));
            }
            else if(now.state == 2){
                if(now.x + 1 <= N && map[now.x + 1][now.y] == 0)
                    q.push(forward(now.x, now.y, 2));
                if(now.y + 1 <= N && now.x + 1 <= N && map[now.x][now.y + 1] == 0 && map[now.x + 1][now.y] == 0 && map[now.x + 1][now.y + 1] == 0)
                    q.push(right(now.x, now.y, 2));
            }
            else{
                if(now.y + 1 <= N && now.x + 1 <= N && map[now.x][now.y + 1] == 0 && map[now.x + 1][now.y] == 0 && map[now.x + 1][now.y + 1] == 0)
                    q.push(forward(now.x, now.y, 3));
                if(now.x + 1 <= N && map[now.x + 1][now.y] == 0)
                    q.push(down(now.x, now.y, 3));
                if(now.y + 1 <= N && map[now.x][now.y + 1] == 0)
                    q.push(right(now.x, now.y, 3));
            }
        }
        return cnt;
    }
    public static XY forward(int now_x, int now_y, int state){
        if(state == 1){
            return new XY(now_x, now_y + 1, state);
        }
        else if( state == 2 ){
            return new XY(now_x + 1, now_y, state);
        }
        else{
            return new XY(now_x + 1, now_y + 1, state);
        }
    }
    public static XY right(int now_x, int now_y, int state){
        if( state == 2 ){
            return new XY(now_x + 1, now_y + 1, 3);
        }
        else{
            return new XY(now_x, now_y + 1, 1);
        }
    }
    public static XY down(int now_x, int now_y, int state){
        if(state == 1){
            return new XY(now_x + 1, now_y + 1, 3);
        }
        else{
            return new XY(now_x + 1, now_y, 2);
        }
    }
}

class XY{

    public int x;
    public int y;
    public int state;               //1 가로 2 세로 3 대각
    public XY(int x, int y, int state){
        this.x = x;
        this.y = y;
        this.state = state;
    }
}*/