/*
문제
두 개의 자연수를 입력받아 최대 공약수와 최소 공배수를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에는 두 개의 자연수가 주어진다. 이 둘은 10,000이하의 자연수이며 사이에 한 칸의 공백이 주어진다.

출력
첫째 줄에는 입력으로 주어진 두 수의 최대공약수를,둘째 줄에는 입력으로 주어진 두 수의 최소 공배수를 출력한다.

풀이:
유클리드 호제법 = a 와 b를 나눈 나머지 r 에서, a 와 b 의 최대 공약수는 b 와 r의 최대 공약수와 같다.
최소공배수 = 상대 수를 최대 공약수로 나눈 값을 곱해주면 된다.
 */
import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());

        int gcd = gcd(a, b);

        System.out.println(gcd);
        System.out.println(a * (b / gcd));
    }
    public static int gcd(int div, int remain){
        while(true){
            int temp = div % remain;
            div = remain;
            if(temp == 0)
                return remain;
            remain = temp;
        }
    }
}