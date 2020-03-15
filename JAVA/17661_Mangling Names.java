import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static int N, M;
    public static int[][] time;
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int K = Integer.parseInt(br.readLine());

        for (int i = 0; i < K ; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());

            N = Integer.parseInt(st.nextToken());
            M = Integer.parseInt(st.nextToken());

            time = new int[N + 1][N + 1];

            for (int j = 0; j < N + 1 ; j++) {
                st = new StringTokenizer(br.readLine());
                for (int k = 0; k < N + 1 ; k++) {
                    time[j][k] = Integer.parseInt(st.nextToken());
                }
            }

            int res = 0;
            for (int j = 0; j < M ; j++) {
                String now = br.readLine();

                res += sum(now);
            }

            bw.write("Data Set " + (i + 1) + ":\n");
            bw.write(res + "\n\n");
        }
        bw.flush();
        bw.close();
    }
    public static int sum(String s){
        int vowel = 0;
        int cons = 0;

        for (int i = 0; i < s.length() ; i++) {
            if(s.charAt(i) == 'a' || s.charAt(i) == 'e' || s.charAt(i) == 'o' || s.charAt(i) == 'y' || s.charAt(i) == 'i' || s.charAt(i) == 'u')
                vowel++;
            else
                cons++;
        }
        return time[vowel][cons];
    }
}