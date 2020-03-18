/*

시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	256 MB	3696	1736	1024	44.658%
문제
n(1≤n≤1,000)개의 도시가 있다. 그리고 한 도시에서 출발하여 다른 도시에 도착하는 m(1≤m≤100,000)개의 버스가 있다. 우리는 A번째 도시에서 B번째 도시까지 가는데 드는 버스 비용을 최소화 시키려고 한다. 그러면 A번째 도시에서 B번째 도시 까지 가는데 드는 최소비용과 경로를 출력하여라. 항상 시작점에서 도착점으로의 경로가 존재한다.

입력
첫째 줄에 도시의 개수 n(1≤n≤1,000)이 주어지고 둘째 줄에는 버스의 개수 m(1≤m≤100,000)이 주어진다. 그리고 셋째 줄부터 m+2줄까지 다음과 같은 버스의 정보가 주어진다. 먼저 처음에는 그 버스의 출발 도시의 번호가 주어진다. 그리고 그 다음에는 도착지의 도시 번호가 주어지고 또 그 버스 비용이 주어진다. 버스 비용은 0보다 크거나 같고, 100,000보다 작은 정수이다.

그리고 m+3째 줄에는 우리가 구하고자 하는 구간 출발점의 도시번호와 도착점의 도시번호가 주어진다.

출력
첫째 줄에 출발 도시에서 도착 도시까지 가는데 드는 최소 비용을 출력한다.

둘째 줄에는 그러한 최소 비용을 갖는 경로에 포함되어있는 도시의 개수를 출력한다. 출발 도시와 도착 도시도 포함한다.

셋째 줄에는 최소 비용을 갖는 경로를 방문하는 도시 순서대로 출력한다.

풀이:
다익스트라 알고리즘, 경로 저장 문제입니다.
 */
import java.io.*;
import java.util.*;

public class Main {

    public static int N, M, s, e;
    public static ArrayList<ArrayList<tuple>> list = new ArrayList<>();
    public static int[] prev;
    public static int[] dist;
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());
        M = Integer.parseInt(br.readLine());
        prev = new int[N + 1];
        dist = new int[N + 1];

        for (int i = 0; i <= N ; i++) {
            list.add(new ArrayList<>());
            prev[i] = -1;
            dist[i] = 1000000000;
        }

        for (int i = 0; i < M ; i++) {
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());

            list.get(from).add(new tuple(to, v));
        }
        st = new StringTokenizer(br.readLine());
        s = Integer.parseInt(st.nextToken());
        e = Integer.parseInt(st.nextToken());

        bw.write(Dijkstra(s, e) + "\n");
        DFS(e);

        bw.flush();
        bw.close();
    }
    public static void DFS(int now) throws IOException{
        Stack<Integer> stack = new Stack<>();

        while(now != -1){
            stack.push(now);
            now = prev[now];
        }
        bw.write(stack.size() + "\n");
        while(!stack.isEmpty()){
            bw.write(stack.pop() + " ");
        }
    }
    public static int Dijkstra(int start, int end){
        PriorityQueue<tuple> pq = new PriorityQueue<>(new myCom());

        dist[start] = 0;
        pq.offer(new tuple(start, 0));

        while(!pq.isEmpty()){
            tuple now = pq.poll();

            for (tuple next: list.get(now.first) ){

                if(dist[next.first] > dist[now.first] + next.second){
                    dist[next.first] = dist[now.first] + next.second;
                    prev[next.first] = now.first;
                    pq.offer(new tuple(next.first, dist[next.first]));
                }
            }
        }
        return dist[end];
    }
}

class tuple{
    int first;
    int second;
    public tuple(int first, int second){
        this.first = first;
        this.second = second;
    }
}

class myCom implements Comparator<tuple>{
    @Override
    public int compare(tuple tuple, tuple t1) {
        return tuple.second >= t1.second ? 1 : -1;
    }
}