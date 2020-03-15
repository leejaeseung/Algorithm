import java.io.*;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    public static int N, M;

    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        while(true) {
            StringTokenizer st = new StringTokenizer(br.readLine());

            N = Integer.parseInt(st.nextToken());
            M = Integer.parseInt(st.nextToken());

            if (N == 0 && M == 0)
                break;

            int[] score = new int[10001];

            for (int i = 0; i < N ; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j = 0; j < M ; j++) {
                    score[Integer.parseInt(st.nextToken())]++;
                }
            }
            int max = 0;
            for (int i = 1; i <= 10000 ; i++) {
                max = Math.max(score[i], max);
            }

            PriorityQueue<Integer> pq = new PriorityQueue<>();

            int second = 0;
            for (int i = 1; i <= 10000 ; i++) {
                if(score[i] == max)
                    score[i] = 0;
                second = Math.max(second, score[i]);
            }
            for (int i = 1; i <= 10000 ; i++) {
                if(score[i] == second)
                    pq.offer(i);
            }
            while(!pq.isEmpty())
                bw.write(pq.poll() + " ");
            bw.write("\n");
        }
        bw.flush();
        bw.close();
    }
}