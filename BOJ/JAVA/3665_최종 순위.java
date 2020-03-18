/*
    문제
올해 ACM-ICPC 대전 인터넷 예선에는 총 n개의 팀이 참가했다. 팀은 1번부터 n번까지 번호가 매겨져 있다. 놀랍게도 올해 참가하는 팀은 작년에 참가했던 팀과 동일하다.

올해는 인터넷 예선 본부에서는 최종 순위를 발표하지 않기로 했다. 그 대신에 작년에 비해서 상대적인 순위가 바뀐 팀의 목록만 발표하려고 한다. (작년에는 순위를 발표했다) 예를 들어, 작년에 팀 13이 팀 6 보다 순위가 높았는데, 올해 팀 6이 팀 13보다 순위가 높다면, (6, 13)을 발표할 것이다.

창영이는 이 정보만을 가지고 올해 최종 순위를 만들어보려고 한다. 작년 순위와 상대적인 순위가 바뀐 모든 팀의 목록이 주어졌을 때, 올해 순위를 만드는 프로그램을 작성하시오. 하지만, 본부에서 발표한 정보를 가지고 확실한 올해 순위를 만들 수 없는 경우가 있을 수도 있고, 일관성이 없는 잘못된 정보일 수도 있다. 이 두 경우도 모두 찾아내야 한다.

입력
첫째 줄에는 테스트 케이스의 개수가 주어진다. 테스트 케이스는 100개를 넘지 않는다. 각 테스트 케이스는 다음과 같이 이루어져 있다.

팀의 수 n을 포함하고 있는 한 줄. (2 ≤ n ≤ 500)
n개의 정수 ti를 포함하고 있는 한 줄. (1 ≤ ti ≤ n) ti는 작년에 i등을 한 팀의 번호이다. 1등이 가장 성적이 높은 팀이다. 모든 ti는 서로 다르다.
상대적인 등수가 바뀐 쌍의 수 m (0 ≤ m ≤ 25000)
두 정수 ai와 bi를 포함하고 있는 m줄. (1 ≤ ai < bi ≤ n) 상대적인 등수가 바뀐 두 팀이 주어진다. 같은 쌍이 여러 번 발표되는 경우는 없다.
출력
각 테스트 케이스에 대해서 다음을 출력한다.

n개의 정수를 한 줄에 출력한다. 출력하는 숫자는 올해 순위이며, 1등팀부터 순서대로 출력한다. 만약, 확실한 순위를 찾을 수 없다면 "?"를 출력한다. 데이터에 일관성이 없어서 순위를 정할 수 없는 경우에는 "IMPOSSIBLE"을 출력한다.
    풀이 :
    1등은 나머지 등수에 대해 정방향 간선을 모두 가지고 있고,2등은 1등을 제외한 나머지 등수에 대해 정방향 간선,...이런 규칙으로 그래프를 만든다.
    등수가 바뀐 경우 그 두 팀에 해당하는 간선의 방향을 바꿔준다.
    그 뒤, 등수를 기준으로 오름차순 위상 정렬을 하여 출력하는데, indegree가 0인 정점이 여러개라면 순위를 확실히 매길 수 없기 때문에 "?"를, 도중에 cycle이 생겨 모든 정점을 돌지 못하면
    "IMPOSSIBLE"을 출력한다.
 */
import java.io.*;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    public static int Team;
    public static BufferedWriter bw;
    public static void main(String[] argc) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        bw=new BufferedWriter(new OutputStreamWriter(System.out));

        int Testcase=Integer.parseInt(br.readLine());

        for (int i = 0; i <Testcase ; i++) {
            Team=Integer.parseInt(br.readLine());
            String s=br.readLine();
            StringTokenizer st=new StringTokenizer(s);

            Node[] nd=new Node[Team+1];
            for (int j = 1; j <=Team ; j++) {
                nd[j]=new Node(j,Integer.parseInt(st.nextToken()));
            }
            for (int j = 1; j <Team ; j++) {
                for (int k = j+1; k <=Team ; k++) {
                    nd[j].next.add(nd[k]);
                    nd[k].indegree++;
                }
            }
            int change=Integer.parseInt(br.readLine());
            boolean IMP_flag=false;
            for (int j = 0; j <change ; j++) {
                st=new StringTokenizer(br.readLine());
                int first=Integer.parseInt(st.nextToken());
                for (int k = 1; k <=Team ; k++) {
                    if(nd[k].team_num==first){
                        first=k;
                        break;
                    }
                }
                int second=Integer.parseInt(st.nextToken());
                for (int k = 1; k <=Team ; k++) {
                    if(nd[k].team_num==second){
                        second=k;
                        break;
                    }
                }
                if(first>second) {
                    if (nd[second].next.remove(nd[first]))
                        nd[first].indegree--;
                    nd[first].next.add(nd[second]);
                    nd[second].indegree++;
                }else{
                        if (nd[first].next.remove(nd[second]))
                            nd[second].indegree--;
                            nd[second].next.add(nd[first]);
                            nd[first].indegree++;
                    }
                }
                TPS(nd);

            bw.write("\n");
            bw.flush();
        }
        bw.close();
    }
    public static int TPS(Node[] nd) throws IOException{
        boolean[] visit=new boolean[Team+1];
        PriorityQueue<Node> pq=new PriorityQueue<>(new Comparator<Node>() {
            @Override
            public int compare(Node o1, Node o2) {
                return o1.rank<=o2.rank?-1:1;
            }
        });
        boolean indegree_flag=false;
        for (int i = 1; i <=Team ; i++) {
            if(indegree_flag==true&&nd[i].indegree==0){
                bw=new BufferedWriter(new OutputStreamWriter(System.out));
                bw.write("?");
                return 0;
            }
            if(nd[i].indegree==0){
                pq.offer(nd[i]);
                indegree_flag=true;
            }
        }
        while(!pq.isEmpty()){
            Node temp=pq.poll();
            bw.write(temp.team_num+" ");
            visit[temp.rank]=true;
            indegree_flag=false;
            for (int i = 0; i <temp.next.size() ; i++) {
                temp.next.get(i).indegree--;
                if(indegree_flag==true&&temp.next.get(i).indegree==0){
                    bw=new BufferedWriter(new OutputStreamWriter(System.out));
                    bw.write("?");
                    return 0;
                }
                if(temp.next.get(i).indegree==0){
                    pq.offer(temp.next.get(i));
                    indegree_flag=true;
                }
            }
        }
        for (int i = 1; i <=Team ; i++) {
            if(visit[i]==false){
                bw=new BufferedWriter(new OutputStreamWriter(System.out));
                bw.write("IMPOSSIBLE");
                return 0;
            }
        }
        return 0;
    }
}

class Node{

    public int rank;
    public int indegree;
    public int team_num;
    public ArrayList<Node> next;
    public Node(int rank,int team_num){
        this.rank=rank;
        this.team_num=team_num;
        next=new ArrayList<>();
    }
}