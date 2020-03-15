/*
문제
넓은 시험 범위와 어려운 과제로 유명한 '운영체제로 보는 데이터베이스시스템 알고리즘' 수업은 시험지가 너무 많아 실내에서는 시험을 치를 수 없어서 야외에서 시험을 진행한다. 해당 수업의 수강생인 현수는 오랜 시간에 걸쳐 풀 수 있는 모든 문제를 풀었고 제출만을 남겨두고 있었다. 그러나 갑자기 불어오는 강풍에 현수의 시험지가 모두 날아가 버렸고, 날아간 시험지를 줍는 동안 남은 시간을 다 써버리고 말았다.

시험지에 명시된 규칙 중에는 채점하는 조교의 편의를 위해 시험지를 반드시 순서대로 제출하라는 규칙이 있는데, 이 규칙 때문에 현수는 힘들게 치른 시험이 0점 처리될 위기에 빠지게 되었다!

그러나, 마음씨 좋은 조교인 주찬이는 평소 수업에 열심히 참여한 현수에게 한 번의 기회를 주기로 했다. 규칙은 규칙이므로 많은 점수를 줄 수는 없고, 시험지를 현재 순서 그대로 K개의 그룹으로 나눈 뒤 각각의 그룹에서 맞은 문제 개수의 합을 구하여 그 중 최솟값을 시험 점수로 하기로 하였다. 현수가 이번 시험에서 받을 수 있는 최대 점수를 계산하는 프로그램을 작성하자.

현수는 모르는 문제를 아예 풀지 않기 때문에 현수가 푼 문제는 모두 맞았다고 생각할 수 있으며, 조교는 마음씨가 좋아서 자신이 줄 수 있는 최대한의 점수를 준다.

입력
첫 번째 줄에 시험지의 개수 N과 시험지를 나눌 그룹의 수 K가 정수로 주어진다. (1 ≤ K ≤ N ≤ 105)

두 번째 줄에 각 시험지마다 맞은 문제의 개수 x가 정수로 주어진다 (0 ≤ x ≤ 20)

출력
현수가 받을 수 있는 최대 점수를 출력한다.

풀이:
2343번 기타레슨과 매우 비슷한 문제.
단 그룹 별 최소 중 최대값을 구하여야 하므로 그룹을 추가할 때 sum = 0으로 해준다.
 */

import java.io.*;
import java.util.StringTokenizer;

public class Main2 {

    public static int[] value;
    public static int N,K;
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        value = new int[N];

        st = new StringTokenizer(br.readLine());
        int sum = 0;

        for (int i = 0; i < N ; i++) {
            value[i] = Integer.parseInt(st.nextToken());
            sum += value[i];
        }

        int left = 0;
        int right = sum;
        int res = 0;
        while (left <= right){
            int mid = (left + right) / 2;

            if(com(mid)){
                res = mid;
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        System.out.println(res);
    }
    public static boolean com(int mid){

        int group = 1;
        int sum = 0;

        for (int i = 0; i < N ; i++) {
            if(mid < value[i])
                return false;

            sum += value[i];
            if(sum > mid){
                sum = 0;
                group++;
            }
        }
        return group <= K;
    }
}