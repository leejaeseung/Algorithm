/*
문제
과거 격투가로 명성을 떨치던 힘스트롱씨는 "힘 겨루기"라는 대회를 주최하여 전국에 홍보를 하였다. 모집 공고를 보고 전국 각지에서 많은 사람들이 모였는 데, 모집 공고에 '힘'이란 것에 대해 정의하지 않아 혼란이 생긴 것이다.

헬스장에서 3대 500치는 근육질 아저씨부터, 유명 RPG 게임의 힘(STR) 스탯이 높은 사람까지 여러 종류의 힘을 두고 모인 것이다.
힘스트롱씨는 문득 "아는 것이 힘이다"라는 유명 격언이 떠올랐다. 예선전에서 상식 퀴즈를 통해 참가자들의 힘을 수치화하였고, 이 수치를 통해 본선 참가자를 선정하기로 하였다.

그렇게 총 N명의 참가자가 본선에 진출하였다. 하지만 예상과 달리, 본선은 홍팀과 청팀 두 팀으로 나누어 승부를 겨루는 팀전으로 진행되었다.

N명의 참가자들이 일렬로 나란히 서 있다. 힘스트롱씨는 1부터 N−1까지의 수가 적힌 공이 들어있는 추첨 상자에서 무작위로 하나를 뽑아 기준선을 선정할 예정이다. 예를 들어, 3번이 적힌 공을 뽑으면 3번과 4번 참가자 사이가 기준선이 된다. 기준선보다 왼쪽은 홍팀, 기준선보다 오른쪽은 청팀이다.

경기는 단판으로 진행된다. 각 팀에서 가장 센 사람이 나온 후, 두 사람이 힘을 겨룬다. 힘이 더 센 사람이 이기고 게임은 종료된다. 힘의 세기가 같으면 이기는 사람은 없다.

도박사 김씨(이하 김도박사)는 경기가 시작되기 전에 참가자 명단을 입수했다! 기준선의 위치에 따라 어느 팀이 이길 지 미리 알 수 있게 된 김도박사는 이길 확률이 더 높은 쪽에 전재산을 걸 예정이다. 김도박사는 어느 팀에 전재산을 걸어야할까?

기준선은 선수와 선수 사이에만 위치할 수 있으며, 팀에는 반드시 1명 이상 있어야 한다.

입력
첫째 줄에 사람의 수 N이 주어진다. N은 1,000,000보다 작거나 같은 짝수이다.

둘째 줄에 1번 사람부터 N번 사람까지의 힘을 나타내는 정수가 주어진다. 각 사람의 힘은 10,000보다 작거나 같은 자연수이다.

출력
김도박사가 홍팀에 걸어야 하는 경우에는 R, 청팀에 걸어야 하는 경우에는 B를 출력한다. 두 팀의 이길 확률이 같은 경우에는 X를 출력한다.

풀이:
최댓값 세그먼트 트리 문제이다.
 */

import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static int[] tree;
    public static int[] value;
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        value = new int[N];
        int red = 0;
        int blue = 0;
        int redcnt = 0;
        int bluecnt = 0;
        for (int i = 0; i < N ; i++) {
            value[i] = Integer.parseInt(st.nextToken());
        }
        int H = (int)Math.ceil((Math.log(N) / Math.log(2))) + 1;
        tree = new int[(int)Math.pow(2, H)];

        init(1, 0, N - 1);

        for (int i = 0; i < N - 1 ; i++) {
            red = getMax(1, 0, N - 1, 0, i);
            blue = getMax(1, 0, N - 1, i + 1, N - 1);

            if(red > blue){
                redcnt++;
            }
            else if(red < blue){
                bluecnt++;
            }
        }
        if(redcnt > bluecnt)
            System.out.println("R");
        else if(redcnt < bluecnt)
            System.out.println("B");
        else
            System.out.println("X");
    }
    public static int init(int now, int left, int right){
        if(right == left)   return tree[now] = value[right];
        return tree[now] = Math.max(init(now * 2, left, (left + right) / 2), init(now * 2 + 1, (left + right) / 2 + 1, right));
    }
    public static int getMax(int now, int left, int right, int start, int end){
        if(end < left || start > right)     return 0;
        if(left >= start && right <= end)   return tree[now];
        return Math.max(getMax(now * 2, left, (left + right) / 2, start, end), getMax(now * 2 + 1, (left + right) / 2 + 1, right, start, end));
    }
}