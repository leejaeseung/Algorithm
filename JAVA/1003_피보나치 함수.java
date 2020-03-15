/*
    피보나치 변형 문제 :
    결국 0과 1의 출력도 피보나치 수열을 이루고 있으므로 반복문을 사용하여 풀이
 */
import java.io.*;

public class Main {

    public static void main(String[] argc) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));

        int N=Integer.parseInt(br.readLine());

        int num;

        for (int i = 0; i <N ; i++) {
            num=Integer.parseInt(br.readLine());
            bw.write(fibo(num,0)+" ");
            bw.write(fibo(num,1)+"\n");
        }
        bw.flush();
        bw.close();
    }

    public static long fibo(int n,int zeroORone){
        if(zeroORone==1){
            long a=1;
            long b=1;
            long res=0;
            if(n==1||n==2){
                return 1;
            }
            else if(n==0){
                return 0;
            }
            else{
                for (int i = 0; i <=n-3 ; i++) {
                    res=add(a,b);
                    b=a;
                    a=res;
                }
            }
            return res;
        }
        else{
            long a=1;
            long b=1;
            long res=0;
            if(n==0||n==2||n==3){
                return 1;
            }
            else if(n==1){
                return 0;
            }
            else{
                for (int i = 0; i <=n-4 ; i++) {
                    res=add(a,b);
                    b=a;
                    a=res;
                }
            }
            return res;
        }
    }
    public static long add(long a,long b){
        return a+b;
    }
}
