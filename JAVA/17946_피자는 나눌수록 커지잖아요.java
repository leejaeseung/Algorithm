import java.io.*;

public class Main6 {

    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = Integer.parseInt(br.readLine());
        for (int i = 0; i < T ; i++) {
            int K = Integer.parseInt(br.readLine());
            bw.write(1 + "\n");
        }
        bw.flush();
        bw.close();
    }
}