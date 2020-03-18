/*
문제
N×M의 행렬로 표현되는 맵이 있다. 맵에서 0은 이동할 수 있는 곳을 나타내고, 1은 이동할 수 없는 벽이 있는 곳을 나타낸다. 한 칸에서 다른 칸으로 이동하려면, 두 칸이 인접해야 한다. 두 칸이 변을 공유할 때, 인접하다고 한다.

각각의 벽에 대해서 다음을 구해보려고 한다.

벽을 부수고 이동할 수 있는 곳으로 변경한다.
그 위치에서 이동할 수 있는 칸의 개수를 세어본다.
입력
첫째 줄에 N(1 ≤ N ≤ 1,000), M(1 ≤ M ≤ 1,000)이 주어진다. 다음 N개의 줄에 M개의 숫자로 맵이 주어진다.

출력
맵의 형태로 정답을 출력한다. 원래 빈 칸인 곳은 0을 출력하고, 벽인 곳은 이동할 수 있는 칸의 개수를 10으로 나눈 나머지를 출력한다.
풀이 : 0 인 곳을 하나의 방으로 생각하고, 0 마다 BFS를 돌면서 각 방의 개수를 세고, room[] 에 해당 방의 개수를 저장합니다. 그리고 0 을 그 방의 인덱스 값으로 바꿉니다.
모든 방을 세준 후, 벽에서는 상하좌우의 방의 개수를 room[]에서 찾고, 중복을 제외하고 모두 더해줍니다.
 */

import java.io.*;
import java.util.*;

public class Main {

    public static int[] mv1 = {0,0,1,-1};
    public static int[] mv2 = {1,-1,0,0};
    public static int[][] map;
    public static int[] room;
    public static int N,M;
    public static int room_index = -1;
    public static int room_cnt = 1;
    public static boolean[][] visit;
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        map = new int[N][M];
        room = new int[N * M + 1];
        visit = new boolean[N][M];
        for (int i = 0; i < N ; i++) {
            String s = br.readLine();
            for (int j = 0; j < M ; j++) {
                map[i][j] = s.charAt(j) - '0';
            }
        }

        for (int i = 0; i < N ; i++) {
            for (int j = 0; j < M ; j++) {
                if(map[i][j] == 0)
                    BFS(new XY(i,j));
            }
        }

        for (int i = 0; i < N ; i++) {
            for (int j = 0; j < M ; j++) {
                if(map[i][j] == 1) {
                    ArrayList<Integer> check = new ArrayList<>();
                    int cnt = 1;

                    for (int k = 0; k < 4 ; k++) {
                        int n_x = i + mv1[k];
                        int n_y = j + mv2[k];

                        if(n_x < 0 || n_y < 0 || n_x >= N || n_y >= M) continue;
                        if(map[n_x][n_y] == 1) continue;
                        if (check.contains(map[n_x][n_y]))
                            continue;
                        if (map[n_x][n_y] < 0) {
                            check.add(map[n_x][n_y]);
                            cnt += room[map[n_x][n_y] * -1];
                        }
                    }
                    bw.write(Integer.toString(cnt % 10));
                    room_cnt++;
                }
                else
                    bw.write(Integer.toString(0));
            }
            bw.write("\n");
            bw.flush();
        }
        bw.close();
    }
    public static void BFS(XY now){
        Queue<XY> q = new LinkedList<>();

        q.offer(now);
        int mycnt = 1;
        visit[now.x][now.y] = true;
        map[now.x][now.y] = room_index;

        while(!q.isEmpty()){
            XY temp = q.poll();

            for (int i = 0; i < 4 ; i++) {
                int next_x = temp.x + mv1[i];
                int next_y = temp.y + mv2[i];

                if(next_x < 0 || next_y < 0 || next_x >= N || next_y >= M) continue;
                if(map[next_x][next_y] == 1) continue;

                if(!visit[next_x][next_y]){
                    visit[next_x][next_y] = true;
                    mycnt++;
                    map[next_x][next_y] = room_index;
                    q.offer(new XY(next_x, next_y));
                }
            }
        }
        room[room_index * -1] = mycnt;
        room_index--;
    }
}

class XY{

    public int x;
    public int y;
    public XY(int x, int y){
        this.x = x;
        this.y = y;
    }
}