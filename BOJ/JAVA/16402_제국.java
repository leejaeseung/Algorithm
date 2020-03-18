/*
문제
배성일력 73년, 대륙을 주름잡던 성일 제국은 무리한 정복 전쟁 끝에 멸망하게 되었다. 기회를 노리던 반란군들은 혼란을 틈타 제각각 왕국을 선포했고, 왕국들은 제국의 자리를 차지하기 위해 수많은 전쟁을 치르게 되었다.

전쟁은 다음과 같은 방식으로 진행된다.

다른 왕국의 속국이 아닌 왕국은 자신의 속국이 아닌 다른 왕국을 공격하여 전쟁을 벌일 수 있다. 만약 전쟁에서 승리한다면 그 왕국과 그 왕국의 속국들을 전부 자신의 속국으로 삼게 된다. 때로는 다른 왕국의 속국을 공격하는 경우도 있는데, 이 경우 그 왕국의 종주국(그 왕국을 거느린 왕국)은 그 왕국을 지키기 위해 지원을 아끼지 않는다. 따라서 여기서 승리한다면 빈털터리가 된 종주국과 그 속국들까지도 전부 자신의 속국으로 삼을 수 있다. 그러나 전쟁에서 패배한다면 자신과 자신의 속국들이 전부 상대 왕국(만약 다른 왕국의 속국이라면 그 종주국)의 속국으로 넘어가게 된다.

속국은 기본적으로 다른 왕국을 공격할 수 없지만, 한 가지 예외가 있다. 바로 자신의 종주국을 공격하는 것이다. 만약 이 전쟁에서 속국이 승리한다면 속국 신세에서 벗어나 종주국이었던 왕국과 그 속국들을 속국으로 삼게 된다. 그러나 종주국이 승리한다면 아쉽게도 아무 일도 일어나지 않는다.

왕국들의 이름과 두 왕국의 전쟁 결과들이 주어질 때, 모든 전쟁이 끝난 후 속국이 아닌 왕국들의 수와 속국이 아닌 각 왕국의 이름을 출력하라.

입력
첫째 줄에 왕국들의 수 N(2 ≤ N ≤ 500), 전쟁 결과의 수 M(1 ≤ M ≤ 2,000) 이 주어진다.

둘째 줄부터 N개의 줄에 걸쳐 각 왕국의 이름이 주어진다.

왕국의 이름은 항상 “Kingdom of ”로 시작하며, 그 뒤로 공백 없는 하나의 단어로 이루어진다. 왕국 이름은 알파벳 대소문자와 공백으로만 이루어지고, 이름의 총 길이는 공백을 포함해 20을 넘지 않는다. 또한 왕국의 이름은 중복되지 않는다.

그다음 줄부터 M개의 줄에 걸쳐 전쟁의 결과가 주어진다.

전쟁의 결과로 왕국1의 이름, 왕국2의 이름, w(w = 1 or 2)가 공백 없이 쉼표(,)를 사이에 둔 형식으로 주어지며, w가 1인 경우 왕국1이, 2인 경우 왕국2가 승리했다는 것을 뜻한다. 왕국 이름의 입력 순서는 어느 쪽이 먼저 공격했는지와는 관계가 없으며, 문제 조건에 따라 성립할 수 있는 전쟁만이 입력으로 주어진다.

출력
첫째 줄에 속국이 아닌 왕국의 수를 출력한다.

둘째 줄부터 속국이 아닌 왕국의 이름을 ASCII 사전 순으로 정렬하여 한 줄에 하나씩 출력한다.

풀이:
종주국이 다른 종주국의 속국이 될 경우는 기존의 유니온-파인드처럼 루트 노드를 연결한 뒤 find로 부모를 찾아주면 된다.
속국이 자신의 종주국을 이겼을 경우는 parent가 같기 때문에 따로 처리를 해준다.
( N 이 작기 때문에 선형으로 부모를 바꿔줌)
HashMap과 String 배열, 우선순위 큐를 이용하여 사전순으로 출력한다.
 */
import java.io.*;
import java.util.Comparator;
import java.util.HashMap;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    public static int N, M;
    public static String[] kingdom;
    public static HashMap<String, Integer> hm = new HashMap<>();
    public static int[] parent;
    public static boolean[] king;
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        parent = new int[N];
        king = new boolean[N];
        kingdom = new String[N];

        for (int i = 0; i < N ; i++) {
            kingdom[i] = br.readLine();
            hm.put(kingdom[i], i);
            parent[i] = i;
        }
        for (int i = 0; i < M ; i++) {
            String[] split = br.readLine().split(",");
            if(Integer.parseInt(split[2]) == 1){
                union(hm.get(split[0]), hm.get(split[1]));
            }
            else{
                union(hm.get(split[1]), hm.get(split[0]));
            }
        }
        int cnt = 0;
        for (int i = 0; i < N ; i++) {
            int idx = find(i);
            if(!king[idx]) {
                king[idx] = true;
                cnt++;
            }
        }

        bw.write(cnt + "\n");

        PriorityQueue<String> pq = new PriorityQueue<>(new Comparator<String>() {
            @Override
            public int compare(String s, String t1) {
                return s.compareTo(t1) > 0 ? 1 : -1;
            }
        });

        for (int i = 0; i < N ; i++) {
            if(king[hm.get(kingdom[i])])
                pq.offer(kingdom[i]);
        }
        while(!pq.isEmpty())
            bw.write(pq.poll() + "\n");
        bw.flush();
        bw.close();
    }
    public static int find(int now){
        if(now == parent[now]){
            return now;
        }
        return parent[now] = find(parent[now]);
    }
    public static void union(int win, int lose){

        int win_temp = win;
        int lose_temp = lose;
        win = find(win);
        lose = find(lose);

        if(win != lose) {
            parent[lose] = win;
        }
        else {
            for (int i = 0; i < N ; i++) {
                if(parent[i] == lose_temp)
                    parent[i] = win_temp;
            }
        }
    }
}