/*
문제
그래프가 주어졌을 때, 그 그래프의 최소 스패닝 트리를 구하는 프로그램을 작성하시오.

최소 스패닝 트리는, 주어진 그래프의 모든 정점들을 연결하는 부분 그래프 중에서 그 가중치의 합이 최소인 트리를 말한다.

입력
첫째 줄에 정점의 개수 V(1 ≤ V ≤ 10,000)와 간선의 개수 E(1 ≤ E ≤ 100,000)가 주어진다. 다음 E개의 줄에는 각 간선에 대한 정보를 나타내는 세 정수 A, B, C가 주어진다. 이는 A번 정점과 B번 정점이 가중치 C인 간선으로 연결되어 있다는 의미이다. C는 음수일 수도 있으며, 절댓값이 1,000,000을 넘지 않는다.

최소 스패닝 트리의 가중치가 -2147483648보다 크거나 같고, 2147483647보다 작거나 같은 데이터만 입력으로 주어진다.

출력
첫째 줄에 최소 스패닝 트리의 가중치를 출력한다.

풀이:
최소 신장 트리(MST) 기본 문제.
크루스칼 알고리즘으로 풀이.
 */
import java.io.*;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    public static int N, E;
    public static PriorityQueue<triple> pq = new PriorityQueue<>(new myCom());
    public static int[] parent;
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        E = Integer.parseInt(st.nextToken());

        parent = new int[N + 1];
        for (int i = 0; i <= N ; i++) {
            parent[i] = i;
        }

        for (int i = 0; i < E ; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            pq.offer(new triple(a, b, c));
        }
        long sum = 0;
        while(!pq.isEmpty()){
            triple now = pq.poll();

            if(union(now.first, now.second)){
                sum += now.third;
            }
        }
        bw.write(Long.toString(sum));
        bw.flush();
        bw.close();
    }
    public static int find(int now){
        if(now == parent[now])
            return now;
        return parent[now] = find(parent[now]);
    }
    public static boolean union(int x, int y){
        x = find(x);
        y = find(y);

        if(x == y)  return false;

        parent[x] = y;
        return true;
    }
}

class triple{
    int first;
    int second;
    int third;
    public triple(int first, int second, int third){
        this.first = first;
        this.second = second;
        this.third = third;
    }
}

class myCom implements Comparator<triple>{
    @Override
    public int compare(triple triple, triple t1) {
        return triple.third >= t1.third ? 1 : -1;
    }
}