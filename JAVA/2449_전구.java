/*
문제
최대 K가지의 서로 다른 색을 표현할 수 있는 전구들이 있다. 이 전구 N개를 다음의 그림과 같이 한 줄로 배치하여 서로 연결한다. (동그라미 안의 숫자는 전구의 색을 의미한다)



각 전구는 스위치가 있어서 전구의 색을 임의의 색으로 바꿀 수 있다. 하나의 전구 색을 바꾸는 경우에는, 색이 바뀌는 전구에 인접한 전구가 같은 색이면, 이 전구의 색도 같이 바뀌게 되며 인접한 전구가 다른 색이 나올 때까지 계속 바뀌게 된다. 예를 들어, 위의 그림에서 4번 전구의 색을 2번 색으로 바꾸면, 5번 전구가 4번 전구와 같은 색이었으므로 2번 색으로 바뀌고, 6번 전구도 5번 전구와 같은 색이었으므로 2번 색으로 바뀌게 된다. 즉, 4번 전구의 색을 2번 색으로 바꾸면, 연결된 같은 색의 모든 전구인 4, 5, 6번의 전구가 2번 색으로 바뀌게 되어 아래의 그림과 같이 된다.



전구의 수 N과 N개의 전등에 대한 초기 색이 주어질 때, 모든 전구의 색이 하나로 같아질 때까지 최소 몇 번 전구의 색을 바꾸어야 하는지를 구하는 프로그램을 작성하시오. 단, 전구의 각 색은 1부터 K까지의 정수로 나타낸다.

입력
입력의 첫 번째 줄에는 전구의 수를 나타내는 양의 정수 N과 전구가 표현할 수 있는 색의 수 K가 주어진다. 단, N은 1이상 200이하의 정수이며, K는 1이상 20이하의 정수이다. 두 번째 줄에는 N개 전구의 색이 전구번호의 순서대로 하나의 정수로 하나의 빈칸을 사이에 두고 주어진다.

출력
첫째 줄에 모든 전구의 색이 하나로 같아질 때까지 전구의 색을 바꾸는 횟수의 최솟값을 하나의 정수로 출력한다.

풀이:
공부중
 */
import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static int N, K;
    public static int[][] dp;
    public static int[] list;
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        list = new int[N];
        dp = new int[N][N];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N ; i++) {
            list[i] = Integer.parseInt(st.nextToken());
        }
        for (int i = 0; i < N ; i++) {
            for (int j = i - 1; j >= 0 ; j--) {
                dp[j][i] = 1000000000;
                for (int k = j; k < i ; k++) {
                    if(list[j] != list[k + 1])
                        dp[j][i] = Math.min(dp[j][i], dp[j][k] + dp[k + 1][i] + 1);
                    else
                        dp[j][i] = Math.min(dp[j][i], dp[j][k] + dp[k + 1][i]);
                }
            }
        }

        System.out.println(dp[0][N - 1]);
    }
}