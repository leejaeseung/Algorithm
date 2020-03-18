/*
문제
우리의 우상 곽철용은 화투로 노름을 하는 것을 매우 좋아한다. 이번에 그는 지인들과 함께 새로운 게임을 해보려고 한다.

게임은 M명의 참가자로 진행되며, 4 × N장의 카드를 가지고 한다. 카드에 적힌 숫자는 1부터 4 × N까지의 수이며, 중복되는 숫자가 적힌 카드는 존재하지 않는다. M명의 참가자들은 우선 4 × N장의 카드에서 각각 2개의 카드를 뽑아서 버린다. 그리고 다시 M명의 참가자들은 각각 2개의 카드를 뽑는다. 게임의 승부는 두번째에 뽑은 두 장의 카드에 적힌 숫자에 따라 결정된다. 각 참가자의 점수는 두 장의 카드에 적힌 숫자를 K로 나눈 나머지의 차이다.

곽철용은 두번의 카드 뽑기 후, 초조한 마음에 자신이 이 게임에서 이길 수 있는지 매우 궁금해졌다. 그래서 자신보다 점수가 높은 사람들이 최대 몇 명인지 알고자 한다. 여러분들이 상남자 곽철용의 초조한 마음을 풀어주도록 하자.

입력
첫째 줄에 양의 정수 N, M, K가 주어진다. (1 ≤ M ≤ N ≤ 100,000, 1 ≤ K ≤ 4 × N)

둘째 줄부터 M+1번째 줄까지 각 참가자가 첫번째 카드 뽑기에서 뽑은 카드에 적힌 두 개의 양의 정수 ai와 bi가 주어진다. (1 ≤ ai, bi ≤ 4 × N)

M+2번째 줄에는 곽철용이 두번째 카드 뽑기에서 뽑은 카드에 적힌 두 개의 양의 정수 A와 B가 주어진다. (1 ≤ A, B ≤ 4 × N)

출력
첫째 줄에 곽철용보다 높은 점수를 가진 사람들이 최대 몇 명인지 출력한다.

풀이:
다시 풀자.
 */
import java.io.*;
import java.util.*;

public class Main8 {

    public static int N,M,K;
    public static int[] cards;
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        cards = new int[N * 4 + 1];
        cards[0] = -1;

        for (int i = 1; i <= N * 4 ; i++) {
            cards[i] = i % K;
        }

        for (int i = 0; i < M ; i++) {
            st = new StringTokenizer(br.readLine());
            cards[Integer.parseInt(st.nextToken())] = -1;
            cards[Integer.parseInt(st.nextToken())] = -1;
        }

        st = new StringTokenizer(br.readLine());
        int gwack_a = Integer.parseInt(st.nextToken());
        int gwack_b = Integer.parseInt(st.nextToken());
        cards[gwack_a] = -1;
        cards[gwack_b] = -1;

        int gwack = Math.abs(gwack_a % K - gwack_b % K);

        Arrays.sort(cards);
        int highp = cards.length - 1;
        int lowp = cards.length - 2;
        int cnt = 0;

        while(true){
            if(cnt > M - 2){
                break;
            }
            if(lowp <= 2 * M + 2){
                break;
            }
            if(cards[highp] <= gwack)
                break;
            if(Math.abs(cards[lowp] - cards[highp]) > gwack){
                    cnt++;
                    highp--;
                    lowp--;
                }
            else{
                lowp--;
            }
        }

        bw.write(Integer.toString(cnt));
        bw.flush();
        bw.close();
    }
}