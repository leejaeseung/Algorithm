import java.io.*;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    public static int N, M;
    public static int[][] map;
    public static int[] mv1 = {0,0,1,-1};
    public static int[] mv2 = {-1,1,0,0};
    public static int city = 0;
    public static ArrayList<XY> startP = new ArrayList<>();
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        map = new int[N][M];

        for (int i = 0; i < N ; i++) {
            String s = br.readLine();
            for (int j = 0; j < M ; j++) {
                map[i][j] = s.charAt(j) - '0';
                if(map[i][j] == 1)
                    city++;
                else
                    startP.add(new XY(i, j));
            }
        }
        int res = 1000000000;
        for (int i = 0; i < startP.size() - 1 ; i++) {
            for (int j = i + 1; j < startP.size() ; j++) {
                    res = Math.min(res, BFS(startP.get(i), startP.get(j)));
            }
        }
        System.out.println(res);
    }
    public static int BFS(XY start1, XY start2){
        Queue<XY> q = new LinkedList<>();
        boolean[][] visit = new boolean[N][M];

        int cnt = 0;
        int now_city = 0;
        visit[start1.x][start1.y] = true;
        q.offer(start1);
        visit[start2.x][start2.y] = true;
        q.offer(start2);

        while(!q.isEmpty()){
            int size = q.size();

            for (int i = 0; i < size ; i++) {
                XY now = q.poll();

                if(map[now.x][now.y] == 1){
                    now_city++;
                    if(city == now_city)
                        return cnt;
                }

                for (int j = 0; j < 4 ; j++) {
                    int next_x = now.x + mv1[j];
                    int next_y = now.y + mv2[j];

                    if(next_x < 0 || next_y < 0 || next_x >= N || next_y >= M)  continue;

                    if(!visit[next_x][next_y]){
                        visit[next_x][next_y] = true;
                        q.offer(new XY(next_x, next_y));
                    }
                }
            }
            cnt++;
        }
        return cnt;
    }
}

class XY{
    int x;
    int y;
    public XY(int x, int y){
        this.x = x;
        this.y = y;
    }
}