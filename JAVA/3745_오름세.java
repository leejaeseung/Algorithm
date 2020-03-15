/*
문제
주식투자를 좋아하는 정인이는 주가의 오름세를 살펴보려고 한다.

정인이는 n일 동안 매일 주가를 적어놓았고, 여기서 오름세를 찾아보려고 한다.

n일 동안의 주가를 p1, p2, ..., pn이라고 했을 때, 오름세란 부분수열 pi1 < pi2 < ... < pik (i1 < i2 < ... ik)을 말한다.

n일 동안 주가가 주어졌을 때, 가장 긴 오름세를 찾는 프로그램을 작성하시오.

입력
입력은 여러개의 테스트 케이스로 이루어져 있다. 각 테스트 케이스의 첫째 줄에는 주가를 관찰한 날의 수 N (N ≤ 100000)이 주어진다. 둘째 줄에는 관찰한 주가가 첫 날부터 순서대로 주어진다. 주가는 한 개 이상의 공백으로 구분되어 있다. 주가는 100,000보다 작거나 같은 자연수이다.

출력
각 테스트 케이스에 대해서 입력으로 주어진 주가의 가장 긴 오름세의 길이를 출력한다.

풀이:
LIS 를 매 테스트케이스마다 구하는 문제.
문자열을 토큰화 할 때 공백을 제거해주는 trim() 함수를 사용해주어야 한다.
 */
import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {

    public static int N;
    public static int[] value;
    public static ArrayList<Integer> dp;
    public static void main(String[] argc) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        String input;

            while ((input = br.readLine()) != null) {

                N = Integer.parseInt(input.trim());
                value = new int[N];
                dp = new ArrayList<>();

                StringTokenizer st = new StringTokenizer(br.readLine().trim());
                for (int i = 0; i < N; i++) {
                    value[i] = Integer.parseInt(st.nextToken());
                }
                dp.add(value[0]);
                for (int i = 1; i < N; i++) {
                    if (value[i] > dp.get(dp.size() - 1))
                        dp.add(value[i]);
                    else
                        lowerBound(0, dp.size(), value[i]);
                }
                bw.write(dp.size() + "\n");
                bw.flush();
            }
                bw.close();
    }
    public static void lowerBound(int s, int e, int v){
        while(s < e){
            int mid = (s + e ) / 2;
            if(dp.get(mid) >= v)
                e = mid;
            else
                s = mid + 1;
        }
        dp.set(s, v);
    }
}
