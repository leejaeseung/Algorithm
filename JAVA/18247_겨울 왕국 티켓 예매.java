import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = Integer.parseInt(br.readLine());

        for (int i = 0; i < T ; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            int M = Integer.parseInt(st.nextToken());

            if(M < 4 || N < 12){
                bw.write(-1 + "\n");
                bw.flush();
                continue;
            }
            else{
                bw.write((M * 11) + 4 + "\n");
                bw.flush();
            }
        }
        bw.close();
    }
}
