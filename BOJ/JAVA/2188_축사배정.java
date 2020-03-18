/*
문제
농부 존은 소 축사를 완성하였다. 축사 환경을 쾌적하게 유지하기 위해서, 존은 축사를 N개의 칸으로 구분하고, 한 칸에는 최대 한 마리의 소만 들어가게 계획했다.

첫 주에는 소를 임의 배정해서 축사를 운영했으나, 곧 문제가 발생하게 되었다. 바로 소가 자신이 희망하는 몇 개의 축사 외에는 들어가기를 거부하는 것이다.

농부 존을 도와 최대한 많은 수의 소가 축사에 들어갈 수 있도록 하는 프로그램을 작성하시오. 축사의 번호는 1부터 M까지 매겨져 있다.

입력
첫째 줄에 소의 수 N과 축사의 수 M이 주어진다. (1 ≤ N, M ≤ 200)

둘째 줄부터 N개의 줄에는 각 소가 들어가기 원하는 축사에 대한 정보가 주어진다. i번째 소가 들어가기 원하는 축사의 수 Si (0 ≤ Si ≤ M)이 먼저 주어지고, 이후 Si개의 축사 번호가 주어진다. 같은 축사 번호가 두 번 이상 주어지는 경우는 없다.

출력
첫째 줄에 축사에 들어갈 수 있는 소의 최댓값을 출력한다.

풀이:
이분 매칭 문제는 간선의 용량이 1인 최대 유량 문제와 동치이므로 에드몬드-카프 알고리즘으로 풀이했습니다.
왼쪽에 S 정점, 오른쪽에 E 정점을 새로 두어 S 에서 E 까지의 최대 용량을 구하면 되는 문제였습니다.
주의할 점 : 역방향 간선을 지정해주지 않아 틀렸습니다 뜸.
 */
import java.io.*;
import java.util.*;

public class Main {

    public static int N, M, E;
    public static ArrayList<ArrayList<Integer>> list = new ArrayList<>();
    public static int[][] c;
    public static int[][] f;

    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        c = new int[N + M + 2][N + M + 2];
        f = new int[N + M + 2][N + M + 2];
        E = N + M + 1;

        for (int i = 0; i < N + M + 2 ; i++) {
            list.add(new ArrayList<>());
        }

        for (int i = 1; i <= N ; i++) {
            st = new StringTokenizer(br.readLine());

            list.get(0).add(i);
            list.get(i).add(0);
            c[0][i] = 1;
            int S = Integer.parseInt(st.nextToken());
            for (int j = 0; j < S ; j++) {
                int num = Integer.parseInt(st.nextToken()) + N;

                list.get(i).add(num);
                list.get(num).add(i);
                c[i][num] = 1;
            }
        }
        for (int i = N + 1; i < E ; i++) {
            list.get(i).add(E);
            list.get(E).add(i);
            c[i][E] = 1;
        }
        System.out.println(BFS());
    }
    public static int BFS(){
        int ret = 0;

        while(true){
            Queue<Integer> q = new LinkedList<>();
            int[] prev = new int[N + M + 2];
            Arrays.fill(prev, -1);

            q.offer(0);

            while(!q.isEmpty() && prev[E] == -1){
                int now = q.poll();

                for (int next : list.get(now)) {
                    int relaxation = c[now][next] - f[now][next];

                    if(relaxation > 0 && prev[next] == -1){
                        q.offer(next);
                        prev[next] = now;
                        if(next == E)   break;
                    }
                }
            }
            if(prev[E] == -1)   break;

            int min = 1000000000;
            for (int i = E; i != 0 ; i = prev[i]) {
                min = Math.min(min, c[prev[i]][i] - f[prev[i]][i]);
            }
            for (int i = E; i != 0 ; i = prev[i]) {
                f[prev[i]][i] += min;
                f[i][prev[i]] -= min;
            }
            ret += min;
        }
        return ret;
    }
}