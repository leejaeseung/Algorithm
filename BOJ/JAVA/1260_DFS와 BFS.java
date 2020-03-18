/*
    문제
그래프를 DFS로 탐색한 결과와 BFS로 탐색한 결과를 출력하는 프로그램을 작성하시오. 단, 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문하고, 더 이상 방문할 수 있는 점이 없는 경우 종료한다. 정점 번호는 1번부터 N번까지이다.

입력
첫째 줄에 정점의 개수 N(1 ≤ N ≤ 1,000), 간선의 개수 M(1 ≤ M ≤ 10,000), 탐색을 시작할 정점의 번호 V가 주어진다. 다음 M개의 줄에는 간선이 연결하는 두 정점의 번호가 주어진다. 어떤 두 정점 사이에 여러 개의 간선이 있을 수 있다. 입력으로 주어지는 간선은 양방향이다.

출력
첫째 줄에 DFS를 수행한 결과를, 그 다음 줄에는 BFS를 수행한 결과를 출력한다. V부터 방문된 점을 순서대로 출력하면 된다.
    풀이 :
    DFS는 Stack으로 구현
    BFS는 Queue로 구현~
 */
import java.io.*;
import java.util.*;

public class Main {

    public static BufferedWriter bw;
    public static void main(String[] argc) throws IOException{
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        bw=new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st=new StringTokenizer(br.readLine());
        int N=Integer.parseInt(st.nextToken());
        int M=Integer.parseInt(st.nextToken());
        int start=Integer.parseInt(st.nextToken());

        Node[] nd_DFS=new Node[N+1];
        Node[] nd_BFS=new Node[N+1];
        for (int i = 1; i <=N ; i++) {
            nd_DFS[i]=new Node(i,1);
            nd_BFS[i]=new Node(i,0);
        }

        for (int i = 0; i <M ; i++) {
            st=new StringTokenizer(br.readLine());
            int first=Integer.parseInt(st.nextToken());
            int second=Integer.parseInt(st.nextToken());

            nd_DFS[first].next.add(nd_DFS[second]);
            nd_DFS[second].next.add(nd_DFS[first]);
            nd_BFS[first].next.add(nd_BFS[second]);
            nd_BFS[second].next.add(nd_BFS[first]);
        }
        DFS(nd_DFS,start);
        bw.write("\n");
        BFS(nd_BFS,start);
        bw.flush();
        bw.close();
    }
    public static void DFS(Node[] nd,int start) throws IOException{
        Stack<Node> stack=new Stack<>();
        boolean[] visit=new boolean[nd.length];
        stack.push(nd[start]);
        while(!stack.isEmpty()){
            Node temp=stack.pop();
            if(visit[temp.num]==false)
            bw.write(temp.num+" ");
            visit[temp.num]=true;
            while(!temp.next.isEmpty()){
                    stack.push(temp.next.poll());
            }
        }
    }
    public static void BFS(Node[] nd,int start) throws IOException{
        Queue<Node> q=new LinkedList<>();
        boolean[] visit=new boolean[nd.length];
        q.offer(nd[start]);
        visit[start]=true;
        while(!q.isEmpty()){
            Node temp=q.poll();
            bw.write(temp.num+" ");
            while(!temp.next.isEmpty()){
                Node tmp=temp.next.poll();
                if(visit[tmp.num]==false) {
                    q.offer(tmp);
                    visit[tmp.num]=true;
                }
            }
        }
    }
}

class Node{

    public int num;
    public PriorityQueue<Node> next;
    public Node(int num,int flag){
        this.num=num;
        next=new PriorityQueue<>(new Comparator<Node>() {
            @Override
            public int compare(Node o1, Node o2) {
                if(flag==1)
                return o1.num>=o2.num?-1:1;
                else
                    return o1.num<=o2.num?-1:1;
            }
        });
    }
}