/*
    풀이 :
    배열의 앞을 가르키는 f와 뒤를 가르키는 b를 만들어 'R'이면 b와f를 바꿔주고, 'D'이면
    f>b이면 앞뒤가 바뀐 것이므로 f--, f<b이면 정상인 배열이므로 f++해주어 f와 b사이에 있는 배열 값을 출력한다
 */
import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static int f;
    public static int b;
    public static BufferedWriter bw;
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N=Integer.parseInt(br.readLine());

        for (int i = 0; i <N ; i++) {
            String func=br.readLine();
            int size=Integer.parseInt(br.readLine());
            int[] arr=new int[size];
            String num=br.readLine();
            StringTokenizer st=new StringTokenizer(num,"[,]");
            for (int j = 0; j <size ; j++) {
                arr[j]=Integer.parseInt(st.nextToken());
            }
            f=0;    b=size-1;
            AC(arr,func);
        }
        bw.flush();
        bw.close();
    }
    public static int AC(int[] arr,String func) throws IOException{
        boolean empty=false;
        int d_count=0;
        for (int i = 0; i <func.length() ; i++) {
            if(b<0) {
                empty = true;
                b=0;
            }
            if(func.charAt(i)=='R'){
                int temp=b;
                b=f;
                f=temp;
            }
            else{
                d_count++;
                if(d_count>arr.length){
                    bw.write("error\n");
                    return 0;
                }
                if(f>b){                                        //앞이 뒤보다 크므로 뒤집힌 상태
                    f--;
                }
                else if(f<b){                                   //정상인 상태
                    f++;
                }
                else{
                    empty=true;
                }
            }
        }
        if(f==b){
            if(empty==true)
            bw.write("[]\n");
            else{
                bw.write("["+arr[f]+"]\n");
            }
        }
        else if(f<b){
            bw.write("[");
            bw.write(Integer.toString(arr[f]));
            for (int i = f+1; i <=b ; i++) {
                bw.write(","+arr[i]);
            }
            bw.write("]\n");
        }
        else{
            bw.write("[");
            bw.write(Integer.toString(arr[f]));
            for (int i = f-1; i >=b ; i--) {
                bw.write(","+arr[i]);
            }
            bw.write("]\n");
        }
        return 0;
    }
}