/*
    풀이 :
    그래프 알고리즘의 4963번 섬의 개수와 같은 문제
 */
import java.io.*;
import java.util.Comparator;
import java.util.PriorityQueue;

public class Main {

    public static PriorityQueue<Integer> pq;
    public static int map[][];
    public static int count=0;
    public static int home_count=0;
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        Comparator<Integer> myCom=new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return o1>=o2?1:-1;
            }
        };
        pq=new PriorityQueue<>(myCom);
        int N = Integer.parseInt(br.readLine());

        map=new int[N+2][N+2];

        for (int i = 1; i <=N ; i++) {
            String s=br.readLine();
            for (int j = 1; j <=N ; j++) {
                map[i][j]=s.charAt(j-1)-'0';
            }
        }
        for (int i = 1; i <=N ; i++) {
            for (int j = 1; j <=N ; j++) {
                count=0;
                if(map[i][j]==1) {
                    find(i, j);
                    home_count++;
                    pq.offer(count);
                }
            }
        }
        bw.write(home_count+"\n");
        while(!pq.isEmpty()){
            bw.write(pq.poll()+"\n");
        }
        bw.flush();
        bw.close();
    }
    public static int find(int i,int j){
        if(map[i][j]==0||map[i][j]==-1)
            return -1;
        if(map[i][j]==1) {
            map[i][j] = -1;
            count++;
        }
            if(map[i-1][j]==1)
                find(i-1,j);
            for (int l = -1; l <2 ; l++) {
                if(map[i][j+l]==1)
                    find(i,j+l);
            }
            if(map[i+1][j]==1)
                find(i+1,j);
        return 0;
    }
}