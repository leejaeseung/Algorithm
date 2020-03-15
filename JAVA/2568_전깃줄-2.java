import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    public static int N;
    public static int[] value;
    public static int[] trace;
    public static boolean[] check;
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());
        value = new int[500001];
        trace = new int[500001];
        check = new boolean[500001];
        Arrays.fill(trace, -1);
        ArrayList<Integer> dp = new ArrayList<>();

        for (int i = 0; i < N ; i++) {
            st = new StringTokenizer(br.readLine());

            int n1 = Integer.parseInt(st.nextToken());
            int n2 = Integer.parseInt(st.nextToken());

            value[n1] = n2;
            check[n2] = true;
        }

        for (int i = 1; i < 500001 ; i++) {
            if(value[i] == 0)   continue;
            if(dp.isEmpty())    dp.add(value[i]);
            else{
                if(dp.get(dp.size() - 1) >= value[i])
                    lowerBound(dp, 0, dp.size(), value[i]);
                else {
                    trace[value[i]] = dp.get(dp.size() - 1);
                    dp.add(value[i]);
                }
            }
        }
        bw.write(N - dp.size() + "\n");

        int last = dp.get(dp.size() - 1);
        while(last != -1){
            check[last] = false;
            last = trace[last];
        }
        for (int i = 1; i < 500001 ; i++) {
            if(check[value[i]])
                bw.write(i + "\n");
        }

        bw.flush();
        bw.close();
    }
    public static void lowerBound(ArrayList<Integer> list, int s, int e, int v){
        while(s < e){
            int mid = (s + e) / 2;
            if(list.get(mid) >= v){
                e = mid;
            }
            else{
                s = mid + 1;
            }
        }
        if(s >= 1)
            trace[v] = list.get(s - 1);
        list.set(s, v);
    }
}