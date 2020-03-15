/*
문제
신종 바이러스인 웜 바이러스는 네트워크를 통해 전파된다. 한 컴퓨터가 웜 바이러스에 걸리면 그 컴퓨터와 네트워크 상에서 연결되어 있는 모든 컴퓨터는 웜 바이러스에 걸리게 된다.

예를 들어 7대의 컴퓨터가 <그림 1>과 같이 네트워크 상에서 연결되어 있다고 하자. 1번 컴퓨터가 웜 바이러스에 걸리면 웜 바이러스는 2번과 5번 컴퓨터를 거쳐 3번과 6번 컴퓨터까지 전파되어 2, 3, 5, 6 네 대의 컴퓨터는 웜 바이러스에 걸리게 된다. 하지만 4번과 7번 컴퓨터는 1번 컴퓨터와 네트워크상에서 연결되어 있지 않기 때문에 영향을 받지 않는다.



어느 날 1번 컴퓨터가 웜 바이러스에 걸렸다. 컴퓨터의 수와 네트워크 상에서 서로 연결되어 있는 정보가 주어질 때, 1번 컴퓨터를 통해 웜 바이러스에 걸리게 되는 컴퓨터의 수를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에는 컴퓨터의 수가 주어진다. 컴퓨터의 수는 100 이하이고 각 컴퓨터에는 1번 부터 차례대로 번호가 매겨진다. 둘째 줄에는 네트워크 상에서 직접 연결되어 있는 컴퓨터 쌍의 수가 주어진다. 이어서 그 수만큼 한 줄에 한 쌍씩 네트워크 상에서 직접 연결되어 있는 컴퓨터의 번호 쌍이 주어진다.

출력
1번 컴퓨터가 웜 바이러스에 걸렸을 때, 1번 컴퓨터를 통해 웜 바이러스에 걸리게 되는 컴퓨터의 수를 첫째 줄에 출력한다.
    풀이 : 연결된 노드는 정방향과 역방향 모두 추가해주고 BFS를 하여 1부터 탐색해가며 count를 증가
 */
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    public static int N;
    public static boolean[] visit;
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N=Integer.parseInt(br.readLine());
        int M=Integer.parseInt(br.readLine());
        int cnt=0;

        visit=new boolean[N+1];
        ArrayList<Node> nd=new ArrayList<>();

        for (int i = 0; i <=N ; i++) {
            nd.add(new Node(i));
        }

        for (int i = 0; i <M ; i++) {
            StringTokenizer st=new StringTokenizer(br.readLine());
            int from=Integer.parseInt(st.nextToken());
            int to=Integer.parseInt(st.nextToken());

            nd.get(from).next.add(nd.get(to));
            nd.get(to).next.add(nd.get(from));
        }

        cnt=Search(nd);

        System.out.println(cnt);
    }
    public static int Search(ArrayList<Node> nd){
        Queue<Node> q=new LinkedList<>();
        int cnt=0;
        q.offer(nd.get(1));
        visit[1]=true;

        while(!q.isEmpty()){
            Node temp=q.poll();

            for (int i = 0; i <temp.next.size() ; i++) {
                if(!visit[temp.next.get(i).num]){
                    q.offer(temp.next.get(i));
                    visit[temp.next.get(i).num]=true;
                    cnt++;
                }
            }
        }
        return cnt;
    }
}

class Node{

    public ArrayList<Node> next;
    public int num;
    public Node(int num){
        this.num=num;
        next=new ArrayList<>();
    }
}