/*
문제
도현이는 컴퓨터와 컴퓨터를 모두 연결하는 네트워크를 구축하려 한다. 하지만 아쉽게도 허브가 있지 않아 컴퓨터와 컴퓨터를 직접 연결하여야 한다. 그런데 모두가 자료를 공유하기 위해서는 모든 컴퓨터가 연결이 되어 있어야 한다. (a와 b가 연결이 되어 있다는 말은 a에서 b로의 경로가 존재한다는 것을 의미한다. a에서 b를 연결하는 선이 있고, b와 c를 연결하는 선이 있으면 a와 c는 연결이 되어 있다.)

그런데 이왕이면 컴퓨터를 연결하는 비용을 최소로 하여야 컴퓨터를 연결하는 비용 외에 다른 곳에 돈을 더 쓸 수 있을 것이다. 이제 각 컴퓨터를 연결하는데 필요한 비용이 주어졌을 때 모든 컴퓨터를 연결하는데 필요한 최소비용을 출력하라. 모든 컴퓨터를 연결할 수 없는 경우는 없다.

입력
첫째 줄에 컴퓨터의 수 N (1 ≤ N ≤ 1000)가 주어진다.

둘째 줄에는 연결할 수 있는 선의 수 M (1 ≤ M ≤ 100,000)가 주어진다.

셋째 줄부터 M+2번째 줄까지 총 M개의 줄에 각 컴퓨터를 연결하는데 드는 비용이 주어진다. 이 비용의 정보는 세 개의 정수로 주어지는데, 만약에 a b c 가 주어져 있다고 하면 a컴퓨터와 b컴퓨터를 연결하는데 비용이 c (1 ≤ c ≤ 10,000) 만큼 든다는 것을 의미한다.

풀이:
최소 신장 트리(MST) 기본 문제이다.
prim 알고리즘으로 풀이.
 */
import java.io.*;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    public static int N, M;
    public static ArrayList<ArrayList<tuple>> list = new ArrayList<>();

    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());
        M = Integer.parseInt(br.readLine());

        for (int i = 0; i <= N ; i++) {
            list.add(new ArrayList<>());
        }

        for (int i = 0; i < M ; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            list.get(a).add(new tuple(b, c));
            list.get(b).add(new tuple(a, c));
        }
            System.out.println(prim(1));
    }
    public static int prim(int start){
        int[] cost = new int[N + 1];
        boolean[] visit = new boolean[N + 1];

        for (int i = 0; i <= N ; i++) {
            cost[i] = 1000000000;
        }

        cost[start] = 0;
        PriorityQueue<tuple> pq = new PriorityQueue<>(new myCom());

        pq.offer(new tuple(start, 0));
        int ret = 0;

        while(!pq.isEmpty()){
            tuple now = pq.poll();

            if(visit[now.first])    continue;
            visit[now.first] = true;

            ret += cost[now.first];

            for (int i = 0; i < list.get(now.first).size() ; i++) {
                tuple next = list.get(now.first).get(i);

                    if(!visit[next.first]){
                        if(cost[next.first] > next.second){
                            cost[next.first] = next.second;
                            pq.offer(new tuple(next.first, cost[next.first]));
                        }
                    }
            }
        }
        return ret;
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
    public int compare(tuple t1, tuple t2){
        return t1.second >= t2.second ? 1 : -1;
    }
}