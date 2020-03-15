import java.io.*;
import java.util.StringTokenizer;

public class Main4 {

    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int T = Integer.parseInt(st.nextToken());

        int arm = 1;
        int cnt = 1;
        int p = -1;

        while(cnt != T){
            if(arm == 2 * N || arm == 1)
                p *= -1;
            arm += p;
            cnt++;
        }
        System.out.println(arm);
    }
}