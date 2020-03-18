/*
문제
한길이는 수습 마법사이며, 마법사의 영혼을 받기 위해 줄을 서있다. 한길이는 강력한 힘을 얻기 위해 인성을 버렸다. 그리고 최고로 강력한 엔비스카의 영혼을 받기 위해서 새치기를 하기로 결심했다.

한길이의 앞에 N명의 사람들이 줄 서있다. 1초가 지날 때마다 줄의 맨 앞 사람은 영혼을 받고 집에 간다. 그리고 1초마다 한길이는 다음과 같은 행동을 할 수 있다.

기다리기
a명 앞으로 가기 (앞에 최소 a명 있을 때)
b명 앞으로 가기 (앞에 최소 b명 있을 때)
단, 한길이는 새치기에는 도가 텄기때문에, 모든 행동을 0초만에 할 수 있다.

예를 들어 N = 5, a = 1, b = 2라고 하자. 5초동안 기다리기만 하면 줄의 맨 앞 사람이 나가기 때문에 줄의 맨 앞에 서있기까지 5초가 걸린다. 하지만 맨 앞 한 명이 집에 가고 한길이가 2명 앞으로 새치기, 그 다음 한 명이 집에 가고 1명 앞으로 새치기하면 2초만에 줄의 맨 앞에 서게 된다. 유의할 점은 1초에 맨 앞 한 명이 가고 2명 앞으로 새치기하고 맨 앞 한 명이 가면 1명이 남는다. 이 때 2명 앞으로 새치기는 불가능하다.

한길이가 줄의 맨 앞에 서있으려면 최소 몇 초가 걸리는가?

입력
첫째 줄에 N, a, b가 주어진다. (0 ≤ N ≤ 1,000,000, 0 ≤ a, b ≤ N)

출력
한길이가 맨 앞에 서는데 걸리는 최소 시간을 출력한다.

풀이 : 기다리기 1초, a+1초, b+1초를 총 인원 N 에서 빼가며 BFS로 풀이했습니다.
 */

import java.io.*;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    public static int N,a,b;
    public static boolean[] visit;
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        a = Integer.parseInt(st.nextToken()) + 1;
        b = Integer.parseInt(st.nextToken()) + 1;

        int[] move = new int[3];
        move[0] = 1;
        move[1] = a;
        move[2] = b;
        visit = new boolean[N + 1];

        Queue<Integer> q = new LinkedList<>();
        q.offer(N);
        visit[N] = true;
        int time = 0;
        boolean stop = false;

        while(!q.isEmpty()){
            int size = q.size();
            for(int j = 0; j < size; j++) {
                int now = q.poll();

                if(0 == now){
                    stop = true;
                    break;
                }

                for (int i = 0; i < 3; i++) {
                    int next = now - move[i];

                    if (next < 0) continue;
                    if (!visit[next]) {
                        visit[next] = true;
                        if(0 == next){
                            stop = true;
                            time++;
                            break;
                        }
                        q.offer(next);
                    }
                }
            }
            if(stop)
                break;
            time++;
        }
        System.out.println(time);
    }
}