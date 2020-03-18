import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int L = Integer.parseInt(st.nextToken());

        int[] answer = new int[N];
        int[] value = new int[N];
        ArrayDeque<Integer> dq = new ArrayDeque<>();

        st = new StringTokenizer(br.readLine());

        for (int i = 0; i < N ; i++) {
            value[i] = Integer.parseInt(st.nextToken());

            while (!dq.isEmpty() && value[dq.getLast()] > value[i]) {
                dq.pollLast();
            }

            dq.offer(i);
            if(dq.peekFirst() <= i - L)
                dq.pollFirst();

            answer[i] = value[dq.peekFirst()];
        }
        for (int i = 0; i < N ; i++) {
            bw.write(Integer.toString(answer[i]));
            bw.write(" ");
        }
        bw.flush();
        bw.close();
    }
}