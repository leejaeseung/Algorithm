/*
문제
n(1 ≤ n ≤ 100)개의 도시가 있다. 그리고 한 도시에서 출발하여 다른 도시에 도착하는 m(1 ≤ m ≤ 100,000)개의 버스가 있다. 각 버스는 한 번 사용할 때 필요한 비용이 있다.

모든 도시의 쌍 (A, B)에 대해서 도시 A에서 B로 가는데 필요한 비용의 최솟값을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 도시의 개수 n(1 ≤ n ≤ 100)이 주어지고 둘째 줄에는 버스의 개수 m(1 ≤ m ≤ 100,000)이 주어진다. 그리고 셋째 줄부터 m+2줄까지 다음과 같은 버스의 정보가 주어진다. 먼저 처음에는 그 버스의 출발 도시의 번호가 주어진다. 버스의 정보는 버스의 시작 도시 a, 도착 도시 b, 한 번 타는데 필요한 비용 c로 이루어져 있다. 시작 도시와 도착 도시가 같은 경우는 없다. 비용은 100,000보다 작거나 같은 자연수이다.

시작 도시와 도착 도시를 연결하는 노선은 하나가 아닐 수 있다.

출력
N개의 줄을 출력해야 한다. i번째 줄에 출력하는 j번째 숫자는 도시 i에서 j로 가는데 필요한 최소 비용이다. 만약, i에서 j로 갈 수 없는 경우에는 그 자리에 0을 출력한다.
    풀이 :
    처음엔 다익스트라로 해보았지만 실패함.
    플로이드-와샬 알고리즘 그대로 구현.
 */
import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static long[][] city;
    public static int N;
    public static long MAX = 999999999;

    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        N = Integer.parseInt(br.readLine());

        city = new long[N][N];

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                    city[i][j] = MAX;
            }
        }
        int M = Integer.parseInt(br.readLine());

        for (int i = 0; i < M; i++) {
            String s = br.readLine();
            StringTokenizer st = new StringTokenizer(s);

            int from = Integer.parseInt(st.nextToken()) - 1;
            int to = Integer.parseInt(st.nextToken()) - 1;
            long cost = Long.parseLong(st.nextToken());
            city[from][to] = Math.min(city[from][to], cost);
        }
        for (int i = 0; i < N; i++) {
            update(i);
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (city[i][j] == MAX)
                    city[i][j] = 0;
                bw.write(city[i][j] + " ");
            }
            bw.write("\n");
        }
        bw.flush();
        bw.close();
    }

    public static void update(int stay) {                                               //플로이드-와샬
        for (int i = (stay + 1) % N; i!=stay; i = (i + 1) % N) {
            for (int j = (i + 1) % N; j!=i; j = (j + 1) % N) {
                if(j==stay)
                    continue;
                    city[i][j] = Math.min(city[i][j], city[i][stay] + city[stay][j]);
            }
        }
    }

    /*public static void update(int from) {                                             //다익스트라로 시도-실패
        boolean[] visit=new boolean[N];
        visit[from]=true;
        int now=from;
        int count=0;
        for (int i = (from + 1) % N; count!=N; i = (i + 1) % N) {
            if(!connected[now][i]) {
                count++;
                continue;
            }
            visit[i]=true;
            int cnt=0;
                for (int j = (i + 1) % N; cnt!=N; j = (j + 1) % N) {
                    cnt++;
                    if (connected[i][j]&&!visit[j]) {
                        city[from][j] = Math.min(city[from][j], city[from][i] + city[i][j]);
                    }
                }
                now=i;
                count++;
        }
    }*/
}