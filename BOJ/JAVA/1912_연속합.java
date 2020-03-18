/*
    풀이 :
    연속해서 숫자를 더해나가고, max값을 계속 갱신한다. 합이 음수가 아니라면 그 때의 max값이 최대값이고, 음수가 나온다면 지금까지의 max값을 큐에 넣고
    다음 음수가 아닌 값이 나올때부터 다시 더하고 max값 갱신을 반복한다.
    큐에 있는 max값 중 가장 큰 값이 답이다.
 */
import java.io.*;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());

        int[] arr=new int[N];
        String s=br.readLine();
        StringTokenizer st=new StringTokenizer(s);
        for (int i = 0; i <N ; i++) {
            arr[i]=Integer.parseInt(st.nextToken());
        }
        bw.write(Integer.toString(find(arr)));
        bw.flush();
        bw.close();
    }
    public static int find(int[] arr){
        Comparator<Integer> myCom=new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return o1<=o2?1:-1;
            }
        };
        PriorityQueue<Integer> pq=new PriorityQueue<>(myCom);
        int max=arr[0];
        int sum=0;

        for (int i = 0; i <arr.length ; i++) {
            sum+=arr[i];
            if(sum>max){
                max=sum;
            }
            if(sum<0){
                pq.offer(max);
                sum=0;
                continue;
            }

        }
        pq.offer(max);
        return pq.poll();
    }
}