/*
문제
0과 1로 이루어진 길이가 무한한 문자열 X가 있다. 이 문자열은 다음과 같은 과정으로 만들어진다.

X는 맨 처음에 "0"으로 시작한다.
X에서 0을 1로, 1을 0으로 뒤바꾼 문자열 X'을 만든다.
X의 뒤에 X'를 붙인 문자열을 X로 다시 정의한다.
2~3의 과정을 무한히 반복한다.
즉, X는 처음에 "0"으로 시작하여 "01"이 되고, "0110"이 되고, "01101001"이 되고, ⋯ 의 과정을 거쳐 다음과 같이 나타내어진다.

    "011010011001011010010110011010011001011001101001⋯⋯"

자연수 k가 주어졌을 때 X의 k번째에는 무슨 문자가 오는지 구하여라.

입력
첫 번째 줄에 자연수 k (1 ≤ k ≤ 1018) 가 주어진다.

출력
첫 번째 줄에 k번째에 오는 문자를 출력하라.
풀이 :
뒤에 문자가 붙는 것이기 때문에 앞의 문자열은 변하지 않는다.
즉, 17번째 문자를 알고 싶으면, 이어 붙이기 전의 길이인 16을 빼면 0,1을 반전하기 전의 문자가 나온다.
첫 번째 문자가 될 때까지 이전 길이를 계속 빼가며 뺀 횟수가 홀수라면 1, 짝수라면 0이다.
 */

import java.io.*;

public class Main2 {

    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        long K = Long.parseLong(br.readLine()) - 1;
            long length = 2;
            if(K == 1) {
                System.out.println(1);
            }
            else if(K == 0 ) {
                System.out.println(0);
            }
            else {
                while (K >= length * 2) {
                    length *= 2;
                }
                int cnt = 0;
                while (true) {
                    K -= length;
                    cnt++;
                    if (K == 0) {
                        if (cnt % 2 == 0)
                            System.out.println(0);
                        else
                            System.out.println(1);
                        break;
                    }
                    while (K < length) {
                        length /= 2;
                    }
                }
            }
    }
}