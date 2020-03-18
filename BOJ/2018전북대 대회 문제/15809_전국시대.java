import java.io.*;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    public static int N, M;
    public static int[] list;
    public static int[] parent;
    public static boolean[] check;
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        list = new int[N + 1];
        parent = new int[N + 1];
        check = new boolean[N + 1];

        for (int i = 1; i <= N ; i++) {
            list[i] = Integer.parseInt(br.readLine());
            parent[i] = i;
        }
        for (int i = 0; i < M ; i++) {
            st = new StringTokenizer(br.readLine());
            int o = Integer.parseInt(st.nextToken());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());

            if(o == 1){
                union(x, y, list[find(x)] + list[find(y)]);
            }
            else{
                union(x, y, list[find(x)] - list[find(y)]);
            }
        }
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for (int i = 1; i <= N ; i++) {
            int n = find(i);
            if(n == 0) continue;
            if(!check[n]){
                check[n] = true;
                pq.offer(list[n]);
            }
        }
        System.out.println(pq.size());
        while(!pq.isEmpty())
            System.out.print(pq.poll() + " ");
    }
    public static int find(int now){
        if(now == parent[now])
            return now;
        return parent[now] = find(parent[now]);
    }
    public static void union(int x, int y, int army){

        int px = find(x);
        int py = find(y);

        if(px != py) {
            if(army > 0) {
                list[px] = army;
                parent[py] = px;
            }
            else if(army < 0) {
                list[py] = army * -1;
                parent[px] = py;
            }
            else {
                list[px] = 0;
                list[py] = 0;
                parent[px] = 0;
                parent[py] = 0;
            }
        }
    }
}