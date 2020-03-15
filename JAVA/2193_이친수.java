/*
    풀이 :
    처음 두 자리는 "10"으로 무조건 고정해야 되기 때문에 N이 1과2일 때는 하나밖에 존재하지 않고 N이 3이상일 때부터 구하면 된다.
    이차원 배열을 생성해 [i][0]은 i-1번째가 0과1둘 다 가능하기 때문에 이전의 0과1의 경우의 수를 더하고,[i][1]은 i-1번째에 0만 가능하므로 0의 경우의 수가 더한다.
    마지막 배열의 0과1의 경우의 수를 더한 값을 출력한다.
 */
import java.io.*;
public class Main {

    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());

        if(N==1||N==2)
            bw.write(Integer.toString(1));
        else{
            bw.write(Long.toString(counting(N-2)));
        }
        bw.flush();
        bw.close();
    }
    public static long counting(int n){
        long[][] pinary=new long[n][2];

        pinary[0][0]=1;
        pinary[0][1]=1;
        for (int i = 1; i <n ; i++) {
            pinary[i][0]=pinary[i-1][0]+pinary[i-1][1];
            pinary[i][1]=pinary[i-1][0];
        }
        return pinary[n-1][0]+pinary[n-1][1];
    }
}