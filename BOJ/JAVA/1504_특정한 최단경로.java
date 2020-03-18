/*
문제
방향성이 없는 그래프가 주어진다. 세준이는 1번 정점에서 N번 정점으로 최단 거리로 이동하려고 한다. 또한 세준이는 두 가지 조건을 만족하면서 이동하는 특정한 최단 경로를 구하고 싶은데, 그것은 바로 임의로 주어진 두 정점은 반드시 통과해야 한다는 것이다.

세준이는 한번 이동했던 정점은 물론, 한번 이동했던 간선도 다시 이동할 수 있다. 하지만 반드시 최단 경로로 이동해야 한다는 사실에 주의하라. 1번 정점에서 N번 정점으로 이동할 때, 주어진 두 정점을 반드시 거치면서 최단 경로로 이동하는 프로그램을 작성하시오.

입력
첫째 줄에 정점의 개수 N과 간선의 개수 E가 주어진다. (2 ≤ N ≤ 800, 0 ≤ E ≤ 200,000) 둘째 줄부터 E개의 줄에 걸쳐서 세 개의 정수 a, b, c가 주어지는데, a번 정점에서 b번 정점까지 양방향 길이 존재하며, 그 거리가 c라는 뜻이다. (1 ≤ c ≤ 1,000) 다음 줄에는 반드시 거쳐야 하는 두 개의 서로 다른 정점 번호가 주어진다.

출력
첫째 줄에 두 개의 정점을 지나는 최단 경로의 길이를 출력한다. 그러한 경로가 없을 때에는 -1을 출력한다.

풀이:
두 개의 점에 대해 다익스트라 알고리즘을 사용하면 됩니다.

 */
import java.io.*;
import java.util.*;

public class Main {

    public static int N, E, n1, n2;
    public static ArrayList<ArrayList<tuple>> list = new ArrayList<>();
    public static int[] dist;
    public static boolean flag = true;
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        E = Integer.parseInt(st.nextToken());

        for (int i = 0; i <= N ; i++) {
            list.add(new ArrayList<>());
        }

        for (int i = 0; i < E ; i++) {
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            int d = Integer.parseInt(st.nextToken());

            list.get(from).add(new tuple(to, d));
            list.get(to).add(new tuple(from, d));
        }
        st = new StringTokenizer(br.readLine());
        n1 = Integer.parseInt(st.nextToken());
        n2 = Integer.parseInt(st.nextToken());


        int res = Math.min(Dijkstra(1, n1) + Dijkstra(n1, n2) + Dijkstra(n2, N), Dijkstra(1, n2) + Dijkstra(n2, n1) + Dijkstra(n1, N));
        if(!flag)
            System.out.println(-1);
        else
            System.out.println(res);
    }
    public static int Dijkstra(int start, int dst){
        PriorityQueue<tuple> pq = new PriorityQueue<>(new Comparator<tuple>() {
            @Override
            public int compare(tuple tuple, tuple t1) {
                return tuple.second >= t1.second ? 1 : -1;
            }
        });
        dist = new int[N + 1];
        for (int i = 1; i <= N ; i++) {
            dist[i] = 1000000000;
        }
        dist[start] = 0;
        pq.offer(new tuple(start, 0));

        while(!pq.isEmpty()){
            tuple now = pq.poll();

            if( now.second > dist[now.first])   continue;

            for (int i = 0; i < list.get(now.first).size() ; i++) {
                tuple next = list.get(now.first).get(i);

                if(dist[next.first] > dist[now.first] + next.second){
                    dist[next.first] = dist[now.first] + next.second;
                    pq.offer(new tuple(next.first, dist[next.first]));
                }
            }
        }
        if(dist[dst] == 1000000000)
            flag = false;
        return dist[dst];
    }
}

class tuple {
    int first;
    int second;
    public tuple(int first, int second){
        this.first = first;
        this.second = second;
    }
}