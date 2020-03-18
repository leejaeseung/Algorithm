/*
    풀이 :
    처음엔 1부터1000000까지 일일이 찾느라 시간이 오래 걸렸지만 어차피 생성자는 분해합-(분해합의 자릿수)*9보다 작을 수 없으므로
    시작 구간을 줄여 시간을 단축했다.
 */
import java.io.*;

public class Main {

    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N=Integer.parseInt(br.readLine());

        int k=1;
        int mul=10;
        while(N/mul!=0){
            mul*=10;
            k++;
        }

        for (int i = N-k*9; true ; i++) {
            int temp=creator(Integer.toString(i));
            if(temp==N) {
                bw.write(Integer.toString(i));
                break;
            }
            else if(i>=N){
                bw.write(Integer.toString(0));
                break;
            }
        }
        bw.flush();
        bw.close();
    }
    public static int creator(String i){
        int sum=0;
        for (int j = 0; j <i.length() ; j++) {
            sum+=i.charAt(j)-'0';
        }
        return Integer.parseInt(i)+sum;
    }
}