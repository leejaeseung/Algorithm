import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int T=Integer.parseInt(br.readLine());

        for (int i = 0; i <T ; i++) {
            StringTokenizer st=new StringTokenizer(br.readLine());
            int sum=0;
            sum+=fes_1(Integer.parseInt(st.nextToken()))+fes_2(Integer.parseInt(st.nextToken()));

            bw.write(Integer.toString(sum)+"\n");
            bw.flush();
        }
        bw.close();
    }
    public static int fes_1(int n){
        if(n==1)
            return 5000000;
        else if(n>=2&&n<=3)
            return 3000000;
        else if(n>=4&&n<=6)
            return 2000000;
        else if(n>=7&&n<=10)
            return 500000;
        else if(n>=11&&n<=15)
            return 300000;
        else if(n>=16&&n<=21)
            return 100000;
        else
            return 0;
    }
    public static int fes_2(int n){
        if(n==1)
            return 5120000;
        else if(n>=2&&n<=3)
            return 2560000;
        else if(n>=4&&n<=7)
            return 1280000;
        else if(n>=8&&n<=15)
            return 640000;
        else if(n>=16&&n<=31)
            return 320000;
        else
            return 0;
    }
}