import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {

    public static int N;
    public static int[] value;
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());
        value = new int[501];
        ArrayList<Integer> dp = new ArrayList<>();

        for (int i = 0; i < N ; i++) {
            st = new StringTokenizer(br.readLine());

            int n1 = Integer.parseInt(st.nextToken());
            int n2 = Integer.parseInt(st.nextToken());

            value[n1] = n2;
        }

        for (int i = 1; i < 501 ; i++) {
            if(value[i] == 0)   continue;
            if(dp.isEmpty())    dp.add(value[i]);
            else{
                if(dp.get(dp.size() - 1) >= value[i])
                    lowerBound(dp, 0, dp.size(), value[i]);
                else
                    dp.add(value[i]);
            }
        }
        System.out.println(N - dp.size());
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
        list.set(s, v);
    }
}