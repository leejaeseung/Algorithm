/*
문제
많은 공장에서 로봇이 이용되고 있다. 우리 월드 공장의 로봇은 바라보는 방향으로 궤도를 따라 움직이며, 움직이는 방향은 동, 서, 남, 북 가운데 하나이다. 로봇의 이동을 제어하는 명령어는 다음과 같이 두 가지이다.

명령 1. Go k
  - k는 1, 2 또는 3일 수 있다. 현재 향하고 있는 방향으로 k칸 만큼 움직인다.

명령 2. Turn dir
  - dir은 left 또는 right 이며, 각각 왼쪽 또는 오른쪽으로 90° 회전한다.

공장 내 궤도가 설치되어 있는 상태가 아래와 같이 0과 1로 이루어진 직사각형 모양으로 로봇에게 입력된다. 0은 궤도가 깔려 있어 로봇이 갈 수 있는 지점이고, 1은 궤도가 없어 로봇이 갈 수 없는 지점이다. 로봇이 (4, 2) 지점에서 남쪽을 향하고 있을 때,  이 로봇을 (2, 4) 지점에서 동쪽으로 향하도록 이동시키는 것은 아래와 같이 9번의 명령으로 가능하다.



로봇의 현재 위치와 바라보는 방향이 주어졌을 때, 로봇을 원하는 위치로 이동시키고, 원하는 방향으로 바라보도록 하는데 최소 몇 번의 명령이 필요한지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 공장 내 궤도 설치 상태를 나타내는 직사각형의 세로 길이 M과 가로 길이 N이 빈칸을 사이에 두고 주어진다. 이때 M과 N은 둘 다 100이하의 자연수이다. 이어 M줄에 걸쳐 한 줄에 N개씩 각 지점의 궤도 설치 상태를 나타내는 숫자 0 또는 1이 빈칸을 사이에 두고 주어진다. 다음 줄에는 로봇의 출발 지점의 위치 (행과 열의 번호)와 바라보는 방향이 빈칸을 사이에 두고 주어진다. 마지막 줄에는 로봇의 도착 지점의 위치 (행과 열의 번호)와 바라보는 방향이 빈칸을 사이에 두고 주어진다. 방향은 동쪽이 1, 서쪽이 2, 남쪽이 3, 북쪽이 4로 주어진다. 출발지점에서 도착지점까지는 항상 이동이 가능하다.

출력
첫째 줄에 로봇을 도착 지점에 원하는 방향으로 이동시키는데 필요한 최소 명령 횟수를 출력한다.

풀이:
visit 배열에 방향값을 추가하여 방문 여부를 판단해가며 BFS한다.(visit[x][y][동서남북])
단, 바라보는 방향으로 전진할 때 1,2,3칸을 갈 수 있으므로 매번 벽이 있는지 확인해준다.
1칸째에 벽이 있으면 2,3칸을 모두 못 가므로 break해주고, 2칸때에 벽이 있으면 3칸을 못 가므로 break해준다.
제자리에서 방향을 바꿀 땐 90도는 카운트 + 1, 180도는 카운트 + 2를 해준다.
 */
import java.io.*;
import java.util.*;

public class Main {

    public static int[][] map;
    public static boolean[][][] visit;
    public static int[] mv1 = {1, -1, 0, 0};
    public static int[] mv2 = {0, 0, 1, -1};
    public static int N,M;
    public static XY start, end;
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        M = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());
        map = new int[M + 1][N + 1];
        visit = new boolean[M + 1][N + 1][5];

        for (int i = 1; i <= M ; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= N ; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        st = new StringTokenizer(br.readLine());
        start = new XY(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()), 0);
        st = new StringTokenizer(br.readLine());
        end = new XY(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()), 0);

        bw.write(Integer.toString(BFS()));
        bw.flush();
        bw.close();
    }
    public static int BFS(){
        Queue<XY> q = new LinkedList<>();
        visit[start.x][start.y][start.dir] = true;
        q.offer(start);

        while (!q.isEmpty()){
            XY now = q.poll();

                if(now.x == end.x && now.y == end.y && now.dir == end.dir)
                    return now.cnt;

            for (int i = 1; i <= 3; i++) {
                int next_x = now.x + mv2[now.dir - 1] * i;
                int next_y = now.y + mv1[now.dir - 1] * i;

                if(next_x < 1 || next_y < 1 || next_x > M || next_y > N)    continue;
                if(map[next_x][next_y] == 1)    break;
                if(!visit[next_x][next_y][now.dir]){
                    visit[next_x][next_y][now.dir] = true;
                    q.offer(new XY(next_x, next_y, now.dir, now.cnt + 1));
                }
            }
                
                for (int i = 1; i <= 4; i++) {
                    if(now.dir != i && !visit[now.x][now.y][i]){
                        int add = 1;
                        if(now.dir == 1){
                            if(i == 2) ++add;
                        }
                        else if(now.dir == 2){
                            if(i == 1) ++add;
                        }
                        else if(now.dir == 3){
                            if(i == 4) ++add;
                        }
                        else{
                            if(i == 3) ++add;
                        }
                        visit[now.x][now.y][i] = true;
                        q.offer(new XY(now.x, now.y, i, now.cnt + add));
                    }
                }
        }
        return 0;
    }
    public static int turnRight(int dir){
        if(dir == 1 || dir == 2)
            return dir + 2;
        else if(dir == 3)
            return 2;
        else
            return 1;
    }
    public static int turnLeft(int dir){
        if(dir == 3 || dir == 4)
            return dir - 2;
        else if(dir == 2)
            return 3;
        else
            return 4;
    }
}

class XY{
    int x;
    int y;
    int dir;
    int cnt;
    public XY(int x, int y, int dir, int cnt){
        this.x = x;
        this.y = y;
        this.dir = dir;
        this.cnt = cnt;
    }
}