/*
문제
LCS(Longest Common Subsequence, 최장 공통 부분 수열)문제는 두 수열이 주어졌을 때, 모두의 부분 수열이 되는 수열 중 가장 긴 것을 찾는 문제이다.

예를 들어, ACAYKP와 CAPCAK의 LCS는 ACAK가 된다.

입력
첫째 줄과 둘째 줄에 두 문자열이 주어진다. 문자열은 알파벳 대문자로만 이루어져 있으며, 최대 1000글자로 이루어져 있다.

출력
첫째 줄에 입력으로 주어진 두 문자열의 LCS의 길이를 출력한다.

풀이:
LCS(Longest Common Subsequence, 최장 공통 부분 수열) 문제이다.
각 문자열의 개수 + 1만큼 2차원 배열을 선언하고,
두 문자가 같을 시 -> 현재 원소 = 왼쪽 위 원소 + 1
두 문자가 다를 시 -> 현재 원소 = Math.max( 왼쪽 원소, 위 원소)
 */
import java.io.*;

public class Main {

    public static String str1, str2;
    public static int[][] dp;
    public static int leng1, leng2;
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        str1 = br.readLine();
        str2 = br.readLine();

        leng1 = str1.length() + 1;
        leng2 = str2.length() + 1;

        dp = new int[leng2][leng1];


        for (int i = 1; i < leng2 ; i++) {
            for (int j = 1; j < leng1 ; j++) {
                if(str1.charAt(j - 1) == str2.charAt(i - 1))
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = Math.max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
        System.out.println(dp[leng2 - 1][leng1 - 1]);
    }
}