import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {

    public static int N;
    public static int[] value;
    public static ArrayList<Integer> dp;
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());
        dp = new ArrayList<>();
        value = new int[N];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N ; i++) {
            value[i] = Integer.parseInt(st.nextToken());
        }

        dp.add(value[0]);
        for (int i = 1; i < N ; i++) {
            if(dp.get(dp.size() - 1) >= value[i]){
                lowerBound(dp, 0, dp.size(), value[i]);
            }
            else
                dp.add(value[i]);
        }
        System.out.println(dp.size());
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
        //s 가 v 보다 큰 최소의 원소 위치
        list.set(s, v);
    }
}