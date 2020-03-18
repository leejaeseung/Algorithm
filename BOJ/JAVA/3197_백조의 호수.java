/*
   백조의 호수 성공
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	256 MB	5116	1086	528	19.186%
문제
두 마리의 백조가 호수에서 살고 있었다. 그렇지만 두 마리는 호수를 덮고 있는 빙판으로 만나지 못한다.

호수는 가로로 R, 세로로 C만큼의 직사각형 모양이다. 어떤 칸은 얼음으로 덮여있다.

호수는 차례로 녹는데, 매일 물 공간과 접촉한 모든 빙판 공간은 녹는다. 두 개의 공간이 접촉하려면 가로나 세로로 닿아 있는 것만 (대각선은 고려하지 않는다) 생각한다.

아래에는 세 가지 예가 있다.

...XXXXXX..XX.XXX ....XXXX.......XX .....XX..........
....XXXXXXXXX.XXX .....XXXX..X..... ......X..........
...XXXXXXXXXXXX.. ....XXX..XXXX.... .....X.....X.....
..XXXXX..XXXXXX.. ...XXX....XXXX... ....X......XX....
.XXXXXX..XXXXXX.. ..XXXX....XXXX... ...XX......XX....
XXXXXXX...XXXX... ..XXXX.....XX.... ....X............
..XXXXX...XXX.... ....XX.....X..... .................
....XXXXX.XXX.... .....XX....X..... .................
in the beginning   after first day   after second day
백조는 오직 물 공간에서 세로나 가로로만(대각선은 제외한다) 움직일 수 있다.

며칠이 지나야 백조들이 만날 수 있는 지 계산하는 프로그램을 작성한다.

입력
입력의 첫째 줄에는 R과 C가 주어진다. 단, 1 ≤ R, C ≤ 1500.

각 R줄 동안 C만큼의 문자열이 주어진다.

'.'은 물 공간, 'X'는 빙판 공간, 'L'은 백조가 있는 공간으로 나타낸다.

출력
첫째 줄에 문제에서 주어진 걸리는 날을 출력한다.
    풀이 : 1. X면 map 값을 최대값으로 설정하고, 빙판이 아닌 곳을 모두 큐에 담는다.
          2. 큐에 담긴 좌표들을 BFS해가며 상하좌우 값들이 현재 지난 일수 + 1 보다 크면 다음 날에 녹아야 하므로 지난 일수 + 1 로 갱신한다.
          3. cnt를 하루하루 증가시키면 당일 날짜보다 작은 map값은 무시하고 지나가며 BFS한다.
 */
import java.io.*;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    public static boolean[][] visit;
    public static char[][] day;
    public static int[][] map;
    public static int N, M;
    public static int[] mv1 = {-1, 0, 1, 0};
    public static int[] mv2 = {0, 1, 0, -1};
    public static Queue<XY> q = new LinkedList<>();
    public static Queue<XY> q2 = new LinkedList<>();

    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        visit = new boolean[N][M];
        day = new char[N][M];
        map = new int[N][M];

        for (int i = 0; i < N ; i++) {
            String s = br.readLine();
            for (int j = 0; j < M ; j++) {

                if(s.charAt(j) == 'L') {
                    q.offer(new XY(i, j));
                    q2.offer(new XY(i,j));
                    visit[i][j] = true;
                    map[i][j] = 0;
                }
                else if(s.charAt(j) == '.'){
                    q.offer(new XY(i,j));
                    map[i][j] = 0;
                }
                else{
                    map[i][j] = Integer.MAX_VALUE;
                }
            }
        }

        while (!q.isEmpty()){
            update(q.poll());
        }
        visit[q2.peek().x][q2.peek().y] = false;
        map[q2.peek().x][q2.poll().y] = -1;

        System.out.println(BFS());

    }
    public static void update(XY now){

        for (int i = 0; i < 4 ; i++) {
            int next_x = now.x + mv1[i];
            int next_y = now.y + mv2[i];

            if(next_x < 0 || next_x >= N || next_y < 0 || next_y >= M)   continue;

            if(map[next_x][next_y] > map[now.x][now.y] + 1){
                map[next_x][next_y] = map[now.x][now.y] + 1;
                q.offer(new XY(next_x,next_y));
            }
        }
    }
    public static int BFS(){
        Queue<XY> q3 = new LinkedList<>();
        int cnt = 0;

        while(true){

            while(!q2.isEmpty()){
                XY temp = q2.poll();

                for (int i = 0; i < 4 ; i++) {
                    int next_x = temp.x + mv1[i];
                    int next_y = temp.y + mv2[i];

                    if(next_x < 0 || next_x >= N || next_y < 0 || next_y >= M)   continue;

                    if(!visit[next_x][next_y]){
                        if(map[next_x][next_y] == -1)
                            return cnt;
                        if(map[next_x][next_y] <= cnt) {
                            q2.offer(new XY(next_x, next_y));
                            visit[next_x][next_y] = true;
                        }
                        else {
                            q3.offer(new XY(next_x, next_y));
                            visit[next_x][next_y] = true;
                        }
                    }
                }
            }
            cnt++;
            while(!q3.isEmpty()){
                q2.offer(q3.poll());
            }
        }
    }
}

class XY{

    public int x;
    public int y;
    public XY(int x,int y){
        this.x=x;
        this.y=y;
    }
}