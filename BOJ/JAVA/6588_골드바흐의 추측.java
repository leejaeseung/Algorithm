/*
    풀이 :
    에라토스테네스의 체를 활용하여 arr에 소수인 index의 값은 0으로 하고, 입력값(N)에서 가장 가까운 값(j)을 먼저 구하고, arr[N-j]가 소수이면 출력한다.
 */
import java.io.*;

public class Main {

    public static int[] arr;
    public static int size=1000000;
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        arr = new int[size+1];

        find();

        while(true){
            int N=Integer.parseInt(br.readLine());
            int temp=0;
            boolean find=false;
            if(N==0)
                break;
            for (int j = N; j >2 ; j--) {
                if(arr[j]==0){
                    temp=N-j;
                    if(arr[temp]==0){
                        bw.write(N+" = "+temp+" + "+j+"\n");
                        find=true;
                        break;
                    }
                }
            }
            if(find==false)
                bw.write("Goldbach's conjecture is wrong.\n");
        }
        bw.flush();
        bw.close();
    }
        public static void find () {
            arr[1] = 1;
            int index = 2;
            int mul = 2;
            while (index <= Math.sqrt(size)) {
                if (arr[index] == 0) {
                    while (index * mul <= size) {
                        if (arr[index * mul] == 0) {
                            arr[index * mul] = 1;
                        }
                        mul++;
                    }
                    mul = 2;
                }
                index++;
            }
        }
    }