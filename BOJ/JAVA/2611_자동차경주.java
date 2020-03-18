/*
문제
자동차 경주로는 <그림 1>의 예와 같이 표현된다. 화살표는 각 지점을 잇는 도로를 의미하며 모든 도로는 일방통행 도로로 화살표 방향으로만 움직일 수 있다.



자동차 경주의 코스는 1번 지점에서 출발하여 다시 1번 지점으로 되돌아오는 것이다. 단, 중간에는 1번 지점을 지나서는 안 된다. 경주로는 1번 지점을 제외한 어느 지점에서 출발하여도 1번 지점을 지나가지 않고서는 같은 지점으로 돌아올 수 없도록 되어 있다. 또한 1번 지점에서 다른 모든 지점으로 갈 수 있고, 다른 모든 지점에서 1번 지점으로 갈 수 있다.

각 도로에는 <그림 2>의 예와 같이 그 도로를 지날 때 얻는 점수가 있다.



1번 지점에서 출발하여 가장 많은 점수를 얻어 다시 1번 지점으로 돌아오는 팀이 우승을 하게 된다. 가장 많은 점수를 얻어 1번 지점으로 돌아오는 경로를 찾아 그 얻는 점수와 경로를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에는 지점의 개수 N이 주어진다. 각 지점에는 1부터 N까지의 서로 다른 번호가 부여된다. 둘째 줄에는 도로의 개수 M이 주어진다. 이어 M개의 줄에는 p ,q ,r의 형식으로 도로의 정보가 주어지는데 이는 p번 지점부터 q번 지점으로 갈 수 있는 도로가 있고 그 도로에 부여된 점수가 r이라는 뜻이다. N은 1000이하의 자연수이고, p와 q는 1이상의 N이하의 자연수이며 r은 100이하의 자연수 이다. p와 q는 같지 않다.

출력
가장 많은 점수를 얻은 경로를 찾아, 첫째 줄에는 그 얻는 점수를 출력하고 둘째 줄에는 그 경로를 출력한다. 경로를 출력할 때는 지나는 지점들의 번호를 사이에 한 칸의 공백을 두어 출력한다. 출력하는 경로는 반드시 1번 지점에서 시작하여 1번 지점으로 끝나야 한다. 만약 같은 점수를 얻는 경로가 둘 이상일 경우 그 중 하나만 출력하면 된다.

풀이:
위상 정렬문제이다.
1번을 제외하곤 위상 정렬을 해주면서 거리의 최대값을 갱신하고, 갱신되었다면 이전 노드를 기억하게 하여 경로를 찍는다.
 */
import java.io.*;
import java.util.*;

public class Main {

    public static int N, M;
    public static ArrayList<node> node;
    public static boolean[] visit;
    public static int[][] dist;
    public static int max = 0;
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        N = Integer.parseInt(br.readLine());
        M = Integer.parseInt(br.readLine());

        node = new ArrayList<>();
        visit = new boolean[N + 1];
        dist = new int[N + 1][N + 1];

        for (int i = 0; i <= N ; i++) {
            node.add(new node(i));
        }

        for (int i = 0; i < M ; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            int value = Integer.parseInt(st.nextToken());

            node.get(from).next.add(node.get(to));
            node.get(to).degree++;
            dist[from][to] = value;
        }
        node.get(1).degree = 0;
        TopologySort();

        Stack<Integer> res = new Stack<>();
        int next = node.get(1).back;

        while(next != 1){
            res.push(next);
            next = node.get(next).back;
        }

        bw.write(node.get(1).dist + "\n");
        bw.write("1 ");
        while(!res.isEmpty()){
            bw.write(res.pop() + " ");
        }
        bw.write("1");
        bw.flush();
        bw.close();
    }
    public static void TopologySort(){
        Queue<node> q = new LinkedList<>();
        q.offer(node.get(1));

        while(!q.isEmpty()){
            node now = q.poll();

            for (node next: now.next) {
                next.degree--;

                if(next.dist < now.dist + dist[now.num][next.num]){
                    next.dist = now.dist + dist[now.num][next.num];
                    next.back = now.num;
                }
                if(next.degree <= 0){
                    if(next.num != 1)
                        q.offer(next);
                }
            }
        }
    }
}

class node{
    int num;
    int back;
    int degree = 0;
    int dist;
    ArrayList<node> next;
    public node(int num){
        this.num = num;
        next = new ArrayList<>();
    }
}