import java.io.*;
import java.util.*;

public class Main {

    public static int N, T;

    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int K = Integer.parseInt(br.readLine());

        for (int i = 0; i < K ; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            T = Integer.parseInt(st.nextToken());

            int[] capSize = new int[1001];
            Arrays.fill(capSize, -2);

            st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= N ; j++) {
                capSize[Integer.parseInt(st.nextToken())] = 2;
            }

            boolean impo = false;
            int cnt = 0;
            int p_idx = 0;
            for (int j = 0; j < T ; j++) {
                st = new StringTokenizer(br.readLine());
                int c = Integer.parseInt(st.nextToken());
                int f = Integer.parseInt(st.nextToken());

                if(capSize[c] == 2)
                    capSize[c] = f;
                else if(capSize[c] == f)
                    continue;
                else
                    impo = true;
            }
            bw.write("Data Set " + (i + 1) + ":\n");

            if(!impo) {
                int largeIdx = -1;
                int smallIdx = 1001;
                int fit_cnt = 0;

                for (int j = 0; j <= 1000; j++) {
                    if(capSize[j] == 1)
                        largeIdx = Math.max(largeIdx, j);
                    if(capSize[j] == -1)
                        smallIdx = Math.min(smallIdx, j);
                    if(capSize[j] == 0) {
                        fit_cnt++;
                        p_idx = j;
                    }
                }

                if(fit_cnt == 0) {

                    if(largeIdx < smallIdx){
                        for (int j = largeIdx + 1; j < smallIdx ; j++) {
                            if(capSize[j] == -2)    continue;
                            cnt++;
                        }
                    }
                    else
                        impo = true;
                }
                else if(fit_cnt == 1){
                    cnt = 1;
                    if(p_idx >= smallIdx || p_idx <= largeIdx)
                        impo = true;
                }
                else
                    impo = true;

                if(!impo)
                    bw.write(cnt + "\n\n");
                else
                    bw.write("Inconsistent feedback\n\n");
            }
            else
                bw.write("Inconsistent feedback\n\n");
        }
        bw.flush();
        bw.close();
    }
}