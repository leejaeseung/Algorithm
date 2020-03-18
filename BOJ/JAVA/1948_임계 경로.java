/*
    문제
월드 나라는 모든 도로가 일방통행인 도로이고, 싸이클이 없다. 그런데 어떤 무수히 많은 사람들이 월드 나라의 지도를 그리기 위해서, 어떤 시작 도시로부터 도착 도시까지 출발을 하여 가능한 모든 경로를 탐색한다고 한다.

이 지도를 그리는 사람들은 사이가 너무 좋아서 지도를 그리는 일을 다 마치고 도착 도시에서 모두 다 만나기로 하였다. 그렇다고 하였을 때 이들이 만나는 시간은 출발 도시로부터 출발한 후 최소 몇 시간 후에 만날 수 있는가? 즉, 마지막에 도착하는 사람까지 도착을 하는 시간을 의미한다.

어떤 사람은 이 시간에 만나기 위하여 1분도 쉬지 않고 달려야 한다. 이런 사람들이 지나는 도로의 수를 카운트 하여라.

출발 도시는 들어오는 도로가 0개이고, 도착 도시는 나가는 도로가 0개이다.

입력
첫째 줄에 도시의 개수 n(1 ≤ n ≤ 10,000)이 주어지고 둘째 줄에는 도로의 개수 m(1 ≤ m ≤ 100,000)이 주어진다. 그리고 셋째 줄부터 m+2줄까지 다음과 같은 도로의 정보가 주어진다. 처음에는 도로의 출발 도시의 번호가 주어지고 그 다음에는 도착 도시의 번호, 그리고 마지막에는 이 도로를 지나는데 걸리는 시간이 주어진다. 도로를 지나가는 시간은 10,000보다 작거나 같은 자연수이다.

그리고 m+3째 줄에는 지도를 그리는 사람들이 출발하는 출발 도시와 도착 도시가 주어진다.

모든 도시는 출발 도시로부터 도달이 가능하고, 모든 도시로부터 도착 도시에 도달이 가능하다.

출력
첫째 줄에는 이들이 만나는 시간을, 둘째 줄에는 1분도 쉬지 않고 달려야 하는 도로의 수가 몇 개인지 출력하여라.
    풀이 :
    위상정렬로 먼저 가장 긴 길이를 구하고,
    도착 지점부터 BFS하여 각 노드들의 max_time값과 비교해가며 최장 거리인지 판단한다.
 */
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    public static int[][] map;
    public static int N,M;
    public static int start,end;
    public static int max,cnt;
    public static void main(String[] argc) throws IOException{
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        N=Integer.parseInt(br.readLine());
        M=Integer.parseInt(br.readLine());
        map=new int[N+1][N+1];
        ArrayList<Node> nd=new ArrayList<>();
        for (int i = 0; i <N+1 ; i++) {
            nd.add(new Node(i));
        }
        for (int i = 0; i <M ; i++) {
            st=new StringTokenizer(br.readLine());

            int s=Integer.parseInt(st.nextToken());
            int e=Integer.parseInt(st.nextToken());
            int dis=Integer.parseInt(st.nextToken());

            map[s][e] = dis;
            map[e][s]=dis;
            nd.get(s).next.add(nd.get(e));
            nd.get(e).prev.add(nd.get(s));
            nd.get(e).indegree++;
        }
        st=new StringTokenizer(br.readLine());
        start=Integer.parseInt(st.nextToken());
        end=Integer.parseInt(st.nextToken());

        max=TPSort(nd);
        cnt=BFS(nd);

        System.out.println(max);
        System.out.println(cnt);
    }
    public static int BFS(ArrayList<Node> nd){
        Queue<Node> q=new LinkedList<>();
        boolean[] visit=new boolean[N+1];
        q.offer(nd.get(end));
        visit[end]=true;
        int cnt=0;

        while(!q.isEmpty()){
            Node temp=q.poll();

            for (int i = 0; i <temp.prev.size() ; i++) {

                    if (temp.max_time - map[temp.num][temp.prev.get(i).num] == temp.prev.get(i).max_time) {
                        if(!visit[temp.prev.get(i).num]) {
                            q.offer(temp.prev.get(i));
                            visit[temp.prev.get(i).num]=true;
                        }
                        cnt++;
                    }
            }
        }
        return cnt;
    }
    public static int TPSort(ArrayList<Node> nd){
        Queue<Node> q=new LinkedList<>();
        q.offer(nd.get(start));

        while(!q.isEmpty()){
            Node temp=q.poll();

            for (int i = 0; i <temp.next.size() ; i++) {
                temp.next.get(i).indegree--;
                if(temp.next.get(i).max_time<temp.max_time+map[temp.num][temp.next.get(i).num]){
                    temp.next.get(i).max_time=temp.max_time+map[temp.num][temp.next.get(i).num];
                }
                if(temp.next.get(i).indegree==0){
                    q.offer(temp.next.get(i));
                }
            }
        }
        return nd.get(end).max_time;
    }
}

class Node{

    public int indegree=0;
    public ArrayList<Node> next;
    public ArrayList<Node> prev;
    public int num;
    public int max_time=0;
    public Node(int num){
        this.num=num;
        next=new ArrayList<>();
        prev=new ArrayList<>();
    }
}
