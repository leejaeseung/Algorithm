/*
문제
n가지 종류의 동전이 있다. 이 동전들을 적당히 사용해서, 그 가치의 합이 k원이 되도록 하고 싶다. 그러면서 동전의 개수가 최소가 되도록 하려고 한다. 각각의 동전은 몇 개라도 사용할 수 있다.

사용한 동전의 구성이 같은데, 순서만 다른 것은 같은 경우이다.

입력
첫째 줄에 n, k가 주어진다. (1 ≤ n ≤ 100, 1 ≤ k ≤ 10,000) 다음 n개의 줄에는 각각의 동전의 가치가 주어진다. 동전의 가치는 100,000보다 작거나 같은 자연수이다. 가치가 같은 동전이 여러 번 주어질 수도 있다.

출력
첫째 줄에 사용한 동전의 최소 개수를 출력한다. 불가능한 경우에는 -1을 출력한다.

풀이:
제곱수의 합(1699) 문제와 비슷하다.
단, 코인이 존재하는지 여부에 따라 구분을 해줘야 한다.
해당 코인이 없으면 즉, dp[i - now_coin] 이 0이면 건너 뛴다.
 */
import java.io.*;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        int[] dp = new int[100001];
        ArrayList<Integer> coin = new ArrayList<>();

        for (int i = 0; i < N ; i++) {
            int co = Integer.parseInt(br.readLine());
            dp[co] = 1;
            if(!coin.contains(co))
                coin.add(co);
        }

        coin.sort(new Comparator<Integer>() {
            @Override
            public int compare(Integer integer, Integer t1) {
                return integer <= t1 ? 1 : -1;
            }
        });

        for (int i = 1; i <= K ; i++) {
            for (int j = 0; j < coin.size() ; j++) {
                int now_coin = coin.get(j);
                if(now_coin >= i)
                    continue;
                if(dp[i] > dp[i - now_coin] + 1 || dp[i] == 0) {
                    if(dp[i - now_coin] == 0 && dp[i] == 0)
                        dp[i] = 0;
                    else if(dp[i - now_coin] != 0)
                        dp[i] = dp[i - now_coin] + 1;
                }
            }
        }
        if(dp[K] != 0)
            bw.write(Integer.toString(dp[K]));
        else
            bw.write(Integer.toString(-1));
        bw.flush();
        bw.close();
    }
}