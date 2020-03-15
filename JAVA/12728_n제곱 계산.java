/*
문제
이 문제에서 숫자 (3 + √5)n 에 대한 소수점 앞에 마지막 세 자리를 찾아야합니다. 예를 들어, n = 5 일 때 (3 + √5)5  = 3935.73982 ... 이므로 답은 935입니다. n = 2 인 경우 (3 + √5)2 = 27.4164079 … 이므로, 답은 027입니다.

입력
첫 번째 입력 줄은 테스트 케이스의 수 T를 알려줍니다. 각각의 T 테스트 케이스는 행(라인)이 분할되어 주어지며, 각 테스트 케이스는 하나의 양의 정수 n을 알려줍니다.

제한

1 <= T <= 100
2 <= n <= 2000000000
출력
각 입력 테스트 케이스에 대해 다음과 같은 출력이 필요합니다.

Case #X: Y
여기서 X는 테스트 케이스 번호이고, Y는 숫자 (3 + (5)^(0.5))^n 의 마지막 세 정수입니다. 만일 소수점 앞의 숫자(정수)가 세 자리보다 작은 경우 출력에 정확히 세 자리가 포함되도록 앞에 0을 추가하십시오.

풀이:
처음에는 (a + b * sqrt(5)) ^ n 에서 a,b를 구하고 sqrt(5)를 곱해주는 방식으로 했는데 정수형과 실수형 연산 시 정확도 차이때문에 N이 커질 때 틀린 답이 되었습니다.
(3 + sqrt(5)) ^ n + (3 - sqrt(5)) ^ n 은 항상 정수라는 점을 이용하면 매우 쉽게 풀이할 수 있습니다.

즉, (3 - sqrt(5)) ^ n == 0.xxx 이므로 위 식을 구한뒤(정수) 1을 빼주면 원하는 답을 얻을 수 있습니다.
 */
import java.io.*;

public class Main {

    public static void main(String[] argc) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));

        int T=Integer.parseInt(br.readLine());
        for (int i = 0; i <T ; i++) {
            long N = Long.parseLong(br.readLine());

            tuple temp = squ(N);

            long res = (temp.a * 2 - 1) % 1000;

            bw.write("Case #" + (i + 1) + ": " + String.format("%03d", res) + "\n");
        }
        bw.flush();
        bw.close();
    }
    public static tuple squ(long N){
        if(N == 1){
            return new tuple(3, 1);
        }
        tuple temp = squ(N / 2);
        if(N % 2 == 0){
            return mul(temp, temp);
        }
        else{
            return mul(mul(temp, temp), new tuple(3, 1));
        }
    }
    public static tuple mul(tuple origin, tuple target){
        return new tuple((((origin.a % 1000) * (target.a % 1000) % 1000) + ((origin.b % 1000) * (target.b % 1000) * 5) % 1000) % 1000, (((origin.b % 1000) * (target.a % 1000) % 1000) + ((origin.a % 1000) * (target.b % 1000)) % 1000) % 1000);
    }
}

class tuple{
    long a;
    long b;
    public tuple(long a, long b){
        this.a = a;
        this.b = b;
    }
}