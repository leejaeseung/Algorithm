/*
문제
여러 개의 소국가로 나뉘어져 있었던 A국을 다시 하나의 국가로 합치기 위해 각 소국가의 대표 N명이 원탁에 모였다.

각 대표는 미리 원탁의 자리를 배정받았다. 회의를 시작하기 전에 일단 서로 악수를 하려고 한다. 각 대표는 한 사람과만 악수할수 있고, 모든 악수는 동시에 일어난다. 이때, 어떤 사람의 팔도 교차하지 않았을 때 완벽하게 악수했다고 한다.

N이 주어지면 완벽하게 악수하는 경우의 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 정상 회담에 참가한 사람의 수 N이 주어진다. 이 값은 10,000보다 작거나 같은 짝수이다.

출력
완벽한 악수의 경우의 수를 987654321로 나눈 나머지를 출력한다.

풀이:
한 점을 기준으로 인접한 두 점, 그리고 두 칸씩 뛰어가며 영역을 두 개로 나누어준다고 생각한다.
그럼 총 N / 2 번 연산을 하는데, 각 영역의 경우의 수들의 곱의 합이 총 경우의 수이다.
 */
import java.io.*;

public class Main {

    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());
        int div = 987654321;

        long[] dp = new long[N + 1];

        dp[0] = 1;
        dp[2] = 1;

            for (int i = 4; i <= N; i += 2) {
                for (int j = 0; j <= i - 2 ; j += 2) {
                    dp[i] += ((dp[j] % div) * (dp[i - j - 2] % div)) % div;
                }
            }
            bw.write(Long.toString(dp[N] % div));
        bw.flush();
        bw.close();
    }
}