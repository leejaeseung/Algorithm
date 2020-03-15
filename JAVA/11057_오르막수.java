import java.io.*;

public class Main {

    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());
        int[][] dp = new int[1001][10];
        int div = 10007;

        for (int i = 0; i < 10 ; i++) {
            dp[1][i] = 1;
        }

        for (int i = 2; i < 1001 ; i++) {
            for (int j = 0; j < 10 ; j++) {
                for (int k = 0; k <= j ; k++) {
                    dp[i][j] = ((dp[i][j] % div) + (dp[i - 1][k] % div)) % div;
                }
            }
        }
        int sum = 0;
        for (int i = 0; i < 10 ; i++) {
            sum = ((sum % div) + (dp[N][i] % div)) % div;
        }
        System.out.println(sum);
    }
}