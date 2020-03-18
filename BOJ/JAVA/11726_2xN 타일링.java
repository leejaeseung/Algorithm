/*
    피보나치 수열과 동일하게 풀이
 */
import java.io.*;

public class Main {

    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N=Integer.parseInt(br.readLine());
        long[] tile=new long[N+1];
        if(N==1)
        bw.write(Integer.toString(1));
        if(N==2)
            bw.write(Integer.toString(2));
        if(N>=3) {
            tile[1]=1;
            tile[2]=2;
            for (int i = 3; i <= N; i++) {
                tile[i] = tile[i - 1] + tile[i - 2];
                tile[i]%=10007;
            }
            bw.write(Long.toString(tile[N]));
        }
        bw.flush();
        bw.close();
    }
}