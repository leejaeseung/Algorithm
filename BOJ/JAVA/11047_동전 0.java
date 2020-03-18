/*
    풀이 :
    가장 큰 종류의 동전부터 K를 계속 빼가면서 count를 세줌
 */
import java.io.*;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String s=br.readLine();
        StringTokenizer st=new StringTokenizer(s);

        int N=Integer.parseInt(st.nextToken());
        int K=Integer.parseInt(st.nextToken());
        Stack<Integer> stack=new Stack<>();
        int count=0;

        for (int i = 0; i <N ; i++) {
            stack.push(Integer.parseInt(br.readLine()));
        }
        while(!stack.empty()){
            int temp=stack.pop();

                while(temp<=K){
                    K-=temp;
                    count++;
                }
        }
        bw.write(Integer.toString(count));
        bw.flush();
        bw.close();
    }
}