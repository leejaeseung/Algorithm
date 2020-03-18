/*
문제
1부터 34까지 수가 적힌 카드가 충분히 많이 있다. 이들 중 몇 장을 일렬로 늘어놓고, 그 숫자를 차례로 적었다. 예를 들어 아래와 같이 카드가 놓인 경우 숫자를 차례로 적으면 27123이 된다.



나중에, 적어 놓은 것에 맞게 다시 카드를 늘어놓으려고 보니, 방법이 여러 가지일 수 있다는 것을 알았다. 예를 들어 27123의 경우 아래와 같이 여섯 가지 다른 방법이 있다.



카드의 숫자를 차례로 적어 놓은 것이 주어질 때, 위와 같이 그것을 가지고 거꾸로 카드의 배열을 찾으려고 한다. 가능한 카드의 배열이 모두 몇 개인지 구하는 프로그램을 작성하시오.

입력
첫 줄에 카드의 숫자를 차례로 적어 놓은 것이 주어지며, 이것은 최대 40자 이하의 숫자로 이루어진다.

출력
첫 줄에 가능한 카드 배열이 몇 개인지를 출력한다.

풀이:
일의 자리와 십의 자리를 구분하여 dp[][] 배열을 작성한다.
dp[몇 번째 숫자인지][십의 자리 or 일의 자리]
1. 마지막 수가 십의 자리라면(dp[][1]) 뒤에 어떤 숫자를 추가해도 같다.
2. 마지막 수가 일의 자리라면(dp[][0]) 뒤에 숫자가 오면 이전 dp[][0]과 dp[][1]의 합이다.
3. 1~34 사이의 수만 십의 자리가 될 수 있다.
4. 10,20,30 같은 0 이오는 경우를 고려한다.
 */
import java.io.*;

public class Main {

    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String str = br.readLine();
        long[][] dp = new long[str.length()][2];

        dp[0][0] = 1;

        for (int i = 1; i < str.length() ; i++) {
            int prev  = str.charAt(i - 1) - '0';
            int now = str.charAt(i) - '0';

            if(now == 0){
                if(prev * 10 + now <= 34) {
                    dp[i][1] = dp[i - 1][0];
                }
                continue;
            }

            if(prev * 10 + now <= 34){
                dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
                dp[i][1] = dp[i - 1][0];
            }
            else{
                dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
            }
        }
        bw.write(Long.toString(dp[str.length() - 1][0] + dp[str.length() - 1][1]));
        bw.flush();
        bw.close();
    }
}