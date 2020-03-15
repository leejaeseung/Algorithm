/*
    브루트 포스 문제 :
    재귀 함수로 모든 경우를 탐색하며 조건에 맞지 않는 경우에만 return -1하고 max값을 계속 갱신
 */
import java.io.*;
import java.util.StringTokenizer;

public class Main {

    private static int N;
    private static int maxday;
    private static int maxcost=0;
    private static int count=0;
    public static void main(String[] argc) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));

        N=Integer.parseInt(br.readLine());
        Node[] day=new Node[N];

        maxday=N+1;

        String s;

        for (int i = 0; i <N ; i++) {
            s=br.readLine();
            StringTokenizer st=new StringTokenizer(s);
            day[i]=new Node(Integer.parseInt(st.nextToken()),Integer.parseInt(st.nextToken()));
        }
        Maxcost(day,0,0,0);

        bw.write(Integer.toString(maxcost));
        bw.flush();
        bw.close();
    }
    public static int Maxcost(Node[] nd,int sum,int nowday,int during){
        if(nowday!=0) {
            if (nowday + nd[nowday - 1].T > maxday)
                return -1;
        }
        if(nowday>during) {
            sum += nd[nowday-1].cost;

            if (maxcost < sum) {
                maxcost = sum;
            }
            during=nd[nowday-1].T+nowday-1;
        }

        for(int i=1;i<=N;i++) {
            if(nowday+i<=N)
            Maxcost(nd, sum, nowday + i, during);
            else
                break;
        }


        return 1;
    }
}

class Node{

    public int T;
    public int cost;
    public Node(int T,int cost){
        this.T=T;
        this.cost=cost;
    }
}