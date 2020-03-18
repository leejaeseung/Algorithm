/*
제
농사꾼 존은 소들이 충분한 물을 마시길 원했다. 그래서 농장에서 우물에서 외양간을 잇는 N개의 배수관의 지도를 만들기로 했다. 존은 아주 다양한 크기의 배수관들이 완전히 우연한 방법으로 연결돼있음을 알았다. 존은 파이프를 통과하는 유량을 계산하고 싶다.

두개의 배수관이 한줄로 연결 돼 있을 때 두 관의 유량 중 최솟값으로 흐르게 된다. 예를 들어 용량이 5인 파이프가 용량이 3인 파이프와 연결되면 한개의 용량 3짜리 파이프가 된다.

  +---5---+---3---+    ->    +---3---+
게다가, 병렬로 연결돼 있는 배수관들은 각 용량의 합만큼의 물을 보낼 수 있다.

    +---5---+
 ---+       +---    ->    +---8---+
    +---3---+
마지막으로, 어떤 것에도 연결돼 있지 않은 파이프는 물을 흐르게 하지 못하므로 제거된다.

    +---5---+
 ---+               ->    +---3---+
    +---3---+--
이로 인해 복잡하게 연결된 모든 배수관들은 한개의 최대 유량을 갖는 배수관으로 만들어진다.

주어진 파이프들의 맵으로부터 우물(A)와 외양간(Z) 사이의 유량을 결정하라.

각 노드의 이름은 알파벳으로 지어져 있다.

                 +-----------6-----------+
        A+---3---+B                      +Z
                 +---3---+---5---+---4---+
                         C       D
파이프 BC와 CD는 합쳐질 수 있다.

                 +-----------6-----------+
        A+---3---+B                      +Z
                 +-----3-----+-----4-----+
                             D
그러면 BD와 DZ 역시 합쳐질 수 있다.

                 +-----------6-----------+
        A+---3---+B                      +Z
                 +-----------3-----------+
병렬 연결된 BZ 역시 합쳐진다.

                 B
        A+---3---+---9---+Z
그러면 AB와 BZ 역시 합쳐질 수 있고 용량 3인 배수관 하나가 만들어진다.

        A+---3---+Z
한 파이프들의 집합을 읽고. 두개의 끝점을 가진 파이프로 만들어놓은 뒤 A부터 Z까지 흐르는 최대 유량을 계산하라. 모든 파이프들은 위의 규칙을 적용시켜 줄일 수 있다.

i번째 파이프는 두개의 다른 노드 ai와 bi와 연결돼 있고 Fi (1 ≤ Fi ≤ 1,000)만큼의 유량을 갖는다. 알파벳은 같지만, 대소문자가 다르면 다른 문자이다. 파이프는 양방향으로 흐를 수 있다.

입력
첫째 줄에 정수 N (1 ≤ N ≤ 700)이 주어진다. 둘째 줄부터 N+1번째 줄까지 파이프의 정보가 주어진다. 첫 번째, 두 번째 위치에 파이프의 이름(알파벳 대문자 또는 소문자)이 주어지고, 세 번째 위치에 파이프의 용량이 주어진다.

출력
첫째 줄에 A에서 Z까지의 최대 유량을 출력한다.

풀이:
최대 유량 기본 문제입니다.
에드몬드-카프(BFS사용) 알고리즘을 이용해 풀이했습니다.
 */
import java.io.*;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    public static int N;
    public static ArrayList<ArrayList<Integer>> list = new ArrayList<>();
    public static int[][] flow_limit;
    public static int[][] flow_now;
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());

        flow_limit = new int[52][52];
        flow_now = new int[52][52];

        for (int i = 0; i < 52 ; i++) {
            list.add(new ArrayList<>());
        }

        for (int i = 0; i < N ; i++) {
            st = new StringTokenizer(br.readLine());

            char s = st.nextToken().charAt(0);
            char e = st.nextToken().charAt(0);
            int v = Integer.parseInt(st.nextToken());

            if(s >= 'A' && s <= 'Z')
                s -= 'A';
            else
                s = (char)(s - 'a' + 26);

            if(e >= 'A' && e <= 'Z')
                e -= 'A';
            else
                e = (char)(e - 'a' + 26);

            list.get((int)s).add((int)e);
            list.get((int)e).add((int)s);
            flow_limit[(int)s][(int)e] = flow_limit[(int)e][(int)s] += v;
        }

        bw.write(Integer.toString(BFS()));
        bw.flush();
        bw.close();
    }
    public static int BFS(){
        int ret = 0;

        while(true){
            Queue<Integer> q = new LinkedList<>();
            q.offer(0);

            int[] prev = new int[52];
            for (int i = 0; i < 52 ; i++) {
                prev[i] = -1;
            }
            while(!q.isEmpty() && prev[25] == -1){
                int now = q.poll();

                for (int i = 0; i < list.get(now).size() ; i++) {
                    int next = list.get(now).get(i);
                    int relaxation = flow_limit[now][next] - flow_now[now][next];

                    if(relaxation > 0 && prev[next] == -1){
                        prev[next] = now;
                        q.offer(next);
                        if(next == 25)
                            break;
                    }

                }
            }
            if(prev[25] == -1)
                break;

            int min = 1000000000;
            for (int i = 25; i != 0  ; i = prev[i]) {
                min = Math.min(min, flow_limit[prev[i]][i] - flow_now[prev[i]][i]);
            }
            for (int i = 25; i != 0 ; i = prev[i]) {
                flow_now[prev[i]][i] += min;
                flow_now[i][prev[i]] -= min;
            }
            ret += min;
        }
        return ret;
    }
}