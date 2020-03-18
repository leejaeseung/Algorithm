/*
문제
동물원에서 막 탈출한 원숭이 한 마리가 세상구경을 하고 있다. 그러나 그는 곧 동물원 직원에게 쫓기는 신세가 되었다. 원숭이와 동물원 직원사이에 쫓고 쫓기는 추격전을 살펴보자.

원숭이가 사는 나라는 여러 개의 도시와 도시들을 연결하는 길들로 구성되어 있다. 각 길들은 두 개의 도시를 양방향으로 연결한다. 또한, 각 길은 지나갈 때마다 일정한 시간이 걸린다. 원숭이는 시작도시에서 탈출하여 도착도시까지 최대한 빠른 시간에 가야한다.

그런데 원숭이의 오랜 숙적 멍멍이가 이를 갈며 원숭이를 기다리고 있었다. 멍멍이는 원숭이가 도망가는 경로 중 시작점과 도착점을 포함한 도시 중 한 군데에서 원숭이를 괴롭히기로 계획했다. 각 도시마다 구조가 다르기 때문에 멍멍이가 원숭이를 괴롭힐 수 있는 시간이 정해져있다.

그래서 멍멍이는 원숭이가 도망가는 경로 상에 있는 모든 도시들 중에서 가장 오랜 시간동안 괴롭힐 수 있는 도시에서 괴롭히기로 계획했다. 원숭이는 멍멍이를 피할 수 없다. 피할 수 없다면 즐겨라! 시작도시와 도착도시가 주어졌을 때, 원숭이가 최대한 빨리 도망갈 수 있는 시간을 구하는 프로그램을 작성하시오.

예를 들어, A, B, C, D 4개의 도시가 있고 원숭이는 A에서 도망쳐서 D로 가려고 한다고 하자. 이때, A-B와 B-D 간의 도로의 통행시간은 각각 50 이고 A-C 와 C-D 간의 도로의 통행시간은 각각 70 이면 A-B-D 의 경로가 더 이익이다. (각각 100 과 140 의 시간이 걸린다.)

그러나, 네 도시에서 멍멍이가 원숭이를 괴롭힐 수 있는 시간이 10, 80, 20, 10 이라면 A-C-D 를 통해 가는 것이 시간을 더 줄일 수 있는 방법이다. (A-B-D 의 경우 100+80 = 180 의 시간이 걸리고, A-C-D 의 경우 140+20 = 160 의 시간이 걸린다.)

입력
첫 번째 줄에는 도시의 개수 N (2 ≦ N ≦ 500) 과 도로의 개수 M (0 ≦ M ≦ 10,000), 그리고 질문의 개수 Q (0 ≦ Q ≦ 40,000) 가 주어진다.

그 다음 줄에, N개의 정수로 각 도시에서 멍멍이가 원숭이를 괴롭힐 수 있는 시간이 주어진다. 각 시간은 1이상 10,000이하의 정수이다. 그 후 M줄에 각각 3개의 정수로, 해당 도로가 잇는 두 도시의 번호 a, b (1 <= a, b <= N) 와 해당 도로의 통행시간 d 가 주어진다. 통행시간은 1이상 10,000이하의 정수이다.

그 후 Q줄에 각각 2개의 정수로, 원숭이의 출발도시와 도착도시 S, T 가 주어진다.

출력
첫째 줄에 원숭이가 S 번 도시로부터 T 번 도시까지 도망가는 데 드는 최소시간을 출력한다. 만약 두 도시 간에 경로가 없을 경우, -1 을 출력한다.

풀이:
플로이드 와샬 알고리즘을 사용한다.
각 거리 배열 값은 괴롭히는 시간을 더한 값을 넣어준다.
a->b 와 a->c->b 중 더 작은 값을 갱신할 때, a->c 의 괴롭히는 시간 값과 c->b 의 괴롭히는 시간 중 더 큰값으로 비교해준다.
중간 노드인 c 를 비교하는 순서는 괴롭히는 시간이 작은 순서로 비교해주어야 한다.
 */
import java.io.*;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    public static int N, M, Q;
    public static int[][] dist;
    public static int[] city;
    public static int[][] plus;
    public static PriorityQueue<tuple> pq;
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        pq = new PriorityQueue<>(new Comparator<tuple>() {
            @Override
            public int compare(tuple tuple, tuple t1) {
                return tuple.value >= t1.value ? 1 : -1;
            }
        });

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        Q = Integer.parseInt(st.nextToken());

        city = new int[N + 1];
        dist = new int[N + 1][N + 1];
        plus = new int[N + 1][N + 1];

        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N ; i++) {
            city[i] = Integer.parseInt(st.nextToken());
            pq.offer(new tuple(i, city[i]));
        }

        for (int i = 1; i <= N ; i++) {
            for (int j = 1; j <= N ; j++) {
                plus[i][j] = Math.max(city[i], city[j]);
                dist[i][j] = 1000000000;
                if(i == j) {
                    dist[i][j] = 0;
                    plus[i][j] = 0;
                }
            }
        }

        for (int i = 0; i < M ; i++) {
            st = new StringTokenizer(br.readLine());

            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int d = Integer.parseInt(st.nextToken());

            int p = Math.max(city[a], city[b]);
            dist[a][b] = d + p;
            dist[b][a] = d + p;
        }
        Floid();

        for (int i = 0; i < Q ; i++) {
            st = new StringTokenizer(br.readLine());

            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());

            if(dist[start][end] != 1000000000)
                bw.write(dist[start][end] + "\n");
            else
                bw.write(-1 + "\n");
        }
        bw.flush();
        bw.close();
    }
    public static void Floid(){
        while(!pq.isEmpty()) {
            int i = pq.poll().index;
            for (int j = 1; j <= N ; j++) {
                for (int k = 1; k <= N ; k++) {
                    if(j == k)  continue;
                    if(i == j || i == k) continue;
                    int p = Math.max(plus[j][i], plus[i][k]);
                    if(dist[j][k] > dist[j][i] + dist[i][k] + p - plus[j][i] - plus[i][k]){
                        //중간 경로 i 가 추가된다.
                        dist[j][k] = dist[j][i] + dist[i][k] + p - plus[j][i] - plus[i][k];
                        plus[j][k] = p;
                    }
                }
            }
        }
    }
}

class tuple {
    int index;
    int value;
    public tuple(int index, int value){
        this.index = index;
        this.value = value;
    }
}