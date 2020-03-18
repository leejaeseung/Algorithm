/*
    풀이 :(큐 활용법을 익히자!)
    1부터 9까지는 감소수이므로 큐에 집어넣고 이후에 큐에서 하나씩 꺼내 마지막수보다 작은 수를 0부터 붙여나가 des배열을 완성한다.
 */
import java.io.*;
import java.util.LinkedList;
import java.util.Queue;

public class Main {

    public static int N;
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        N = Integer.parseInt(br.readLine());
        Queue<Long> q=new LinkedList<>();
        long[] des=new long[1000001];

        for (int i = 1; i <=9 ; i++) {
            des[i]=i;
            q.offer((long)i);
        }
        int index=9;

        while(index<=N){

            if(q.isEmpty())
                break;
            long temp=q.poll();

            long lastNum=temp%10;
            for (int i = 0; i <lastNum ; i++) {
                q.offer(temp*10+i);
                des[++index]=temp*10+i;
            }
        }
        des[0]=0;
        if(des[N]==0&&N!=0)
            bw.write(Integer.toString(-1));
        else
        bw.write(Long.toString(des[N]));

        bw.flush();
        bw.close();
    }
}