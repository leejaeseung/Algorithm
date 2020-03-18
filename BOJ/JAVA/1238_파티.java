import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static int N, M, X;
    public static int[][] dist;
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        X = Integer.parseInt(st.nextToken());

        dist = new int[N + 1][N + 1];
        for (int i = 0; i <= N ; i++) {
            for (int j = 0; j <= N ; j++) {
                dist[i][j] = 10000000;
                if(i == j)
                    dist[i][j] = 0;
            }
        }

        for (int i = 0; i < M ; i++) {
            st = new StringTokenizer(br.readLine());

            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            int d = Integer.parseInt(st.nextToken());

            dist[from][to] = d;
        }
        Floid();

        int max = 0;
        for (int i = 1; i <= N ; i++) {
            max = Math.max(max, dist[i][X] + dist[X][i]);
        }

        bw.write(Integer.toString(max));
        bw.flush();
        bw.close();
    }
    public static void Floid(){
        for (int i = 1; i <= N ; i++) {
            for (int j = 1; j <= N ; j++) {
                if(dist[j][i] == 10000000)  continue;
                for (int k = 1; k <= N ; k++) {
                    dist[j][k] = Math.min(dist[j][k], dist[j][i] + dist[i][k]);
                }
            }
        }
    }
}