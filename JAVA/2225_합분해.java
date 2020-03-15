/*
문제
0부터 N까지의 정수 K개를 더해서 그 합이 N이 되는 경우의 수를 구하는 프로그램을 작성하시오.

덧셈의 순서가 바뀐 경우는 다른 경우로 센다(1+2와 2+1은 서로 다른 경우). 또한 한 개의 수를 여러 번 쓸 수도 있다.

입력
첫째 줄에 두 정수 N(1 ≤ N ≤ 200), K(1 ≤ K ≤ 200)가 주어진다.

출력
첫째 줄에 답을 1,000,000,000으로 나눈 나머지를 출력한다.

풀이:
dp[만들 수][동전의 개수]
dp[모든 수][1] 은 한 가지 경우밖에 없다.
dp[0][모든 수] = 1 (0은 한 가지밖에 없다.)
dp[현재 수][동전 수] = dp[현재까지][동전 수 - 1] 를 모두 더해준다.
 */
import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static long div = 1000000000;
    public static void main(String[] argc) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        long[][] dp = new long[N + 1][K + 1];

        for (int i = 0; i <= N ; i++) {
            dp[i][1] = 1;
        }
        for (int i = 2; i <= K ; i++) {
            for (int j = 1; j <= N ; j++) {
                for (int k = 0; k <= j ; k++) {
                    dp[0][i - 1] = 1;
                    dp[j][i] = ((dp[j][i] % div) + (dp[k][i - 1] % div)) % div;
                }
            }
        }
        bw.write(Long.toString(dp[N][K] % div));
        bw.flush();
        bw.close();
    }
}