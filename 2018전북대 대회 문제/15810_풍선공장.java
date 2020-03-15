import java.io.*;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    public static int N, M;
    public static long[] dp;
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        PriorityQueue<tuple> pq = new PriorityQueue<>(new Comparator<tuple>() {
            @Override
            public int compare(tuple tuple, tuple t1) {
                return tuple.value * tuple.origin >= t1.value * t1.origin ? 1 : -1;
            }
        });
        dp = new long[1000001];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N ; i++) {
            int n = Integer.parseInt(st.nextToken());
            pq.offer(new tuple(n, 1));
        }
        for (int i = 1; i <= M ; i++) {
            tuple temp = pq.poll();
            dp[i] = temp.value * temp.origin;
            pq.offer(new tuple(temp.origin, temp.value + 1));
        }
        System.out.println(dp[M]);
    }
}
class tuple{
    long origin;
    long value;
    public tuple(long origin, long value){
        this.origin = origin;
        this.value = value;
    }
}