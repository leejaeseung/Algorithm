/*
    문제
그래프의 정점의 집합을 둘로 분할하여, 각 집합에 속한 정점끼리는 서로 인접하지 않도록 분할할 수 있을 때, 그러한 그래프를 특별히 이분 그래프 (Bipartite Graph) 라 부른다.

그래프가 입력으로 주어졌을 때, 이 그래프가 이분 그래프인지 아닌지 판별하는 프로그램을 작성하시오.

입력
입력은 여러 개의 테스트 케이스로 구성되어 있는데, 첫째 줄에 테스트 케이스의 개수 K(2≤K≤5)가 주어진다. 각 테스트 케이스의 첫째 줄에는 그래프의 정점의 개수 V(1≤V≤20,000)와 간선의 개수 E(1≤E≤200,000)가 빈 칸을 사이에 두고 순서대로 주어진다. 각 정점에는 1부터 V까지 차례로 번호가 붙어 있다. 이어서 둘째 줄부터 E개의 줄에 걸쳐 간선에 대한 정보가 주어지는데, 각 줄에 인접한 두 정점의 번호가 빈 칸을 사이에 두고 주어진다.

출력
K개의 줄에 걸쳐 입력으로 주어진 그래프가 이분 그래프이면 YES, 아니면 NO를 순서대로 출력한다.
    풀이 :
    그래프를 BFS로 탐색하면서 flag를 껐다켰다 하며 인접 노드와 flag가 같은지 확인하고 같으면 잘못된 것이므로 -1을 리턴한다.
    끊어진 그래프도 생각해야 하므로 모든 연결된 노드에 대해 실행한다.
 */
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;
import java.util.Vector;

public class Main {

    public static boolean now_flag=false;
    public static boolean[] visit;
    public static void main(String[] argc) throws IOException{
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));

        int T=Integer.parseInt(br.readLine());
        for (int i = 0; i <T ; i++) {
            StringTokenizer st=new StringTokenizer(br.readLine());
            int V=Integer.parseInt(st.nextToken());
            int E=Integer.parseInt(st.nextToken());

            Vector<node>[] vt=new Vector[V+1];
            node[] nd=new node[V+1];
            visit=new boolean[V+1];
            for (int j = 1; j <=V ; j++) {
                vt[j]=new Vector<>();
                nd[j]=new node(j,false);
            }
            for (int j = 0; j <E ; j++) {
                st = new StringTokenizer(br.readLine());
                int from = Integer.parseInt(st.nextToken());
                int to = Integer.parseInt(st.nextToken());
                vt[from].add(nd[to]);
                vt[to].add(nd[from]);
            }
            int res=0;
            for (int j = 1; j <=V ; j++) {
                if(!visit[j]){
                    res=BFS(vt,j);
                    if(res==-1)
                        break;
                }
            }
            if(res==-1){
                System.out.println("NO");
            }
            else{
                System.out.println("YES");
            }
        }
    }
    public static int BFS(Vector<node>[] vt,int start){
        Queue<node> q=new LinkedList<>();
        visit[start]=true;
        now_flag=false;
        for (int i = 0; i <vt[start].size() ; i++) {
            vt[start].get(i).flag=true;
            q.offer(vt[start].get(i));
        }
        while(!q.isEmpty()) {
            int qs = q.size();
            now_flag=!now_flag;
            for (int j = 0; j < qs; j++) {
                node temp = q.poll();
                if (now_flag !=temp.flag)
                    return -1;
                visit[temp.num] = true;
                for (int i = 0; i < vt[temp.num].size(); i++) {
                    if (!visit[vt[temp.num].get(i).num]) {
                        vt[temp.num].get(i).flag = !temp.flag;
                        q.offer(vt[temp.num].get(i));
                    }
                }

            }
        }
        return 0;
    }
}

class node{

    public int num;
    public boolean flag;
    public node(int num,boolean flag){
        this.num=num;
        this.flag=flag;
    }
}