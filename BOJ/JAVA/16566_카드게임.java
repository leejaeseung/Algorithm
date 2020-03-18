import java.io.*;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    public static int N,M,K;
    public static int[] CL;
    public static boolean[] CLB;
    public static int[] arr;
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        //CL = new int[M];
        //CLB = new boolean[M];
        arr = new int[N + 1];
        st = new StringTokenizer(br.readLine());
        int next = N + 1;
        for (int i = 0; i < M ; i++) {
            int idx = Integer.parseInt(st.nextToken());
            //CL[i] = idx;
            //CLB[i] = true;
            arr[idx] = idx;
        }

        for (int i = N; i > 0 ; i--) {
            if(i == arr[i]){
                next = i;
            }
            else{
                arr[i] = next;
            }
        }

        //Arrays.sort(CL);

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < K ; i++) {
            int index = Integer.parseInt(st.nextToken()) + 1;
            int res = find(index);
            bw.write(res + "\n");
            arr[res] = res + 1;
            /*int search = Arrays.binarySearch(CL, index);

            if(search >= 0 ){
                search++;
                while(!CLB[search]){
                    search++;
                }
                bw.write(CL[search] + "\n");
                CLB[search] = false;
            }
            else{
                search = (search * -1 ) - 1;
                while(!CLB[search]){
                    search++;
                }
                bw.write(CL[search] + "\n");
                CLB[search] = false;
            }*/
        }
        bw.flush();
        bw.close();
    }
    public static int find(int idx){
        if(idx == arr[idx]){
            return idx;
        }
        else{
            return arr[idx] = find(arr[idx]);
        }
    }
}