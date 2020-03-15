/*
    문제
숌 회사에서 이번에 새로운 전략 시뮬레이션 게임 세준 크래프트를 개발하기로 하였다. 핵심적인 부분은 개발이 끝난 상태고, 종족별 균형과 전체 게임 시간 등을 조절하는 부분만 남아 있었다.

게임 플레이에 들어가는 시간은 상황에 따라 다를 수 있기 때문에, 모든 건물을 짓는데 걸리는 최소의 시간을 이용하여 근사하기로 하였다. 물론, 어떤 건물을 짓기 위해서 다른 건물을 먼저 지어야 할 수도 있기 때문에 문제가 단순하지만은 않을 수도 있다. 예를 들면 스타크래프트에서 벙커를 짓기 위해서는 배럭을 먼저 지어야 하기 때문에, 배럭을 먼저 지은 뒤 벙커를 지어야 한다.

편의상 자원은 무한히 많이 가지고 있고, 건물을 짓는 명령을 내리기까지는 시간이 걸리지 않는다고 가정하자.

입력
첫째 줄에 건물의 종류 수 N(1 ≤ N ≤ 500)이 주어진다. 다음 N개의 줄에는 각 건물을 짓는데 걸리는 시간과 그 건물을 짓기 위해 먼저 지어져야 하는 건물들의 번호가 주어진다. 건물의 번호는 1부터 N까지로 하고, 각 줄은 -1로 끝난다고 하자. 각 건물을 짓는데 걸리는 시간은 100,000보다 작거나 같은 자연수이다.

출력
N개의 각 건물이 완성되기까지 걸리는 최소 시간을 출력한다.
    풀이 :
    위상 정렬과 인접 행렬을 이용하여 푼 문제.
    1. 각 정점들은 자기 자신의 시간 값을 가진다.
    2. 위상 정렬을 하면서 다음 정점의 최장 시간을 갱신한다.
 */
import java.io.*;
import java.util.*;

public class Main {

    public static int N;
    public static BufferedWriter bw;
    public static int[] max_time;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        bw=new BufferedWriter(new OutputStreamWriter(System.out));

        N=Integer.parseInt(br.readLine());
        Node[] nd=new Node[N+1];
        max_time=new int[N+1];
        for (int i = 1; i <=N ; i++) {
            nd[i]=new Node(i);
        }

        for (int to = 1; to <=N ; to++) {
            String s = br.readLine();
            StringTokenizer st = new StringTokenizer(s);
            int time=Integer.parseInt(st.nextToken());
            nd[to].time=time;
            max_time[to]=time;
            while(true){
                int from=Integer.parseInt(st.nextToken());
                if(from==-1)
                    break;
                else{
                    nd[from].next.add(nd[to]);
                    nd[to].indegree++;
                }
            }
        }
        TPSort(nd);
        bw.flush();
        bw.close();
    }
    public static void TPSort(Node[] nd) throws IOException{
        Queue<Node> q=new LinkedList<>();

        for (int i = 1; i <=N ; i++) {
            if(nd[i].indegree==0){
                q.offer(nd[i]);
            }
        }
        while(!q.isEmpty()){
            Node temp=q.poll();
            for (int i = 0; i <temp.next.size() ; i++) {
                temp.next.get(i).indegree--;

                max_time[temp.next.get(i).num]=Math.max(max_time[temp.next.get(i).num],max_time[temp.num]+temp.next.get(i).time);

                if(temp.next.get(i).indegree==0){
                    q.offer(temp.next.get(i));
                }
            }
        }
        for (int i = 1; i <=N ; i++) {
            bw.write(max_time[i]+"\n");
        }
    }
}

class Node{

    public int num;
    public ArrayList<Node> next;
    public int indegree;
    public int time;
    public Node(int num){
        this.num=num;
        next=new ArrayList<>();
    }
}