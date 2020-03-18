/*
문제
N층으로 이뤄진 고층 아파트에 M대의 엘리베이터가 있다. 각 엘리베이터에는 1부터 M까지 번호가 매겨져있다.

아파트 관리인은 유지비를 줄이기 위하여 각 엘리베이터가 특정한 층에서만 서도록 하였다. 그 결과 i번 엘리베이터는 Xi번째 층에서부터 시작하여 매 Yi번째 층에서만 선다. 예를 들어 Xi = 4, Yi = 3이라면 i번 엘리베이터는 4층, 7층, 10층, …에서만 서게 된다.

이 아파트 A층에서 사는 철수는 B층에 있는 친구 집에 놀러 가려고 한다. 그런데 가능하면 엘리베이터를 타는 횟수를 줄이고 싶어 한다.

예를 들어 아파트가 총 12층이고, 엘리베이터가 3대 있으며, 각 엘리베이터가 다음과 같이 운행한다고 하자.



10층에서 8층으로 가기 위해서는 1번 - 2번 - 3번 엘리베이터를 차례로 탈 수도 있고, 1번 - 3번 엘리베이터를 탈 수도 있다. 어떤 방법이든 최소 두 번 엘리베이터를 타야한다.

N과 M 그리고 엘리베이터 운행 정보가 주어질 때 철수가 최소 몇 번 엘리베이터를 타야하는지와 타야할 엘리베이터의 순서를 구하는 프로그램을 작성하시오.

입력
첫째 줄에는 N과 M이 빈 칸을 사이에 두고 주어진다. 둘째 줄부터 M줄에 걸쳐 엘리베이터 번호 순서대로 Xi와 Yi가 빈 칸을 사이에 두고 주어지며, 마지막 줄에는 A와 B가 주어진다. N은 100,000이하, M은 100이하의 자연수이며, Xi, Yi, A, B는 모두 N이하의 자연수이다. A와 B는 서로 다른 수이다.

출력
첫째 줄에는 A층에서 B층으로 가기 위해 최소 몇 번 엘리베이터를 타야하는지를 출력한다. 다음 줄부터 타야하는 엘리베이터의 번호를 한 줄에 하나씩 타는 순서대로 출력한다. 또한 엘리베이터를 타는 방법이 여러 가지인 경우에는 그 중의 한 방법만을 출력한다. 만약 A층에서 B층으로 갈 수 없다면 첫째 줄에 -1을 출력한다.

풀이:
BFS 응용 문제입니다.
층에 대한 인접 행렬, 엘리베이터에 대한 인접 행렬 총 두개의 인접 행렬을 만들어 줍니다.

ex)층에 대한 인접 행렬
```
7층 - 1번 엘리베이터, 2번 엘리베이터
```

ex)엘리베이터에 대한 인접 행렬
```
1번 엘리베이터 - 4층, 7층, 10층
```

A와 B , 즉 층에 대한 값을 인수로 받았으니 다음과 같이 BFS로 엘리베이터를 탐색합니다.(방문 여부는 엘리베이터와 층 둘 다 해주었습니다.)
1. 현재 층을 갈 수 있는 엘리베이터를 모두 탐색
2. 탐색한 모든 엘리베이터에 대해 다음으로 갈 층을 큐에 삽입
3. B층을 발견하면 카운트 리턴

경로값은 trace배열로 이전 엘리베이터를 기억하게 하여 역으로 출력합니다.
 */
import java.io.*;
import java.util.*;

public class Main {

    public static int N,M,A,B;
    public static ArrayList<ArrayList<Integer>> floor;
    public static ArrayList<ArrayList<Integer>> elevator;
    public static boolean[] visit;
    public static boolean[] visit_elv;
    public static int[] trace;
    public static int lastElv = 0;

    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        floor = new ArrayList<>();
        elevator = new ArrayList<>();
        visit = new boolean[N + 1];
        visit_elv = new boolean[M + 1];
        trace = new int[M + 1];

        for (int i = 0; i <= M ; i++) {
            elevator.add(new ArrayList<>());
        }

        for (int i = 0; i <= N ; i++) {
            floor.add(new ArrayList<>());
        }

        for (int i = 1; i <= M ; i++) {
            st = new StringTokenizer(br.readLine());
            int Xi = Integer.parseInt(st.nextToken());
            int Yi = Integer.parseInt(st.nextToken());
            int temp = 0;

            for (int j = 0; Xi + Yi * j <= N ; j++ ) {
                temp = Xi + Yi * j;
                elevator.get(i).add(temp);
                floor.get(temp).add(i);
            }
        }
        st = new StringTokenizer(br.readLine());
        A = Integer.parseInt(st.nextToken());
        B = Integer.parseInt(st.nextToken());

        bw.write(BFS(A) + "\n");

        Stack<Integer> res = new Stack<>();
        int temp = lastElv;
        while(temp != 0){
            res.push(temp);
            temp = trace[temp];
        }
        while(!res.isEmpty()){
            bw.write(res.pop() + "\n");
        }
        bw.flush();
        bw.close();
    }
    public static int BFS(int start){
        Queue<tuple> q = new LinkedList<>();
        visit[start] = true;
        q.offer(new tuple(start, 0));
        int cnt = 0;

        while(!q.isEmpty()){
            int size = q.size();

            cnt++;

            for (int j = 0; j < size ; j++) {

                int now_floor = q.peek().floor;
                int now_elv = q.poll().elv;

                for (int elv : floor.get(now_floor)) {
                    if (!visit_elv[elv]) {
                        visit_elv[elv] = true;

                        for (int next_floor : elevator.get(elv)) {
                            if (!visit[next_floor]) {

                                trace[elv] = now_elv;
                                if (next_floor == B) {
                                    lastElv = elv;
                                    return cnt;
                                }

                                visit[next_floor] = true;
                                q.offer(new tuple(next_floor, elv));
                            }
                        }
                    }
                }
            }
        }
        return -1;
    }
}

class tuple{
    int floor;
    int elv;
    public tuple(int floor, int elv){
        this.floor = floor;
        this.elv = elv;
    }
}