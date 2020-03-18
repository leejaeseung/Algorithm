/*
문제
오늘도 과제산에서는 크고 작은 스노우볼들이 굴러가고 있다. 과제산 아래에서 살고 있는 정명이는 이 스노우볼이 너무 커져서 집을 무너뜨릴까 걱정이다. 시작은 아무리 작은 스노우볼이라도, 내려오면서 엄청나게 커지기 때문에 스노우볼에 대한 대비책이 필요했다. 정명이는 스노우볼들이 산에서 모두 굴러내려왔을 때 총량이 어느 정도일지 계산해보려고 한다. 스노우볼은 다음과 같은 규칙으로 성장한다.

과제산의 높이는 H cm이다.
스노우볼은 해발고도 1cm 이상에서만 만들어지고, 처음 만들어진 크기는 1이다.
만들어진 스노우볼은 1cm 내려올 때마다 이전 크기의 x배가 된다.
스노우볼의 개수가 적었다면 정명이가 직접 계산할 수 있었겠지만, 오늘은 어째서인지 스노우볼이 너무 많이 내려오고 있다. 여러분이 정명이를 도와주자!

입력
첫번째 줄에 과제산의 높이 H, 스노우볼이 커지는 정도 x가 정수로 주어진다. (1 ≤ H ≤ 106, 1 ≤ x ≤ 100)

두번째 줄부터 H줄 동안 과제산에서 만들어진 스노우볼의 개수가 정수로 주어진다. i+1번째 줄의 수가 높이 i cm에서 만들어진 스노우볼의 개수 ci를 의미한다. (0 ≤ ci ≤ 100)

출력
과제산에서 모든 스노우볼이 내려왔을 때의 크기 합을 출력하라. 단 답이 너무 커질 수 있으니 109 + 7로 나눈 나머지를 출력하라.

풀이:
단순히 x를 곱해가며 합을 더해주고, 더해줄 때 모든 연산에 모듈러 연산을 적용하여 오버플로우를 방지함.(O(n) 의 시간복잡도)
 */
import java.io.*;
import java.util.StringTokenizer;

public class Main10 {

    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int H = Integer.parseInt(st.nextToken());
        int x = Integer.parseInt(st.nextToken());
        int div = 1000000007;

        long mul = x;
        long sum = 0;

        for (int i = 1; i <= H ; i++) {
            int cnt = Integer.parseInt(br.readLine());

            sum = ((sum % div) + (((mul % div) * (cnt % div)) % div) % div) % div;
            mul = ((mul % div) * (x % div)) % div;
        }
        System.out.println(sum);
    }
}