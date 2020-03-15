/*
문제
어떤 동물원에 가로로 두칸 세로로 N칸인 아래와 같은 우리가 있다.



이 동물원에는 사자들이 살고 있는데 사자들을 우리에 가둘 때, 가로로도 세로로도 붙어 있게 배치할 수는 없다. 이 동물원 조련사는 사자들의 배치 문제 때문에 골머리를 앓고 있다.

동물원 조련사의 머리가 아프지 않도록 우리가 2*N 배열에 사자를 배치하는 경우의 수가 몇 가지인지를 알아내는 프로그램을 작성해 주도록 하자. 사자를 한 마리도 배치하지 않는 경우도 하나의 경우의 수로 친다고 가정한다.

입력
첫째 줄에 우리의 크기 N(1≤N≤100,000)이 주어진다.

출력
첫째 줄에 사자를 배치하는 경우의 수를 9901로 나눈 나머지를 출력하여라.

풀이:
가장 아래가 (0,1), (0,0), (1,0) 인 경우로 나눠서 생각한다.
위 경우들은 이전 경우(i - 1)의 (0,1), (0,0), (1,0) 의 개수에 따라 결정된다.
 */
import java.io.*;

public class Main {

    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());
        int[][] dp = new int[N][3];
        int div = 9901;

        dp[0][0] = 1;   //0,1
        dp[0][1] = 1;   //0,0
        dp[0][2] = 1;   //1,0

        for (int i = 1; i < N ; i++) {
            dp[i][0] = ((dp[i - 1][1] % div) + (dp[i - 1][2] % div)) % div;
            dp[i][1] = ((dp[i - 1][0] % div) + (dp[i - 1][1] % div) + (dp[i - 1][2] % div)) % div;
            dp[i][2] = ((dp[i - 1][0] % div) + (dp[i - 1][1] % div)) % div;
        }

        bw.write(Integer.toString(((dp[N - 1][0] % div) + (dp[N - 1][1] % div) + (dp[N - 1][2] % div)) % div));
        bw.flush();
        bw.close();
    }
}