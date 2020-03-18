/*
    풀이 :
    그리디 알고리즘이기 때문에 종료 시간을 오름차순으로 정렬->같으면 시작시간도 오름차순으로 정렬하여 가장 먼저 끝나고 빨리 시작하는 순서로
    회의실을 배정한다.
 */
import java.io.*;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    public static PriorityQueue<Node> pq;
    public static int time=0;
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        Comparator<Node> myCom=new Comparator<Node>() {
            @Override
            public int compare(Node o1, Node o2) {
                if(o1.e<o2.e){
                    return -1;
                }else if(o1.e==o2.e){
                    if(o1.s<=o2.s)
                        return -1;
                    else
                    return 1;
                }
                else
                    return 1;
            }
        };
        int N=Integer.parseInt(br.readLine());

        pq=new PriorityQueue<>(myCom);
        for (int i = 0; i <N ; i++) {
            String s=br.readLine();
            StringTokenizer st=new StringTokenizer(s);
            Node temp=new Node(Integer.parseInt(st.nextToken()),Integer.parseInt(st.nextToken()));
            pq.offer(temp);
        }
        int count=0;
        while(!pq.isEmpty()){
            Node temp=pq.poll();
            if(temp.s>=time) {
                time = temp.e;
                count++;
            }
        }
        bw.write(Integer.toString(count));
        bw.flush();
        bw.close();
    }
}

class Node{

    public int s;
    public int e;
    public Node(int s,int e){
        this.s=s;
        this.e=e;
    }
}