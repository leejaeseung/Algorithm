/*
    문제
방향 그래프가 주어졌을 때, 그 그래프를 SCC들로 나누는 프로그램을 작성하시오.

방향 그래프의 SCC는 우선 정점의 최대 부분집합이며, 그 부분집합에 들어있는 서로 다른 임의의 두 정점 u, v에 대해서 u에서 v로 가는 경로와 v에서 u로 가는 경로가 모두 존재하는 경우를 말한다.



예를 들어 위와 같은 그림을 보자. 이 그래프에서 SCC들은 {a, b, e}, {c, d}, {f, g}, {h} 가 있다. 물론 h에서 h로 가는 간선이 없는 경우에도 {h}는 SCC를 이룬다.

입력
첫째 줄에 두 정수 V(1≤V≤10,000), E(1≤E≤100,000)가 주어진다. 이는 그래프가 V개의 정점과 E개의 간선으로 이루어져 있다는 의미이다. 다음 E개의 줄에는 간선에 대한 정보를 나타내는 두 정수 A, B가 주어진다. 이는 A번 정점과 B번 정점이 연결되어 있다는 의미이다. 이때 방향은 A->B가 된다.

출력
첫째 줄에 SCC의 개수 K를 출력한다. 다음 K개의 줄에는 각 줄에 하나의 SCC에 속한 정점의 번호를 출력한다. 각 줄의 끝에는 -1을 출력하여 그 줄의 끝을 나타낸다. 각각의 SCC를 출력할 때 그 안에 속한 정점들은 오름차순으로 출력한다. 또한 여러 개의 SCC에 대해서는 그 안에 속해있는 가장 작은 정점의 정점 번호 순으로 출력한다.
    풀이 :
    코사라주 알고리즘을 이용해 풀었다.(DFS 감이 안잡혀 매우 헤맴;;-> 연습 ㄱㄱ)
    1. 정방향 그래프를 DFS로 탐색해 DFS가 끝난 지점부터 Stack에 넣음.
    2. 역방향 그래프를 Stack의 top부터 DFS로 탐색하여 한번 탐색마다 SCC로 묶음.
 */
import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class Main {

    public static Node[] nd;
    public static int pq_index=0;
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String s=br.readLine();
        StringTokenizer st=new StringTokenizer(s);
        int V=Integer.parseInt(st.nextToken());
        PriorityQueue<Node>[] pq=new PriorityQueue[V+1];
        Stack<Node> stack=new Stack<>();
        PriorityQueue<PriorityQueue<Node>> out_pq=new PriorityQueue<>(new Comparator<PriorityQueue<Node>>() {
            @Override
            public int compare(PriorityQueue<Node> o1, PriorityQueue<Node> o2) {
                return o1.peek().index<=o2.peek().index?-1:1;
            }
        });
        nd=new Node[V+1];

        for (int i = 1; i <=V ; i++) {
            nd[i]=new Node(i);
            stack.push(nd[i]);
        }
        int E=Integer.parseInt(st.nextToken());

        for (int i = 0; i <E ; i++) {
            st=new StringTokenizer(br.readLine());
            int node_index=Integer.parseInt(st.nextToken());
            int next=Integer.parseInt(st.nextToken());
            nd[node_index].next.add(nd[next]);
            nd[next].prev.add(nd[node_index]);
        }
        for (int i = 1; i <=V ; i++) {
            Collections.sort(nd[i].next, new Comparator<Node>() {
                @Override
                public int compare(Node o1, Node o2) {
                    return o1.index<=o2.index?-1:1;
                }
            });
        }

        search_2(search_1(nd),pq);

        bw.write(pq_index+"\n");
        for (int i = 1; i <=pq_index ; i++) {
            out_pq.offer(pq[i]);
        }

        while(!out_pq.isEmpty()){
            PriorityQueue<Node> temp=out_pq.poll();
            while(!temp.isEmpty()) {
                bw.write(temp.poll().index + " ");
                bw.flush();
            }
            bw.write("-1\n");
            bw.flush();
        }

        bw.close();
    }
    public static Stack<Node> search_1(Node[] nd){
        boolean[] visit=new boolean[nd.length];
        Stack<Node> stack=new Stack<>();
        Stack<Node> temp_stack=new Stack<>();

        for (int j = 1; j <nd.length ; j++) {
            if(visit[nd[j].index]==true)
                continue;
            stack.push(nd[j]);
            visit[nd[j].index]=true;
            while (!stack.isEmpty()) {
                Node temp = stack.peek();

                boolean find_flag=false;

                for (int i = 0; i < temp.next.size(); i++) {
                    if (visit[temp.next.get(i).index] == false) {
                        stack.push(temp.next.get(i));
                        visit[temp.next.get(i).index]=true;
                        find_flag=true;
                        break;
                    }
                }
                if(!find_flag) {
                    temp_stack.push(stack.pop());
                }
            }
        }
        return temp_stack;
    }
    public static void search_2(Stack<Node> stack,PriorityQueue<Node>[] pq){
        boolean[] visit=new boolean[nd.length];
        Stack<Node> temp_stack=new Stack<>();
        Stack<Node> res=new Stack<>();

        while(!stack.isEmpty()){
            if(visit[stack.peek().index]==false) {
                temp_stack.push(stack.peek());
                pq[++pq_index]=new PriorityQueue<>(new Comparator<Node>() {
                    @Override
                    public int compare(Node o1, Node o2) {
                        return o1.index<=o2.index?-1:1;
                    }
                });
                visit[stack.peek().index]=true;
                pq[pq_index].offer(stack.pop());
            }
            else
                stack.pop();
            while(!temp_stack.isEmpty()) {
                Node temp=temp_stack.peek();

                boolean find_flag=false;

                for (int i=0;i<temp.prev.size();i++) {
                    if(visit[temp.prev.get(i).index]==false) {
                        temp_stack.push(temp.prev.get(i));
                        pq[pq_index].offer(temp.prev.get(i));
                        visit[temp.prev.get(i).index]=true;
                        find_flag=true;
                        break;
                    }
                }
                if(!find_flag)
                    temp_stack.pop();
            }
        }
    }
}

class Node{

    public ArrayList<Node> next;
    public ArrayList<Node> prev;
    public int index;
    public Node(int index){
        this.index=index;
        next=new ArrayList<>();
        prev=new ArrayList<>();
    }
}