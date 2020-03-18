/*
    풀이 :
    x가 30의 배수란 건 결국 x에서 마지막 0을 뺀 수가 3의 배수라는 말과 같다.
    그러므로 일단 x안에 0이 하나는 무조건 존재해야 하고, x가 3의 배수이려면 x의 각 자리수들의 합이 3의 배수가 되면 된다.
    그 수 중 가장 큰 수는 x를 내림차순으로 정렬했을 때가 가장 큰 수이다.
 */
import java.io.*;
import java.util.Comparator;
import java.util.PriorityQueue;

public class Main {

    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        Comparator<Integer> myCom=new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return o1<o2?1:-1;
            }
        };
        PriorityQueue<Integer> pq=new PriorityQueue<>(myCom);

        String s=br.readLine();
        for (int i = 0; i <s.length() ; i++) {
            pq.add(s.charAt(i)-'0');
        }
        StringBuilder sb=new StringBuilder();
        int temp;
        int sum=0;
        while(!pq.isEmpty()) {
            temp=pq.poll();
            sb.append(temp);
            sum+=temp;
        }
        if(sb.toString().charAt(sb.length()-1)=='0'){
            if(sum%3==0){
                bw.write(sb.toString());
            }
            else{
                bw.write(Integer.toString(-1));
            }
        }
        else{
            bw.write(Integer.toString(-1));
        }
        bw.flush();
        bw.close();
    }
}