/*
문제
대학원생인 형욱이는 연구실에 출근할 때 주로 지하철을 이용한다. 지하철은 A와 B, 두 개의 회사에서 운영하고 있다. 두 회사는 경쟁사 관계로 사람들이 상대 회사의 지하철을 이용하는 것을 매우 싫어한다. 그래서 A와 B는 모두 상대 회사의 지하철로 환승할 때 마다 비싼 요금을 받고 있다.

형욱이는 가난한 대학원생이기 때문에 돈을 아끼는 것이 가장 중요하다. 형욱이에게 최적의 출근경로를 찾아주자. 최적의 출근 경로란 환승 횟수를 최소로 하는 경로 중 소요시간이 가장 짧은 경로이다. 여기에서의 환승은 이동하면서 지하철역을 운영하는 회사가 바뀔 때 마다 환승 1회로 계산한다.



위의 그림에서 원은 지하철역을 의미하고 선들은 지하철역들이 연결되어 있는 지를 나타낸다. 흰색으로 표시된 지하철역은 A회사가 운영하는 지하철역이고 검은색으로 표시된 역은 B회사가 운영하는 지하철역이다. 이 때 붉게 표시된 경로로 이동하는 것이 환승 2회로 가장 적게 환승하면서 시간이 가장 짧은 경로이다.

입력
첫째 줄에 지하철역의 수 N과 도착지의 번호 M이 공백을 사이에 두고 정수로 주어진다. 지하철역은 순서대로 0 부터 N-1까지 존재하며 출발지는 항상 0 이다. (2 ≤ N ≤ 1000, 0 < M < 1000)

그 다음 N 줄에 걸쳐 각각의 지하철역을 운영하는 회사의 정보 Ci(0 ≤  i < N)가 0 또는 1로 주어진다. 0은 A회사를 뜻하고 1은 B회사를 뜻한다.

그 다음 N 줄은 지하철역간의 연결 상태 Eij(0 ≤ Eij ≤ 1000)가 정수로 주어진다.  Eij가 0인 경우 i번째 역과 j번째 역이 연결되어 있지 않음을 의미하고 0보다 클 경우 두 역이 연결되어 있으며 요금이 Eij 만큼 듦을 의미한다.

출력
최적의 경로를 이용할 때 환승 횟수와 총 소요 시간을 공백으로 구분하여 출력한다.

또한 출발지와 도착지는 무조건 연결되어 있음이 보장된다.

풀이:
다익스트라 알고리즘으로 최단 시간을 구하는데, 우선 순위 큐를 환승 횟수로 정렬해준다.
환승 횟수가 같다면 짧은 시간 순으로 정렬한다.
 */
import java.io.*;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main16 {

    public static int[][] pay;
    public static boolean[] company;
    public static int[] distance;
    public static int N,M;
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        pay = new int[N][N];
        company = new boolean[N];
        distance = new int[N];
        for (int i = 0; i < N ; i++) {
            distance[i] = Integer.MAX_VALUE;
        }

        for (int i = 0; i < N ; i++) {
            if(Integer.parseInt(br.readLine()) == 1)
                company[i] = true;
        }
        for (int i = 0; i < N ; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N ; j++) {
                pay[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        Dijkstra(0);
    }
    public static void Dijkstra(int start){
        PriorityQueue<tuples> pq = new PriorityQueue<>(new Comparator<tuples>() {
            @Override
            public int compare(tuples o1, tuples o2) {
                if(o1.dis > o2.dis)
                    return 1;
                else if(o1.dis == o2.dis){
                    return o1.pay >= o2.pay ? 1 : -1;
                }
                else
                    return -1;
            }
        });

        pq.offer(new tuples(start, 0, 0));
        distance[0] = 0;

        while(!pq.isEmpty()){
            int now = pq.peek().num;
            int now_dis = pq.peek().dis;
            int now_pay = pq.poll().pay;

            if(distance[now] < now_pay)
                continue;

            if(now == M) {
                System.out.println(now_dis + " " + now_pay);
                return;
            }

            for (int i = 0; i < N ; i++) {
                if(pay[now][i] == 0)    continue;
                if(distance[i] > now_pay + pay[now][i]){
                    distance[i] = now_pay + pay[now][i];
                    if(company[i] != company[now]){
                        pq.offer(new tuples(i, now_dis + 1, distance[i]));
                    }
                    else{
                        pq.offer(new tuples(i, now_dis, distance[i]));
                    }
                }
            }
        }
    }
}

class tuples{
    int num;
    int dis;
    int pay;
    public tuples(int num, int dis, int pay){
        this.num = num;
        this.dis = dis;
        this.pay = pay;
    }
}