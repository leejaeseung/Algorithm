/*

문제
숫자 1, 2, 3으로만 이루어지는 수열이 있다. 임의의 길이의 인접한 두 개의 부분 수열이 동일한 것이 있으면, 그 수열을 나쁜 수열이라고 부른다. 그렇지 않은 수열은 좋은 수열이다.

다음은 나쁜 수열의 예이다.

33
32121323
123123213
다음은 좋은 수열의 예이다.

2
32
32123
1232123
길이가 N인 좋은 수열들을 N자리의 정수로 보아 그중 가장 작은 수를 나타내는 수열을 구하는 프로그램을 작성하라. 예를 들면, 1213121과 2123212는 모두 좋은 수열이지만 그 중에서 작은 수를 나타내는 수열은 1213121이다.

입력
입력은 숫자 N하나로 이루어진다. N은 1 이상 80 이하이다.

출력
첫 번째 줄에 1, 2, 3으로만 이루어져 있는 길이가 N인 좋은 수열들 중에서 가장 작은 수를 나타내는 수열만 출력한다. 수열을 이루는 1, 2, 3들 사이에는 빈칸을 두지 않는다.

풀이:
수열이 좋은 수열인지 판단하는 함수를 만듭니다.
넘겨받은 문자열의 절반 길이까지만 비교를 해가며(모든 크기마다) 중복되는 수열이 있는지 검사합니다.
재귀 함수에선 1부터(가장 작은 수이므로) 3까지 붙여가며 좋은 수열인지 판단해가며 재귀 호출합니다.
 */
import java.io.*;

public class Main {

    public static int N;
    public static StringBuilder out = new StringBuilder();
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());

        BT(0);
    }
    public static void BT(int cnt){
        if(cnt == N){
            System.out.println(out);
            System.exit(0);
        }

        for (int i = 1; i <= 3 ; i++) {
            out.append(i);
            if(!isGood(out.toString())){
                out.delete(out.length() - 1, out.length());
                continue;
            }
            else{
                BT(cnt + 1);
                out.delete(out.length() - 1, out.length());
            }
        }
    }
    public static boolean isGood(String str){
        int size = 1;
        while(size <= str.length() / 2 + 1) {

            for (int i = 0; i <= str.length() - size * 2 ; i++) {
                if(str.substring(i, i + size).equals(str.substring(i + size, i + size * 2)))
                    return false;
            }
            size += 1;
        }
        return true;
    }
}