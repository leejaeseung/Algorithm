/*
    문제
N명의 학생들을 키 순서대로 줄을 세우려고 한다. 각 학생의 키를 직접 재서 정렬하면 간단하겠지만, 마땅한 방법이 없어서 두 학생의 키를 비교하는 방법을 사용하기로 하였다. 그나마도 모든 학생들을 다 비교해 본 것이 아니고, 일부 학생들의 키만을 비교해 보았다.

일부 학생들의 키를 비교한 결과가 주어졌을 때, 줄을 세우는 프로그램을 작성하시오.

입력
첫째 줄에 N(1≤N≤32,000), M(1≤M≤100,000)이 주어진다. M은 키를 비교한 회수이다. 다음 M개의 줄에는 키를 비교한 두 학생의 번호 A, B가 주어진다. 이는 학생 A가 학생 B의 앞에 서야 한다는 의미이다.

학생들의 번호는 1번부터 N번이다.

출력
첫째 줄부터 앞에서부터 줄을 세운 결과를 출력한다. 답이 여러 가지인 경우에는 아무거나 출력한다.
    풀이 :
    위상 정렬 문제로, 정점에 대해 그 정점에 들어오는 간선의 수를 indegree로 구하고, indegree가 0인 정점을 모두 큐에 넣고 정렬을 시작한다.
    indegree가 0인 정점은 자신의 모든 간선과 연결된 정점의 indegree를 -1한다.
    위에서 indegree를 -1했을 때 새롭게 indegree가 0이 되는 정점을 큐에 넣고 위 작업을 큐가 빌 때까지 반복한다.
 */
import java.io.*;
import java.util.*;

public class Main {

    public static int N;
    public static BufferedWriter bw;
    public static void main(String[] args) throws IOException{
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        bw=new BufferedWriter(new OutputStreamWriter(System.out));

        String s=br.readLine();
        StringTokenizer st=new StringTokenizer(s);
        N=Integer.parseInt(st.nextToken());
        int M=Integer.parseInt(st.nextToken());

        Node[] point=new Node[N+1];
        for (int i = 1; i <=N ; i++) {
            point[i]=new Node(i);
        }
        for (int i = 0; i <M ; i++) {
            s=br.readLine();
            st=new StringTokenizer(s);
            int front=Integer.parseInt(st.nextToken());
            int back=Integer.parseInt(st.nextToken());
            point[front].next.add(point[back]);
            point[back].indegree++;
        }
        TopologySort(point);
        bw.flush();
        bw.close();
    }
    public static void TopologySort(Node[] nd) throws IOException{
        Queue<Node> q=new LinkedList<>();
        for (int i = 1; i <= N; i++) {
            if (nd[i].indegree == 0) {
                q.offer(nd[i]);
            }
        }
        while(!q.isEmpty()) {
            if (!q.isEmpty()) {
                Node temp = q.poll();
                bw.write(temp.num + " ");
                for (int j = 0; j < temp.next.size(); j++) {
                    temp.next.get(j).indegree--;
                    if(temp.next.get(j).indegree==0){
                      q.offer(temp.next.get(j));
                    }
                }
            }
        }
    }
}
class Node{

    public int indegree;
    public ArrayList<Node> next;
    public int num;
    public Node(int num){
        next=new ArrayList<>();
        int indegree=0;
        this.num=num;
    }

}
