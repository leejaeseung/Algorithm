/*
문 제
성권이는 Heroes of the Storm 프로게이머 지망생이다.

이 게임에는 총 N개의 캐릭터가 있다. 그리고 현재 각 캐릭터의 레벨은 Xi이다. 성권이는 앞으로 게임이 끝날 때까지, 레벨을 최대 총합 K만큼 올릴 수 있다.

팀 목표레벨 T =min(Xi) (1 ≤ i ≤ N)라고 정의하면, 게임이 끝날 때까지 성권이가 달성할 수 있는 최대 팀 목표레벨 T는 무엇인가?

예를 들어, N = 3, X1= 10, X2= 20, X3= 15이고 K = 10일 때, X1을 7만큼 올리고 X3을 2만큼 올리면 최소 레벨 Xi는 17이 된다. 따라서 팀 목표레벨 T는 17이다. 이 경우처럼 레벨을 총합 K보다 적게 올릴 수도 있다.

입력
첫째 줄에는 캐릭터의 개수 N, 올릴 수 있는 레벨 총합 K가 주어진다. (1 ≤ N ≤1,000,000, 1 ≤ K ≤ 1,000,000,000)

다음 N개의 줄에는 현재 각 캐릭터의 레벨이 X1, X2, X3, ... , Xn 으로 주어진다. (1 ≤ Xi ≤ 1,000,000,000)

출력
가능한 최대 팀 목표레벨 T를 출력한다.

풀이 : 캐릭터 레벨을 오름차순 정렬한 뒤, prev 와 now 를 계속 갱신해갑니다.
now가 prev 와 계속 같다면 카운팅해주고, 새로운 now가 나오거나 끝났을 때 카운팅된 캐릭터 수만큼 레벨을 올려줍니다.
 */

import java.io.*;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    public static int N;
    public static long K;
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Long.parseLong(st.nextToken());
        PriorityQueue<Long> pq = new PriorityQueue<>();

        for (int i = 0; i < N ; i++) {
            pq.offer(Long.parseLong(br.readLine()));
        }

        long prev = pq.poll();
        long same_cnt = 1;
        long min = prev + K;

        while(!pq.isEmpty()){
            long now = pq.poll();
            if(now == prev){
                same_cnt++;
            }
            else{
                long diff = now - prev;
                if(diff * same_cnt <= K){
                    K -= diff * same_cnt;
                    prev = now;
                    min = prev;
                    same_cnt++;

                }
                else{
                    min = prev + (K / same_cnt);
                    break;
                }
            }
            if(pq.isEmpty())
                min = now + (K / same_cnt);
        }
        bw.write(Long.toString(min));
        bw.flush();
        bw.close();
    }
}