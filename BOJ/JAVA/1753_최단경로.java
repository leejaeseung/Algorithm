/*
    문제
방향그래프가 주어지면 주어진 시작점에서 다른 모든 정점으로의 최단 경로를 구하는 프로그램을 작성하시오. 단, 모든 간선의 가중치는 10 이하의 자연수이다.

입력
첫째 줄에 정점의 개수 V와 간선의 개수 E가 주어진다. (1≤V≤20,000, 1≤E≤300,000) 모든 정점에는 1부터 V까지 번호가 매겨져 있다고 가정한다. 둘째 줄에는 시작 정점의 번호 K(1≤K≤V)가 주어진다. 셋째 줄부터 E개의 줄에 걸쳐 각 간선을 나타내는 세 개의 정수 (u, v, w)가 순서대로 주어진다. 이는 u에서 v로 가는 가중치 w인 간선이 존재한다는 뜻이다. u와 v는 서로 다르며 w는 10 이하의 자연수이다. 서로 다른 두 정점 사이에 여러 개의 간선이 존재할 수도 있음에 유의한다.

출력
첫째 줄부터 V개의 줄에 걸쳐, i번째 줄에 i번 정점으로의 최단 경로의 경로값을 출력한다. 시작점 자신은 0으로 출력하고, 경로가 존재하지 않는 경우에는 INF를 출력하면 된다.
    풀이 :
    우선순위 큐를 이용하자 -> 가중치에 대해 오름차순 정렬하여 다익스트라 ㄱ
 */
import java.io.*;
import java.util.*;

public class Main {

    public static int[] dist;
    public static  Vector<node>[] vt;
    public static int MAX=99999999;
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw=new BufferedWriter(new OutputStreamWriter((System.out)));

        StringTokenizer st=new StringTokenizer(br.readLine());
        int N=Integer.parseInt(st.nextToken());
        int M=Integer.parseInt(st.nextToken());
        int K=Integer.parseInt(br.readLine());

        vt=new Vector[N+1];
        dist=new int[N+1];
        for (int i = 1; i <=N ; i++) {
            vt[i]=new Vector<>();
            dist[i]=MAX;
        }
        for (int i = 0; i <M ; i++) {
            st=new StringTokenizer(br.readLine());
            int from=Integer.parseInt(st.nextToken());
            int to=Integer.parseInt(st.nextToken());
            int distance=Integer.parseInt(st.nextToken());
            node tmp=new node(from,distance);
            tmp.to=to;
            vt[from].add(tmp);
        }
        dist[K]=0;
        dijkstra2(K, N);

        for (int i = 1; i <=N ; i++) {
            if(dist[i]!=MAX)
            bw.write(dist[i]+"\n");
            else
                bw.write("INF\n");
        }
        bw.flush();
        bw.close();
    }
    public static void dijkstra(int start) {
        PriorityQueue<node> pq = new PriorityQueue<>(new Comparator<node>() {
            @Override
            public int compare(node o1, node o2) {
                if(o1.dist<=o2.dist)
                    return -1;
                else
                    return 1;
            }
        });
        pq.offer(new node(start, 0));
        while (!pq.isEmpty()) {
            node temp=pq.poll();

            if(temp.dist<=dist[temp.from]) {
                for (int i = 0; i < vt[temp.from].size(); i++) {
                    if (dist[vt[temp.from].get(i).to] > dist[temp.from] + vt[temp.from].get(i).dist) {
                        dist[vt[temp.from].get(i).to] = dist[temp.from] + vt[temp.from].get(i).dist;
                        pq.offer(new node(vt[temp.from].get(i).to,  dist[vt[temp.from].get(i).to]));
                    }
                }
            }
        }
    }
    public static void dijkstra2(int start, int N){
        boolean[] visit = new boolean[N + 1];
        for (int i = 0; i <= N ; i++) {
            visit[i] = false;
        }
        dist[start] = 0;
        while(true){
            int closest = MAX;
            int now = 0;

            for (int i = 1; i <= N ; i++) {
                if(dist[i] < closest && !visit[i]){
                    now =i;
                    closest = dist[i];
                }
            }
            if(closest == MAX) break;

            visit[now] = true;

            for (int i = 0; i < vt[now].size() ; i++) {
                int there = vt[now].get(i).to;
                if(visit[there])    continue;
                int nextDist = dist[now] + vt[now].get(i).dist;
                dist[there] = Math.min(dist[there], nextDist);
            }
        }
    }
}

class node{
    public int from;
    public int to;
    public int dist;
    public node(int from,int dist){
        this.from=from;
        this.dist=dist;
    }
}