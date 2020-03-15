/*
문제
윤영이는 3의 배수 마니아이다. 그는 모든 자연수를 3개의 3의 배수의 자연수로 분해하는 것을 취미로 가지고 있다. 문득 그는 자신에게 주어진 수를 3개의 3의 배수로 분리하는 경우의 수가 몇 개인지 궁금해졌다. 하지만 윤영이는 마지막 학기이기 때문에 이런 계산을 하기에는 너무 게을러졌다. 그래서 당신에게 이 계산을 부탁했다.

즉, 임의의 3의 배수 자연수 n이 주어졌을 때, 해당 수를 3의 배수의 자연수 3개로 분리하는 방법의 개수를 출력해라. 단 분해한 수의 순서가 다르면 다른 방법으로 간주한다. 예를 들어 12 = 3 + 6 + 3 과 12 = 3 + 3 + 6 은 다른 방법이다.

입력
임의의 3의 배수 자연수 n이 주어진다. (3 ≤ n ≤ 3000)

출력
자연수 n을 분해하는 방법의 개수를 출력하라.

풀이 : 계차 수열 문제. 1 3 6 10 15 의 규칙이다.
 */

import java.io.*;

public class Main {

    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());
        int[] dp = new int[1001];

        dp[1] = 1;
        int plus = 2;
        for (int i = 2; i < 1001 ; i++) {
            dp[i] = dp[i - 1] + plus;
            plus++;
        }
        if(N >= 9)
            bw.write(Integer.toString(dp[N / 3 - 2]));
        else
            bw.write(Integer.toString(0));
        bw.flush();
        bw.close();
    }
}