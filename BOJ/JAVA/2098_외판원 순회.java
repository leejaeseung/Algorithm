import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static int N;
    public static int[][] cost;
    public static int[][] visit;
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());

        cost = new int[N][N];
        visit = new int[N][1 << N];
        for (int i = 0; i < N ; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N ; j++) {
                cost[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        System.out.println(TSP(0, 1));
    }
    public static int TSP(int now, int visited){
        int ret = visit[now][visited];

        if(visited == (1 << N) - 1)
            //모든 visit 비트가 1 이므로 모든 지점을 방문한 경우이다.
            if(cost[now][0] != 0)
                //다시 처음 지점으로 갈 수 있는지 판별
                return cost[now][0];

        if(ret != 0)
            return ret;

        ret = 1000000000;
        for (int i = 0; i < N ; i++) {
            if((visited & (1 << i)) != 0 || cost[now][i] == 0)   continue;
            //이미 방문했거나, 갈 수 없으면 거른다.

            ret = Math.min(ret, TSP(i, (1 << i) | visited) + cost[now][i]);
        }
        return visit[now][visited] = ret;
    }
}