/*
문제
수열 A가 주어졌을 때, 그 수열의 증가 부분 수열 중에서 합이 가장 큰 것을 구하는 프로그램을 작성하시오.

예를 들어, 수열 A = {1, 100, 2, 50, 60, 3, 5, 6, 7, 8} 인 경우에 합이 가장 큰 증가 부분 수열은 A = {1, 100, 2, 50, 60, 3, 5, 6, 7, 8} 이고, 합은 113이다.

입력
첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000)이 주어진다.

둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000)

출력
첫째 줄에 수열 A의 합이 가장 큰 증가 부분 수열의 합을 출력한다.

풀이:
dp[i] 는 i번째 수 까지의 가장 큰 증가 부분 수열이다.
먼저, dp를 numbers와 같이 초기화를 하고 시작한다.
dp를 하나하나 새로 업데이트하며 진행하는데, i번째를 업데이트할 때 i - 1까지의 dp와 비교하며 업데이트한다.
i번째 수보다 크거나 같은 수가 나오면 증가하지 않으므로 무시하고, 아니라면 최댓값을 저장한다.
저장한 최댓값을 dp[i]에 업데이트한다.(dp[i]와 더한다.)
 */
import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static int N;
    public static int[] numbers;
    public static int[] dp;
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        dp = new int[N];
        numbers = new int[N];
        for (int i = 0; i < N ; i++) {
            numbers[i] = Integer.parseInt(st.nextToken());
            dp[i] = numbers[i];
        }

        int res = 0;
        for (int i = 0; i < N ; i++) {
            int max = 0;
            int j;
            for (j = 0; j < i  ; j++) {
                if(numbers[j] >= dp[i])  continue;
                max = Math.max(dp[j], max);
            }
            dp[j] = max + numbers[i];
            res = Math.max(dp[j], res);
        }

        bw.write(Integer.toString(res));
        bw.flush();
        bw.close();
    }
}